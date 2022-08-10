/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2015 - 2016 Intel Corporation.
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

#ifndef __IA_CSS_ISYS_PROCESS_GROUP_TYPES_H
#define __IA_CSS_ISYS_PROCESS_GROUP_TYPES_H

#include "type_support.h"


struct ia_css_process_group_light_s {			/**< Structure as is is 64-bit aligned */
	uint32_t	size;				/**< Total size of this structure and all its underlying ones */
	uint16_t	terminals_offset_offset;	/**< offset of "ia_css_terminal_offset_t array[terminal_count]" containing terminal offsets on this process group */
	uint16_t	terminal_count;			/**< Number of terminals for this process group (param, program, spatial param) */
};


#endif /* __IA_CSS_ISYS_PROCESS_GROUP_TYPES_H */
