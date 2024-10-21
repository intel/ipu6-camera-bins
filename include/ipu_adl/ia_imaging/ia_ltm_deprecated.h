/*
 * Copyright 2016-2020 Intel Corporation
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
 * \file ia_ltm_deprecated.h
 * \brief Definitions and declarations of Intel LTM library.
 */


#ifndef _IA_LTM__DEPRECATED_H_
#define _IA_LTM__DEPRECATED_H_

#include "ia_ltm_types.h"
#include "ia_types.h"
#include "ia_aiq_types.h"
#include "ia_bcomp_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Input parameter structure for LTM/DRC algorithm.
 * Note that, even though all the input statistics and image are optional (i.e. yv_grid, rgbs,grid_ptr, hdr_rgbs_grid_ptr and input_image_ptr),
 * one of them is always needed. While certain LTM algorithms (selectable from tunings) can utilize different input, all algorithms can operate
 * on input_image_ptr data. Some inputs may provide certain PnP or IQ advantages over others, so all inputs should still be set if available in
 * order to allow the tuner make the appropriate choice (for instance rgbs_grid_ptr and hdr_rgbs_grid_ptr). Notice that input image or statistics
 * may or may not contain WB gains and CCM applied. Parameters needed by Optibright algorithm are marked with '(ob)' and parameters needed by LBCE are
 * marked with '(lb)'.
 */
typedef struct ia_ltm_input_params
{
    ia_ltm_level ltm_level;                 /*!< Mandatory. LTM level. -1 to use tuning defaults.*/
    ia_aiq_frame_use frame_use;             /*!< Mandatory. Target frame type of the LTM calculations (Preview, Still, video etc.). */
    float ev_shift;                         /*!< Optional. (ob) Exposure Value shift [-4,4]. */
    char ltm_strength_manual;               /*!< Optional. (ob) User defined manual control for ltm strength, will be casted into unsigned char, [0, 200], default is 100 and means no manual effect*/
    ia_aiq_ae_results *ae_results;          /*!< Optional. (ob) AEC output will be used by LTM.*/
    ia_isp_bxt_hdr_yv_grid_t *yv_grid;      /*!< Optional. (ob) Statistics used to calculate LTMs. (available only in IPU4 using FW DRC). */
    int16_t frame_width;                    /*!< Mandatory. Width of the frame where the results will be applied. */
    int16_t frame_height;                   /*!< Mandatory. Height of the frame where the results will be applied. */
    ia_aiq_rgbs_grid *rgbs_grid_ptr;        /*!< Optional. (lb) RGBS statistics. LTM may use this small grid instead of given larger grids to reduce PnP (available in IPU4 and onwards). */
    ia_aiq_hdr_rgbs_grid *hdr_rgbs_grid_ptr;/*!< Optional. (lb) HDR RGBS statistics. LTM may use this small grid instead of given larger grids to reduce PnP (available in IPU4 and onwards). */
    ia_ltm_input_image *input_image_ptr;    /*!< Optional. (ob)(lb) Image data of any resolution based on IQ requirements for particular use case from which LTM calculates local tone maps (HW generated image available in IPU5 and onwards). */
    ia_ltm_gtm_input_params *gtm_input_params_ptr;  /*!< Optional. (ob) GTM parameters of LTM if GTM should be applied inside LTM. */
} ia_ltm_input_params;

typedef struct ia_ltm_input_params_v1
{
    ia_ltm_level ltm_level;                         /*!< Mandatory. LTM level. -1 to use tuning defaults.*/
    float ev_shift;                                 /*!< Optional. (ob) Exposure Value shift [-4,4]. */
    char ltm_strength_manual;                       /*!< Optional. (ob) User defined manual control for ltm strength, will be casted into unsigned char, [0, 200], default is 100 and means no manual effect*/
    ia_aiq_ae_results *ae_results;                  /*!< Optional. (ob) AEC output will be used by LTM.*/
    ia_isp_bxt_hdr_yv_grid_t *yv_grid;              /*!< Optional. (ob) Statistics used to calculate LTMs. (available only in IPU4 using FW DRC). */
    int16_t frame_width;                            /*!< Mandatory. Width of the frame where the results will be applied. */
    int16_t frame_height;                           /*!< Mandatory. Height of the frame where the results will be applied. */
    ia_aiq_rgbs_grid *rgbs_grid_ptr;                /*!< Optional. (lb) RGBS statistics. LTM may use this small grid instead of given larger grids to reduce PnP (available in IPU4 and onwards). */
    ia_aiq_hdr_rgbs_grid *hdr_rgbs_grid_ptr;        /*!< Optional. (lb) HDR RGBS statistics. LTM may use this small grid instead of given larger grids to reduce PnP (available in IPU4 and onwards). */
    ia_ltm_input_image *input_image_ptr;            /*!< Optional. (ob)(lb) Image data of any resolution based on IQ requirements for particular use case from which LTM calculates local tone maps (HW generated image available in IPU5 and onwards). */
    ia_ltm_gtm_input_params *gtm_input_params_ptr;  /*!< Optional. (ob) GTM parameters of LTM if GTM should be applied inside LTM. */
} ia_ltm_input_params_v1;

/*!
 * \brief LTM calculation based on input parameters and frame statistics.
  *
 * \param[in] ia_ltm                        Mandatory.\n
 *                                          LTM instance handle.
 * \param[in] ltm_input_params              Mandatory.\n
 *                                          Input parameters for LTM calculations.
 * \param[out] ltm_results                  Mandatory.\n
 *                                          Pointer's pointer where address of LTM results are stored.
 * \return                                  Error code.
 */
LIBEXPORT ia_err
ia_ltm_run(ia_ltm *ia_ltm,
        const ia_ltm_input_params *ltm_input_params,
        ia_ltm_results **ltm_results,
        ia_ltm_drc_params **ltm_results_drc);

LIBEXPORT ia_err
ia_ltm_run_v1(ia_ltm *ia_ltm,
        const ia_ltm_input_params_v1 *ltm_input_params,
        ia_ltm_results **ltm_results,
        ia_ltm_drc_params **ltm_results_drc);


#ifdef __cplusplus
}
#endif

#endif /* _IA_LTM__DEPRECATED_H_ */
