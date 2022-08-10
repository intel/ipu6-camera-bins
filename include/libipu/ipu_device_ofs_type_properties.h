/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2019 - 2019 Intel Corporation.
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

#ifndef __IPU_DEVICE_OFS_TYPE_PROPERTIES_H
#define __IPU_DEVICE_OFS_TYPE_PROPERTIES_H

#include "storage_class.h"

/* from bboutputformatter_defs.h and HAS OFS */
#define IPU_DEVICE_OFS_OF_SYSTEM_NWAYS        (32)
#define IPU_DEVICE_OFS_OF_REG_ALIGN           (4)
#define IPU_DEVICE_OFS_OF_NR_GENERAL_REGS     (64)
#define IPU_DEVICE_OFS_OF_NR_PIN_REGS         (64)

#define IPU_DEVICE_OFS_OF_MAP_PIN_REG(reg, pin_idx) ((reg) + ((pin_idx) * IPU_DEVICE_OFS_OF_NR_PIN_REGS) + \
						     IPU_DEVICE_OFS_OF_NR_GENERAL_REGS)

/* all general (config and status) registers: */
#define IPU_DEVICE_OFS_OF_CMD                          (0)

#define IPU_DEVICE_OFS_OF_PIN0_DMA_DATA_ACK            (1)
#define IPU_DEVICE_OFS_OF_PIN1_DMA_DATA_ACK            (2)
#define IPU_DEVICE_OFS_OF_PIN2_DMA_DATA_ACK            (3)
#define IPU_DEVICE_OFS_OF_PIN0_DMA_DE_QUEUE_ACK        (4)
#define IPU_DEVICE_OFS_OF_PIN1_DMA_DE_QUEUE_ACK        (5)
#define IPU_DEVICE_OFS_OF_PIN2_DMA_DE_QUEUE_ACK        (6)
#define IPU_DEVICE_OFS_OF_PIN0_STREAM2GEN_READ_PTR     (7)
#define IPU_DEVICE_OFS_OF_PIN2_STREAM2GEN_READ_PTR     (9)

#define IPU_DEVICE_OFS_OF_IRQ                          (16)

/* generIPU_DEVICE_OFSal status register ID's: */
#define IPU_DEVICE_OFS_OF_STAT_RD_STATUS0              (17)
#define IPU_DEVICE_OFS_OF_STAT_RD_STATUS1              (18)
#define IPU_DEVICE_OFS_OF_STAT_UPSAMPLE_STATUS         (19)
#define IPU_DEVICE_OFS_OF_STAT_RANGE_STATUS            (20)
#define IPU_DEVICE_OFS_OF_STAT_PACK_STATUS             (21)
#define IPU_DEVICE_OFS_OF_STAT_WR_STATUS0              (22)
#define IPU_DEVICE_OFS_OF_STAT_WR_STATUS1              (23)
#define IPU_DEVICE_OFS_OF_STAT_ALLOCATED_BUFFERS       (24)
#define IPU_DEVICE_OFS_OF_STAT_MT_STATUS               (25)
#define IPU_DEVICE_OFS_OF_STAT_ACK_GEN_STATUS          (26)

#define IPU_DEVICE_OFS_OF_REG_DESCRIPTOR_RPWC          (32)
#define IPU_DEVICE_OFS_OF_REG_OFA_CONTROL              (33)
#define IPU_DEVICE_OFS_OF_REG_INPUT_BPP                (34)

#define IPU_DEVICE_OFS_OF_REG_UP_P_E_0                 (35)
#define IPU_DEVICE_OFS_OF_REG_UP_P_E_1                 (36)
#define IPU_DEVICE_OFS_OF_REG_UP_P_O_0                 (37)
#define IPU_DEVICE_OFS_OF_REG_UP_P_O_1                 (38)

/* all pin dependent (config and status) registers: */
#define IPU_DEVICE_OFS_OF_REG_FORMAT                      (0)
#define IPU_DEVICE_OFS_OF_REG_VERTICAL_MIRROR             (1)
#define IPU_DEVICE_OFS_OF_REG_HORIZONTAL_MIRROR           (2)
#define IPU_DEVICE_OFS_OF_REG_TILING                      (3)
#define IPU_DEVICE_OFS_OF_REG_REDUCE_RANGE                (4)

#define IPU_DEVICE_OFS_OF_REG_IMAGE_WIDTH_VECTORS         (5)
#define IPU_DEVICE_OFS_OF_REG_IMAGE_HEIGHT_LINES          (6)

#define IPU_DEVICE_OFS_OF_REG_OUTPUT_LUMA_X               (7)
#define IPU_DEVICE_OFS_OF_REG_OUTPUT_LUMA_Y               (8)
#define IPU_DEVICE_OFS_OF_REG_INPUT_LEFT_CROP_PIXEL       (9)
#define IPU_DEVICE_OFS_OF_REG_INPUT_TOP_CROP_PIXEL       (10)

#define IPU_DEVICE_OFS_OF_REG_RELEASE_INPUT_ADDR         (11)
#define IPU_DEVICE_OFS_OF_REG_IN_BUF_REL_TOKEN           (12)

#define IPU_DEVICE_OFS_OF_REG_IN_BUF_NUMBER_OF_BUFFERS   (13)
#define IPU_DEVICE_OFS_OF_REG_IN_BUF_Y_ST_ADDR           (14)
#define IPU_DEVICE_OFS_OF_REG_IN_BUF_Y_BUFFER_STRIDE     (15)
#define IPU_DEVICE_OFS_OF_REG_IN_BUF_Y_LINE_STRIDE       (16)
#define IPU_DEVICE_OFS_OF_REG_IN_BUF_U_ST_ADDR           (17)
#define IPU_DEVICE_OFS_OF_REG_IN_BUF_UV_BUFFER_STRIDE    (18)
#define IPU_DEVICE_OFS_OF_REG_IN_BUF_UV_LINE_STRIDE      (19)
#define IPU_DEVICE_OFS_OF_REG_IN_BUF_V_ST_ADDR           (20)

#define IPU_DEVICE_OFS_OF_REG_PROCESS_OUTPUT_BUF_ADDR    (23)

#define IPU_DEVICE_OFS_OF_REG_OUT_BUF_NUMBER_OF_BUFFERS  (25)
#define IPU_DEVICE_OFS_OF_REG_OUT_BUF_Y_ST_ADDR          (26)
#define IPU_DEVICE_OFS_OF_REG_OUT_BUF_Y_BUFFER_STRIDE    (27)
#define IPU_DEVICE_OFS_OF_REG_OUT_BUF_Y_LINE_STRIDE      (28)
#define IPU_DEVICE_OFS_OF_REG_OUT_BUF_U_ST_ADDR          (29)
#define IPU_DEVICE_OFS_OF_REG_OUT_BUF_UV_BUFFER_STRIDE   (30)
#define IPU_DEVICE_OFS_OF_REG_OUT_BUF_UV_LINE_STRIDE     (31)
#define IPU_DEVICE_OFS_OF_REG_OUT_BUF_V_ST_ADDR          (32)

#define IPU_DEVICE_OFS_OF_REG_HIST_BUF_ST_ADDR           (36)
#define IPU_DEVICE_OFS_OF_REG_HIST_BUF_LINE_STRIDE       (38)

#define IPU_DEVICE_OFS_OF_REG_OUTPUT_Y_ADDR              (39)
#define IPU_DEVICE_OFS_OF_REG_OUTPUT_U_ADDR              (40)
#define IPU_DEVICE_OFS_OF_REG_OUTPUT_V_ADDR              (41)
#define IPU_DEVICE_OFS_OF_REG_OUTPUT_Y_STRIDE            (42)
#define IPU_DEVICE_OFS_OF_REG_OUTPUT_UV_STRIDE           (43)

#define IPU_DEVICE_OFS_OF_REG_UNIT_DESCR_ID              (44)
#define IPU_DEVICE_OFS_OF_REG_CHANNEL_DESCR_ID           (45)
#define IPU_DEVICE_OFS_OF_REG_SPAN_A_DESCR_ID            (46)
#define IPU_DEVICE_OFS_OF_REG_SPAN_B_DESCR_ID            (47)
#define IPU_DEVICE_OFS_OF_REG_TERMINAL_A_DESCR_ID        (48)
#define IPU_DEVICE_OFS_OF_REG_TERMINAL_B_DESCR_ID        (49)
#define IPU_DEVICE_OFS_OF_REG_UNIT_DESCR_ADDRESS         (50)
#define IPU_DEVICE_OFS_OF_REG_UNIT_DESCR_STRIDE          (51)
#define IPU_DEVICE_OFS_OF_REG_TERMINAL_A_DESCR_ADDRESS   (55)
#define IPU_DEVICE_OFS_OF_REG_TERMINAL_B_DESCR_ADDRESS   (56)
#define IPU_DEVICE_OFS_OF_REG_TERMINAL_DESCR_STRIDE      (57)
#define IPU_DEVICE_OFS_OF_REG_DMA_REQ_QUEUE_CNT          (58)
#define IPU_DEVICE_OFS_OF_REG_DONE_ADDRESS               (59)
#define IPU_DEVICE_OFS_OF_REG_DONE_MESSAGE               (60)

#define IPU_DEVICE_OFS_OF_REG_STREAM2GEN_HEAD_PTR        (61)
#define IPU_DEVICE_OFS_OF_REG_STREAM2GEN_BUFFER_SIZE     (62)
#define IPU_DEVICE_OFS_OF_REG_STREAM2GEN_FRAME_INDEX     (63)

/* Legagcy : Needs to be cleaned up */
#define IPU_DEVICE_OFS_OF_CMD_REG_OFFSET (0)/* from outputformatter_defs.h */
#define IPU_DEVICE_OFS_OF_SID_REG_OFFSET (5)/* from outputformatter_defs.h */
#define IPU_DEVICE_OFS_OF_CHR_UPSAMPLE_REG_OFFSET (6) /* from outputformatter_defs.h */
#define IPU_DEVICE_OFS_OF_OUT_NR_BUF_REG_OFFSET (2)
#define IPU_DEVICE_OFS_OF_OUT_BUF_ST_ADDR_REG_OFFSET (3)
#define IPU_DEVICE_OFS_OF_OUT_BUF_STRIDE_REG_OFFSET (4)
#define IPU_DEVICE_OFS_OF_IMAGE_WIDTH_VECS_REG_OFFSET (10)/* from outputformatter_defs.h */
#define IPU_DEVICE_OFS_OF_IMAGE_HEIGHT_LINES_REG_OFFSET (11)

#define IPU_DEVICE_OFS_OF_IN_BUF_Y_ST_ADDR_REG_OFFSET          (12)
#define IPU_DEVICE_OFS_OF_IN_BUF_Y_LINE_STRIDE_REG_OFFSET      (13)
#define IPU_DEVICE_OFS_OF_IN_BUF_Y_BUFFER_STRIDE_REG_OFFSET    (14)
#define IPU_DEVICE_OFS_OF_IN_BUF_U_ST_ADDR_REG_OFFSET          (15)
#define IPU_DEVICE_OFS_OF_IN_BUF_V_ST_ADDR_REG_OFFSET          (16)
#define IPU_DEVICE_OFS_OF_IN_BUF_UV_LINE_STRIDE_REG_OFFSET     (17)
#define IPU_DEVICE_OFS_OF_IN_BUF_UV_BUFFER_STRIDE_REG_OFFSET   (18)

#define IPU_DEVICE_OFS_OF_OUT_BUF_LEVEL_REG_OFFSET             (19)
#define IPU_DEVICE_OFS_OF_OUT_BUF_NR_Y_LINES_REG_OFFSET        (20)
#define IPU_DEVICE_OFS_OF_OUT_BUF_U_ST_OFFSET_REG_OFFSET       (21)
#define IPU_DEVICE_OFS_OF_OUT_BUF_V_ST_OFFSET_REG_OFFSET       (22)
#define IPU_DEVICE_OFS_OF_OUT_BUF_Y_LINE_STRIDE_REG_OFFSET     (23)
#define IPU_DEVICE_OFS_OF_OUT_BUF_UV_LINE_STRIDE_REG_OFFSET    (24)
#define IPU_DEVICE_OFS_OF_HIST_BUF_ST_ADDR_REG_OFFSET          (25)
#define IPU_DEVICE_OFS_OF_HIST_BUF_LINE_STRIDE_REG_OFFSET      (26)
#define IPU_DEVICE_OFS_OF_HIST_BUF_NR_LINES (27)/* from outputformatter_defs.h */
#define IPU_DEVICE_OFS_OF_PID_REG_OFFSET (9)/* from outputformatter_defs.h */
#define IPU_DEVICE_OFS_OF_NR_OUTPUT_IDX_REGS (64)/* from outputformatter_defs.h */
#define IPU_DEVICE_OFS_OF_REG_REL_INP_ADDR_REG_OFFSET (6)/* from outputformatter_defs.h */
#define IPU_DEVICE_OFS_OF_REG_REL_INP_EN_REG_OFFSET (7)/* from outputformatter_defs.h */
#define IPU_DEVICE_OFS_OF_REG_PROC_OUT_ADDR_REG_OFFSET (8)/* from outputformatter_defs.h */
/* legacy finished */

#define IPU_DEVICE_OFS_SC_SNR_PRESERVE_BITS (3)
#define IPU_DEVICE_OFS_SC_REG_ALIGN (4)/* from polyphase_scaler_defs.h */
#define IPU_DEVICE_OFS_SC_CMD_REG_OFFSET (0)/* from polyphase_scaler_defs.h */
#define IPU_DEVICE_OFS_SC_NR_GENERAL_REGS (16)/* from polyphase_scaler_defs.h */
#define IPU_DEVICE_OFS_SC_SID_REG_OFFSET (58)/* from polyphase_scaler_defs.h */
#define IPU_DEVICE_OFS_SC_PID_REG_OFFSET (59)/* from polyphase_scaler_defs.h */
#define IPU_DEVICE_OFS_SC_REL_INP_ADDR_REG_OFFSET (31)/* from polyphase_scaler_defs.h */
#define IPU_DEVICE_OFS_SC_REL_INP_EN_REG_OFFSET (32)/* from polyphase_scaler_defs.h */
#define IPU_DEVICE_OFS_SC_REL_OUT_EN_REG_OFFSET (33)/* from polyphase_scaler_defs.h */
#define IPU_DEVICE_OFS_SC_PROC_OUT_ADDR_REG_OFFSET (34)/* from polyphase_scaler_defs.h */
/* input buffer registers */
#define IPU_DEVICE_OFS_SC_INP_BUF_Y_ST_ADDR_REG_OFFSET            (0)
#define IPU_DEVICE_OFS_SC_INP_BUF_Y_LINE_STRIDE_REG_OFFSET        (1)
#define IPU_DEVICE_OFS_SC_INP_BUF_Y_BUFFER_STRIDE_REG_OFFSET      (2)
#define IPU_DEVICE_OFS_SC_INP_BUF_U_ST_ADDR_REG_OFFSET            (3)
#define IPU_DEVICE_OFS_SC_INP_BUF_V_ST_ADDR_REG_OFFSET            (4)
#define IPU_DEVICE_OFS_SC_INP_BUF_UV_LINE_STRIDE_REG_OFFSET       (5)
#define IPU_DEVICE_OFS_SC_INP_BUF_UV_BUFFER_STRIDE_REG_OFFSET     (6)
#define IPU_DEVICE_OFS_SC_INP_BUF_CHUNK_WIDTH_REG_OFFSET          (7)
#define IPU_DEVICE_OFS_SC_INP_BUF_NR_BUFFERS_REG_OFFSET           (8)
/* output buffer registers */
#define IPU_DEVICE_OFS_SC_OUT_BUF_Y_ST_ADDR_REG_OFFSET            (9)
#define IPU_DEVICE_OFS_SC_OUT_BUF_Y_LINE_STRIDE_REG_OFFSET        (10)
#define IPU_DEVICE_OFS_SC_OUT_BUF_Y_BUFFER_STRIDE_REG_OFFSET      (11)
#define IPU_DEVICE_OFS_SC_OUT_BUF_U_ST_ADDR_REG_OFFSET            (12)
#define IPU_DEVICE_OFS_SC_OUT_BUF_V_ST_ADDR_REG_OFFSET            (13)
#define IPU_DEVICE_OFS_SC_OUT_BUF_UV_LINE_STRIDE_REG_OFFSET       (14)
#define IPU_DEVICE_OFS_SC_OUT_BUF_UV_BUFFER_STRIDE_REG_OFFSET     (15)
#define IPU_DEVICE_OFS_SC_OUT_BUF_NR_BUFFERS_REG_OFFSET           (16)
/* intermediate buffer registers */
#define IPU_DEVICE_OFS_SC_INT_BUF_Y_ST_ADDR_REG_OFFSET            (17)
#define IPU_DEVICE_OFS_SC_INT_BUF_Y_LINE_STRIDE_REG_OFFSET        (18)
#define IPU_DEVICE_OFS_SC_INT_BUF_U_ST_ADDR_REG_OFFSET            (19)
#define IPU_DEVICE_OFS_SC_INT_BUF_V_ST_ADDR_REG_OFFSET            (20)
#define IPU_DEVICE_OFS_SC_INT_BUF_UV_LINE_STRIDE_REG_OFFSET       (21)
#define IPU_DEVICE_OFS_SC_INT_BUF_HEIGHT_REG_OFFSET               (22)
#define IPU_DEVICE_OFS_SC_INT_BUF_CHUNK_WIDTH_REG_OFFSET          (23)
#define IPU_DEVICE_OFS_SC_INT_BUF_CHUNK_HEIGHT_REG_OFFSET         (24)
/* context buffer registers */
#define IPU_DEVICE_OFS_SC_CTX_BUF_HOR_Y_ST_ADDR_REG_OFFSET        (25)
#define IPU_DEVICE_OFS_SC_CTX_BUF_HOR_U_ST_ADDR_REG_OFFSET        (26)
#define IPU_DEVICE_OFS_SC_CTX_BUF_HOR_V_ST_ADDR_REG_OFFSET        (27)
#define IPU_DEVICE_OFS_SC_CTX_BUF_VER_Y_ST_ADDR_REG_OFFSET        (28)
#define IPU_DEVICE_OFS_SC_CTX_BUF_VER_U_ST_ADDR_REG_OFFSET        (29)
#define IPU_DEVICE_OFS_SC_CTX_BUF_VER_V_ST_ADDR_REG_OFFSET        (30)
#define IPU_DEVICE_OFS_SC_INPUT_IMAGE_Y_WIDTH_REG_OFFSET (35)/* from polyphase_scaler_defs.h */
#define IPU_DEVICE_OFS_SC_OUTPUT_PROCESSING_MODE_REG_OFFSET       (47)
#define IPU_DEVICE_OFS_SC_OUTPUT_SCALING_RATIO_REG_OFFSET         (48)
#define IPU_DEVICE_OFS_SC_COEFFS_LUT_OFFSET (128)/* from polyphase_scaler_defs.h */

/* formats and value */
#define IPU_DEVICE_OFS_NR_420_FORMATS      (9)
#define IPU_DEVICE_OFS_NR_422_FORMATS      (3)
#define IPU_DEVICE_OFS_NR_FORMATS          (IPU_DEVICE_OFS_NR_420_FORMATS + IPU_DEVICE_OFS_NR_422_FORMATS + IPU_DEVICE_OFS_NR_444_FORMATS)

#define IPU_DEVICE_OFS_FORMAT_I420         (0)
#define IPU_DEVICE_OFS_FORMAT_YV12         (1)
#define IPU_DEVICE_OFS_FORMAT_NV12         (2)
#define IPU_DEVICE_OFS_FORMAT_NV21         (3)
#define IPU_DEVICE_OFS_FORMAT_M420         (4)
#define IPU_DEVICE_OFS_FORMAT_YUY2         (5)
#define IPU_DEVICE_OFS_FORMAT_YUYV         (5)
#define IPU_DEVICE_OFS_FORMAT_NV16         (6)
#define IPU_DEVICE_OFS_FORMAT_NV61         (7)
#define IPU_DEVICE_OFS_FORMAT_P010_MSB     (8)
#define IPU_DEVICE_OFS_FORMAT_P010_LSB     (9)
#define IPU_DEVICE_OFS_FORMAT_P016_MSB     (10)
#define IPU_DEVICE_OFS_FORMAT_P016_LSB     (11)

/* tiling support values */
#define IPU_DEVICE_OFS_NO_TILING           (0)
#define IPU_DEVICE_OFS_Y_TILING            (1)
#define IPU_DEVICE_OFS_YF_TILING           (2)

/* max supported scaling output width */
#define IPU_DEVICE_OFS_SC_MAX_WIDTH(sc_id) ((sc_id == 0) ? 4096 : 1920)

/*********************  COMMAND PROTOCOL  *********************************/
/****************************************************************************************************************************************************************************************************
    protocol definition
     _______________________________________________________________________________________________________________________________________________________________________________________________
    |  31 |  30 |  29 |  28 |  27 |  26 |  25 |  24 |  23 |  22 |  21 |  20 |  19 |  18 |  17 |  16 |  15 |  14 |  13 |  12 |  11 |  10 |  9  |  8  |  7  |  6  |  5  |  4  |  3  |  2  |  1  |  0  |
    |-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|
    |                SID                |                PID                |       BUFFER ID       |                 HEIGHT                  |                  WIDTH                  |    CMD    |
    |___________________________________|___________________________________|_______________________|_________________________________________|_________________________________________|___________|

*****************************************************************************************************************************************************************************************************/

/* Mask of ones at 'nr_bits' LSBs of an unsigned variable - supported up to 63 bit tokens */
#define IPU_DEVICE_OFS_ONES_MASK(nr_bits)                   ((unsigned)(((unsigned long long)1 << (nr_bits)) - 1))

/* CMD field description */
#define IPU_DEVICE_OFS_CMD_CMD_IDX                          (0)
#define IPU_DEVICE_OFS_CMD_CMD_BITS                         (2)
#define IPU_DEVICE_OFS_CMD_CMD_MASK                         ((1 << (IPU_DEVICE_OFS_CMD_CMD_IDX + IPU_DEVICE_OFS_CMD_CMD_BITS)) - 1)

/* WIDTH field description */
#define IPU_DEVICE_OFS_CMD_WIDTH_IDX                        (IPU_DEVICE_OFS_CMD_CMD_IDX + IPU_DEVICE_OFS_CMD_CMD_BITS)
#define IPU_DEVICE_OFS_CMD_WIDTH_BITS                       (7)
#define IPU_DEVICE_OFS_CMD_WIDTH_MASK                       (IPU_DEVICE_OFS_ONES_MASK(IPU_DEVICE_OFS_CMD_WIDTH_IDX + IPU_DEVICE_OFS_CMD_WIDTH_BITS) ^ IPU_DEVICE_OFS_ONES_MASK(IPU_DEVICE_OFS_CMD_WIDTH_IDX))

/* HEIGHT field description */
#define IPU_DEVICE_OFS_CMD_HEIGHT_IDX                       (IPU_DEVICE_OFS_CMD_WIDTH_IDX + IPU_DEVICE_OFS_CMD_WIDTH_BITS)
#define IPU_DEVICE_OFS_CMD_HEIGHT_BITS                      (7)
#define IPU_DEVICE_OFS_CMD_HEIGHT_MASK                      (IPU_DEVICE_OFS_ONES_MASK(IPU_DEVICE_OFS_CMD_HEIGHT_IDX + IPU_DEVICE_OFS_CMD_HEIGHT_BITS) ^ IPU_DEVICE_OFS_ONES_MASK(IPU_DEVICE_OFS_CMD_HEIGHT_IDX))

/* BUFFER ID field description */
#define IPU_DEVICE_OFS_CMD_BUFFER_IDX                       (IPU_DEVICE_OFS_CMD_HEIGHT_IDX + IPU_DEVICE_OFS_CMD_HEIGHT_BITS)
#define IPU_DEVICE_OFS_CMD_BUFFER_BITS                      (4)
#define IPU_DEVICE_OFS_CMD_BUFFER_MASK                      (IPU_DEVICE_OFS_ONES_MASK(IPU_DEVICE_OFS_CMD_BUFFER_IDX + IPU_DEVICE_OFS_CMD_BUFFER_BITS) ^ IPU_DEVICE_OFS_ONES_MASK(IPU_DEVICE_OFS_CMD_BUFFER_IDX))

/* PIN ID field description */
#define IPU_DEVICE_OFS_CMD_PIN_IDX                          (IPU_DEVICE_OFS_CMD_BUFFER_IDX + IPU_DEVICE_OFS_CMD_BUFFER_BITS)
#define IPU_DEVICE_OFS_CMD_PIN_BITS                         (0)
#define IPU_DEVICE_OFS_CMD_PIN_MASK                         (IPU_DEVICE_OFS_ONES_MASK(IPU_DEVICE_OFS_CMD_PIN_IDX + IPU_DEVICE_OFS_CMD_PIN_BITS) ^ IPU_DEVICE_OFS_ONES_MASK(IPU_DEVICE_OFS_CMD_PIN_IDX))

/* PID field description */
#define IPU_DEVICE_OFS_CMD_PID_IDX                          (IPU_DEVICE_OFS_CMD_BUFFER_IDX + IPU_DEVICE_OFS_CMD_BUFFER_BITS)
#define IPU_DEVICE_OFS_CMD_PID_BITS                         (6)
#define IPU_DEVICE_OFS_CMD_PID_MASK                         (IPU_DEVICE_OFS_ONES_MASK(IPU_DEVICE_OFS_CMD_PID_IDX + IPU_DEVICE_OFS_CMD_PID_BITS) ^ IPU_DEVICE_OFS_ONES_MASK(IPU_DEVICE_OFS_CMD_PID_IDX))

/* SID field description */
#define IPU_DEVICE_OFS_CMD_SID_IDX                          (IPU_DEVICE_OFS_CMD_PID_IDX + IPU_DEVICE_OFS_CMD_PID_BITS)
#define IPU_DEVICE_OFS_CMD_SID_BITS                         (6)
#define IPU_DEVICE_OFS_CMD_SID_MASK                         (IPU_DEVICE_OFS_ONES_MASK(IPU_DEVICE_OFS_CMD_SID_IDX + IPU_DEVICE_OFS_CMD_SID_BITS) ^ IPU_DEVICE_OFS_ONES_MASK(IPU_DEVICE_OFS_CMD_SID_IDX))

/* RESERVED field description */
#define IPU_DEVICE_OFS_CMD_RESERVED_IDX                     (IPU_DEVICE_OFS_CMD_SID_IDX + IPU_DEVICE_OFS_CMD_SID_BITS)
#define IPU_DEVICE_OFS_CMD_RESERVED_BITS                    (0)

/* Total bits in a protocol token */
#define IPU_DEVICE_OFS_CMD_BITS                             (IPU_DEVICE_OFS_CMD_RESERVED_IDX + IPU_DEVICE_OFS_CMD_RESERVED_BITS)

/* Number of elements per word */
#define IPU_DEVICE_OFS_PROTOCOL_DATA_WIDTH                  (32)

#define IPU_DEVICE_OFS_SC_PROCESS_CMD       (0)
#define IPU_DEVICE_OFS_SC_INIT_CMD          (1)
#define IPU_DEVICE_OFS_SC_PROCESS_BELOW_CMD (2)
#define IPU_DEVICE_OFS_OF_INIT_CMD          (1)
#define IPU_DEVICE_OFS_OF_PROCESS_CMD       (0)
#define IPU_DEVICE_OFS_OF_PROCESS_BELOW_CMD (2)

STORAGE_CLASS_INLINE uint32_t
ipu_device_ofs_cmd_pack(uint32_t sid,
			uint32_t pid,
			uint32_t buf_id,
			uint32_t height,
			uint32_t width,
			uint32_t cmd)
{
	return (IPU_DEVICE_OFS_CMD_SID_MASK & (sid << IPU_DEVICE_OFS_CMD_SID_IDX)) |
		(IPU_DEVICE_OFS_CMD_PID_MASK & (pid << IPU_DEVICE_OFS_CMD_PID_IDX)) |
		(IPU_DEVICE_OFS_CMD_BUFFER_MASK & (buf_id << IPU_DEVICE_OFS_CMD_BUFFER_IDX)) |
		(IPU_DEVICE_OFS_CMD_HEIGHT_MASK & (height << IPU_DEVICE_OFS_CMD_HEIGHT_IDX)) |
		(IPU_DEVICE_OFS_CMD_WIDTH_MASK & (width << IPU_DEVICE_OFS_CMD_WIDTH_IDX)) |
		(IPU_DEVICE_OFS_CMD_CMD_MASK & (cmd << IPU_DEVICE_OFS_CMD_CMD_IDX));
}

/**************************************
 * OFS TOKEN UNPACK HELPER FUNCTIONS
 **************************************/

/**
 * Extract the command field from a process-buffer token.
 */
STORAGE_CLASS_INLINE int ipu_device_ofs_get_command_from_ofs_token(int token)
{
	return ((token >> IPU_DEVICE_OFS_CMD_CMD_IDX) & ((1 << IPU_DEVICE_OFS_CMD_CMD_BITS) - 1));
}

/**
 * Extract the buffer ID field from a process-buffer token.
 */
STORAGE_CLASS_INLINE int ipu_device_ofs_get_buf_id_from_ofs_token(int token)
{
	return ((token >> IPU_DEVICE_OFS_CMD_BUFFER_IDX) & ((1 << IPU_DEVICE_OFS_CMD_BUFFER_BITS) - 1));
}

/**
 * Extract the output pin ID field from a process-buffer token.
 */
STORAGE_CLASS_INLINE int ipu_device_ofs_get_pid_from_ofs_token(int token)
{
	return ((token >> IPU_DEVICE_OFS_CMD_PID_IDX) &
			((1 << IPU_DEVICE_OFS_CMD_PID_BITS) - 1));
}

/**
 * Extract the block width field from a process-buffer token.
 */
STORAGE_CLASS_INLINE int ipu_device_ofs_get_width_from_ofs_token(int token)
{
	return ((token >> IPU_DEVICE_OFS_CMD_WIDTH_IDX) & ((1 << IPU_DEVICE_OFS_CMD_WIDTH_BITS) - 1));
}

/**
 * Extract the block height field from a process-buffer token.
 */
STORAGE_CLASS_INLINE int ipu_device_ofs_get_height_from_ofs_token(int token)
{
	return ((token >> IPU_DEVICE_OFS_CMD_HEIGHT_IDX) & ((1 << IPU_DEVICE_OFS_CMD_HEIGHT_BITS) - 1));
}

#endif /* __IPU_DEVICE_OFS_TYPE_PROPERTIES_H */
