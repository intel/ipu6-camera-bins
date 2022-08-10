/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2017 - 2020 Intel Corporation.
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

#ifndef __ACB_CONTROL_INIT_DEP_C__
#define __ACB_CONTROL_INIT_DEP_C__

#include "acb_control_init.h"
#include "logger.h"

int
acb_payload_fill(
		vied_nci_lb_acb_id_t acb_id,
		const ia_css_process_group_t *process_group,
		load_section_desc_list_t load_sec_desc_list,
		uint32_t ack_addr,
		uint32_t ack_data,
		void *payload_address,
		s_resolution_t res,
		nci_acb_port_t in_select,
		nci_acb_port_t out_select)
{
	int retval = 0;
	int size = 0;
	uint32_t scale_mult, scale_nf, ignore_line_num;
	unsigned load_sec_mem_offset0 = pg_control_init_get_mem_offset_at_index(load_sec_desc_list, 0);
	int load_sec_size0 = pg_control_init_get_mem_size_at_index(load_sec_desc_list, 0);
	int load_sec_size1 = pg_control_init_get_mem_size_at_index(load_sec_desc_list, 1);
	(void) process_group;

	payload_address = (char *)payload_address + load_sec_mem_offset0;
	scale_mult = 1;

	switch (acb_id) {
	case VIED_NCI_ACB_SIS_A_ID:
	case VIED_NCI_ACB_SIS_B_ID:
	case VIED_NCI_ACB_R2I_DS_A_ID:
#if HAS_FF_R2I_DS_B
	case VIED_NCI_ACB_R2I_DS_B_ID:
#endif
		scale_nf = 1;
		ignore_line_num = 1;
		break;
	case VIED_NCI_ACB_PAF_ID:
               scale_nf = 0;
               ignore_line_num = 1;
               break;
	default:
		scale_nf = 0;
		ignore_line_num = 0;
		break;
	}

	size = acb_open(acb_id,
		ack_addr,
		ack_data,
		payload_address,
		res,
		scale_mult,
		scale_nf,
		ignore_line_num,
		in_select,
		out_select);

	PRINT_LOG(LOGLEVEL_INFO, "Init@Host: Inside %s, size: %d", __func__, size);
	assert(acb_get_payload_size() == size);
	/*
	 * the acb_open function will fill two adjacent payloads.
	 * so for the size check we need to assert the total size.
	 */
	assert(load_sec_size0 + load_sec_size1 == size);
	retval = (acb_get_payload_size() == size) ? 0 : 1;

	return retval;
}
#endif /* __ACB_CONTROL_INIT_DEP_C__ */
