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

#ifndef __PG_BB_OFS_SHARED_H
#define __PG_BB_OFS_SHARED_H
#include "ia_css_vmem_resources.h"

/* TERMINAL properties */
#define GET_MIN_WIDTH          256
#define GET_MIN_HEIGHT         128
#define GET_MAX_WIDTH          4096
#define GET_MAX_HEIGHT         2160

#define MAIN_OUTPUT_MIN_WIDTH          256
#define MAIN_OUTPUT_MIN_HEIGHT         128
#define MAIN_OUTPUT_MAX_WIDTH          4096
#define MAIN_OUTPUT_MAX_HEIGHT         2160

#define DISPLAY_OUTPUT_MIN_WIDTH          256
#define DISPLAY_OUTPUT_MIN_HEIGHT         128
#define DISPLAY_OUTPUT_MAX_WIDTH          4096
#define DISPLAY_OUTPUT_MAX_HEIGHT         2160

#define PP_OUTPUT_MIN_WIDTH          256
#define PP_OUTPUT_MIN_HEIGHT         128
#define PP_OUTPUT_MAX_WIDTH          1920
#define PP_OUTPUT_MAX_HEIGHT         1080

/*DMA resources offsets*/
#define	VIED_NCI_LB_VMEM_TYPE_OFFSET                    0
#define	VIED_NCI_DEV_CHN_DMA_EXT0_OFFSET                0
#define VIED_NCI_DEV_CHN_DMA_EXT1_WRITE_OFFSET          5
#define VIED_NCI_DEV_CHN_DMA_EXT1_READ_OFFSET           8
#define VIED_NCI_TRANSFER_VMEM1_TYPE_OFFSET		VMEM_SECTION_BBPS_OFA_OUTPUT_OFFSET
#define OFS_CONNECT_SECTIONS_PER_PIN                              (3)
#define OFS_RELEASE_ACK_AGGREGATE_CONNECT_SECTIONS_PER_PIN        (1)

#define GATHER_MC_MASK_CONNECT_SECTIONS                           (1)
#endif /* __PG_BB_OFS_SHARED_H */