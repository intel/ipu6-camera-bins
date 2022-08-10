/*
 * Copyright 2014-2017 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*!
 * \file ia_isp_bxt_config.h
*/

#ifndef IA_ISP_BXT_CONFIG_H_
#define IA_ISP_BXT_CONFIG_H_

#include "ia_types.h"
#include "ia_isp_bxt_types.h"

#ifdef __cplusplus
extern "C" {
#endif

ia_isp_bxt_resolution_info_t resolution_info_IDS =
{
    1920, 1080, { 0, 0, 0, 0 }, 1920, 1080, { 0, 0, 0, 0 }
};
/*
 * Example GraphConfig structure of ISYS kernels.
 */
const ia_isp_bxt_run_kernels_t run_kernels[11] =
{
    {
        60000,           /* stream_id */
        40241,           /* kernel_uuid = ia_pal_uuid_isp_bxt_norm_lin */
        1,               /* enable */
        NULL,            /* resolution_info */
        NULL,            /* resolution_history */
        { 0, 0, 0, 0 }   /* metadata[4] */
    },
    {
        60000,           /* stream_id */
        58152,           /* kernel_uuid = ia_pal_uuid_isp_bxt_blc */
        1,               /* enable */
        NULL,            /* resolution_info */
        NULL,            /* resolution_history */
        { 0, 0, 0, 0 }   /* metadata[4] */
    },
    {
        60000,           /* stream_id */
        63030,           /* kernel_uuid = ia_pal_uuid_isp_bxt_linearization */
        1,               /* enable */
        NULL,            /* resolution_info */
        NULL,            /* resolution_history */
        { 0, 0, 0, 0 }   /* metadata[4] */
    },
    {
        60000,           /* stream_id */
        4752,            /* kernel_uuid = ia_pal_uuid_isp_bxt_lsc */
        1,               /* enable */
        NULL,            /* resolution_info */
        NULL,            /* resolution_history */
        { 0, 0, 0, 0 }   /* metadata[4] */
    },
    {
        60000,           /* stream_id */
        49162,           /* kernel_uuid = ia_pal_uuid_isp_bxt_dpc */
        1,               /* enable */
        NULL,            /* resolution_info */
        NULL,            /* resolution_history */
        { 0, 0, 0, 0 }   /* metadata[4] */
    },
    {
        60000,           /* stream_id */
        21032,           /* kernel_uuid = ia_pal_uuid_isp_bxt_disparity */
        1,               /* enable */
        NULL,            /* resolution_info */
        NULL,            /* resolution_history */
        { 0, 0, 0, 0 }   /* metadata[4] */
    },
#if A0
    {
        60000,           /* stream_id */
        26126,           /* kernel_uuid = ia_pal_uuid_isp_bxt_inputscaler_a0 */
        1,               /* enable */
        &resolution_info_IDS, /* resolution_info */
        NULL,            /* resolution_history */
        { 0, 0, 0, 0 }   /* metadata[4] */
    },
#else
    {
        60000,           /* stream_id */
        29273,           /* kernel_uuid = ia_pal_uuid_isp_bxt_inputscaler */
        1,               /* enable */
        &resolution_info_IDS, /* resolution_info */
        NULL,            /* resolution_history */
        { 0, 0, 0, 0 }   /* metadata[4] */
    },
#endif
    {
        60000,           /* stream_id */
        3369,            /* kernel_uuid = ia_pal_uuid_isp_bxt_awbstatistics */
        1,               /* enable */
        NULL,            /* resolution_info */
        NULL,            /* resolution_history */
        { 0, 0, 0, 0 }   /* metadata[4] */
    },
    {
        60000,           /* stream_id */
        41227,           /* kernel_uuid = ia_pal_uuid_isp_bxt_af_awb_fr_statistics */
        1,               /* enable */
        NULL,            /* resolution_info */
        NULL,            /* resolution_history */
        { 0, 0, 0, 0 }   /* metadata[4] */
    },
    {
        60000,           /* stream_id */
        64443,           /* kernel_uuid = ia_pal_uuid_isp_bxt_3a_ccm */
        1,               /* enable */
        NULL,            /* resolution_info */
        NULL,            /* resolution_history */
        { 0, 0, 0, 0 }   /* metadata[4] */
    },
    {
        60000,           /* stream_id */
        42807,           /* kernel_uuid = ia_pal_uuid_isp_bxt_aestatistics */
        1,               /* enable */
        NULL,            /* resolution_info */
        NULL,            /* resolution_history */
        { 0, 0, 0, 0 }   /* metadata[4] */
    },
};

/*
 * Example GraphConfig structure of PSYS kernels.
 */
const ia_isp_bxt_run_kernels_t run_kernels_psys[14] =
{
    {
        60000,           /* stream_id */
        18263,           /* kernel_uuid = ia_pal_uuid_isp_bxt_wb */
        1,               /* enable */
        NULL,            /* resolution_info */
        NULL,            /* resolution_history */
        { 0, 0, 0, 0 }   /* metadata[4] */
    },
    {
        60000,           /* stream_id */
        38358,           /* kernel_uuid = ia_pal_uuid_isp_bxt_bitcomp_a0 */
        1,               /* enable */
        NULL,            /* resolution_info */
        NULL,            /* resolution_history */
        { 0, 0, 0, 0 }   /* metadata[4] */
    },
    {
        60000,           /* stream_id */
        14768,           /* kernel_uuid = ia_pal_uuid_isp_bxt_demosaic */
        1,               /* enable */
        NULL,            /* resolution_info */
        NULL,            /* resolution_history */
        { 0, 0, 0, 0 }   /* metadata[4] */
    },
    {
        60000,           /* stream_id */
        28826,           /* kernel_uuid = ia_pal_uuid_isp_bxt_ccm */
        1,               /* enable */
        NULL,            /* resolution_info */
        NULL,            /* resolution_history */
        { 0, 0, 0, 0 }   /* metadata[4] */
    },
    {
        60000,           /* stream_id */
        25423,           /* kernel_uuid = ia_pal_uuid_isp_bxt_bitdecomp_a0 */
        1,               /* enable */
        NULL,            /* resolution_info */
        NULL,            /* resolution_history */
        { 0, 0, 0, 0 }   /* metadata[4] */
    },
    {
        60000,           /* stream_id */
        46859,           /* kernel_uuid = ia_pal_uuid_isp_bxt_csc */
        1,               /* enable */
        NULL,            /* resolution_info */
        NULL,            /* resolution_history */
        { 0, 0, 0, 0 }   /* metadata[4] */
    },
    {
        60000,           /* stream_id */
        35563,           /* kernel_uuid = ia_pal_uuid_isp_bxt_gammatm */
        1,               /* enable */
        NULL,            /* resolution_info */
        NULL,            /* resolution_history */
        { 0, 0, 0, 0 }   /* metadata[4] */
    },
    {
        60000,           /* stream_id */
        21752,           /* kernel_uuid = ia_pal_uuid_isp_sc_iefd */
        1,               /* enable */
        NULL,            /* resolution_info */
        NULL,            /* resolution_history */
        { 0, 0, 0, 0 }   /* metadata[4] */
    },
    {
        60000,           /* stream_id */
        34391,           /* kernel_uuid = ia_pal_uuid_isp_bxt_dvsstatistics */
        1,               /* enable */
        NULL,            /* resolution_info */
        NULL,            /* resolution_history */
        { 0, 0, 0, 0 }   /* metadata[4] */
    },
    {
        60000,           /* stream_id */
        13358,           /* kernel_uuid = ia_pal_uuid_isp_bxt_ofa_mp */
        1,               /* enable */
        NULL,            /* resolution_info */
        NULL,            /* resolution_history */
        { 0, 0, 0, 0 }   /* metadata[4] */
    },
    {
        60000,           /* stream_id */
        43262,           /* kernel_uuid = ia_pal_uuid_isp_bxt_ofa_dp */
        1,               /* enable */
        NULL,            /* resolution_info */
        NULL,            /* resolution_history */
        { 0, 0, 0, 0 }   /* metadata[4] */
    },
    {
        60000,           /* stream_id */
        62328,           /* kernel_uuid = ia_pal_uuid_isp_bxt_ofa_ppp */
        1,               /* enable */
        NULL,            /* resolution_info */
        NULL,            /* resolution_history */
        { 0, 0, 0, 0 }   /* metadata[4] */
    },
    {
        60000,           /* stream_id */
        15103,           /* kernel_uuid = ia_pal_uuid_isp_sc_outputscaler_dp */
        1,               /* enable */
        NULL,            /* resolution_info */
        NULL,            /* resolution_history */
        { 0, 0, 0, 0 }   /* metadata[4] */
    },
    {
        60000,           /* stream_id */
        26683,           /* kernel_uuid = ia_pal_uuid_isp_sc_outputscaler_ppp */
        1,               /* enable */
        NULL,            /* resolution_info */
        NULL,            /* resolution_history */
        { 0, 0, 0, 0 }   /* metadata[4] */
    },
};

#ifdef __cplusplus
}
#endif
#endif /* IA_ISP_BXT_CONFIG_H_ */
