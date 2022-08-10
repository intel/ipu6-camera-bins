/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2012-2021 Intel Corporation
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

/*!
 * \file ia_ccat.h
 * \brief Definitions of common analysis functions used by Intel 3A modules.
*/

#ifndef IA_CCAT_H_
#define IA_CCAT_H_

#include "ia_configuration.h"
#include "ia_ccat_types.h"
#include "ia_aiq_types.h"
#include "ia_cmc_types.h"
#include "ia_ccat_params.h"
#include "t3aplus.h"
#ifdef IA_CCAT_LIGHT_SOURCE_ESTIMATION_ENABLED
#include "chromaticity.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define IA_CCAT_ACM_SECTORS_MAX_NUM 36
#define PERCENTAGE_2_DECIMAL 0.01F

typedef struct ia_ccat_t ia_ccat;
typedef struct frame_info_t ia_ccat_frame_info;

LIBEXPORT ia_ccat*
ia_ccat_init(void);

/*!
 * \brief (Re)allocates memory for CMC/tunings used inside CCAT.
 * Given CMC structure must be valid throughout lifetime of CCAT.
 */
LIBEXPORT ia_err
ia_ccat_set_tunings(
    ia_ccat *a_ccat_ptr,        /*!< \param[in] Analysis toolbox's internal structure. */
    const ia_cmc_t *a_cmc_ptr); /*!< \param[in] CMC structure that will be stored and copied/modified for CCAT internal use. */

/*!
 * \brief De-initializes and frees memory allocated in ia_ccat_init() function.
 */
LIBEXPORT void
ia_ccat_deinit(ia_ccat *a_ccat_ptr); /*!< \param[in] Analysis toolbox's internal structure. */

/*!
 * \brief Statistics setting and initialization functions.
 *
 * Note: frame_parameters_available and frame_type:
 * CCAT keeps shallow copy of ia_ccat_frame_parameters structure for all frame_types (eg. flash and nonflash frame parameters) and accesses
 * parameters behind given pointers directly during its lifetime. When ia_ccat_set_frame_parameters is called with new set of parameters
 * (and frame_parameters_available is set to true), previously given frame parameters (for the given frame_type) will no longer be used and
 * can be freed/reused by CCAT client.
 * If CCAT client wants to invalidate given frame parameters (for particular frame_type) without new set of parameters, frame_parameters_available
 * flag should be set to false. This needs to be done for all frame_types that CCAT client wants to invalidate.
 *
 * Note: statistics_crop_area:
 * This information is needed to restrict use parameters from Camera Module Characterization (for example LSC),
 * which was done relative to the full sensor resolution (FOV).
 * For example, if sensor captures image size 1600x1200 (4:3 ratio) pixels and only 1600x900 (16:9) area is used from the center.
 * So, image area at top and bottom must not be used (needs to be cropped 150 pixels from top and bottom).
 * statistics_crop_area crop rectangle needs to be given relative to IA_COORDINATE_WIDTH, IA_COORDINATE_HEIGHT found in ia_coordinate.h.
 * Thus given structure in this example case should be:
 *  statistics_crop_area.left = (0*IA_COORDINATE_WIDTH/1600);
 *  statistics_crop_area.top = (150*IA_COORDINATE_HEIGHT/1200);
 *  statistics_crop_area.right = (0*IA_COORDINATE_WIDTH/1600);
 *  statistics_crop_area.bottom = (150*IA_COORDINATE_HEIGHT/1200);
 *
 */
LIBEXPORT ia_err
ia_ccat_set_frame_parameters(
    ia_ccat *a_ccat_ptr,                                                           /*!< \param[in] Analysis toolbox internal data structure. */
    const ia_ccat_frame_statistics *a_in_statistics_ptr,                        /*!< \param[in] Input statistics */
    const ia_ccat_frame_parameters *a_in_parameters_ptr);                       /*!< \param[in] Input parameters */

/*!
 * \brief Registers percentile that will be calculated from histograms covering whole frame.
 */
LIBEXPORT ia_err
ia_ccat_register_percentile_frame(
    ia_ccat *a_ccat_ptr,                    /*!< \param[in] Analysis toolbox internal data structure. */
    float32_t a_percentile);

/*!
 * \brief Registers percentile that will be calculated from histograms covering whole frame.
 */
LIBEXPORT ia_err
ia_ccat_get_percentile_list_frame(
    ia_ccat *a_ccat_ptr,                    /*!< \param[in] Analysis toolbox internal data structure. */
    uint32_t *num_percentiles,              /*!< \param[out] number of percentiles for frame.*/
    const float32_t **percentile_list);               /*!< \param[out] address of percentiles list for frame.*/

/*!
 * \brief Reserves frame into use.
 * \return Error code.
 */
LIBEXPORT ia_err
ia_ccat_hold_frame(
    ia_ccat *a_ccat_ptr,                    /*!< \param[in]  Analysis toolbox internal data structure. */
    ia_ccat_frame_type a_frame_type,    /*!< \param[in]  Frame type to acquire. */
    ia_ccat_frame_info **a_frame_info_ptr); /*!< \param[out] Pointer to acquired frame info. */

LIBEXPORT ia_err
ia_ccat_release_frame(
    ia_ccat *a_ccat_ptr,                    /*!< \param[in] Analysis toolbox internal data structure. */
    ia_ccat_frame_info **a_frame_info_ptr); /*!< \param[in] Frame info pointer that is no longer used. */

LIBEXPORT ia_err
ia_ccat_get_frame_percentile(
    ia_ccat_frame_info *a_frame_info_ptr,
    float32_t a_percentile,
    uint32_t a_exposure_index,
    ia_ccat_histogram_type a_histogram_type,
    float32_t *a_percentile_bin_ptr);

LIBEXPORT ia_err
ia_ccat_get_frame_normalized_percentile(
    ia_ccat_frame_info *a_frame_info_ptr,
    float32_t a_percentile,
    uint32_t a_exposure_index,
    ia_ccat_histogram_type a_histogram_type,
    float32_t *a_normalized_percentile_ptr);

LIBEXPORT ia_err
ia_ccat_get_frame_total_gain(
    ia_ccat_frame_info *a_frame_info_ptr,
    uint32_t a_exposure_index,
    float32_t *a_total_gain_ptr);

LIBEXPORT ia_err
ia_ccat_calculate_total_gain(
    const ia_aiq_exposure_parameters *a_exposure_params,
    float32_t *total_gain);

LIBEXPORT ia_err
ia_ccat_get_frame_total_exposure_time(
    ia_ccat_frame_info *a_frame_info_ptr,
    uint32_t a_exposure_index,
    uint32_t *a_total_exposure_time_ptr);

LIBEXPORT ia_err
ia_ccat_get_frame_lux_level_estimate(
    ia_ccat_frame_info *a_frame_info_ptr,
    uint32_t a_exposure_index,
    float32_t *a_lux_level_estimate_ptr);

LIBEXPORT ia_err
ia_ccat_get_frame_filtered_lux_level_estimate(
    ia_ccat_frame_info *a_frame_info_ptr,
    uint32_t a_exposure_index,
    float32_t *a_filtered_lux_level_estimate);

LIBEXPORT ia_err
ia_ccat_hold_frame_histogram(
    ia_ccat_frame_info *a_frame_info_ptr,
    uint32_t a_exposure_index,
    ia_ccat_histogram_type a_histogram_type,
    const ia_histogram **a_histogram_ptr);

LIBEXPORT ia_err
ia_ccat_get_frame_camera_orientation(
    ia_ccat_frame_info *a_frame_info_ptr,
    ia_aiq_camera_orientation *a_camera_orientation);

LIBEXPORT ia_err
ia_ccat_get_frame_ccat(
    ia_ccat_frame_info *a_frame_info_ptr,
    ia_ccat **ccat_ptr);

LIBEXPORT ia_err
ia_ccat_estimate_percentile_with_saturation_frame(
    ia_ccat_frame_info *a_frame_info_ptr,
    ia_ccat_histogram_type a_ccat_histogram_type,
    uint32_t exposure_index,
    float32_t a_full_sat_step,
    float32_t a_percentile,
    uint32_t *adjusted_prc);

LIBEXPORT ia_err
ia_ccat_release_frame_histogram(
    ia_ccat_frame_info *a_frame_info_ptr,
    uint32_t a_exposure_index,
    ia_ccat_histogram_type a_histogram_type,
    const ia_histogram **a_histogram_ptr);

LIBEXPORT ia_err
ia_ccat_get_frame_hist_info(
    ia_ccat_frame_info *a_frame_info_ptr,
    uint32_t a_exposure_index,
    ia_ccat_histogram_type a_histogram_type,
    float32_t *a_mean_ptr,
    float32_t *a_saturation_percent_ptr,
    float32_t *a_max_ptr);

LIBEXPORT ia_err
ia_ccat_get_frame_histogram_segment_average(
    ia_ccat_frame_info *a_frame_info_ptr,
    uint32_t a_exposure_index,
    ia_ccat_histogram_type a_histogram_type,
    float32_t a_low_limit,
    float32_t a_high_limit,
    float32_t *a_average_ptr);

LIBEXPORT ia_err
ia_ccat_get_frame_ae_results(
    ia_ccat_frame_info *a_frame_info_ptr,
    const ia_aec_results **a_ae_results_ptr);

LIBEXPORT ia_err
ia_ccat_get_frame_awb_results(
    ia_ccat_frame_info *a_frame_info_ptr,
    const ia_aiq_awb_results **a_awb_results_ptr);

LIBEXPORT ia_err
ia_ccat_get_frame_af_results(
    ia_ccat_frame_info *a_frame_info_ptr,
    const ia_aiq_af_results **a_af_results_ptr);

LIBEXPORT ia_err
ia_ccat_get_frame_sa_results(
    ia_ccat_frame_info *a_frame_info_ptr,
    const ia_aiq_sa_results_v1 **a_sa_results_ptr);

LIBEXPORT ia_err
ia_ccat_get_frame_pa_results(
    ia_ccat_frame_info *a_frame_info_ptr,
    const ia_aiq_pa_results_v1 **a_pa_results_ptr);

LIBEXPORT ia_err
ia_ccat_get_frame_exposure_result(
    ia_ccat_frame_info *a_frame_info_ptr,
    uint32_t a_exposure_index,
    const ia_aec_exposure_result **a_exposure_result_ptr);

LIBEXPORT ia_err
ia_ccat_get_frame_exposure_parameters(
    ia_ccat_frame_info *a_frame_info_ptr,
    uint32_t a_exposure_index,
    const ia_aec_exposure_parameters **a_exposure_parameters_ptr);

/*!
 *  Calculate amount of pixels (normalized) in a segment defined by min and max
 *  values. Raw histograms are used to compute area in between of low and high
 *  bins, that define of segment.
 *
 *
 *  \param [in]  frame_info         A pointer to the frame info.
 *  \param [in]  a_low_limit        Low limit bin (min 0).
 *  \param [in]  a_high_limit       High limit bin (max 255).
 *  \param [in]  a_num_exposures    Number of exposures, or number of RGBS statistics grids.
 *  \param [out] power_normal       Amount of pixels (normalized) in a segment defined by min and max values
 */
LIBEXPORT ia_err
ia_ccat_calculate_segment_size(
    ia_ccat_frame_info *a_frame_info_ptr,
    uint16_t a_low_limit,
    uint16_t a_high_limit,
    uint16_t a_num_exposures,
    float32_t *power_noraml);

LIBEXPORT ia_err
ia_ccat_get_frame_statistics_grid_changed(
    ia_ccat_frame_info *a_frame_info_ptr,
    bool *statistics_grid_changed);

#ifdef IA_AEC_FEATURE_WEIGHT_GRID
LIBEXPORT ia_err
ia_ccat_get_frame_histogram_weight_map(
    ia_ccat_frame_info *a_frame_info_ptr,
    const ia_aec_weight_grid **a_weight_grid_ptr);

LIBEXPORT ia_err
ia_ccat_get_frame_weight_map_changed(
    ia_ccat_frame_info *a_frame_info_ptr,
    bool *weight_map_changed);
#endif

LIBEXPORT ia_err
ia_ccat_get_frame_sensor_exposure_parameters(
    ia_ccat_frame_info *a_frame_info_ptr,
    uint32_t a_exposure_index,
    ia_aiq_exposure_sensor_parameters *a_exposure_sensor_parameters_ptr);

LIBEXPORT ia_err
ia_ccat_get_frame_color_gains(
    ia_ccat_frame_info *a_frame_info_ptr,
    ia_aiq_color_channels *a_color_gains_ptr);

LIBEXPORT ia_err
ia_ccat_get_frame_color_correction_matrix(
    ia_ccat_frame_info *a_frame_info_ptr,
    float32_t(*a_matrix_ptr)[3][3]);

LIBEXPORT ia_err
ia_ccat_get_frame_timestamp(
    ia_ccat_frame_info *a_frame_info_ptr,
    uint64_t *a_frame_timestamp_ptr);

LIBEXPORT ia_err
ia_ccat_get_frame_id(
    ia_ccat_frame_info *a_frame_info_ptr,
    uint64_t *frame_id_ptr);

/*!
 * \brief Get information about number of exposures and which of them is the center (in case of multi exposure frame) exposure index.
 */
LIBEXPORT ia_err
ia_ccat_get_frame_exposure_index_info(
    ia_ccat_frame_info *a_frame_info_ptr,                                    /*!< [in] Frame handle. */
    uint32_t *a_center_exposure_index_ptr,                               /*!< [out] Center (in case of multiple exposures) / default exposure index . */
    uint32_t *a_num_exposures_ptr);                                      /*!< [out] Number of exposures/statistics in the frame. */

/*!
 * \brief Get closest ACMs for a white point.
 * Note: Only CCMs are updated in out_acm structure.
 */
LIBEXPORT ia_err
ia_ccat_calculate_weighted_acm(
    ia_ccat_frame_info *a_frame_info_ptr,                                    /*!< [in] Frame handle. */
    const cmc_parsed_advanced_color_matrices_ls_t *a_parsed_acms_ls,      /*!< [in] ACMs from CMC or AIQ tunings. */
    uint32_t a_num_advanced_color_matrices,                        /*!< [in] Number of advanced color matrices */
    uint32_t a_sector_count,                                         /*!< [in] Number of sectors in ACMs. */
    cmc_chromaticity a_point,                                            /*!< [in] Chromaticity to calculate distance (x and y axis) against input list of chromaticities in R/G and B/G plane. */
    t3aplus_parsed_rgbir_t* t3aplus_rgbir,
    float32_t (*a_out_acm)[3][3],                                            /*!< [out] Resulting ACMs. Array length is defined by sector_count. */
    float32_t (*a_out_ccm)[3][3],                                            /*!< [out] Resulting CCM. */
    float32_t (*ccm_weights)[CMC_NUM_LIGHTSOURCES]);                       /*!< [out] CCM weight. */

/*!
 * \brief Get closest CCMs for a white point.
 */
LIBEXPORT ia_err
ia_ccat_calculate_weighted_ccm(
    ia_ccat_frame_info *a_frame_info_ptr,                                    /*!< [in] Frame handle. */
    const cmc_parsed_color_matrices_t *a_parsed_color_matrices_ptr,          /*!< [in] CCM characterization data with R/G and B/G chromaticities. */
    bool output_ccm_type_preferred,                                    /*!< [in] Flag to control output CCM to be preferred (true) or accurate (false). */
    cmc_chromaticity a_point,                                            /*!< [in] Chromaticity to calculate distance (x and y axis) against input list of chromaticities in R/G and B/G plane. */
    t3aplus_parsed_rgbir_t* t3aplus_rgbir,
    float32_t (*a_out_ccm)[3][3],                                            /*!< [out] Resulting CCM. */
    float32_t (*ccm_weights)[CMC_NUM_LIGHTSOURCES]);                       /*!< [out] CCM weight. */

LIBEXPORT ia_err
ia_ccat_calculate_weighted_acm_cct_based(
    const cmc_parsed_advanced_color_matrices_ls_t *a_parsed_acm_ls,
    uint32_t a_num_color_matrices,
    uint32_t a_sector_count,
    float32_t a_point_x,
    float32_t a_point_y,
    const locus_t* a_locus_ptr,
    int32_t num_of_cct_segments,
    ia_aiq_advanced_ccm_t *a_out_acm,
    float32_t* a_out_ccm,
    float32_t* a_ccm_weights);

LIBEXPORT ia_err
ia_ccat_get_frame_scaled_cmc_lens_shading(
    ia_ccat_frame_info *a_frame_info_ptr,
    uint32_t a_exposure_index,
    const cmc_lens_shading_correction **a_scaled_lsc_ptr);

LIBEXPORT ia_err
ia_ccat_calculate_chromaticity_based_weights(
    ia_ccat_frame_info *a_frame_info_ptr,                                      /*!< [in] Frame handle. */
    cmc_chromaticity(*a_chromaticities_ptr)[CMC_NUM_LIGHTSOURCES],       /*!< [in] CCM characterization data with R/G and B/G chromaticities. */
    cmc_cie_coords (*a_cie_coords_ptr)[CMC_NUM_LIGHTSOURCES],                /*!< [in] CCM characterization data with CIE X/Y chromaticities. */
    uint32_t a_num_chromaticities,                                     /*!< [in] Number of input chromaticities. */
    cmc_chromaticity a_point,                                              /*!< [in] Chromaticity to calculate distance (x and y axis) against input list of chromaticities in R/G and B/G plane or CIE X/Y plane. */
    ia_ccat_point_type_t a_point_type,                                   /*!< [in] Option for using accurate or preferred CCM interpolation */
    const float32_t *a_ir_proportion,                                          /*!< [in] Ir effect on chromaticity point distance (z axis). */
    const t3aplus_parsed_rgbir_t* t3aplus_rgbir,
    float32_t(*a_cct_weights)[CMC_NUM_LIGHTSOURCES],                               /*!< [out] Normalized chromaticity distances translated into weights. */
    float32_t *frame_ir_proportion);                                         /*!< [out] Frame ir proportion, ir mean divided by y_mean. */

#ifdef IA_AEC_FEATURE_FLASH
/*!
 * \brief Calculate preferred flash ratio for multi-flash using non-flash white point information. flash_ratio scale between 0-100
 */
LIBEXPORT ia_err
ia_ccat_calculate_flash_ratios(
    const cmc_multi_led_flash_t *a_flash_tunings_ptr,
    ia_ccat_frame_info *a_nonflash_frame_info_ptr,
    float32_t (*flash_ratios)[IA_AEC_FLASHES_NUM]);

/*!
 * \brief Calculate preferred flash ratio for multi-flash using non-flash white point information. flash_ratio scale between 0-100
 */
LIBEXPORT ia_err
ia_ccat_calculate_flash_ratios_frame_tuning(
    ia_ccat_frame_info *a_frame_info_ptr,
    float32_t (*flash_ratios)[IA_AEC_FLASHES_NUM]);
#endif

#ifdef IA_CCAT_IR_GRID_ENABLED
LIBEXPORT ia_err
ia_ccat_get_frame_ir_grid(
    ia_ccat_frame_info *a_frame_info_ptr,
    const ia_ccat_ir_grid **a_ir_grid_ptr);

LIBEXPORT ia_err
ia_ccat_get_frame_ir_histogram_info(
    ia_ccat_frame_info *a_frame_info_ptr,
    float32_t *a_mean_ptr,
    float32_t *a_saturation_percent_ptr,
    float32_t *a_max_ptr);

LIBEXPORT ia_err
ia_ccat_set_ir_compgain(
    ia_ccat_frame_info *a_frame_info_ptr,
    float32_t ir_compgain_isp);

LIBEXPORT ia_err
ia_ccat_get_ir_compgain(
    ia_ccat_frame_info *a_frame_info_ptr,
    float32_t *ir_compgain_ptr);
#endif

#ifdef IA_CCAT_DEPTH_GRID_ENABLED
LIBEXPORT ia_err
ia_ccat_get_frame_depth_grid(
    ia_ccat_frame_info *a_frame_info_ptr,
    const ia_depth_grid **a_depth_grid_ptr);
#endif

#ifdef IA_CCAT_RGBS_GRID_ENABLED
LIBEXPORT ia_err
ia_ccat_get_frame_rgbs_grid(
    ia_ccat_frame_info *a_frame_info_ptr,
    bool a_shading_corrected,
    uint32_t a_exposure_index,
    const ia_rgbs_grid **a_rgbs_grid_ptr);

LIBEXPORT ia_err
ia_ccat_get_frame_af_grid(
    ia_ccat_frame_info *a_frame_info_ptr,
    uint32_t a_exposure_index,
    const ia_filter_response_grid **a_af_grid_ptr);

#ifdef IA_CCAT_HSV_GRID_ENABLED
LIBEXPORT ia_err
ia_ccat_get_frame_hsv_grid(
    ia_ccat_frame_info *a_frame_info_ptr,
    uint32_t a_exposure_index,
    const ia_ccat_hsv_grid **a_hsv_grid_ptr);
#endif

#ifdef IA_CCAT_LUMINANCE_GRID_ENABLED
LIBEXPORT ia_err
ia_ccat_get_frame_luminance_grid(
    ia_ccat_frame_info *a_frame_info_ptr,
    uint32_t a_exposure_index,
    const ia_ccat_grid_char **a_luminance_grid_ptr);

#ifdef IA_CCAT_LUMINANCE_MOTION_ESTIMATE_ENABLED
LIBEXPORT ia_err
ia_ccat_get_frame_motion_level_estimate(
    ia_ccat_frame_info *a_frame_info_ptr,
    uint32_t a_exposure_index,
    float32_t *a_motion_estimate_ptr);

LIBEXPORT ia_err
ia_ccat_get_frame_luminance_average(
    ia_ccat_frame_info *a_frame_info_ptr,
    uint32_t a_exposure_index,
    float32_t *luminance_average);
#endif
#endif

#ifdef IA_CCAT_ROI_ANALYSIS_ENABLED
LIBEXPORT ia_err
ia_ccat_register_percentile_roi(
    ia_ccat *a_ccat_ptr,                    /*!< \param[in] Analysis toolbox internal data structure. */
    float32_t a_percentile);

LIBEXPORT ia_err
ia_ccat_hold_frame_histogram_roi(
    ia_ccat_frame_info *a_frame_info_ptr,
    uint32_t a_exposure_index,
    const ia_rectangle *a_roi_area_ptr,
    ia_ccat_histogram_type a_histogram_type,
    const ia_histogram **a_histogram_ptr);

LIBEXPORT ia_err
ia_ccat_release_histogram_roi(
    ia_ccat_frame_info *a_frame_info_ptr,
    uint32_t a_exposure_index,
    const ia_rectangle *a_roi_area_ptr,
    ia_ccat_histogram_type a_histogram_type,
    const ia_histogram **a_histogram_ptr);

LIBEXPORT ia_err
ia_ccat_get_frame_hist_info_roi(
    ia_ccat_frame_info *a_frame_info_ptr,
    uint32_t a_exposure_index,
    const ia_rectangle *a_roi_area_ptr,
    ia_ccat_histogram_type a_histogram_type,
    float32_t *a_mean_ptr,
    float32_t *a_saturation_percent_ptr,
    float32_t *a_max_ptr);

LIBEXPORT ia_err
ia_ccat_get_frame_percentile_roi(
    ia_ccat_frame_info *a_frame_info_ptr,
    float32_t a_percentile,
    uint32_t a_exposure_index,
    const ia_rectangle *a_roi_area_ptr,
    ia_ccat_histogram_type a_histogram_type,
    float32_t *a_percentile_bin_ptr);
#endif /* IA_CCAT_ROI_ANALYSIS_ENABLED */

#ifdef IA_CCAT_FACE_ANALYSIS_ENABLED
LIBEXPORT ia_err
ia_ccat_register_percentile_face(
    ia_ccat *a_ccat_ptr,                    /*!< \param[in] Analysis toolbox internal data structure. */
    float32_t a_percentile);

LIBEXPORT ia_err
ia_ccat_get_face_stencil(
    ia_ccat_frame_info *a_frame_info_ptr,
    uint32_t a_exposure_index,
    const ia_rectangle *a_face_area_ptr,
    const ia_ccat_grid_char **a_stencil_mask_ptr);

LIBEXPORT ia_err
ia_ccat_get_frame_faces(
    ia_ccat_frame_info *a_frame_info_ptr,
    uint32_t *a_num_faces_ptr,
    const ia_face_roi **a_faces_ptr);

LIBEXPORT ia_err
ia_ccat_get_frame_face_states(
    ia_ccat_frame_info *a_frame_info_ptr,
    bool *updated,
    bool *is_video_conf);

LIBEXPORT ia_err
ia_ccat_get_analyzed_face_area(
    ia_ccat_frame_info* a_frame_info_ptr,
    uint32_t a_exposure_index,
    const ia_face_roi *a_face_ptr,
    const ia_rectangle **area);

LIBEXPORT ia_err
ia_ccat_get_face_coverage(
    const ia_face_roi *a_face_ptr,
    float32_t *a_coverage);

LIBEXPORT ia_err
ia_ccat_hold_frame_faces_histogram(
    ia_ccat_frame_info *a_frame_info_ptr,
    const ia_face_roi *a_face_ptr,
    uint32_t a_exposure_index,
    ia_ccat_histogram_type a_histogram_type,
    const ia_histogram **a_histogram_ptr);

LIBEXPORT ia_err ia_ccat_release_histogram_face(
    ia_ccat_frame_info *a_frame_info_ptr,
    uint32_t a_exposure_index,
    const ia_face_roi *a_face_ptr,
    ia_ccat_histogram_type a_histogram_type,
    const ia_histogram **a_histogram_ptr);

LIBEXPORT ia_err
ia_ccat_get_frame_face_y_mean(
    ia_ccat_frame_info *a_frame_info_ptr,
    uint32_t a_exposure_index,
    const ia_face_roi *a_face_ptr,
    float32_t *a_face_y_mean_ptr);

LIBEXPORT ia_err
ia_ccat_get_frame_percentile_face(
    ia_ccat_frame_info *a_frame_info_ptr,
    float32_t a_percentile,
    uint32_t a_exposure_index,
    const ia_face_roi *a_face_ptr,
    ia_ccat_histogram_type a_histogram_type,
    float32_t *a_percentile_bin_ptr);

/*!
 *  Calculates the percentage of how many pixels of the given roi are contained in the luminance segment [low, high].
 */
LIBEXPORT ia_err
ia_ccat_calculate_face_coverage_in_segment(
    ia_ccat_frame_info *a_frame_info_ptr,
    uint8_t a_thr_low,
    uint8_t a_thr_high,
    const ia_face_roi *face,
    float32_t *coverage_segment);

LIBEXPORT ia_err
ia_ccat_set_face_in_exit_time(
    ia_ccat_frame_info *a_frame_info_ptr,
    bool face_in_exit_time);

LIBEXPORT ia_err
ia_ccat_get_face_in_exit_time(
    ia_ccat_frame_info *a_frame_info_ptr,
    bool* face_in_exit_time);
#endif /* IA_CCAT_FACE_ANALYSIS_ENABLED */
#endif /* IA_CCAT_RGBS_GRID_ENABLED */

#ifdef IA_CCAT_EXTERNAL_SENSORS_ENABLED
/*
* Sensor event functions.
*/
/*!
* \brief Set the accelerometer sensor events to CCAT internal circular buffer.
* Initialize sensor_events structure. Const fields in the structure are assumed to be initialized before calling this function.
*/
LIBEXPORT ia_err
ia_ccat_set_sensor_events_accelerometer(
    ia_ccat *a_ccat_ptr,                                     /*!< [in, out] Analysistoolbox internal data structures. */
    uint32_t a_num_events,                           /*!< [in] Number of accelerometer sensor events. */
    const ia_ccat_motion_sensor_event *a_sensor_events_ptr); /*!< [in] Structure containing accelerometer events for given time range. */

/*!
* \brief Get a copy of accelerometer events.
* Outputs all events within given timestamps.
*/
LIBEXPORT ia_err
ia_ccat_get_sensor_events_accelerometer(
    const ia_ccat *a_ccat_ptr,                               /*!< [in] Analysistoolbox internal data structures. */
    uint64_t a_start_timestamp,                /*!< [in]  Start time for events to be copied. 0 if all data (max_num_events) must be copied. */
    uint64_t a_end_timestamp,                  /*!< [in]  End time for events to be copied. 0 if all data (max_num_events) must be copied. */
    uint32_t *a_num_events_ptr,                          /*!< [in]  Number of events allowed to be copied (maximum amount of available memory in sensor_events).
                                                       [out] How many events were copied to the sensor_events structure. */
    ia_ccat_motion_sensor_event *a_sensor_events_ptr);       /*!< [out] Copied accelerometer events. */

/*!
* \brief Set the gyroscope sensor events to CCAT internal circular buffer.
*/
LIBEXPORT ia_err
ia_ccat_set_sensor_events_gyroscope(
    ia_ccat *a_ccat_ptr,                                     /*!< [in, out] Analysistoolbox internal data structures. */
    uint32_t a_num_events,                           /*!< [in] Number of gyroscope sensor events. */
    const ia_ccat_motion_sensor_event *a_sensor_events_ptr); /*!< [in] Structure containing gyroscope events for given time range. */

/*!
* \brief Get a copy of gyroscope events.
* Outputs all events within given timestamps.
*/
LIBEXPORT ia_err
ia_ccat_get_sensor_events_gyroscope(
    const ia_ccat *a_ccat_ptr,                               /*!< [in]  Analysistoolbox internal data structures. */
    uint64_t a_start_timestamp,                /*!< [in]  Start time for events to be copied. 0 if all data (max_num_events) must be copied. */
    uint64_t a_end_timestamp,                  /*!< [in]  End time for events to be copied. 0 if all data (max_num_events) must be copied. */
    uint32_t *a_num_events_ptr,                          /*!< [in]  Number of events allowed to be copied (maximum amount of available memory in sensor_events).
                                                       [out] How many events were copied to the sensor_events structure. */
    ia_ccat_motion_sensor_event *a_sensor_events_ptr);       /*!< [out] Copied gyroscope events. */

/*!
* \brief Set the gravity sensor events to CCAT internal circular buffer.
*/
LIBEXPORT ia_err
ia_ccat_set_sensor_events_gravity(
    ia_ccat *a_ccat_ptr,                                     /*!< [in, out] Analysistoolbox internal data structures. */
    uint32_t a_num_events,                           /*!< [in] Number of gravity sensor events. */
    const ia_ccat_motion_sensor_event *a_sensor_events_ptr); /*!< [in] Structure containing gravity events for given time range. */

/*!
* \brief Get a copy of gravity events.
* Outputs all events within given timestamps.
*/
LIBEXPORT ia_err
ia_ccat_get_sensor_events_gravity(
    const ia_ccat *a_ccat_ptr,                               /*!< [in]  Analysistoolbox internal data structures. */
    uint64_t a_start_timestamp,                /*!< [in]  Start time for events to be copied. 0 if all data (max_num_events) must be copied. */
    uint64_t a_end_timestamp,                  /*!< [in]  End time for events to be copied. 0 if all data (max_num_events) must be copied. */
    uint32_t *a_num_events_ptr,                          /*!< [in]  Number of events allowed to be copied (maximum amount of available memory in sensor_events).
                                                       [out] How many events were copied to the sensor_events structure. */
    ia_ccat_motion_sensor_event* a_sensor_events_ptr);       /*!< [out] Copied gravity events. */

/*!
* \brief Set the ambient light sensor events to CCAT internal circular buffer.
*/
LIBEXPORT ia_err
ia_ccat_set_sensor_events_ambient_light(
    ia_ccat *a_ccat_ptr,                                     /*!< [in, out] Analysistoolbox internal data structures. */
    uint32_t a_num_events,                           /*!< [in] Number of ambient light sensor events. */
    const ia_ccat_ambient_light_event *a_sensor_events_ptr); /*!< [in] Structure containing ambient light events for given time range. */

/*!
* \brief Get a copy of ambient light events.
* Outputs all events within given timestamps.
*/
LIBEXPORT ia_err
ia_ccat_get_sensor_events_ambient_light(
    const ia_ccat *a_ccat_ptr,                               /*!< [in]  Analysistoolbox internal data structures. */
    uint64_t a_start_timestamp,                /*!< [in]  Start time for events to be copied. 0 if all data (max_num_events) must be copied. */
    uint64_t a_end_timestamp,                  /*!< [in]  End time for events to be copied. 0 if all data (max_num_events) must be copied. */
    uint32_t *a_num_events_ptr,                          /*!< [in]  Number of events allowed to be copied (maximum amount of available memory in sensor_events).
                                                            [out] How many events were copied to the sensor_events structure. */
    ia_ccat_ambient_light_event *a_sensor_events_ptr);       /*!< [out] Copied ambient light events. */

                                                       /* Following functions require frame_info structure as input. Client should call ia_ccat_hold_frame() to get the frame handle.
                                                       * Once frame handle is no longer used, ia_ccat_release_frame() must be called. */
#endif /* IA_CCAT_EXTERNAL_SENSORS_ENABLED */

#ifdef IA_CCAT_LIGHT_SOURCE_ESTIMATION_ENABLED
/*!
* \brief Get a copy of ambient light events.
* Outputs all events within given timestamps.
*/
LIBEXPORT ia_err
ia_ccat_get_lse_results(
    ia_ccat_frame_info *a_frame_info_ptr,                                    /*!< [in]  Frame data structure pointer. */
    const ia_ccat_lse_results_t **lse_results_ptr);                    /*!< [out] Copied lse results. */

LIBEXPORT ia_err
ia_ccat_lse_run(
    ia_ccat_frame_info *a_frame_info_ptr,
    uint16_t *a_cct_lsc_weights_ptr,
    uint16_t* a_prev_lse_weights_ptr,
    const uint16_t* a_lsc_weights_cct_range_ptr,
    const ia_cmc_t *a_cmc_ptr,
    chromaticity_characterization_t *a_sensor_chroma_chara_ptr,
    const crop_params *a_lsc_crop_params_ptr,
    uint32_t a_final_cct_estimate,
    const uint32_t *a_cmc_cct,
    const ia_ccat_lse_results_t **a_lse_results_ptr);

LIBEXPORT ia_err
ia_ccat_remap_ir_light_sources(
    const cmc_parsed_ir_weight_t *a_cmc_parsed_ir_weight,
    const cmc_light_source *lsrc_in,
    uint32_t a_num_of_lsources_in,
    float32_t *a_ir_proportion);
#endif /* IA_CCAT_LIGHT_SOURCE_ESTIMATION_ENABLED */

LIBEXPORT ia_err
ia_ccat_set_frame_athena_mode(
    ia_ccat_frame_info *a_frame_info_ptr,
    bool athena_mode);

LIBEXPORT ia_err
ia_ccat_set_frame_min_gamma_gtm(
    ia_ccat_frame_info *a_frame_info_ptr,
    float32_t min_gamma_gtm);

LIBEXPORT ia_err
ia_ccat_get_frame_athena_mode(
    ia_ccat_frame_info *a_frame_info_ptr,
    bool *athena_mode);

LIBEXPORT ia_err
ia_ccat_get_frame_min_gamma_gtm(
    ia_ccat_frame_info *a_frame_info_ptr,
    float32_t *min_gamma_gtm);
#ifdef __cplusplus
}
#endif

#endif /* IA_CCAT_H_ */
