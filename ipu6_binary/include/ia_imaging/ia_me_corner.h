/*
 * Copyright 2014-2016 Intel Corporation
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
 * \file ia_me_corner.h
 * \brief Motion estimation from corner detection and feature matching DVS statistics.
 */
#ifndef _IA_ME_CORNER_H_
#define _IA_ME_CORNER_H_

#include <stdint.h>
#include "ia_dvs_types.h"
#include "dvs_stat_public.h"

#ifdef __cplusplus
extern "C" {
#endif

/** ME Corner State.
 * Host code access to the Motion Estimation Corner detection API with this.
 */
typedef struct t_ia_me_corner ia_me_corner_state;

/** \brief Initialize the ME corner detection module.
 *
 * \param[out]  me_corner_state      ME corner state.
 *                                   This is a pointer to a pointer to a module.
 * \param[in]   aiq_tuning_binary    aiqb binary tuning parameter.
 * \return                           0 for no error, others for error.
 *
 * This function initializes the Motion Estimation Corner detection module. This allocates and initializes
 * internal data structures. This function must always be called before any
 * other ia_me_corner function.
 */
LIBEXPORT ia_err
ia_me_corner_init(ia_me_corner_state **me_corner_state,
                  const ia_binary_data *aiq_tuning_binary);

/** \brief Configures the ME corner module.
 *
 * \param[in]  me_corner_state       ME corner state.
 *                                   This is a pointer to a module.
 * \param[in]  input_resolution      ISP input resolution in BQ.
 * \return                           0 for no error, others for error.
 *
 * This function configures the Motion Estimation corner detection module. This function must always be called
 * after ia_me_corner_init.
 */
LIBEXPORT ia_err
ia_me_corner_config(ia_me_corner_state *me_corner_state,
                    ia_dvs_bq_resolution *input_resolution);

/** \brief Deinitialize the ME corner module.
 *
 * \param[in]   me_corner_state  ME corner state.
 *                               This is a pointer to a module.
 *
 * This function deinitilizes the ME corner module. This frees the allocated memory.
 */
LIBEXPORT void
ia_me_corner_deinit(ia_me_corner_state *me_corner_state);

/*!
 * \brief Allocate statistics buffer.
 *
 * Returns allocated DVS statistics.
 *
 * \param[out]  statistics          Mandatory.\n
 *                                  Pointer's pointer where statistics buffer instance is stored.
 * \return                          Error code.
 */
LIBEXPORT ia_err
ia_me_corner_allocate_statistics(struct ia_css_skc_dvs_statistics **statistics);

/*!
 * \brief Free the statistics buffer.
 *
 * Free the statistics buffer.
 *
 * \param[in]   statistics          Mandatory.\n
 *                                  Pointer to allocated statistics buffer.
 * \return                          Error code.
 */
LIBEXPORT ia_err
ia_me_corner_free_statistics(struct ia_css_skc_dvs_statistics *statistics);


/** \brief Set the ME corner statistics.
 *
 * \param[in]   me_corner_state     ME corner state.
 *                                  This is a pointer to a module.
 * \param[in]   corner_statistics   Pointer to statistics from ISP
 * \param[out]  dvs_statistics      Pointer to pointer to converted DVS statistics
 * \return                          0 for no error, others for error.
 *
 * This function converts corner based statistics to generic DVS statistics.
 */
LIBEXPORT ia_err
ia_me_corner_convert_statistics(ia_me_corner_state *me_corner_state,
                                const struct ia_css_skc_dvs_statistics *corner_statistics,
                                ia_dvs_statistics **dvs_statistics);

/** \brief Gets the ME corner statistics configuration.
 *
 * \param[in]   me_corner_state        ME corner state.
 *                                     This is a pointer to a module.
 * \param[out]  dvs_statistics_config  Pointer to pointer to calculated DVS statistics configuration
 * \return                             0 for no error, others for error.
 *
 * This function calculates configuration for collecting DVS statistics.
 */
LIBEXPORT ia_err
ia_me_corner_get_statistics_config(ia_me_corner_state *me_corner_state,
                                   struct ia_css_dvs_stat_grid_info **dvs_statistics_config);


/*!
 * \brief Get version.
 * Get version from version header.
 *
 * \return                             Version string.
 */
LIBEXPORT const char* ia_me_corner_get_version(void);

#ifdef __cplusplus
}
#endif

#endif /* _IA_ME_CORNER_H_ */
