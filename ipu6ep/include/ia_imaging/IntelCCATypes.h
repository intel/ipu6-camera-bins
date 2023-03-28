/*
 * Copyright (C) 2019-2023 Intel Corporation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef INTELCCA_TYPES_H_
#define INTELCCA_TYPES_H_

#include "ia_configuration.h"
#include "ia_aiq.h"
#include "ia_types.h"
#include "ia_ob.h"
#include "ia_lard.h"
#ifndef PAC_ENABLE
#ifdef ENABLE_LTM
#include "ia_ltm.h"
#endif
#ifdef ENABLE_DVS
#include "ia_dvs.h"
#endif
#endif
#include "ia_view.h"
#include "ia_cmc_types.h"
#include "ia_cmc_parser.h"
#include "ia_bcomp.h"
#include "ia_mkn_encoder.h"
#ifdef PAC_ENABLE
#include "ia_aic_types.h"
#else
#include "ia_isp_bxt.h"
#include "ia_isp_types.h"
#endif
#include "ia_abstraction.h"
#include "CCAMacro.h"
#include "ia_emd_decoder.h"

namespace cca {

/*!
 *  \brief cca cpf struct.
 */
typedef struct
{
    size_t size;                /*!< Mandatory. size of aiqb data. */
    uint8_t buf[MAX_CPF_LEN];   /*!< Mandatory. buffer of aiqb data. */
} cca_cpf;

/*!
 *  \brief cca nvm struct.
 */
typedef struct
{
    size_t size;               /*!< Mandatory. size of sensor nvm data. */
    uint8_t buf[MAX_NVM_LEN];  /*!< Mandatory. buffer of sensor nvm data. */
} cca_nvm;

/*!
 *  \brief aiq data struct.
 */
typedef struct
{
    size_t size;               /*!< Mandatory. size of aiq data. */
    uint8_t buf[MAX_AIQD_LEN]; /*!< Mandatory. buffer of aiq data. */
} cca_aiqd;

/*!
 *  \brief aiq data struct.
 */
typedef struct
{
    size_t size;               /*!< Mandatory. size of mkn data. */
    uint8_t buf[MAX_MKN_LEN];  /*!< Mandatory. buffer of mkn data. */
} cca_mkn;

/*!
 *  \brief statistics data struct.
 */
typedef struct
{
    size_t size;                /*!< Mandatory. size of statistics bin. */
    uint8_t buf[MAX_STATS_LEN]; /*!< Mandatory. buffer of statistics data. */
} cca_stats_bin;

/*!
 *  \brief stream id struct.
 */
typedef struct
{
    size_t count;
    int32_t ids[MAX_STREAM_NUM];
} cca_stream_ids;

/*!
 * \brief bitmap to enable CCA modules in running.
 */
enum CCAModuleBitMap
{
    CCA_MODULE_AE = 1,
    CCA_MODULE_AF = 1 << 1,
    CCA_MODULE_AWB = 1 << 2,
    CCA_MODULE_PA = 1 << 3,
    CCA_MODULE_SA = 1 << 4,
    CCA_MODULE_GBCE = 1 << 5,
    CCA_MODULE_LTM = 1 << 6,
    CCA_MODULE_DVS = 1 << 7,
    CCA_MODULE_OB = 1 << 8,
    CCA_MODULE_BCOM = 1 << 9,
    CCA_MODULE_LARD = 1 << 10,
    CCA_MODULE_EMDED = 1 << 11
};

/*!
 * \brief aiqb contents.
 */
enum CCALardItem
{
    CCA_LARD_CMC = 1,
    CCA_LARD_AIQ = 1 << 1,
    CCA_LARD_ISP = 1 << 2,
    CCA_LARD_OTHER = 1 << 3
};

/*!
 * \brief lard contents.
 */
typedef struct
{
    uint32_t cmc_count;
    uint32_t cmc_tags[MAX_TAG_LIST_LEN];
    uint32_t aiq_count;
    uint32_t aiq_tags[MAX_TAG_LIST_LEN];
    uint32_t isp_count;
    uint32_t isp_index[MAX_TAG_LIST_LEN];
    uint32_t other_count;
    uint32_t other_tags[MAX_TAG_LIST_LEN];
} cca_lard_data;

/*!
 * \brief denote the type of statistics.
 */
enum CCAStatsType
{
    CCA_STATS_RGBS = 1,
    CCA_STATS_HIST = 1 << 1,
    CCA_STATS_AF = 1 << 2,
    CCA_STATS_YV = 1 << 3,
    CCA_STATS_LTM = 1 << 4,
    CCA_STATS_DVS = 1 << 5,
    CCA_STATS_PDAF = 1 << 6,
    CCA_STATS_RGBIR_IR = 1 << 7
};

/*!
 * \brief DVS results type.
 */
enum CCADVSOutputType
{
    CCA_DVS_MORPH_TABLE = 0,
    CCA_DVS_IMAGE_TRANSFORM
};

/*!
 * \brief aec_features input parameters.
 */
typedef struct
{
    bool aec_features_enabled;
    ia_aiq_ae_features aec_features;
}cca_ae_features;

/*!
 * \brief exposure algo input parameters.
 */
typedef struct
{
    bool is_bypass;                                             /*!< Mandatory. bypass AEC run. */
    ia_aiq_frame_use frame_use;                                 /*!< Mandatory. Target frame type of the AEC calculations (Preview, Still, video etc.). */
    uint32_t num_exposures;                                     /*!< Mandatory. The number of exposure outputs to have. Must be positive. One for LDR, two or more for HDR/exposure bracketing. */
    ia_aiq_flash_mode flash_mode;                               /*!< Mandatory. Manual flash mode. If AEC should make flash decision, set mode to ia_aiq_flash_mode_auto. */
    ia_aiq_ae_metering_mode metering_mode;                      /*!< Mandatory. AEC metering mode. */
    ia_aiq_ae_priority_mode priority_mode;                      /*!< Mandatory. AEC priority mode. */
    ia_aiq_ae_operation_mode operation_mode;                    /*!< Mandatory. AEC operation mode. */
    ia_aiq_ae_flicker_reduction flicker_reduction_mode;         /*!< Mandatory. AEC flicker reduction mode. */
    ia_aiq_exposure_sensor_descriptor sensor_descriptor[MAX_SENSOR];       /*!< Mandatory although function will not return error, if not given.
                                                                     Sensor specific descriptor and limits of the used sensor mode for target frame use.
                                                                     AEC will not limit and calculate sensor specific parameters, if not given */
    uint32_t num_sensor_descriptors;                            /*!< Mandatory. The number of sensor descriptors given in the above pointer.
                                                                     Used to specify different sensor descriptors for each exposure. */
    cca_ae_features aec_features;                               /*!< Optional. AEC features in use when calculating new exposure parameters. */
    ia_rectangle exposure_window;                               /*!< Optional. Rectangle of area which AEC uses to to calculate new exposure parameters. */
    ia_coordinate exposure_coordinate;                          /*!< Optional. Coordinate for a point in which the exposure should be prioritized.
                                                                     AEC increases weight of given point in final AEC results. */
    float32_t ev_shift;                                             /*!< Optional. Exposure Value shift [-4,4]. */
    uint32_t manual_exposure_time_us[MAX_NUM_EXPOSURE];         /*!< Optional. Manual exposure time in microseconds. NULL if NA. Otherwise, array of values
                                                                     of num_exposures length. Order of exposure times corresponds to exposure_index of
                                                                     ae_results, e.g.
                                                                     manual_exposure_time_us[ae_results->exposures[0].exposure_index] = 33000; */
    float32_t manual_analog_gain [MAX_NUM_EXPOSURE];                /*!< Optional. Manual analog gain. NULL if NA. Otherwise, array of values of num_exposures
                                                                     length. Order of gain values corresponds to exposure_index of ae_results,
                                                                     e.g., manual_analog_gain[ae_results->exposures[0].exposure_index] = 4.0f; */
    uint16_t manual_iso[MAX_NUM_EXPOSURE];                      /*!< Optional. Manual ISO. Overrides manual_analog_gain. NULL if NA. Otherwise, array of
                                                                     values of num_exposures length. Order of ISO values corresponds to exposure_index of
                                                                     ae_results, e.g., manual_iso[ae_results->exposures[0].exposure_index] = 100; */
    ia_aiq_ae_manual_limits manual_limits[MAX_NUM_EXPOSURE];    /*!< Optional. Manual limits which override limits defined in AEC tunings. */
    uint32_t manual_total_target_exposure[MAX_NUM_EXPOSURE];    /*!< Optional. Manual total target exposure. */
    ia_aiq_ae_exposure_distribution_priority exposure_distribution_priority; /*!< Mandatory. AEC exposure distribution priority mode. */
    float32_t manual_convergence_time;                              /*!< Mandatory. Manual AEC convergence speed in seconds.
                                                                     -1.0 if NA (uses tunings).
                                                                     0.0  means convergence filters are bypassed, this is similar behavior as in previous
                                                                          API when using frame_use still
                                                                     > 0.0  Overrides convergence speed from tunings. */
    bool is_bypass_result;                                       /*!< Optional. True if AE result need save to IntelCCA*/
} cca_ae_input_params;

/*!
 * \brief exposure results.
 */
typedef struct
{
    ia_aiq_exposure_parameters exposure[MAX_EXPO_PLAN]; /*!< Exposure parameters to be used in the next frame in sensor specific format. */
    ia_aiq_exposure_sensor_parameters sensor_exposure[MAX_EXPO_PLAN]; /*!< Exposure parameters to be used in the next frame in sensor specific format. */
    float32_t distance_from_convergence;       /*!< Distance of convergence as an EV shift value. Negative is underexposure, positive is overexposure */
    bool converged;
} cca_ae_exposure;

/*!
 *  \brief AEC hist weight map.
 */
typedef struct
{
    uint16_t width;     /*!< Width of the weight grid. */
    uint16_t height;    /*!< Height of the weight grid. */
    uint8_t  weights[MAX_RGBS_STATS_GRID_SIZE]; /*!< Multipliers (weight) of RGB values in the grid. Values range [0, 15]. */
} cca_hist_weight_grid;

/*!
 * \brief AEC results.
 */
typedef struct
{
    cca_ae_exposure exposures[MAX_SENSOR]; /*!< Exposure results to be used in the next frame. */
    uint32_t num_exposures;                            /*!< The number of calculated exposures. */
    ia_aiq_flash_parameters flashes[MAX_NUM_FLASH_LEDS]; /*!< Array of flash parameters for each flashes to be used in the next frame. */
    uint32_t num_flashes;
    ia_aiq_bracket_mode multiframe;                     /*!< AEC may propose to use multiframe for optimal results. */
    ia_aiq_aperture_control aperture_control;          /*!< Aperture control parameters. */
    cca_hist_weight_grid weight_grid;   /*!< AEC weight wap used by next frame. */
    ia_aiq_ae_flicker_reduction flicker_reduction_mode; /*!< Flicker reduction mode proposed by the AEC algorithm */
} cca_ae_results;

/*!
 *  \brief Input parameter structure for AF algorithm.
 */
typedef struct
{
    ia_aiq_frame_use frame_use;                                 /*!< Mandatory. Target frame type of the AF calculations (Preview, Still, video etc.). */
    uint32_t lens_position;                                     /*!< Mandatory. Current lens position. */
    uint64_t lens_movement_start_timestamp;                     /*!< Mandatory. Lens movement start timestamp in us. Timestamp is compared against
                                                                     statistics timestamp
                                                                     to determine if lens was moving during statistics collection. */
    ia_aiq_af_operation_mode focus_mode;                        /*!< Mandatory. Focusing mode. */
    ia_aiq_af_range focus_range;                                /*!< Mandatory. Focusing range. Only valid when focus_mode is ia_aiq_af_operation_mode_auto. */
    ia_aiq_af_metering_mode focus_metering_mode;                /*!< Mandatory. Metering mode (multispot, touch). */
    ia_aiq_flash_mode flash_mode;                               /*!< Mandatory. User setting for flash. */
    ia_rectangle focus_rect;                                    /*!< Optional. */
    ia_aiq_manual_focus_parameters manual_focus_parameters;     /*!< Optional. Manual focus parameters (manual lens position, manual focusing distance).
                                                                     Used only if focus mode 'ia_aiq_af_operation_mode_manual' is used. */
    bool trigger_new_search;                                    /*!< TRUE if new AF search is needed, FALSE otherwise. Host is responsible for flag cleaning. */
    bool exit_success_state;                                    /*!< TRUE if AF need exit success state and if trigger_new_search is true.*/
} cca_af_input_params;

/*!
 *  \brief output of AF algorithm.
 */
typedef struct
{
    ia_aiq_af_status status;                           /*!< Focus status */
    uint32_t next_lens_position;                       /*!< Next lens position */
    int32_t next_focus_distance;                      /*!< Next focusing distance [mm] between the lens and object plane */
    uint16_t current_focus_distance;                   /*!< Current focusing distance [mm] between the lens and object plane */
    ia_aiq_lens_driver_action lens_driver_action;      /*!< Lens driver action*/
    bool use_af_assist;                                /*!< True if the af assist light is to be used at half press, false otherwise */
    bool final_lens_position_reached;                  /*!< Lens has reached the final lens position */
} cca_af_results;


/*!
 *  \brief Input parameter structure for AWB algorithm.
 */
typedef struct
{
    bool is_bypass;                                   /*!< Mandatory. bypass AWB run. */
    ia_aiq_awb_operation_mode scene_mode;             /*!< Mandatory. AWB scene mode. */
    ia_aiq_awb_manual_cct_range manual_cct_range;     /*!< Optional. Manual CCT range. Used only if AWB scene mode
                                                           'ia_aiq_awb_operation_manual_cct_range' is used. */
    ia_coordinate manual_white_coordinate;            /*!< Optional. Manual white point coordinate relative to the full FOV of the scene.
                                                           Used only if AWB scene mode 'ia_aiq_awb_operation_manual_white' is used. */
    float32_t manual_convergence_time;                    /*!< Optional. Manual AWB convergence speed in seconds. -1.0 if NA.
                                                           Overrides convergence speed from tunings. */
} cca_awb_input_params;

/*!
 * \brief Results from AWB.
 */
typedef struct
{
    float32_t accurate_r_per_g;           /*!< Accurate White Point for the image. */
    float32_t accurate_b_per_g;           /*!< Accurate White Point for the image. */
    float32_t distance_from_convergence;  /*!< Range [0.0f, 1.0f]. Distance from convergence. Value 0.0f means converged. */
    unsigned int cct_estimate;        /*!< Correlated Color Temperature estimate calculated from the accurate WP. */
} cca_awb_results;

/*!
 *  \brief Input parameter structure for GBCE algorithm.
 */
typedef struct
{
    bool is_bypass;                         /*!< Optional. Don't run gbce, just use last results*/
    float32_t ev_shift;                         /*!< Optional. Exposure Value shift [-4,4]. */
    bool gbce_on;                           /*!< Optional. This flag is used to return gamma table in output params*/
    bool athena_mode;                       /*!< Optional. This flag is used to indicate whethe athena mode is enabled in ful_gtm algo*/
} cca_gbce_input_params;

/*!
 * \brief R, G, B and Saturation grid block.
 * As defined in the AIQ statistics specification.
 * RGBS grid covers the full Field Of View (FOV) of the sensor.
 */
typedef struct
{
    rgbs_grid_block blocks_ptr[MAX_RGBS_STATS_GRID_SIZE];  /*!< RGBS blocks. */
    unsigned short grid_width;    /*!< Grid width. */
    unsigned short grid_height;   /*!< Grid height. */
    bool shading_correction;      /*!< Flag indicating if statistics was calculated using lens shading corrected data. */
} cca_rgbs_grid;

 /*!
 * \brief R, G, B and Saturation grid block for 32-bit HDR statistics.
 * As defined in the AIQ statistics specification.
 * HDR RGBS grid covers the full Field Of View (FOV) of the sensor.
 */
typedef struct
{
    hdr_rgbs_grid_block blocks_ptr[MAX_RGBS_STATS_GRID_SIZE];    /*!< HDR RGBS blocks. */
    uint32_t grid_width;            /*!< Grid width. */
    uint32_t grid_height;           /*!< Grid height. */
    uint32_t grid_data_bit_depth;   /*!< Bit depth of data in channel data. */
    bool shading_correction;        /*!< Flag indicating if statistics was calculated using lens shading corrected data. */
} cca_hdr_rgbs_grid;

/*!
 * \brief AF statistics
 * As defined in the AIQ statistics specification.
 * AF grid covers the full Field Of View (FOV) of the sensor.
 */
typedef struct
{
    uint16_t grid_width;    /*!< Number of block elements horizontally in a grid. */
    uint16_t grid_height;   /*!< Number of block elements vertically in a grid. */
    uint16_t block_width;   /*!< Block width (bq per block element). */
    uint16_t block_height;  /*!< Block height (bq per grid element). */
    int32_t filter_response_1[MAX_AF_STATS_GRID_SIZE];       /*!< Filter response of filter 1 (e.g. low pass, used by auto focus). */
    int32_t filter_response_2[MAX_AF_STATS_GRID_SIZE];       /*!< Filter response of filter 2 (e.g. high pass, used by auto focus). */
} cca_af_grid;

/** @brief Face state data.
 * This structure is used to hold inputs and outputs of functions and also works as a handle of the engine instance.
 */
typedef struct
{
    uint32_t      num_faces;                 /*!< Number of faces in the recently processed input frame. */
    ia_atbx_face  faces[MAX_FACE_NUM];       /*!< Array of face information. */
    bool updated;                            /*!< The update status of face. true is the real statistics, and false is the false statistics that have not been updated. */
    bool is_video_conf;                      /*!< video confenerce mode. */
} cca_face_state;

/*!
 *  \brief Input parameter structure of stats for AIQ algorithm.
 */
typedef struct
{
    uint64_t frame_id;                  /*!< The frame identifier which identifies to which frame the given statistics correspond. Must be positive. */
    uint64_t frame_timestamp;           /*!< Mandatory although function will not return error, if not given. Start of frame timestamp in microseconds. */
    cca_face_state faces;               /*!< Mandatory although function will not return error, if not given. Face coordinates from external face detector.
                                             DSD will not return all scene modes, if not given. AWB will not take face information into account,
                                             if not given. */
    ia_aiq_camera_orientation camera_orientation;               /*!< The orientation of the camera. Currently unused. */
    cca_hist_weight_grid weight_grid;   /*!< Weight map to be used in the next frame histogram calculation. */
    uint16_t dvs_stats_height;                /*!< height of dvs statistics */
    uint16_t dvs_stats_width;                 /*!< width of dvs statistics */
    ia_rectangle statistics_crop_area;  /*!< Mandatory for IPU7. RGBS and AF grid area crop with respect to full field of view of sensor output using (relative)ranges from ia_coordinate.h. */
    bool using_rgbs_for_aec;            /*!< use rgbs to generate the AE histogram */
    bool bAssitLightOn;                 /*!< True if the af assist light is on, false otherwise .*/
    uint8_t AECFrameDelay;              /*!< Optional.frame delay for auto exposure to take effect*/
    bool hasEmbeddedData;               /*!< Optional. TRUE if embedded data is available*/
} cca_stats_params;

typedef struct
{
    bool get_rgbs_stats;                /*!< If get rgbs statistics back. */
    ia_aiq_rgbs_grid rgbs_grid;
    rgbs_grid_block rgbs_blocks[BXT_RGBS_GRID_MAX_NUM_ELEMENTS];
} cca_out_stats;

/*!
*  \brief Input parameter structure for Parameter adaptor.
*/
typedef struct
{
    ia_aiq_color_channels color_gains;              /*!< Optional. RGB gains for each color channels.
                                                         These gain will be applied on top of RGB gains calculated from WB results. */
    bool enable_gtm_desaturation;                   /*!< Optional, use base_gamma to calculate saturation factor */
} cca_pa_input_params;

/*!
 *  \brief Input parameter structure for Shading Adaptor.
 */
typedef struct
{
    float32_t manual_convergence_time;          /*!< Mandatory, in seconds. Allows override of tunings for LSC transition interval
                                                 -1.0 if NA (uses tunings).
                                                 0.0  forces update of LSC table, this is similar behavior as in previous API when using frame_use still
                                                 > 0.0  Overrides convergence speed from tunings */
    bool lsc_on;                            /*!< Optional, return the lsc results */
} cca_sa_input_params;

/*!
 *  \brief output structure for Shading Adaptor.
 */
typedef struct
{
    uint16_t lsc_grid[MAX_LSC_DIM_SIZE][MAX_LSC_DIM_SIZE][MAX_LSC_GRID_SIZE];   /*!< Arrays of the LSC grid for all color channels.*/
    uint16_t width;                            /*!< Width of LSC grid. */
    uint16_t height;                           /*!< Height of LSC grid. */
    cmc_bayer_order color_order;               /*!< Bayer order of LSC grid. */
    bool lsc_update;                           /*!< LSC LUT is updated */
} cca_sa_results;

/*!
 *  \brief params for global brightness and contrast enhancement.
 */
typedef struct
{
    bool have_manual_settings;                      /*!< have manual gamma/tm lut. */
    float32_t r_gamma_lut[MAX_GAMMA_LUT_SIZE];          /*!< Gamma LUT for R channel. Range [0.0, 1.0]. */
    float32_t b_gamma_lut[MAX_GAMMA_LUT_SIZE];          /*!< Gamma LUT for B channel. Range [0.0, 1.0]. */
    float32_t g_gamma_lut[MAX_GAMMA_LUT_SIZE];          /*!< Gamma LUT for G channel. Range [0.0, 1.0]. */
    uint32_t gamma_lut_size;                        /*!< size of gamma LUT. */
    float32_t tone_map_lut[MAX_TONE_MAP_LUT_SIZE];      /*!< GTM LUT. */
    uint32_t tone_map_lut_size;                     /*!< size of GTM LUT. */
} cca_gbce_params;

/*!
 *  \brief params for parameter adaptor.
 */
typedef struct
{
    bool enable_manual_settings;               /*!< indicate input params is valid. */
    float32_t color_conversion_matrix[3][3];       /*!< CC matrix. */
    ia_aiq_color_channels color_gains;         /*!< RGB gains for each color channels. */
} cca_pa_params;

/*!
 *  \brief input parameter structure for aiq algorithm comp.
 */
typedef struct
{
    uint32_t bitmap;                /*!< algo(af,awb,gbce,pa,sa) enable/disable bitmap (CCAModuleBitMap) */
    cca_af_input_params af_input;
    cca_awb_input_params awb_input;
    cca_gbce_input_params gbce_input;
    cca_pa_input_params pa_input;
    cca_sa_input_params sa_input;
} cca_aiq_params;

/*!
 *  \brief results structure for aiq algorithm comp.
 */
typedef struct
{
    cca_af_results af_output;    /*!< auto focus algo output */
    cca_awb_results awb_output;  /*!< auto white balance algo output */
    cca_sa_results sa_output;    /*!< shading adaptor algo focus output */
    cca_gbce_params gbce_output; /*!< global brightness contrast enhancement algo output */
    cca_pa_params  pa_output;    /*!< parameter adaptor algo output */
} cca_aiq_results;

/*!
 *  \brief structure for LTM statistics.
 */
typedef struct
{
    ia_image_full_info image_info;       /*!< image info e.g image resolution */
    uint32_t size;                       /*!< length of SIS */
    uint8_t data[MAX_SIS_FRAME_SIZE];    /*!< SIS frame */
} cca_ltm_statistics;

/*!
 *  \brief input params of LTM
 */
typedef struct
{
    ia_ltm_level ltm_level;                 /*!< Mandatory. LTM level. -1 to use tuning defaults.*/
    float32_t ev_shift;                         /*!< Optional. (ob) Exposure Value shift [-4,4]. */
    uint8_t ltm_strength_manual;            /*!< Optional. (ob) User defined manual control for ltm strength, will be casted into unsigned char,
                                                 [0, 200], default is 100 and means no manual effect*/
    int16_t frame_width;                    /*!< Mandatory. Width of the frame where the results will be applied. */
    int16_t frame_height;                   /*!< Mandatory. Height of the frame where the results will be applied. */
    cca_ltm_statistics sis;                 /*!< Mandatory. downscaling raw image as LTM statistics. */
} cca_ltm_input_params;


/*!
 * \brief  structure contains DVS statistics.
 */
typedef struct
{
    uint32_t vector_count;              /*!< Number of motion vectors */
    ia_dvs_motion_vector motion_vectors[MAX_DVS_VECTOR_COUNT];   /*!< Table of local motion vectors. Contains [vector_count] values. */
} cca_dvs_statistics;

/*!
 * \brief  structure contains DVS configuration.
 */
typedef struct
{
    ia_isp_bxt_resolution_info_t gdc_resolution_history;
    ia_isp_bxt_resolution_info_t gdc_resolution_info;
    int32_t pre_gdc_top_padding;
    int32_t pre_gdc_bottom_padding;
    int32_t gdc_filter_width;
    int32_t gdc_filter_height;
    uint8_t splitMetadata[GDC_SPLIT_METADATA_LEN];
} cca_gdc_configuration;

/*!
 * \brief  struct of zoom parameters.
 */
struct cca_dvs_zoom
{
    float32_t digital_zoom_ratio;               /*!< Digital zoom ratio */
    float32_t digital_zoom_factor;              /*!< If LGD correction is enabled and envelope is not big enough, small amount of DZ is automatically applied. */
    ia_dvs_zoom_mode zoom_mode;             /*!< Digital zooming mode */
    ia_rectangle zoom_region;               /*!< Zooming region which defines area to be scaled for the output. */
    ia_coordinate zoom_coordinate;          /*!< Zooming coordinate which defines point where digital zoom is applied. */
};

/*!
*  \brief IA_ISP_BXT parameter input structure.
*/
typedef struct
{
    size_t size;
    uint8_t data[MAX_PAL_TUNING_SIZE];
} cca_pal_tuning;

/*!
*  \brief parameters structure for customer customization.
*/
typedef struct
{
    int count;                                        /*!< number of customized parameters */
    float32_t parameters[MAX_CUSTOM_CONTROLS_PARAM_SIZE]; /*!< customized parameters */
} cca_custom_control_params;

/*!
*  \brief ia view parameters structure for image rotation/affine...
*/
typedef struct
{
    bool enabled;                  /*!< enable/disable the feature */
    ia_view_config_t view_config;  /*!< configuration of ia view */
} cca_view_params;

/*!
*  \brief program group of pipeline configuration as known as graph config
*/
typedef struct
{
    ia_isp_bxt_program_group base;
    ia_isp_bxt_run_kernels_t run_kernels[MAX_KERNEL_NUMBERS_IN_PIPE];  /*!< Array of kernels in the program group. */
    ia_isp_bxt_pipe_t pipe[MAX_KERNEL_NUMBERS_IN_PIPE];                /*!< The graph of kernels in the program group .*/
    ia_isp_bxt_resolution_info_t resolution_info[MAX_KERNEL_NUMBERS_IN_PIPE];          /*!< Resolution change to be done in this kernel. NULL, if kernel doesn't change resolution. */
    ia_isp_bxt_resolution_info_t resolution_history[MAX_KERNEL_NUMBERS_IN_PIPE];       /*!< Resolution changes done before current kernel with respect to sensor output. NULL, if not available*/
} cca_program_group;

/*!
*  \brief AIC parameters input params structure including 3A and manual settings
*/
typedef struct
{
    ia_aiq_advanced_ccm_t preferred_acm;       /*!< Optional, manual setting for acm to replace the acm in PA results */
    uint32_t stream_id;                        /*!< Optional. If program_group is not given, stream_id is used to fetch all the tunings for all the kernels
                                                    associated with the stream_id. */
    uint32_t seq_id;                           /*!< Optional. sequence number for aic run */
    uint32_t dvs_id;                           /*!< Optinal. sequence number for DVS */
    ia_isp_feature_setting nr_setting;         /*!< Mandatory. Feature setting for noise reduction algorithms. */
    ia_isp_feature_setting ee_setting;         /*!< Mandatory. Feature setting for edge enhancement algorithms. */
    int8_t manual_brightness;                  /*!< Optional. Manual brightness value range [-128,127]. Value 0 means no change. */
    int8_t manual_contrast;                    /*!< Optional. Manual contrast value range [-128,127]. Value 0 means no change. */
    int8_t manual_hue;                         /*!< Optional. Manual hue value range [-128,127]. Value 0 means no change.
                                                    Value -96 means red become blue, green become red, blue become green */
    int8_t manual_saturation;                  /*!< Optional. Manual saturation value range [-128,127]. Value 0 means no change. */
    ia_isp_effect effects;                     /*!< Optional. Manual setting for special effects. Combination of ia_isp_effect enums.*/
    float32_t manual_digital_gain;                 /*!< Optional. Additional digital gain that is applied to all color channels of the image before ISP
                                                    statistics collection. Values less than 1.0 means no additional gain. */
    ia_media_format media_format;              /*!< Mandatory. Selected Digital television output format.(e.g. BT709) */
    cca_program_group program_group;           /*!< Program group parameters for running AIC */
    cca_custom_control_params custom_controls; /*!< Optional. Custom control parameter for interpolating between different tunings.
                                                    If custom controls are not used, pointer can be set as null.*/
    cca_pal_tuning pal_override;               /*!< Optional. Set of parameters for overriding tunings from CPF. Parameters need to follow
                                                    Algo API binary format. Binary may contain multiple parameter sets.
                                                    Can be set as null if PAL override functionality is not used. */
    cca_view_params view_params;               /*!< Optional. View parameters for running in GDC5 mode.*/
    ia_isp_bxt_gdc_limits gdc_mbr_limits;      /*!< Optional. GDC MBR limits for WFOV usecases */
    cca_pa_params manual_pa_setting;           /*!< Optional. manual settings (ccm & gain) for pa results.*/
    cca_gbce_params manual_gbce_setting;       /*!< Optional. manual settings (gamma lut) for gbce results.*/
    bool force_lsc_update;                     /*!< Optional. force to update LSC for SA results.*/
    ia_isp_call_rate_control call_rate_control; /*!< Optional. algo run frequency for power saving purpose.*/
    ia_isp_bxt_csc csc_matrix;                  /*!< Optional. manual rgb2yuv matrix for bxt_csc.*/
    uint32_t gain_id_gaic;                        /*!< Optional. tell which gain is used by generic AIC in multi-expo case.*/
} cca_pal_input_params;

/*!
*  \brief cmc parsed structure.
*/
typedef struct
{
    uint16_t base_iso;
    cmc_optomechanics_t optics;
    float32_t min_ag;
    float32_t max_ag;
    float32_t min_dg;
    float32_t max_dg;
    uint16_t lut_apertures;
    int32_t media_format;
    tnr7us_trigger_info_t tnr7us_trigger_info;
} cca_cmc;

/*!
*  \brief initlization paramters of CCA Flow.
*/
struct cca_init_params{
    cca_cpf aiq_cpf;                 /*!< Mandatory. tuning data */
    cca_nvm aiq_nvm;                 /*!< Mandatory. sensor nvm data */
    cca_aiqd aiq_aiqd;               /*!< Mandatory. aiq algo calibration data, NULL for 1st time launch */
    uint32_t bitmap;             /*!< Mandatory. list all components (CCAModuleBitMap) that need initialization. */
    ia_aiq_frame_params frameParams; /*!< Mandatory. Sensor frame parameters. Describe frame scaling/cropping done in sensor. */
    ia_aiq_frame_use frameUse;       /*!< Mandatory. scenario for use case still/preview/video */
    //BComp init params
    float32_t conversionGainRatio;
    ia_bcomp_dol_mode_t dolMode;
    //DVS
    CCADVSOutputType dvsOutputType;  /*!< Mandatory. DVS algo output configuration must match with GDC kernel */
    float32_t dvsZoomRatio;              /*!< Mandatory. zoom factor */
    bool enableVideoStablization;    /*!< Mandatory. enable/disable video statlization */
    cca_gdc_configuration gdcConfig; /*!< Mandatory. GDC resolution configuration */
    uint8_t aiqStorageLen;           /*!< Mandatory. lehgth of history to store algo results */
    uint8_t aecFrameDelay;           /*!< Mandatory. frame delay for auto exposure take effect */
    cca_stream_ids aic_stream_ids;   /*!< Optional. the stream id for aic handle*/
    cca_stream_ids dvs_ids;          /*!< Optional. the DVS handle number */
    cca_init_params() :
        frameUse(ia_aiq_frame_use_preview),
        conversionGainRatio(1),
        dolMode(ia_bcomp_non_dol),
        dvsOutputType(CCA_DVS_MORPH_TABLE),
        dvsZoomRatio(1.0f),
        enableVideoStablization(false),
        aiqStorageLen(3),
        aecFrameDelay(2)
        {
            bitmap = CCA_MODULE_AE | CCA_MODULE_AF | CCA_MODULE_AWB |
                     CCA_MODULE_PA | CCA_MODULE_SA | CCA_MODULE_GBCE |
                     CCA_MODULE_LTM | CCA_MODULE_DVS | CCA_MODULE_OB |
                     CCA_MODULE_BCOM;

            IA_MEMSET(&aiq_cpf, 0, sizeof(aiq_cpf));
            IA_MEMSET(&aiq_nvm, 0, sizeof(aiq_nvm));
            IA_MEMSET(&aiq_aiqd, 0, sizeof(aiq_aiqd));
            IA_MEMSET(&frameParams, 0, sizeof(frameParams));
            IA_MEMSET(&gdcConfig, 0, sizeof(gdcConfig));
            IA_MEMSET(&aic_stream_ids, 0, sizeof(aic_stream_ids));
            IA_MEMSET(&dvs_ids, 0, sizeof(dvs_ids));
        }
};
/*!
*  \brief paramters of Multi CCA Flow.
*/
typedef enum {
    front = 0,
    right,
    back,
    left,
} ccd_sv_id;

typedef struct
{
    uint8_t cam_idx;     /*!< multiple camera index. */
    bool main_cam_flag;   /*!< current camera is main camera or not. */
    ccd_sv_id sv_idx;     /*!< surround view camera index. */
}cca_multi_id;

typedef struct
{
    uint8_t cam_num;    /*!< maximum multiple camera number. */
    uint8_t group_type; /*!< 0, 1:X 1, X:X. */
    cca_init_params* init_params;
}cca_multi_cam;

}//cca
#endif //INTELCCA_TYPES_H_
