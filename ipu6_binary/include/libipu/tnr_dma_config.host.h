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

#ifndef TNR_DMA_CONFIG_HOST_H_
#define TNR_DMA_CONFIG_HOST_H_

#include "storage_class.h"
#include "ia_css_common_io_types.h" /* For p_terminal_config */
#include "ipu_resources_dma_term.h" /* For ipu_resources_dma_descriptor_config */
#include "bufqueue.host.h" /* For bufqueue_t */

struct tnr_dma_resource_id {
	unsigned dma_dev_chn_id;
	unsigned req_bank_id;
	unsigned unit_descr_id;
	unsigned channel_descr_id;
	uint32_t spanA_descr_id;
	uint32_t spanB_descr_id;
	unsigned terminalA_descr_id;
	unsigned terminalB_descr_id;
};

/**
 * @brief TNR6 Fill the DMA HBtX descriptor for Reference Frame writing
 *
 * @param[in] p_terminal_config ddr_config                            Data Out terminal configuration pointer (DDR)
 * @param[in] p_spatial_terminal_config ddr_spatial_config            Spatial Out terminal configuration pointer (DDR)
 * @param[in] bufqueue_t q_in                                         Buffer queue in Transfer VMEM
 * @param[in] struct ipu_resources_dma_descriptor_config *dma_desc_cfg   DMA HBtX descriptor configuration
 * @param[in] uint32_t ack_addr                                       Address where the DMA Ack should be sent
 * @param[in] uint32_t ack_data                                       Value of the DMA Ack token
 * @param[in] uint32_t nof_dma_chan                                   Number of DMA channels (3: Y, UV, recsim)
 *
 * @return void
 **/
void tnr_dma_hb_ref_out_config(p_terminal_config ddr_config,
		p_spatial_terminal_config ddr_spatial_config,
		bufqueue_t q_out,
		struct  ipu_resources_dma_descriptor_config *dma_desc_cfg,
		uint32_t ack_addr,
		uint32_t ack_data,
		vied_nci_resource_size_t nof_dma_chan);

#endif /* TNR_DMA_CONFIG_HOST_H_ */
