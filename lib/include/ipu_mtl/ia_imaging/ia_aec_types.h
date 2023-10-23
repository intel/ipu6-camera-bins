/*
 * Copyright 2018 Intel Corporation
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
 * \file ia_aec.h
 * \brief Definitions and declarations of Intel AEC algorithm.
 */

#ifndef _IA_AEC_TYPES_H_
#define _IA_AEC_TYPES_H_

#include "ia_configuration.h"
#include "ia_types.h"
#include "ia_aiq_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef IA_AEC_FEATURE_WEIGHT_GRID
#define IA_AEC_WEIGHT_GRID_SIZE (IA_AEC_WEIGHT_GRID_WIDTH * IA_AEC_WEIGHT_GRID_HEIGHT)
typedef struct
{
    unsigned int grid_width;
    unsigned int grid_height;
    unsigned char data[IA_AEC_WEIGHT_GRID_SIZE];
} ia_aec_weight_grid;
#endif

typedef struct ia_aec_t ia_aec;

/*!
 * \brief Input parameter structure for AE algorithm.
 * This structure can be initialized to zero values for basic functionality (disable or make features ineffective).
 */
typedef struct
{
    unsigned int num_exposures;                                                     /*!< The number of exposure outputs to have. One for LDR, two or more for HDR/exposure bracketing. */
    ia_aiq_exposure_sensor_descriptor sensor_descriptor[IA_AEC_EXPOSURES_MAX_NUM];  /*!< Sensor specific descriptor and limits of the used sensor mode for target frame use. */
    unsigned int num_sensor_descriptors;                                            /*!< The number of sensor descriptors given in the above pointer.
                                                                                         Used to specify different sensor descriptors for each exposure. */
    ia_aiq_ae_exposure_distribution_priority exposure_distribution_priority;        /*!< AEC exposure distribution priority mode. */
    ia_aiq_ae_priority_mode priority_mode;                                          /*!< AEC priority mode. */
    float manual_convergence_time;                                                  /*!< Manual AEC convergence speed in seconds.
                                                                                        < 0.0   Use convergence speed from tunings.
                                                                                         0.0    Convergence filters are bypassed. This is similar behavior as in previous API when using frame_use still
                                                                                         > 0.0  Overrides convergence speed from tunings. */
    ia_aiq_ae_manual_limits manual_limits[IA_AEC_EXPOSURES_MAX_NUM];                /*!< Manual limits which override limits defined in AEC tunings. If tunings are to be used, all values must be set to 0. */
    unsigned int num_manual_limits;                                                 /*!< Number of limits to use. One, if same limits are used for all exposures, two or more if different limits for each exposure are used. */
    float ev_shift;                                                                 /*!< Exposure Value shift [-4,4]. */
#ifdef IA_AEC_FEATURE_FLASH
    ia_aiq_flash_mode flash_mode;                                                   /*!< Manual flash mode. If AEC should make flash decision, set mode to ia_aiq_flash_mode_auto. */
#endif
#ifdef IA_AEC_FEATURE_WEIGHT_GRID
    ia_aiq_ae_metering_mode metering_mode;                                          /*!< AEC metering mode. */
#endif
#ifdef IA_AEC_FEATURE_FLICKER_DETECTION
    ia_aiq_ae_flicker_reduction flicker_reduction_mode;                             /*!< AEC flicker reduction mode. */
#endif
#ifdef IA_AEC_FEATURE_ROI_ENABLED
    ia_rectangle exposure_window;                                                   /*!< Rectangle of area which AEC uses to to calculate new exposure parameters. If rectangle is not to be used, all values must be set to 0. */
#endif
#ifdef IA_AEC_FEATURE_APERTURE_CONTROL
    float manual_aperture_fn;                                                       /*!< Manual f-number of aperture (e.g. 2.8), <= 0.0 for N/A. Used only with P iris. */
#endif
#ifdef IA_AEC_FEATURE_DC_IRIS
    ia_aiq_aperture_control_dc_iris_command manual_dc_iris_command;                 /*!< Used only with DC iris. 0 (auto) for N/A. */
#endif
} ia_aec_input_params;

/*!
 *  \brief Gain structure defining gain value and type.
 */
typedef struct
{
    cmc_gain_type_t type;       /*!< Gain type (analog, digital, etc.). */
    float value;                /*!< Gain value as a multiplier (e.g. 1.0). */
} ia_aec_gain;

/*!
* \brief AEC results.
*/
typedef struct
{
    unsigned int exposure_time_us;           /*!< Exposure time in microseconds, -1 if N/A. */
    ia_aec_gain gains[IA_CMC_GAINS_MAX_NUM]; /*!< Gain as multipliers (e.g. 1.0), -1.0f if N/A. */
    unsigned int num_gains;                  /*!< The number of gains. */
    int iso;                                 /*!< ISO value corresponding to the total gains. -1 if N/A. */
    unsigned int total_target_exposure;      /*!< Total exposure ie. combination of Et, Total gains and Aperture gain, -1 if N/A. */
} ia_aec_exposure_parameters;

typedef struct
{
    unsigned int exposure_index;                                                    /*!< Exposure index which identifies the exposure. */
    ia_aec_exposure_parameters exposure[IA_AEC_EXPOSURE_PLANS_NUM];                 /*!< Exposure parameters to be used in the next frame in generic format. */
    ia_aiq_exposure_sensor_parameters sensor_exposure[IA_AEC_EXPOSURE_PLANS_NUM];   /*!< Exposure parameters to be used in the next frame in sensor specific format. */
    unsigned int exposure_plan_ids[IA_AEC_EXPOSURE_PLANS_NUM];                      /*!< Exposure plan IDs. Used to identify and sync what parameters were changed in the exposure plan. */
    float distance_from_convergence;                                                /*!< Distance of convergence as an EV shift value. Negative is underexposure, positive is overexposure */
} ia_aec_exposure_result;

typedef struct
{
    ia_aec_exposure_result exposures[IA_AEC_EXPOSURES_MAX_NUM];  /*!< Results for each exposure to be used in the next frame. */
    unsigned int num_exposures;                                  /*!< The number of calculated exposures. */
    float lux_level_estimate;                                    /*!< Lux level estimate. */
    bool converged;                                              /*!< Indicates that AE has converged. */
#ifdef IA_AEC_FEATURE_WEIGHT_GRID
    ia_aec_weight_grid weight_grid;                              /*!< Weight map to be used in the next frame histogram calculation. */
#endif
#ifdef IA_AEC_FEATURE_FLASH
    ia_aiq_flash_parameters flashes[IA_AEC_FLASHES_NUM];         /*!< Array of flash parameters for each flashes to be used in the next frame. */
#endif
#ifdef IA_AEC_FEATURE_FLICKER_DETECTION
    ia_aiq_ae_flicker_reduction flicker_reduction_mode;          /*!< Flicker reduction mode proposed by the AEC algorithm */
#endif
#ifdef IA_AEC_FEATURE_MULTIFRAME_HINT
    ia_aiq_bracket_mode multiframe;                              /*!< AEC may propose to use multiframe for optimal results. */
#endif
#ifdef IA_AEC_FEATURE_APERTURE_CONTROL
    ia_aiq_aperture_control aperture_control;                    /*!< Aperture control parameters. */
#endif
} ia_aec_results;


#ifdef __cplusplus
}
#endif

#endif /* _IA_AEC_H_ */
