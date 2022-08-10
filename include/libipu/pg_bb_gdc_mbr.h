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

#ifndef __PG_BB_GDC_MBR_H
#define __PG_BB_GDC_MBR_H

#include "isp_global.h"
#include "mbr_defines.h"
#include "frame_support.h"

#define CHROMA_SUBSAMPLE_SHIFT                      (1)

/*
 * QUEUE CONFIGURATIONS
 */
/* GDC output queue configuration */
#define Q_GDC_OUT_BUF_MEM                            (buf_mem_transfer_vmem0)
#define Q_GDC_OUT_BUF_START_ADDR                     (0)
#define Q_GDC_OUT_NUMBUF                             (3)
#define Q_GDC_OUT_WIDTH                              (GDC_OXDIM_DEFAULT)
#define Q_GDC_OUT_HEIGHT                             (GDC_OYDIM_DEFAULT)

#define Q_GDC_OUT_WIDTH_Y                            (CEIL_DIV(Q_GDC_OUT_WIDTH, ISP_NWAY))
#define Q_GDC_OUT_HEIGHT_Y                           (Q_GDC_OUT_HEIGHT)
#define Q_GDC_OUT_SIZE_Y                             (Q_GDC_OUT_WIDTH_Y * Q_GDC_OUT_HEIGHT_Y)

#define Q_GDC_OUT_WIDTH_U                            (CEIL_DIV((Q_GDC_OUT_WIDTH >> CHROMA_SUBSAMPLE_SHIFT), ISP_NWAY))
#define Q_GDC_OUT_HEIGHT_U                           (Q_GDC_OUT_HEIGHT_Y >> CHROMA_SUBSAMPLE_SHIFT)
#define Q_GDC_OUT_SIZE_U                             (Q_GDC_OUT_WIDTH_U * Q_GDC_OUT_HEIGHT_U)

#define Q_GDC_OUT_WIDTH_V                            (Q_GDC_OUT_WIDTH_U)
#define Q_GDC_OUT_HEIGHT_V                           (Q_GDC_OUT_HEIGHT_U)
#define Q_GDC_OUT_SIZE_V                             (Q_GDC_OUT_SIZE_U)

#define Q_GDC_OUT_SIZE                               (Q_GDC_OUT_SIZE_Y + Q_GDC_OUT_SIZE_U + Q_GDC_OUT_SIZE_V)


/*
 * DMA CONFIGURATIONS
 */

/* DMA in configuration */
#define GDC_MBR_DMA_HB_ID                                vied_nci_dev_chn_dma_ext1_read
#define GDC_MBR_DMA_HB_SIZE                              (GDC_MBR_MAX_BATCH_SIZE)

#define GDC_MBR_DMA_INT_ID                               vied_nci_dev_chn_dma_internal
#define GDC_MBR_DMA_INT_SIZE                             GDC_MBR_NUMBER_OF_INTERNAL_DMA_CHANNELS

/* DMA out configuration */
#define DMA_NCI_YUV_OUTPUT_TRANSFER_DMA_RESOURCE_ID      vied_nci_dev_chn_dma_ext1_write
#define DMA_NCI_YUV_TRANSFER_NUM_DMA_CHANNELS_PER_PLANE  (1)
#define DMA_NCI_YUV_TRANSFER_NUM_DMA_CHANNELS            (YUV_PLANAR_FRAME_TYPE_NUM_PLANES * DMA_NCI_YUV_TRANSFER_NUM_DMA_CHANNELS_PER_PLANE)

/*
 * DFM CONFIGURATIONS
 */

/* DFM for output kernel */
#define DFM_CONS_DMA_YUV_OUTPUT_PORT_NUM_VPLESS          (32)
#define DFM_CONS_DMA_YUV_OUTPUT_PORT_SIZE                (3)
#define DFM_CONS_DEVICE_ID                               VIED_NCI_DEV_DFM_BB_FULL_PORT_ID
#define DFM_DMA_YUV_OUTPUT_DMA_RESOURCE_ID               DMA_NCI_YUV_OUTPUT_TRANSFER_DMA_RESOURCE_ID

/* DFM gather multicast */
#define DFM_GATHER_PORT_OFFSET                           (DFM_CONS_DMA_YUV_OUTPUT_PORT_NUM_VPLESS + DFM_CONS_DMA_YUV_OUTPUT_PORT_SIZE)
#define DFM_GATHER_DEVICE_ID                             VIED_NCI_DEV_DFM_BB_FULL_PORT_ID
#define DFM_GATHER_PORT_SIZE                             (3)

#define DFM_MULTICAST_PORT_OFFSET                        (0)
#define DFM_MULTICAST_DEVICE_ID                          VIED_NCI_DEV_DFM_BB_EMPTY_PORT_ID
#define DFM_MULTICAST_PORT_SIZE                          (3)

#endif /* __PG_BB_GDC_MBR_H */

