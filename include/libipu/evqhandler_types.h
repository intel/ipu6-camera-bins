/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2014 - 2018 Intel Corporation.
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

#ifndef __EVQHANDLER_SHARED_H
#define __EVQHANDLER_SHARED_H

#define EVENT_QUEUE_MSG_MASK 0xF
#define IPF_MSG_NEXT 0
#define IPF_MSG_DONE 1
#define ACB_ACK_MASK	(1<<19)
#define S2V_CMD_ACK_MASK	(1<<19)
#define S2V_ISL_CMD_ACK_MASK	(1)
#define EQ_IPF_SID 0x1
#define EQ_S2V_SID 0x4
#define EQ_DMA_SID 0x5
#define EQ_GDC0_SID 0x6
#define EQ_GDC1_SID 0x7
#define EQ_OFS_SID 0x8
#define EQ_STR2MMIO_SID 0x9

#define EVQ_NUM_SID 10

#define EQ_S2V_PID 0x23
#define DMA_INPUT_PID 0x4
#define DMA_OUTPUT_PID 0x5
#define EQ_IPF_MSG_NEXT 0
#define EQ_IPF_MSG_DONE 1

#define EQ_OFS_MSG_NEXT 0x4
#define EQ_OFS_MSG_DONE 0x5

#define EVQ_NUM_PID 6

#define BUFFER_IDLE 0

#define EQ_UNUSED_SID 0xE

#define EVQ_STR2MMIO_MSG_MASK		0xFF
#define EVQ_STR2MMIO_MSG_INIT_ACK	0x0

/* The message in ACK token sent back after req command
is processed by device proxy */
#define EQ_MSG_NEXT 0xA
/* The message in ACK token sent back after done command
is processed by device proxy */
#define EQ_MSG_DONE 0xB

/* TODO - get these address using DPI function */
#define PSA_EQC_SPP0_EVQ_ADDR       (IPU_DEVICE_EQ_SPP_0_ADDRESS + IPU_DEVICE_LBPS_TO_CIO_BUS_ADDR)

#ifndef CUSTOM_EVQ_PID_LIST
typedef enum evq_pid {
	EVQ_PID_IPF0,
	EVQ_PID_IPF1,
	EVQ_PID_IPF2,
	EVQ_PID_IPF3,
	EVQ_PID_IPF4,
	EVQ_PID_IPF5,
	EVQ_PID_V2S0,
	EVQ_PID_V2S1,
	EVQ_PID_S2V0,
	EVQ_PID_S2V1,
	EVQ_PID_S2V2,
	EVQ_PID_S2V3,
	EVQ_PID_S2V4,
	EVQ_PID_S2V5,
	EVQ_PID_ISL_S2V0,
	EVQ_PID_ISL_S2V1,
	EVQ_PID_GDC_Y,
	EVQ_PID_GDC_U,
	EVQ_PID_GDC_V,
	EVQ_PID_GDC_NS,
	EVQ_PID_OFS_NEXT,
	EVQ_PID_OFS_DONE,
	EVQ_PID_ISA_INIT,
	EVQ_PID_ISA_NEXT,
	EVQ_PID_ISA_DONE,
	EVQ_PID_WBA_BC_NEXT,
	EVQ_PID_WBA_BC_DONE,
	EVQ_PID_ANR_NEXT,
	EVQ_PID_ANR_DONE,
	EVQ_PID_DM_NEXT,
	EVQ_PID_DM_DONE,
	EVQ_PID_BD_CCM_NEXT,
	EVQ_PID_BD_CCM_DONE,
	EVQ_PID_GTC_NEXT,
	EVQ_PID_GTC_DONE,
	EVQ_PID_YUV_NEXT,
	EVQ_PID_YUV_DONE,
	EVQ_PID_DVS_NEXT,
	EVQ_PID_DVS_DONE,
	EVQ_PID_RYNR_NEXT,
	EVQ_PID_RYNR_DONE,
	EVQ_PID_ACM_NEXT,
	EVQ_PID_ACM_DONE,
	EVQ_PID_GAMMASTAR_NEXT,
	EVQ_PID_GAMMASTAR_DONE,
	EVQ_PID_GLTM_NEXT,
	EVQ_PID_GLTM_DONE,
	EVQ_PID_XNR_NEXT,
	EVQ_PID_XNR_DONE,
	EVQ_PID_VCSC_NEXT,
	EVQ_PID_VCSC_DONE,
	EVQ_PID_STR2MMIO0,
	EVQ_PID_DFM_NEXT,
#ifdef IPU5_LCA_WORKAROUND
	EVQ_PID_LCA,
#endif
	EVQ_PID_INVALID,
	EVQ_PID_NUM
} evq_pid_t;
#endif /* CUSTOM_EVQ_PID_LIST */

#endif
