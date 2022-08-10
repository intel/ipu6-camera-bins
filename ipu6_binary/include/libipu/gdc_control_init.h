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
#ifndef __GDC_CONTROL_INIT_H
#define __GDC_CONTROL_INIT_H

#include "ia_css_psys_terminal_private_types.h"
#include "bufqueue.host.h"
#include "ipu_dim_cfg_types.h"
#include "nci_mbr.h"
#include "nci_gdc_types.h"
#include "pg_control_init_support.h"


uint32_t
gdc_get_payload_size(void);

uint32_t
gdc_get_numberof_load_sections(void);

void
gdc_fill_load_section_descriptor(
	ia_css_program_control_init_program_desc_t *prog_ctrl_init_prog_desc);

int32_t
gdc_payload_fill(
		struct nci_gdc_kup *kup_cfg,
		enum nci_mbr_device_id mbr_dev_id,
		struct ipu_dim_cfg input_dim,
		uint32_t op_ack_addr[NCI_GDC_NUM_CHANS],
		bufqueue_t q_in,
		bufqueue_t q_out,
		unsigned out_msb_aligned,
		unsigned is_dst_packed,
		void *payload_address,
		load_section_desc_list_t load_sec_desc,
		ia_css_process_id_t process_id);

void
gdc_payload_print(void *cfg);


#endif /* __MBR_CONTROL_INIT_H */
