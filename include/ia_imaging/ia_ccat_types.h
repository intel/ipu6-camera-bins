/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2012-2020 Intel Corporation
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
 * \brief Definitions of common analysis types used by Intel 3A modules.
*/

#ifndef IA_CCAT_TYPES_H_
#define IA_CCAT_TYPES_H_

#include "ia_configuration.h"
#include "ia_statistics_types.h"
#include "ia_aiq_types.h"
#include "ia_aec_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    ia_ccat_frame_type_nonflash,
#ifdef IA_AEC_FEATURE_FLASH
    ia_ccat_frame_type_flash,
#endif
    ia_ccat_frame_type_count
} ia_ccat_frame_type;

typedef enum
{
    ia_ccat_histogram_type_cc_start = 0,
    ia_ccat_histogram_type_cc_rgb_averaged = ia_ccat_histogram_type_cc_start, /*!< Color corrected and weighted R, G and B histograms averaged into one histogram. */
    ia_ccat_histogram_type_cc_rgb_combined,                                   /*!< Color corrected and weighted R, G and B histograms summed into one histogram. */
    ia_ccat_histogram_type_cc_y,                                              /*!< Color corrected and weighted R, G and B histograms converted to Y (luminance) histogram. */
    ia_ccat_histogram_type_cc_end,
    ia_ccat_histogram_type_raw_start = ia_ccat_histogram_type_cc_end,
#ifdef IA_CCAT_RGBS_GRID_ENABLED
    ia_ccat_histogram_type_raw_rgb_averaged = ia_ccat_histogram_type_cc_end,  /*!< Raw (calculated from RGBS grid before color correction) R, G and B histograms averaged into one histogram. */
    ia_ccat_histogram_type_raw_rgb_combined,                                  /*!< Raw (calculated from RGBS grid before color correction) R, G and B histograms summed into one histogram. */
    ia_ccat_histogram_type_raw_y,                                             /*!< Raw (calculated from RGBS grid before color correction) R, G and B histograms converted to Y (luminance) histogram. */
    ia_ccat_histogram_type_uncorrected_raw_y,                                 /*!< Raw (calculated from RGBS grid before LSC and color correction) R, G and B histograms converted to Y (luminance) histogram. */
    ia_ccat_histogram_type_raw_end,
#else
    ia_ccat_histogram_type_raw_end = ia_ccat_histogram_type_raw_start,
    ia_ccat_histogram_type_raw_rgb_averaged = ia_ccat_histogram_type_raw_end,
    ia_ccat_histogram_type_raw_rgb_combined = ia_ccat_histogram_type_raw_end,
    ia_ccat_histogram_type_raw_y = ia_ccat_histogram_type_raw_end,
    ia_ccat_histogram_type_uncorrected_raw_y = ia_ccat_histogram_type_raw_end,
#endif
    ia_ccat_histogram_type_count = ia_ccat_histogram_type_raw_end,
    ia_ccat_histogram_type_invalid = ia_ccat_histogram_type_count,
} ia_ccat_histogram_type;

typedef struct ia_ccat_histograms
{
    ia_histogram r;
    ia_histogram g;
    ia_histogram b;
} ia_ccat_histograms;

#ifdef IA_CCAT_RGBS_GRID_ENABLED
#ifdef IA_CCAT_HSV_GRID_ENABLED
typedef struct ia_ccat_hsv_channels
{
    float h;
    float s;
    float v;
} ia_ccat_hsv_channels;

/*!
* \brief HSV grid structure.
*/
typedef struct ia_ccat_hsv_grid
{
    unsigned int grid_width;                        /*! Width of the grid. */
    unsigned int grid_height;                       /*! Height of the grid. */
    ia_ccat_hsv_channels data[IA_RGBS_GRID_SIZE];   /*! Grid data. */
} ia_ccat_hsv_grid;
#endif
#endif

#if defined IA_CCAT_RGBS_GRID_ENABLED || defined IA_CCAT_LUMINANCE_GRID_ENABLED || defined IA_CCAT_IR_GRID_ENABLED
/*!
 * \brief Generic 8 bit grid structure.
 */
typedef struct ia_ccat_grid_char
{
    unsigned int grid_width;                    /*! Width of the grid. */
    unsigned int grid_height;                   /*! Height of the grid. */
    unsigned char data[IA_RGBS_GRID_SIZE];      /*! Grid data. */
} ia_ccat_grid_char;

/*!
* \brief Generic 16 bit grid structure.
*/
typedef struct ia_ccat_grid_short
{
    unsigned int grid_width;                    /*! Width of the grid. */
    unsigned int grid_height;                   /*! Height of the grid. */
    unsigned short data[IA_RGBS_GRID_SIZE];     /*! Grid data. */
} ia_ccat_grid_short;

/*!
 * \brief Generic grid structure with floating point values.
 */
typedef struct ia_ccat_grid_float
{
    unsigned int grid_width;                    /*! Width of the grid. */
    unsigned int grid_height;                   /*! Height of the grid. */
    float data[IA_RGBS_GRID_SIZE];              /*! Grid data in floating point format. */
} ia_ccat_grid_float;
#if defined IA_CCAT_IR_GRID_ENABLED
typedef struct ia_ccat_ir_grid
{
    ia_ccat_grid_char grid_data;
    float i_per_y;
    float out_ir_compgain_isp;
} ia_ccat_ir_grid;
#endif
#endif

typedef struct ia_ccat_frame_statistics
{
    bool frame_parameters_available;                                         /*!< Mandatory. Flag indicating that frame parameters can be used by CCAT. Set to false to invalidate frame parameters. */
    bool shading_corrected;                                                  /*!< Mandatory. Flag indicating if statistics were calculated using lens shading corrected data. */
    ia_ccat_frame_type frame_type;                                           /*!< Mandatory. Indicates if statistics were captured from non-flash or flash illuminated frame. */
    unsigned long long frame_id;                                             /*!< Mandatory. ID for the captured frame. */
    unsigned long long frame_timestamp;                                      /*!< Mandatory. Time stamp for captured frame. */
    ia_rectangle statistics_crop_area;                                       /*!< Mandatory. RGBS and AF grid area crop with respect to full field of view of sensor output using (relative)ranges from ia_coordinate.h. */
#ifdef IA_CCAT_EXTERNAL_RGB_HISTOGRAMS_ENABLED
    ia_ccat_histograms rgb_histograms[IA_CCAT_STATISTICS_MAX_NUM];           /*!< Optional. RGB histograms pointer for each exposure statistics. */
#endif
#ifdef IA_CCAT_EXTERNAL_LUMINANCE_HISTOGRAM_ENABLED
    ia_histogram y_histogram[IA_CCAT_STATISTICS_MAX_NUM];                    /*!< Optional. Luminance histogram. */
#endif
#ifdef IA_CCAT_RGBS_GRID_ENABLED
    ia_rgbs_grid rgbs_grids[IA_CCAT_STATISTICS_MAX_NUM];                     /*!< Optional. RGBS grids for each exposure statistics. */
#endif
#ifdef IA_CCAT_CONVOLUTION_FILTER_GRID_ENABLED
    ia_filter_response_grid af_grids[IA_CCAT_STATISTICS_MAX_NUM];            /*!< Optional. AF grids for each exposure statistics. */
#endif
#ifdef IA_CCAT_EXTERNAL_LUMINANCE_GRID_ENABLED
    ia_ccat_grid_char y_grid[IA_CCAT_STATISTICS_MAX_NUM];                    /*!< Optional. Luminance (LSC and color corrected) grids for each exposure statistics. */
#endif
#ifdef IA_CCAT_IR_GRID_ENABLED
    ia_ccat_ir_grid ir_grid;                                               /*!< Optional. Ir grid (Non LSC corrected grid). */
#endif
#ifdef IA_CCAT_DEPTH_GRID_ENABLED
    ia_depth_grid depth_grid;                                                /*!< Optional. Depth grid. */
#endif
} ia_ccat_frame_statistics;

typedef struct ia_ccat_frame_parameters
{
    ia_aec_results aec_results;                                              /*!< Mandatory. Exposure parameters used to capture the frame. */
    ia_aiq_pa_results_v1 pa_results;                                         /*!< Optional. */
    ia_aiq_sa_results_v1 sa_results;                                         /*!< Optional. */
    ia_aiq_awb_results awb_results;                                          /*!< Optional. */
    ia_aiq_af_results af_results;                                            /*!< Optional. */
#ifdef IA_CCAT_FACE_ANALYSIS_ENABLED
    ia_face_roi faces[IA_CCAT_FACES_MAX_NUM];                                /*!< Optional. Face coordinates from external face detector. NULL if not available. */
#endif
} ia_ccat_frame_parameters;

/*!
 * \brief Structure for various motion sensors
 * Accelerometer Events:
 *  - The data holds information on the acceleration of the device in mg/sec (miligravity per second). Acceleration = Gravity + Linear Acceleration.
 * Gravity Events:
 *  - The data holds information on the gravitation of the device in mg/sec (miligravity per second).
 * Gyroscope Events:
 *  - The data holds information on the angular velocity of the device in rad/sec.
 */
typedef struct ia_ccat_motion_sensor_event
{
    unsigned long long ts;  /*!< Time stamp in usec (microseconds) */
    float x;                /*!< Sensor Data in X direction depending on the type of the sensor */
    float y;                /*!< Sensor Data in Y direction depending on the type of the sensor */
    float z;                /*!< Sensor Data in Z direction depending on the type of the sensor */
    float sensitivity;      /*!< Sensitivity of the sensor */
    unsigned long long fs;  /*!< Frame stamp in usec (microseconds) */
} ia_ccat_motion_sensor_event;

/*!
 * \brief Ambient Light Events
 * NOTE: This should always match to libsensorhub API
 * TODO: Update the structure according to the API
 */
typedef struct ia_ccat_ambient_light_event
{
    unsigned long long ts;  /*!< Time stamp in usec (microseconds) */
    float data;             /*!< Ambient Light data ? */
    float sensitivity;      /*!< Sensitivity of Ambient Light sensor */
    unsigned long long fs;  /*!< Frame stamp in usec (microseconds) */
} ia_ccat_ambient_light_event;

#if 0
/*!
 * \brief Face rectangle
 * Range of rectangle values is defined in ia_coordinate.h:
 * IA_COORDINATE_TOP, IA_COORDINATE_LEFT, IA_COORDINATE_BOTTOM, IA_COORDINATE_RIGHT
 */
typedef struct ia_face_roi
{
    int tracking_id;                   /*!< Tracking id of the face. */
    ia_rectangle face_area;            /*!< Bounding box of the face in the coordination system where (0,0) indicates left-top position. */
    ia_coordinate mouth;               /*!< Mid-point of the mouth. */
    ia_coordinate left_eye;            /*!< Left eye */
    ia_coordinate right_eye;           /*!< Right eye */
    bool eye_validity;                 /*!< Indicates whether a face was processed to get eye positions */
    float skin_type_dark_likelihood;   /*!< Likelihood of skin type being dark [0.0, 1.0]. Bright skin likelihood = 1.0 - dark_skin_type_likelihood */
    bool skin_type_validity;           /*!< Indicates whether a face was processed to get skin likelihood */
} ia_face_roi;
#endif
#ifdef __cplusplus
}
#endif

#endif /* IA_CCAT_H_ */
