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

#ifndef __DMA_NCI_BAYER_TRANSFER_INIT_HOST_H
#define __DMA_NCI_BAYER_TRANSFER_INIT_HOST_H

#include "bufqueue.host.h"
#include "resource.shared.h"
#include "dma_nci_io.host.h"
#include "ia_css_common_io_types.h"
#include "storage_class.h"

#define TWO_LINES_PER_PIXEL (2)
#define ONE_LINE_PER_PIXEL (1)

STORAGE_CLASS_INLINE void dma_nci_bayer_transfer_open(
		struct ia_css_terminal_descriptor_s *terminal,
		struct ipu_resources_dma_descriptor_config *cfg,
		dma_resource_t resource,
		uint32_t cmd,
		bufqueue_t q_in,
		uint32_t ack_addr,
		uint32_t ack_data,
		uint32_t h_interl_f,
		uint32_t v_interl_f,
		uint32_t stream_id);

STORAGE_CLASS_INLINE void dma_nci_bayer_isl_transfer_open(
		struct ia_css_terminal_descriptor_s *terminal,
		struct ipu_resources_dma_descriptor_config *cfg,
		dma_resource_t dma_resource,
		bufqueue_t q_in,
		uint32_t cio2str_stride,
		uint32_t ack_addr,
		uint32_t ack_data,
		uint32_t cio2str_fifo_size,
		uint32_t cio2str_databus_addr,
		uint32_t h_interl_f,
		uint32_t v_interl_f,
		uint32_t lines_per_pixel);

#ifndef PIPE_GENERATION
#include "dma_nci_bayer_transfer_init.host.c"
#endif

#endif /* __DMA_NCI_BAYER_TRANSFER_INIT_HOST_H */
