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
 * \file ia_cmc_types.h
 * \brief Definitions of Camera Module Characterization (CMC) records.
*/

#ifndef IA_CMC_TYPES_H_
#define IA_CMC_TYPES_H_

#include "ia_mkn_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* All CMC records are inside AIQB record in CPFF file. */
#define AIQB_TAG IA_MKN_CHTOUL('A','I','Q','B')  /*!< AIQ configuration block tag. */

/*
 * Color Channels (1-4) refer to Raw Bayer quad in the following order.
 * -------------
 * | CC1 | CC2 |
 * -------------
 * | CC3 | CC4 |
 * -------------
 *
 * Structures defined in this header file, which are stored into memory/file must start from 64 bit boundary (for 64 bit systems).
 * Keep in mind also structures' internal padding when defining new structures.
 */
#define CMC_NUM_CHANNELS 4
#define VERSION_LEN 16

typedef struct
{
    uint16_t cc1;
    uint16_t cc2;
    uint16_t cc3;
    uint16_t cc4;
} cmc_color_channels;

/*!
 * \brief CIE x and Y coordinates.
 */
typedef struct
{
    uint16_t x;
    uint16_t y;
} cie_coords_t;

/*!
 * \brief R/G and B/G ratios.
 */
typedef struct
{
    uint16_t r_per_g;
    uint16_t b_per_g;
} chromaticity_t;

/*!
 * \brief Physical pixel coordinates.
 */
typedef struct
{
    uint16_t x;
    uint16_t y;
} cmc_coords;

/*!
 * \brief Chromaticity coordinates in CIE 1931 space.
 */
typedef struct
{
    float x;
    float y;
} cmc_cie_coords;

/*!
 * \brief Chromaticity coordinates in R/G & B/G space.
 */
typedef struct
{
    float r_per_g;
    float b_per_g;
} cmc_chromaticity;

/*!
* \brief 3x3 color matrix.
*/
typedef struct
{
    float matrix[3][3];                 /*!< 3x3 accurate CCM, each consequtive elements sum to 1. */
} cmc_color_matrix;

/*!
 * \brief Raw image bayer order.
 */
typedef enum
{
    cmc_bayer_order_2x2,                            /*!< Start of enumerations for 2x2 bayer types. */
    cmc_bayer_order_grbg = cmc_bayer_order_2x2,     /*!< First row contains pixels Gr, R. Second row contains pixels B, Gb. */
    cmc_bayer_order_rggb,                           /*!< First row contains pixels R, Gr. Second row contains pixels Gb, B. */
    cmc_bayer_order_bggr,                           /*!< First row contains pixels B, Gb. Second row contains pixels Gr, R. */
    cmc_bayer_order_gbrg,                           /*!< First row contains pixels Gb, B. Second row contains pixels R, Gr. */
    cmc_bayer_order_grbi,                           /*!< First row contains pixels Gr, R. Second row contains pixels B, IR. */
    cmc_bayer_order_irbg,                           /*!< First row contains pixels IR, R. Second row contains pixels B, Gb. */
    cmc_bayer_order_rgib,                           /*!< First row contains pixels R, Gr. Second row contains pixels IR, B. */
    cmc_bayer_order_rigb,                           /*!< First row contains pixels R, IR. Second row contains pixels Gb, B. */
    cmc_bayer_order_bgir,                           /*!< First row contains pixels B, Gb. Second row contains pixels IR, R. */
    cmc_bayer_order_bigr,                           /*!< First row contains pixels B, IR. Second row contains pixels Gr, R. */
    cmc_bayer_order_gbri,                           /*!< First row contains pixels Gb, B. Second row contains pixels R, IR. */
    cmc_bayer_order_ibrg,                           /*!< First row contains pixels IR, B. Second row contains pixels R, Gr. */
    cmc_bayer_order_4x2 = 128,                      /*!< Start of enumerations for 4x2 bayer types. */
    cmc_bayer_order_2pd_grbg = cmc_bayer_order_4x2, /*!< Two photodiodes per pixel in Gr, R, B, Gb order (4x2). */
    cmc_bayer_order_2pd_rggb,                       /*!< Two photodiodes per pixel in R, Gr, Gb, B order (4x2). */
    cmc_bayer_order_2pd_bggr,                       /*!< Two photodiodes per pixel in B, Gb, Gr, R order (4x2). */
    cmc_bayer_order_2pd_gbrg,                       /*!< Two photodiodes per pixel in Gb, B, R, Gr order (4x2). */
    cmc_bayer_order_4x4 = 256,                      /*!< Start of enumerations for 4x4 bayer types. */
    cmc_bayer_order_bgrg_gigi_rgbg_gigi = cmc_bayer_order_4x4, /*!< Order: 1st row: B G R G, 2nd row: G I G I, 3rd row: R G B G, 4th row: G I G I (4x4). */
    cmc_bayer_order_grgb_igig_gbgr_igig,                       /*!< Order: 1st row: G R G B, 2nd row: I G I G, 3rd row: G B G R, 4th row: I G I G (4x4). */
    cmc_bayer_order_rgbg_gigi_bgrg_gigi,                       /*!< Order: 1st row: R G B G, 2nd row: G I G I, 3rd row: B G R G, 4th row: G I G I (4x4). */
    cmc_bayer_order_gbgr_igig_grgb_igig,                       /*!< Order: 1st row: G B G R, 2nd row: I G I G, 3rd row: G R G B, 4th row: I G I G (4x4). */
    cmc_bayer_order_gigi_rgbg_gigi_bgrg,                       /*!< Order: 1st row: G I G I, 2nd row: R G B G, 3rd row: G I G I, 4th row: B G R G (4x4). */
    cmc_bayer_order_igig_gbgr_igig_grgb,                       /*!< Order: 1st row: I G I G, 2nd row: G B G R, 3rd row: I G I G, 4th row: G R G B (4x4). */
    cmc_bayer_order_gigi_bgrg_gigi_rgbg,                       /*!< Order: 1st row: G I G I, 2nd row: B G R G, 3rd row: G I G I, 4th row: R G B G (4x4). */
    cmc_bayer_order_igig_grgb_igig_gbgr                        /*!< Order: 1st row: I G I G, 2nd row: G R G B, 3rd row: I G I G, 4th row: G B G R (4x4). */
} cmc_bayer_order;

/*!
 * \brief Color space definitions.
 */
typedef enum
{
    cmc_color_space_srgb,
    cmc_color_space_bt601,
    cmc_color_space_bt709,
    cmc_color_space_bt2020,
    cmc_color_space_bt2100_rgb,
    cmc_color_space_bt2100_lms,
    cmc_color_space_dci_p3,
    cmc_color_space_adobergb,
} cmc_color_space;

/*!
 * \brief CMC names used in the record headers.
 */
typedef enum
{
    cmc_name_id_reserved = 0,                            /*!< 00 */
    cmc_name_id_comment,                                 /*!< 01 */
    cmc_name_id_general_data,                            /*!< 02 */
    cmc_name_id_black_level,                             /*!< 03 */
    cmc_name_id_black_level_spatial,                     /*!< 04 */
    cmc_name_id_saturation_level,                        /*!< 05 */
    cmc_name_id_dynamic_range_and_linearity,             /*!< 06 */
    cmc_name_id_module_sensitivity,                      /*!< 07 */
    cmc_name_id_defect_pixels,                           /*!< 08 */
    cmc_name_id_noise,                                   /*!< 09 */
    cmc_name_id_lens_shading_correction,                 /*!< 10 */
    cmc_name_id_lens_shading_correction_ratio,           /*!< 11 */
    cmc_name_id_geometric_distortion_correction,         /*!< 12 */
    cmc_name_id_optics_and_mechanics,                    /*!< 13 */
    cmc_name_id_module_spectral_response,                /*!< 14 */
    cmc_name_id_chromaticity_response,                   /*!< 15 */
    cmc_name_id_flash_chromaticity,                      /*!< 16 */
    cmc_name_id_nvm_info,                                /*!< 17 */
    cmc_name_id_color_matrices,                          /*!< 18 */
    cmc_name_id_analog_gain_conversion,                  /*!< 19 DEPRECATED */
    cmc_name_id_digital_gain,                            /*!< 20 */
    cmc_name_id_sensor_metadata,                         /*!< 21 */
    cmc_name_id_geometric_distortion_correction2,        /*!< 22 */
    cmc_name_id_exposure_range,                          /*!< 23 */
    cmc_name_id_multi_led_flash_chromaticity,            /*!< 24 */
    cmc_name_id_advanced_color_matrices,                 /*!< 25 */
    cmc_name_id_hdr,                                     /*!< 26 */
    cmc_name_id_infrared_correction,                     /*!< 27 */
    cmc_name_id_lens_shading_correction_4x4,             /*!< 28 */
    cmc_name_id_lateral_chromatic_aberration_correction, /*!< 29 */
    cmc_name_id_phase_difference,                        /*!< 30 */
    cmc_name_id_black_level_global,                      /*!< 31 */
    cmc_name_id_valid_image_area,                        /*!< 32 */
    cmc_name_id_lens_shading_correction_4x4_ratio,       /*!< 33 */
    cmc_name_id_multi_gain_conversions,                  /*!< 34 */
    cmc_name_id_pipe_comp_decomp,                        /*!< 35 */
    cmc_name_id_sensor_decomp,                           /*!< 36 */
} cmc_name_id;

/*!
 * \brief Camera features flags (see cmc_optomechanics_t.camera_features).
 * Bit '1' means that the feature is presented.
 */
typedef enum {
    cmc_camera_feature_lens_position_sensor        = 1U,            /*!< Physical Lens Position sensor */
    cmc_camera_feature_voice_coil_actuator         = (1U << 1U),     /*!< 'Voice Coil' type of lens actuator */
    cmc_camera_feature_hybrid_voice_coil_actuator  = (1U << 2U),     /*!< 'Hybrid Voice Coil' type of lens actuator */
    cmc_camera_feature_piezo_actuator              = (1U << 3U),     /*!< 'Piezo' type of lens actuator */
    cmc_camera_feature_mems_actuator               = (1U << 4U),     /*!< 'MEMS' type of lens actuator */
    cmc_camera_feature_nd_filter                   = (1U << 5U),     /*!< Neutral Density filter */
    cmc_camera_feature_mechanical_shutter          = (1U << 6U),     /*!< Mechanical Shutter */
    cmc_camera_feature_variable_apertures          = (1U << 7U),     /*!< Variable Apertures */
    cmc_camera_feature_optical_zoom                = (1U << 8U)      /*!< Optical Zoom */
} cmc_camera_feature;

/*!
 * \brief Camera module orientation
 */
typedef enum {
    cmc_camera_orientation_down = 0,            /*!< Camera module is pointing down */
    cmc_camera_orientation_horizontally,        /*!< Camera module is pointing horizontally */
    cmc_camera_orientation_up                   /*!< Camera module is pointing up */
} cmc_camera_orientation;

/*!
 * \brief LSC level enumeration.
 */
typedef enum {
    cmc_lsc_force_first_grid = 0,           /*!< Use always first LSC grid */
    cmc_lsc_without_nvm,                    /*!< Use LSC adaptation without NVM */
    cmc_lsc_with_nvm                        /*!< Use LSC adaptation with NVM */
} cmc_lsc_level;

/*!
 * \brief Shading Adaptor Level enumeration.
 */
typedef enum {
    cmc_sa_disable = 0,                     /*!< Do not apply shading tables (bypass LSC) */
    cmc_sa_cct_based,                       /*!< Use CCT based LSC selection */
    cmc_sa_adaptive,                        /*!< Use adaptive LSC selection */
    cmc_sa_self_adjusting                   /*!< Use module variation correcting LSC */
} cmc_sa_level;

/*!
 * \brief Light source enumeration
 */
typedef enum {
    cmc_light_source_none = 0,           /*!< Light source N/A */
    cmc_light_source_a,                  /*!< Incandescent / Tungsten */
    cmc_light_source_b,                  /*!< Obsolete. Direct sunlight at noon */
    cmc_light_source_c,                  /*!< Obsolete. Average / north sky daylight */
    cmc_light_source_d50,                /*!< Horizon light. ICC profile PCS */
    cmc_light_source_d55,                /*!< Mid-morning / mid-afternoon daylight */
    cmc_light_source_d65,                /*!< Noon daylight. Television, sRGB color space */
    cmc_light_source_d75,                /*!< North sky daylight */
    cmc_light_source_e,                  /*!< Equal energy */
    cmc_light_source_f1,                 /*!< Daylight fluorescent */
    cmc_light_source_f2,                 /*!< Cool white fluorescent */
    cmc_light_source_f3,                 /*!< White fluorescent */
    cmc_light_source_f4,                 /*!< Warm white fluorescent */
    cmc_light_source_f5,                 /*!< Daylight fluorescent */
    cmc_light_source_f6,                 /*!< Lite white fluorescent */
    cmc_light_source_f7,                 /*!< D65 simulator, daylight simulator */
    cmc_light_source_f8,                 /*!< D50 simulator, Sylvania F40 Design 50 */
    cmc_light_source_f9,                 /*!< Cool white deluxe fluorescent */
    cmc_light_source_f10,                /*!< Philips TL85, Ultralume 50 */
    cmc_light_source_f11,                /*!< Philips TL84, Ultralume 40 */
    cmc_light_source_f12,                /*!< Philips TL83, Ultralume 30 */
    cmc_light_source_hz,                 /*!< Horizon IR */
    cmc_light_source_a_md,               /*!< A - Incandescent / Tungsten Medium light */
    cmc_light_source_a_lw,               /*!< A - Incandescent / Tungsten Low light */
} cmc_light_source;
#define CMC_NUM_LIGHTSOURCES 24u

/*!
 * \brief PD sensor type enumeration.
 */
typedef enum {
    cmc_pd_sensor_type_non_pd = 0,        /*!< Non-PD sensor */
    cmc_pd_sensor_type_1,                 /*!< Type 1 (All processing done on sensor) */
    cmc_pd_sensor_type_2,                 /*!< Type 2 (PD extraction on sensor, statistics processing in IPU) */
    cmc_pd_sensor_type_3                  /*!< Type 3 (All processing done in IPU) */
} cmc_pd_sensor_type;

/*!
 * \brief PD technology type enumeration.
 */
typedef enum {
    cmc_pd_technology_type_metal_shield = 0,        /*!< Metal shield-based PD */
    cmc_pd_technology_type_dual_photodiode,         /*!< Dual photodiode-based PD */
    cmc_pd_technology_type_wide_microlens           /*!< Wide microlens-based PD */
} cmc_pd_technology_type;

/*!
 * \brief CMC gdc mode type enumeration.
 */
typedef enum {
    cmc_gdc_mode_grid,    /*!< CMC GDC Grid mode */
    cmc_gdc_mode_lut,     /*!< CMC GDC Look-up Table mode */
    cmc_gdc_mode_extlut   /*!< CMC GDC Look-up Table from External Tool mode */
} cmc_gdc_mode_type;

/*!
 * \brief CMC Comment
 */
typedef struct
{
    ia_mkn_record_header header; /*!< Record header with Format ID: UInt8 (See AIQB_DataID), Name ID: cmc_name_id_comment (See cmc_name_id). */
    uint8_t project_id[VERSION_LEN];      /*!< NULL terminated Project ID string. Date format: yymmddHHMMSSFFF. For example: 1202201823444. */
/*    uint8_t comment[];          / *!< Free C string text comment (NULL terminated). Must end at 64 bit alignment. * / */
} cmc_comment_t;
#define SIZEOF_CMC_COMMENT_T 24UL

/*!
 * \brief CMC General Data
 */
typedef struct
{
    ia_mkn_record_header header;        /*!< Record header with Format ID: Uint16 (See AIQB_DataID) Name ID: cmc_name_id_general_data. (enum cmc_name_id). */
    uint16_t width;                     /*!< Sensor native maximum width. */
    uint16_t height;                    /*!< Sensor native maximum height. */
    uint16_t bit_depth;                 /*!< Sensor native maximum bit depth (after sensor linearization). For HDR sensor, this is the bit depth after stitching. */
    uint16_t color_order;               /*!< Sensor color order in native orientation. */
    uint16_t bit_depth_packed;          /*!< Sensor native maximum bit depth (before sensor linearization = packed) . */
    uint8_t sve_pattern[16];            /*!< 4x4 pixel pattern. 0 means shortest exposure time and n the longest. */
    uint16_t single_exposure_bit_depth; /*!< Sensor native maximum bit depth for single (non-stitched) exposure. */
} cmc_general_data_t;
#define SIZEOF_CMC_GENERAL_DATA_V100_T 16
#define SIZEOF_CMC_GENERAL_DATA_V101_T 18
#define SIZEOF_CMC_GENERAL_DATA_V102_T 34
#define SIZEOF_CMC_GENERAL_DATA_V103_T 36

/*!
 * \brief CMC Black Level
 * - Global black level compensation.
 */
typedef struct
{
    uint32_t exposure_time;              /*!< Exposure time. */
    uint32_t analog_gain;                /*!< Analog gain. */
    cmc_color_channels color_channels;     /*!< Color channel correction for given exposure time and analog gain. */
} cmc_black_level_lut_t;
#define SIZEOF_CMC_BLACK_LEVEL_LUT_T 16U

typedef struct
{
    ia_mkn_record_header header;     /*!< Record header with Format ID: Custom (See AIQB_DataID) Name ID: cmc_name_id_black_level. (enum cmc_name_id). */
    uint32_t num_bl_luts;            /*!< Number of black level lookup tables (number of analog gain * number of exposures).  */
/*    cmc_black_level_lut_t bl_luts[]; / *!< Lookup tables for black level correction. * / */
} cmc_black_level_t;
#define SIZEOF_CMC_BLACK_LEVEL_T 12U

/*!
* \brief CMC for global black Level
* - Global black level compensation for 4x4 sensors.
*/
typedef struct
{
    uint32_t exposure_time;         /*!< Exposure time in microseconds. */
    float total_gain;               /*!< Total gain (including both analog and digital gains). */
    float black_level[4][4];        /*!< Black level correction for given exposure time and total gain. */
} cmc_black_level_values;

typedef struct
{
    ia_mkn_record_header header;             /*!< Record header with Format ID: UInt16 (See AIQB_DataID), Name ID: cmc_name_id_black_level_global (See cmc_name_id). */
    uint32_t num_bl_luts;                    /*!< Number of black level lookup tables (number of analog gain * number of exposures).  */
    uint32_t padding;                        /* Ensures that next 64 bit variable starts from 64 bit boundary. */
    union {
        cmc_black_level_values *ptr;         /*!< Array of global black level values as function of exposure time and gain. Array length is defined by num_bl_luts. */
        uint64_t dummy;                      /* Ensures that pointer is accessible in both 32 and 64 bit systems. */
    } bl_values;
} cmc_black_level_global;

/*!
 * \brief CMC Saturation Level
 * - Defined for each color channels.
 * - Absolute pixel values using native max bit depth.
 */
typedef struct
{
    ia_mkn_record_header header; /*!< Record header with Format ID: UInt16 (See AIQB_DataID) Name ID: cmc_name_id_saturation_level. (enum cmc_name_id). */
    uint16_t saturation_cc1;     /*!< Saturation level of 1st color channel. */
    uint16_t saturation_cc2;     /*!< Saturation level of 2nd color channel. */
    uint16_t saturation_cc3;     /*!< Saturation level of 3rd color channel. */
    uint16_t saturation_cc4;     /*!< Saturation level of 4th color channel. */
} cmc_saturation_level_t;
#define SIZEOF_CMC_SATURATION_LEVEL_T 16

/*!
 * \brief CMC Pixel Dynamic Range And Linearity
 */
typedef struct
{
    ia_mkn_record_header header; /*!< Record header with Format ID: Custom (See AIQB_DataID) Name ID: cmc_name_id_dynamic_range_and_linearity. (enum cmc_name_id). */
    uint32_t dynamic_range;      /*!< Pixel dynamic range in dB. */
    uint8_t num_linearity_cc1;   /*!< Number of points in color channel 1 linearity lookup table. */
    uint8_t num_linearity_cc2;   /*!< Number of points in color channel 2 linearity lookup table. */
    uint8_t num_linearity_cc3;   /*!< Number of points in color channel 3 linearity lookup table. */
    uint8_t num_linearity_cc4;   /*!< Number of points in color channel 4 linearity lookup table. */
/*    uint16_t lut_linearities[]; / *!< Linearity lookup table for color channels in order: Ch1, Ch2, Ch3 and Ch4. * / */
} cmc_linearity_t;
#define SIZEOF_CMC_LINEARITY_T 16U

/*!
 * \brief CMC Module Sensitivity
 */
typedef struct
{
    ia_mkn_record_header header; /*!< Record header with Format ID: UInt16 (See AIQB_DataID), Name ID: cmc_name_id_module_sensitivity (See cmc_name_id). */
    uint16_t base_iso;           /*!< Base ISO value of the camera module. */
} cmc_sensitivity_t;
#define SIZEOF_CMC_SENSITIVITY_T 10

/*!
 * \brief CMC Defect Pixels
 */
typedef struct
{
    ia_mkn_record_header header; /*!< Record header with Format ID: ??? (See AIQB_DataID), Name ID: cmc_name_id_defect_pixels (See cmc_name_id). */
    uint16_t not_defined;        /*!<  */
} cmc_defect_pixel_t;
#define SIZEOF_CMC_DEFECT_PIXEL_T 10

/*!
 * \brief CMC Noise
 */
typedef struct
{
    ia_mkn_record_header header;       /*!< Record header with Format ID: Float (See AIQB_DataID), Name ID: cmc_name_id_noise (See cmc_name_id). */
    float noise_model_coefficients[5]; /*!< Noise model coefficients (c1..5) in equation y = c1*x^2 + Gain*c2*x + Gain^2*c3 + Gain*c4 + c5.
                                            Gain is sum of gain applied to pixel (DG and AG), x is the normalized mean (pixel value), and y is the variance. */
    int reserved;                      /*!< Reserved for alignment. Always 0. */
} cmc_noise;

typedef struct
{
    uint16_t source_type;      /*!< Light source type (enum), e.g. Fluorescent. */
    uint16_t correction_level; /*!< Luminance correction level. */
    cie_coords_t cie_coords;   /*!< CIE x and y coordinates. */
/*    uint16_t lsc_grid[];       / *!< LSC Grid. * / */
} cmc_lsc_grid_t;
#define SIZEOF_CMC_LSC_GRID_T 8U

/*!
 * \brief CMC_Lens Shading Correction
 * - Full native FOV
 * - Absolute gain values
 * - 100% color shading correction
 * - x% grid "divided by" NVM_calibration_grid (=ratio) - if no NVM use ones
 */
typedef struct
{
    ia_mkn_record_header header; /*!< Record header with Format ID: Custom (See AIQB_DataID), Name ID: cmc_name_id_lens_shading_correction (See cmc_name_id). */
    uint16_t lsc_level;          /*!< LSC level enumeration. */
    uint16_t num_grids;          /*!< Number of LSC grids. */
    uint16_t grid_width;         /*!< LSC Grid width. */
    uint16_t grid_height;        /*!< LSC Grid height. */
/*  cmc_lsc_grid_t lsc_grids[]; / *!< LSC grids. * / */
} cmc_lens_shading_t;
#define SIZEOF_CMC_LENS_SHADING_T 16U

typedef struct
{
    uint16_t pair_index;       /*!< Calibration light source pair index. */
    uint16_t source_type;      /*!< Light source type (enum), e.g. Fluorescent. */
    uint16_t correction_level; /*!< Luminance correction level. */
    cie_coords_t cie_coords;   /*!< CIE x and y coordinates. */
/*    uint16_t lsc_grid[];       / *!< LSC Grid. * / */
} cmc_lsc_ratio_grid_t;
#define SIZEOF_CMC_LSC_RATIO_GRID_T 10U

/*!
 * \brief Lens Shading Correction Ratio
 */
typedef struct
{
    ia_mkn_record_header header;      /*!< Record header with Format ID: Custom (See AIQB_DataID), Name ID: cmc_name_id_lens_shading_correction_ratio (See cmc_name_id). */
    uint16_t num_grids;               /*!< Number of LSC grids. */
    uint16_t grid_width;              /*!< LSC Grid width. */
    uint16_t grid_height;             /*!< LSC Grid height. */
/*    cmc_lsc_ratio_grid_t lsc_grids[]; / *!< LSC grids. * / */
} cmc_lens_shading_ratio_t;
#define SIZEOF_CMC_LENS_SHADING_RATIO_T 14U

/*!
 * \brief CMC Geometric Distortion Correction
 */
typedef struct
{
    ia_mkn_record_header header; /*!< Record header with Format ID: Float (See AIQB_DataID), Name ID: cmc_name_id_geometric_distortion_correction (See cmc_name_id). */
    float gdck1;                 /*!<  1st order radial distortion coefficient. */
    float gdck2;                 /*!<  2nd order radial distortion coefficient. */
    float gdck3;                 /*!<  3rd order radial distortion coefficient. */
    float gdcp1;                 /*!<  1st order tangential distortion coefficient. */
    float gdcp2;                 /*!<  2nd order tangential distortion coefficient. */
} cmc_geometric_distortion_t;
#define SIZEOF_CMC_GEOMETRIC_DISTORTION_T 28

/*!
 * \brief CMC Optics and Mechanics
 */
typedef struct
{
    ia_mkn_record_header header;                         /*!< Record header with Format ID: UInt16 (See AIQB_DataID), Name ID: cmc_name_id_optics_and_mechanics (See cmc_name_id). */
    uint8_t actuator;                                    /*!< Actuator type (enum). */
    uint8_t camera_module_orientation;                   /*!< Camera module orientation during the AF calibration (enum from Camera Module Orientation). */
    uint16_t camera_actuator_features;                   /*!< Camera features list (flags from cmc_camera_feature enumeration). */
    uint16_t nd_gain;                                    /*!< Neutral density filter gain. */
    uint16_t effect_focal_length;                        /*!< Effective Focal Length, (mm * 100). */
    uint16_t sensor_pix_size_v;                          /*!< Sensor pixel size Vertical, (um * 100). */
    uint16_t sensor_pix_size_h;                          /*!< Sensor pixel size Horizontal, (um * 100). */
    uint16_t sensor_width_pix_total;                     /*!< Sensor width in pixels, total. */
    uint16_t sensor_height_pix_total;                    /*!< Sensor height in pixels, total. */
    uint16_t lens_offset_up_to_horz;                     /*!< Lens displacement when module turns from Up to Horizontal, (um). */
    uint16_t lens_offset_horz_to_down;                   /*!< Lens displacement when module turns from Horizontal to Down, (um). */
    uint16_t range_inf_to_85mm;                          /*!< Optical range 'Inf - 8.5 cm', (um). */
    uint16_t range_inf_to_100mm;                         /*!< Optical range 'Inf - 10 cm', (um). */
    uint16_t range_inf_to_300mm;                         /*!< Optical range 'Inf - 30 cm', (um). */
    uint16_t range_inf_to_500mm;                         /*!< Optical range 'Inf - 50 cm', (um). */
    uint16_t range_inf_to_950mm;                         /*!< Optical range 'Inf - 95 cm', (um). */
    uint16_t range_inf_to_1200mm;                        /*!< Optical range 'Inf - 120 cm', (um). */
    uint16_t range_inf_to_hyperfocal;                    /*!< Optical range 'Inf - Hyperfocal', (um). */
    uint16_t range_inf_to_calibration_distance_far;      /*!< Optical range 'Inf - calibration distance far', (um). */
    uint16_t range_inf_to_calibration_distance_near;     /*!< Optical range 'Inf - calibration_distance_near', (um). */
    uint16_t range_inf_to_min_focusing_distance;         /*!< Optical range 'Inf - calibration_distance_near', (um). */
    uint16_t calibration_distance_far;                   /*!< Distance to supplier's FAR production calibration target, (cm). */
    uint16_t calibration_distance_near;                  /*!< Distance to supplier's NEAR production calibration target, (cm). */
    int16_t calibration_position_far;                    /*!< Supplier's FAR production calibration target in ACTUATOR UNITS, default (used in case NVM is not available).*/
    int16_t calibration_position_near;                   /*!< Supplier's NEAR production calibration target in ACTUATOR UNITS,  default (used in case NVM is not available).*/
    int32_t lens_range_limit;                            /*!< Maximum available value for the lens actuator. */
    int32_t lens_actuator_offset;                        /*!< Permanent offset to lens actuator values. */
    uint32_t lens_movement_time;                         /*!< Time (in us) needed to move the lens per single VC unit (if linear_lens_movement_time is 1). Total time needed per one lens move (if linear_lens_movement_time is 0)*/
    uint16_t min_focus_distance;                         /*!< Minimum focusing distance, (cm). */
    uint16_t num_apertures;                              /*!< Actual number of apertures, presented in camera. */
} cmc_optomechanics_t;
#define SIZEOF_CMC_OPTOMECHANICS    72U

/*!
 * \brief CMC Module Spectral Response
 */
typedef struct
{
    ia_mkn_record_header header;          /*!< Record header with Format ID: UInt16 (See AIQB_DataID), Name ID: cmc_name_id_module_spectral_response (See cmc_name_id). */
    uint16_t min_wavelength;              /*!< Minimum wave length. */
    uint16_t max_wavelength;              /*!< Maximum wave length. */
    uint16_t wavelength_sampling_rate;    /*!< Wave length sampling rate. */
/*    cmc_color_channels spectral_response[]; / *!< Module spectral response in order: Ch1,Ch2,Ch3 and Ch4. * / */
} cmc_spectral_response_t;
#define SIZEOF_CMC_SPECTRAL_RESPONSE 14U

/*!
 * \brief Lightsource definition.
 */
typedef struct
{
    cie_coords_t cie_coords;           /*!< Light source CIE xy coordinates. */
    chromaticity_t chromaticity_response; /*!< Avg Chromaticity response for R/G anf B/G.*/
} cmc_lightsource_t;
#define SIZEOF_CMC_LIGHTSOURCE_T 8U

/*!
 * \brief CMC Chromaticity Response
 */
typedef struct
{
    ia_mkn_record_header header;      /*!< Record header with Format ID: UInt16 (See AIQB_DataID), Name ID: cmc_name_id_chromaticity_response (See cmc_name_id). */
    uint16_t num_lightsources;        /*!< Number of avg light sources. */
    uint16_t num_nvm_lightsources;    /*!< Number of nvm light sources. */
/*  cmc_lightsource_t lightsources[]; / *!< Lightsources in the order: avg, high and low. * / */
} cmc_chromaticity_response_t;
#define SIZEOF_CMC_CHROMATICITY_RESPONSE 12U

/*!
 *  \brief Flash chromaticity responses for a point.
 */
typedef struct
{
    chromaticity_t flash_chromaticity_response;    /*!< Flash Chromaticity response, R/G and B/G */
} cmc_poly_point_t;
#define SIZEOF_CMC_POLY_POINT_T 4U

/*!
 * \brief CMC Flash Chromaticity
 */
typedef struct
{
    ia_mkn_record_header header;        /*!< Record header with Format ID: UInt16 (See AIQB_DataID), Name ID: cmc_name_id_flash_chromaticity (See cmc_name_id). */
    chromaticity_t flash_avg_chromaticity; /*!< Flash chromaticity in R/G, B/G plane. */
    uint16_t num_poly_points;           /*!< Number of points defining polygon. */
/*    cmc_poly_point_t poly_point[];    / *!< Flash Chromaticity Deviation in R/G, B/G plane. * / */
} cmc_flash_chromaticity_t;
#define SIZEOF_CMC_FLASH_CHROMATICITY_T 14U

typedef struct
{
    cmc_light_source light_src_type; /*!< Light-source type. See enum cmc_light_source.  */
    chromaticity_t chromaticity;     /*!< Chromaticity (sensor) in R/G, B/G plane. */
    cie_coords_t cie_coords;      /*!< CIE x and y coordinates. */
    int32_t matrix_accurate[9];   /*!< 3x3 accurate CCM, each 3 consequtive elemets sum to 1. */
    int32_t matrix_preferred[9];  /*!< 3x3 preferred CCM, each 3 consequtive elemets sum to 1. */
} cmc_color_matrix_t;
#define SIZEOF_CMC_COLOR_MATRIX_T 84U

/*!
 * \brief CMC Color matrices
 */
typedef struct
{
    ia_mkn_record_header header;         /*!< Record header with Format ID: UInt16 (See AIQB_DataID), Name ID: cmc_name_id_color_matrices (See cmc_name_id). */
    uint16_t num_matrices;               /*!< Number of color matrices. */
/*    cmc_color_matrix_t color_matrices[]; / *!< Color matrices. * / */
} cmc_color_matrices_t;
#define SIZEOF_CMC_COLOR_MATRICES_T 10U
/*!
 * \brief CMC NVM Info
 */
typedef struct
{
    ia_mkn_record_header header;      /*!< Record header with Format ID: UInt16 (See AIQB_DataID), Name ID: cmc_name_id_nvm_info (See cmc_name_id). */
    uint16_t nvm_parser_version;      /*!< Parser version for current camera module type */
    uint16_t nvm_data_color_order;    /*!< NVM data color order */
    uint16_t nvm_data_orientation;    /*!< NVM data orientation */
} cmc_nvm_info_t;
#define SIZEOF_CMC_NVM_INFO_T 14

/*!
 * \brief CMC NVM Info v101
 */
typedef struct
{
    uint16_t nvm_scaling_method;        /*!< NVM table scaling method. */
} cmc_nvm_info_v101_t;
#define SIZEOF_CMC_NVM_INFO_V101_T   2U

typedef struct
{
    cmc_nvm_info_t *cmc_nvm_info;           /*!< CMC NVM info data. */
    cmc_nvm_info_v101_t *cmc_nvm_info_v101; /*!< CMC NVM info data v101. */
} cmc_parsed_nvm_info_t;

/*!
 * \brief Analog gain to gain code mapping.
 * Gains must be defined in ascending order.
 */
typedef struct
{
    uint32_t gain;                 /*!< Gain in fixed point format (16bit integer part + 16bit fraction part). */
    uint32_t code;                 /*!< Code corresponding to gain. */
} cmc_analog_gain_pair_t;
#define SIZEOF_CMC_ANALOG_GAIN_PAIR_T 8U

/*!
 * \brief Analog gain to gain code mapping of a segment.
 * Segments contain SMIA analog gain parameters. When ranges is defined, beginning is always inclusive and end exclusive.
 * For example analog gain 2.0 and ranges: [1.0, 2.0[; [2.0, 4.0[;. Analog gain 2.0 is not calculated from the first range parameters but from the second range.
 */
typedef struct
{
    uint32_t gain_begin;         /*!< Begin of gain of the segment (inclusive) in fixed point format (16bit integer part + 16bit fraction part). */
    uint32_t gain_end;           /*!< End of gain of the segment (exclusive) in fixed point format (16bit integer part + 16bit fraction part). */
    uint32_t code_min;           /*!< The minimum recommended setting for the analog gain control. */
    uint32_t code_max;           /*!< The maximum recommended setting for the analog gain control. */
    uint32_t code_step;          /*!< The precision of the analog gain control. */
    int16_t M0;                  /*!< Gain code M0 as in SMIA. */
    int16_t C0;                  /*!< Gain code C0 as in SMIA. */
    int16_t M1;                  /*!< Gain code M1 as in SMIA. */
    int16_t C1;                  /*!< Gain code C1 as in SMIA. */
} cmc_analog_gain_segment_t;
#define SIZEOF_CMC_ANALOG_GAIN_SEGMENT_T 28U

/*!
 * \brief CMC Analog gain conversion types
 * Enum defines different analog gain conversion types.
 */
typedef enum
{
    cmc_analog_gain_conversion_type_none,    /*!< No analog gain conversion should be done. */
    cmc_analog_gain_conversion_type_segment, /*!< Segments contain SMIA compatible parameters for calculating register value for a certain range of analog gain. */
    cmc_analog_gain_conversion_type_pair,    /*!< Pairs contain analog gain value & corresponding register value. */
} cmc_analog_gain_conversion_type_t;

/*!
 * \brief CMC Analog gain conversion table
 * Analog gain can be represented with n amount of gain code (register value) pairs/segments.
 */
typedef struct
{
    ia_mkn_record_header header;         /*!< Record header with Format ID: UInt16 (See AIQB_DataID), Name ID: cmc_name_id_analog_gain_conversion (See cmc_name_id). */
    uint16_t conversion_type;            /*!< Analog gain conversion type.  See cmc_analog_gain_conversion_type_t. */
    uint16_t reserved;                   /*!< Reserved due to byte alignment. */
    uint16_t num_segments;               /*!< Number of gain/code segments which describe the analog gain. */
    uint16_t num_pairs;                  /*!< Number of gain/code pairs which describe the analog gain. */
/*    cmc_analog_gain_segment_t gain_segments[]; */
/*    cmc_analog_gain_pair_t gain_pairs[]; */
} cmc_analog_gain_conversion_t;
#define SIZEOF_CMC_ANALOG_GAIN_CONVERSION_T 16U

/*!
 * \brief CMC Digital gain conversion types
 * Enum defines different digital gain conversion types.
 */
typedef enum
{
    cmc_digital_gain_conversion_type_fixed_point, /*!< Digital gain is defined in fixed point format. */
    cmc_digital_gain_conversion_type_pair,        /*!< Pairs contain digital gain value & corresponding register value. */
} cmc_digital_gain_conversion_type_t;

/*!
 * \brief CMC digital gain limits and step.
 */
typedef struct
{
    ia_mkn_record_header header;         /*!< Record header with Format ID: UInt16 (See AIQB_DataID), Name ID: cmc_name_id_digital_gain (See cmc_name_id). */
    uint16_t digital_gain_min;           /*!< The minimum valid limit of the digital gain control parameters in fixed point format (16bit integer part + 16bit fraction part). */
    uint16_t digital_gain_max;           /*!< The maximum valid limit of the digital gain control parameters in fixed point format (16bit integer part + 16bit fraction part). */
    uint8_t digital_gain_step_size;      /*!< Step size of digital gain code register value. */
    uint8_t digital_gain_fraction_bits;  /*!< Number of bits used for the fraction part of the 16 bit register value. */
/*    cmc_digital_gain_v102_t dg_v102; */
/*    cmc_analog_gain_pair_t dg_pairs[];*/
} cmc_digital_gain_t;
#define SIZEOF_CMC_DIGITAL_GAIN_T 14

/*!
 * \brief Defines additions to digital gain structure with gain/code pairs support.
 */
typedef struct
{
    uint16_t conversion_type;            /*!< Digital gain conversion type.  See cmc_digital_gain_conversion_type_t. */
    uint16_t num_pairs;                  /*!< Number of gain/code pairs which describe the digital gain. */
    uint16_t reserved;                   /*!< Not used at the moment. Reserved to ensure correct (32 bit) alignment. */
} cmc_digital_gain_v102_t;
#define SIZEOF_CMC_DIGITAL_GAIN_V102_T 6U

/*!
 * \brief CMC Sensor exposure registers ranges.
 */
typedef struct
{
    ia_mkn_record_header header;         /*!< Record header with Format ID: UInt16 (See AIQB_DataID), Name ID: cmc_name_id_exposure_range (See cmc_name_id). */
    uint32_t coarse_integration_min;     /*!< Minimum sensor register value for coarse integration time. */
    uint32_t coarse_integration_max;     /*!< Maximum sensor register value for coarse integration time.*/
    uint32_t fine_integration_min;       /*!< Minimum sensor register value for fine integration time.*/
    uint32_t fine_integration_max;       /*!< Maximum sensor register value for fine integration time.*/
} cmc_exposure_range_t;
#define SIZEOF_CMC_EXPOSURE_RANGE_T 24

/*!
 * \brief CMC Multiple LED flash chromaticity.
 */
typedef struct
{
    uint16_t device_id;                    /*!< Flash device ID enumerator. */
    uint16_t num_poly_points;              /*!< Number of points defining polygon. */
    chromaticity_t flash_avg_chromaticity; /*!< Flash chromaticity in R/G, B/G plane. */
    cie_coords_t flash_avg_cie;            /*!< Flash chromaticity in CIE X, CIE Y plane. */
    uint16_t reserved[2];                  /*!< Reserved for future changes. Always 0 (for now).. */
    cmc_poly_point_t *poly_points;         /*!< Flash Chromaticity Deviation in R/G, B/G plane. */
} cmc_flash_device_t;
#define SIZEOF_CMC_FLASH_DEVICE_T 16U     /*!< Size of the structure without pointers. Used in copying data from CPF to this structure. */

typedef struct
{
    ia_mkn_record_header header;         /*!< Record header with Format ID: UInt16 (See AIQB_DataID), Name ID: cmc_name_id_multi_led_flash_chromaticity (See cmc_name_id). */
    uint16_t max_flash_output;           /*!< Flash maximum energy output for full power, lumen per second [lm/s] */
    uint16_t multi_led_flash_mode;       /*!< Reserved for future changes. Always 0 (for now). */
    uint16_t reserved;                   /*!< Reserved for future changes. Always 0 (for now). */
    uint16_t num_flash_devices;          /*!< Number of flash devices/LEDs. */
    cmc_flash_device_t *flash_devices;   /*!< Data of all flash devices. */
} cmc_multi_led_flash_t;
#define SIZEOF_CMC_MULTI_LED_FLASH_T 16  /*!< Size of the structure without pointers. Used in copying data from CPF to this structure. */

typedef struct
{
    ia_mkn_record_header header;         /*!< Record header with Format ID: UInt16 (See AIQB_DataID), Name ID: cmc_name_id_sensor_metadata (See cmc_name_id). */
    uint16_t total_num_of_cfg_blocks;    /*!< Total number of config blocks (ia_emd_config_block_t). */
    uint16_t total_num_of_data_blocks;   /*!< Total number of decoded data blocks (ia_emd_decoded_block_t). */
    uint8_t num_of_exposure_sets;        /*!< Number of exposure sets in sensor embedded data. */
    uint8_t num_of_color_channels;       /*!< Number of color channels in sensor embedded data. */
    uint8_t max_num_of_faces;            /*!< Maximum number of faces in external ISP embedded data. */
    uint8_t reserved;                    /*!< Reserved. */
    /* ia_emd_config_block_t cfg_blocks[];*/   /*!< Configuration blocks array. */
} cmc_emd_decoder_config_t;
#define SIZEOF_CMC_EMD_DECODER_CONFIG_T  16 /*!< Size of cmc_emd_decoder_config_t without pointer. Used in copying data from CPF to this structure. */

typedef struct
{
    uint8_t *key;                       /*!< Free C string text key (NULL terminated) */
    uint8_t *version;                   /*!< Free C string text version (NULL terminated) */
} cmc_version_info_t;

typedef struct
{
    cmc_comment_t *cmc_comment;
    uint8_t *comment;
    uint16_t num_version_infos;
    cmc_version_info_t *version_infos;
} cmc_parsed_comment_t;

typedef struct
{
    cmc_black_level_t *cmc_black_level;
    cmc_black_level_lut_t *cmc_black_level_luts;
} cmc_parsed_black_level_t;

typedef struct
{
    cmc_linearity_t *cmc_linearity;
    uint16_t *cmc_linearity_lut;
} cmc_parsed_linearity_t;

typedef struct
{
    cmc_lens_shading_t *cmc_lens_shading;
    cmc_lsc_grid_t *cmc_lsc_grids;
    uint16_t *lsc_grids;
    chromaticity_t *cmc_lsc_rg_bg_ratios;  /* Sensor R/G B/G ratios, available in
                                               cmc_name_id_lens_shading_correction v101. */
} cmc_parsed_lens_shading_t;

typedef struct
{
    cmc_lens_shading_ratio_t *cmc_lens_shading_ratio;
    cmc_lsc_ratio_grid_t *cmc_lsc_ratio_grids;
    uint16_t *lsc_grids;
} cmc_parsed_lens_shading_ratio_t;

typedef enum
{
    cmc_aperture_type_fixed = 0,          /*!< Aperture is fixed. */
    cmc_aperture_type_dc_iris,            /*!< Aperture is controlled by DC-iris. */
    cmc_aperture_type_p_iris,             /*!< Aperture is controlled by P-iris. */
} cmc_aperture_type_t;

typedef struct
{
    int16_t cmc_dac_min;        /*!< Minimum value of the DA-converter (will close the iris). */
    int16_t cmc_dac_hold;       /*!< A value for DA-converter that will hold the iris ("barely open or barely close"). */
    int16_t cmc_dac_max;        /*!< Maximum value of the DA-converter (will open the iris). */
} cmc_dc_iris_dac_t;

typedef struct
{
    cmc_optomechanics_t *cmc_optomechanics;
    uint16_t *lut_apertures;
    uint16_t aperture_type;         /*!< Aperture type control of type cmc_aperture_type_t, v101 and onwards. */
    cmc_dc_iris_dac_t dc_iris_dac;  /*!< DAC values for DC-iris, v102 and onwards. */
} cmc_parsed_optics_t;

typedef struct
{
    cmc_spectral_response_t *cmc_spectral_response;
    cmc_color_channels *spectral_responses;
} cmc_parsed_spectral_response_t;

/*!
 * \brief CMC Gamut.
 */
typedef struct
{
    uint16_t light_source;               /*!< Light source type (0 if not known). */
    uint16_t r_per_g;                    /*!< Gamut achromatic point R per G (white balance gains for given gamut).*/
    uint16_t b_per_g;                    /*!< Gamut achromatic point R per G (white balance gains for given gamut).*/
    uint16_t CIE_x;                      /*!< Illumination CIE x coordinate.*/
    uint16_t CIE_y;                      /*!< Illumination CIE x coordinate.*/
    uint16_t size;                       /*!< Size of the gamut tables.*/
    uint16_t *gamut_r_per_g;             /*!< Illumination gamut (convex hull). R per g points in clockwise order*/
    uint16_t *gamut_b_per_g;             /*!< Illumination gamut (convex hull). R per g points in clockwise order*/
} cmc_gamut_t;
#define SIZEOF_CMC_GAMUT_T 12U

typedef struct
{
    uint16_t num_illumination_gamuts;   /*!< Number of illumination gamuts */
    cmc_gamut_t *cmc_gamut;
} cmc_chromaticity_response_v101_t;
#define SIZEOF_CMC_CHROMATICITY_RESPONSE_V101 2U

/*!
 * \brief Parametric model coefficients for the average chromaticity locus and CCT curve
 */
typedef struct
{
    float locus_model[4];
    float cct_model[3];
} cmc_locus_t;

typedef struct
{
    cmc_chromaticity_response_t *cmc_chromaticity_response;
    cmc_chromaticity_response_v101_t *cmc_chromaticity_response_v101;
    cmc_locus_t *cmc_locus;
    cmc_lightsource_t *cmc_lightsources_avg;
    cmc_lightsource_t *cmc_lightsources_hi;
    cmc_lightsource_t *cmc_lightsources_lo;
    cmc_lightsource_t *cmc_lightsources_nvm;
} cmc_parsed_chromaticity_response_t;

typedef struct
{
    cmc_flash_chromaticity_t *cmc_flash_chromaticity;
    cmc_poly_point_t *cmc_poly_points;
} cmc_parsed_flash_chromaticity_t;

typedef enum
{
    ccm_estimate_method_bypass,     /*!< Return unity CCM matrix. */
    ccm_estimate_method_wp,         /*!< Return CCM matrix using only white point estimate from AWB. */
    ccm_estimate_method_wp_sa,      /*!< Return CCM matrix using both white point estimate from AWB and Shading Adaptor Results. */
    ccm_estimate_method_cct,        /*!< Return CCM matrix using cct */
} ccm_estimate_method_t;

typedef struct
{
    cmc_color_matrices_t *cmc_color_matrices;
    cmc_color_matrix_t *cmc_color_matrix;
    uint16_t *ccm_estimate_method;              /*!< ccm_estimate_method for interpolation -> ccm_estimate_method_t */
} cmc_parsed_color_matrices_t;

typedef struct
{
    cmc_analog_gain_conversion_t *cmc_analog_gain_conversion;
    cmc_analog_gain_segment_t *cmc_analog_gain_segments;
    cmc_analog_gain_pair_t *cmc_analog_gain_pairs;
} cmc_parsed_analog_gain_conversion_t;

/*!
 * \brief Gain to gain code mapping.
 * Gains must be defined in ascending order.
*/
typedef struct
{
    float gain;                         /*!< Gain in floating point format. */
    uint32_t code;                      /*!< Code corresponding to gain. */
} cmc_gain_code_pair_t;

/*!
 * \brief Gain to gain code mapping of a segment.
 * Segments contain SMIA gain parameters. When ranges is defined, beginning is always inclusive and end exclusive.
 * For example gain 2.0 and ranges: [1.0, 2.0[; [2.0, 4.0[;. Gain 2.0 is not calculated from the first range parameters but from the second range.
 */
typedef struct
{
    float gain_begin;                   /*!< Begin of gain of the segment (inclusive) in floating point format. */
    float gain_end;                     /*!< End of gain of the segment (exclusive) in floating point format. */
    uint32_t code_min;                  /*!< The minimum recommended setting for the gain control. */
    uint32_t code_max;                  /*!< The maximum recommended setting for the gain control. */
    uint32_t code_step;                 /*!< The precision of the gain control. */
    int16_t M0;                         /*!< Gain code M0 as in SMIA. */
    int16_t C0;                         /*!< Gain code C0 as in SMIA. */
    int16_t M1;                         /*!< Gain code M1 as in SMIA. */
    int16_t C1;                         /*!< Gain code C1 as in SMIA. */
    uint32_t padding;                   /*!< Padding to 64-bit boundary. */
} cmc_gain_segment_t;

typedef struct
{
    cmc_digital_gain_t *cmc_digital_gain;
    cmc_digital_gain_v102_t *cmc_digital_gain_v102;
    cmc_analog_gain_pair_t *cmc_digital_gain_pairs;
} cmc_parsed_digital_gain_t;

typedef enum
{
    cmc_gain_type_invalid = -1,     /*!< Invalid gain. */
    cmc_gain_type_analog_gain = 0,  /*!< Analog gain. */
    cmc_gain_type_digital_gain,     /*!< Digital gain. */
    cmc_gain_type_conversion_gain,  /*!< Conversion gain for HDR sensors. */
    cmc_gain_type_isp_gain,         /*!< Gain applied in ISP. */
} cmc_gain_type_t;

#ifndef IA_CMC_GAINS_MAX_NUM
/* TODO: Use definition from ia_configuration.h */
/* Windows driver and imaging system simulators don't include ia_configuration.h correctly. */
#define IA_CMC_GAINS_MAX_NUM 4
#endif

typedef enum
{
    cmc_gain_conversion_type_none,          /*!< No gain conversion should be done. */
    cmc_gain_conversion_type_segment,       /*!< Segments contain SMIA compatible parameters for calculating register value for a certain range of gain. */
    cmc_gain_conversion_type_pair,          /*!< Pairs contain gain value & corresponding register value. */
    cmc_gain_conversion_type_fixed_point,   /*!< Gain is defined in fixed point format. */
} cmc_gain_conversion_type_t;

typedef struct
{
    uint16_t gain_min;           /*!< The minimum valid limit of the gain control parameters in fixed point format (16bit integer part + 16bit fraction part). */
    uint16_t gain_max;           /*!< The maximum valid limit of the gain control parameters in fixed point format (16bit integer part + 16bit fraction part). */
    uint16_t gain_step_size;      /*!< Step size of gain code register value. */
    uint16_t fraction_bits;       /*!< Number of bits used for the fraction part of the 16 bit register value. */
} cmc_gain_fixed_t;

typedef struct
{
    cmc_gain_type_t gain_type;                  /*!< Gain type. */
    cmc_gain_conversion_type_t conversion_type; /*!< Gain conversion type. */
    uint32_t num_segments;                      /*!< Number of gain/code segments which describe the gain. */
    uint32_t num_pairs;                         /*!< Number of gain/code pairs which describe the gain. */
    union
    {
        cmc_gain_segment_t *ptr;                /*!< Array of gain segments. Array length is defined by num_segments. */
        uint64_t dummy;                         /* Ensures that pointer is accessible in both 32 and 64 bit systems. */
    } segments;
    union
    {
        cmc_gain_code_pair_t *ptr;              /*!< Array of gain code pairs. Array length is defined by num_pairs. */
        uint64_t dummy;                         /* Ensures that pointer is accessible in both 32 and 64 bit systems. */
    } pairs;
    union
    {
        cmc_gain_fixed_t *ptr;                  /*!< A pointer to the fixed point format. */
        uint64_t dummy;                         /* Ensures that pointer is accessible in both 32 and 64 bit systems. */
    } fixed;
} cmc_gain_conversion_t;

typedef struct
{
    ia_mkn_record_header header;        /*!< Record header with Format ID: UInt16 (See AIQB_DataID), Name ID: cmc_name_id_multi_gain_conversions (See cmc_name_id). */
    uint32_t num_gains;                 /*!< Number of gains configured. */
    uint32_t padding;
    union
    {
        cmc_gain_conversion_t* ptr;     /*!< Array of gain conversions. Array length defined in num_gains. */
        uint64_t dummy;                 /* Ensures that pointer is accessible in both 32 and 64 bit systems. */
    } gains;
    uint64_t reserved;                  /* Reserved for record version updates. */
} cmc_multi_gain_conversions_t;

/*!
* \brief CMC geometric distortion correction grids
*/
typedef struct
{
    uint16_t focus_position;             /*!< Focus motor position in terms of those used by the sensor module.
                                         Range should be depicted from the cmc_name_id_optics_and_mechanics section in the CPFF.). */
    int32_t *x_deltas;                  /*!< Table of x-axis deltas of the grid points. The delta at each point represents the distortion
                                        that was done. Contains [GDC_grid_height  x GDC_grid_width] values. */
    int32_t *y_deltas;                  /*!< Table of y-axis deltas of the grid points. The delta at each point represents the distortion
                                        that was done. Contains [GDC_grid_height  x GDC_grid_width] values. */
} cmc_geometric_distortion2_grid_t;

typedef struct
{
    int32_t focalLength;            /*!< Focal length in terms of those used by the camera module.Range should be depicted from the CMC_OpticsAndMechanics section in the CPFF.*/
    int32_t ldc_r_lut[256];         /*!< LDC(R) LUT table*/
    int32_t ldc_r_x_center;         /*!< X coordinate of LDC(R) correction center of symmetry */
    int32_t ldc_r_y_center;         /*!< Y coordinate of LDC(R) correction center of symmetry */
    int32_t ldc_r_y_scale_factor;   /*!< Y coordinate scaling factor for elliptical distortion of LDC(R) correction */
} cmc_ldc_lut_t;

/*!
 * \brief LDC LUT mode
 */
typedef enum {
    cmc_camera_ldc_lut_type_incident_angle_vs_distorted_radius = 0,  /*!< incident angle vs Rd */
    cmc_camera_ldc_lut_type_undistorted_radius_vs_distorted_radius,  /*!< 1-> Ru vs Rd */
} cmc_camera_ldc_lut_mode_t;


/*!
 * \brief CMC WFOV LDC parameters
 */

typedef struct
{
    float focal_length;            /*!< Focal length in terms of those used by the camera module.Range should be depicted from the CMC_OpticsAndMechanics section in the CPFF.*/
    float max_fov_lut;            /*!< Max incident angle (in degrees) covered in the LUT.*/
    cmc_camera_ldc_lut_mode_t lut_mode;    /*!< LDC LUT mode: 0 -> incident angle vs Rd, 1-> Ru vs Rd*/
    int32_t num_lut_elements;     /*!< Number of LUT elements.*/
    float *ldc_r_lut;             /*!< LDC(R) LUT table in pixels*/
} cmc_wfov_ldc_lut_t;


/*!
 * \brief CMC WFOV calibration parameters
 */
typedef struct
{
    float horizontal_shift;         /*!< Horizontal shifts in pixels */
    float vertical_shift;           /*!< Vertical shifts in pixels */
    float horizontal_foclen_fact;   /*!< Horizontal focal length factor */
    float vertical_foclen_fact;     /*!< Vertical focal length factor */
    float horizontal_shear;         /*!< Horizontal shear factor */
    float vertical_shear;           /*!< Vertical shear factor */
} cmc_affine_params_t;
#define SIZEOF_CMC_AFFINE_PARAMS (24)

typedef struct
{
    int16_t ldc_col_start;                             /*!< Table X offset in pixels from left corner of the sensor maximum visible area e.g.
                                                       If GDC_col_start=GDC_block_width*(-1) then GDC table offset is is one block left compared
                                                       to the maximum visible sensor area. */
    int16_t ldc_row_start;                             /*!< Table Y offset in pixels from upper corner of the sensor maximum visible area e.g.
                                                       If GDC_row_start=GDC_block_height*(-1) then GDC table offset is is one block up compared
                                                       to the maximum visible sensor area.  */
    int16_t ldc_grid_width;                            /*!< Indicates number of grid vertices on the horizontal axis. */
    int16_t ldc_grid_height;                           /*!< Indicates number of grid vertices on the vertical axis. */
    int16_t ldc_block_width;                           /*!< Average width of the grid cell in pixel count. */
    int16_t ldc_block_height;                          /*!< Average height of the grid cell in pixel count. */
    uint16_t ldc_grid_count;                           /*!< Number of LDC grids (focus positions). */
    cmc_gdc_mode_type gdc_mode;                        /*!< GDC mode enum, 0=Grid based (old),  1=LUT, 2=ext-LUT. */
    int32_t ldc_lut_count;                             /*!< Number of LDC Luts (focal lengths) */
    int32_t spherical_r_lut[256];                      /*!< R-spherical LUT table for spherical to Cartesian coordinate system transformation (dewarping) */
    int32_t spherical_r_lut_radius_start;              /*!< R-spherical LUT table starting radius, 0-65535 */
    int32_t spherical_r_lut_radius_end;                /*!< R-spherical LUT table ending radius, 0-65535 */
    int32_t spherical_to_cartesian_x_center;           /*!< X coordinate of spherical to Cartesian coordinate system transformation (dewarping), 0-65535 */
    int32_t spherical_to_cartesian_y_center;           /*!< Y coordinate of spherical to Cartesian coordinate system transformation (dewarping), 0-65535 */
    cmc_geometric_distortion2_grid_t* ldc_grid;        /*!< LDC grids (legacy) */
    cmc_ldc_lut_t* ldc_lut;                            /*!< LDC LUTs */
    float max_fov_lens;                                /*!< Max field of view of the lens(degrees) */
    int32_t num_wfov_luts;                             /*!< Number of WFOV Luts (focal lengths) */
    cmc_wfov_ldc_lut_t *wfov_ldc_lut;                  /*!< WFOV LDC LUTs: Number of LUTs specified by num_wfov_luts */
    cmc_affine_params_t *affine_params;                /*!< WFOV affine parameters: One for each LUT */
} cmc_parsed_geometric_distortion2_t;
#define SIZEOF_CMC_GEOMETRIC_DISTORTION_V100_T 22U
#define SIZEOF_CMC_GEOMETRIC_DISTORTION_SPHERICAL_R_LUT 1024U /* 256 * 4 */
#define SIZEOF_CMC_GEOMETRIC_DISTORTION_SPHERICAL_CFG_PARAMS 16U



/*!
 * \brief CMC advanced color matrix info
 */
typedef struct
{
    ia_mkn_record_header header;         /*!< Record header with Format ID: UInt16 (See AIQB_DataID), Name ID: CMC_GeometricDistortion2 (See cmc_name_id). */
    uint16_t light_sources_count;        /*!< Number of light sources. */
    uint16_t sector_count;               /*!< Number of color matrix sectors.  */
} cmc_advanced_color_matrix_info_t;
#define SIZEOF_CMC_ADVANCED_COLOR_MATRIX_INFO_T 12U

/*!
 * \brief CMC color matrix
 */
typedef struct
{
    float color_matrix[9];                 /*!< 3x3 accurate CCM, each consequtive elements sum to 1. */
} cmc_acm_color_matrix_t;
#define SIZEOF_CMC_ACM_COLOR_MATRIX_T 36U

/*!
 * \brief CMC advanced color matrices info for light sources
 */
typedef struct
{
    uint32_t src_type;                   /*!< Light source type (enum), e.g. Fluorescent. */
    float chromaticity[2];               /*!< Chromaticity (sensor) in R/G, B/G plane. */
    float src_cie_xy[2];                 /*!< CIE x and y coordinates. */
    uint32_t cct;                        /*!< Color temperature */
} cmc_acm_color_matrices_info_t;

#define SIZEOF_CMC_ACM_COLOR_MATRICES_INFO_T 20U
#define SIZEOF_CMC_ACM_COLOR_MATRICES_INFO_V101_T  24U

typedef struct
{
    cmc_acm_color_matrices_info_t *color_matrices_info;         /*! < Information for Color matrices. */
    cmc_acm_color_matrix_t traditional_color_matrix;            /*! < Color matrix optimized using all sectors. */
    cmc_acm_color_matrix_t *advanced_color_matrices;            /*! < Array of color matrices. Array size is sector_count */
} cmc_parsed_advanced_color_matrices_ls_t;

typedef struct
{
    cmc_advanced_color_matrix_info_t *cmc_advanced_color_matrix_info;
    uint32_t *hue_of_sectors;                                                       /*! < Starting hue angle array of sectors. Array size is sector_count. */
    cmc_parsed_advanced_color_matrices_ls_t *cmc_parsed_advanced_color_matrices_ls; /*! < Array of color matrices
                                                                                          for different light sources.
                                                                                          Array size is light_sources_count. */
} cmc_parsed_advanced_color_matrix_t;

typedef struct
{
    float min;    /*!< The minimum allowed ratio for the parameter. */
    float max;    /*!< The maximum allowed ratio for the parameter. */
} cmc_hdr_param_ratio_limit_t;

/*!
 *  CMC HDR ratio limits.
 */
typedef struct
{
    cmc_hdr_param_ratio_limit_t hdr_exposure_time_ratio_limits; /*!< Allowed ratio between exposure times. */
    cmc_hdr_param_ratio_limit_t hdr_analog_gain_ratio_limits;   /*!< Allowed ratio between analog gains. */
    cmc_hdr_param_ratio_limit_t hdr_digital_gain_ratio_limits;  /*!< Allowed ratio between digital gains. */
} cmc_hdr_ratio_limits_t;

/*!
* \brief CMC HDR Parameters
*/
typedef struct
{
    ia_mkn_record_header header;    /*!< Record header with Format ID: Uint16 (See AIQB_DataID) Name ID: cmc_name_id_hdr. */
    float hdr_exposure_ratio_min;   /*!< Minimum HDR exposure ratio between different exposures. */
    float hdr_exposure_ratio_max;   /*!< Maximum HDR exposure ratio between different exposures. */

    cmc_hdr_ratio_limits_t overall_ratio_limits;    /*!< v101. Ratio limits between the longest and shortest exposure. */
    cmc_hdr_ratio_limits_t pair_ratio_limits;       /*!< v101. Ratio limits between exposure pairs. */
} cmc_parsed_hdr_parameters_t;

#define SIZEOF_CMC_HDR_T        16U
#define SIZEOF_CMC_HDR_V101_T   (2U*(uint32_t)sizeof(cmc_hdr_ratio_limits_t))

typedef enum
{
    ir_correction_level_bypass,     /*!< Set PA IR Weight grid pointer as NULL. */
    ir_correction_level_wp,         /*!< Interpolate IR Weight grid using only white point estimate from AWB. */
} ir_correction_level_t;

/*!
* \brief CMC IR Weight Grids Parameters
*/
typedef struct
{
    ia_mkn_record_header header;    /*!< Record header with Format ID: Uint16 (See AIQB_DataID) Name ID: cmc_name_id_hdr. */
    int8_t grid_indices[16];        /*!< IR Weight grid indices showing which tables in the structure holds information. -1 means no correction for that pixel */
    uint16_t num_light_sources;     /*!< Number of light sources for which IR Weight Grids are characterized . */
    uint16_t num_grids;             /*!< Number of grids per light source. This depends on the CFA type and non -1 elements in  . */
    uint16_t grid_width;            /*!< IR Weight Grid width. */
    uint16_t grid_height;           /*!< IR Weight Grid height. */
}
cmc_ir_weight_info_t;
#define SIZEOF_CMC_IR_WEIGHT_INFO_T 32U


typedef struct
{
    cmc_light_source source_type;    /*!< Light-source type. See enum cmc_light_source.  */
    float chromaticity[2];          /*!< Chromaticity (sensor) in R/G, B/G plane. */
    float cie_coords[2];            /*!< CIE x and y coordinates. */
} cmc_ir_weight_grid_info_t;
#define SIZEOF_CMC_IR_WEIGHT_GRID_INFO_T 20U

typedef struct
{
    cmc_ir_weight_grid_info_t *ir_weight_grid_info;     /*!< IR Weight Grid Info. */
    uint16_t *ir_weight_grid;        /*!< IR Weight Grids for all channels. */
}
cmc_ir_weight_grids_t;

typedef struct
{
    float ir_proportion;            /*!< IR and green pixel proportion in sensor plane, */
    float reserved[3];              /*!< Reserved. */
}
cmc_ir_proportion_t;
#define SIZEOF_CMC_IR_PROPORTION_V101_T   ((uint32_t)sizeof(cmc_ir_proportion_t))

typedef struct
{
    cmc_ir_weight_info_t *ir_weight_info;       /*!< IR Weight Info . */
    cmc_ir_weight_grids_t *ir_weight_grids;     /*!< IR Weight Grids. */
    cmc_ir_proportion_t *ir_proportion;         /*!< v101. */
}
cmc_parsed_ir_weight_t;

/* CMC structures with version ID >= v200 */

typedef struct
{
    cmc_light_source source_type;         /*!< Light source type (enum), e.g. Fluorescent. */
    cmc_chromaticity chromaticity;        /*!< Chromaticity (sensor) in R/G, B/G plane. */
    cmc_cie_coords cie_coords;            /*!< CIE x and y coordinates. */
    cmc_color_matrix traditional;         /*!< Color matrix optimized using all sectors. */
    cmc_color_matrix *advanced;           /*!< Array of color matrices (as defined by num_sectors). */
} cmc_advanced_color_matrices;

typedef struct
{
    ia_mkn_record_header header;          /*!< Record header with Format ID: UInt16 (See AIQB_DataID), Name ID: cmc_name_id_advanced_color_matrices (See cmc_name_id). */
    unsigned short num_light_srcs;        /*!< Number of light sources. */
    unsigned short num_sectors;           /*!< Number of color matrix sectors.  */
    cmc_advanced_color_matrices *acms;    /*!< Advanced color matrices for all light sources (as defined by num_light_srcs). */
    unsigned int *hue_of_sectors;         /*!< Starting hue angle array of sectors (as defined by num_sectors). */
} cmc_advanced_color_matrix_correction;

typedef struct
{
    cmc_light_source source_type;         /*!< Light source type. */
    float chromaticity_i_per_g;           /*!< Sensor Ir/G ratio. */
    cmc_chromaticity chromaticity;        /*!< Sensor R/G B/G ratios. */
    cmc_cie_coords cie_coords;            /*!< CIE x and y coordinates. */
    uint16_t *grids[4][4];                /*!< IR Grids for all color channels (as defined by grid_indices). */
} cmc_ir_grid;

typedef struct
{
    ia_mkn_record_header header;          /*!< Record header with Format ID: UInt16 (See AIQB_DataID), Name ID: cmc_name_id_infrared_correction (See cmc_name_id). */
    char grid_indices[4][4];              /*!< IR grid indices showing which tables in the structure holds information. -1 means no correction. */
    unsigned short num_light_srcs;        /*!< Number of light sources. */
    unsigned short grid_width;            /*!< IR Grid width. */
    unsigned short grid_height;           /*!< IR Grid height. */
    cmc_ir_grid *ir_grids;                /*!< IR grids for all light sources (as defined by num_light_srcs). */
} cmc_infrared_correction;

typedef struct
{
    cmc_light_source source_type;         /*!< Light source type. */
    cmc_chromaticity chromaticity;        /*!< Sensor R/G B/G ratios. */
    cmc_cie_coords cie_coords;            /*!< CIE x and y coordinates. */
    unsigned short fraction_bits;         /*!< Number of fraction bits in the shading table fix point representation. */
    unsigned short *grids[4][4];          /*!< LSC gain grid stored in fixed point format with variable number of fraction bits, (16-fraction_bits)Qfraction_bits. */
} cmc_lsc_grid;
#define SIZEOF_CMC_LSC_GAIN_GRID_T 22U

typedef struct
{
    ia_mkn_record_header header;          /*!< Record header with Format ID: UInt16 (See AIQB_DataID), Name ID: cmc_name_id_lens_shading_correction_4x4 (See cmc_name_id). */
    char grid_indices[4][4];              /*!< LSC grid indices showing which tables in the structure holds information. -1 means no correction. */
    unsigned short num_light_srcs;        /*!< Number of light sources. */
    unsigned short grid_width;            /*!< LSC grid width. */
    unsigned short grid_height;           /*!< LSC grid height. */
    cmc_lsc_grid *lsc_grids;              /*!< LSC grids for all light sources (as defined by num_light_srcs). */
} cmc_lens_shading_correction;
#define SIZEOF_CMC_LENS_SHADING4x4_T 32U

typedef struct
{
    cmc_lsc_grid lsc_grid;                /* LSC gain grid. */
    uint16_t pair_index;                  /* Calibration light source pair index. Tells which NVM table number should be used (in case there are more than one, if there is only one the value is always 0). */
} cmc_lsc_ratio_grid;

typedef struct
{
    ia_mkn_record_header header;          /*!< Record header with Format ID: UInt16 (See AIQB_DataID), Name ID: cmc_name_id_lens_shading_correction_4x4 (See cmc_name_id). */
    char grid_indices[4][4];              /*!< LSC grid indices showing which tables in the structure holds information. -1 means no correction. */
    unsigned short num_light_srcs;        /*!< Number of light sources. */
    unsigned short grid_width;            /*!< LSC grid width. */
    unsigned short grid_height;           /*!< LSC grid height. */
    cmc_lsc_ratio_grid *ratio_grids;      /*!< LSC grids for all light sources (as defined by num_light_srcs). */
} cmc_lens_shading_ratio_correction;

typedef struct
{
    ia_mkn_record_header header;          /*!< Record header with Format ID: UInt16 (See AIQB_DataID), Name ID: cmc_name_id_lateral_chromatic_aberration_correction (See cmc_name_id). */
    cmc_coords optical_center;            /*!< Optical center distance from the left uppermost corner of the sensor (in native sensors resolution). This the location where no lateral chromatic aberration is present. [x, y]. */
    uint16_t grid_width;                  /*!< Width of the grid. */
    uint16_t grid_height;                 /*!< Height of the grid. */
    uint16_t cell_size_x;                 /*!< X-dimension distance (in pixels) between the grid points (lca_grid_*). Guaranteed to be 2^n. This is always in respect to the maximum native sensor width defined in ID2 (General Data). All adaptations to other resolutions is done in the imaging system code in the device in the runtime.*/
    uint16_t cell_size_y;                 /*!< Same as above but y-dimension */
    float *lca_grid_blue_x;               /*!< Amount of absolute lateral chromatic aberration in horizontal direction in each of the grid locations for blue pixels, in respect to the green pixel. The grid is evenly spaced over the native maximum sensor resolution and maximum field of view. 0 means no aberration, -x means shifted to left, +x mean shifted to right. Grid is aligned to the left uppermost corner of the maximum focal plane. This, as all other CMC tables, are in respect to the maximum native image sensor resolution. All adaptations to other resolutions is done in the imaging system code in the device in the runtime. */
    float *lca_grid_blue_y;               /*!< Same as above but in vertical direction. */
    float *lca_grid_red_x;                /*!< Same as above but for horizontal and red pixel. */
    float *lca_grid_red_y;                /*!< Same as above but in vertical direction. */
} cmc_lateral_chromatic_aberration_correction;
#define SIZEOF_CMC_LCA_HDR 20

typedef struct
{
    uint16_t pattern_horizontal_offsets;    /*!< Buffer of horizontal offsets for repetitive PD pixels within the pattern */
    uint16_t pattern_vertical_offsets;      /*!< Buffer of vertical offsets for repetitive PD pixels within the pattern */
    uint16_t pattern_labels;                /*!< Buffer of labels for repetitive PD pixels within the pattern (0 - left pixel, 1 - right pixel) */
} cmc_pd_pattern_t;

typedef struct
{
    int32_t dlom;                          /*!< Default DLOM table for the reference golden sample */
} cmc_pd_dlom_t;

typedef struct
{
    uint16_t ps_gains_left;                /*!< Default PS gains table for left pixels for the reference golden module */
    uint16_t ps_gains_right;               /*!< Default PS gains table for right pixels for the reference golden module */
} cmc_pd_ps_gains_t;

typedef struct
{
    ia_mkn_record_header header;            /*!< Record header with Format ID: Uint16 (See AIQB_DataID) Name ID: cmc_name_id_phase_difference */
    uint16_t sensor_type;                   /*!< PD sensor type (See cmc_pd_sensor_type)*/
    uint16_t technology_type;               /*!< PD technology type (See cmc_pd_technology_type) */
    uint16_t pd_horizontal_offset;          /*!< Number of pixel pairs skipped at the beginning of the frame before the start of the first PD pattern */
    uint16_t pd_vertical_offset;            /*!< Number of line pairs skipped at the beginning of the frame before the start of the first PD pattern */
    uint16_t num_pd_pixels;                 /*!< Number of repetitive PD pixels within the pattern */
    uint16_t pattern_width;                 /*!< Pattern width (horizontal period for repetitive PD pixels) */
    uint16_t pattern_height;                /*!< Pattern height (vertical period for repetitive PD pixels) */
    uint16_t dlom_width;                    /*!< Number of Disparity of Lens Offset Mapping (DLOM) knots in horizontal orientation */
    uint16_t dlom_height;                   /*!< Number of Disparity of Lens Offset Mapping (DLOM) knots in vertical orientation */
    uint16_t ps_gains_width;                /*!< Number of pixel sensitivity (PS) knots in horizontal orientation */
    uint16_t ps_gains_height;               /*!< Number of pixel sensitivity (PS) knots in vertical orientation */
    cmc_pd_pattern_t *cmc_pd_pattern;       /*!< PD pattern characterization (num_pd_pixels) */
    cmc_pd_dlom_t *cmc_pd_dlom;             /*!< Disparity of Lens Offset Mapping characterization (dlom_width*dlom_height) */
    cmc_pd_ps_gains_t *cmc_pd_ps_gains;     /*!< Pixel sensitivity characterization (ps_gains_width*ps_gains_height) */
} cmc_phase_difference_t;
#define SIZEOF_CMC_PHASE_DIFFERENCE_T 30

/*!
 * \brief Structure defining run (count) and value pairs.
 */
typedef struct
{
    unsigned short run;    /*!< Count of how many times the same 'value' is present. */
    unsigned short value;  /*!< Value. */
} cmc_run_value;

/*!
 * \brief Defines structure that describes valid image area.
 * When using WFOV lens, for example fisheye lens, image coming through the optics is not covering the whole sensor area.
 * For example corners of the captured image from sensor may be invalid and need to be excluded from 3A analysis and ISP processing.
 * This structure defines generic form of describing areas that should be excluded from captured rectangular sensor image.
 * 0 value indicates invalid area and 1 indicates valid area.
 * { run, value } pairs are used to compress data.
 *
 * Example how following 2D table is described with { run, value } pairs:
 * 0000000000000000 -> { 16, 0 },
 * 0000011111111111 -> { 5, 0 },  { 11, 1 },
 * 0111111111111110 -> { 1, 0  }, { 14, 1 }, { 1, 0 },
 * 0011111111111100 -> { 2, 0  }, { 12, 1 }, { 2, 0 },
 * 0000111111110000 -> { 4, 0  }, { 8, 1  }, { 4, 0 },
 *
 * This 2D table can be further reduced by joining per row { run, value } pairs to 1D table:
 * { 21, 0 }, { 11, 1 }, { 1, 0 }, { 14, 1 }, { 3, 0 }, { 12, 1 }, { 6, 0 }, { 8, 1 }, { 4, 0 }
 * 'width' defines how to decode 1D array into 2D table.
 * 'height' is given for reference, in order to calculate size of 2D table for decoding it into memory.
 */
typedef struct
{
    ia_mkn_record_header header; /*!< Record header with Format ID: UInt16 (See AIQB_DataID), Name ID: cmc_name_id_valid_image_area (See cmc_name_id). */
    unsigned short width;        /*!< Width of the map that indicates valid image area. */
    unsigned short height;       /*!< Height of the map that indicates valid image area. */
    unsigned int num_run_values; /*!< Number of { run, value } pairs encoded. */
    union {
        cmc_run_value *ptr;      /*!< Pointer to { run, value} pairs. */
        uint64_t dummy;          /* Ensures that pointer is accessible in both 32 and 64 bit systems. */
    } run_values;

    unsigned short center_x;     /*!< v201+ only -- Horizontal center of radial approximation of valid image area in pixels. */
    unsigned short center_y;     /*!< v201+ only -- Vertical center of radial approximation of valid image area in pixels. */
    unsigned int radius;         /*!< v201+ only -- Radius of valid image area in pixels */
    uint64_t reserved_v202;      /*!< v202+ only -- reserved for pointer to v202 data */
    uint64_t reserved_v203;      /*!< v202+ only -- reserved for pointer to v203 data */
} cmc_valid_image_area;

/*!
* \brief CMC Sensor decompand
*/
typedef struct
{
    ia_mkn_record_header header;    /*!< Record header with Format ID: UInt16 (See AIQB_DataID) Name ID: cmc_name_id_saturation_level. (enum cmc_name_id). */
    uint8_t enable;
    uint16_t companded_pedestal;
    uint8_t companded_bpp;
    uint8_t linear_bpp;
    uint8_t number_of_points;
    uint16_t *x_coords;             /*Array of x coordinates for sensor decompand curve. Count of array is equal number_of_point*/
    uint32_t *y_coords;             /*Array of y coordinates for sensor decompand curve. Count of array is equal number_of_point*/
} cmc_parsed_sensor_decompand_t;

/*!
* \brief CMC Pipe compand
*/
typedef struct
{
    ia_mkn_record_header header;    /*!< Record header with Format ID: UInt16 (See AIQB_DataID) Name ID: cmc_name_id_saturation_level. (enum cmc_name_id). */
    uint8_t enable;
    uint32_t linear_pedestal;
    uint8_t segments;
    uint32_t *x_coords;             /*Array of x coordinates for pipe compand curve. Count of array is equal segments + 1 */
    uint16_t *y_coords;             /*Array of y coordinates for pipe compand curve. Count of array is equal segments*/
    uint16_t *slopes;               /*Array of slopes for pipe compand curve. Count of array is equal segments*/
} cmc_parsed_pipe_compand_t;

/*!
* \brief CMC Pipe decompand
*/
typedef struct
{
    ia_mkn_record_header header;    /*!< Record header with Format ID: UInt16 (See AIQB_DataID) Name ID: cmc_name_id_saturation_level. (enum cmc_name_id). */
    uint8_t enable;
    uint32_t linear_pedestal;
    uint8_t segments;
    uint16_t *x_coords;             /*Array of x coordinates for pipe decompand curve. Count of array is equal segments + 1 */
    uint32_t *y_coords;             /*Array of y coordinates for pipe decompand curve. Count of array is equal segments*/
    uint32_t *slopes;               /*Array of slopes for pipe decompand curve. Count of array is equal segments*/
} cmc_parsed_pipe_decompand_t;

typedef struct
{
    float gain;
    int32_t frame_count;
} trigger_info_t;

#define MAX_TNR7US_TRIGGER_INFO_COUNT   16U
typedef struct
{
    float tnr7us_threshold_gain;
    uint32_t num_gains;
    trigger_info_t trigger_infos[MAX_TNR7US_TRIGGER_INFO_COUNT];
} tnr7us_trigger_info_t;

/*!
 * \brief Parsed CMC structure.
 * Parser will fill the pointers in this structure so that data can be accessed more easily.
 */
typedef struct
{
    cmc_parsed_comment_t cmc_parsed_comment;                               /* 0 */
    cmc_general_data_t *cmc_general_data;                                  /* 8 */
    cmc_parsed_black_level_t cmc_parsed_black_level;                       /* DEPRECATED. Use cmc_black_level_global instead. */
    cmc_saturation_level_t *cmc_saturation_level;                          /* 20 */
    cmc_parsed_linearity_t cmc_parsed_linearity;                           /* 24 */
    cmc_sensitivity_t *cmc_sensitivity;                                    /* 32 */
    cmc_defect_pixel_t *cmc_defect_pixel;                                  /* 36 */
    cmc_noise *cmc_noise_model;                                            /* 40 */
    cmc_parsed_lens_shading_t cmc_parsed_lens_shading;                     /* 44 */
    cmc_parsed_optics_t cmc_parsed_optics;                                 /* 72 */
    cmc_parsed_spectral_response_t cmc_parsed_spectral_response;           /* 80 */
    cmc_parsed_chromaticity_response_t cmc_parsed_chromaticity_response;   /* 88 */
    cmc_parsed_flash_chromaticity_t cmc_parsed_flash_chromaticity;         /* 108 */
    cmc_parsed_nvm_info_t cmc_parsed_nvm_info;                             /* 114 */
    cmc_parsed_color_matrices_t cmc_parsed_color_matrices;                 /* */
    cmc_parsed_analog_gain_conversion_t cmc_parsed_analog_gain_conversion; /* DEPRECATED. Use cmc_multi_gain_conversions instead. */
    cmc_parsed_digital_gain_t cmc_parsed_digital_gain;                     /* DEPRECATED. Use cmc_multi_gain_conversions instead. */
    cmc_parsed_geometric_distortion2_t *cmc_parsed_geometric_distortion2;
    cmc_exposure_range_t *cmc_exposure_range;
    cmc_multi_led_flash_t *cmc_multi_led_flashes;
    cmc_emd_decoder_config_t *cmc_emd_decoder_config;
    cmc_parsed_advanced_color_matrix_t cmc_parsed_advanced_color_matrix;
    cmc_parsed_hdr_parameters_t *cmc_parsed_hdr_parameters;
    cmc_parsed_ir_weight_t *cmc_parsed_ir_weight;
    cmc_phase_difference_t *cmc_phase_difference;
    cmc_lateral_chromatic_aberration_correction *cmc_parsed_lca;
    cmc_lens_shading_correction *cmc_lens_shading;
    cmc_black_level_global *cmc_black_level_global;
    cmc_valid_image_area *cmc_valid_image_area;
    cmc_lens_shading_ratio_correction *cmc_lens_shading_ratio;
    cmc_multi_gain_conversions_t *cmc_multi_gain_conversions;
    cmc_parsed_pipe_compand_t *cmc_parsed_pipe_compand;
    cmc_parsed_pipe_decompand_t *cmc_parsed_pipe_decompand;
    cmc_parsed_sensor_decompand_t *cmc_parsed_sensor_decompand;
    tnr7us_trigger_info_t *tnr7us_trigger_info;
} ia_cmc_t;

#ifdef __cplusplus
}
#endif

#endif /* IA_CMC_TYPES_H_ */
