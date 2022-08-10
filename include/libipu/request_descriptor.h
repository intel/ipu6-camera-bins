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

#ifndef __REQUEST_DESCRIPTOR_H
#define __REQUEST_DESCRIPTOR_H

#include "storage_class.h"
#include "assert_support.h"
#include "type_support.h"
#include "vied_nci_dma_dev_access.h"
#include "ipu_device_dma_properties.h"
#include "request_descriptor_dep.h"
#include "vied_nci_dma_types.h"

#include "vied_nci_dma_trace.h"

STORAGE_CLASS_INLINE uint32_t nci_dma_reg_addr_request(
	const enum nci_dma_device_id dev_id,
	const uint32_t requestor_id,
	const enum ipu_device_dma_request_reg reg)
{
	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);
	assert(N_IPU_DEVICE_DMA_REQUEST_REG > (unsigned int)reg);
	assert(ipu_device_dma_request_banks(dev_id) > requestor_id);
	return nci_dma_reg_addr(dev_id, IPU_DEVICE_DMA_REQUEST_GROUP_ID, requestor_id, reg);
}

STORAGE_CLASS_INLINE uint32_t nci_dma_reg_addr_int_request(
	const enum nci_dma_device_id dev_id,
	const uint32_t requestor_id,
	const enum ipu_device_dma_request_reg reg)
{
	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);
	assert(N_IPU_DEVICE_DMA_REQUEST_REG > (unsigned int)reg);
	assert(ipu_device_dma_request_banks(dev_id) > requestor_id);
	return nci_dma_reg_addr_int(dev_id, IPU_DEVICE_DMA_REQUEST_GROUP_ID, requestor_id, reg);
}

STORAGE_CLASS_INLINE uint32_t nci_dma_reg_load_request(
	const enum nci_dma_device_id dev_id,
	const uint32_t requestor_id,
	const enum ipu_device_dma_request_reg reg)
{
	const uint32_t address = nci_dma_reg_addr_request(dev_id, requestor_id, reg);

	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);
	assert(N_IPU_DEVICE_DMA_REQUEST_REG > (unsigned int)reg);
	assert(ipu_device_dma_request_banks(dev_id) > requestor_id);
	return nci_dma_reg_load(address);
}

STORAGE_CLASS_INLINE void nci_dma_reg_store_request(
	const enum nci_dma_device_id dev_id,
	const uint32_t requestor_id,
	const enum ipu_device_dma_request_reg reg,
	const uint32_t val)
{
	const uint32_t address = nci_dma_reg_addr_request(dev_id, requestor_id, reg);

	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);
	assert(N_IPU_DEVICE_DMA_REQUEST_REG > (unsigned int)reg);
	assert(ipu_device_dma_request_banks(dev_id) > requestor_id);
	nci_dma_reg_store(address, val);
}

STORAGE_CLASS_INLINE void nci_dma_request_desc_run(
	const enum nci_dma_device_id dev_id,
	const uint32_t requestor_id,
	const uint32_t instruction)
{
	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);
	assert(ipu_device_dma_request_banks(dev_id) > requestor_id);
	nci_dma_reg_store_request(dev_id, requestor_id, IPU_DEVICE_DMA_REQUEST_REG_INSTRUCTION, instruction);
}

STORAGE_CLASS_INLINE void nci_dma_request_desc_reg_store(
	const enum nci_dma_device_id dev_id,
	const uint32_t requestor_id,
	const struct nci_dma_request_desc * const request_descriptor)
{
	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);
	assert(ipu_device_dma_request_banks(dev_id) > requestor_id);
	assert(NULL != request_descriptor);

	nci_dma_reg_store_request(dev_id, requestor_id, IPU_DEVICE_DMA_REQUEST_REG_DESC_ID_SETUP1,
		request_descriptor->descriptor_id_setup_1);
	nci_dma_reg_store_request(dev_id, requestor_id, IPU_DEVICE_DMA_REQUEST_REG_DESC_ID_SETUP2,
		request_descriptor->descriptor_id_setup_2);
}

STORAGE_CLASS_INLINE uint32_t nci_dma_read_request_valid_register(
	const uint32_t dev_id,
	const uint32_t requestor_id)
{
	assert(requestor_id < ipu_device_dma_request_banks(dev_id));
	return nci_dma_reg_load_request((enum nci_dma_device_id)dev_id,
		requestor_id, IPU_DEVICE_DMA_REQUEST_REG_REQUEST_VALID);
}

/*
* Number of retries to wait and keep polling to see if the register becomes available.
* Keep polling the register to prevent deadlock and also issue instructions once the register is available.
*/
#define RETRY_COUNT_MAX 100

STORAGE_CLASS_INLINE int nci_dma_check_request_bank_busy(
	const enum nci_dma_device_id dev_id,
	const enum nci_dma_requestor_id requestor_id)
{
	int retry_count = 0;
	int valid;
	/* Poll the register to ensure the bank is not busy before issuing instructions to prevent deadlock */
	do {
		valid = nci_dma_read_request_valid_register(dev_id, requestor_id);
		if (valid == 0) {
			break;
		}
		retry_count++;
		ia_css_sleep();
	} while (retry_count <= RETRY_COUNT_MAX);
	return valid;
}

#endif /* __REQUEST_DESCRIPTOR_H */
