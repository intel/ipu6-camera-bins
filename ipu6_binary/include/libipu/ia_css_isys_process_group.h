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

#ifndef __IA_CSS_ISYS_PROCESS_GROUP_H
#define __IA_CSS_ISYS_PROCESS_GROUP_H

#include "ia_css_isys_process_group_types.h" /* for ia_css_process_group_light_s */
#include "type_support.h"

typedef struct ia_css_process_group_light_s	ia_css_process_group_light_t;
typedef uint16_t 				ia_css_terminal_offset_t;		/**< To be used as element in the array of terminal offsets */


/**< Partial means without counting the terminal sizes contained */
extern unsigned int ia_css_process_group_light_get_partial_descriptor_size(
	const unsigned int terminal_count
);

/**< This returns the pointer where the terminal_index'th terminal offset is stored */
extern ia_css_terminal_offset_t *ia_css_process_group_light_get_terminal_offset_offset(
	const ia_css_process_group_light_t *process_group_light,
	const uint16_t terminal_index
);

/**< This will initialize the process_group_light basic struct (optimal packing) */
extern int ia_css_process_group_light_create(
	ia_css_process_group_light_t *process_group_light,
	const uint32_t total_process_group_light_size,	/**< Contains also the terminal sizes */
	const uint16_t terminal_count
);


#endif /* __IA_CSS_ISYS_PROCESS_GROUP_H */
