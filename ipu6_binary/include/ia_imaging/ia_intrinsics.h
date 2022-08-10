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
 * \file ia_intrinsics.h
 * \brief Definitions and declarations of intrinsics library.
 */

#ifndef _IA_INTRINSICS_H_
#define _IA_INTRINSICS_H_

#include "ia_types.h"
#include "ia_isp_bxt_types.h"
#include "ia_aiq_types.h"
#include "ia_intrinsics_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    ia_aiq_frame_params *output_frame_descriptor;   /*!<Scale and crop info of output*/
    bool  focus_supported;                          /*!<Is focussing supported*/
    bool  dvs_enabled;                              /*!<Is DVS enabled*/
} ia_intrinsics_config_params;

/*!
 * \brief Initialize intrinsics.
 * This function must be called before any other function in the library. It allocates memories for all intrinsics
 * algorithms based on input parameters given by the user.
 *
 * \param[in]     ia_cmc            Mandatory. Parsed camera module characterization structure.
 *  return                          ia_intrinsics handle. Use the returned handle as input parameter for the consequent intrinsics calls.
 */
LIBEXPORT ia_intrinsics*
ia_intrinsics_init(const ia_cmc_t *ia_cmc);

/*!
 * \brief Focal length calculation based on AF results.
 * Intrinsics lib calculates focal length for each frame.
 * \param[in]   intrinsics_ptr      Mandatory.\n
 *                                  Intrinsics handle.
 * \param[in]   af_results          Mandatory.\n
 *                                  AF results from AF algorithm.
 * \param[out]  out_focal_length    Mandatory.\n
 *                                  Calculated focal_length in x and y coordinates.
 * \return                          Error code.
 */
LIBEXPORT ia_err
ia_intrinsics_get_focal_length(ia_intrinsics *intrinsics_ptr, ia_aiq_af_results *af_results, float *out_focal_length);

/*! \brief Configure the intrinsics lib to calculate the principal point.
*
* \param[in]   intrinsics_ptr           Mandatory.\n
*                                       Intrinsics handle.
* \param[in]   config_params            Mandatory.\n
*                                       Needed to know the scaling/cropping done in the sensor and isp.
* \return                               0 for no error, others for error.
*
* This function configures the intrinsics lib to provide the needed info to calculate
* the principal point. This function must be called everytime the pipe config changes before
* calling the API to get the principal point.
*/
LIBEXPORT ia_err
ia_intrinsics_config(ia_intrinsics *intrinsics_ptr,
    ia_intrinsics_config_params *config_params);


/*! \brief Function to get the principal point x, y coordinates.
*
* \param[in]   intrinsics_ptr       Mandatory.\n
*                                   Intrinsics handle.
* \param[out]  out_principal_point  Mandatory.\n
*                                   Calculated principal point  x, y coordinates.
* \return                           0 for no error, others for error.
*
* This function returns the principal point based on the sensor params and pipe config given in the config function.
* Config function must be called atleast once before calling this function.
*/
LIBEXPORT ia_err
ia_intrinsics_get_principal_point(ia_intrinsics *intrinsics_ptr, float *out_principal_point);

/*! \brief Function to get the distortion coefficients.
*
* \param[in]   intrinsics_ptr               Mandatory.\n
*                                           Intrinsics handle.
* \param[out]  out_radial_distortion        Mandatory.\n
*                                           Calculated radial_distortion coefficients k1, k2, k3.
* \param[out]  out_tangential_distortion    Mandatory.\n
*                                           Calculated tangential_distortion coefficients p1, p2.
* \return                                   0 for no error, others for error.
*
* This function returns the radial_distortion and tangential_distortion coefficients point based on the cmc info given in the
* init function. Cmc is not expected to change after intrinsic lib init.
*/
LIBEXPORT ia_err
ia_intrinsics_get_distortion_coefficients(ia_intrinsics *intrinsics_ptr, float *out_radial_distortion, float *out_tangential_distortion);

/*! \brief Function to set zoom factor.
*
* \param[in]   intrinsics_ptr               Mandatory.\n
*                                           Intrinsics handle.
* \param[out]  zoom_factor                  Mandatory.\n
*                                           Zoom factor to set.
*/
LIBEXPORT void
ia_intrinsics_set_zoom_factor(ia_intrinsics *intrinsics_ptr, float zoom_factor);

/*!
 * \brief De-initialize intrinsics lib.
 * All memory allocated by intrinsics library are freed.
 *
 */
LIBEXPORT void
ia_intrinsics_deinit(ia_intrinsics *intrinsics_ptr);




#ifdef __cplusplus
}
#endif

#endif /* _IA_INTRINSICS_H_ */
