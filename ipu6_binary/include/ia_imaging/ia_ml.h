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
 * \file ia_ml.h
 * \brief Declares the machine learning (IA_ML) interface.
 */

#ifndef _IA_ML_H_
#define _IA_ML_H_

#include <ia_types.h>
#include "ia_ml_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define INVALID_NETWORK_ID      -1

typedef struct ia_ml_t ia_ml;

/*!
 *  Initializes the machine learning module.
 *
 *  \param [in] mldb_binary MLDB binary containing all network data blobs in MKN format.
 *
 *  \return A handle to ia_ml object.
 */
LIBEXPORT ia_ml* ia_ml_init(const ia_binary_data* mldb_binary);

/*!
 *  Registers and initializes a new network.
 *
 *  \param [in] ia_ml_ptr       A handle to IA_ML instance.
 *  \param [in] network_uuid    Unique identifier for the network.
 *
 *  \return A identifier for the network. INVALID_NETWORK_ID in case of errors.
 */
LIBEXPORT ia_ml_network_id ia_ml_load_network(
    ia_ml* ia_ml_ptr,
    unsigned int network_uuid);

/*!
 *  Sends network input data to the processing queue.
 *
 *  \param [in] ia_ml_ptr       A handle to IA_ML instance.
 *  \param [in] network_id      The network identifier.
 *  \param [in] data            A buffer containing the input data for the network.
 *  \param [in] count           Number of float elements in the data buffer.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if invalid arguments and/or count does not match with the network input size.
 */
LIBEXPORT ia_err ia_ml_process_network_input(
    ia_ml* ia_ml_ptr,
    ia_ml_network_id network_id,
    const ia_ml_network_input_t* input);

/*!
 *  Checks the current status of the network execution.
 *
 *  \param [in] ia_ml_ptr       A handle to IA_ML instance.
 *  \param [in] network_id      The network identifier.
 *
 *  \return True, if the network doesn't have anything to process.
 */
LIBEXPORT bool ia_ml_is_network_idle(
    ia_ml* ia_ml_ptr,
    ia_ml_network_id network_id);

/*!
 *  Retrieves the latest results for the network with the given id.
 *
 *  \param [in]  ia_ml_ptr       A handle to IA_ML instance.
 *  \param [in]  network_id      The network identifier.
 *  \param [out] output          A buffer for the output.
 *  \param [in]  count           The number of float elements expected as output.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if id does not exist or the output count does not match with the network output shape.
 *          ia_err_data, if network output is not yet available.
 */
LIBEXPORT ia_err ia_ml_get_network_output(
    ia_ml* ia_ml_ptr,
    ia_ml_network_id network_id,
    ia_ml_network_output_t* output);

/*!
 *  De-initializes the machine learning module.
 *
 *  \param [in]  ia_ml_ptr       A handle to IA_ML instance.
 */
LIBEXPORT void ia_ml_deinit(ia_ml* ia_ml_ptr);

#ifdef __cplusplus
}
#endif

#endif /* _IA_ML_H_ */
