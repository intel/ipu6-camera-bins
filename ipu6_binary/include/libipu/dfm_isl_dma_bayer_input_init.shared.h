/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2017 Intel Corporation.
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

#ifndef __DFM_ISL_DMA_BAYER_INPUT_INIT_SHARED_H_
#define __DFM_ISL_DMA_BAYER_INPUT_INIT_SHARED_H_

#include "resource_types.h"
#include "dev_api_dfm_types.h"
#include "dfm_resource_types.h"
#include "bufqueue.shared.h"

static void dfm_isl_dma_bayer_in_open(p_terminal_config terminal,
		bufqueue_t q_in,
		dfm_port_resource_t dfm_isl_ipfd_port,
		s_resolution_t res,
		resource_t isl_dma_chan,
		uint32_t ignore_first_event,
		void *payload_address,
		uint32_t requestor_id,
		uint32_t num_lines_interleaved);

#ifndef PIPE_GENERATION
#include "dfm_isl_dma_bayer_input_init.shared.c"
#endif

#endif /* __DFM_ISL_DMA_BAYER_INPUT_INIT_SHARED_H_ */
