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

#ifndef __DFM_DMA_NV12_INIT_HOST_H_
#define __DFM_DMA_NV12_INIT_HOST_H_

#include "bufqueue.host.h"
#include "dfm_dma_config_port.isp.h"
#include "pg_control_init_support.h"

static void dfm_dma_nv12_host_open(p_terminal_config terminal,
					bufqueue_t q,
					resource_t dma_res,
					unsigned ack_addr,
					unsigned ack_data,
					unsigned dma_channels_per_plane,
					enum dfm_dma_direction direction,
					dfm_port_resource_t port_res,
					unsigned is_active,
					unsigned ignore_first_event,
					load_section_desc_list_t load_sec_desc_list,
					void *payload_address,
					unsigned dma_requestor_id);

#ifndef PIPE_GENERATION
#include "dfm_dma_nv12_init.host.c"
#endif

#endif /* __DFM_DMA_NV12_INIT_HOST_H_ */
