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
 * \mainpage IA BCOMP API documentation
 *
 * Browse Files and Classes tabs for details.
 *
 */
/*!
 * \file ia_bcomp.h
 * \brief Definitions and declarations of IA_BCOMP library.
 */
#ifndef _IA_BCOMP_H_
#define _IA_BCOMP_H_

#include "ia_aiq_types.h"
#include "ia_types.h"
#include "ia_bcomp_types.h"
#include "ia_cmc_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Initialize ia_bcomp handle.
 *        If yes the object is allocated and initialized.
 *        If not, null is returned
 * \param [in]      ia_cmc              Mandatory, Pointer to CMC structure
 * \param [in]      dol_mode            Mandatory, Operating mode for DOL sensor
 * \param [in]      cg_ratio            Optional, conversion gain ratio for DCG sensor, if sensor is not DCG sensor, this should be set to 1.
 * return                               IA_BCOMP handle. Use the returned handle as input parameter for the consequent IA_BCOMP calls.
 *                                      Returns NULL is ia_bcomp initialization fails.
 */
LIBEXPORT ia_bcomp*
ia_bcomp_init(const ia_cmc_t *ia_cmc, ia_bcomp_dol_mode_t dol_mode,
              float cg_ratio);

/*!
 * \brief Deinitialize IA_BCOMP.
 *        All memory allocated by BCOMP algoritmhs are freed. BCOMP handle can no longer be used.
 *
 * \param[in] ia_bcomp                  Mandatory. BCOMP instance handle.
 *
 */
LIBEXPORT void
ia_bcomp_deinit(ia_bcomp *ia_bcomp);

/*!
* \brief IA_BCOMP parameters to calculate compression info.
*/
typedef struct ia_bcomp_input_params
{
    ia_aiq_ae_results *ae_results;  /*!< Mandatory. Exposure results which are to be used to calculate next ISP parameters.
                                         Currently only exposure times, analog and digital gains are used. For convenience reasons bcomp takes
                                         ae results and not only needed parameters. */
} ia_bcomp_input_params;

/*!
* \brief Run a bit-compression and generates necessary outputs.
*
*  \param [in]      ia_bcomp            Mandatory, initialized ia_bcomp handle.\n
*  \param [in]      bcomp_input_params  Mandatory. Input parameters to run bit-compression.\n
*  \param[out]      bcomp_results       Mandatory. Pointer's pointer where address of bcomp results are stored.
*  \return                              Error code.
*
*/
LIBEXPORT ia_err
ia_bcomp_run(ia_bcomp *ia_bcomp,
             const ia_bcomp_input_params *bcomp_input_params,
             ia_bcomp_results **bcomp_results);

#ifdef __cplusplus
}
#endif
#endif /* _IA_BCOMP_H_ */
