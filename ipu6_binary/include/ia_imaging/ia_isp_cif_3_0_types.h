/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2014 Intel Corporation
 * All Rights Reserved.
 *
 * The source code contained or described herein and all documents related to
 * the source code ("Material") are owned by Intel Corporation or its
 * suppliers or licensors. Title to the Material remains with Intel
 * Corporation or its suppliers and licensors. The Material may contain trade
 * secrets and proprietary and confidential information of Intel Corporation
 * and its suppliers and licensors, and is protected by worldwide copyright
 * and trade secret laws and treaty provisions. No part of the Material may be
 * used, copied, reproduced, modified, published, uploaded, posted,
 * transmitted, distributed, or disclosed in any way without Intel's prior
 * express written permission.
 *
 * No license under any patent, copyright, trade secret or other intellectual
 * property right is granted to or conferred upon you by disclosure or
 * delivery of the Materials, either expressly, by implication, inducement,
 * estoppel or otherwise. Any license under such intellectual property rights
 * must be express and approved by Intel in writing.
 *
 * Unless otherwise agreed by Intel in writing, you may not remove or alter
 * this notice or any other notice embedded in Materials by Intel or Intels
 * suppliers or licensors in any way.
 */

#ifndef IA_ISP_CIF_3_0_TYPES_H_
#define IA_ISP_CIF_3_0_TYPES_H_

#include "cif_3_0_lp_isp_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------- INPUTS TO ISP ----------------------*/
#define BPC_CONFIG (1)
#define BLS_CONFIG (BPC_CONFIG << 1)
#define SDG_CONFIG (BLS_CONFIG << 1)
#define HST_CONFIG (SDG_CONFIG << 1)
#define LSC_CONFIG (HST_CONFIG << 1)
#define AWB_CONFIG (LSC_CONFIG << 1)
#define FLT_CONFIG (AWB_CONFIG << 1)
#define BDM_CONFIG (FLT_CONFIG << 1)
#define CTK_CONFIG (BDM_CONFIG << 1)
#define GOC_CONFIG (CTK_CONFIG << 1)
#define CPROC_CONFIG (GOC_CONFIG << 1)
#define YCFILT_CONFIG (CPROC_CONFIG << 1)
#define AFC_CONFIG (YCFILT_CONFIG << 1)
#define TMAP_CONFIG (AFC_CONFIG << 1)
#define MACC_CONFIG (TMAP_CONFIG << 1)
#define AWB_MEAS_CONFIG (MACC_CONFIG << 1)
#define IE_CONFIG (AWB_MEAS_CONFIG << 1)

#define CIFISP_BPC_CONFIG_SIZE (IA_ALIGN(sizeof(struct cifisp_bpc_config),8))
#define CIFISP_BLS_CONFIG_SIZE (IA_ALIGN(sizeof(struct cifisp_bls_config),8))
#define CIFISP_SDG_CONFIG_SIZE (IA_ALIGN(sizeof(struct cifisp_sdg_config),8))
#define CIFISP_LSC_CONFIG_SIZE (IA_ALIGN(sizeof(struct cifisp_lsc_config),8))
#define CIFISP_AWB_GAIN_CONFIG_SIZE (IA_ALIGN(sizeof(struct cifisp_awb_gain_config),8))
#define CIFISP_AWB_MEAS_CONFIG_SIZE (IA_ALIGN(sizeof(struct cifisp_awb_meas_config),8))
#define CIFISP_AEC_MEAS_CONFIG_SIZE (IA_ALIGN(sizeof(struct cifisp_aec_config),8))
#define CIFISP_BDM_CONFIG_SIZE (IA_ALIGN(sizeof(struct cifisp_bdm_config),8))
#define CIFISP_FLT_CONFIG_SIZE (IA_ALIGN(sizeof(struct cifisp_flt_config),8))
#define CIFISP_CTK_CONFIG_SIZE (IA_ALIGN(sizeof(struct cifisp_ctk_config),8))
#define CIFISP_GOC_CONFIG_SIZE (IA_ALIGN(sizeof(struct cifisp_goc_config),8))
#define CIFISP_CPROC_CONFIG_SIZE (IA_ALIGN(sizeof(struct cifisp_cproc_config),8))
#define CIFISP_YCFILT_CONFIG_SIZE (IA_ALIGN(sizeof(struct cifisp_ycflt_config),8))
#define CIFISP_AFC_CONFIG_SIZE (IA_ALIGN(sizeof(struct cifisp_afc_config),8))
#define CIFISP_HST_CONFIG_SIZE (IA_ALIGN(sizeof(struct cifisp_hst_config),8))
#define CIFISP_TMAP_CONFIG_SIZE (IA_ALIGN(sizeof(struct cifisp_tmap_config),8))
#define CIFISP_MACC_CONFIG_SIZE (IA_ALIGN(sizeof(struct cifisp_macc_config),8))

struct ia_cif_isp_3_0_awb_stat{
    // directly use the memory of stats buffer to save some space
    struct cifisp_awb_stat *awb_stat;
    unsigned short grid_width;
    unsigned short grid_height;
    struct cifisp_window window_config;
};

struct ia_cif_isp_3_0_config {
    unsigned int active_configs;
    struct cifisp_bpc_config bpc_config;
    struct cifisp_bls_config bls_config;
    struct cifisp_sdg_config sdg_config;
    struct cifisp_hst_config hst_config;
    struct cifisp_lsc_config lsc_config;
    struct cifisp_awb_gain_config awb_gain_config;
    struct cifisp_awb_meas_config awb_meas_config;
    struct cifisp_flt_config flt_config;
    struct cifisp_bdm_config bdm_config;
    struct cifisp_ctk_config ctk_config;
    struct cifisp_goc_config goc_config;
    struct cifisp_cproc_config cproc_config;
    struct cifisp_ycflt_config ycfilt_config;
    struct cifisp_afc_config afc_config;
    struct cifisp_tmap_config tmap_config;
    struct cifisp_macc_config macc_config;
    struct cifisp_ie_config ie_config;
};

#ifdef __cplusplus
}
#endif

#endif /* IA_CIF_3_0_TYPES_H_ */
