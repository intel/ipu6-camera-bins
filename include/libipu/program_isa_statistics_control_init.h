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

#ifndef __PROGRAM_ISA_STATISTICS_CONTROL_INIT_H
#define __PROGRAM_ISA_STATISTICS_CONTROL_INIT_H

#include "type_support.h"
#include "ia_css_psys_process_types.h"
#include "ia_css_terminal_types.h"
#include "dev_api_dfm_types.h"
#include "resource_types.h"
#include "dfm_resource_types.h"
#include "vied_nci_psys_resource_model_private.h"
#include "spatial_param_interface.h"
#include "ipu_device_ff_devices.h"
#include "ipu_sequencer_info_descriptor.h"
#include "pg_control_init_support.h"
#include "program_isa_stat_shared.h"

typedef struct {
	dfm_port_resource_t dfm_acb;
	dfm_port_resource_t dfm_dma;
} dfm_stat_resources_t;

int
program_isa_statistics_payload_fill(
	const struct ipu_kernel_fragment_sequencer_info_desc_s *kernel_sequencer_info_desc,
	const ia_css_process_group_t *process_group,
	load_section_desc_list_t load_sec_desc_list,
	void *payload_base_address,
	int terminal_id,
	unsigned int spatial_parameter_terminal_out_section_count,
	vied_nci_lb_acb_id_t acb_res_id,
	dfm_stat_resources_t dfm_resources,
	enum ipu_device_ff_id ipu_device_ff_id,
	const interface_spatial_parameter_t *p_spatial,
	unsigned int dfm_num_buffers,
	resource_t dma_spatial,
	uint16_t frag_idx);

int
program_isa_statistics_get_payload_size(
	resource_t dma_spatial,
	dfm_stat_resources_t dfm_resources);

int
program_isa_statistics_fill_load_section_descriptor(
	ia_css_program_control_init_program_desc_t *prog_ctrl_init_prog_desc,
	vied_nci_lb_acb_id_t acb_res_id,
	resource_t dma_spatial,
	dfm_stat_resources_t dfm_resources);

int
program_isa_statistics_fill_connect_section_descriptor(
	ia_css_program_control_init_connect_section_desc_t *connect_sec_desc,
	resource_t dma_spatial,
	ia_css_terminal_ID_t terminal_id);

void
program_isa_statistics_set_desc_sid_pid(
	ia_css_program_control_init_program_desc_t *prog_ctrl_init_prog_desc,
	dfm_port_resource_t dfm_acb);

#endif /* __PROGRAM_ISA_STATISTICS_CONTROL_INIT_H */


