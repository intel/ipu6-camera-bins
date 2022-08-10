/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2015 - 2020 Intel Corporation.
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

#ifndef __PG_LB_VIDEO_MANIFEST_H
#define __PG_LB_VIDEO_MANIFEST_H

#include "ia_css_progdesc_acc_symbol_ids.h"
#include "pg_lb_video.terminal_ids.h"
#include "vied_nci_psys_resource_model_private.h"

enum PG_LB_VIDEO_DEVICE_ID {
	PG_LB_VIDEO_DEVICE_ID_V2S_DEV = VIED_NCI_DEVICE_ID_V2S,
	PG_LB_VIDEO_DEVICE_ID_S2V_DEV = VIED_NCI_DEVICE_ID_S2V,
	PG_LB_VIDEO_DEVICE_ID_DEC400_PSA_OUT_DEV = VIED_NCI_DEVICE_ID_DEC400,
	PG_LB_VIDEO_DEVICE_ID_ACB_DEV = VIED_NCI_DEVICE_ID_LB_ACB,
	PG_LB_VIDEO_DEVICE_ID_DVS_CONTROLLER_DEV = VIED_NCI_DEVICE_ID_DVS_CONTROLLER,
	PG_LB_VIDEO_DEVICE_ID_STRM_PACK_DEV = VIED_NCI_DEVICE_ID_STRM_PACK,
};

enum PG_LB_VIDEO_KERNEL_ID {
	PG_LB_VIDEO_KERNEL_ID_BNLM_FF           = KERNEL_ID_RYNR_BNLM,
	PG_LB_VIDEO_KERNEL_ID_GLTM_FF           = KERNEL_ID_GLTM,
	PG_LB_VIDEO_KERNEL_ID_XNR5_VHF_FF       = KERNEL_ID_XNR_VHF,
	PG_LB_VIDEO_KERNEL_ID_XNR5_HF_FF        = KERNEL_ID_XNR_HF,
	PG_LB_VIDEO_KERNEL_ID_XNR5_SE_FF     = KERNEL_ID_XNR_HF_SE,
	PG_LB_VIDEO_KERNEL_ID_XNR5_MF_FF        = KERNEL_ID_XNR_MF,
	PG_LB_VIDEO_KERNEL_ID_XNR5_SE_MF_FF     = KERNEL_ID_XNR_MF_SE,
	PG_LB_VIDEO_KERNEL_ID_XNR5_LF_FF        = KERNEL_ID_XNR_LF,
	PG_LB_VIDEO_KERNEL_ID_XNR5_SE_LF_FF     = KERNEL_ID_XNR_LF_SE,
	PG_LB_VIDEO_KERNEL_ID_XNR5_LFE_FF       = KERNEL_ID_XNR_LFE,
	PG_LB_VIDEO_KERNEL_ID_XNR5_VLF_FF       = KERNEL_ID_XNR_VLF,
	PG_LB_VIDEO_KERNEL_ID_XNR5_SE_VLF_FF    = KERNEL_ID_XNR_VLF_SE,
#if HAS_VCR_IN_VCA
	PG_LB_VIDEO_KERNEL_ID_VCR2_FF           = KERNEL_ID_VCA_VCR2,
#else
	PG_LB_VIDEO_KERNEL_ID_VCR_FF            = KERNEL_ID_XNR_VCR,
#endif
#if HAS_ACM_CCM
	PG_LB_VIDEO_KERNEL_ID_CCM_FF            = KERNEL_ID_ACM_CCM,
#endif
	PG_LB_VIDEO_KERNEL_ID_GLIM_FF           = KERNEL_ID_ACM_GLIM,
	PG_LB_VIDEO_KERNEL_ID_ACM_FF            = KERNEL_ID_ACM_ACM,
	PG_LB_VIDEO_KERNEL_ID_GAMMASTAR_FF      = KERNEL_ID_GAMMASTAR,
	PG_LB_VIDEO_KERNEL_ID_FF_GAMMA_TM_FF    = KERNEL_ID_GTC_GTM,
	PG_LB_VIDEO_KERNEL_ID_CSC_CDS_FF        = KERNEL_ID_GTC_CSC_CDS,
	PG_LB_VIDEO_KERNEL_ID_YUV_SPLITTER_FF   = KERNEL_ID_YUV1_SPLITTER,
	PG_LB_VIDEO_KERNEL_ID_IEFD_FF           = KERNEL_ID_YUV1_IEFD,
	PG_LB_VIDEO_KERNEL_ID_Y_BIN_FF          = KERNEL_ID_DVS_YBIN,
	PG_LB_VIDEO_KERNEL_ID_DVS_FF            = KERNEL_ID_DVS_DVS,
	PG_LB_VIDEO_KERNEL_ID_ESPA_FF           = KERNEL_ID_ESPA,
	PG_LB_VIDEO_KERNEL_ID_ESPA_V2S_PSA_1_FF = KERNEL_ID_ESPA_V2S_PSA_1,
	PG_LB_VIDEO_KERNEL_ID_STRMCROP_FF_PSA_H = KERNEL_ID_STREAM_CROP_PSA_H,
	PG_LB_VIDEO_KERNEL_ID_DVS_STATS_L0      = KERNEL_ID_DVS_STATS_L0,
	PG_LB_VIDEO_KERNEL_ID_DVS_STATS_L1      = KERNEL_ID_DVS_STATS_L1,
	PG_LB_VIDEO_KERNEL_ID_DVS_STATS_L2      = KERNEL_ID_DVS_STATS_L2,
	PG_LB_VIDEO_KERNEL_ID_GET               = PG_LB_VIDEO_KERNEL_ID_DVS_STATS_L2 + 1,
	PG_LB_VIDEO_KERNEL_ID_PUT               = PG_LB_VIDEO_KERNEL_ID_GET + 1,
	PG_LB_VIDEO_KERNEL_ID_GAMMASTAR_GRID    = PG_LB_VIDEO_KERNEL_ID_PUT + 1
};

#endif /* __PG_LB_VIDEO_MANIFEST_H */

