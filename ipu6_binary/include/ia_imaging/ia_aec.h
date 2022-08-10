/*
 * Copyright 2020-2021 Intel Corporation
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

#ifndef IA_AEC_H_
#define IA_AEC_H_

#include "ia_configuration.h"
#include "ia_types.h"
#include "ia_ccat.h"
#include "ia_aec_types.h"
#include "ia_cmc_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Initialize IA_AEC
 * This function must be called before any other function in the library. It allocates memories for all AEC algorithms based on input parameters
 * given by the user. AIQB (from CPFF). Initialization returns a handle to the AEC instance, which is given as input parameter for all the
 * subsequent calls to this library. Therefore, multiple instances of AEC can running simultaneously. For example one instance per camera.
 *
 * \param[in]     atbx              Analysis Toolbox handle. AEC will use it to get statistics analysis results.
 * \param[in]     aiqb_data         Contains tuning parameters for AEC algorithms. NULL, if built-ion defaults are to be used.
 * return                           IA_AEC handle. Use the returned handle as input parameter for the consequent IA_AEC calls.
 */
LIBEXPORT ia_aec*
ia_aec_init(
    ia_ccat *a_ccat_ptr,
    const ia_binary_data *a_aiqb_data_ptr,
    const ia_cmc_t *a_cmc_ptr);

/*!
 * \brief De-initialize IA_AEC and its submodules.
 * All memory allocated by AEC algorithm is freed. AEC handle can no longer be used.
 *
 * \param[in] ia_aec                AEC instance handle.
 */
LIBEXPORT void
ia_aec_deinit(ia_aec *a_aec_ptr);

/*!
 * \brief AEC calculation based on input parameters and frame statistics.
 * AE calculates new exposure parameters to be used for the next frame based on previously given statistics and user parameters.
 *
 * \param[in] ia_aec                 AEC instance handle.
 * \param[in] aec_input_params       Input parameters for AEC calculations.
 * \param[out] aec_results           Pointer where AEC results are stored. Client allocates this memory and AEC only fills it with next exposure parameters.
 * \return                           Error code.
 */
LIBEXPORT ia_err
ia_aec_run(
    ia_aec *a_aec_ptr,
    const ia_aec_input_params *aec_input_params,
    ia_aec_results *a_aec_results_ptr);


#ifdef __cplusplus
}
#endif

#endif /* IA_AEC_H_ */
