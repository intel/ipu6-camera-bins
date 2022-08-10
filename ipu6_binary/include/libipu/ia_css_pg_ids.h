/**
* INTEL CONFIDENTIAL
*
* Copyright (C) 2016 - 2019 Intel Corporation. All Rights
* Reserved.
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

#ifndef __IA_CSS_PG_IDS_H
#define __IA_CSS_PG_IDS_H

/******************************************************************************
 *
 * I M P O R T A N T   N O T E
 *
 * Do not add new program group id without previously asking for it!!!
 *
 * Contact ICG API CCB
 *
 ******************************************************************************/

#define IA_CSS_PROGRAM_GROUP_ID_4K60                            102
#define IA_CSS_PROGRAM_GROUP_ID_WBSWAP                          106
#define IA_CSS_PROGRAM_GROUP_ID_YUV0                            107
#define IA_CSS_PROGRAM_GROUP_ID_YUV1                            113
#define IA_CSS_PROGRAM_GROUP_ID_BAYER1_YUV0                     108
#define IA_CSS_PROGRAM_GROUP_ID_YUV0_NEW_PARAM                  200
#define IA_CSS_PROGRAM_GROUP_ID_BAYER0_YUV0_MULTI_SECTION       201
#define IA_CSS_PROGRAM_GROUP_ID_VPOSTGDC                        114
#define IA_CSS_PROGRAM_GROUP_ID_VPREGDC                         116
#define IA_CSS_PROGRAM_GROUP_ID_SPREGDC                         117
#define IA_CSS_PROGRAM_GROUP_ID_SPOSTGDC                        118
#define IA_CSS_PROGRAM_GROUP_ID_UVSWAP                          119
#define IA_CSS_PROGRAM_GROUP_ID_ISL_PS                          120
#define IA_CSS_PROGRAM_GROUP_ID_VHDRPREPROC                     121
#define IA_CSS_PROGRAM_GROUP_ID_VPREGDC_HQ                      122
#define IA_CSS_PROGRAM_GROUP_ID_GAUSSIAN                        123
#define IA_CSS_PROGRAM_GROUP_ID_SOBEL                           124
#define IA_CSS_PROGRAM_GROUP_ID_SPREGDC_XNR                     125
#define IA_CSS_PROGRAM_GROUP_ID_VIDEO_ISL_PREGDC                126
#define IA_CSS_PROGRAM_GROUP_ID_ISL_PS_HIRES                    127
#define IA_CSS_PROGRAM_GROUP_ID_SPOSTGDC_V2                     128
#define IA_CSS_PROGRAM_GROUP_ID_VPOSTGDC_V2                     129
#define IA_CSS_PROGRAM_GROUP_ID_SPREGDC_XNR_V2                  131
#define IA_CSS_PROGRAM_GROUP_ID_VPOSTGDC_MBR                    132
#define IA_CSS_PROGRAM_GROUP_ID_SPOSTGDC_MBR                    133
#define IA_CSS_PROGRAM_GROUP_ID_OFS_PIPE                        134
#define IA_CSS_PROGRAM_GROUP_ID_ISL_PS_INPUT_CROP               135
#define IA_CSS_PROGRAM_GROUP_ID_SPREGDC_XNR_V3                  136
#define IA_CSS_PROGRAM_GROUP_ID_VIDEO_ISL_PREGDC_HQ             137
#define IA_CSS_PROGRAM_GROUP_ID_VPREGDC_VCA_YUV1                139
/* #define IA_CSS_PROGRAM_GROUP_ID_IPU5_VPREGDC                 140 (PG Deleted. ID can be reused) */
#define IA_CSS_PROGRAM_GROUP_ID_DFM_ISL_PS_GLV                  141
#define IA_CSS_PROGRAM_GROUP_ID_GAUSSIAN_MEM                    142
/* #define IA_CSS_PROGRAM_GROUP_ID_IPU5_SPREGDC                 143 (PG Deleted. ID can be reused) */
/* #define IA_CSS_PROGRAM_GROUP_ID_IPU5_SPREGDC_NO_XNR          144 (PG Deleted. ID can be reused) */
/* #define IA_CSS_PROGRAM_GROUP_ID_IPU5_SPOSTGDC_MBR            145 (PG Deleted. ID can be reused) */
#define IA_CSS_PROGRAM_GROUP_ID_IPU5_SPOSTGDC                   146
#define IA_CSS_PROGRAM_GROUP_ID_IPU5_SPOSTGDC_IN8               147
#define IA_CSS_PROGRAM_GROUP_ID_VPREGDC_HQ_VCR2                 148
#define IA_CSS_PROGRAM_GROUP_ID_SPREGDC_XNR_V2_VCR2             149
#define IA_CSS_PROGRAM_GROUP_ID_SPREGDC_XNR_V3_VCR2             150
#define IA_CSS_PROGRAM_GROUP_ID_IPU5_VPOSTGDC                   151
#define IA_CSS_PROGRAM_GROUP_ID_IPU5_SPOSTGDC_IN8_DFM           152
/* #define IA_CSS_PROGRAM_GROUP_ID_IPU5_SPOSTGDC_IN8_MBR        153 (PG Deleted. ID can be reused) */
#define IA_CSS_PROGRAM_GROUP_ID_IPU5_VPREGDC_DVS                154
#define IA_CSS_PROGRAM_GROUP_ID_VIDEO_ISL_PREGDC_HQ_VCR2        156
#define IA_CSS_PROGRAM_GROUP_ID_IPU5_VPOSTGDC_DFM               157
/* #define IA_CSS_PROGRAM_GROUP_ID_IPU5_SPOSTGDCV1_IN8_DFM_MBR  158 (PG Deleted. ID can be reused) */
#define IA_CSS_PROGRAM_GROUP_ID_MULTI_CORE_COMMUNICATION        159
#define IA_CSS_PROGRAM_GROUP_ID_IPU5_YUV_ISA_TO_PSA             160
#define IA_CSS_PROGRAM_GROUP_ID_IPU5_SPOSTGDC_V4                161
#define IA_CSS_PROGRAM_GROUP_ID_IPU5_SPOSTGDC_IN8_V4            162
#define IA_CSS_PROGRAM_GROUP_ID_IPU5_YUV_ISA_TO_PSA_YUV_VMEM    164
#define IA_CSS_PROGRAM_GROUP_ID_IPU5_ISL_PS_VPLESS              166
/* #define IA_CSS_PROGRAM_GROUP_ID_IPU5_VPREGDC_VPLESS          167 (PG Deleted. ID can be reused) */
#define IA_CSS_PROGRAM_GROUP_ID_IPU5_SPREGDC_VPLESS             168
#define IA_CSS_PROGRAM_GROUP_ID_IPU5_VPOSTGDC_V4                169
/* #define IA_CSS_PROGRAM_GROUP_ID_IPU5_DFM_ISA_TO_PSA_YUV      170 (PG Deleted. ID can be reused) */
/* #define IA_CSS_PROGRAM_GROUP_ID_IPU5_DFM_ISA_TO_PSA_BAYER    171 (PG Deleted. ID can be reused) */
#define IA_CSS_PROGRAM_GROUP_ID_VPOSTGDC_V2_MBR                 172
#define IA_CSS_PROGRAM_GROUP_ID_SPOSTGDC_V2_MBR                 173
/* #define IA_CSS_PROGRAM_GROUP_ID_IPU5_DFM_ISA_TO_PSA_YUV_VMEM 174 (PG Deleted. ID can be reused) */
/* #define IA_CSS_PROGRAM_GROUP_ID_IPU5_DFM_ISA_TO_PSA_BAYER_VMEM 175 (PG Deleted. ID can be reused) */
#define IA_CSS_PROGRAM_GROUP_ID_IPU6_DMA_IN_OUT                 181
#define IA_CSS_PROGRAM_GROUP_ID_IPU6_LB_VIDEO                   182
#define IA_CSS_PROGRAM_GROUP_ID_IPU6_LB                         183
#define IA_CSS_PROGRAM_GROUP_ID_IPU6_ISA_VIDEO                  184
#define IA_CSS_PROGRAM_GROUP_ID_IPU6_ISA                        185
#define IA_CSS_PROGRAM_GROUP_ID_IPU6_ISA_LB_VIDEO               186
#define IA_CSS_PROGRAM_GROUP_ID_IPU6_ISA_LB                     187
#define IA_CSS_PROGRAM_GROUP_ID_IPU6_BB_OFS                     188
#define IA_CSS_PROGRAM_GROUP_ID_IPU6_BB                         189
#define IA_CSS_PROGRAM_GROUP_ID_DFM_ISL_PS_V2                   190
#define IA_CSS_PROGRAM_GROUP_ID_IPU5_SPOSTGDC_IN8_V4_DEC_CMPRS  192
#define IA_CSS_PROGRAM_GROUP_ID_IPU5_5_VPOSTGDC_10BIT           193
#define IA_CSS_PROGRAM_GROUP_ID_IPU5_ISA_LB                     194
#define IA_CSS_PROGRAM_GROUP_ID_IPU5_VPOSTGDC_V4_DEC_CMPRS      195
#define IA_CSS_PROGRAM_GROUP_ID_IPU6_BB_GDC_MBR_OFS             196
#define IA_CSS_PROGRAM_GROUP_ID_IPU5_5_SPOSTGDC_10BIT           197
#define IA_CSS_PROGRAM_GROUP_ID_IPU6S_ISA                       198
/* #define IA_CSS_PROGRAM_GROUP_ID_IPU7_ISA                     199 (PG Deleted. ID can be reused) */
#define IA_CSS_PROGRAM_GROUP_ID_IPU7_LBFF_SLIM                  200
#define IA_CSS_PROGRAM_GROUP_ID_IPU7_BBPS_SLIM                  201
#define IA_CSS_PROGRAM_GROUP_ID_IPU7_LBFF_FULL                  202


/* IDs in 300~999 are reserved for hetero computing by PVA */

/* 1000 - 1999 are reserved for IOT PGs
 * For DSS, the PG ID range is 1000 - 1049
 */
#define IA_CSS_PROGRAM_GROUP_ID_VPREGDC_HQ_NS                   1000
#define IA_CSS_PROGRAM_GROUP_ID_VPOSTGDC_HQ_NS                  1001
#define IA_CSS_PROGRAM_GROUP_ID_VPREGDC_HP                      1002
#define IA_CSS_PROGRAM_GROUP_ID_VPOSTGDC_HP                     1003
#define IA_CSS_PROGRAM_GROUP_ID_VPREGDC_LL                      1004
#define IA_CSS_PROGRAM_GROUP_ID_VHDRPREPROC_V2                  1005
#define IA_CSS_PROGRAM_GROUP_ID_VPREGDC_HQ_NS_DVS               1007
#define IA_CSS_PROGRAM_GROUP_ID_VPOSTGDC_HQ_NS_DVS2             1008
#define IA_CSS_PROGRAM_GROUP_ID_VPOSTGDC_HQ_NS_DVS3             1009
#define IA_CSS_PROGRAM_GROUP_ID_VPREGDC_HP_2FR                  1010
#define IA_CSS_PROGRAM_GROUP_ID_VPOSTGDC_HQ_4K                  1011
#define IA_CSS_PROGRAM_GROUP_ID_VPREGDC_ISL_HQ_4K               1012
#define IA_CSS_PROGRAM_GROUP_ID_VHDRPREPROC_STATS_HP            1013
#define IA_CSS_PROGRAM_GROUP_ID_VPREGDC_HP_DRC                  1014

/* 1050 - 1060 are reserved for IOT PGs
 * For TSD, the PG ID range is 1050 - 1060
 */
#define IA_CSS_PROGRAM_GROUP_ID_WEAVING                         1050
#define IA_CSS_PROGRAM_GROUP_ID_YUYV_SCALE                      1051
#define IA_CSS_PROGRAM_GROUP_ID_YUV_CSC                         1052
#define IA_CSS_PROGRAM_GROUP_ID_YUYV_LDC                        1053

/* 1100 - 1149 are reserved for SV PGs
 * For SV, the PG ID range is 1100 - 1149
 */
#define IA_CSS_PROGRAM_GROUP_ID_IPU5_PREGDC_BNLM                1100
/* #define IA_CSS_PROGRAM_GROUP_ID_IPU5_PREGDC_GS_SA            1101 (PG Deleted. ID can be reused) */
#define IA_CSS_PROGRAM_GROUP_ID_IPU5_SPOSTGDC_IN10              1103

/* Test PG Ids
 */
#define IA_CSS_PROGRAM_GROUP_DDR_LBVMEM_DDR                     10000
#define IA_CSS_PROGRAM_GROUP_OTF_BUF_CHASING                    10001
#define IA_CSS_PROGRAM_GROUP_ID_DDR_DMEM_DDR                    10006

/* VP less PG */
#define IA_CSS_PROGRAM_GROUP_DDR_LBVMEM_DDR_VPLESS              10004
#define IA_CSS_PROGRAM_GROUP_ID_IPU6_BB_GDC_MBR                 10005

#endif /* __IA_CSS_PG_IDS_H */
