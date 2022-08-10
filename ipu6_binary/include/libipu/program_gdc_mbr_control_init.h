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

#ifndef __PROGRAM_GDC_MBR_CONTROL_INIT_H
#define __PROGRAM_GDC_MBR_CONTROL_INIT_H

#include "type_support.h"
#include "ia_css_psys_process_types.h"
#include "ia_css_terminal_types.h"
#include "bufqueue.host.h"
#include "ia_css_common_io_types.h"
#include "resource_types.h"
#include "mbr_defines.h"
#include "ipu_device_mbr_devices.h"
#include "nci_gdc_types.h"
#include "ia_css_kernel_user_param_instance_types.h"
#include "pg_control_init_support.h"

/* GDC RF queue */
#define Q_IN_BUF_MEM                 (buf_mem_gdc_vmem)
#define Q_IN_BUF_START_ADDR          (0)
#define Q_IN_NUMBUF                  (2)

/* MBR_GDC will update unit width and height based of the distortions at run-time.
 * Thus for simplicity, queue width and height are set to 1
 */
#define Q_IN_WIDTH_Y                 1
#define Q_IN_HEIGHT_Y                1
#define Q_IN_SIZE_Y                  GDC_RF_LUMA_BUF_SIZE_VECS

#define Q_IN_WIDTH_U                 1
#define Q_IN_HEIGHT_U                1
#define Q_IN_SIZE_U                  GDC_RF_CHROMA_BUF_SIZE_VECS

#define Q_IN_WIDTH_V                 1
#define Q_IN_HEIGHT_V                1
#define Q_IN_SIZE_V                  GDC_RF_CHROMA_BUF_SIZE_VECS

enum gdc_mbr_processing_mode {
	GDC_MBR_DEPRECATED_MODE = 0,
	GDC_MBR_TETRAGON_MODE,
	GDC_MBR_LDC_HOMOGRAPHY_MODE,
	GDC_MBR_WFOV_MODE
};

enum gdc_mbr_operation {
	GDC_MBR_OP_BYPASS = 0,
	GDC_MBR_OP_LDC,
	GDC_MBR_OP_HOMOGRAPHY,
};

/*
 * @brief       Fill control init payload of the program
 *
 * @param[in]   load_sec_desc           Progctrlinit terminal section descriptor list
 * @param[in]   payload_address         Program's ctrlinit terminal payload start address
 * @param[in]   get_terminal            Terminal descriptor at input side
 * @param[in]   kup_cfg                 Pointer to kernel user parameter structure of GDC-MBR
 * @param[in]   q_out                   GDC output queue
 * @param[in]   op_ack_addr[]           Array of addresses (per chan) to which GDC will send process output cmds
 * @param[in]   out_msb_aligned         GDC output alignment (0: LSB, 1: MSB)
 * @param[in]   is_dst_packed           GDC output packing enable (0: unpacked, 1: packed)
 * @param[in]   dma_hb_id               DMA resource ID for HB DMA controlled by MBR
 * @param[in]   dma_hb_resource         DMA resource (device id and offset) for HB DMA controlled by MBR
 * @param[in]   dma_hb_size             Number of DMA channels for HB DMA controlled by MBR
 * @param[in]   dma_int_id              DMA resource ID for Internal DMA controlled by MBR
 * @param[in]   dma_int_resource        DMA resource (device id and offset) for Internal DMA controlled by MBR
 * @param[in]   dma_int_size            Number of DMA channels for Internal DMA controlled by MBR
 * @param[in]   stream_ids_array        An array of the stream IDs for the transfer
 * @param[in]   num_of_streams          The number of entries in stream_ids_array
 *
 * @retval 0    Successful.
 * @retval 1    Error.
 */
int
program_gdc_mbr_payload_fill(
		load_section_desc_list_t load_sec_desc_list,
		void *payload_address,
		p_terminal_config get_terminal,
		struct ia_css_kup_gdc_mbr *kup_cfg,
		bufqueue_t q_out,
		uint32_t op_ack_addr[NCI_GDC_NUM_CHANS],
		unsigned out_msb_aligned,
		unsigned is_dst_packed,
		vied_nci_dev_chn_ID_t dma_hb_id,
		dma_resource_t dma_hb_resource,
		vied_nci_resource_size_t dma_hb_size,
		vied_nci_dev_chn_ID_t dma_int_id,
		dma_resource_t dma_int_resource,
		vied_nci_resource_size_t dma_int_size,
		uint32_t *stream_ids_array,
		unsigned num_of_streams);

/*
 * @brief       Get control init payload size of the program
 * @param[in]   dma_hb_id         DMA resource ID for HB DMA controlled by MBR
 * @param[in]   dma_hb_size       Number of DMA channels for HB DMA controlled by MBR
 * @param[in]   dma_int_id        DMA resource ID for Internal DMA controlled by MBR
 * @param[in]   dma_int_size      Number of DMA channels for Internal DMA controlled by MBR
 * @param[in]   num_of_streams          The number of entries in stream_ids_array
 *
 * @retval	Size of the program payload
 */
int
program_gdc_mbr_get_payload_size(
		vied_nci_dev_chn_ID_t dma_hb_id,
		vied_nci_resource_size_t dma_hb_size,
		vied_nci_dev_chn_ID_t dma_int_id,
		vied_nci_resource_size_t dma_int_size,
		unsigned num_of_streams);

/*
 * @brief       Fill load section descriptor of the program
 *
 * @param[in]   prog_ctrl_init_prog_desc Pointer to the program descriptor in which the sections need to be added
 * @param[in]   load_sec_desc           Pointer to the section descriptor to fill
 * @param[in]   payload_offset          Payload offset of the program (first device in the program
 *                                      will set this in its first section descriptor)
 * @param[in]   dma_hb_id               DMA resource ID for HB DMA controlled by MBR
 * @param[in]   dma_hb_channel_offset   DMA Channel offset for HB DMA controlled by MBR
 * @param[in]   dma_hb_size             Number of DMA channels for HB DMA controlled by MBR
 * @param[in]   dma_int_id              DMA resource ID for internal DMA controlled by MBR
 * @param[in]   dma_int_channel_offset  DMA channel offset for internal DMA controlled by MBR
 * @param[in]   dma_int_size            Number of DMA channels for internal DMA controlled by MBR
 * @param[in]   stream_ids_array        An array of the stream IDs for the transfer
 * @param[in]   num_of_streams          The number of entries in stream_ids_array
 *
 * @retval 0    Successful.
 * @retval 1    Error.
 */
unsigned int
program_gdc_mbr_fill_load_section_descriptor(
		ia_css_program_control_init_program_desc_t *prog_ctrl_init_prog_desc,
		vied_nci_dev_chn_ID_t dma_hb_id,
		uint32_t dma_hb_channel_offset,
		vied_nci_resource_size_t dma_hb_size,
		vied_nci_dev_chn_ID_t dma_int_id,
		uint32_t dma_int_channel_offset,
		vied_nci_resource_size_t dma_int_size,
		uint32_t *stream_ids_array,
		unsigned num_of_streams);

/*
 * @brief       Fill connect section descriptor of the program
 *
 * @param[in]   connect_sec_desc        Pointer to the section descriptor to fill
 * @param[in]   dma_hb_id               DMA device id
 * @param[in]   dma_hb_offset           DMA channel offset
 * @param[in]   dma_hb_size             Number of DMA channels
 * @param[in]   get_terminal_id         Terminal id of the input data terminal
 * @param[in]   stream_ids_array        An array of the stream IDs for the transfer
 * @param[in]   num_of_streams          The number of entries in stream_ids_array
 *
 * @retval 0    Successful.
 * @retval 1    Error.
 */
int
program_gdc_mbr_fill_connect_section_descriptor(
		ia_css_program_control_init_connect_section_desc_t *connect_sec_desc,
		vied_nci_dev_chn_ID_t dma_hb_id,
		uint32_t dma_hb_offset,
		uint32_t dma_hb_size,
		uint32_t get_terminal_id,
		uint32_t *stream_ids_array,
		unsigned num_of_streams);

/*
 * @brief       Get process ID of GDC MBR program
 *
 * @retval	process id
 */
ia_css_process_id_t
program_gdc_mbr_get_process_id(void);

/*
 * @brief       Get load and connect section count
 *
 * @param[out]  load_section_count
 * @param[out]  connect_section_count
 * @param[in]   dma_hb_id
 * @param[in]   dma_hb_size
 * @param[in]   dma_int_id
 * @param[in]   num_of_streams          The number of entries in stream_ids_array
 *
 * @retval	0 if successful -1 otherwise
 */
int
program_gdc_mbr_get_section_count(
		uint32_t* load_section_count,
		uint32_t* connect_section_count,
		vied_nci_dev_chn_ID_t dma_hb_id,
		vied_nci_resource_size_t dma_hb_size,
		vied_nci_dev_chn_ID_t dma_int_id,
		unsigned num_of_streams);

/*
 * @brief       Checks the validity of the GDC-MBR KUP struct passed from P2P
 *
 * @param[in]   kup_cfg       Pointer to KUP struct
 *
 * @retval      0 if successful -1 otherwise
 */
int
program_gdc_mbr_kup_checker(
		const struct ia_css_kup_gdc_mbr *kup_cfg);

/*
 * @brief       Temporary function to set GDC-MBR KUP members with valid values
 *
 * @param[in]   kup_cfg       Pointer to KUP struct
 * @param[in]   get_terminal  Input terminal struct
 *
 * @retval	None
 */
void
ia_css_kup_gdc_mbr_set_temp(
		struct ia_css_kup_gdc_mbr *kup_cfg,
		struct ia_css_terminal_descriptor_s get_terminal);


void
program_gdc_mbr_kup_print(
		const struct ia_css_kup_gdc_mbr *kup_cfg);

#endif /* __PROGRAM_GDC_MBR_CONTROL_INIT_H */
