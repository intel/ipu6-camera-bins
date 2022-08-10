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

#ifndef _IA_CIPR_MEMORY_DEVICE_H_
#define _IA_CIPR_MEMORY_DEVICE_H_

#include <ia_cipr/ia_cipr_memory.h>

/**
 * \file ia_cipr_memory_device.h
 *
 * \brief Tentative definition for memory device interface abstraction
 *
 * \defgroup ia_cipr_memory_device Memory Device
 * \ingroup ia_cipr_memory
 */
typedef struct _cipr_memory_device_ops  ia_cipr_memory_device_t;

/**
 * Migrate buffer object with specific memory device
 *
 * This function lets user to associate in which device address space the
 * memory of buffer resides. Actual memory operations done depend on
 * allocation and usage information given to \p buffer.
 *
 * \ingroup ia_cipr_memory_device
 *
 * \param[in]   memory_device   interface handle of specific memory device
 * \param[in]   buffer          buffer object to associate
 */
css_err_t
ia_cipr_memory_device_migrate_buffer(ia_cipr_memory_device_t *memory_device,
                                     ia_cipr_buffer_t *buffer);

#endif /* _IA_CIPR_MEMORY_DEVICE_H_ */

