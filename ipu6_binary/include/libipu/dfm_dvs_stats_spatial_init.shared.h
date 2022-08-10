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

#ifndef __DFM_DVS_STATS_SPATIAL_INIT_SHARED_H
#define __DFM_DVS_STATS_SPATIAL_INIT_SHARED_H

#define DFM_DVS_STATS_DMA_SPATIAL_NUM_BUFFERS	(2)
#define DVS_STATS_TRANSFER_DMA_ID		NCI_DMA_EXT0

static void dfm_dma_dvs_stats_spatial_open(uint32_t grid_height,
					uint32_t dfm_nci_port_dma,
					resource_t dma_channel,
					uint32_t ack_addr,
					uint32_t ack_data,
					void *payload_address,
					bool ignore_first_event,
					unsigned dma_requestor_id);

static void dfm_acb_dvs_stats_spatial_open(unsigned int dvs_level_select,
					uint32_t grid_height,
					uint32_t block_height,
					uint32_t ff_y_bin_mode,
					uint32_t y_start,
					uint32_t y_end,
					uint32_t dfm_nci_port_acb,
					s_resolution_t res,
					uint32_t ack_addr,
					uint32_t ack_data,
					void *payload_address,
					bool send_init_cmd);

#ifndef PIPE_GENERATION
#include "dfm_dvs_stats_spatial_init.shared.c"
#endif

#endif /* __DFM_DVS_STATS_SPATIAL_INIT_SHARED_H */
