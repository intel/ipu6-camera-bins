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

#ifndef __DMA_NCI_YUV_TRANSFER_INIT_HOST_H
#define __DMA_NCI_YUV_TRANSFER_INIT_HOST_H

#include "bufqueue.host.h"
#include "resource.shared.h"
#include "ia_css_common_io_types.h"

static void dma_nci_yuv_transfer_open(
		struct ia_css_terminal_descriptor_s *terminal,
		bufqueue_t q_in,
		uint32_t cmd,
		struct ipu_resources_dma_descriptor_config *cfg_y,
		struct ipu_resources_dma_descriptor_config *cfg_u,
		struct ipu_resources_dma_descriptor_config *cfg_v,
		dma_resource_t dma_resource_y,
		dma_resource_t dma_resource_u,
		dma_resource_t dma_resource_v,
		uint32_t ack_addr_y,
		uint32_t ack_addr_u,
		uint32_t ack_addr_v,
		uint32_t stream_y,
		uint32_t stream_u,
		uint32_t stream_v,
		uint32_t chroma_subsample_shift_x,
		uint32_t chroma_subsample_shift_y,
		bool is_packed);

#ifndef PIPE_GENERATION
#include "dma_nci_yuv_transfer_init.host.c"
#endif

#endif /* __DMA_NCI_YUV_TRANSFER_INIT_HOST_H */

