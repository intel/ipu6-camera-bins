
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

#ifndef __ISA_LB_TERMINAL_IDS_H
#define __ISA_LB_TERMINAL_IDS_H

/* TERMINAL ids */
enum ISA_LB_TERMINAL_ID {
	ISA_LB_TERMINAL_ID_CACHED_PARAMETER_IN = 0,
	ISA_LB_TERMINAL_ID_PROGRAM_INIT,
	ISA_LB_TERMINAL_ID_PROGRAM_CONTROL_INIT,
	ISA_LB_TERMINAL_ID_GET_HIGH,
	ISA_LB_TERMINAL_ID_BLC_GRID,
	ISA_LB_TERMINAL_ID_LSC_GRID,
	ISA_LB_TERMINAL_ID_GAMMASTAR_GRID,
	ISA_LB_TERMINAL_ID_PUT,
	ISA_LB_TERMINAL_ID_PUT_BAYER,
#if HAS_FF_R2I_DS_B
	ISA_LB_TERMINAL_ID_PUT_YUV_B,
#endif
	ISA_LB_TERMINAL_ID_PUT_SIS_A,
	ISA_LB_TERMINAL_ID_PUT_SIS_B,
	ISA_LB_TERMINAL_ID_PUT_VIDEO_FULL,
	ISA_LB_TERMINAL_ID_PUT_IR_DEPTH,
	ISA_LB_TERMINAL_ID_SPT_3A_STAT_AF,
	ISA_LB_TERMINAL_ID_SPT_3A_STAT_AWB,
	ISA_LB_TERMINAL_ID_SPT_PAF,
	ISA_LB_TERMINAL_ID_SPT_DVS_MV_OUT_L0,
	ISA_LB_TERMINAL_ID_SPT_DVS_MV_OUT_L1,
	ISA_LB_TERMINAL_ID_SPT_DVS_MV_OUT_L2,
	ISA_LB_TERMINAL_ID_CACHED_PARAMETER_OUT_AE_STAT,
	ISA_LB_TERMINAL_ID_DVS_FE_IN_L0,
	ISA_LB_TERMINAL_ID_DVS_FE_IN_L1,
	ISA_LB_TERMINAL_ID_DVS_FE_IN_L2,
	ISA_LB_TERMINAL_ID_DVS_FE_OUT_L0,
	ISA_LB_TERMINAL_ID_DVS_FE_OUT_L1,
	ISA_LB_TERMINAL_ID_DVS_FE_OUT_L2,
#if HAS_FF_DOL_DOL
	ISA_LB_TERMINAL_ID_GET_SHORT,
	ISA_LB_TERMINAL_ID_GET_MEDIUM,
#endif
	ISA_LB_TERMINAL_ID_GET_PAF,
	ISA_LB_TERMINAL_ID_N
};

#endif /* __ISA_LB_TERMINAL_IDS_H */
