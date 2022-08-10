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

#ifndef __DMA_SPATIAL_INIT_HOST_H
#define __DMA_SPATIAL_INIT_HOST_H

#include "resource.host.h"
#include "dma_nci_io.host.h"
#include "ia_css_common_io_types.h"
#include "ipu_device_ff_properties.h"
#include "spatial_param_interface.h"
#include "storage_class.h"

enum spatial_term_type {
	DFM_SPATIAL_CTRL_INIT_SPATIAL_IN,
	DFM_SPATIAL_CTRL_INIT_SPATIAL_OUT,
};

STORAGE_CLASS_INLINE void generic_dma_spatial_open(const struct ipu_kernel_fragment_sequencer_info_desc_s *kernel_frag_seq_info,
				enum ipu_device_ff_id ipu_device_ff_id_,
				enum spatial_term_type spatial_type_,
				enum nci_dma_command dma_cmd_,
				p_spatial_terminal_config spatial_cfg,
				struct ipu_resources_dma_descriptor_config *cfg,
				resource_t dma_chan,
				unsigned dma_ack_addresses[],
				unsigned int num_dma_channel_,
				unsigned int num_buf_,
				const interface_spatial_parameter_t *p_spatial_);

#ifndef PIPE_GENERATION
#include "dma_spatial_init.host.c"
#endif

#endif /* __GENERIC_DMA_SPATIAL_INIT_HOST_H */
