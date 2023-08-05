/*
 * Copyright 2016-2018 Intel Corporation
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
 * \file ia_ltm_types.h
 * \brief Definitions of input/output structures of the Intel local tone mapping library.
 */

#ifndef _IA_LTM_TYPES_H_
#define _IA_LTM_TYPES_H_

#include "ia_types.h"
#include <stdint.h>
#include "ia_isp_bxt_statistics_types.h"

#define GTM_LUT_SIZE 32
#define GCE_DEFOG_LUT_SIZE 64
#define NUM_TONE_MAP_PWL_SEGMENTS 7   /*!< Local curves in piece-wise-linear form (7 pieces)*/
#define MAX_LUT_WIDTH   145
#define MAX_LUT_HEIGHT  500
#define MAX_NUM_LUT 500           /*!< Max. possible number of grids in GammaStar (25 x 20) */

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ia_ltm_t ia_ltm;

/*!
 * \brief New struct for LTM/DRC (local tone mapping/dynamic range compression),
 * LTM is a algorithm for local tone mapping when sensor is in HDR mode
 * LTM/DRC analysis algorithm is in CPU, applying LTM is a FW block called gamma.
 */
typedef enum
{
    ia_ltm_level_use_tuning = -1,      /*!< Use LTM level defined in the tuning. */
    ia_ltm_level_bypass = 0,           /*!< Bypass LTM (DRC) */
} ia_ltm_level;

/*!
 * \brief Input image for LTM calculations.
 */
typedef struct
{
    ia_image_full_info image_info;     /*!< Structure defining given image format, size and other characteristics. */
    const ia_binary_data *image_data;  /*!< Input image buffer format, layout and size depends of width & height (and other paddings) defined in image_info structure above. */
} ia_ltm_input_image;

/*!
 * \brief struct to hold LTM LUTs
 * Local curves in pwl format as needed by GammaStar
 * x & y indexes, slopes for each linear piece
 */
typedef struct ia_ltm_lut
{
    uint16_t points_x[NUM_TONE_MAP_PWL_SEGMENTS + 1]; /* UQ0.15 + 2^15(offset) */
    uint16_t slopes_a[NUM_TONE_MAP_PWL_SEGMENTS];     /* UQ8.8 */
    uint16_t points_y[NUM_TONE_MAP_PWL_SEGMENTS];     /* UQ0.15 */
} ia_ltm_lut;

/*!
 * \brief struct to hold LTM results
 * - Local LUTs
 * - Number of blocks in each dimension
 * - Average local gain (An estimate of overall local gains to be applied is needed for accurate denoising)
 */
typedef struct ia_ltm_results
{
    ia_ltm_lut ltm_luts[MAX_NUM_LUT];   /*!< Local look-up-tables */
    int grid_width;                     /*!< Grid width of LTM LUTs. */
    int grid_height;                    /*!< Grid height of LTM LUTs. */
    int block_size;                     /*!< Block size (width & height in pixels) to which LTM LUTs are applied. */
    float ltm_gain;                     /*!< LTM gain. */
    float dynamic_range;                /*!< Estimated scene's dynamic range from 0 to 100.  Scene has wider dynamic range when this gets closer to 100.
                                        Currently only Optibright outputs this value and this would be zero always for all other LTM algorithms. */
} ia_ltm_results;

/*!
 * \brief GTM parameters for DRC.
 */

typedef struct ia_ltm_gce_defog
{
    int32_t offset_vec[GCE_DEFOG_LUT_SIZE]; /* U15 */
    int32_t slope_vec[GCE_DEFOG_LUT_SIZE];  /* S15 */
    int32_t x_cord_vec[GCE_DEFOG_LUT_SIZE]; /* U15 */
    int32_t x_cord_max;                     /* U15 */
    int32_t exponent;                       /* U4  */
    int32_t resolution;                     /* U4  */
    int32_t A0;
    int32_t A1;
    int32_t ltm_bypass;
    int32_t ltm_weight;                     /* U15 */
    int32_t defog_enable;
    int32_t defog_enhance;
} ia_ltm_gce_defog;

typedef struct ia_ltm_drc_gtm
{
    unsigned short gtm_bypass;
    unsigned short xcu_gtm_offset_vec[GTM_LUT_SIZE];
    short xcu_gtm_slope_vec[GTM_LUT_SIZE];
    unsigned short xcu_gtm_x_cord_vec[GTM_LUT_SIZE];
    unsigned short xcu_gtm_x_cord_max;
    unsigned short xcu_gtm_exponent;
    unsigned short xcu_gtm_slope_resolution;
    unsigned short gtm_gain_frac_bit;
} ia_ltm_drc_gtm;

/*!
 * \brief LTM results from algorithms, passing to DRC in IPU4i HDR pipe.
 */

typedef struct ia_ltm_drc_params
{
    unsigned short gain_map[BXT_HDR_RGBY_GRID_MAX_NUM_ELEMENTS];    /*!< U15.gain_map is upscaled by bilateral, applied to pixel-to-pixel in DRC FW block. */
    unsigned short weight_map[BXT_HDR_RGBY_GRID_MAX_NUM_ELEMENTS];  /*!< U15.weight_map is for computing similarity inside DRC FW block. */
    ia_ltm_drc_gtm drc_gtm;                                         /*! GTM parameters. */
    ia_ltm_gce_defog gce_defog;                                     /*! GCE/DEFOG parameters. */
} ia_ltm_drc_params;

/*!
 * \brief GTM parameters for GTM part of LTM.
 * If GTM is applied inside LTM this structure is used for passing arguments to GTM. In case that GTM is applied
 * inside LTM, GBCE and GammaTM ISP block should be disabled.
 */
typedef struct
{
    float manual_gain;                  /*!< Mandatory. Manual gain. -1.0 if NA */
    float manual_convergence_time;      /*!< Mandatory. Manual brightness convergence speed in seconds. -1.0 if NA. */
    unsigned long long frame_timestamp; /*!< Mandatory. Current time stamp in micro seconds. */
} ia_ltm_gtm_input_params;

#ifdef __cplusplus
}
#endif

#endif /* _IA_LTM_TYPES_H_ */
