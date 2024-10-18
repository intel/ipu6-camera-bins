/*
 * Copyright 2015-2019 Intel Corporation
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
 * \file ia_p2p_types.h
 * \brief Declares public2private interface data types.
 */

#ifndef IA_P2P_TYPES_H_
#define IA_P2P_TYPES_H_

#include <stdint.h>

#include "ia_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * Max section count for each kernel
 */
#define MAX_NUM_SECTIONS_PER_KERNEL 20

/*!
 * Max number of Algo kernels associated with a HW device
 */
#define MAX_NUM_ASSOCIATED_PALS_PER_DEVICE 5

/*!
 *  P2P instance handle type.
 */
typedef struct ia_p2p_t* ia_p2p_handle;

/*!
 *  Platform identifier.
 */
typedef enum
{
    IA_P2P_PLATFORM_BXT_A0,
    IA_P2P_PLATFORM_BXT_B0,
    IA_P2P_PLATFORM_CNL_A0,
    IA_P2P_PLATFORM_CNL_B0,
    IA_P2P_PLATFORM_GLV_A0,
    IA_P2P_PLATFORM_IPU6,
} ia_p2p_platform_t;

#define IA_P2P_MAX_FRAGMENTS       10
#define IA_P2P_MAX_KERNELS_PER_PG  128

/*!
 *  Fragment descriptor.
 */
typedef struct
{
    uint16_t fragment_width;    /*!< The width of the fragment. */
    uint16_t fragment_height;   /*!< The height of the fragment. */
    uint16_t fragment_start_x;  /*!< The x offset from the top-left corner of the full image. */
    uint16_t fragment_start_y;  /*!< The y offset from the top-left corner of the full image. */
} ia_p2p_fragment_desc;

/*!
 *  Fragment requirements.
 */
typedef struct
{
    uint8_t input_bpe;    /*!< The input bits per element. */
    uint8_t output_bpe;   /*!< The output bits per element. */
} ia_p2p_fragment_reqs;

/*!
 *  Full fragmentation configuration for a program group.
 */
typedef struct
{
    unsigned int fragment_count;
    ia_p2p_fragment_desc pixel_fragment_descs[IA_P2P_MAX_KERNELS_PER_PG][IA_P2P_MAX_FRAGMENTS];
} ia_p2p_fragment_configuration_t;

/*!
 *  Structure for terminal requirements, specifying the number of sections required for each terminal type.
 */
typedef struct
{
    unsigned int param_in_section_count;                        /*!< The number of parameter input sections required. */
    unsigned int param_out_section_count_per_fragment;          /*!< The number of parameter output sections required per fragment. */
    unsigned int program_section_count_per_fragment;            /*!< The number of program sections required per fragment. */
    unsigned int spatial_param_in_section_count;                /*!< The number of spatial param input sections required. */
    unsigned int spatial_param_out_section_count;               /*!< The number of spatial param output sections required. */
} ia_p2p_terminal_requirements_t;

/*!
 *  Payload descriptor specifying the total size of payload required for each terminal type.
 */
typedef struct
{
    uint32_t param_in_payload_size;             /*!< The total size of the parameter input payload in bytes. */
    uint32_t param_out_payload_size;            /*!< The total size of the parameter output payload in bytes. */
    uint32_t program_payload_size;              /*!< The total size of the program payload in bytes. */
    uint32_t spatial_param_in_payload_size;     /*!< The total size of the spatial param input payload in bytes. */
    uint32_t spatial_param_out_payload_size;    /*!< The total size of the spatial param output payload in bytes. */
} ia_p2p_payload_desc;

/*!
 *  Payload descriptor specifying the count and size of payload required for each terminal type.
 */
typedef struct
{
    uint32_t param_in_section_count;                              /*!< The count of parameter input sections. */
    uint32_t param_out_section_count;                             /*!< The count of parameter output sections (per fragment). */
    uint32_t program_section_count;                               /*!< The count of program sections (per fragment). */
    uint32_t param_in_section_size[MAX_NUM_SECTIONS_PER_KERNEL];  /*!< The size of the parameter input section in bytes. */
    uint32_t param_out_section_size[MAX_NUM_SECTIONS_PER_KERNEL]; /*!< The size of the parameter output section in bytes. */
    uint32_t program_section_size[MAX_NUM_SECTIONS_PER_KERNEL];   /*!< The size of the program section in bytes. */
} ia_p2p_payload_section_desc;
/*!
 *  Flags for available serialized statistics.
 */
typedef struct
{
    bool rgbs_grid;          /*!< If true, RGBS grid is available. */
    bool af_grid;            /*!< If true, AF grid is available. */
    bool histograms;         /*!< If true, histograms are available. */
    bool dvs_stats;          /*!< If true, DVS statistics are available. */
    bool paf_grid;           /*!< If true, PAF grid is available. */
    bool rgbs_grids_hdr;     /*!< If true, RGBS HDR grids are available. */
    bool rgby_grids_hdr;     /*!< If true, RGBY stat for high precision histogram is available. */
    bool yv_grids_hdr;       /*!< If true, YV HDR grids are available. */
} ia_p2p_statistics_included_t;

/* Currently supported program groups. */
#define IA_P2P_PG_ISYS                       0       /* No manifest available so we define a custom PG specification id for ISYS. */
#define IA_P2P_PG_VPOSTGDC                   114     /* IA_CSS_BXT_PSS_PG_SPECIFICATION_VPOSTGDC */
#define IA_P2P_PG_VPREGDC                    116     /* Deprecated */
#define IA_P2P_PG_SPREGDC                    117     /* Deprecated */
#define IA_P2P_PG_SPOSTGDC                   118
#define IA_P2P_PG_ISL                        120     /* Deprecated */
#define IA_P2P_PG_VHDR_PREPROC               121     /* Deprecated */
#define IA_P2P_PG_VPREGDC_HQ                 122
#define IA_P2P_PG_VPREGDC_HQ_VCR2            148
#define IA_P2P_PG_VIDEO_ISL_PREGDC_HQ_VCR2   156
#define IA_P2P_PG_SPREGDC_XNR                125     /* Deprecated */
#define IA_P2P_PG_SPREGDC_XNR_V2             131
#define IA_P2P_PG_SPREGDC_XNR_V3             136
#define IA_P2P_PG_SPOSTGDC_IN8               152
#define IA_P2P_PG_SPOSTGDC_V4                161     /* For SV usage only */
#define IA_P2P_PG_SPOSTGDC_IN8_V4            162
#define IA_P2P_PG_SPREGDC_XNR_V2_VCR2        149
#define IA_P2P_PG_SPREGDC_XNR_V3_VCR2        150
#define IA_P2P_PG_ISL_PS_HIRES               127
#define IA_P2P_PG_ISL_PS_INPUT_CROP          127
#define IA_P2P_PG_ISL_PS_RGBIR               130
#define IA_P2P_PG_ISL_RGBIR_VPREGDC_HQ_VCR2  158
#define IA_P2P_PG_SPOSTGDC_V2                128
#define IA_P2P_PG_SPOSTGDC_V2_MBR            173
#define IA_P2P_PG_VPOSTGDC_V2                129
#define IA_P2P_PG_VPOSTGDC_V2_MBR            172
#define IA_P2P_PG_VPOSTGDC_MBR               132
#define IA_P2P_PG_SPOSTGDC_MBR               133
#define IA_P2P_PG_IPU5_SPOSTGDC_10BIT        197
#define IA_P2P_PG_POWERON                    201     /* Deprecated */
#define IA_P2P_PG_VIDEO_ISL_PREGDC_HQ        137
#define IA_P2P_PG_ISL_PS_GLV                 138
#define IA_P2P_PG_ISL_PS_GLV_V2              155
#define IA_P2P_PG_DFM_ISL_PS_GLV_VPLESS      166     /* To be removed, leaved here to simplify integration (referenced by libiacss) */
#define IA_P2P_PG_ISL_PS_GLV_VPLESS          166
#define IA_P2P_PG_ISA_LB_GLV_VPLESS          194
#define IA_P2P_PG_IPU5_VPREGDC_VPLESS        167
#define IA_P2P_PG_IPU5_SPREGDC_VPLESS        168
#define IA_P2P_PG_IPU5_VPOSTGDC_V1           151
#define IA_P2P_PG_IPU5_VPOSTGDC_V4           169
#define IA_P2P_PG_IPU5_VPOSTGDC_V4_HDR10     193 /* TODO: Remove after merge. Here just to avoid two-way dependency to libiacss */
#define IA_P2P_PG_IPU5_VPOSTGDC_V4_10BIT     193
#define IA_P2P_PG_IPU6_LB_PSA_BYPASS         182
#define IA_P2P_PG_IPU6_LB_PSA                183
#define IA_P2P_PG_IPU6_ISL_RBM               185
#define IA_P2P_PG_IPU6_ISA_LB                187
#define IA_P2P_PG_IPU6_BB_OFS                188
#define IA_P2P_PG_IPU6_BB                    189
#define IA_P2P_PG_IPU6_BB_OFS_GDC            196
#define IA_P2P_PG_IPU6S_ISA                  198
#define IA_P2P_PG_VPREGDC_HQ_NS              1000    /* IA_CSS_PROGRAM_GROUP_ID_VPREGDC_HQ_NS */
#define IA_P2P_PG_VPOSTGDC_HQ_NS             1001    /* IA_CSS_PROGRAM_GROUP_ID_VPOSTGDC_HQ_NS */
#define IA_P2P_PG_VPREGDC_HP                 1002    /* IA_CSS_PROGRAM_GROUP_ID_VPREGDC_HP */
#define IA_P2P_PG_VPOSTGDC_HP                1003    /* IA_CSS_PROGRAM_GROUP_ID_VPOSTGDC_HP */
#define IA_P2P_PG_VPREGDC_LL                 1004    /* IA_CSS_PROGRAM_GROUP_ID_VPREGDC_LL */
#define IA_P2P_PG_VHDR_PREPROC_V2            1005    /* IA_CSS_PROGRAM_GROUP_ID_VHDR_PREPROC_V2 */
#define IA_P2P_PG_VPREGDC_HQ_NS_DVS          1007    /* IA_CSS_PROGRAM_GROUP_ID_VPREGDC_HQ_NS_DVS */
#define IA_P2P_PG_VPOSTGDC_HQ_NS_DVS2        1008    /* IA_CSS_PROGRAM_GROUP_ID_VPOSTGDC_HQ_NS_DVS2 */
#define IA_P2P_PG_VPOSTGDC_HQ_NS_DVS3        1009    /* IA_CSS_PROGRAM_GROUP_ID_VPOSTGDC_HQ_NS_DVS3 */
#define IA_P2P_PG_VPREGDC_HP_2FR             1010    /* IA_CSS_PROGRAM_GROUP_ID_VPREGDC_HP_2FR */
#define IA_P2P_PG_VPOSTGDC_HQ_4K             1011    /* IA_CSS_PROGRAM_GROUP_ID_VPOSTGDC_HQ_4K */
#define IA_P2P_PG_VPREGDC_ISL_HQ_4K          1012    /* IA_CSS_PROGRAM_GROUP_ID_VPREGDC_ISL_HQ_4K */
#define IA_P2P_PG_VHDR_PREPROC_STATS_HP      1013    /* A_CSS_PROGRAM_GROUP_ID_VHDRPREPROC_STATS_HP */
#define IA_P2P_PG_VPREGDC_HP_DRC             1014    /* IA_CSS_PROGRAM_GROUP_ID_VPREGDC_HP_DRC */
#define IA_P2P_PG_VHDR_PREGDC_HP             1015    /* IA_CSS_PROGRAM_GROUP_ID_VHDR_PREGDC_HP */
#define IA_P2P_PG_VHDR_PREGDC_HP_DRC2        1016    /* IA_CSS_PROGRAM_GROUP_ID_VHDR_PREGDC_HP_DRC2 */
#define IA_P2P_PG_VHDR_PREGDC_HP_2FR_V2      1017    /* IA_CSS_PROGRAM_GROUP_ID_VHDR_PREGDC_HP_2FR_V2 */
#define IA_P2P_PG_YUYV_SCALE                 1051    /* IA_CSS_PROGRAM_GROUP_ID_YUYV_SCALE */
#define IA_P2P_PG_YUV_CSC                    1052    /* IA_CSS_PROGRAM_GROUP_ID_YUV_CSC */
#define IA_P2P_PG_YUYV_LDC                   1053    /* IA_CSS_PROGRAM_GROUP_ID_YUYV_LDC */
#define IA_P2P_PG_TEST                       1       /* For internal P2P testing. */

#ifdef __cplusplus
}
#endif

#endif /* IA_P2P_TYPES_H_ */
