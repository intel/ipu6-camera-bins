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

#ifndef __DFM_DMA_BAYER_OUTPUT_INIT_SHARED_H
#define __DFM_DMA_BAYER_OUTPUT_INIT_SHARED_H

#include "bufqueue.shared.h"
#include "resource.shared.h"
#include "dfm_resource_types.h"

#define DFM_DMA_BAYER_OUTPUT_NUM_DMA_CHANNELS	(2)
#ifndef DFM_DMA_BAYER_OUTPUT_DMA_RESOURCE_ID
#define DFM_DMA_BAYER_OUTPUT_DMA_RESOURCE_ID	vied_nci_dev_chn_dma_ext0
#endif

#ifndef DFM_DMA_BAYER_OUTPUT_NUM_LINES_INTERLEAVED
#define DFM_DMA_BAYER_OUTPUT_NUM_LINES_INTERLEAVED	(1)
#endif

#ifndef DFM_DMA_BAYER_OUTPUT_DMA_STREAM_ID
#define DFM_DMA_BAYER_OUTPUT_DMA_STREAM_ID       (0)
#endif

static void dfm_dma_bayer_output_open(
		p_terminal_config terminal,
		bufqueue_t q_in,
		resource_t dma_chan,
		dfm_port_resource_t dfm_out_port,
		unsigned gather_multi_mask,
		unsigned ignore_first_event,
		unsigned threshold,
		unsigned nci_dma_req_id,
		void *payload_pointer,
		unsigned num_lines_interleaved);

static void dfm_dma_bayer_unused_output_open(
		const vied_nci_dev_dfm_id_t dfm_dev_id,
		unsigned port_num,
		uint8_t *payload_address_offset);

#ifndef PIPE_GENERATION
#include "dfm_dma_bayer_output_init.shared.c"
#endif

#endif /* __DFM_DMA_BAYER_OUTPUT_INIT_SHARED_H */
