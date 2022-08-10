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

#ifndef __PSA_SHARED_DEFS_H
#define __PSA_SHARED_DEFS_H
/**
 * Defines that are common to IPU6_LB and ISA_LB.
 */
#define PSA_GAMMASTAR_DMA_EXT0_SIZE			(1)
#define PSA_GAMMASTAR_DMA_EXT0_OFFSET			IA_CSS_DMA_RESOURCES_DMA_LB_CHN_OFFSET_PSA

#define PSA_DVS_STATS_DMA_EXT0_SIZE			(1) /* Same for all levels */
#define PSA_DVS_STATS_DMA_ID_ISP_MODEL			vied_nci_dev_chn_dma_ext0
#define PSA_DVS_STATS_DMA_ID_API_MODEL			VIED_NCI_DEV_CHN_DMA_EXT0_ID
#define PSA_DVS_STATS_L0_DMA_EXT0_OFFSET		(PSA_GAMMASTAR_DMA_EXT0_OFFSET + PSA_GAMMASTAR_DMA_EXT0_SIZE)
#define PSA_DVS_STATS_L1_DMA_EXT0_OFFSET		(PSA_DVS_STATS_L0_DMA_EXT0_OFFSET + PSA_DVS_STATS_DMA_EXT0_SIZE)
#define PSA_DVS_STATS_L2_DMA_EXT0_OFFSET		(PSA_DVS_STATS_L1_DMA_EXT0_OFFSET + PSA_DVS_STATS_DMA_EXT0_SIZE)

#endif /* __PSA_SHARED_DEFS_H */
