/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2018 Intel Corporation.
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

#ifndef __PG_CONTROL_INIT_SUPPORT_DEP_H
#define __PG_CONTROL_INIT_SUPPORT_DEP_H

resource_id_t get_resource_id_from_dev_chn_id(vied_nci_dev_chn_ID_t chn_id)
{
	switch (chn_id) {
	case VIED_NCI_DEV_CHN_DMA_EXT0_ID:
		return vied_nci_dev_chn_dma_ext0;
	case VIED_NCI_DEV_CHN_DMA_EXT1_READ_ID:
		return vied_nci_dev_chn_dma_ext1_read;
	case VIED_NCI_DEV_CHN_DMA_EXT1_WRITE_ID:
		return vied_nci_dev_chn_dma_ext1_write;
#if (HAS_DMA_INTERNAL == 1)
	case VIED_NCI_DEV_CHN_DMA_INTERNAL_ID:
		return vied_nci_dev_chn_dma_internal;
#endif
	default:
		IA_CSS_TRACE_1(PG_CONTROL_INIT, ERROR, "get_resource_id_from_dev_chn_id chn_id:%d not supported", chn_id);
		assert(0);
		return 0;
	}
}


#endif /* __PG_CONTROL_INIT_SUPPORT_DEP_H */
