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
#ifndef __V2S_CONTROL_INIT_H
#define __V2S_CONTROL_INIT_H

#include "ia_css_common_io_types.h"
#include "ia_css_psys_terminal_private_types.h"
#include "vied_nci_psys_resource_model_private.h"
#include "bufqueue.host.h"
#include "pg_control_init_support.h"

int
v2s_payload_fill(
		vied_nci_v2s_id_t v2s_id,
		unsigned int ack_address,
		struct ia_css_terminal_descriptor_s *get_terminal,
		bufqueue_t q,
		void *payload_base,
		load_section_desc_list_t sec_desc_list);

int
v2s_get_payload_size(void);

int
v2s_fill_load_section_descriptor(
		vied_nci_v2s_id_t v2s_id,
		ia_css_program_control_init_program_desc_t *prog_ctrl_init_prog_desc,
		int format);

unsigned int
v2s_get_numberof_load_sections(void);

#endif /* __V2S_CONTROL_INIT_H */
