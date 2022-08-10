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
 * \file ia_intrinsics_types.h
 * \brief Data types and enumerations for Intel Intrinsics library.
 */
#ifndef _IA_INTRINSICS_TYPES_H_
#define _IA_INTRINSICS_TYPES_H_
#include <stdint.h>
#include "ia_types.h"

typedef struct ia_intrinsics_t ia_intrinsics;

/*!
 * \brief ia_intrinsics structure.
 */

typedef struct ia_intrinsics_t
{
    float principal_point[2];                       /*!<The current principal point of the camera in x and y coordinates based on the current pipe config*/
    float radial_distortion[3];                     /*!<The radial distortion coefficients of the camera based on the current cmc*/
    float tangential_distortion[2];                 /*!<The tangential distortion coefficients of the camera based on the current cmc*/
    float undistorted_projection_transform[16];     /*!<4x4 warping matrix which can be used to describe the mapping between
                                                        3D world points and image pixels like camera intrinsics matrix*/
    const ia_cmc_t *ia_cmc;
    float zoom_factor;                              /*!<Zoom factor to be used in the calculations*/
    bool  focus_supported;                          /*!<Is focussing supported*/
    bool  dvs_enabled;                              /*!<Is DVS enabled*/
    ia_aiq_frame_params *output_frame_descriptor;   /*!<Scale and crop info of output*/
} ia_intrinsics_t;

/** Total cropping parameters
*  These parameters contain sensor and ISP cropping information without any scaling or binning.
*  In case of scaling before cropping, cropping params needs to be scaled back to the original resolution.
*  This information is used to crop lens distortion grids accordingly.
*/
typedef struct
{
    unsigned int horizontal_crop_offset;    /* Read out offset horizontal */
    unsigned int vertical_crop_offset;      /* Read out offset vertical */
    unsigned int cropped_width;             /* Width of cropped area without any scaling*/
    unsigned int cropped_height;            /* Height of cropped area without any scaling*/
} ia_intrinsics_crop_params;

#endif /* _IA_INTRINSICS_TYPES_H_ */
