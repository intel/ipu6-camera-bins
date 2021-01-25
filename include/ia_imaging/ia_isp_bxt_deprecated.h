/*
 * Copyright 2017-2018 Intel Corporation
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
 * \file ia_isp_bxt_deprecated.h
 * \brief ia_isp_bxt specific implementation.
*/

#ifndef IA_ISP_BXT_DEPRECATED_H_
#define IA_ISP_BXT_DEPRECATED_H_

#include "ia_aiq_types.h"
#include "ia_types.h"
#include "ia_isp_bxt_types.h"
#include "ia_bcomp_types.h"
#include "ia_aiq_deprecated.h"
#include "ia_cmc_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
*  HDR exposure info which provides information about the thresholds and exposure ratios.
*
*  Exposure 0: L[0]|---------------|H[0]
*         R[0] <--->
*  Exposure 1:      L[1]|----------------------|H[1]
*              R[1] <--->
*  Exposure 2:           L[2]|-----------------------------|H[2]
*  ...
*                 R[N-2] <--->
*  Exposure N:                L[N-1]|-----------------------------------|H[N-1]
*
*  N = number of exposures
*  L[n] = lowest intensity captured by n:th exposure (ia_isp_stat_split_thresh::low)
*  H[n] = highest intensity captured by n:th exposure (ia_isp_stat_split_thresh::high)
*  R[n] = exposure ratio between n:th and the longest exposure
*
*  Number of thresholds equals N, but number of exposure ratios equals N-1.
*/
typedef struct
{
    unsigned int num_exposures;                             /*!< Number of exposures. */
    ia_isp_stat_split_thresh thresholds[IA_AIQ_MAX_NUM_EXPOSURES]; /*!< Lowest and highest intensity values in the stitched data for each exposure [0, num_exposures-1]. */
    float exposure_ratios[IA_AIQ_MAX_NUM_EXPOSURES - 1];    /*!< Exposure ratios for each exposure pair (between n:th and the longest exposure) [0, num_exposures-2]. */
    float hdr_gain;                                         /*!< Scaling factor for normalizing pixel data to the maximum bit depth. */
} ia_isp_hdr_exposure_info_t;


/*!
*  \brief IA_ISP_BXT parameter input structure.
*/
typedef struct
{
    ia_aiq_frame_params *sensor_frame_params;        /*!< Mandatory. Sensor frame parameters. Describe frame scaling/cropping done in sensor. */
    ia_aiq_awb_results *awb_results;                 /*!< Mandatory. WB results which are to be used to calculate next ISP parameters (WB gains, color matrix,etc). */
    ia_aiq_gbce_results *gbce_results;               /*!< Mandatory. GBCE Gamma tables which are to be used to calculate next ISP parameters.*/
    ia_aiq_ae_results *ae_results;                   /*!< Mandatory. Exposure results which are to be used to calculate next ISP parameters.
                                                     Currently only exposure times, analog and digital gains are used. For convenience reasons AIC takes
                                                     ae results and not only needed parameters. */
    ia_aiq_pa_results *pa_results;                   /*!< Mandatory. Parameter adaptor results from AIQ. */
    ia_aiq_sa_results *sa_results;                   /*!< Mandatory. Shading adaptor results from AIQ. */
    ia_aiq_hist_weight_grid *weight_grid;            /*!< Mandatory. Weight map to be used in the next frame histogram calculation. */
    ia_isp_bxt_program_group *program_group;         /*!< Mandatory. List of kernels associated with this program group */
    unsigned int stream_id;                          /*!< Optional. If program_group is not given, stream_id is used to fetch all the tunings for all the kernels
                                                     associated with the stream_id. */
    ia_isp_feature_setting nr_setting;               /*!< Mandatory. Feature setting for noise reduction algorithms. */
    ia_isp_feature_setting ee_setting;               /*!< Mandatory. Feature setting for edge enhancement algorithms. */
    char manual_brightness;                          /*!< Optional. Manual brightness value range [-128,127]. Value 0 means no change. */
    char manual_contrast;                            /*!< Optional. Manual contrast value range [-128,127]. Value 0 means no change. */
    char manual_hue;                                 /*!< Optional. Manual hue value range [-128,127]. Value 0 means no change.
                                                     Value -96 means red become blue, green become red, blue become green */
    char manual_saturation;                          /*!< Optional. Manual saturation value range [-128,127]. Value 0 means no change. */
    ia_isp_effect effects;                           /*!< Optional. Manual setting for special effects. Combination of ia_isp_effect enums.*/
    ia_dvs_morph_table *dvs_morph_table;             /*!< Mandatory. DVS results which are passed to GDC ISP FW. If null is given, PAL produces default
                                                     morphing table in PAL results. PAL will add scaling to the grid if defined in resolution info.*/
    ia_isp_custom_controls* custom_controls;         /*!< Optional. Custom control parameter for interpolating between different tunings.
                                                     If custom controls are not used, pointer can be set as null.*/
    ia_binary_data* pal_override;                    /*!< Optional. Set of parameters for overriding tunings from CPF. Parameters need to follow
                                                     Algo API binary format. Binary may contain multiple parameter sets.
                                                     Can be set as null if PAL override functionality is not used. */
    ia_ltm_results *ltm_results;                     /*!< Mandatory. Local tone mapping results from LTM. */
    ia_ltm_drc_params *ltm_drc_params;               /*!< Mandatory. DRC parameters from LTM. */
    float manual_digital_gain;                       /*!< Optional. Additional digital gain that is applied to all color channels of the image before ISP statistics collection.
                                                     Values less than 1.0 means no additional gain. */
    ia_ob_output ob_black_level;                     /*!< Optional. Black level values calculated on-the-fly when the sensor supports. */
    unsigned long long timestamp;                    /*!< Mandatory. Current timestamp (is microseconds) when ia_isp_bxt_run function is called. AIC uses timestamp to decide what
                                                     calculations are done based on tunable run rate for each ISP configuration algorithm. */
    ia_dvs_image_transformation *gdc_transformation; /*!< Mandatory. Image transformation parameters for GDC5 ISP FW. This feature replaces the need for morph_table usage.*/
    ia_isp_bxt_view_params_t const *view_params;     /*!< Optional. View parameters for running in GDC5 mode.*/
    ia_media_format media_format;                    /*!< Mandatory. Selected Digital television output format.(e.g. BT709) */
    ia_bcomp_results const *bcomp_results;           /*!< Optional.  bit-compression curves. */
} ia_isp_bxt_input_params;

/*!
*  \brief IA_ISP_BXT parameter input structure.
*/
typedef struct
{
    ia_aiq_frame_params *sensor_frame_params;        /*!< Mandatory. Sensor frame parameters. Describe frame scaling/cropping done in sensor. */
    ia_aiq_awb_results *awb_results;                 /*!< Mandatory. WB results which are to be used to calculate next ISP parameters (WB gains, color matrix,etc). */
    ia_aiq_gbce_results *gbce_results;               /*!< Mandatory. GBCE Gamma tables which are to be used to calculate next ISP parameters.*/
    ia_aiq_ae_results *ae_results;                   /*!< Mandatory. Exposure results which are to be used to calculate next ISP parameters.
                                                     Currently only exposure times, analog and digital gains are used. For convenience reasons AIC takes
                                                     ae results and not only needed parameters. */
    ia_aiq_pa_results_v1 *pa_results;                /*!< Mandatory. Parameter adaptor results from AIQ. */
    ia_aiq_sa_results *sa_results;                   /*!< Mandatory. Shading adaptor results from AIQ. */
    ia_aiq_hist_weight_grid *weight_grid;            /*!< Mandatory. Weight map to be used in the next frame histogram calculation. */
    ia_isp_bxt_program_group *program_group;         /*!< Mandatory. List of kernels associated with this program group */
    unsigned int stream_id;                          /*!< Optional. If program_group is not given, stream_id is used to fetch all the tunings for all the kernels
                                                     associated with the stream_id. */
    ia_isp_feature_setting nr_setting;               /*!< Mandatory. Feature setting for noise reduction algorithms. */
    ia_isp_feature_setting ee_setting;               /*!< Mandatory. Feature setting for edge enhancement algorithms. */
    char manual_brightness;                          /*!< Optional. Manual brightness value range [-128,127]. Value 0 means no change. */
    char manual_contrast;                            /*!< Optional. Manual contrast value range [-128,127]. Value 0 means no change. */
    char manual_hue;                                 /*!< Optional. Manual hue value range [-128,127]. Value 0 means no change.
                                                     Value -96 means red become blue, green become red, blue become green */
    char manual_saturation;                          /*!< Optional. Manual saturation value range [-128,127]. Value 0 means no change. */
    ia_isp_effect effects;                           /*!< Optional. Manual setting for special effects. Combination of ia_isp_effect enums.*/
    ia_dvs_morph_table *dvs_morph_table;             /*!< Mandatory. DVS results which are passed to GDC ISP FW. If null is given, PAL produces default
                                                     morphing table in PAL results. PAL will add scaling to the grid if defined in resolution info.*/
    ia_isp_custom_controls* custom_controls;         /*!< Optional. Custom control parameter for interpolating between different tunings.
                                                     If custom controls are not used, pointer can be set as null.*/
    ia_binary_data* pal_override;                    /*!< Optional. Set of parameters for overriding tunings from CPF. Parameters need to follow
                                                     Algo API binary format. Binary may contain multiple parameter sets.
                                                     Can be set as null if PAL override functionality is not used. */
    ia_ltm_results *ltm_results;                     /*!< Mandatory. Local tone mapping results from LTM. */
    ia_ltm_drc_params *ltm_drc_params;               /*!< Mandatory. DRC parameters from LTM. */
    float manual_digital_gain;                       /*!< Optional. Additional digital gain that is applied to all color channels of the image before ISP statistics collection.
                                                     Values less than 1.0 means no additional gain. */
    ia_ob_output ob_black_level;                     /*!< Optional. Black level values calculated on-the-fly when the sensor supports. */
    unsigned long long timestamp;                    /*!< Mandatory. Current timestamp (is microseconds) when ia_isp_bxt_run function is called. AIC uses timestamp to decide what
                                                     calculations are done based on tunable run rate for each ISP configuration algorithm. */
    ia_dvs_image_transformation *gdc_transformation; /*!< Mandatory. Image transformation parameters for GDC5 ISP FW. This feature replaces the need for morph_table usage.*/
    ia_isp_bxt_view_params_t const *view_params;     /*!< Optional. View parameters for running in GDC5 mode.*/
    ia_media_format media_format;                    /*!< Mandatory. Selected Digital television output format.(e.g. BT709) */
    ia_bcomp_results const *bcomp_results;           /*!< Optional.  bit-compression curves. */
} ia_isp_bxt_input_params_v1;

/*!
* \brief ISP configuration for the next frame
* Computes ISP parameters from input parameters and CPF values for the next image.
*
* \param[in] ia_isp_bxt                    Mandatory. ISP instance handle.
* \param[in] input_params                  Mandatory. Input parameters for ISP calculations.
* \param[in] output_data                   Mandatory. Output data structure. If output_data->data pointer is given, AIC writes the results to given buffer.
*                                                     Output is PAL output following ISP API format.
* \return                                  Error code.
*
*/
LIBEXPORT ia_err
ia_isp_bxt_run(
    ia_isp_bxt *ia_isp_bxt,
    const ia_isp_bxt_input_params *input_params,
    ia_binary_data *output_data);

/*!
* \brief ISP configuration for the next frame
* Computes ISP parameters from input parameters and CPF values for the next image.
*
* \param[in] ia_isp_bxt                    Mandatory. ISP instance handle.
* \param[in] input_params                  Mandatory. Input parameters for ISP calculations.
* \param[in] output_data                   Mandatory. Output data structure. If output_data->data pointer is given, AIC writes the results to given buffer.
*                                                     Output is PAL output following ISP API format.
* \return                                  Error code.
*
*/
LIBEXPORT ia_err
ia_isp_bxt_run_v1(
    ia_isp_bxt *ia_isp_bxt,
    const ia_isp_bxt_input_params_v1 *input_params,
    ia_binary_data *output_data);

LIBEXPORT ia_err
ia_isp_bxt_statistics_convert_awb_from_binary(
    ia_isp_bxt *ia_isp_bxt,
    const ia_binary_data *statistics,
    ia_aiq_rgbs_grid **out_rgbs_grid);

LIBEXPORT ia_err
ia_isp_bxt_statistics_convert_awb(
    ia_isp_bxt *ia_isp_bxt,
    unsigned int stats_width,
    unsigned int stats_height,
    void *c0_avg,
    void *c1_avg,
    void *c2_avg,
    void *c3_avg,
    void *c4_avg,
    void *c5_avg,
    void *c6_avg,
    void *c7_avg,
    void *sat_ratio_0,
    void *sat_ratio_1,
    void *sat_ratio_2,
    void *sat_ratio_3,
    ia_aiq_rgbs_grid **out_rgbs_grid);

LIBEXPORT ia_err
ia_isp_bxt_statistics_convert_awb_hdr_from_binary(
    ia_isp_bxt *ia_isp_bxt,
    const ia_binary_data *statistics,
    const ia_isp_stat_split_thresh *thresholds,
    int num_thresholds,
    ia_isp_bxt_hdr_params_t *ia_isp_bxt_hdr_params,
    unsigned int stats_rgbs_hdr_block_pixel_width,
    unsigned int stats_rgbs_hdr_block_pixel_height,
    float r_gain,
    float g_gain,
    float b_gain,
    ia_aiq_rgbs_grid **out_rgbs_grid);

LIBEXPORT ia_err
ia_isp_bxt_statistics_convert_awb_hdr(
    ia_isp_bxt *ia_isp_bxt_ptr,
    unsigned int stats_width,
    unsigned int stats_height,
    void *stats_r,
    void *stats_g,
    void *stats_b,
    void *stats_s,
    const ia_isp_stat_split_thresh *thresholds,
    int num_thresholds,
    ia_isp_bxt_hdr_params_t *ia_isp_bxt_hdr_params,
    unsigned int stats_rgbs_hdr_block_pixel_width,
    unsigned int stats_rgbs_hdr_block_pixel_height,
    float  r_gain,
    float  g_gain,
    float  b_gain,
    ia_aiq_rgbs_grid **out_rgbs_grid);

/*!
* \brief Converts BXT ISP specific statistics to IA_AIQ format.
* ISP generated statistics may not be in the format in which AIQ algorithms expect. Statistics need to be converted
* from various ISP formats into AIQ statistics format.
*
* \param[in] ia_isp_bxt                          Mandatory. ia_isp_bxt instance handle.
* \param[in]  statistics                         Mandatory. Statistics in ISP specific format.
* \param[in]  hdr_exposure_info                  Mandatory. HDR exposure info calculated with ia_isp_bxt_calculate_hdr_exposure_info().
* \param[in]  hdr_compression                    Optional. NULL, if HDR statistics are already in linear space (no compression).
* \param[in]  stats_rgbs_hdr_block_pixel_width   Mandatory. TODO: Remove when FW will output saturation percentage instead of saturation count. Width of the block in pixel used in computing the saturation percentage.
* \param[in]  stats_rgbs_hdr_block_pixel_height  Mandatory. TODO: Remove when FW will output saturation percentage instead of saturation count. Height of the block in pixel used in computing the saturation percentage.
* \param[in]  r_gain                             Mandatory. Gain applied to the R color channel before HDR statistic collection. Gain will be reverted from HDR statistics.
* \param[in]  g_gain                             Mandatory. Gain applied to the G color channel before HDR statistic collection. Gain will be reverted from HDR statistics.
* \param[in]  b_gain                             Mandatory. Gain applied to the B color channel before HDR statistic collection. Gain will be reverted from HDR statistics.
* \param[out] out_rgbs_grid                      Mandatory. Pointer's pointer where address of converted statistics are stored.
* \param[out] out_hdr_rgbs_grid                  Optional. Pointer's pointer where address of combined HDR statistics are stored.
*                                                Converted RGBS grid statistics. Output can be directly used as input in function ia_aiq_statistics_set.
*                                                if the external buffer is provided in out_rgbs_grid it will be used otherwise internal buffer is used.
* \return                                        Error code.
*/
LIBEXPORT ia_err
ia_isp_bxt_statistics_convert_awb_hdr_from_binary_v1(
    ia_isp_bxt *ia_isp_bxt,
    const ia_binary_data *statistics,
    const ia_isp_hdr_exposure_info_t *hdr_exposure_info,
    const ia_isp_bxt_hdr_compression_t *hdr_compression,
    unsigned int stats_rgbs_hdr_block_pixel_width,
    unsigned int stats_rgbs_hdr_block_pixel_height,
    float r_gain,
    float g_gain,
    float b_gain,
    ia_aiq_rgbs_grid **out_rgbs_grid,
    ia_aiq_hdr_rgbs_grid **out_hdr_rgbs_grid);

/*!
* \brief Converts HDR DP RGBS statistics to AIQ format.
* ISP/VLIW generated statistics may not be in the format in which AIQ algorithms expect. Statistics need to be converted  into AIQ statistics format.
* \param[in]  ia_isp_bxt                         Mandatory. ia_isp_bxt instance handle.
* \param[in]  stats_width                        Mandatory. Actual width of the statistics grid.
* \param[in]  stats_height                       Mandatory. Actual height of the statistics grid.
* \param[in]  stats_r                            Mandatory.
* \param[in]  stats_b                            Mandatory.
* \param[in]  stats_g                            Mandatory.
* \param[in]  stats_s                            Mandatory.
* \param[in]  hdr_exposure_info                  Mandatory. HDR exposure info calculated with ia_isp_bxt_calculate_hdr_exposure_info().
* \param[in]  hdr_compression                    Optional. NULL, if HDR statistics are already in linear space (no compression).
* \param[in]  stats_rgbs_hdr_block_pixel_width   Mandatory. TODO: Remove when FW will output saturation percentage instead of saturation count. Width of the block in pixel used in computing the saturation percentage.
* \param[in]  stats_rgbs_hdr_block_pixel_height  Mandatory. TODO: Remove when FW will output saturation percentage instead of saturation count. Height of the block in pixel used in computing the saturation percentage.
* \param[in]  r_gain                             Mandatory. Gain applied to the R color channel before HDR statistic collection. Gain will be reverted from HDR statistics.
* \param[in]  g_gain                             Mandatory. Gain applied to the G color channel before HDR statistic collection. Gain will be reverted from HDR statistics.
* \param[in]  b_gain                             Mandatory. Gain applied to the B color channel before HDR statistic collection. Gain will be reverted from HDR statistics.
* \param[out] out_rgbs_grid                      Mandatory. Pointer's pointer where address of de-stitched statistics array is stored.
* \param[out] out_hdr_rgbs_grid                  Optional. Pointer's pointer where address of combined HDR statistics is stored.
*                                                Converted RGBS grid statistics. Output can be directly used as input in function ia_aiq_statistics_set.
*                                                if the external buffer is provided in out_rgbs_grid it will be used otherwise internal buffer is used.
* \return                                        Error code.
*/
LIBEXPORT ia_err
ia_isp_bxt_statistics_convert_awb_hdr_v1(
    ia_isp_bxt *ia_isp_bxt_ptr,
    unsigned int stats_width,
    unsigned int stats_height,
    void *stats_r,
    void *stats_g,
    void *stats_b,
    void *stats_s,
    const ia_isp_hdr_exposure_info_t *hdr_exposure_info,
    const ia_isp_bxt_hdr_compression_t *hdr_compression,
    unsigned int stats_rgbs_hdr_block_pixel_width,
    unsigned int stats_rgbs_hdr_block_pixel_height,
    float  r_gain,
    float  g_gain,
    float  b_gain,
    ia_aiq_rgbs_grid **out_rgbs_grid,
    ia_aiq_hdr_rgbs_grid **out_hdr_rgbs_grid);

/*!
*  Calculates additional HDR exposure information based on the AE results.
*
*  \param [in]  ia_isp_bxt         Mandatory. ia_isp_bxt instance handle.
*  \param [in]  ae_results         Mandatory. AE results structure containing the used exposures.
*  \param [in]  hdr_bit_depth      Mandatory. Maximum bit depth of the HDR data.
*  \param [out] hdr_exposure_info  Mandatory. Calculated additional HDR exposure information.
*
*  \return                         Error code.
*/
LIBEXPORT ia_err
ia_isp_bxt_calculate_hdr_exposure_info(
ia_isp_bxt *ia_isp_bxt,
const ia_aiq_ae_results *ae_results,
unsigned int hdr_bit_depth,
ia_isp_hdr_exposure_info_t *hdr_exposure_info);

/*!
* \brief Converts BXT ISP specific statistics to IA_AIQ format.
* ISP generated statistics may not be in the format in which AIQ algorithms expect. Statistics need to be converted
* from various ISP formats into AIQ statistics format.
* \param[in] ia_isp_bxt     Mandatory.\n
*                           ia_isp_bxt instance handle.
* \param[in]  stats_width   Mandatory actual width of the statistics grid.
* \param[in]  stats_height  Mandatory actual height of the statistics grid.
* \param[in]  c0_avg        Mandatory Average level of c0 color
* \param[in]  c1_avg        Mandatory Average level of c0 color
* \param[in]  c2_avg        Mandatory Average level of c0 color
* \param[in]  c3_avg        Mandatory Average level of c0 color
* \param[in]  c4_avg        Mandatory Average level of c0 color
* \param[in]  c5_avg        Mandatory Average level of c0 color
* \param[in]  c6_avg        Mandatory Average level of c0 color
* \param[in]  c7_avg        Mandatory Average level of c0 color
* \param[in]  sat_ratio_0   Mandatory Represents Saturation ratio.
*                                     0: 0% above saturation
*                                     255: 100% above saturation
* \param[in]  sat_ratio_1   Mandatory Represents Saturation ratio.
*                                     0: 0% above saturation
*                                     255: 100% above saturation
* \param[in]  sat_ratio_2   Mandatory Represents Saturation ratio.
*                                     0: 0% above saturation
*                                     255: 100% above saturation
* \param[in]  sat_ratio_3   Mandatory Represents Saturation ratio.
*                                     0: 0% above saturation
*                                     255: 100% above saturation
* \param[in]  ir_weight     Mandatory for RGB-IR sensors, NULL otherwise. IR contamination grid for given frame.
*
* \param[out] out_rgbs_grid Mandatory. Pointer's pointer where address of converted statistics are stored.
*                           Converted RGBS grid statistics. Output can be directly used as input in function ia_aiq_statistics_set.
*                           if the external buffer is provided in out_rgbs_grid it will be used otherwise internal buffer is used.
* \param[out] out_ir_grid   Mandatory for RGB-IR sensors, NULL otherwise. Pointer's pointer where address of converted statistics are stored.
*                           Converted IR grid statistics. Output can be directly used as input in function ia_aiq_statistics_set.
*                           if the external buffer is provided in out_ir_grid it will be used otherwise internal buffer is used.
*
* \return                   Error code.
*/
LIBEXPORT ia_err
ia_isp_bxt_statistics_convert_awb_v1(
    ia_isp_bxt *ia_isp_bxt,
    unsigned int stats_width,
    unsigned int stats_height,
    void *c0_avg,
    void *c1_avg,
    void *c2_avg,
    void *c3_avg,
    void *c4_avg,
    void *c5_avg,
    void *c6_avg,
    void *c7_avg,
    void *sat_ratio_0,
    void *sat_ratio_1,
    void *sat_ratio_2,
    void *sat_ratio_3,
    const ia_aiq_ir_weight_t *ir_weight,
    ia_aiq_rgbs_grid **out_rgbs_grid,
    ia_aiq_grid **out_ir_grid);

/*!
* \brief Converts BXT ISP specific statistics to IA_AIQ format.
* ISP generated statistics may not be in the format in which AIQ algorithms expect. Statistics need to be converted
* from various ISP formats into AIQ statistics format.
* \param[in] ia_isp_bxt     Mandatory.\n
*                           ia_isp_bxt instance handle.
* \param[in]  stats_width   Mandatory actual width of the statistics grid.
* \param[in]  stats_height  Mandatory actual height of the statistics grid.
* \param[in]  c0_avg        Mandatory Average level of c0 color
* \param[in]  c1_avg        Mandatory Average level of c0 color
* \param[in]  c2_avg        Mandatory Average level of c0 color
* \param[in]  c3_avg        Mandatory Average level of c0 color
* \param[in]  c4_avg        Mandatory Average level of c0 color
* \param[in]  c5_avg        Mandatory Average level of c0 color
* \param[in]  c6_avg        Mandatory Average level of c0 color
* \param[in]  c7_avg        Mandatory Average level of c0 color
* \param[in]  sat_ratio_0   Mandatory Represents Saturation ratio.
*                                     0: 0% above saturation
*                                     255: 100% above saturation
* \param[in]  sat_ratio_1   Mandatory Represents Saturation ratio.
*                                     0: 0% above saturation
*                                     255: 100% above saturation
* \param[in]  sat_ratio_2   Mandatory Represents Saturation ratio.
*                                     0: 0% above saturation
*                                     255: 100% above saturation
* \param[in]  sat_ratio_3   Mandatory Represents Saturation ratio.
*                                     0: 0% above saturation
*                                     255: 100% above saturation
* \param[in]  ir_weight     Mandatory for RGB-IR sensors, NULL otherwise. IR contamination grid for given frame.
* \param[in]  ae_results    Mandatory for 2DP-SVE sensors for frames captured with >=2 exposures, ignored otherwise. Exposure parameters
*                                     used in de-stiching of input HDR statistics to num_exposures LDR RGBS grids.
*
* \param[out] out_rgbs_grid Mandatory. Pointer's pointer where address of converted statistics are stored.
*                           Converted RGBS grid statistics. Output can be directly used as input in function ia_aiq_statistics_set.
*                           if the external buffer is provided in out_rgbs_grid it will be used otherwise internal buffer is used.
* \param[out] out_ir_grid   Mandatory for RGB-IR sensors, NULL otherwise. Pointer's pointer where address of converted statistics are stored.
*                           Converted IR grid statistics. Output can be directly used as input in function ia_aiq_statistics_set.
*                           if the external buffer is provided in out_ir_grid it will be used otherwise internal buffer is used.
*
* \return                   Error code.
*/
LIBEXPORT ia_err
ia_isp_bxt_statistics_convert_awb_v2(
    ia_isp_bxt *ia_isp_bxt,
    unsigned int stats_width,
    unsigned int stats_height,
    void *c0_avg,
    void *c1_avg,
    void *c2_avg,
    void *c3_avg,
    void *c4_avg,
    void *c5_avg,
    void *c6_avg,
    void *c7_avg,
    void *sat_ratio_0,
    void *sat_ratio_1,
    void *sat_ratio_2,
    void *sat_ratio_3,
    const ia_aiq_ir_weight_t *ir_weight,
    const ia_aiq_ae_results *ae_results,
    ia_aiq_rgbs_grid **out_rgbs_grid,
    ia_aiq_grid **out_ir_grid);

/*!
 * \brief Converts BXT ISP specific statistics to IA_AIQ format.
 * ISP generated statistics may not be in the format in which AIQ algorithms expect. Statistics need to be converted
 * from various ISP formats into AIQ statistics format.
 * \param[in] ia_isp_bxt     Mandatory.\n
 *                           ia_isp_bxt instance handle.
 * \param[in]  stats_width   Mandatory actual width of the statistics grid.
 * \param[in]  stats_height  Mandatory actual height of the statistics grid.
 * \param[in]  c0_avg        Mandatory Average level of c0 color
 * \param[in]  c1_avg        Mandatory Average level of c0 color
 * \param[in]  c2_avg        Mandatory Average level of c0 color
 * \param[in]  c3_avg        Mandatory Average level of c0 color
 * \param[in]  c4_avg        Mandatory Average level of c0 color
 * \param[in]  c5_avg        Mandatory Average level of c0 color
 * \param[in]  c6_avg        Mandatory Average level of c0 color
 * \param[in]  c7_avg        Mandatory Average level of c0 color
 * \param[in]  sat_ratio_0   Mandatory Represents Saturation ratio.
 *                                     0: 0% above saturation
 *                                     255: 100% above saturation
 * \param[in]  sat_ratio_1   Mandatory Represents Saturation ratio.
 *                                     0: 0% above saturation
 *                                     255: 100% above saturation
 * \param[in]  sat_ratio_2   Mandatory Represents Saturation ratio.
 *                                     0: 0% above saturation
 *                                     255: 100% above saturation
 * \param[in]  sat_ratio_3   Mandatory Represents Saturation ratio.
 *                                     0: 0% above saturation
 *                                     255: 100% above saturation
 * \param[in]  ir_weight     Mandatory for RGB-IR sensors, NULL otherwise. IR contamination grid for given frame.
 * \param[in]  ae_results    Mandatory for 2DP-SVE sensors for frames captured with >=2 exposures, ignored otherwise. Exposure parameters
 *                                     used in de-stiching of input HDR statistics to num_exposures LDR RGBS grids.
 * \param[in] bcomp_results  Mandatory for compressed statistics data (e.g. in case of 20-bit DOL statistics in IPU6)
 *
 * \param[out] out_rgbs_grid Mandatory. Pointer's pointer where address of converted statistics are stored.
 *                           Converted RGBS grid statistics. Output can be directly used as input in function ia_aiq_statistics_set.
 *                           if the external buffer is provided in out_rgbs_grid it will be used otherwise internal buffer is used.
 * \param[out] out_ir_grid   Mandatory for RGB-IR sensors, NULL otherwise. Pointer's pointer where address of converted statistics are stored.
 *                           Converted IR grid statistics. Output can be directly used as input in function ia_aiq_statistics_set.
 *                           if the external buffer is provided in out_ir_grid it will be used otherwise internal buffer is used.
 *
 * \return                   Error code.
 */
LIBEXPORT ia_err
ia_isp_bxt_statistics_convert_awb_v3(
    ia_isp_bxt *ia_isp_bxt,
    unsigned int stats_width,
    unsigned int stats_height,
    void *c0_avg,
    void *c1_avg,
    void *c2_avg,
    void *c3_avg,
    void *c4_avg,
    void *c5_avg,
    void *c6_avg,
    void *c7_avg,
    void *sat_ratio_0,
    void *sat_ratio_1,
    void *sat_ratio_2,
    void *sat_ratio_3,
    const ia_aiq_ir_weight_t *ir_weight,
    const ia_aiq_ae_results *ae_results,
    const ia_bcomp_results *bcomp_results,
    ia_aiq_rgbs_grid **out_rgbs_grid,
    ia_aiq_grid **out_ir_grid);

/*!
* \brief Converts BXT ISP specific statistics to IA_AIQ format.
* ISP generated statistics may not be in the format in which AIQ algorithms expect. Statistics need to be converted
* from various ISP formats into AIQ statistics format.
* \param[in] ia_isp_bxt        Mandatory. ia_isp_bxt instance handle.
* \param[in]  statistics       Mandatory. Statistics in ISP specific format.
* \param[in]  ir_weight        Mandatory for RGB-IR sensors, NULL otherwise. IR contamination grid.
* \param[out] out_rgbs_grid    Mandatory. Pointer's pointer where address of converted statistics are stored.
*                              Converted RGBS grid statistics. Output can be directly used as input in function ia_aiq_statistics_set.
*                              if the external buffer is provided in out_rgbs_grid it will be used otherwise internal buffer is used.
* \param[out] out_ir_grid      Mandatory for RGB-IR sensors, NULL otherwise. Pointer's pointer where address of converted statistics are stored.
*                              Converted IR grid statistics. Output can be directly used as input in function ia_aiq_statistics_set.
*                              if the external buffer is provided in out_ir_grid it will be used otherwise internal buffer is used.
* \return                      Error code.
*/
LIBEXPORT ia_err
ia_isp_bxt_statistics_convert_awb_from_binary_v1(
    ia_isp_bxt *ia_isp_bxt,
    const ia_binary_data *statistics,
    const ia_aiq_ir_weight_t *ir_weight,
    ia_aiq_rgbs_grid **out_rgbs_grid,
    ia_aiq_grid **out_ir_grid);

/*!
* \brief Converts BXT ISP specific statistics to IA_AIQ format.
* ISP generated statistics may not be in the format in which AIQ algorithms expect. Statistics need to be converted
* from various ISP formats into AIQ statistics format.
* \param[in] ia_isp_bxt        Mandatory. ia_isp_bxt instance handle.
* \param[in]  statistics       Mandatory. Statistics in ISP specific format.
* \param[in]  ir_weight        Mandatory for RGB-IR sensors, NULL otherwise. IR contamination grid.
* \param[in]  ae_results       Mandatory for 2DP-SVE sensors for frames captured with >=2 exposures, ignored otherwise. Exposure parameters
                               used in de-stiching of input HDR statistics to num_exposures LDR RGBS grids.
* \param[out] out_rgbs_grid    Mandatory. Pointer's pointer where address of converted statistics are stored.
*                              Converted RGBS grid statistics. Output can be directly used as input in function ia_aiq_statistics_set.
*                              if the external buffer is provided in out_rgbs_grid it will be used otherwise internal buffer is used.
* \param[out] out_ir_grid      Mandatory for RGB-IR sensors, NULL otherwise. Pointer's pointer where address of converted statistics are stored.
*                              Converted IR grid statistics. Output can be directly used as input in function ia_aiq_statistics_set.
*                              if the external buffer is provided in out_ir_grid it will be used otherwise internal buffer is used.
* \return                      Error code.
*/
LIBEXPORT ia_err
ia_isp_bxt_statistics_convert_awb_from_binary_v2(
    ia_isp_bxt *ia_isp_bxt,
    const ia_binary_data *statistics,
    const ia_aiq_ir_weight_t *ir_weight,
    const ia_aiq_ae_results *ae_results,
    ia_aiq_rgbs_grid **out_rgbs_grid,
    ia_aiq_grid **out_ir_grid);

/*!
 * \brief Converts BXT ISP specific statistics to IA_AIQ format.
 * ISP generated statistics may not be in the format in which AIQ algorithms expect. Statistics need to be converted
 * from various ISP formats into AIQ statistics format.
 * \param[in] ia_isp_bxt        Mandatory. ia_isp_bxt instance handle.
 * \param[in] statistics        Mandatory. Statistics in ISP specific format.
 * \param[in] ir_weight         Mandatory for RGB-IR sensors, NULL otherwise. IR contamination grid.
 * \param[in] ae_results        Mandatory for 2DP-SVE sensors for frames captured with >=2 exposures, ignored otherwise. Exposure parameters
 *                              used in de-stiching of input HDR statistics to num_exposures LDR RGBS grids.
 * \param[in] bcomp_results     Mandatory for compressed statistics data (e.g. in case of 20-bit DOL statistics in IPU6).
 * \param[out] out_rgbs_grid    Mandatory. Pointer's pointer where address of converted statistics are stored.
 *                              Converted RGBS grid statistics. Output can be directly used as input in function ia_aiq_statistics_set.
 *                              if the external buffer is provided in out_rgbs_grid it will be used otherwise internal buffer is used.
 * \param[out] out_ir_grid      Mandatory for RGB-IR sensors, NULL otherwise. Pointer's pointer where address of converted statistics are stored.
 *                              Converted IR grid statistics. Output can be directly used as input in function ia_aiq_statistics_set.
 *                              if the external buffer is provided in out_ir_grid it will be used otherwise internal buffer is used.
 * \return                      Error code.
 */
LIBEXPORT ia_err
ia_isp_bxt_statistics_convert_awb_from_binary_v3(
    ia_isp_bxt *ia_isp_bxt,
    const ia_binary_data *statistics,
    const ia_aiq_ir_weight_t *ir_weight,
    const ia_aiq_ae_results *ae_results,
    const ia_bcomp_results *bcomp_results,
    ia_aiq_rgbs_grid **out_rgbs_grid,
    ia_aiq_grid **out_ir_grid);

/*!
* \brief Convert legacy isp api input data to version 1 data
* Convert legacy isp api input data structure to new version 1 input
* format structure.
* \param[in] input_params       Legacy format input parameters
* \param[in] ia_cmc             CMC handle
* \param[out] pa_results_v1_ptr pa_results version 1 output pointer
* \param[out] input_params_v1   pointer to version 1 output data
*
*/

LIBEXPORT void
ia_isp_convert_input_params_v0_to_v1(
    const ia_isp_bxt_input_params *input_params,
    ia_isp_bxt_input_params_v1 *input_params_v1,
    const ia_cmc_t *ia_cmc,
    ia_aiq_pa_results_v1* pa_results_v1_ptr);

/*!
* \brief Convert isp api input v1 data to version 2 data
* Convert isp api input v1 data structure to new version 2 input
* format structure.
* \param[in] input_params       Legacy format input parameters
* \param[out] sa_results_v1     sa-results in format v1
* \param[out] input_params_v1   pointer to version 1 output data
*
*/

struct ia_isp_bxt_input_params_v2;
LIBEXPORT void
ia_isp_convert_input_params_v1_to_v2(const ia_isp_bxt_input_params_v1 *input_params_v1,
    struct ia_isp_bxt_input_params_v2 *input_params_v2,
    ia_aiq_sa_results_v1 *sa_results_v1);

#ifdef __cplusplus
}
#endif
#endif /* IA_ISP_BXT_DEPRECATED_H_ */
