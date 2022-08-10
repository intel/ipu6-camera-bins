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

#ifndef __PROGRAM_PSA_OUT_NV12_S2V_DMA_CONTROL_INIT_H
#define __PROGRAM_PSA_OUT_NV12_S2V_DMA_CONTROL_INIT_H

#include "type_support.h"
#include "ia_css_psys_process_types.h"
#include "ia_css_terminal_types.h"
#include "math_support.h"
#include "isp_global.h"
#include "pg_control_init_support.h"

/**
 * @brief       Fill ctrlinit payload of the program
 * @param[in]   process_group           Process group
 * @param[in]   load_sec_desc           Progctrlinit terminal section descriptor
 * @param[in]   payload_address         Program's ctrlinit terminal payload start address
 * @param[in]   put_terminal_id         Terminal ID of process group this program is connected to
 * @retval 0    Successful.
 * @retval 1    Error.
 */
int
program_psa_out_nv12_s2v_dma_payload_fill(
	const ia_css_process_group_t *process_group,
	load_section_desc_list_t load_sec_desc_list,
	void *payload_address,
	int put_terminal_id,
	ia_css_frame_format_type_t format,
	uint16_t frag_idx,
	uint32_t *stream_ids_array,
	unsigned int num_of_streams);

/**
 * @brief       Get ctrlinit payload size of the program
 * @retval	Size of the program payload
 */
int
program_psa_out_nv12_s2v_dma_get_payload_size(void);

/**
 * @brief       Fill load section descriptor of the program
 * @param[in]   prog_ctrl_init_prog_desc Pointer to the program descriptor to add the section descriptor
 *
 * @retval 0    Successful.
 * @retval 1    Error.
 */
int
program_psa_out_nv12_s2v_dma_fill_load_section_descriptor(
	ia_css_program_control_init_program_desc_t *prog_ctrl_init_prog_desc);

/**
 * @brief       Fill connect section descriptor of the program
 * @param[in]   connect_sec_desc        Pointer to the section descriptor to fill
 * @param[in]   connect_sec_count       Number of objects in connect_sec_desc
 * @param[in]   put_terminal_id         Terminal ID of process group this program is connected to
 * @retval 0    Successful.
 * @retval 1    Error.
 */
int
program_psa_out_nv12_s2v_dma_fill_connect_section_descriptor(
	ia_css_program_control_init_connect_section_desc_t *connect_sec_desc,
	unsigned int connect_sec_count,
	int put_terminal_id);

void
program_psa_out_nv12_s2v_dma_set_desc_sid_pid(ia_css_program_control_init_program_desc_t *prog_ctrl_init_prog_desc);

#endif /* __PROGRAM_PSA_OUT_NV12_S2V_DMA_CONTROL_INIT_H */
