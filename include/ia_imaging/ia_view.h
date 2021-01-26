/*
 * Copyright 2017 Intel Corporation
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


#ifndef __IA_VIEW_H__
#define __IA_VIEW_H__


#include "ia_view_types.h"
#include "ia_cmc_types.h"


#ifdef __cplusplus
extern "C" {
#endif

/*! \brief Initialize the view module.
 *
 * \param[out]  view_handle    handle maintaining the view instance
 * \param[in]  cmc    The CMC parameters
 * \return                        0 for no error, others for error.
 *
 * This function initializes the view module. This is expected to be called before any
 * other ia_view* function.
 */
LIBEXPORT ia_err
ia_view_init(ia_view_handle *view_handle, const ia_cmc_t *cmc);


/*! \brief Deinitialize the view module.
 *
 * \param[in]  ia_view_handle    handle maintaining the view instance
 *
 * This function deinitilizes the view module and frees internal memory
 */
LIBEXPORT ia_err
ia_view_deinit(ia_view_handle *view_handle);


/*! \brief Set configuration parameters
*
* \param[in]  ia_view_handle   handle maintaining the view instance
* \param[in]  config           Sets the basic configuration for the view
*
* This function sets the basic configurations parameters
*/
LIBEXPORT ia_err
ia_view_set_configuration(ia_view_handle view_handle,
    const ia_view_config_t *config);


/*! \brief Get configuration parameters
*
* \param[in]  ia_view_handle   handle maintaining the view instance
* \param[out] config           Sets the basic configuration for the view
*
* This function gets the basic configurations parameters
*/
LIBEXPORT ia_err
ia_view_get_configuration(ia_view_handle view_handle,
    ia_view_config_t *config);

/*! \brief Run the view parameter calculation
*
* \param[in]  ia_view_handle   handle maintaining the view instance
* \param[in]  camera_rotation  camera rotation matrix from DVS
*
* This function does the calculation of parameters
*/
LIBEXPORT ia_err
ia_view_run(ia_view_handle view_handle,
    const float camera_rotation[3][3]);

/*! \brief Get the last calculated view parameters
*
* \param[in]  ia_view_handle   handle maintaining the view instance
* \param[out] view_params      Get calculated view parameters
*
* This function returns the view parameters
*/
LIBEXPORT ia_err
ia_view_get_view_parameters(ia_view_handle view_handle,
    ia_view_params_t *view_params);


/*! \brief Set view rotation
*
* \param[in]  ia_view_handle    handle maintaining the view instance
* \param[in]  view_rotation     New rotation to apply
*
* This function sets the new view rotation
*/
LIBEXPORT ia_err
ia_view_set_view_rotation(ia_view_handle view_handle,
    const ia_view_rotation_t *view_rotation);

/*! \brief Set camera rotation
*
* \param[in]  ia_view_handle    handle maintaining the view instance
* \param[in]  view_rotation     New rotation to apply
*
* This function sets the new camera rotation
*/
LIBEXPORT ia_err
ia_view_set_camera_rotation(ia_view_handle view_handle,
    const ia_view_rotation_t *camera_rotation);

/*! \brief Get view rotation
*
* \param[in]  ia_view_handle    handle maintaining the view instance
* \param[out] view_rotation    The current rotation settings
*
* This function get the current view rotation
*/
LIBEXPORT ia_err
ia_view_get_view_rotation(ia_view_handle view_handle,
     ia_view_rotation_t *view_rotation);


/*! \brief Set window adjustment parameters
*
* \param[in] ia_view_handle    handle maintaining the view instance
* \param[in] fine_adjustments  Set the window adjustment parameters
*
* This function sets the window adjustment
*/
LIBEXPORT ia_err
ia_view_set_fine_adjustments(ia_view_handle view_handle,
    const ia_view_fine_adjustments_t *fine_adjustments);


/*! \brief Get window adjustment parameters
*
* \param[in]  ia_view_handle   handle maintaining the view instance
* \param[out] fine_adjustments Get the window adjustment parameters
*
* This function gets the current window adjustment
*/
LIBEXPORT ia_err
ia_view_get_fine_adjustments(ia_view_handle view_handle,
    ia_view_fine_adjustments_t *fine_adjustments);


#ifdef __cplusplus
}
#endif

#endif /* __IA_VIEW_H__ */


