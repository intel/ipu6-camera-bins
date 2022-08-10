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

#ifndef __PG_BB_GDC_MBR_SHARED_H
#define __PG_BB_GDC_MBR_SHARED_H


/* TERMINAL properties */
#define GET_MIN_WIDTH                  256
#define GET_MIN_HEIGHT                 128
#define GET_MAX_WIDTH                  4096
#define GET_MAX_HEIGHT                 2160

#define PUT_MIN_WIDTH                  256
#define PUT_MIN_HEIGHT                 128
#define PUT_MAX_WIDTH                  4096
#define PUT_MAX_HEIGHT                 2160

/*DMA resources offsets*/
#define	VIED_NCI_LB_VMEM_TYPE_OFFSET                    0
#define	VIED_NCI_DEV_CHN_DMA_EXT0_OFFSET                0
#define VIED_NCI_DEV_CHN_DMA_EXT1_WRITE_OFFSET          0
#define VIED_NCI_DEV_CHN_DMA_EXT1_READ_OFFSET           0
#define VIED_NCI_DEV_CHN_DMA_INTERNAL_OFFSET            0

#endif /* __PG_BB_GDC_MBR_SHARED_H */
