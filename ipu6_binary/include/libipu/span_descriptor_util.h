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

#ifndef __SPAN_DESCRIPTOR_UTIL_V4_H
#define __SPAN_DESCRIPTOR_UTIL_V4_H

#include "ipu_device_dma_properties.h"
#include "ipu_device_dma_devices.h"
#include "assert_support.h"
#include "type_support.h"

STORAGE_CLASS_INLINE uint32_t nci_dma_unit_location(
	const enum nci_dma_device_id dev_id,
	const int x,
	const int y)
{
	NOT_USED(dev_id);

	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);
	assert(x < (1 << NCI_DMA_SPAN_WIDTH_BITS));
	assert(y < (1 << NCI_DMA_SPAN_HEIGHT_BITS));

	return ((x << NCI_DMA_SPAN_WIDTH_SHIFT) | y);
}

#endif /* __SPAN_DESCRIPTOR_UTIL_V4_H */
