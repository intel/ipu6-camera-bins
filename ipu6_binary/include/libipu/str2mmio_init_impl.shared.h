/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2017 - 2017 Intel Corporation.
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
#ifndef __STR2MMIO_INIT_IMPL_SHARED_H
#define __STR2MMIO_INIT_IMPL_SHARED_H

#include "common_io.shared.h"
#include "bufqueue.shared.h"
#include "nci_pixel_str2mmio.h"
#include "ipu_device_str2mmio_properties_defs.h" /* IPU_DEVICE_S2M_CTRL_BUS_DATA_BYTES */
#include "str2mmio_init_impl_dep.h"
#include "storage_class.h"

#define BYTES_TO_WORDS_RIGHT_SHIFT	(6)
#define ALIGNED_BYTES_TO_WORDS(bytes)	((bytes) >> (BYTES_TO_WORDS_RIGHT_SHIFT))/* When byte size is word aligned */
/* For now using the full LB VMEM */
#define LBFF_VMEM_SIZE			(0x400)

STORAGE_CLASS_INLINE unsigned
str2mmio_isys_configure(bufqueue_t q,
			s_resolution_t res,
			enum ipu_device_str2mmio_id s2m_id,
			unsigned ack_data,
			unsigned ack_addr_in_bytes,
			unsigned line_idx,
			void *payload_address)
{
	unsigned block_size = queue_get_block_size(q);


	block_dimensions_t blk_dimension = calc_block_dimensions(queue_get_blockwidth(q),
					      queue_get_blockheight(q),
					      CEIL_DIV(res.width, ISP_NWAY),
					      res.height);
	struct nci_pixel_str2mmio_cfg s2m_sid;

	/* TODO move to ipu_device_memory_hrt.txt */
	uint32_t lb_vmem_base = LBFF_VMEM_START_ADDRESS;
	uint32_t s2m_start_offset = line_idx * (block_size / 2);
	/* write to VMEM */
	s2m_sid.start_address = DEVICE_UNIT_CONVERT(ALIGNED_BYTES_TO_WORDS(lb_vmem_base) + s2m_start_offset);
	/* TODO: there should be a file common to ISYS and PSYS describing how much we can use from this VMEM */
	s2m_sid.end_address = DEVICE_UNIT_CONVERT(s2m_sid.start_address + LBFF_VMEM_SIZE) - 1;
	/* acks should be send to DFM */
	s2m_sid.pix_width = width_16bit;
	s2m_sid.stride    = DEVICE_UNIT_CONVERT(block_size);
	s2m_sid.block_when_no_cmd = 1;
	s2m_sid.ack_base_addr = DEVICE_ACK_CONVERT(ack_addr_in_bytes / IPU_DEVICE_S2M_CTRL_BUS_DATA_BYTES);

	s2m_sid.sidpid = ack_data;
	s2m_sid.num_items = DEVICE_UNIT_CONVERT(blk_dimension.block_width * blk_dimension.block_height);
	s2m_sid.rpwc_enable = 1;
	s2m_sid.datafield_remap_cfg = NCI_PIXEL_STR2MMIO_NO_REMAP_VALUE;

	return nci_pixel_str2mmio_fill_config(s2m_id, &s2m_sid, payload_address);
}

STORAGE_CLASS_INLINE unsigned
str2mmio_isl_ps_configure(bufqueue_t q,
			s_resolution_t res,
			enum ipu_device_str2mmio_id s2m_id,
			unsigned ack_data,
			unsigned ack_addr_in_bytes,
			void *payload_address)
{
	unsigned num_blocks = queue_get_numblocks(q);
	unsigned block_size = queue_get_block_size(q);

	/* S2M ISL instance sees the same address as S2V instances */
	unsigned start_address = get_start_address_for_s2v(queue_get_mem_ptr(q));

	block_dimensions_t blk_dimension = calc_block_dimensions(queue_get_blockwidth(q),
					      queue_get_blockheight(q),
					      CEIL_DIV(res.width, ISP_NWAY),
					      res.height);
	struct nci_pixel_str2mmio_cfg s2m_sid;

	s2m_sid.pix_width = width_16bit;
	s2m_sid.start_address = DEVICE_UNIT_CONVERT(start_address);
	s2m_sid.end_address   = DEVICE_UNIT_CONVERT(start_address + (num_blocks * block_size)) - 1;
	s2m_sid.stride = DEVICE_UNIT_CONVERT(block_size);
	s2m_sid.block_when_no_cmd = 1;
	s2m_sid.ack_base_addr = DEVICE_ACK_CONVERT(ack_addr_in_bytes / IPU_DEVICE_S2M_CTRL_BUS_DATA_BYTES);
	s2m_sid.sidpid = ack_data;
	s2m_sid.num_items = DEVICE_UNIT_CONVERT(blk_dimension.block_width * blk_dimension.block_height);
	s2m_sid.rpwc_enable = 1;
	s2m_sid.datafield_remap_cfg = NCI_PIXEL_STR2MMIO_NO_REMAP_VALUE;

	return nci_pixel_str2mmio_fill_config(s2m_id, &s2m_sid, payload_address);
}

#endif /* __STR2MMIO_INIT_IMPL_SHARED_H */
