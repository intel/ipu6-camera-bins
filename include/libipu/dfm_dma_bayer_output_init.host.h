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

#ifndef __DFM_DMA_BAYER_OUTPUT_INIT_HOST_H
#define __DFM_DMA_BAYER_OUTPUT_INIT_HOST_H

#include "bufqueue.host.h"
#include "ia_css_common_io_types.h"

static void dfm_dma_bayer_output_host_open(
		p_terminal_config terminal,
		bufqueue_t q_in,
		resource_t dma_chan,
		dfm_port_resource_t dfm_out_port,
		unsigned gather_multi_mask,
		unsigned ignore_first_event,
		unsigned threshold,
		unsigned dma_requestor_id,
		void *payload_pointer,
		unsigned num_lines_interleaved);

static void dfm_dma_bayer_unused_output_host_open(
		const vied_nci_dev_dfm_id_t dfm_dev_id,
		unsigned port_num,
		uint8_t *payload_address_offset);

#ifndef PIPE_GENERATION
#include "dfm_dma_bayer_output_init.host.c"
#endif

#endif /* __DFM_DMA_BAYER_OUTPUT_INIT_HOST_H */
