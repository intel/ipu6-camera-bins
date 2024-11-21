/*
 * Copyright 2017-2022 Intel Corporation
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


#ifndef __IA_VIEW_TYPES_H_
#define __IA_VIEW_TYPES_H_

#include <stdint.h>
#include "ia_types.h"


#ifdef __cplusplus
extern "C" {
#endif


/*!< ia_view_status_t: ia_view enable/disable and configure status */
typedef enum {
    ia_view_bypass=0,
    ia_view_user_input_configured,
    ia_view_resolution_configured,
} ia_view_status_t;

/*!< ia_view_proc_enabled_t: The processing blocks enabled in GDC. Used in PAL*/
typedef enum {
    ia_view_proc_enabled_none=0,
    ia_view_proc_enabled_pre_affine=(1<<0),
    ia_view_proc_enabled_rotation=(1<<1),
    ia_view_proc_enabled_post_affine=(1<<2),
} ia_view_proc_enabled_t;


/*!< ia_view_resolution_params_t: The frame resolutions at various points in the pipe*/
typedef enum {
    ia_view_resolution_at_sensor_output=0, /*Resolution at sensor output */
    ia_view_resolution_at_gdc_input,       /*Resolution at gdc input */
    ia_view_resolution_at_gdc_output,      /*Resolution at gdc output */
    ia_view_resolution_at_pipe_output,     /*Resolution at pipe output */
    ia_view_resolution_max,
} ia_view_resolution_params_t;


/*!< Invalid coordinate size: Number of color channels possible to be specified.*/
#define IA_VIEW_INVALID_COORD_SIZE      (4)

/*!< ia_view_projection_type_t: User controllable projection type*/
typedef enum {
    ia_view_projection_rectilinear,
    ia_view_projection_conical,
    ia_view_projection_equirectangular,
    ia_view_projection_2Dbowl,
    ia_view_projection_cylindrical
} ia_view_projection_type_t;

/*!< ia_view_camera_mount_type_t: User controllable camera mount type*/
typedef enum {
    ia_view_wall_mounted,
    ia_view_ceiling_mounted,
} ia_view_camera_mount_type_t;

/*!< ia_view_fine_adjustments_t: Control fine adjustments of the viewing window*/
typedef struct
{
    float horizontal_shift;    /*!< Horizontal shift in pixels*/
    float vertical_shift;      /*!< Vertical shift in pixels*/
    float window_rotation;     /*!< Rotate the window, angle in degrees*/
    float vertical_stretch;    /*!< Vertical stretch factor*/
} ia_view_fine_adjustments_t;


/*!< ia_view_rotation_t: Set view rotation in x, y, z axis*/
typedef struct
{
    float pitch;   /*!< pitch angle in degrees: rotation along X axis*/
    float yaw;     /*!< yaw angle in degrees: rotation along Y axis*/
    float roll;    /*!< roll angle in degrees: rotation along Z axis*/
} ia_view_rotation_t;


/*!< ia_view_resolution_t: The resolution required for view*/
typedef struct
{
    int width;      /*!< Resolution width */
    int height;     /*!< Resolution height */
    int horz_offset;    /*!< Horizontal offset */
    int vert_offset;    /*!< Vertical offset */
    float scale_factor; /*!< Scale factor */
} ia_view_resolution_t;

/*!< translation array size*/
#define IA_VIEW_3D_TRANSLATION_SIZE (3)

/*!< ia_view_config_t: Set view parameters*/
typedef struct
{
    ia_view_projection_type_t type;   /*!< type: The projection type desired*/
    float zoom;                       /*!< zoom: Zoom configuration*/
    float cone_angle;                 /*!< cone_angle used only for ia_view_projection_conical*/
    double bowl_radius_sqr;            /*!< bowl_radius_sqr used only for ia_view_projection_2Dbowl*/
    double bowl_scale;                 /*!< bowl_scale used only for ia_view_projection_2Dbowl*/
    ia_view_camera_mount_type_t camera_mount_type; /*! camera mount type: The mounting position of the camera: wall, ceiling*/
    int32_t invalid_coordinate_mask[IA_VIEW_INVALID_COORD_SIZE]; /*!< Used to fill for each color channel when coordinates falls out of bounds */

    ia_view_rotation_t          camera_rotation;     /*(< Camera rotation configuration */
    ia_view_rotation_t          view_rotation;       /*!< View rotation configuration */
    float translation[IA_VIEW_3D_TRANSLATION_SIZE];  /*!< Translation3D vector for Bowl projection*/
    ia_view_fine_adjustments_t  fine_adjustments;    /*!< Fine adjustment configuration */
} ia_view_config_t, ia_isp_bxt_view_params_t;

/*!< ia_view_mbr_limits_t: Set mbr limits for view parameters*/
typedef struct
{
    /*!< Min Zooming on projection*/
    float  zoom;
    /*!< max pitch of view*/
    float pitch;
    /*!< max yaw of view*/
    float yaw;
    /*!< max roll view*/
    float roll;
    /*!<  max Window rotation*/
    float winrotation;
    /*!< max vertical scale*/
    float vertical_stretch;
    /*!< max horizontal shift*/
    float horizontal_shift;
    /*!< max vertical shift*/
    float vertical_shift;
} ia_view_limits_t;

typedef struct
{
    ia_view_limits_t cylindrical;
    ia_view_limits_t equirectangular;
    ia_view_limits_t rectilinear;
    ia_view_limits_t conical_m40;
    ia_view_limits_t conical_m20;
    ia_view_limits_t conical_p20;
    ia_view_limits_t conical_p40;
}ia_view_mbr_limits_t,ia_isp_bxt_gdc_limits;



/*!< ia_view_projection_t: Calculated parameter used in PAL*/
typedef struct
{
    ia_view_projection_type_t type; /*!< type: Projection type to be used*/
    double scale_factor_1[2];   /*!< scale_factor_1: Internal scale factor calculated*/
    double scale_factor_2[2];   /*!< scale_factor_2: Internal scale factor calculated*/
    double inv_f_pi;            /*!< inv_f_pi is inverse focal lenght pi: Internal parameter*/
    double bowl_radius_sqr;
    double bowl_scale;
} ia_view_projection_t;


/*!< ia_view_params_t: Calculated parameter to be used in PAL*/
typedef struct
{
    /*!< Mask indicating what parameters are enabled*/
    int32_t enabled_mask;

    /*!< Projections the view */
    ia_view_projection_t projection;

    /*!< Pre Affine Matrix: Window rotatoin and scale*/
    float pre_affine_scale_matrix[2][2];

    /*!< Pre Affine Matrix: Translation*/
    double pre_affine_translation_matrix[2];

    /*!< Rotation Matrix combines camera and view rotations */
    float rotation_matrix[3][3];

    /*!< Translation3D Matrix for Bowl Projection*/
    float translation_matrix[IA_VIEW_3D_TRANSLATION_SIZE];

    /*!< Post Affine Matrix */
    float post_affine_scale_matrix[2][2];

    /*!< Post Affine Matrix */
    double post_affine_translation_matrix[2];

    /*!< Invalid coordinate mask for each color channel */
    int32_t invalid_coordinate_mask[IA_VIEW_INVALID_COORD_SIZE];

} ia_view_params_t;

typedef struct
{
    ia_view_status_t is_configured;
    ia_view_config_t config;
    ia_view_resolution_t resolution[ia_view_resolution_max]; /*!< View resolution at different stages in the pipe */
    float cmc_affine_scale_matrix[2][2];
    double cmc_affine_translation_matrix[2];
    float cmc_focal_length;

    ia_view_params_t isp_params;
} ia_view_t;

typedef ia_view_t* ia_view_handle;

#ifdef __cplusplus
}
#endif

#endif /* __IA_VIEW_TYPES_H_ */

