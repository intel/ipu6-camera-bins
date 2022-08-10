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

#ifndef __PG_BB_GDC_MBR_OFS_H
#define __PG_BB_GDC_MBR_OFS_H

#include "isp_global.h"
#include "mbr_defines.h"
#include "ofs_dma_config_def.h"
#include "ia_css_vmem_resources.h"

#define CHROMA_SUBSAMPLE_SHIFT                        (1)

/*
 * QUEUE CONFIGURATIONS
 */
/* OFS input queue configuration */
#define Q_OFS_IN_BUF_MEM                              (buf_mem_ofs_vmem)
#define Q_OFS_IN_BUF_START_ADDR                       (0)
#define Q_OFS_IN_NUMBUF                               (3)
#define Q_OFS_IN_WIDTH                                (GDC_OXDIM_DEFAULT)
#define Q_OFS_IN_HEIGHT                               (GDC_OYDIM_DEFAULT)

#define Q_OFS_IN_WIDTH_Y                              (CEIL_DIV(Q_OFS_IN_WIDTH, ISP_NWAY))
#define Q_OFS_IN_HEIGHT_Y                             (Q_OFS_IN_HEIGHT)
#define Q_OFS_IN_SIZE_Y                               (Q_OFS_IN_WIDTH_Y * Q_OFS_IN_HEIGHT_Y)

#define Q_OFS_IN_WIDTH_U                              (CEIL_DIV((Q_OFS_IN_WIDTH >> CHROMA_SUBSAMPLE_SHIFT), ISP_NWAY))
#define Q_OFS_IN_HEIGHT_U                             (Q_OFS_IN_HEIGHT_Y >> CHROMA_SUBSAMPLE_SHIFT)
#define Q_OFS_IN_SIZE_U                               (Q_OFS_IN_WIDTH_U * Q_OFS_IN_HEIGHT_U)

#define Q_OFS_IN_WIDTH_V                              (Q_OFS_IN_WIDTH_U)
#define Q_OFS_IN_HEIGHT_V                             (Q_OFS_IN_HEIGHT_U)
#define Q_OFS_IN_SIZE_V                               (Q_OFS_IN_SIZE_U)

#define Q_OFS_IN_SIZE                                 (Q_OFS_IN_SIZE_Y + Q_OFS_IN_SIZE_U + Q_OFS_IN_SIZE_V)

/* OFS output queue properties */
#define Q_OFS_OUT_BUF_MEM                             VMEM_SECTION_BBPS_OFA_OUTPUT_MEM_ID
#define Q_OFS_OUT_BUF_START_ADDR                      (VMEM_SECTION_BBPS_OFA_OUTPUT_OFFSET * ISP_VEC_BYTES)
#define Q_OFS_OUT_BUF_SIZE_VECS                       (VMEM_SECTION_BBPS_OFA_OUTPUT_SIZE)
#define Q_OFS_OUT_BUF_SIZE_BYTES                      (VMEM_SECTION_BBPS_OFA_OUTPUT_SIZE * ISP_VEC_BYTES)

/*
 * DMA CONFIGURATIONS
 */

/* DMA in configuration */
#define GDC_MBR_DMA_HB_ID                             vied_nci_dev_chn_dma_ext1_read
#define GDC_MBR_DMA_HB_SIZE                           (GDC_MBR_MAX_BATCH_SIZE)

#define GDC_MBR_DMA_INT_ID                            vied_nci_dev_chn_dma_internal
#define GDC_MBR_DMA_INT_SIZE                          GDC_MBR_NUMBER_OF_INTERNAL_DMA_CHANNELS

/* DMA out configuration */
#define MAIN_OUTPUT_PIN_DMA_RESOURCE_ID               vied_nci_dev_chn_dma_ext1_write
#define MAIN_OUTPUT_PIN_NUM_DMA_CHANNELS              OFS_DMA_MAX_NUM_DMA_CHANNELS

#define DISPLAY_OUTPUT_PIN_DMA_RESOURCE_ID            vied_nci_dev_chn_dma_ext1_write
#define DISPLAY_OUTPUT_PIN_NUM_DMA_CHANNELS           OFS_DMA_MAX_NUM_DMA_CHANNELS

#define PP_OUTPUT_PIN_DMA_RESOURCE_ID                 vied_nci_dev_chn_dma_ext1_write
#define PP_OUTPUT_PIN_NUM_DMA_CHANNELS                OFS_DMA_MAX_NUM_DMA_CHANNELS

#endif /* __PG_BB_GDC_MBR_OFS_H */

