
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

#ifndef __ISL_PS_RBM_TERMINAL_IDS_H
#define __ISL_PS_RBM_TERMINAL_IDS_H

/* TERMINAL ids */
enum ISL_PS_RBM_TERMINAL_ID {
	ISL_PS_RBM_TERMINAL_ID_CACHED_PARAMETER_IN = 0,
	ISL_PS_RBM_TERMINAL_ID_PROGRAM_INIT,
	ISL_PS_RBM_TERMINAL_ID_PROGRAM_CONTROL_INIT,
	ISL_PS_RBM_TERMINAL_ID_GET_HIGH,
	ISL_PS_RBM_TERMINAL_ID_BLC_GRID,
	ISL_PS_RBM_TERMINAL_ID_LSC_GRID,
	ISL_PS_RBM_TERMINAL_ID_PUT_BAYER,
	ISL_PS_RBM_TERMINAL_ID_PUT_YUV_A,
#if HAS_FF_R2I_DS_B
	ISL_PS_RBM_TERMINAL_ID_PUT_YUV_B,
#endif
	ISL_PS_RBM_TERMINAL_ID_PUT_VIDEO_FULL,
	ISL_PS_RBM_TERMINAL_ID_PUT_IR_DEPTH,
	ISL_PS_RBM_TERMINAL_ID_PUT_SIS_A,
	ISL_PS_RBM_TERMINAL_ID_PUT_SIS_B,
	ISL_PS_RBM_TERMINAL_ID_SPT_3A_STAT_AF,
	ISL_PS_RBM_TERMINAL_ID_SPT_3A_STAT_AWB,
	ISL_PS_RBM_TERMINAL_ID_SPT_PAF,
	ISL_PS_RBM_TERMINAL_ID_CACHED_PARAMETER_OUT_AE_STAT,
#if HAS_FF_DOL_DOL
	ISL_PS_RBM_TERMINAL_ID_GET_SHORT,
	ISL_PS_RBM_TERMINAL_ID_GET_MEDIUM,
#endif
	ISL_PS_RBM_TERMINAL_ID_GET_PAF,
	ISL_PS_RBM_TERMINAL_ID_N
};

#endif /* __ISL_PS_RBM_TERMINAL_IDS_H */
