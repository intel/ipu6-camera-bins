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

#ifndef __PROGRAM_ISA_SCALED_OUT_TO_PSA_IN_VMEM_INIT_H
#define __PROGRAM_ISA_SCALED_OUT_TO_PSA_IN_VMEM_INIT_H

#include "type_support.h"
#include "ia_css_psys_process_types.h"
#include "ia_css_terminal_types.h"
#include "resource_types.h"
#include "ia_css_common_io_types.h"
#include "bufqueue.host.h"

#include "ia_css_kernel_user_param_instance_types.h"
#include "pg_control_init_support.h"

#include "vied_nci_psys_resource_model_private.h"
#include "ipu_device_strm_pack_devices.h"
#include "common_io.shared.h"


typedef struct {
	dfm_port_resource_t dfm_s2v;
	dfm_port_resource_t dfm_v2s;
} dfm_scaled_isa2psa_resources_t;

int
program_isa_scaled_out_to_psa_in_vmem_payload_fill(
	const s_resolution_t *resolution,
	load_section_desc_list_t load_sec_desc_list,
	void *payload_base_address,
	bufqueue_t q, vied_nci_s2v_id_t s2v_id,
	enum dev_api_dfm_agent agent_id,
	dfm_scaled_isa2psa_resources_t dfm_scaled_isa2psa_resources);

int
program_isa_scaled_out_to_psa_in_vmem_get_payload_size(dfm_scaled_isa2psa_resources_t dfm_scaled_isa2psa_resources);

int
program_isa_scaled_out_to_psa_in_vmem_fill_load_section_descriptor(
	ia_css_program_control_init_program_desc_t *prog_ctrl_init_prog_desc, vied_nci_s2v_id_t s2v_id, enum ipu_device_strm_pack_dev_id strm_pack_id,
	dfm_scaled_isa2psa_resources_t dfm_scaled_isa2psa_resources);

void
program_isa_scaled_out_to_psa_in_vmem_set_desc_sid_pid(
		ia_css_program_control_init_program_desc_t *prog_ctrl_init_prog_desc,
		dfm_scaled_isa2psa_resources_t dfm_scaled_isa2psa_resources);

unsigned int
program_isa_scaled_out_to_psa_in_vmem_get_numberof_load_sections(dfm_scaled_isa2psa_resources_t dfm_scaled_isa2psa_resources);

#endif /* __PROGRAM_ISA_SCALED_OUT_TO_PSA_IN_VMEM_INIT_H */
