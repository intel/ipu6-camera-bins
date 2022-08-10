/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2017 - 2019 Intel Corporation.
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

#ifndef __PG_BB_SHARED_H
#define __PG_BB_SHARED_H
#include "ia_css_vmem_resources.h"
#include "ia_css_dma_resources.h"

/* TERMINAL properties
 * TNR Bypass Mode still has a horizontal limit of 4096
 * Video: max: 4096x2304 (TNR)
 * Still: max: 4096x4016 (no TNR)
 */
#define GET_MIN_WIDTH                  256
#define GET_MIN_HEIGHT                 128
#define GET_MAX_WIDTH                  4096
#define GET_MAX_HEIGHT                 4016

#define MAIN_OUTPUT_MIN_WIDTH          256
#define MAIN_OUTPUT_MIN_HEIGHT         128
#define MAIN_OUTPUT_MAX_WIDTH          4096
#define MAIN_OUTPUT_MAX_HEIGHT         4016

#define DISPLAY_OUTPUT_MIN_WIDTH       256
#define DISPLAY_OUTPUT_MIN_HEIGHT      128
#define DISPLAY_OUTPUT_MAX_WIDTH       4096
#define DISPLAY_OUTPUT_MAX_HEIGHT      4016

#define PP_OUTPUT_MIN_WIDTH            256
#define PP_OUTPUT_MIN_HEIGHT           128
#define PP_OUTPUT_MAX_WIDTH            1920
#define PP_OUTPUT_MAX_HEIGHT           1080

#define TNR_REF_IN_MIN_WIDTH            256
#define TNR_REF_IN_MIN_HEIGHT           128
#define TNR_REF_IN_MAX_WIDTH            4096
#define TNR_REF_IN_MAX_HEIGHT           2304

#define TNR_REF_OUT_MIN_WIDTH            256
#define TNR_REF_OUT_MIN_HEIGHT           128
#define TNR_REF_OUT_MAX_WIDTH            4096
#define TNR_REF_OUT_MAX_HEIGHT           2304

#define TNR_RECSIM_COMPUTE_UNITS_PER_ELEM  1
#define TNR_RECSIM_ELEM_SIZE_IN_BYTES      2
#define TNR_RECSIM_SUBSAMPLE_SHIFT         2

#define TNR_RECSIM_OUT_MIN_WIDTH            (TNR_REF_OUT_MIN_WIDTH  >> TNR_RECSIM_SUBSAMPLE_SHIFT)
#define TNR_RECSIM_OUT_MIN_HEIGHT           (TNR_REF_OUT_MIN_HEIGHT >> TNR_RECSIM_SUBSAMPLE_SHIFT)
#define TNR_RECSIM_OUT_MAX_WIDTH            (TNR_REF_OUT_MAX_WIDTH  >> TNR_RECSIM_SUBSAMPLE_SHIFT)
#define TNR_RECSIM_OUT_MAX_HEIGHT           (TNR_REF_OUT_MAX_HEIGHT >> TNR_RECSIM_SUBSAMPLE_SHIFT)

#define TNR_RECSIM_IN_MIN_WIDTH            (TNR_REF_IN_MIN_WIDTH  >> TNR_RECSIM_SUBSAMPLE_SHIFT)
#define TNR_RECSIM_IN_MIN_HEIGHT           (TNR_REF_IN_MIN_HEIGHT >> TNR_RECSIM_SUBSAMPLE_SHIFT)
#define TNR_RECSIM_IN_MAX_WIDTH            (TNR_REF_IN_MAX_WIDTH  >> TNR_RECSIM_SUBSAMPLE_SHIFT)
#define TNR_RECSIM_IN_MAX_HEIGHT           (TNR_REF_IN_MAX_HEIGHT >> TNR_RECSIM_SUBSAMPLE_SHIFT)

/*DMA resources offsets*/
#define VIED_NCI_DEV_CHN_DMA_EXT0_OFFSET                IA_CSS_DMA_RESOURCES_DMA_LB_CHN_OFFSET_BB
#define VIED_NCI_DEV_CHN_DMA_EXT1_WRITE_OFFSET          IA_CSS_DMA_RESOURCES_DMA_EXT1_CHN_WRITE_OFFSET_BB
#define VIED_NCI_DEV_CHN_DMA_EXT1_READ_OFFSET           IA_CSS_DMA_RESOURCES_DMA_EXT1_CHN_READ_OFFSET_BB
#define VIED_NCI_DEV_CHN_DMA_INTERNAL_OFFSET            0
/*VMEM resources offsets*/
#define VIED_NCI_TRANSFER_VMEM0_TYPE_OFFSET             VMEM_SECTION_BBPS_TNR_REFOUT_OFFSET
#define VIED_NCI_TRANSFER_VMEM1_TYPE_OFFSET		VMEM_SECTION_BBPS_OFA_OUTPUT_OFFSET

#define OFS_CONNECT_SECTIONS_PER_PIN                    (3)

/* TNR required two connect section to set the frame init
 * register dynamically. If the reference input terminal
 * is enabled/exists then reading of the reference data will
 * be enabled. If the reference output terminal is enabled/exists
 * then writing of the reference data will be enabled
 */
#define TNR_FRAME_INIT_CONNECT_SECTIONS                         (2)
#define TNR_GATHER_MC_MASK_CONNECT_SECTIONS                     (1)
#define OFS_RELEASE_ACK_AGGREGATE_CONNECT_SECTIONS_PER_PIN      (1)
/* Stream2gen is supported only on MP */
#define OFS_STREAM2GEN_CONNECT_SECTIONS                   (1)

#endif /* __PG_BB_SHARED_H */
