/*
 * Copyright 2018-2019 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*!
 * \file ia_aic_myriad.h
 * \brief ia_aic_myriad specific implementation.
 *
 * \mainpage
 * \section main Automatic ISP (AIC) Configuration component for Myriad ISP
 *
 * AIC is stateless component, which purpose is to
 * - Convert generic results into ISP specific format.
 * - Adapt ISP tunings based on run-time changing parameters.
 * - Convert ISP specific statistics into format that is used by 3A and control other algorithms.
 *
 * AIC consists of following components:
 * - \ref gaic
 *
 * AIC API is defined in ia_aic_myriad.h file.
 *
 * See \ref integration for more detailed information about various integration details.
 *
 * \page aicparts AIC modules
 * \section gaic Generic AIC (GAIC)
 *
 * GAIC implements generic adaptation of tunings (generated with IQ tools) as factor of run-time changing parameters. GAIC uses various interpolation
 * schemes to calculate ISP parameters between distinct tunings.
 *
 * \page integration Integration notes
 * \section AIC output buffer state
 *
 * AIC is stateless but instead state is stored inside output buffer. Naturally, if same output buffer is not given back to AIC in the next iteration
 * AIC will recalculate all ISP parameters, thus maintaining backwards compatibility for systems that don't utilize buffer state.AIC determines if the given buffer
 * is the same by compating if the first 8 bytes of the given buffer are always the same. If AIC client uses the same output buffer all the time, client should
 * invalidate (by clearing the first 8 bytes of the) given AIC output buffer when any resolution (resolution_info or resolution_history) parameters change at any
 * stage of the camera operation. Such changes include for example change in digital zoom, scaling and cropping.
 *
*/

#ifndef IA_AIC_MYRIAD_H_
#define IA_AIC_MYRIAD_H_

#include "ia_aiq_types.h"
#include "ia_types.h"
#include "ipipe.h"
#include "ia_statistics_types.h"
//#include "ia_dvs_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ia_aic_myriad_t ia_aic_myriad;

/*!
 * \brief Initialize ia_aic_myriad.
 * This function must be called before any other function in the library.
 * Initialization returns a handle to the ISP instance, which is given as input parameter for all the ia_aic_myriad functions.
 */

LIBEXPORT ia_aic_myriad*
ia_aic_myriad_init(void);

LIBEXPORT void
ia_aic_myriad_deinit(ia_aic_myriad *ia_aic_myriad);

LIBEXPORT ia_err
ia_aic_myriad_set_tuning(
    ia_aic_myriad *aic_myriad,
    const ia_binary_data *aiqb_data,
    const ia_cmc_t *ia_cmc);

/*!
 *  \brief ia_aic_myriad parameter input structure.
 */
typedef struct
{
    unsigned long long timestamp;                    /*!< Mandatory. Current timestamp (is microseconds) when ia_aic_myriad_run function is called. AIC uses timestamp to decide what
                                                                     calculations are done based on tunable run rate for each ISP configuration algorithm. */
    unsigned int frame_width;
    unsigned int frame_height;
    ia_aiq_frame_params *sensor_frame_params;        /*!< Mandatory. Sensor frame parameters. Describe frame scaling/cropping done in sensor. */
    ia_aiq_awb_results *awb_results;                 /*!< Mandatory. WB results which are to be used to calculate next ISP parameters (WB gains, color matrix,etc). */
    ia_aiq_gbce_results *gbce_results;               /*!< Mandatory. GBCE Gamma tables which are to be used to calculate next ISP parameters.*/
    ia_aiq_ae_results *ae_results;                   /*!< Mandatory. Exposure results which are to be used to calculate next ISP parameters.
                                                                     Currently only exposure times, analog and digital gains are used. For convenience reasons AIC takes
                                                                     ae results and not only needed parameters. */
    ia_aiq_pa_results_v1 *pa_results;                /*!< Mandatory. Parameter adaptor results from AIQ. */
    ia_aiq_sa_results_v1 *sa_results;                /*!< Mandatory. Shading adaptor results from AIQ. */
//    ia_dvs_image_transformation *gdc_transformation; /*!< Mandatory. Image transformation parameters for GDC5 ISP FW. This feature replaces the need for morph_table usage.*/
} ia_aic_myriad_input_params;

/*!
 * \brief ISP configuration for the next frame
 * Computes ISP parameters from input parameters and CPF values for the next image.
 *
 * \param[in] ia_aic_myriad                 Mandatory. ISP instance handle.
 * \param[in] input_params                  Mandatory. Input parameters for ISP calculations.
 * \param[in/out] output                    Mandatory. Output data structure. If output pointer is given, AIC writes the results to given buffer.
 *                                                     Output is following ISP API format.
 * \return                                  Error code.
 */
LIBEXPORT ia_err
ia_aic_myriad_run(
    ia_aic_myriad *ia_aic_myriad,
    const ia_aic_myriad_input_params *input_params,
    icIspConfig *output);

/*!
 * \brief Creates ISP parameters output buffer.
 * This function can be used by AIC client to create AIC output buffer. This function's output can be
 * passed ia_aic_myriad_run() function to fill the output_data structure.
 *
 * \return                         ISP configuration parameter structure.
 */
LIBEXPORT icIspConfig *
ia_aic_myriad_create_output(void);

LIBEXPORT void
ia_aic_myriad_delete_output(icIspConfig *output);

LIBEXPORT ia_err
ia_aic_myriad_statistics_convert_rgbs_grid_v2(
        const icIspConfig *isp_config,
        ia_rgbs_grid *rgbs_grid);

LIBEXPORT ia_err
ia_aic_myriad_statistics_convert_rgbs_grid(
    const icIspConfig *isp_config,
    ia_aiq_rgbs_grid *rgbs_grid);

/*!
 * \brief Converts Myriad ISP specific convolution filter response grid statistics to CCAT format.
 * ISP generated statistics may not be in the format in which AIQ algorithms expect. Statistics need to be converted
 * from various ISP formats into CCAT format.
 * \param[in]  ia_aic_myriad Mandatory. ia_aic_myriad instance handle.
 *
 * \param[out] out_fr_grid   Mandatory.\n
 *                           Pointer's to structure where converted statistics are stored.
 *                           Converted af grid statistics.
 * \return                   Error code.
 */
LIBEXPORT ia_err
ia_aic_myriad_statistics_convert_fr_grid_v2(
    const icIspConfig *isp_config,
    ia_filter_response_grid *out_fr_grid);

/*!
 * \brief Converts Myriad ISP specific convolution filter response grid statistics to IA_AIQ format.
 * ISP generated statistics may not be in the format in which AIQ algorithms expect. Statistics need to be converted
 * from various ISP formats into AIQ statistics format.
 * \param[in]  ia_aic_myriad Mandatory. ia_aic_myriad instance handle.
 *
 * \param[out] out_fr_grid   Mandatory.\n
 *                           Pointer's pointer where address of converted statistics are stored.
 *                           Converted af grid statistics. Output can be directly used as input in function ia_aiq_statistics_set.
 *                           if the external buffer is provided in out_af_grid it will be used otherwise internal buffer is used.
 * \return                   Error code.
 */
LIBEXPORT ia_err
ia_aic_myriad_statistics_convert_fr_grid(
    const icIspConfig *isp_config,
    ia_aiq_af_grid *out_fr_grid);

#ifdef __cplusplus
}
#endif
#endif /* IA_AIC_MYRIAD_H_ */
