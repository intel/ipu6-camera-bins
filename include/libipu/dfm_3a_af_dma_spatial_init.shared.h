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

#ifndef __DFM_3A_AF_DMA_SPATIAL_INIT_SHARED_H
#define __DFM_3A_AF_DMA_SPATIAL_INIT_SHARED_H

#include "common_io.host.h"
#include "dfm_resource_types.h"
#include "resource_types.h"

/* ACTIVE PORTS - 2
 * 1) DFM_ISA_3A_AF_0_PORT
 * 2) DFM_ISA_3A_AF_1_PORT
 */
/* PASSIVE PORTS
 * DFM_ISA_DMA_3A_AF_STAT_CH_0_PORT
 * DFM_ISA_DMA_3A_AF_STAT_CH_1_PORT
 */

#define DFM_3A_AF_DMA_SPATIAL_NUM_PROD_PORTS	(2) /* DFM_ISA_3A_AF_0_PORT
						       DFM_ISA_3A_AF_1_PORT */
#define DFM_3A_AF_DMA_SPATIAL_NUM_CONS_PORTS	(2) /* DFM_ISA_DMA_3A_AF_STAT_CH_0_PORT,
						       DFM_ISA_DMA_3A_AF_STAT_CH_1_PORT */
#define DFM_3A_AF_NUM_BUFFERS			(2)

static void dfm_dma_3a_af_spatial_open(const struct ipu_kernel_fragment_sequencer_info_desc_s *kernel_frag_seq_info,
					dfm_port_resource_t dfm_dma_ports,
					uint32_t ack_addr,
					uint32_t ack_data,
					resource_t dma_chan,
					enum ipu_device_dfm_id dev_id,
					void *payload_address[DFM_3A_AF_DMA_SPATIAL_NUM_CONS_PORTS]);

static void dfm_acb_3a_af_spatial_open(const struct ipu_kernel_fragment_sequencer_info_desc_s *kernel_frag_seq_info,
					dfm_port_resource_t dfm_acb_ports,
					uint32_t ack_addr,
					uint32_t ack_data,
					enum ipu_device_dfm_id dev_id,
					void *payload_address[DFM_3A_AF_DMA_SPATIAL_NUM_PROD_PORTS]);

#ifndef PIPE_GENERATION
#include "dfm_3a_af_dma_spatial_init.shared.c"
#endif

#endif /* __DFM_3A_AF_DMA_SPATIAL_INIT_SHARED_H */