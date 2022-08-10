/*
* INTEL CONFIDENTIAL
* Copyright (c) 2016-2021 Intel Corporation
* All Rights Reserved.
*
* The source code contained or described herein and all documents related to
* the source code ("Material") are owned by Intel Corporation or its
* suppliers or licensors. Title to the Material remains with Intel
* Corporation or its suppliers and licensors. The Material may contain trade
* secrets and proprietary and confidential information of Intel Corporation
* and its suppliers and licensors, and is protected by worldwide copyright
* and trade secret laws and treaty provisions. No part of the Material may be
* used, copied, reproduced, modified, published, uploaded, posted,
* transmitted, distributed, or disclosed in any way without Intel's prior
* express written permission.
*
* No license under any patent, copyright, trade secret or other intellectual
* property right is granted to or conferred upon you by disclosure or
* delivery of the Materials, either expressly, by implication, inducement,
* estoppel or otherwise. Any license under such intellectual property rights
* must be express and approved by Intel in writing.
*
* Unless otherwise agreed by Intel in writing, you may not remove or alter
* this notice or any other notice embedded in Materials by Intel or Intel's
* suppliers or licensors in any way.
*/
#ifndef IA_PAL_DIRECT_H
#define IA_PAL_DIRECT_H

#include "ia_aiq_types.h"
#include "ia_ltm_types.h"
#include "ia_dvs_types.h"
#include "ia_isp_bxt_types.h"
#include "ia_cmc_types.h"
#include "ia_view_types.h"
#include "ia_tnr7_types.h"
#include "ia_bcomp_types.h"

/*!
 *\brief Enumeration for direct results UUIDs.
 * UUIDs are used when fetching direct results from InputData class.
 */
typedef enum
{
    ia_pal_direct_results_uuid_start,
    ia_pal_direct_results_uuid_aiq_sa_results = ia_pal_direct_results_uuid_start,
    ia_pal_direct_results_uuid_aiq_hist_weight_grid,
    ia_pal_direct_results_uuid_ltm_drc_params,
    ia_pal_direct_results_uuid_dvs_morph_table,
    ia_pal_direct_results_uuid_ltm_results,
    ia_pal_direct_results_uuid_cmc_phase_difference,
    ia_pal_direct_results_uuid_cmc_general_data,
    ia_pal_direct_results_uuid_dvs_image_transformation,
    ia_pal_direct_results_uuid_cmc_parsed_geometric_distortion2,
    ia_pal_direct_results_uuid_cmc_lateral_chromatic_aberration_correction,
    ia_pal_direct_results_uuid_cmc_optomechanics,
    ia_pal_direct_results_uuid_view_params,
    ia_pal_direct_results_uuid_bcomp_results,
    ia_pal_direct_results_uuid_rgbir_results,
    ia_pal_direct_results_uuid_count, /* Keep this last */
} ia_pal_direct_results_uuid;

/*!
 * \brief Direct results coming from algorithms without conversion to algo API structures.
 * In case GAIC is not used, for improved PnP, it's not needed to copy large buffers from algorithm results to
 * algo API structures. Define a structure, where algorithm results can be passed directly to PAL.
 * ia_pal_direct_results structure must contain only pointers to other structures (no copied structures)!
 */
typedef struct
{
    ia_aiq_sa_results_v1 const *direct_ia_aiq_sa_results_v1;
    ia_aiq_hist_weight_grid const *direct_ia_aiq_hist_weight_grid;
    ia_ltm_drc_params const *direct_ia_ltm_drc_params;
    ia_dvs_morph_table const *direct_ia_dvs_morph_table;
    ia_ltm_results const *direct_ia_ltm_results;
    cmc_phase_difference_t const *direct_cmc_phase_difference_t;
    cmc_general_data_t const *direct_cmc_general_data_t;
    ia_dvs_image_transformation const *direct_ia_dvs_image_transformation;
    cmc_parsed_geometric_distortion2_t const *direct_cmc_parsed_geometric_distortion2_t;
    cmc_lateral_chromatic_aberration_correction const *direct_cmc_lateral_chromatic_aberration_correction;
    cmc_optomechanics_t const *direct_cmc_optomechanics_t;
    ia_view_t const *direct_ia_view_t;
    ia_bcomp_results const *direct_ia_bcomp_results;
    cmc_parsed_sensor_decompand_t const *direct_cmc_parsed_sensor_decompand_t;
    cmc_parsed_pipe_compand_t const *direct_cmc_parsed_pipe_compand_t;
    cmc_parsed_pipe_decompand_t const* direct_cmc_parsed_pipe_decompand_t;
    ia_tnr7_t const* direct_ia_tnr7_t;
    ia_aiq_ir_weight_t const* direct_ia_aiq_ir_weight_grid;
    ia_aiq_rgbir_t const* direct_ia_aiq_rgbir_t;
    cmc_parsed_cbd_t *direct_cmc_parsed_cbd_t;
	ia_aiq_gbce_results const* direct_ia_aiq_gbce_results;
    ia_aiq_scd_results const* direct_ia_aiq_scd_results;
} ia_pal_direct_results;

#endif // IA_PAL_DIRECT_H