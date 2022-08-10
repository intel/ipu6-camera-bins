/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2017 Intel Corporation
 * All Rights Reserved.
 *
 * The source code contained or described herein and all documents related to
 * the source code ("Material") are owned by Intel Corporation or its
 * suppliers or licensors.Title to the Material remains with Intel
 * Corporation or its suppliers and licensors.The Material may contain trade
 * secrets and proprietary and confidential information of Intel Corporation
 * and its suppliers and licensors, and is protected by worldwide copyright
 * and trade secret laws and treaty provisions.No part of the Material may be
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
 * this notice or any other notice embedded in Materials by Intel or Intels
 * suppliers or licensors in any way.
 */


#ifndef __IA_CSS_DVS_STATISTICS_SPATIAL_PARAM_DEFS_H
#define __IA_CSS_DVS_STATISTICS_SPATIAL_PARAM_DEFS_H

#include "spatial_param_interface.h"
#include "ia_css_psa_parameter_defs.h"

/* ----- spatial parameter out terminal: terminal program description ----- */
const spatial_parameter_terminal_terminal_private_desc_t spatial_parameter_dvs_mv_l0_out_terminal_terminal_private_desc = {
	IA_CSS_PSA_SPATIAL_PARAMETER_TERMINAL_OUT_DVS_MV_L0_COMPUTE_UNITS_PER_ELEM,
	IA_CSS_PSA_SPATIAL_PARAMETER_TERMINAL_OUT_DVS_MV_L0_SECTION_COUNT
};
const spatial_parameter_terminal_section_private_desc_t spatial_parameter_dvs_mv_l0_out_terminal_section_private_desc[] = {
	{
		IA_CSS_PSA_SPATIAL_PARAMETER_TERMINAL_OUT_DVS_MV_L0_MAX_SLICE_SIZE_SECTION_0,
		IA_CSS_PSA_SPATIAL_PARAMETER_TERMINAL_OUT_DVS_MV_L0_SLICE_0_DEST_OFFSET_SECTION_0,
		IA_CSS_PSA_SPATIAL_PARAMETER_TERMINAL_OUT_DVS_MV_L0_NEXT_SLICE_OFFSET_SECTION_0,
		IA_CSS_PSA_SPATIAL_PARAMETER_TERMINAL_OUT_DVS_MV_L0_ELEM_SIZE_SECTION_0
	}
};
const interface_spatial_parameter_t dvs_mv_l0_statistic_spatial_parameter = {
	NULL,
	&spatial_parameter_dvs_mv_l0_out_terminal_terminal_private_desc,
	NULL,
	spatial_parameter_dvs_mv_l0_out_terminal_section_private_desc
};

const spatial_parameter_terminal_terminal_private_desc_t spatial_parameter_dvs_mv_l1_out_terminal_terminal_private_desc = {
	IA_CSS_PSA_SPATIAL_PARAMETER_TERMINAL_OUT_DVS_MV_L1_COMPUTE_UNITS_PER_ELEM,
	IA_CSS_PSA_SPATIAL_PARAMETER_TERMINAL_OUT_DVS_MV_L1_SECTION_COUNT
};
const spatial_parameter_terminal_section_private_desc_t spatial_parameter_dvs_mv_l1_out_terminal_section_private_desc[] = {
	{
		IA_CSS_PSA_SPATIAL_PARAMETER_TERMINAL_OUT_DVS_MV_L1_MAX_SLICE_SIZE_SECTION_0,
		IA_CSS_PSA_SPATIAL_PARAMETER_TERMINAL_OUT_DVS_MV_L1_SLICE_0_DEST_OFFSET_SECTION_0,
		IA_CSS_PSA_SPATIAL_PARAMETER_TERMINAL_OUT_DVS_MV_L1_NEXT_SLICE_OFFSET_SECTION_0,
		IA_CSS_PSA_SPATIAL_PARAMETER_TERMINAL_OUT_DVS_MV_L1_ELEM_SIZE_SECTION_0
	}
};
const interface_spatial_parameter_t dvs_mv_l1_statistic_spatial_parameter = {
	NULL,
	&spatial_parameter_dvs_mv_l1_out_terminal_terminal_private_desc,
	NULL,
	spatial_parameter_dvs_mv_l1_out_terminal_section_private_desc
};

const spatial_parameter_terminal_terminal_private_desc_t spatial_parameter_dvs_mv_l2_out_terminal_terminal_private_desc = {
	IA_CSS_PSA_SPATIAL_PARAMETER_TERMINAL_OUT_DVS_MV_L2_COMPUTE_UNITS_PER_ELEM,
	IA_CSS_PSA_SPATIAL_PARAMETER_TERMINAL_OUT_DVS_MV_L2_SECTION_COUNT
};
const spatial_parameter_terminal_section_private_desc_t spatial_parameter_dvs_mv_l2_out_terminal_section_private_desc[] = {
	{
		IA_CSS_PSA_SPATIAL_PARAMETER_TERMINAL_OUT_DVS_MV_L2_MAX_SLICE_SIZE_SECTION_0,
		IA_CSS_PSA_SPATIAL_PARAMETER_TERMINAL_OUT_DVS_MV_L2_SLICE_0_DEST_OFFSET_SECTION_0,
		IA_CSS_PSA_SPATIAL_PARAMETER_TERMINAL_OUT_DVS_MV_L2_NEXT_SLICE_OFFSET_SECTION_0,
		IA_CSS_PSA_SPATIAL_PARAMETER_TERMINAL_OUT_DVS_MV_L2_ELEM_SIZE_SECTION_0
	}
};
const interface_spatial_parameter_t dvs_mv_l2_statistic_spatial_parameter = {
	NULL,
	&spatial_parameter_dvs_mv_l2_out_terminal_terminal_private_desc,
	NULL,
	spatial_parameter_dvs_mv_l2_out_terminal_section_private_desc
};

#endif /* __IA_CSS_DVS_STATISTICS_SPATIAL_PARAM_DEFS_H */
