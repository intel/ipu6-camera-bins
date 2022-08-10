/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2017 - 2018 Intel Corporation.
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

#ifndef __PG_CONTROL_INIT_FRAMEWORK_COMPOSITION_H
#define __PG_CONTORL_INIT_FRAMEWORK_COMPOSITION_H

#include "ia_css_psys_process_types.h"
#include "ia_css_terminal_types.h"
#include "ia_css_kernel_user_param_types.h"
#include "type_support.h"

typedef int (*pg_control_init_sec_desc_init_t)(const ia_css_process_group_t *process_group,
		ia_css_program_control_init_terminal_t *terminal,
		unsigned int *payload_size);
typedef int (*pg_control_payload_init_t)(const ia_css_process_group_t *process_group,
		const ia_css_kernel_user_param_t *params,
		void *payload_address, uint16_t frag_idx);
typedef int (*pg_get_control_payload_init_buffer_size_t)(const ia_css_process_group_t *process_group,
		unsigned int *payload_size);

struct pg_control_init_framework_pg_ptrs_s {
	ia_css_program_group_ID_t                 pg_id;
	pg_control_init_sec_desc_init_t           pg_control_init_sec_desc_init;
	pg_control_payload_init_t                 pg_control_payload_init;
	pg_get_control_payload_init_buffer_size_t pg_get_control_payload_init_buffer_size;
};

extern const struct pg_control_init_framework_pg_ptrs_s pg_control_init_framework_pgs[];
extern const unsigned int pg_control_init_framework_pgs_count;

#endif /* __PG_CONTROL_INIT_FRAMEWORK_COMPOSITION_H */
