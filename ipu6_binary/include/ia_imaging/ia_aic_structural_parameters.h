/*
* INTEL CONFIDENTIAL
* Copyright (c) 2018-2019 Intel Corporation
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

#ifndef __IA_AIC_STRUCTURAL_PARAMETERS_HEADER__
#define __IA_AIC_STRUCTURAL_PARAMETERS_HEADER__

/* Define ALL_STRUCTURAL_PARAMETER_VARIABLES to expose using macro prototype
 * STRUCTURAL_PARAMETER_VARIABLE(variable_name, pal_uuid, output_class, member_function)
 *
 * NOTE: member_function must comply to prototype int32_t (output_class::*)(void)
 *
 * TODO: Several definitions below are for example only
 * TODO: Expect variable read-outs mapping to be auto-generated
 */
#define ALL_STRUCTURAL_PARAMETER_VARIABLES \
    STRUCTURAL_PARAMETER_VARIABLE(lsc_table_width, ia_pal_uuid_isp_lsc_1_1, ia_pal_lsc_1_1_output, lsc_table_width__GetFragSeq) \
    STRUCTURAL_PARAMETER_VARIABLE(bnr_radial_y_initial, ia_pal_uuid_isp_b2i_bnr_1_0, ia_pal_b2i_bnr_1_0_output, radial_y_initial__GetFragSeq)

/* For internal PAC compilation, include corresponding output-class headers */
#ifdef PAC_STRUCTURAL_PARAMETERS_INTERNAL
#include "ia_pal_lsc_1_1_class_autogen.h"
#include "ia_pal_b2i_bnr_1_0_class_autogen.h"
#endif

/* For public API, populate defined parameters as flat enum compatible with IaAicStructuralParameter */
#define STRUCTURAL_PARAMETER_VARIABLE(variable_name,pal_uuid, output_class, member_function)\
        IaAicStructuralParameter_##variable_name,

enum _IaAicStructuralParameter {
#ifdef ALL_STRUCTURAL_PARAMETER_VARIABLES
    ALL_STRUCTURAL_PARAMETER_VARIABLES
#endif
};

#undef STRUCTURAL_PARAMETER_VARIABLE
#endif
