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

#ifndef _ISA_LB_MANIFEST_GENERATED_H_
#define _ISA_LB_MANIFEST_GENERATED_H_

enum ISA_LB_PROGRAM_ID {
	ISA_LB_PROGRAM_ID_ISA_LB_IN_PAF,
#if HAS_FF_DOL_DOL
	ISA_LB_PROGRAM_ID_ISA_LB_IN_DOL_3_INPUTS,
	ISA_LB_PROGRAM_ID_ISA_LB_IN_DOL_2_INPUTS,
#endif
	ISA_LB_PROGRAM_ID_ISA_LB_IN,
	ISA_LB_PROGRAM_ID_ACC_AWB_STAT,
	ISA_LB_PROGRAM_ID_ACC_AF_STAT,
	ISA_LB_PROGRAM_ID_ACC_AE_STAT,
	ISA_LB_PROGRAM_ID_ACC_B2B,
	ISA_LB_PROGRAM_ID_ISL_OUT_STILL_DIRECT_TO_PSA,
	ISA_LB_PROGRAM_ID_ACC_SIS_A,
	ISA_LB_PROGRAM_ID_ACC_SIS_B,
	ISA_LB_PROGRAM_ID_ACC_GDDPC_PEXT,
	ISA_LB_PROGRAM_ID_ACC_ICA,
	ISA_LB_PROGRAM_ID_ACC_LSC,
	ISA_LB_PROGRAM_ID_ACC_B2R,
	ISA_LB_PROGRAM_ID_ACC_R2I_SIE,
	ISA_LB_PROGRAM_ID_ACC_R2I_DS_A,
	ISA_LB_PROGRAM_ID_ISA_SCALED_OUT_TO_PSA_IN_VMEM,
#if HAS_FF_R2I_DS_B
	ISA_LB_PROGRAM_ID_ACC_R2I_DS_B,
#endif
#if HAS_FF_DOL_DOL
	ISA_LB_PROGRAM_ID_ACC_DOL,
	ISA_LB_PROGRAM_ID_ACC_ICA_SHORT,
#endif
	ISA_LB_PROGRAM_ID_ACC_X2B_MD,
#if HAS_FF_DOL_DOL
	ISA_LB_PROGRAM_ID_ACC_ICA_MEDIUM,
#endif
	ISA_LB_PROGRAM_ID_ACC_X2B_SVE_RGBIR,
	ISA_LB_PROGRAM_ID_ACC_PAF,
	ISA_LB_PROGRAM_ID_PSA_OUT_S2V_DMA_VERT_PADD,
	ISA_LB_PROGRAM_ID_PSA_OUT_S2V_DMA,
	ISA_LB_PROGRAM_ID_ISL_PS_OUT_STILL_ORIG_RES,
#if HAS_FF_R2I_DS_B
	ISA_LB_PROGRAM_ID_ISL_PS_OUT_VIDEO_SCALED_RES_B,
#endif
	ISA_LB_PROGRAM_ID_ISL_PS_OUT_SIS_SCALED_A,
	ISA_LB_PROGRAM_ID_ISL_PS_OUT_SIS_SCALED_B,
	ISA_LB_PROGRAM_ID_ISL_PS_OUT_VIDEO_FULL_RES,
	ISA_LB_PROGRAM_ID_ISL_PS_OUT_IR_DEPTH,
	ISA_LB_PROGRAM_ID_ACC_LSC_SPT,
	ISA_LB_PROGRAM_ID_ACC_RYNR,
	ISA_LB_PROGRAM_ID_ACC_DM,
	ISA_LB_PROGRAM_ID_ACC_VCSC,
	ISA_LB_PROGRAM_ID_ACC_ACM,
	ISA_LB_PROGRAM_ID_ACC_GTC,
	ISA_LB_PROGRAM_ID_ACC_YUV1,
	ISA_LB_PROGRAM_ID_ACC_GAMMASTAR_PASSTHROUGH,
	ISA_LB_PROGRAM_ID_ACC_GAMMASTAR,
	ISA_LB_PROGRAM_ID_ACC_DVS_L0,
	ISA_LB_PROGRAM_ID_ACC_DVS_L0_DISABLED,
	ISA_LB_PROGRAM_ID_ACC_DVS_L1,
	ISA_LB_PROGRAM_ID_ACC_DVS_L1_DISABLED,
	ISA_LB_PROGRAM_ID_ACC_DVS_L2,
	ISA_LB_PROGRAM_ID_ACC_DVS_L2_DISABLED,
	ISA_LB_PROGRAM_ID_ACC_GLTM,
	ISA_LB_PROGRAM_ID_ACC_XNR,
	ISA_LB_PROGRAM_ID_ACC_BLC_SPT,
	ISA_LB_PROGRAM_ID_N
};
#endif /* _ISA_LB_MANIFEST_GENERATED_H_ */
