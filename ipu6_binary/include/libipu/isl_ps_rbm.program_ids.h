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

#ifndef ISL_PS_RBM_PROGRAMS_H_
#define ISL_PS_RBM_PROGRAMS_H_

enum ISL_PS_RBM_PROGRAM_ID {
	ISL_PS_RBM_PROGRAM_ID_ISL_PS_IN_PAF,
#if HAS_FF_DOL_DOL
	ISL_PS_RBM_PROGRAM_ID_ISL_PS_IN_DOL_3_INPUTS,
	ISL_PS_RBM_PROGRAM_ID_ISL_PS_IN_DOL_2_INPUTS,
#endif
	ISL_PS_RBM_PROGRAM_ID_ISL_PS_IN,
	ISL_PS_RBM_PROGRAM_ID_ACC_AWB_STAT,
	ISL_PS_RBM_PROGRAM_ID_ACC_AF_STAT,
	ISL_PS_RBM_PROGRAM_ID_ACC_AE_STAT,
	ISL_PS_RBM_PROGRAM_ID_ACC_B2B,
	ISL_PS_RBM_PROGRAM_ID_ACC_SIS_A,
	ISL_PS_RBM_PROGRAM_ID_ACC_SIS_B,
	ISL_PS_RBM_PROGRAM_ID_ACC_GDDPC_PEXT,
	ISL_PS_RBM_PROGRAM_ID_ACC_ICA,
	ISL_PS_RBM_PROGRAM_ID_ACC_LSC,
	ISL_PS_RBM_PROGRAM_ID_ACC_B2R,
	ISL_PS_RBM_PROGRAM_ID_ACC_R2I_SIE,
	ISL_PS_RBM_PROGRAM_ID_ACC_R2I_DS_A,
#if HAS_FF_R2I_DS_B
	ISL_PS_RBM_PROGRAM_ID_ACC_R2I_DS_B,
#endif
#if HAS_FF_DOL_DOL
	ISL_PS_RBM_PROGRAM_ID_ACC_DOL,
	ISL_PS_RBM_PROGRAM_ID_ACC_ICA_SHORT,
#endif
	ISL_PS_RBM_PROGRAM_ID_ACC_X2B_MD,
	ISL_PS_RBM_PROGRAM_ID_ACC_X2B_SVE_RGBIR,
	ISL_PS_RBM_PROGRAM_ID_ACC_PAF,
#if HAS_FF_DOL_DOL
	ISL_PS_RBM_PROGRAM_ID_ACC_ICA_MEDIUM,
#endif
	ISL_PS_RBM_PROGRAM_ID_ISL_PS_OUT_STILL_ORIG_RES,
	ISL_PS_RBM_PROGRAM_ID_ISL_PS_OUT_VIDEO_SCALED_RES_A,
#if HAS_FF_R2I_DS_B
	ISL_PS_RBM_PROGRAM_ID_ISL_PS_OUT_VIDEO_SCALED_RES_B,
#endif
	ISL_PS_RBM_PROGRAM_ID_ISL_PS_OUT_SIS_SCALED_A,
	ISL_PS_RBM_PROGRAM_ID_ISL_PS_OUT_SIS_SCALED_B,
	ISL_PS_RBM_PROGRAM_ID_ISL_PS_OUT_VIDEO_FULL_RES,
	ISL_PS_RBM_PROGRAM_ID_ISL_PS_OUT_IR_DEPTH,
	ISL_PS_RBM_PROGRAM_ID_ACC_LSC_SPT,
	ISL_PS_RBM_PROGRAM_ID_ACC_BLC_SPT,
	ISL_PS_RBM_PROGRAM_ID_N
};
#endif /* ISL_PS_RBM_PROGRAMS_H_ */
