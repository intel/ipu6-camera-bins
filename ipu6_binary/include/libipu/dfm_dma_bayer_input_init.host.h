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

#ifndef __DFM_DMA_BAYER_INPUT_INIT_HOST_H
#define __DFM_DMA_BAYER_INPUT_INIT_HOST_H

#include "ia_css_common_io_types.h"
#include "bufqueue.host.h"
#include "ipu_device_dma_type_properties.h"

static void dfm_dma_bayer_input_host_open(
		p_terminal_config terminal,
		bufqueue_t q_in,
		resource_t dma_chan,
		uint32_t ack_addr,
		uint32_t ack_data,
		dfm_port_resource_t dfm_in_port,
		uint32_t is_active,
		uint32_t gather_multi_mask,
		uint32_t ignore_first_event,
		uint32_t buf_chasing_mode,
		uint32_t bcpr_reg,
		uint32_t frame_index,
		void *payload_pointer,
		uint32_t num_lines_interleaved,
		enum nci_dma_requestor_id req_id);

#ifndef PIPE_GENERATION
#include "dfm_dma_bayer_input_init.host.c"
#endif

#endif /* __DFM_DMA_BAYER_INPUT_INIT_HOST_H */
