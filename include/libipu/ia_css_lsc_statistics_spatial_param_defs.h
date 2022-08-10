/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2018 Intel Corporation
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


#ifndef __IA_CSS_LSC_STATISTICS_SPATIAL_PARAM_DEFS_H
#define __IA_CSS_LSC_STATISTICS_SPATIAL_PARAM_DEFS_H

#include "spatial_param_interface.h"
#include "ia_css_isa_parameter_defs.h"

/* ==================== LSC_SENSOR_TYPE_0 START==================== */

/* ----- spatial parameter out terminal: terminal program description ----- */
static const spatial_parameter_terminal_terminal_private_desc_t
spatial_parameter_lsc_in_terminal_terminal_private_desc_sensor_type_0 = {
		IA_CSS_ISA_SPATIAL_PARAMETER_TERMINAL_IN_LSC_SENSOR_TYPE_0_COMPUTE_UNITS_PER_ELEM,
		IA_CSS_ISA_SPATIAL_PARAMETER_TERMINAL_IN_LSC_SENSOR_TYPE_0_SECTION_COUNT
};

static const spatial_parameter_terminal_section_private_desc_t
spatial_parameter_lsc_in_terminal_section_private_desc_sensor_type_0[] = {
	{
		IA_CSS_ISA_SPATIAL_PARAMETER_TERMINAL_IN_LSC_SENSOR_TYPE_0_MAX_SLICE_SIZE_SECTION_0,
		IA_CSS_ISA_SPATIAL_PARAMETER_TERMINAL_IN_LSC_SENSOR_TYPE_0_SLICE_0_DEST_OFFSET_SECTION_0,
		IA_CSS_ISA_SPATIAL_PARAMETER_TERMINAL_IN_LSC_SENSOR_TYPE_0_NEXT_SLICE_OFFSET_SECTION_0,
		IA_CSS_ISA_SPATIAL_PARAMETER_TERMINAL_IN_LSC_SENSOR_TYPE_0_ELEM_SIZE_SECTION_0
	}
};

static const interface_spatial_parameter_t lsc_statistic_spatial_parameter_sensor_type_0 = {
	&spatial_parameter_lsc_in_terminal_terminal_private_desc_sensor_type_0,
	NULL,
	spatial_parameter_lsc_in_terminal_section_private_desc_sensor_type_0,
	NULL
};

/* ==================== LSC_SENSOR_TYPE_0 END ==================== */

/* ==================== LSC_SENSOR_TYPE_1 START==================== */

/* ----- spatial parameter out terminal: terminal program description ----- */
static const spatial_parameter_terminal_terminal_private_desc_t
spatial_parameter_lsc_in_terminal_terminal_private_desc_sensor_type_1 = {
		IA_CSS_ISA_SPATIAL_PARAMETER_TERMINAL_IN_LSC_SENSOR_TYPE_1_COMPUTE_UNITS_PER_ELEM,
		IA_CSS_ISA_SPATIAL_PARAMETER_TERMINAL_IN_LSC_SENSOR_TYPE_1_SECTION_COUNT
};

static const spatial_parameter_terminal_section_private_desc_t
spatial_parameter_lsc_in_terminal_section_private_desc_sensor_type_1[] = {
	{
		IA_CSS_ISA_SPATIAL_PARAMETER_TERMINAL_IN_LSC_SENSOR_TYPE_1_MAX_SLICE_SIZE_SECTION_0,
		IA_CSS_ISA_SPATIAL_PARAMETER_TERMINAL_IN_LSC_SENSOR_TYPE_1_SLICE_0_DEST_OFFSET_SECTION_0,
		IA_CSS_ISA_SPATIAL_PARAMETER_TERMINAL_IN_LSC_SENSOR_TYPE_1_NEXT_SLICE_OFFSET_SECTION_0,
		IA_CSS_ISA_SPATIAL_PARAMETER_TERMINAL_IN_LSC_SENSOR_TYPE_1_ELEM_SIZE_SECTION_0
	}
};

static const interface_spatial_parameter_t lsc_statistic_spatial_parameter_sensor_type_1 = {
	&spatial_parameter_lsc_in_terminal_terminal_private_desc_sensor_type_1,
	NULL,
	spatial_parameter_lsc_in_terminal_section_private_desc_sensor_type_1,
	NULL
};

/* ==================== LSC_SENSOR_TYPE_1 END ==================== */

/* ==================== LSC_SENSOR_TYPE_2 START==================== */

/* ----- spatial parameter out terminal: terminal program description ----- */
static const spatial_parameter_terminal_terminal_private_desc_t
spatial_parameter_lsc_in_terminal_terminal_private_desc_sensor_type_2 = {
		IA_CSS_ISA_SPATIAL_PARAMETER_TERMINAL_IN_LSC_SENSOR_TYPE_2_COMPUTE_UNITS_PER_ELEM,
		IA_CSS_ISA_SPATIAL_PARAMETER_TERMINAL_IN_LSC_SENSOR_TYPE_2_SECTION_COUNT
};

static const spatial_parameter_terminal_section_private_desc_t
spatial_parameter_lsc_in_terminal_section_private_desc_sensor_type_2[] = {
	{
		IA_CSS_ISA_SPATIAL_PARAMETER_TERMINAL_IN_LSC_SENSOR_TYPE_2_MAX_SLICE_SIZE_SECTION_0,
		IA_CSS_ISA_SPATIAL_PARAMETER_TERMINAL_IN_LSC_SENSOR_TYPE_2_SLICE_0_DEST_OFFSET_SECTION_0,
		IA_CSS_ISA_SPATIAL_PARAMETER_TERMINAL_IN_LSC_SENSOR_TYPE_2_NEXT_SLICE_OFFSET_SECTION_0,
		IA_CSS_ISA_SPATIAL_PARAMETER_TERMINAL_IN_LSC_SENSOR_TYPE_2_ELEM_SIZE_SECTION_0
	}
};

static const interface_spatial_parameter_t lsc_statistic_spatial_parameter_sensor_type_2 = {
	&spatial_parameter_lsc_in_terminal_terminal_private_desc_sensor_type_2,
	NULL,
	spatial_parameter_lsc_in_terminal_section_private_desc_sensor_type_2,
	NULL
};

/* ==================== LSC_SENSOR_TYPE_2 END ==================== */

/*usage: lsc_statistic_spatial_parameter_arr[<program_isl_acc_lsc_sensor_type_e>]*/
static const interface_spatial_parameter_t *lsc_statistic_spatial_parameter_arr[] = {
	&lsc_statistic_spatial_parameter_sensor_type_0,
	&lsc_statistic_spatial_parameter_sensor_type_1,
	&lsc_statistic_spatial_parameter_sensor_type_2
};

#endif /* __IA_CSS_LSC_STATISTICS_SPATIAL_PARAM_DEFS_H */

