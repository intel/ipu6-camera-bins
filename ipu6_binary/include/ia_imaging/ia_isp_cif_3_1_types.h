/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2014-2017 Intel Corporation
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

#ifndef IA_ISP_CIF_3_1_TYPES_H_
#define IA_ISP_CIF_3_1_TYPES_H_

#include "cif_isp3_isp_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------- INPUTS TO ISP ----------------------*/

struct ia_cif_isp_3_1_stats{
    struct cifisp_awb_stat *awb; /* NULL or stats from driver */
    struct cifisp_meas_grid *awb_grid;
    struct cifisp_af_stat *af; /* NULL or stats from driver */
    struct cifisp_meas_grid *af_grid;
};

struct ia_cif_isp_3_1_config {
    struct cifisp_bpc_config bpc_config;
    struct cifisp_bls_config bls_config;
    struct cifisp_lsc_config lsc_config;
    struct cifisp_awb_gain_config awb_gain_config;
    struct cifisp_awb_meas_config awb_meas_config;
    struct cifisp_bnr_config bnr_config;
    struct cifisp_flt_config flt_config;
    struct cifisp_ctk_config ctk_config;
    struct cifisp_goc_config goc_config;
    struct cifisp_cproc_config cproc_config;
    struct cifisp_ycflt_config ycfilt_config;
    struct cifisp_afm_config afm_config;
    struct cifisp_tmap_config tmap_config;
    struct cifisp_macc_config macc_config;
    struct cifisp_ie_config ie_config;
};

#ifdef __cplusplus
}
#endif

#endif /* IA_CIF_3_1_TYPES_H_ */
