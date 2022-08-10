/**
* INTEL CONFIDENTIAL
*
* Copyright (C) 2014 - 2017 Intel Corporation.
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

/*! \file */

#ifndef __GLOBAL_DESCRIPTOR_H
#define __GLOBAL_DESCRIPTOR_H

#include "assert_support.h"
#include "type_support.h"
#include "vied_nci_dma.h"
#include "vied_nci_dma_dev_access.h"
#include "ipu_device_dma_properties.h"
#include "ipu_device_dma_type_properties.h"

#include "vied_nci_dma_trace.h"

#include "vied_nci_dma_context.h"
#include "vied_nci_dma_trace.h"

STORAGE_CLASS_INLINE uint32_t nci_dma_reg_addr_global(
	const enum nci_dma_device_id dev_id,
	const uint32_t global_id,
	const enum ipu_device_dma_global_reg reg)
{
	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);
	assert(N_IPU_DEVICE_DMA_GLOBAL_REG(dev_id) > (unsigned int)reg);
	assert(ipu_device_dma_global_sets(dev_id) > global_id);
	return nci_dma_reg_addr(dev_id, IPU_DEVICE_DMA_GLOBAL_GROUP_ID, global_id, reg);
}

STORAGE_CLASS_INLINE uint32_t nci_dma_reg_addr_int_global(
	const enum nci_dma_device_id dev_id,
	const uint32_t global_id,
	const enum ipu_device_dma_global_reg reg)
{
	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);
	assert(N_IPU_DEVICE_DMA_GLOBAL_REG(dev_id) > (unsigned int)reg);
	assert(ipu_device_dma_global_banks(dev_id) > global_id);
	return nci_dma_reg_addr_int(dev_id, IPU_DEVICE_DMA_GLOBAL_GROUP_ID, global_id, reg);
}

STORAGE_CLASS_INLINE uint32_t nci_dma_reg_load_global(
	const enum nci_dma_device_id dev_id,
	const uint32_t global_id,
	const enum ipu_device_dma_global_reg reg)
{
	const uint32_t address = nci_dma_reg_addr_global(dev_id, global_id, reg);

	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);
	assert(N_IPU_DEVICE_DMA_GLOBAL_REG(dev_id) > (unsigned int)reg);
	assert(ipu_device_dma_global_sets(dev_id) > global_id);
	return nci_dma_reg_load(address);
}

STORAGE_CLASS_INLINE void nci_dma_reg_store_global(
	const enum nci_dma_device_id dev_id,
	const uint32_t global_id,
	const enum ipu_device_dma_global_reg reg,
	const uint32_t val)
{
	const uint32_t address = nci_dma_reg_addr_global(dev_id, global_id, reg);

	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);
	assert(N_IPU_DEVICE_DMA_GLOBAL_REG(dev_id) > (unsigned int)reg);
	assert(ipu_device_dma_global_sets(dev_id) > global_id);
	nci_dma_reg_store(address, val);
}
/** Uploads a global descriptor \p global_desc to DMA global registers.
 */
STORAGE_CLASS_INLINE void nci_dma_global_desc_reg_store(
	const enum nci_dma_device_id dev_id,
	const uint32_t global_id,
	const struct nci_dma_global_desc * const global_descriptor)
{
	uint32_t set_id;

	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);
	assert(ipu_device_dma_global_sets(dev_id) > global_id);
	assert(NULL != global_descriptor);

	nci_dma_reg_store_global(dev_id, global_id, IPU_DEVICE_DMA_GLOBAL_REG_UNIT_BASE_ADDR,
		global_descriptor->unit_descriptor_base_addr);
	nci_dma_reg_store_global(dev_id, global_id, IPU_DEVICE_DMA_GLOBAL_REG_SPAN_BASE_ADDR,
		global_descriptor->span_descriptor_base_addr);
	nci_dma_reg_store_global(dev_id, global_id, IPU_DEVICE_DMA_GLOBAL_REG_TERMINAL_BASE_ADDR,
		global_descriptor->terminal_descriptor_base_addr);
	nci_dma_reg_store_global(dev_id, global_id, IPU_DEVICE_DMA_GLOBAL_REG_CHANNEL_BASE_ADDR,
		global_descriptor->channel_descriptor_base_addr);
	nci_dma_reg_store_global(dev_id, global_id, IPU_DEVICE_DMA_GLOBAL_REG_MAX_BLOCK_HEIGHT,
		global_descriptor->max_block_height);
	for (set_id = 0; set_id < ipu_device_dma_global_sets(dev_id); set_id++) {
		nci_dma_reg_store_global(dev_id, global_id, (const enum ipu_device_dma_global_reg)IPU_DEVICE_DMA_REG_MAX_BLOCK_WIDTH_1DBURST(set_id),
			global_descriptor->max_1d_block_width[set_id]);
		nci_dma_reg_store_global(dev_id, global_id, (const enum ipu_device_dma_global_reg)IPU_DEVICE_DMA_REG_MAX_BLOCK_WIDTH_2DBURST(set_id),
			global_descriptor->max_2d_block_width[set_id]);
	}
}

#ifdef NCI_DMA_DEBUG
/** Downloads a global descriptor from DMA global registers.
 */
STORAGE_CLASS_INLINE void nci_dma_global_desc_reg_load(
	const enum nci_dma_device_id dev_id,
	const uint32_t global_id,
	struct nci_dma_global_desc *global_descriptor)
{
	uint32_t set_id;

	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);
	assert(ipu_device_dma_global_banks(dev_id) > global_id);
	assert(NULL != global_descriptor);

	global_descriptor->unit_descriptor_base_addr = nci_dma_reg_load_global(dev_id, global_id,
		IPU_DEVICE_DMA_GLOBAL_REG_UNIT_BASE_ADDR);
	global_descriptor->span_descriptor_base_addr = nci_dma_reg_load_global(dev_id, global_id,
		IPU_DEVICE_DMA_GLOBAL_REG_SPAN_BASE_ADDR);
	global_descriptor->terminal_descriptor_base_addr = nci_dma_reg_load_global(dev_id, global_id,
		IPU_DEVICE_DMA_GLOBAL_REG_TERMINAL_BASE_ADDR);
	global_descriptor->channel_descriptor_base_addr = nci_dma_reg_load_global(dev_id, global_id,
		IPU_DEVICE_DMA_GLOBAL_REG_CHANNEL_BASE_ADDR);
	global_descriptor->max_block_height = nci_dma_reg_load_global(dev_id, global_id,
		IPU_DEVICE_DMA_GLOBAL_REG_MAX_BLOCK_HEIGHT);
	for (set_id = 0; set_id < ipu_device_dma_global_sets(dev_id); set_id++) {
		global_descriptor->max_1d_block_width[set_id] = nci_dma_reg_load_global(dev_id, global_id,
			IPU_DEVICE_DMA_REG_MAX_BLOCK_WIDTH_1DBURST(set_id));
		global_descriptor->max_2d_block_width[set_id] = nci_dma_reg_load_global(dev_id, global_id,
			IPU_DEVICE_DMA_REG_MAX_BLOCK_WIDTH_2DBURST(set_id));
	}
}
#endif

#endif /* __GLOBAL_DESCRIPTOR_H */
