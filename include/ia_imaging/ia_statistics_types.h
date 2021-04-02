/*
 * Copyright 2018-2021 Intel Corporation
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

#ifndef __IA_STATISTICS_TYPES_H_
#define __IA_STATISTICS_TYPES_H_

#include "ia_types.h"
#include "ia_configuration.h"

#define IA_RGBS_GRID_SIZE ((IA_RGBS_GRID_WIDTH) * (IA_RGBS_GRID_HEIGHT))

 /*!
 * \brief Bayer color channels grouped into one structure.
 */
typedef struct
{
    unsigned char gr;
    unsigned char r;
    unsigned char b;
    unsigned char gb;
} ia_color_channels;

/*!
 * \brief Statistics grid with averaged RGBS color channels and saturation percentage.
 * Total size of each color channel array is defined by width * height of the grid.
 */
typedef struct
{
    unsigned int grid_width;                        /*!< Mandatory. Width of RGBYS grids. */
    unsigned int grid_height;                       /*!< Mandatory. Height of RGBYS grids. */
    ia_color_channels avg[IA_RGBS_GRID_SIZE];       /*!< Mandatory. Averaged R, Gr, Gb and B channel data. */
    unsigned char sat[IA_RGBS_GRID_SIZE];           /*!< Mandatory. Saturation percentage of pixels within collected data. [0, 255] = [0, 100]%. */
} ia_rgbs_grid;

#define IA_FILTER_RESPONSE_GRID_SIZE (IA_FILTER_RESPONSE_GRID_WIDTH * IA_FILTER_RESPONSE_GRID_HEIGHT)

/*!
 * \brief Filter responses interleaved.
 */
typedef struct
{
    int filter_1;    /*!< Filter response of filter 1 (e.g. low pass, used by auto focus). */
    int filter_2;    /*!< Filter response of filter 2 (e.g. high pass, used by auto focus). */
} ia_filter_response;

/*!
 * \brief Convolution filter respose statistics
 * As defined in the AIQ statistics specification.
 */
typedef struct
{
    unsigned int grid_width;                                    /*!< Number of block elements horizontally in a grid. */
    unsigned int grid_height;                                   /*!< Number of block elements vertically in a grid. */
    ia_filter_response responses[IA_FILTER_RESPONSE_GRID_SIZE]; /*!< Interleaved filter responses. */
} ia_filter_response_grid;

typedef struct
{
    unsigned int element_count;                     /*!< Number of elements in the histogram. */
    unsigned int bins[IA_HISTOGRAM_SIZE];           /*!< Histogram data. */
} ia_histogram;

typedef struct
{
    ia_rectangle   face_area;                 /*!< Bounding box of the face in the coordination system where (0,0) indicates left-top position. */
    int32_t        tracking_id;               /*!< Tracking id of the face. */
    int32_t        confidence;                /*!< Confidence in face detection result. */
    ia_coordinate  mouth;                     /*!< Mid-point of the mouth. */
    ia_coordinate  left_eye;                  /*!< Left eye */
    ia_coordinate  right_eye;                 /*!< Right eye */
    bool           eye_validity;              /*!< Indicates whether a face was processed to get eye positions */
    float          skin_type_dark_likelihood; /*!< Likelihood of skin type being dark. Bright skin likelihood = 100 - dark_skin_type_likelihood */
    bool           skin_type_validity;        /*!< Validity of the Skin Likelihood */
} ia_face_roi;


#define IA_DEPTH_GRID_SIZE (IA_DEPTH_GRID_WIDTH * IA_DEPTH_GRID_HEIGHT)

typedef enum
{
    ia_depth_data_type_vcm,     /*!< VCM units */
    ia_depth_data_type_mm,      /*!< Distance to the object in mm */
} ia_depth_data_type;

/*!
 * Depth statistics grid.
 */
typedef struct
{
    unsigned int grid_width;                      /*!< Number of grid elements horizontally */
    unsigned int grid_height;                     /*!< Number of grid elements vertically */
    ia_depth_data_type type;                      /*!< Data type (VCM units/mm)*/
    ia_rectangle grid_rect;                       /*!< ROI for the grid */
    int depth_data[IA_DEPTH_GRID_SIZE];           /*!< Depth data (type of data is defined by ia_depth_data_type) */
    unsigned char confidence[IA_DEPTH_GRID_SIZE]; /*!< Confidence level */
} ia_depth_grid;

#endif /* __IA_STATISTICS_TYPES_H_ */
