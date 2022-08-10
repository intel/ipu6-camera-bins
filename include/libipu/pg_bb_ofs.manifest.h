/**
* INTEL CONFIDENTIAL
*
* Copyright (C) 2017 - 2019 Intel Corporation.
* All Rights Reserved.
*
* The source code contained or described herein and all documents
* related to the source code ("Material") are owned by Intel Corporation
* or licensors. Title to the Material remains with Intel
* Corporation or its licensors. The Material contains trade
* secrets and proprietary and confidential information of Intel or its
* licensors. The Material is protected by worldwide copyright
* and trade secret laws and treaty provisions. No part of the Material may
* be used, copied, reproduced, modified, published, uploaded, posted,
* transmitted, distributed, or disclosed in any way without Intel's prior
* express written permission.
*
* No License under any patent, copyright, trade secret or other intellectual
* property right is granted to or conferred upon you by disclosure or
* delivery of the Materials, either expressly, by implication, inducement,
* estoppel or otherwise. Any license under such intellectual property rights
* must be express and approved by Intel in writing.
*/

#ifndef __PG_BB_OFS_MANIFEST_H
#define __PG_BB_OFS_MANIFEST_H

#include "ia_css_progdesc_acc_symbol_ids.h"

#if HAS_DEC400 == 1
#include "vied_nci_psys_resource_model_private.h"

/* Note: Same NCI devices mappings for both supported pins on purpose.
 * The only reason why this enumeration has two entries is to work-around
 * genpipe limitations.
 */
enum PG_BB_OFS_DEVICE_ID {
	PG_BB_OFS_DEVICE_ID_DEC400_OFS_OUT_MAIN_DEV = VIED_NCI_DEVICE_ID_DEC400,
	PG_BB_OFS_DEVICE_ID_DEC400_OFS_OUT_DISPLAY_DEV = VIED_NCI_DEVICE_ID_DEC400
};
#endif

enum PG_BB_OFS_KERNEL_ID {
	PG_BB_OFS_KERNEL_ID_PIN_MAIN_OFS_OF0 = KERNEL_ID_OFS_OF_PIN_MAIN,
	PG_BB_OFS_KERNEL_ID_PIN_DISPLAY_OFS_OF1 = KERNEL_ID_OFS_OF_PIN_DISPLAY,
	PG_BB_OFS_KERNEL_ID_PIN_PP_OFS_OF2 = KERNEL_ID_OFS_OF_PIN_PP,
	PG_BB_OFS_KERNEL_ID_GET,
	PG_BB_OFS_KERNEL_ID_MAIN_OUTPUT,
	PG_BB_OFS_KERNEL_ID_DISPLAY_OUTPUT,
	PG_BB_OFS_KERNEL_ID_PP_OUTPUT,
	PG_BB_OFS_KERNEL_ID_PROGRAM_CONTROL_INIT,
};

enum TERMINAL_ID {
	PG_BB_OFS_TERMINAL_ID_GET = 0,
	PG_BB_OFS_TERMINAL_ID_MAIN_OUTPUT,
	PG_BB_OFS_TERMINAL_ID_DISPLAY_OUTPUT,
	PG_BB_OFS_TERMINAL_ID_PP_OUTPUT,
	PG_BB_OFS_TERMINAL_ID_PROGRAM_CONTROL_INIT,
	PG_BB_OFS_TERMINAL_ID_CACHED_PARAMETER_IN,
	PG_BB_OFS_TERMINAL_ID_PROGRAM_INIT,
	PG_BB_OFS_TERMINAL_ID_N
};

#endif /* __PG_BB_OFS_MANIFEST_H */
