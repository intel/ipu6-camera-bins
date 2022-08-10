/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2013-2018 Intel Corporation. All Rights Reserved.
 *
 * The source code contained or described herein and all documents related to
 * the source code ("Material") are owned by Intel Corporation or its suppliers
 * or licensors. Title to the Material remains with Intel Corporation or its
 * suppliers and licensors. The Material contains trade secrets and proprietary
 * and confidential information of Intel or its suppliers and licensors. The
 * Material is protected by worldwide copyright and trade secret laws and
 * treaty provisions. No part of the Material may be used, copied, reproduced,
 * modified, published, uploaded, posted, transmitted, distributed, or
 * disclosed in any way without Intel's prior express written permission.
 *
 * No license under any patent, copyright, trade secret or other intellectual
 * property right is granted to or conferred upon you by disclosure or delivery
 * of the Materials, either expressly, by implication, inducement, estoppel or
 * otherwise. Any license under such intellectual property rights must be
 * express and approved by Intel in writing.
 */
#ifndef _PSYS_UTILS_H_
#define _PSYS_UTILS_H_

#include <ia_cipf/ia_cipf_types.h>

/** Write data into parameter section associated with buffer
 *
 * PSYS PG parameter sections are exposed as CIPF stage properties
 * with offset value from buffer payload start address. This function
 * fetches the property with given UID and copies data from given
 * data address to section offset address. Function is intended for
 * writing defaults. Dynamic operations should access the payload
 * directly.
 *
 * \ingroup ia_cipf_css
 *
 * \param[in,out]   buffer      handle to ia_cipf_buffer_t
 * \param[in]       section_uid uid to the payload section property
 * \param[in]       data        pointer to source data to copy
 * \param[in]       size        size of source data to validate with property
 */
css_err_t
psys_utils_write_buffer_section(ia_cipf_buffer_t *buffer,
                                ia_uid section_uid,
                                void const *data,
                                uint32_t size);

/** Read data from parameter section associated with buffer
 *
 * PSYS PG parameter sections are exposed as CIPF stage properties
 * with offset value from buffer payload start address. This function
 * fetches the property with given UID and copies data from section
 * offset address to given data address.
 *
 * \ingroup ia_cipf_css
 *
 * \param[in]   buffer      handle to ia_cipf_buffer_t
 * \param[in]   section_uid uid to the payload section property
 * \param[out]  data        pointer to source data to copy
 * \param[in]   size        size of source data to validate with property
 */
css_err_t
psys_utils_read_buffer_section(ia_cipf_buffer_t *buffer,
                               ia_uid section_uid,
                               void *data,
                               uint32_t size);

#endif /* _PSYS_UTILS_H_ */
