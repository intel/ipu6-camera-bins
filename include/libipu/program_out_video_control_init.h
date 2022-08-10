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

#ifndef __PROGRAM_OUT_VIDEO_CONTROL_INIT_H
#define __PROGRAM_OUT_VIDEO_CONTROL_INIT_H

#include "type_support.h"
#include "resource_types.h"
#include "dfm_resource_types.h"
#include "ia_css_psys_process_types.h"
#include "ia_css_terminal_types.h"
#include "s2v_control_init.h"
#include "dev_api_dfm_types.h"
#include "ipu_device_strm_pack_devices.h"
#include "ipu_fabrics.h"
#include "ia_css_dma_resources.h"
#include "pg_control_init_support.h"

#define DMA_OUT_Y_SIZE            (DMA_NCI_YUV_TRANSFER_NUM_DMA_CHANNELS_PER_PLANE)
#define DMA_OUT_U_SIZE            (DMA_NCI_YUV_TRANSFER_NUM_DMA_CHANNELS_PER_PLANE)
#define DMA_OUT_V_SIZE            (DMA_NCI_YUV_TRANSFER_NUM_DMA_CHANNELS_PER_PLANE)
#define DMA_OUT_SIZE              (DMA_OUT_Y_SIZE + DMA_OUT_U_SIZE + DMA_OUT_V_SIZE)
#define DMA_OUT_RESOURCE_ID       VIED_NCI_DEV_CHN_DMA_EXT1_WRITE_ID

typedef struct {
	resource_t dma_out_chan;
} pg_ext_resources_t;

typedef struct {
	dfm_port_resource_t dfm_s2v;
	dfm_port_resource_t dfm_dma;
} dfm_resources_t;

/*
 * @brief       Fill ctrlinit payload of the program
 *
 * @param[in]   process_group           Process group
 * @param[in]   load_sec_desc           Progctrlinit terminal section descriptor
 * @param[in]   payload_base_address    Program's ctrlinit terminal payload start address
 * @param[in]   terminal_id             The outout terminal for OUT_VIDEO
 * @param[in]   q                       The outout queue for OUT_VIDEO
 * @param[in]   fabric_id               FABRIC id
 * @param[in]   s2v_id                  Id of the output S2V
 * @param[in]   dfm_agent_id            Id of the output DFM
 * @param[in]   dfm_resources           DFM ports
 * @param[in]   ext_resources           DMA chan
 * @param[in]   req_id                  requestor_id for dma
 * @param[in]   stream_blocker_id       Stream blocker to unblock, use STREAM_BLOCKER_NUM_DEVS for none.
 *
 * @retval 0    Successful.
 * @retval 1    Error.
 */
int
program_out_video_payload_fill(
		const ia_css_process_group_t *process_group,
		load_section_desc_list_t load_sec_desc_list,
		void *payload_base_address,
		int terminal_id,
		bufqueue_t q,
		enum ipu_fabrics_id fabric_id,
		vied_nci_s2v_id_t s2v_id,
		enum dev_api_dfm_agent dfm_agent_id,
		dfm_resources_t dfm_resources,
		pg_ext_resources_t ext_resources,
		unsigned int req_id,
		vied_nci_stream_blocker_id_t stream_blocker_id,
		uint16_t frag_idx,
		unsigned int stream_id_y,
		unsigned int stream_id_u,
		unsigned int stream_id_v);

/*
 * @brief       Get ctrlinit payload size of the program
 *
 * @param[in]   dfm_resources            DFM ports
 * @param[in]   stream_blocker_id        Stream blocker to unblock, use STREAM_BLOCKER_NUM_DEVS for none.
 *
 * @retval	Size of the program payload
 */
int
program_out_video_get_payload_size(
		dfm_resources_t dfm_resources,
		vied_nci_stream_blocker_id_t stream_blocker_id);

/*
 * @brief       Fill load section descriptor of the program
 *
 * @param[in]   prog_ctrl_init_prog_desc Pointer to the program descriptor in
 *                                       which the section descriptor has to be filled
 * @param[in]   s2v_id                  Id of the output S2V
 * @param[in]   dfm_resources           DFM ports
 * @param[in]   strm_pack_id            Id of the output stream pack
 * @param[in]   dma_out_resource_offset Offset to the dma channel
 * @param[in]   stream_blocker_id       Stream blocker to unblock, use STREAM_BLOCKER_NUM_DEVS for none.
 * @retval 0    Successful.
 * @retval 1    Error.
 */
int
program_out_video_fill_load_section_descriptor(
		ia_css_program_control_init_program_desc_t *prog_ctrl_init_prog_desc,
		vied_nci_s2v_id_t s2v_id,
		dfm_resources_t dfm_resources,
		enum ipu_device_strm_pack_dev_id strm_pack_id,
		vied_nci_resource_size_t dma_out_resource_offset,
		vied_nci_stream_blocker_id_t stream_blocker_id);

/*
 * @brief       Fill connect section descriptor of the program
 *
 * @param[in]   connect_sec_desc        Pointer to the section descriptor to fill
 * @param[in]   terminal_id             The outout terminal for OUT_VIDEO
 * @param[in]   dma_out_y_resource_offset Offset to the dma channel for Y
 * @param[in]   dma_out_u_resource_offset Offset to the dma channel for U
 * @param[in]   dma_out_v_resource_offset Offset to the dma channel for V
 * @retval 0    Successful.
 * @retval 1    Error.
 */
int
program_out_video_fill_connect_section_descriptor(
		ia_css_program_control_init_connect_section_desc_t *connect_sec_desc,
		ia_css_terminal_ID_t terminal_id,
		pg_ext_resources_t ext_resources);

void
program_out_video_set_desc_sid_pid(
	ia_css_program_control_init_program_desc_t *prog_ctrl_init_prog_desc,
	dfm_resources_t dfm_resources);


#endif /* __PROGRAM_OUT_VIDEO_CONTROL_INIT_H */


