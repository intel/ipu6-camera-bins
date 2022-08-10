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

#ifndef __PROGRAM_ISL_PS_NV12_COMMON_CONTROL_INIT_H
#define __PROGRAM_ISL_PS_NV12_COMMON_CONTROL_INIT_H

#include "type_support.h"
#include "ia_css_psys_process_types.h"
#include "ia_css_terminal_types.h"
#include "s2v_control_init.h"
#include "dev_api_dfm_types.h"
#include "resource_types.h"
#include "dfm_resource_types.h"
#include "ipu_device_strm_pack_devices.h"
#include "pg_control_init_support.h"

typedef struct {
	resource_t dma_nv12_out_chan;
} pg_nv12_ext_resources_t;

typedef struct {
	dfm_port_resource_t dfm_s2v_nv12;
	dfm_port_resource_t dfm_dma_nv12_out;
} dfm_nv12_resources_t;

#define DMA_OUT_Y_SIZE				(DMA_NCI_YUV_TRANSFER_NUM_DMA_CHANNELS_PER_PLANE)
#define DMA_OUT_UV_SIZE				(DMA_NCI_YUV_TRANSFER_NUM_DMA_CHANNELS_PER_PLANE)
#define DMA_OUT_RESOURCE_ID			VIED_NCI_DEV_CHN_DMA_EXT1_WRITE_ID
#define DMA_OUT_NV12_SIZE			(DMA_OUT_Y_SIZE + DMA_OUT_UV_SIZE)

/*
 * @brief       Fill ctrlinit payload of the program
 *
 * @param[in]   process_group           Process group
 * @param[in]   load_sec_desc           Progctrlinit terminal section descriptor
 * @param[in]   payload_base_address    Program's ctrlinit terminal payload start address
 * @param[in]   terminal_id             The outout terminal for NV12
 * @param[in]   s2v_id                  Id of the output S2V
 * @param[in]   dfm_agent_id            Id of the output DFM
 * @param[in]   dfm_resources            DFM ports
 * @param[in]   ext_resources            DMA chan
 * @param[in]   stream_blocker_id        Stream blocker to unblock, use STREAM_BLOCKER_NUM_DEVS for none.
 *
 * @retval 0    Successful.
 * @retval 1    Error.
 */
int
program_isl_ps_nv12_common_payload_fill(
		const ia_css_process_group_t *process_group,
		load_section_desc_list_t load_sec_desc_list,
		void *payload_base_address,
		int terminal_id,
		bufqueue_t q,
		vied_nci_s2v_id_t s2v_id,
		enum dev_api_dfm_agent dfm_agent_id,
		dfm_nv12_resources_t dfm_resources,
		pg_nv12_ext_resources_t ext_resources,
		ia_css_frame_format_type_t format,
		vied_nci_stream_blocker_id_t stream_blocker_id,
		uint16_t frag_idx,
		uint32_t stream_id_y,
		uint32_t stream_id_uv);

/*
 * @brief       Get ctrlinit payload size of the program
 *
 *  @param[in]   dfm_resources            DFM ports
 * @param[in]   stream_blocker_id        Stream blocker to unblock, use STREAM_BLOCKER_NUM_DEVS for none.
 *
 * @retval	Size of the program payload
 */
int
program_isl_ps_nv12_common_get_payload_size(dfm_nv12_resources_t dfm_resources,
		vied_nci_stream_blocker_id_t stream_blocker_id);

/*
 * @brief       Fill load section descriptor of the program
 *
 * @param[in]   prog_ctrl_init_prog_desc Pointer to the program descriptor in
 *                                       which the section descriptor has to be filled
 * @param[in]   s2v_id                  Id of the output S2V
 * @param[in]   dfm_resources            DFM ports
 * @param[in]   strm_pack_id            Id of the output stream pack
 * @param[in]   stream_blocker_id        Stream blocker to unblock, use STREAM_BLOCKER_NUM_DEVS for none.
 *
 * @retval 0    Successful.
 * @retval 1    Error.
 */
int
program_isl_ps_nv12_common_fill_load_section_descriptor(
		ia_css_program_control_init_program_desc_t *prog_ctrl_init_prog_desc,
		vied_nci_s2v_id_t s2v_id,
		dfm_nv12_resources_t dfm_resources,
		enum ipu_device_strm_pack_dev_id strm_pack_id,
		vied_nci_resource_size_t dma_out_resource_offset,
		vied_nci_stream_blocker_id_t stream_blocker_id);

/*
 * @brief       Fill connect section descriptor of the program
 *
 * @param[in]   connect_sec_desc        Pointer to the section descriptor to fill
 * @param[in]   terminal_id             The outout terminal for NV12
 * @retval 0    Successful.
 * @retval 1    Error.
 */
int
program_isl_ps_nv12_common_fill_connect_section_descriptor(
		ia_css_program_control_init_connect_section_desc_t *connect_sec_desc,
		ia_css_terminal_ID_t terminal_id,
		uint8_t dma_out_y_resource_offset,
		uint8_t dma_out_uv_resource_offset);

void
program_isl_ps_nv12_common_set_desc_sid_pid(
	ia_css_program_control_init_program_desc_t *prog_ctrl_init_prog_desc,
	dfm_nv12_resources_t dfm_resources);


#endif /* __PROGRAM_ISL_PS_NV12_COMMON_CONTROL_INIT_H */


