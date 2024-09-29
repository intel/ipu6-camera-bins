/*
 * Copyright 2021 Intel Corporation
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
 * \file ia_isp_bxt_statistics_types.h
 * \brief BXT ISP specific statistics data types.
*/
#ifndef IA_ISP_BXT_STATISTICS_TYPES_H_
#define IA_ISP_BXT_STATISTICS_TYPES_H_

#include "ia_types.h"

#define BXT_HISTOGRAM_BINS                          256
#define BXT_FILTER_RESPONSE_GRID_MAX_NUM_ELEMENTS   1024    /* Max grid size = [32, 32] */

#define BXT_RGBS_GRID_MAX_WIDTH                     96 /* Max grid size = [96, 72] */
#define BXT_RGBS_GRID_MAX_HEIGHT                    72
#define BXT_RGBS_GRID_MAX_NUM_ELEMENTS              (BXT_RGBS_GRID_MAX_WIDTH*BXT_RGBS_GRID_MAX_HEIGHT)

#define BXT_DVS_STATS_L0_MAX_NUM_ELEMENTS 154
#define BXT_DVS_STATS_L1_MAX_NUM_ELEMENTS 120
#define BXT_DVS_STATS_L2_MAX_NUM_ELEMENTS 85

#define BXT_PAF_STATS_MAX_STEPS                      11     /*!< Max number of phase shifts in a block. */
#define BXT_PAF_STATS_GRID_MAX_NUM_ELEMENTS          (16*12*BXT_PAF_STATS_MAX_STEPS) /*!< Max grid size = [16, 12] */

#define BXT_HDR_RGBY_GRID_MAX_WIDTH                  484  /*!< Maximum grid width for HDR-statisics.*/
#define BXT_HDR_RGBY_GRID_MAX_HEIGHT                 276  /*!< Maximum grid height for HDR-statisics.*/
#define BXT_HDR_RGBY_GRID_MAX_NUM_ELEMENTS           (BXT_HDR_RGBY_GRID_MAX_WIDTH * BXT_HDR_RGBY_GRID_MAX_HEIGHT)  /*!< Maximum grid size for HDR-statisics.484*276=133584.*/

typedef enum
{
    /* TODO: These should be calculated as a hash from the below data structures. */
    ia_isp_bxt_statistics_uuid_filter_response_grid = 101,
    ia_isp_bxt_statistics_uuid_rgbs_grid = 102,
    ia_isp_bxt_statistics_uuid_histograms = 103,
    ia_isp_bxt_statistics_uuid_motion_vectors = 104,
    ia_isp_bxt_statistics_uuid_paf_grid = 105,
    ia_isp_bxt_statistics_uuid_hdr_rgbs_grid = 106,           /*!< RGBS grid with higher than 8 bit precision. */
    ia_isp_bxt_statistics_uuid_hdr_rgby_grid = 107,           /*!< RGBY grid with higher than 8 bit precision. Possibly compressed. */
    ia_isp_bxt_statistics_uuid_hdr_yv_grid = 108              /*!< Y (Luma) V (Value in HSV color space)  grid with higher than 8 bit precision. Possibly compressed. */
} ia_isp_bxt_statistics_uuid;

typedef struct
{
    int32_t uuid;                           /*!< Unique identifier of the record. See ia_isp_bxt_statistics_uuid. */
    int32_t size;                           /*!< The size of the record (i.e., the size of this struct). */
} ia_isp_bxt_statistics_header_t;

typedef struct
{
    ia_isp_bxt_statistics_header_t header;  /*!< Header data. */
    int32_t hist_c0[BXT_HISTOGRAM_BINS];    /*!< Histogram for color channel C0. */
    int32_t hist_c1[BXT_HISTOGRAM_BINS];    /*!< Histogram for color channel C1. */
    int32_t hist_c2[BXT_HISTOGRAM_BINS];    /*!< Histogram for color channel C2. */
    int32_t hist_c3[BXT_HISTOGRAM_BINS];    /*!< Histogram for color channel C3. */
    int32_t hist_c4[BXT_HISTOGRAM_BINS];    /*!< Histogram for color channel C4. */
    int32_t hist_c5[BXT_HISTOGRAM_BINS];    /*!< Histogram for color channel C5. */
    int32_t hist_c6[BXT_HISTOGRAM_BINS];    /*!< Histogram for color channel C6. */
    int32_t hist_c7[BXT_HISTOGRAM_BINS];    /*!< Histogram for color channel C7. */
} ia_isp_bxt_histograms_t;

typedef struct
{
    ia_isp_bxt_statistics_header_t header;                      /*!< Header data. */
    int32_t grid_width;                                         /*!< The actual grid width. Specifies the amount of valid data in the below arrays. */
    int32_t grid_height;                                        /*!< The actual grid height. Specifies the amount of valid data in the below arrays. */
    int32_t y00_avg[BXT_FILTER_RESPONSE_GRID_MAX_NUM_ELEMENTS]; /*!< Y00 filter responses for each grid block. */
    int32_t y01_avg[BXT_FILTER_RESPONSE_GRID_MAX_NUM_ELEMENTS]; /*!< Y01 filter responses for each grid block. */
    int32_t y10_avg[BXT_FILTER_RESPONSE_GRID_MAX_NUM_ELEMENTS]; /*!< Y10 filter responses for each grid block. */
    int32_t y11_avg[BXT_FILTER_RESPONSE_GRID_MAX_NUM_ELEMENTS]; /*!< Y11 filter responses for each grid block. */
    int32_t r_avg[BXT_FILTER_RESPONSE_GRID_MAX_NUM_ELEMENTS];   /*!< R filter responses for each grid block. */
    int32_t g_avg[BXT_FILTER_RESPONSE_GRID_MAX_NUM_ELEMENTS];   /*!< G filter responses for each grid block. */
    int32_t b_avg[BXT_FILTER_RESPONSE_GRID_MAX_NUM_ELEMENTS];   /*!< B filter responses for each grid block. */
} ia_isp_bxt_filter_response_grid_t;

typedef struct
{
    ia_isp_bxt_statistics_header_t header;                      /*!< Header data. */
    int32_t grid_width;                                         /*!< The actual grid width. Specifies the amount of valid data in the below arrays. */
    int32_t grid_height;                                        /*!< The actual grid height. Specifies the amount of valid data in the below arrays. */
    int32_t c0_avg[BXT_RGBS_GRID_MAX_NUM_ELEMENTS];             /*!< Average level of C0 color for each grid block. */
    int32_t c1_avg[BXT_RGBS_GRID_MAX_NUM_ELEMENTS];             /*!< Average level of C1 color for each grid block. */
    int32_t c2_avg[BXT_RGBS_GRID_MAX_NUM_ELEMENTS];             /*!< Average level of C2 color for each grid block. */
    int32_t c3_avg[BXT_RGBS_GRID_MAX_NUM_ELEMENTS];             /*!< Average level of C3 color for each grid block. */
    int32_t c4_avg[BXT_RGBS_GRID_MAX_NUM_ELEMENTS];             /*!< Average level of C4 color for each grid block. */
    int32_t c5_avg[BXT_RGBS_GRID_MAX_NUM_ELEMENTS];             /*!< Average level of C5 color for each grid block. */
    int32_t c6_avg[BXT_RGBS_GRID_MAX_NUM_ELEMENTS];             /*!< Average level of C6 color for each grid block. */
    int32_t c7_avg[BXT_RGBS_GRID_MAX_NUM_ELEMENTS];             /*!< Average level of C7 color for each grid block. */
    int32_t sat_ratio_0[BXT_RGBS_GRID_MAX_NUM_ELEMENTS / 4];    /*!< Saturation ratios. 0 = 0% above saturation. 255 = 100% above saturation. */
    int32_t sat_ratio_1[BXT_RGBS_GRID_MAX_NUM_ELEMENTS / 4];    /*!< Saturation ratios. 0 = 0% above saturation. 255 = 100% above saturation. */
    int32_t sat_ratio_2[BXT_RGBS_GRID_MAX_NUM_ELEMENTS / 4];    /*!< Saturation ratios. 0 = 0% above saturation. 255 = 100% above saturation. */
    int32_t sat_ratio_3[BXT_RGBS_GRID_MAX_NUM_ELEMENTS / 4];    /*!< Saturation ratios. 0 = 0% above saturation. 255 = 100% above saturation. */
} ia_isp_bxt_rgbs_grid_t;

/*!
 * \brief RGBS data collected from decompressed and merged (from multiple exposures) HDR image.
 * Named as StatR/G/B/S in ISP Firmware.
*/
typedef struct
{
    ia_isp_bxt_statistics_header_t header;                      /*!< Header data. */
    int32_t grid_width;                                         /*!< The actual grid width. Specifies the amount of valid data in the below arrays. */
    int32_t grid_height;                                        /*!< The actual grid height. Specifies the amount of valid data in the below arrays. */
    int32_t r_avg[BXT_RGBS_GRID_MAX_NUM_ELEMENTS];              /*!< U20. Average level of red color for each grid block. */
    int32_t g_avg[BXT_RGBS_GRID_MAX_NUM_ELEMENTS];              /*!< U20. Average level of (gr+gb)/2 color for each grid block. */
    int32_t b_avg[BXT_RGBS_GRID_MAX_NUM_ELEMENTS];              /*!< U20. Average level of blue color for each grid block. */
    uint8_t sat[BXT_RGBS_GRID_MAX_NUM_ELEMENTS];          /*!< U8. currently this is saturation count and it will be saturation percentage after a few weeks. All codes need to be updated accordingly.*/
} ia_isp_bxt_hdr_rgbs_grid_t;

/*!
 * \brief RBGY grids of data which may be compressed or not based on sensor and ISP pipe type.
 * Named as HistStatR/G/B/Y in ISP Firmware.
 * If statistics are compressed, information for decompression is described in structure ia_isp_bxt_hdr_compression_property_t.
*/
typedef struct
{
    ia_isp_bxt_statistics_header_t header;                      /*!< Header data. */
    int32_t grid_width;                                         /*!< The actual grid width. Specifies the amount of valid data in the below arrays. */
    int32_t grid_height;                                        /*!< The actual grid height. Specifies the amount of valid data in the below arrays. */
    uint16_t r_avg[BXT_HDR_RGBY_GRID_MAX_NUM_ELEMENTS];   /*!< U15. Average level of R color for each grid block with high resolution. */
    uint16_t b_avg[BXT_HDR_RGBY_GRID_MAX_NUM_ELEMENTS];   /*!< U15. Average level of B color for each grid block with high resolution. */
    uint16_t g_avg[BXT_HDR_RGBY_GRID_MAX_NUM_ELEMENTS];   /*!< U15. Average level of (GR+GB)/2 color for each grid block with high resolution. */
    uint16_t y_avg[BXT_HDR_RGBY_GRID_MAX_NUM_ELEMENTS];   /*!< U15. Average level of Y (luminance) for each grid block with high resolution. */
} ia_isp_bxt_hdr_rgby_grid_t;

/*!
 * \brief Y (luminance) V (Value in HSV color space) grids of data which may be compressed or not based on sensor and ISP pipe type.
 * Named as DRCStatY/V in ISP Firmware.
 * If statistics are compressed, information for decompression is described in structure ia_isp_bxt_hdr_compression_property_t.
*/
typedef struct
{
    ia_isp_bxt_statistics_header_t header;                      /*!< Header data. */
    int32_t grid_width;                                         /*!< The actual grid width. Specifies the amount of valid data in the below arrays. */
    int32_t grid_height;                                        /*!< The actual grid height. Specifies the amount of valid data in the below arrays. */
    uint16_t v_max[BXT_HDR_RGBY_GRID_MAX_NUM_ELEMENTS];   /*!< U15.v_max = max(R,G,B) in HSV color space. Compressed or not based on sensor type. */
    uint16_t y_avg[BXT_HDR_RGBY_GRID_MAX_NUM_ELEMENTS];   /*!< U15.y_avg is same data as the y_avg in ia_isp_bxt_hdr_rgby_grid_t, but sub-sampled by 2x. */
} ia_isp_bxt_hdr_yv_grid_t;

typedef struct
{
    int32_t vec_fe_x_pos;
    int32_t vec_fe_y_pos;
    int32_t vec_fm_x_pos;
    int32_t vec_fm_y_pos;
    int32_t harris_grade;
    int32_t match_grade;
    int32_t level;
} ia_isp_bxt_dvs_motion_vector_entry_t;

typedef struct
{
    ia_isp_bxt_statistics_header_t header;                                          /*!< Header data. */
    int32_t grid_width_l0;                                                          /*!< The actual grid width. Specifies the amount of valid data in the below arrays. */
    int32_t grid_height_l0;                                                         /*!< The actual grid height. Specifies the amount of valid data in the below arrays. */
    int32_t grid_width_l1;                                                          /*!< The actual grid width. Specifies the amount of valid data in the below arrays. */
    int32_t grid_height_l1;                                                         /*!< The actual grid height. Specifies the amount of valid data in the below arrays. */
    int32_t grid_width_l2;                                                          /*!< The actual grid width. Specifies the amount of valid data in the below arrays. */
    int32_t grid_height_l2;                                                         /*!< The actual grid height. Specifies the amount of valid data in the below arrays. */
    ia_isp_bxt_dvs_motion_vector_entry_t mv_l0[BXT_DVS_STATS_L0_MAX_NUM_ELEMENTS];  /*!< Motion vectors for L0 grid. */
    ia_isp_bxt_dvs_motion_vector_entry_t mv_l1[BXT_DVS_STATS_L1_MAX_NUM_ELEMENTS];  /*!< Motion vectors for L1 grid. */
    ia_isp_bxt_dvs_motion_vector_entry_t mv_l2[BXT_DVS_STATS_L2_MAX_NUM_ELEMENTS];  /*!< Motion vectors for L2 grid. */
    int32_t reserved;                                                               /*! align to 8. */
} ia_isp_bxt_motion_vectors_t;

typedef struct
{
    ia_isp_bxt_statistics_header_t header;                                          /*!< Header data. */
    int32_t sum_of_diff[BXT_PAF_STATS_GRID_MAX_NUM_ELEMENTS];                       /*!<  Sum of phase differences from blocks. */
}ia_isp_bxt_paf_grid_t;

typedef struct
{
    float32_t r;        /*!< Compensation gain for R */
    float32_t gr;       /*!< Compensation gain for Gr */
    float32_t gb;       /*!< Compensation gain for Gb */
    float32_t b;        /*!< Compensation gain for B */
    float32_t isp;      /*!< Compensation gain to be used as ISP gain in the pipeline */
} ia_isp_bxt_ir_compgain_t;

#endif /* IA_ISP_BXT_STATISTICS_TYPES_H_ */
