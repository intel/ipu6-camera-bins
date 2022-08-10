/*
* INTEL CONFIDENTIAL
* Copyright (c) 2014-2016, 2018 Intel Corporation
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
* this notice or any other notice embedded in Materials by Intel or Intel's
* suppliers or licensors in any way.
*/

#ifndef IA_PAL_API_H
#define IA_PAL_API_H

// Public APIs
#include "ia_pal_exports.h"

// Dependencies to other AIQ modules
#include "ia_types.h" // in include
#include "ia_isp_bxt_types.h"
#include "ia_pal_direct.h"

#ifdef __cplusplus
extern "C" {
#endif

// This is the common handle to API call functions. Implementation details are
// not exposed to clients.
typedef struct ia_pal* ia_pal_handle;

// Should be called at start. Should allocate all required memory and in this
// case large enough memory chunk to fit ISP control parameters.
IA_PAL_API ia_pal_handle ia_pal_init();

IA_PAL_API ia_err ia_pal_run(ia_pal_handle handle
                             , ia_binary_data const *tuning_parameters
                             , ia_binary_data* isp_parameters
                             , ia_isp_bxt_program_group *program_group
                             , ia_pal_direct_results const *direct_results
                             , ia_isp_pal_status_t *pal_status
                             , uint32_t *pal_status_count);

// Should be called in the end. Release all memory that was allocated in init
IA_PAL_API ia_err ia_pal_deinit(ia_pal_handle handle);


/*!
 * \brief Get version.
 * Get version from version header.
 *
 * \return                         Version string.
 */
IA_PAL_API const char* ia_pal_get_version(void);

/*!
 * \brief Get size of PAL output buffer.
 * This function can be used to query size of buffer required to fit PAL output.
 *
 * \param[in] program_group Optional. Indicate for which PAL kernels output data size needs to be calculated. If NULL, all PAL kernels' outputs data size is returned.
 * \return                  Size of PAL output.
 */
IA_PAL_API int32_t ia_pal_get_output_size(ia_isp_bxt_program_group *program_group);

#ifdef __cplusplus
}
#endif

#endif // IA_PAL_API_H
