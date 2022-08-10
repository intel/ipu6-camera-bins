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

#ifndef __DVS_ACC_SHARED_H
#define __DVS_ACC_SHARED_H

#include "ia_css_psa_parameter_defs.h"

#define ISP_TO_DVS_CTRLR_BASE              (IDSP_TO_DVS_CTRLR_ACB_BASE_ADDR)
#define ISP_TO_DVS_CTRLR_CMD_FIFO_L0       (ISP_TO_DVS_CTRLR_BASE)
#define ISP_TO_DVS_CTRLR_ACK_ADDR_L0       (ISP_TO_DVS_CTRLR_BASE + 0x04)
#define ISP_TO_DVS_CTRLR_ACK_DATA_L0       (ISP_TO_DVS_CTRLR_BASE + 0x08)
#define ISP_TO_DVS_CTRLR_CMD_FIFO_L1       (ISP_TO_DVS_CTRLR_BASE + 0x0C)
#define ISP_TO_DVS_CTRLR_ACK_ADDR_L1       (ISP_TO_DVS_CTRLR_BASE + 0x10)
#define ISP_TO_DVS_CTRLR_ACK_DATA_L1       (ISP_TO_DVS_CTRLR_BASE + 0x14)
#define ISP_TO_DVS_CTRLR_CMD_FIFO_L2       (ISP_TO_DVS_CTRLR_BASE + 0x18)
#define ISP_TO_DVS_CTRLR_ACK_ADDR_L2       (ISP_TO_DVS_CTRLR_BASE + 0x1C)
#define ISP_TO_DVS_CTRLR_ACK_DATA_L2       (ISP_TO_DVS_CTRLR_BASE + 0x20)

#define ISP_TO_DVS_CTRLR_ACK_FIFO_TAIL     (ISP_TO_DVS_CTRLR_BASE + 0x24)
#define ISP_TO_DVS_CTRLR_GENERAL_CNRL      (ISP_TO_DVS_CTRLR_BASE + 0x28)
#define ISP_TO_DVS_CTRLR_DVS_ACC_ACB_ADDR  (ISP_TO_DVS_CTRLR_BASE + 0x2C)

#define ISP_TO_DVS_CTRLR_STATUS0           (ISP_TO_DVS_CTRLR_BASE + 0x30)
#define ISP_TO_DVS_CTRLR_STATUS1           (ISP_TO_DVS_CTRLR_BASE + 0x34)
#define ISP_TO_DVS_CTRLR_STATUS2           (ISP_TO_DVS_CTRLR_BASE + 0x38)

#define ISP_TO_DVS_CTRLR_HW_ASSR_CLEAR     (ISP_TO_DVS_CTRLR_BASE + 0x3C)
#define ISP_TO_DVS_CTRLR_HW_ASSR_MASK      (ISP_TO_DVS_CTRLR_BASE + 0x40)
#define ISP_TO_DVS_CTRLR_HW_ASSR_STAT      (ISP_TO_DVS_CTRLR_BASE + 0x44)
#define ISP_TO_DVS_CTRLR_HW_ASSR_RAW_STAT  (ISP_TO_DVS_CTRLR_BASE + 0x48)

#define DVS_ACB_TO_DVS_CTRLR_ACK_FIFO_TAIL (DVS_ACB_TO_DVS_CTRLR_BASE_ADDR + 0x24)
#define ACK_DATA                  (0xCAFEBABE)
#define DVS_MV_ACK_OFFSET         (0x00000)
#define CMD_FIFO_TAIL_Lx_OFFSET   (0x0C)

/* This offset is from DVS ACB to DVS_DVS == (LB_DMA_TO_DVS_STATS_BASE_ADDRESS - REGISTER_MAP_BASE_DMA_M0) */
#define DVS_STATS_BASE            (0x00300)
#define DVS_BEST_FE_L0_REG_OFFSET (IA_CSS_PSA_PARAMETER_OUT_TERMINAL_DVS_FE_L0_DEST_OFFSET_SECTION_0 + DVS_STATS_BASE)
#define DVS_BEST_FE_L1_REG_OFFSET (IA_CSS_PSA_PARAMETER_OUT_TERMINAL_DVS_FE_L1_DEST_OFFSET_SECTION_0 + DVS_STATS_BASE)
#define DVS_BEST_FE_L2_REG_OFFSET (IA_CSS_PSA_PARAMETER_OUT_TERMINAL_DVS_FE_L2_DEST_OFFSET_SECTION_0 + DVS_STATS_BASE)

#define DVS_PREV_FE_L0_REG_OFFSET (IA_CSS_PSA_PROGRAM_TERMINAL_DVS_PREV_FE_L0_DEST_OFFSET_SECTION_0 + DVS_STATS_BASE)
#define DVS_PREV_FE_L1_REG_OFFSET (IA_CSS_PSA_PROGRAM_TERMINAL_DVS_PREV_FE_L1_DEST_OFFSET_SECTION_0 + DVS_STATS_BASE)
#define DVS_PREV_FE_L2_REG_OFFSET (IA_CSS_PSA_PROGRAM_TERMINAL_DVS_PREV_FE_L2_DEST_OFFSET_SECTION_0 + DVS_STATS_BASE)

#define DVS_MV_L0_REG_OFFSET      (0x04200 + DVS_STATS_BASE)
#define DVS_MV_L1_REG_OFFSET      (0x04500 + DVS_STATS_BASE)
#define DVS_MV_L2_REG_OFFSET      (0x04780 + DVS_STATS_BASE)

#define DVS_MV_L0_SET0_SET1_OFF_DIFF (0x20) /* Base offset difference between Set0 base address + Set0 size - Set1 base offset */
#define DVS_MV_L1_SET0_SET1_OFF_DIFF (0x0)  /* Base offset difference between Set0 base address + Set0 size - Set1 base offset */
#define DVS_MV_L2_SET0_SET1_OFF_DIFF (0x30) /* Base offset difference between Set0 base address + Set0 size - Set1 base offset */

/* DVS addresses using CMEM bus */
#define DVS_BF_L0_BASE_ADDRESS       (IDSP_TO_DVS_STAT_BASE_ADDR + IA_CSS_PSA_PROGRAM_TERMINAL_DVS_PREV_FE_L0_DEST_OFFSET_SECTION_0)
#define DVS_BF_L1_BASE_ADDRESS       (IDSP_TO_DVS_STAT_BASE_ADDR + IA_CSS_PSA_PROGRAM_TERMINAL_DVS_PREV_FE_L1_DEST_OFFSET_SECTION_0)
#define DVS_BF_L2_BASE_ADDRESS       (IDSP_TO_DVS_STAT_BASE_ADDR + IA_CSS_PSA_PROGRAM_TERMINAL_DVS_PREV_FE_L2_DEST_OFFSET_SECTION_0)

#define PREV_FE_INSTANCES_L0         (154)
#define PREV_FE_INSTANCES_L1         (120)
#define PREV_FE_INSTANCES_L2         (85)

#define L0_BF_BYTE_READ_PER_MV_READ (0x20)
#define FE_BYTES_PER_GRID_UNIT      (40)  /* 10 parts of 4 bytes */
#define PREV_FE_Q_BLK_WIDTH_L0      (PREV_FE_INSTANCES_L0 * FE_BYTES_PER_GRID_UNIT)
#define PREV_FE_Q_BLK_WIDTH_L1      (PREV_FE_INSTANCES_L1 * FE_BYTES_PER_GRID_UNIT)
#define PREV_FE_Q_BLK_WIDTH_L2      (PREV_FE_INSTANCES_L2 * FE_BYTES_PER_GRID_UNIT)

/* Ref. HAS DVS statistics */
#define DVS_NUM_OF_LEVELS         (3)
#define MV_Q_NUMBUF               (2)
#define MV_INSTANCES_L0           (22)
#define MV_INSTANCES_L1           (20)
#define MV_INSTANCES_L2           (17)
#define MV_BYTES_PER_GRID_UNIT    (16)  /* 4 parts of 4 bytes */

#define MV_Q_BLK_WIDTH_L0         ((MV_INSTANCES_L0 * MV_BYTES_PER_GRID_UNIT) + DVS_MV_L0_SET0_SET1_OFF_DIFF)
#define MV_Q_BLK_WIDTH_L1         ((MV_INSTANCES_L1 * MV_BYTES_PER_GRID_UNIT) + DVS_MV_L1_SET0_SET1_OFF_DIFF)
#define MV_Q_BLK_WIDTH_L2         ((MV_INSTANCES_L2 * MV_BYTES_PER_GRID_UNIT) + DVS_MV_L2_SET0_SET1_OFF_DIFF)
#define MV_Q_BLK_HEIGHT_L0        1
#define MV_Q_BLK_HEIGHT_L1        1
#define MV_Q_BLK_HEIGHT_L2        1
#define MV_Q_SIZE_L0              (MV_Q_BLK_HEIGHT_L0 * MV_Q_BLK_WIDTH_L0)
#define MV_Q_SIZE_L1              (MV_Q_BLK_HEIGHT_L1 * MV_Q_BLK_WIDTH_L1)
#define MV_Q_SIZE_L2              (MV_Q_BLK_HEIGHT_L2 * MV_Q_BLK_WIDTH_L2)

/* Ref. HAS DVS statistics */
#define PREV_FE_Q_NUMBUF               1
#define PREV_FE_Q_BLK_HEIGHT_L0        1
#define PREV_FE_Q_BLK_HEIGHT_L1        1
#define PREV_FE_Q_BLK_HEIGHT_L2        1
#define PREV_FE_Q_SIZE_L0              (PREV_FE_Q_BLK_HEIGHT_L0 * PREV_FE_Q_BLK_WIDTH_L0)
#define PREV_FE_Q_SIZE_L1              (PREV_FE_Q_BLK_HEIGHT_L1 * PREV_FE_Q_BLK_WIDTH_L1)
#define PREV_FE_Q_SIZE_L2              (PREV_FE_Q_BLK_HEIGHT_L2 * PREV_FE_Q_BLK_WIDTH_L2)

/* Ref. HAS DVS statistics */
#define BEST_FE_Q_NUMBUF               1
#define BEST_FE_Q_BLK_WIDTH_L0         (PREV_FE_Q_BLK_WIDTH_L0)
#define BEST_FE_Q_BLK_WIDTH_L1         (PREV_FE_Q_BLK_WIDTH_L1)
#define BEST_FE_Q_BLK_WIDTH_L2         (PREV_FE_Q_BLK_WIDTH_L2)
#define BEST_FE_Q_BLK_HEIGHT_L0        1
#define BEST_FE_Q_BLK_HEIGHT_L1        1
#define BEST_FE_Q_BLK_HEIGHT_L2        1
#define BEST_FE_Q_SIZE_L0              (BEST_FE_Q_BLK_HEIGHT_L0 * BEST_FE_Q_BLK_WIDTH_L0)
#define BEST_FE_Q_SIZE_L1              (BEST_FE_Q_BLK_HEIGHT_L1 * BEST_FE_Q_BLK_WIDTH_L1)
#define BEST_FE_Q_SIZE_L2              (BEST_FE_Q_BLK_HEIGHT_L2 * BEST_FE_Q_BLK_WIDTH_L2)

/* queue for notifying the ack's for any level */
#define MV_Q_ACK_NUMBUF             2
#define MV_Q_ACK_BLK_WIDTH          1
#define MV_Q_ACK_BLK_HEIGHT         1
#define MV_Q_ACK_SIZE               (MV_Q_ACK_BLK_HEIGHT * MV_Q_ACK_BLK_WIDTH)

#define DVS_Y_BIN_MODE_SCALE_FACTOR_4X4  2
#define DVS_L0_VERT_DOWNSAMPLE  2
#define DVS_L1_VERT_DOWNSAMPLE  4
#define DVS_L2_VERT_DOWNSAMPLE  8

#define DVS_L0_MAX_GRD_HEIGHT  16
#define DVS_L1_MAX_GRD_HEIGHT  16
#define DVS_L2_MAX_GRD_HEIGHT  16

#define DVS_PREV_FE_SECTION_NUM    (0)
#define DVS_BEST_FE_SECTION_NUM    (0)
#define DVS_MV_SECTION_NUM         (1)

#define L2_L1_BF_START_ADDRESS_BYTE_OVERLAP \
	(DVS_BF_L2_BASE_ADDRESS - FLOOR_MUL( DVS_BF_L2_BASE_ADDRESS, HIVE_ISP_DDR_WORD_BYTES))
#define L1_BF_INDEX_RESET_BYTES \
	(CEIL_MUL (L2_L1_BF_START_ADDRESS_BYTE_OVERLAP, FE_BYTES_PER_GRID_UNIT) - L2_L1_BF_START_ADDRESS_BYTE_OVERLAP)

#endif /* __DVS_ACC_SHARED_H */

