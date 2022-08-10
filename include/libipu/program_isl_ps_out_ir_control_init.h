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

#ifndef __PROGRAM_ISL_PS_OUT_IR_CONTROL_INIT_H
#define __PROGRAM_ISL_PS_OUT_IR_CONTROL_INIT_H

#include "type_support.h"
#include "ia_css_psys_process_types.h"
#include "ia_css_terminal_types.h"
#include "dev_api_dfm_types.h"
#include "str2mmio_control_init.h"
#include "resource_types.h"
#include "dfm_resource_types.h"
#include "ipu_resources_dma_term.h"
#include "bufqueue.host.h"
#include "pg_control_init_support.h"

typedef struct {
	dfm_port_resource_t dfm_ir_s2m_port;
	dfm_port_resource_t dfm_ir_dma_port;
} dfm_ir_resources_t;

/*
 * @brief       Fill ctrlinit payload of the program
 *
 * @param[in]   process_group           Process group
 * @param[in]   load_sec_desc           Progctrlinit terminal section descriptor
 * @param[in]   payload_base_address    Program's ctrlinit terminal payload start address
 * @param[in]   dma_cfg_buff    Temporary buffer to hold dma configuration
 *
 * @retval 0    Successful.
 * @retval 1    Error.
 */
int
program_isl_ps_out_ir_payload_fill(
	const ia_css_process_group_t *process_group,
	load_section_desc_list_t load_sec_desc_list,
	void *payload_base_address,
	int terminal_id,
	bufqueue_t q,
	vied_nci_pixel_str2mmio_id_t s2v_id,
	enum dev_api_dfm_agent dfm_agent_id,
	dfm_ir_resources_t dfm_resources,
	dma_resource_t dma_resource,
	struct ipu_resources_dma_descriptor_config *dma_cfg_buff,
	uint16_t frag_idx,
	uint32_t stream_id);

/*
 * @brief       Get ctrlinit payload size of the program
 *
 * @retval	Size of the program payload
 */
int
program_isl_ps_out_ir_get_payload_size(dfm_ir_resources_t dfm_resources);

/*
 * @brief       Fill load section descriptor of the program
 *
 * @param[in]   prog_ctrl_init_prog_desc Pointer to the program descriptor in
 *                                       which the section descriptor has to be filled
 *
 * @retval 0    Successful.
 * @retval 1    Error.
 */
int
program_isl_ps_out_ir_fill_load_section_descriptor(
	ia_css_program_control_init_program_desc_t *prog_ctrl_init_prog_desc,
	vied_nci_pixel_str2mmio_id_t s2m_id,
	dfm_ir_resources_t dfm_resources,
	dma_resource_t dma_resource);

/*
 * @brief       Fill connect section descriptor of the program
 *
 * @param[in]   connect_sec_desc        Pointer to the section descriptor to fill
 *
 * @retval 0    Successful.
 * @retval 1    Error.
 */
int
program_isl_ps_out_ir_fill_connect_section_descriptor(
	ia_css_program_control_init_connect_section_desc_t *connect_sec_desc,
	ia_css_terminal_ID_t terminal_id,
	dma_resource_t dma_resource);

void
program_isl_ps_out_ir_set_desc_sid_pid(
		ia_css_program_control_init_program_desc_t *prog_ctrl_init_prog_desc,
		dfm_ir_resources_t dfm_resources);

#endif /* __PROGRAM_ISL_PS_OUT_IR_CONTROL_INIT_H */
