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

#ifndef MBR_DMA_CONFIG_HOST_H_
#define MBR_DMA_CONFIG_HOST_H_

#include "storage_class.h"
#include "ipu_device_dma_devices.h"
#include "ipu_device_dma_type_properties.h"
#include "dev_api_dfm_types.h"
#include "resource_types.h"
#include "buf_blk.host.h"
#include "ia_css_common_io_types.h"
#include "ipu_resources_dma_term.h"
#include "ofs_dma_config_def.h"
#include "adi_ofs_types.h"
#include "ipu_device_mbr_devices.h"
#include "bufqueue.host.h"
#include "ipu_dma_cfg_types.h"
#include "nci_mbr_types.h"
#include "pg_control_init_support.h"

struct mbr_dma_desc_tbl {
	uint8_t ch;
	uint8_t port_type;
};

enum mbr_dma_term_desc_id {
	MBR_DMA_TERM_DESC_DDR_Y = 0,    /* MBR_CH0_TERMINALB_DESC */
	MBR_DMA_TERM_DESC_DDR_U,        /* MBR_CH1_TERMINALB_DESC */
	MBR_DMA_TERM_DESC_DDR_V,        /* MBR_CH2_TERMINALB_DESC */
	MBR_DMA_TERM_DESC_VMEM_BUF0_Y,	/* MBR_CH0_TERMINALA_DESC */
	MBR_DMA_TERM_DESC_VMEM_BUF1_Y,
	MBR_DMA_TERM_DESC_VMEM_BUF0_U,  /* MBR_CH1_TERMINALA_DESC */
	MBR_DMA_TERM_DESC_VMEM_BUF1_U,
	MBR_DMA_TERM_DESC_VMEM_BUF0_V,  /* MBR_CH2_TERMINALA_DESC */
	MBR_DMA_TERM_DESC_VMEM_BUF1_V,
};

#define MBR_DMA_TERM_DESC_N_ID (MBR_DMA_TERM_DESC_VMEM_BUF1_V + 1)

struct mbr_dma_desc_tbl mbr_get_dma_term_desc_alloc(enum mbr_dma_term_desc_id id);

void mbr_dma_set_mbr_dma_hb_config(
		enum nci_mbr_ch mbr_ch,
		struct ipu_dma_desc_id_cfg *mbr_dma_cfg,
		const vied_nci_dev_chn_ID_t dev_chn_id,
		const uint32_t dma_chan_offset);

void mbr_dma_set_mbr_dma_internal_config(
		enum nci_mbr_ch mbr_ch,
		struct ipu_dma_desc_id_cfg *mbr_dma_cfg,
		const vied_nci_dev_chn_ID_t dev_id,
		const uint32_t dma_chan_base_offset);

void mbr_dma_set_dma_hb_desc_config(
		const p_terminal_config ddr_config,
		struct ipu_spatial_terminal_descriptor_s *rec_sim_in,
		bufqueue_t q_in,
		struct  ipu_resources_dma_descriptor_config *dma_desc_cfg,
		uint32_t mbr_dev_id,
		uint32_t stream_id_y,
		uint32_t stream_id_u,
		uint32_t stream_id_v,
		vied_nci_dev_chn_ID_t dev,
		dma_resource_t dma_resource, /* dma_resource -> dev_id, chan_offset */
		uint32_t nof_dma_chan);

void mbr_dma_set_dma_internal_desc_config(
		struct  ipu_resources_dma_descriptor_config *dma_desc_cfg,
		enum nci_mbr_device_id mbr_dev_id,
		bufqueue_t q_in,
		uint32_t dma_size,
		vied_nci_dev_chn_ID_t dev);

unsigned int
mbr_dma_get_load_section_count(
		vied_nci_dev_chn_ID_t dma_hb_id,
		vied_nci_dev_chn_ID_t dma_int_id);

unsigned int
mbr_dma_get_payload_size(
		vied_nci_dev_chn_ID_t dma_hb_id,
		vied_nci_resource_size_t dma_hb_size,
		vied_nci_dev_chn_ID_t dma_int_id,
		vied_nci_resource_size_t dma_int_size);
int
mbr_dma_fill_load_section_descriptor(
		ia_css_program_control_init_program_desc_t *prog_ctrl_init_prog_desc,
		enum nci_mbr_device_id mbr_dev_id,
		vied_nci_dev_chn_ID_t dma_hb_id,
		uint32_t dma_hb_channel_offset,
		vied_nci_resource_size_t dma_hb_size,
		vied_nci_dev_chn_ID_t dma_int_id,
		uint32_t dma_int_channel_offset,
		vied_nci_resource_size_t dma_int_size);

void
mbr_dma_payload_fill(
		load_section_desc_list_t load_sec_desc,
		void *payload_address,
		enum nci_mbr_device_id mbr_dev_id,
		const p_terminal_config term_in,
		struct ipu_spatial_terminal_descriptor_s *rec_sim_in,
		bufqueue_t q_in,
		vied_nci_dev_chn_ID_t dma_hb_id,
		dma_resource_t dma_hb_resource,
		vied_nci_resource_size_t dma_hb_size,
		vied_nci_dev_chn_ID_t dma_int_id,
		dma_resource_t dma_int_resource,
		vied_nci_resource_size_t dma_int_size);

#endif /* MBR_DMA_CONFIG_HOST_H_ */
