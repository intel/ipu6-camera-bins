/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2013-2017 Intel Corporation. All Rights Reserved.
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

#ifndef _IA_CIPR_H_
#define _IA_CIPR_H_

/**
 * TODO: split & get rid of ia_tools
 */
#include <ia_tools/css_types.h>

/** \file ia_cipr.h
 *
 * \ingroup ia_cipr
 *
 * Common API for Camera Imaging Platform Runtime features
 *
 * Includes qyery functions with semantics derived from OpenCL Platform Layer.
 */

typedef uint8_t ia_cipr_platform_id_t;
typedef uint8_t ia_cipr_device_id_t;
typedef uint8_t ia_cipr_device_type_t;

typedef enum {
    cipr_platform_info_key_na
} ia_cipr_platform_info_key_t;

typedef enum {
    cipr_device_info_key_na
} ia_cipr_device_info_key_t;

typedef struct _cipr_context* ia_cipr_context_t;

/**
 * Create and initialize CIPR context
 *
 * \ingroup ia_cipr
 *
 * \return cipr context struct
 */
ia_cipr_context_t ia_cipr_create(void);

/**
 * Destroy and deinitialize CIPR context
 *
 * \ingroup ia_cipr
 *
 * \param[in] cipr context struct
 */
void ia_cipr_destroy(ia_cipr_context_t ctx);

/**
 * Qyery available platform IDs
 *
 * \ingroup ia_cipr
 *
 * \param[in]   num_entries   number of platform id elements that can be stored
 *                            in \p platforms.
 * \param[out]  platforms     returns a list of platform IDs available.
 * \param[out]  num_platforms returns the number of IDs stored in \p
 *                            platforms.
 */
css_err_t ia_cipr_get_platform_ids(uint32_t num_entries,
                                  ia_cipr_platform_id_t *platforms,
                                  uint32_t *num_platforms);

/**
 * Query platform info
 *
 * \ingroup ia_cipr
 *
 * \param[in]   platform      platform ID to query
 * \param[in]   key           key for information to query
 * \param[in]   value_size    storage size in bytes for \p value
 * \param[out]  value         pointer where to store the info
 * \param[out]  ret_value_size returns size in bytes written to \p value
 */
css_err_t ia_cipr_get_platform_info(ia_cipr_platform_id_t platform,
                                   ia_cipr_platform_info_key_t key,
                                   uint32_t value_size,
                                   void *value,
                                   uint32_t *ret_value_size);

/**
 * Qyery available device IDs from platform
 *
 * \ingroup ia_cipr
 *
 * \param[in]   platform      platform ID to query
 * \param[in]   device_type   bitfield for device types to query
 * \param[in]   num_entries   number of platform id elements that can be stored
 *                            in \p platforms.
 * \param[out]  devices       a list of device IDs available in platform
 * \param[out]  num_devices   returns the number of IDs stored in \p
 *                            platforms.
 */
css_err_t ia_cipr_get_device_ids(ia_cipr_platform_id_t platform,
                                ia_cipr_device_type_t device_type,
                                uint32_t num_entries,
                                ia_cipr_device_id_t *devices,
                                uint32_t *num_devices);

/**
 * Query device info
 *
 * \ingroup ia_cipr
 *
 * \param[in]   device        device ID to query
 * \param[in]   key           key for information to query
 * \param[in]   value_size    storage size in bytes for \p value
 * \param[out]  value         pointer where to store the info
 * \param[out]  ret_value_size returns size in bytes written to \p value
 */
css_err_t ia_cipr_get_device_info(ia_cipr_device_id_t device,
                                 ia_cipr_device_info_key_t key,
                                 uint32_t value_size,
                                 void *value,
                                 uint32_t *ret_value_size);

#endif /* _IA_CIPR_H_ */
