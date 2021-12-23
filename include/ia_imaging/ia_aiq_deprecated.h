/*
 * Copyright 2018-2021 Intel Corporation
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
 * \file ia_aiq_deprecated.h
 * \brief Definitions and declarations of Intel 3A library.
 */

#ifndef IA_AIQ_DEPRECATED_H_
#define IA_AIQ_DEPRECATED_H_

#include "ia_aiq_types.h"
#include "ia_aiq_types_deprecated.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
  Forward declaration of struct declared in ia_aiq.h
*/
struct ia_aiq_pa_input_params;

/*!
* \brief Parameter adaptor calculations for the next frame.
* Compute generic parameters (Color Correction Matrix and Black Level Correction),
* which should be used to correct the next frame. Calculations are based on previously calculated AIQ algorithm results.
* These generic results are converted to ISP specific parameters by ia_isp component.
*
* \param[in] ia_aiq                Mandatory.\n
*                                  AIQ instance handle.
* \param[in] pa_input_params       Mandatory.\n
*                                  Input parameters for PA calculations.
* \param[out] pa_results           Mandatory.\n
*                                  Pointer's pointer where address of parameter adaptor results are stored.

* \return                          Error code.
*/
LIBEXPORT ia_err
ia_aiq_pa_run(ia_aiq *a_ia_aiq_ptr,
     const struct ia_aiq_pa_input_params *pa_input_params,
     ia_aiq_pa_results **pa_results);

/*!
 * \brief Set event statistics.
 * Some of the AIQ algorithms benefit from sensor information which tells about the conditions in which the device is in use
 *
 * \param[in] ia_aiq                        Mandatory.\n
 *                                          AIQ instance handle.
 * \param[in] sensor_events_input           Mandatory.\n
 *                                          Sensor events input holds data from libsensorhub.
 * \return                                  Error code.
 */
LIBEXPORT ia_err
ia_aiq_sensor_events_set(ia_aiq *ia_aiq_ptr, const ia_aiq_sensor_events *sensor_events_input);


/*!
 *  \brief Input parameter structure for AE algorithm.
 */
typedef struct
{
    unsigned int num_exposures;                                 /*!< Mandatory. The number of exposure outputs to have. Must be positive. One for LDR, two or more for HDR/exposure bracketing. */
    ia_aiq_frame_use frame_use;                                 /*!< Mandatory. Target frame type of the AEC calculations (Preview, Still, video etc.). */
    ia_aiq_flash_mode flash_mode;                               /*!< Mandatory. Manual flash mode. If AEC should make flash decision, set mode to ia_aiq_flash_mode_auto. */
    ia_aiq_ae_operation_mode operation_mode;                    /*!< Mandatory. AEC operation mode. */
    ia_aiq_ae_metering_mode metering_mode;                      /*!< Mandatory. AEC metering mode. */
    ia_aiq_ae_priority_mode priority_mode;                      /*!< Mandatory. AEC priority mode. */
    ia_aiq_ae_flicker_reduction flicker_reduction_mode;         /*!< Mandatory. AEC flicker reduction mode. */
    ia_aiq_exposure_sensor_descriptor *sensor_descriptor;       /*!< Mandatory although function will not return error, if not given.
                                                                     Sensor specific descriptor and limits of the used sensor mode for target frame use.
                                                                     AEC will not limit and calculate sensor specific parameters, if not given */
    unsigned int num_sensor_descriptors;                        /*!< Mandatory. The number of sensor descriptors given in the above pointer.
                                                                     Used to specify different sensor descriptors for each exposure. */
    ia_rectangle *exposure_window;                              /*!< Optional. Rectangle of area which AEC uses to to calculate new exposure parameters. */
    ia_coordinate *exposure_coordinate;                         /*!< Optional. Coordinate for a point in which the exposure should be prioritized.
                                                                     AEC increases weight of given point in final AEC results. */
    float ev_shift;                                             /*!< Optional. Exposure Value shift [-4,4]. */
    long *manual_exposure_time_us;                              /*!< Optional. Manual exposure time in microseconds. NULL if NA. Otherwise, array of values
                                                                     of num_exposures length. Order of exposure times corresponds to exposure_index of ae_results,
                                                                     e.g., manual_exposure_time_us[ae_results->exposures[0].exposure_index] = 33000; */
    float *manual_analog_gain;                                  /*!< Optional. Manual analog gain. NULL if NA. Otherwise, array of values of num_exposures length.
                                                                     Order of gain values corresponds to exposure_index of ae_results,
                                                                     e.g., manual_analog_gain[ae_results->exposures[0].exposure_index] = 4.0f; */
    short *manual_iso;                                          /*!< Optional. Manual ISO. Overrides manual_analog_gain. NULL if NA. Otherwise, array of values
                                                                     of num_exposures length. Order of ISO values corresponds to exposure_index of ae_results,
                                                                     e.g., manual_iso[ae_results->exposures[0].exposure_index] = 100; */
    ia_aiq_ae_features *aec_features;                           /*!< Optional. AEC features in use when calculating new exposure parameters. */
    ia_aiq_ae_manual_limits *manual_limits;                     /*!< Optional. Manual limits which override limits defined in AEC tunings. */
    float manual_aperture_fn;                                   /*!< Optional. Manual f-number of aperture (e.g. 2.8), -1.0 for N/A. Used only with P iris. */
    ia_aiq_aperture_control_dc_iris_command manual_dc_iris_command; /*!< Optional. Used only with DC iris. 0 (auto) for N/A. */
    ia_aiq_ae_exposure_distribution_priority exposure_distribution_priority; /*!< Mandatory. AEC exposure distribution priority mode. */
    float manual_convergence_time;                              /*!< Optional. Manual AEC convergence speed in seconds. -1.0 if NA. Overrides convergence speed from tunings. */
} ia_aiq_ae_input_params;

/*!
 * \brief AEC calculation based on input parameters and frame statistics.
 * AE calculates new exposure parameters to be used for the next frame based on previously given statistics and user parameters.
 *
 * \param[in] ia_aiq                Mandatory.\n
 *                                  AIQ instance handle.
 * \param[in] ae_input_params       Mandatory.\n
 *                                  Input parameters for AEC calculations.
 * \param[out] ae_results           Mandatory.\n
 *                                  Pointer's pointer where address of ISP parameters are stored.
 *                                  Results from AEC calculations. Results can be used directly as input for AIC.
 * \return                          Error code.
 */
LIBEXPORT ia_err
ia_aiq_ae_run(ia_aiq *a_ia_aiq_ptr,
              const ia_aiq_ae_input_params *ae_input_params,
              ia_aiq_ae_results **ae_results);

/*!
* \brief Get the AEC calculated histograms.
* AE calculates histograms from the RGBS grid.
*
* \param[in] ia_aiq                Mandatory.\n
*                                  AIQ instance handle.
* \return                          Pointer to the calculated histograms.
*/
LIBEXPORT ia_aiq_histogram *
ia_aiq_get_histograms(ia_aiq *a_ia_aiq_ptr);

/*
 *  \brief Input parameter structure for Shading Adaptor. DEPRECATED
 */
typedef struct
{
    ia_aiq_frame_use frame_use;                      /*!< Mandatory. Target frame type of the AIC calculations (Preview, Still, video etc.). */
    ia_aiq_frame_params *sensor_frame_params;        /*!< Mandatory. Sensor frame parameters. Describe frame scaling/cropping done in sensor. */
    ia_aiq_awb_results *awb_results;                 /*!< Mandatory. WB results which are to be used to calculate next ISP parameters (WB gains, color matrix,etc). */
} ia_aiq_sa_input_params;

/*!
 * \brief Shading Adaptor calculations for the next frame.
 * Compute shading correction parameters.
 * which should be used to correct the next frame. Calculations are based on previously calculated AIQ algorithm results.
 * These generic results are converted to ISP specific parameters by ia_isp component.
 * DEPRECATED
 *
 * \param[in] a_ia_aiq_ptr          Mandatory.\n
 *                                  AIQ instance handle.
 * \param[in] a_sa_input_params     Mandatory.\n
 *                                  Input parameters for SA calculations.
 * \param[out] a_sa_results         Mandatory.\n
 *                                  Pointer's pointer where address of shading adaptor results are stored.
 * \return                          Error code.
 */
LIBEXPORT ia_err
ia_aiq_sa_run(ia_aiq *a_ia_aiq_ptr,
                const ia_aiq_sa_input_params *a_sa_input_params,
                ia_aiq_sa_results **a_sa_results);


/*!
* \brief Shading Adaptor calculations for the next frame.
* Compute shading correction parameters.
* which should be used to correct the next frame. Calculations are based on previously calculated AIQ algorithm results.
* These generic results are converted to ISP specific parameters by ia_isp component.
*
* \param[in] a_ia_aiq_ptr          Mandatory.\n
*                                  AIQ instance handle.
* \param[in] a_sa_input_params     Mandatory.\n
*                                  Input parameters for SA calculations.
* \param[out] a_sa_results         Mandatory.\n
*                                  Pointer's pointer where address of shading adaptor results are stored.
* \return                          Error code.
*/
LIBEXPORT ia_err
ia_aiq_sa_run_v1(ia_aiq *a_ia_aiq_ptr,
                const ia_aiq_sa_input_params_v1 *a_sa_input_params,
                ia_aiq_sa_results **a_sa_results);

/*!
*  \brief Input parameter structure for AWB algorithm.
*/
typedef struct
{
    ia_aiq_frame_use frame_use;                       /*!< Mandatory. Target frame type of the AWB calculations (Preview, Still, video etc.). */
    ia_aiq_awb_operation_mode scene_mode;             /*!< Mandatory. AWB scene mode. */
    ia_aiq_awb_manual_cct_range *manual_cct_range;    /*!< Optional. Manual CCT range. Used only if AWB scene mode 'ia_aiq_awb_operation_manual_cct_range' is used. */
    ia_coordinate *manual_white_coordinate;           /*!< Optional. Manual white point coordinate relative to the full FOV of the scene. Used only if AWB scene mode 'ia_aiq_awb_operation_manual_white' is used. */
    float manual_convergence_time;                    /*!< Optional. Manual AWB convergence speed in seconds. -1.0 if NA. Overrides convergence speed from tunings. */
} ia_aiq_awb_input_params;

/*!
* \brief AWB calculation based on input parameters and frame statistics.
*
* \param[in] ia_aiq                Mandatory.\n
*                                  AIQ instance handle.
* \param[in] awb_input_params      Mandatory.\n
*                                  Input parameters for AWB calculations.
* \param[out] awb_results          Mandatory.\n
*                                  Pointer's pointer where address of AWB results are stored.
*                                  Results from AWB calculations. Results can be used directly as input for ia_isp.
* \return                          Error code.
*/
LIBEXPORT ia_err
ia_aiq_awb_run(ia_aiq *a_ia_aiq_ptr,
const ia_aiq_awb_input_params *awb_input_params,
ia_aiq_awb_results **awb_results);


#ifdef __cplusplus
}
#endif

#endif /* IA_AIQ_DEPRECATED_H_ */
