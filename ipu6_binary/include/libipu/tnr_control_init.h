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
#ifndef __TNR_CONTROL_INIT_H
#define __TNR_CONTROL_INIT_H

#include "ia_css_psys_terminal_private_types.h"
#include "bufqueue.host.h"
#include "pg_control_init_support.h"

uint32_t
tnr_control_init_get_payload_size(void);

uint32_t
tnr_control_init_get_numberof_load_sections(void);

int32_t
tnr_control_init_fill_load_section_descriptor(
		ia_css_program_control_init_program_desc_t *prog_ctrl_init_prog_desc,
		uint32_t base_section_id);

int32_t
tnr_control_init_payload_fill(
		void *payload_address,
		load_section_desc_list_t load_sec_desc,
		bufqueue_t q_in,       /* Input queue from which TNR consumes data */
		uint32_t ip_buf_rel_cmd_addr, /* Address to which TNR sends the release token for input Y-plane */
		bufqueue_t q_out,      /* Output queue to which TNR produces data */
		uint32_t op_buf_enq_cmd_addr, /* Address to which TNR sends process command after producing output */
		bufqueue_t q_ref_in,
		bufqueue_t q_ref_out,
		vied_nci_dev_chn_ID_t ref_out_dma_dev_id,
		uint32_t ref_out_dma_offset,
		uint32_t fragment_ack_addr,
		uint32_t fragment_ack_data);

#endif /* __TNR_CONTROL_INIT_H */
