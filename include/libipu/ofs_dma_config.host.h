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

#ifndef OFS_DMA_CONFIG_HOST_H_
#define OFS_DMA_CONFIG_HOST_H_

#include "storage_class.h"
#include "dma_nci_io.shared.h"
#include "vied_nci_dma_types.h"
#include "ipu_device_dma_devices.h"
#include "ipu_device_ofs_devices.h"
#include "ipu_device_dma_type_properties.h"
#include "dev_api_dfm_types.h"
#include "resource_types.h"
#include "buf_blk.host.h"
#include "ia_css_common_io_types.h"
#include "ipu_resources_dma_term.h"
#include "ofs_dma_config_def.h"
#include "adi_ofs_types.h"

void ofs_dma_set_dma_desc_config(p_terminal_config ddr_config,
		mem_ptr_t q_out_ptr,
		struct  ipu_resources_dma_descriptor_config *dma_desc_cfg,
		uint32_t *stream_ids_array,
		uint32_t num_of_streams,
		uint32_t ack_addr,
		uint32_t ack_data,
		vied_nci_dev_chn_ID_t dev,
		uint32_t dma_chan_offset,
		uint32_t nof_dma_chan,
		enum ipu_device_ofs_pin_id pin_id);

#endif /* OFS_DMA_CONFIG_HOST_H_ */
