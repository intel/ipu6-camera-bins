/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2017 - 2020 Intel Corporation.
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

#ifndef __PG_LB_PROGRAM_IDS_H
#define __PG_LB_PROGRAM_IDS_H

enum PG_LB_PROGRAM_ID {
	PG_LB_PROGRAM_ID_PSA_IN_DMA_V2S,
	PG_LB_PROGRAM_ID_ACC_RYNR,
	PG_LB_PROGRAM_ID_ACC_DM,
	PG_LB_PROGRAM_ID_ACC_VCSC,
	PG_LB_PROGRAM_ID_ACC_ACM,
	PG_LB_PROGRAM_ID_ACC_GTC,
	PG_LB_PROGRAM_ID_ACC_YUV1,
	PG_LB_PROGRAM_ID_ACC_GAMMASTAR_PASSTHROUGH,
	PG_LB_PROGRAM_ID_ACC_GAMMASTAR,
	PG_LB_PROGRAM_ID_ACC_DVS_L0,
	PG_LB_PROGRAM_ID_ACC_DVS_L0_DISABLED,
	PG_LB_PROGRAM_ID_ACC_DVS_L1,
	PG_LB_PROGRAM_ID_ACC_DVS_L1_DISABLED,
	PG_LB_PROGRAM_ID_ACC_DVS_L2,
	PG_LB_PROGRAM_ID_ACC_DVS_L2_DISABLED,
	PG_LB_PROGRAM_ID_ACC_GLTM,
	PG_LB_PROGRAM_ID_ACC_XNR,
	PG_LB_PROGRAM_ID_PSA_OUT_S2V_DMA_VERT_PADD,
	PG_LB_PROGRAM_ID_PSA_OUT_S2V_DMA,
	PG_LB_PROGRAM_ID_N
};

#endif /* __PG_LB_PROGRAM_IDS_H */
