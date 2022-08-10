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

#ifndef __DFM_SPATIAL_CONTROL_INIT_SHARED_H
#define __DFM_SPATIAL_CONTROL_INIT_SHARED_H

/* TODO: Move a function to an isp-only file */
#ifdef __ISP
static void acb_configure(unsigned acb_dev_id,
				unsigned ack_address,
				struct ipu_kernel_fragment_sequencer_info_desc_s *kernel_frag_seq_info);
#endif

static void dfm_acb_port_configure(struct dev_api_dfm_stream *stream,
					enum dev_api_dfm_agent dfm_agent,
					unsigned num_buf,
					unsigned *port_nums,
					bool ignore_first_event,
					const struct ipu_kernel_fragment_sequencer_info_desc_s *kernel_frag_seq_info,
					void **payload_addresses);

/**
 * Configure DMA port
 * @param dma_chan
 * @param dma_cmd
 * @param stream
 * @param dfm_agent
 * @param num_buf
 * @param port_nums
 * @param ignore_first_event
 * @param initial_macrosize		Use this value as the macro_size of the first request. The rest of the requests
 * 					will have 1 as macro_size.
 */
static void dfm_dma_port_configure(resource_t dma_chan,
					enum nci_dma_command dma_cmd,
					struct dev_api_dfm_stream *stream,
					enum dev_api_dfm_agent dfm_agent,
					unsigned num_buf,
					unsigned *port_nums,
					bool ignore_first_event,
					unsigned initial_macrosize,
					void **payload_addresses,
					unsigned dma_requestor_id);


#ifndef PIPE_GENERATION
#include "dfm_spatial_control_init.shared.c"
#endif

#endif /* __DFM_SPATIAL_CONTROL_INIT_SHARED_H */
