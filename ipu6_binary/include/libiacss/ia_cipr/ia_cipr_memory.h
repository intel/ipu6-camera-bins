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

#ifndef _IA_CIPR_MEMORY_H_
#define _IA_CIPR_MEMORY_H_

/** \file ia_cipr_memory.h
 *
 * Tentative CIPR Memory Header
 *
 * \defgroup ia_cipr_memory Memory
 * \ingroup ia_cipr
 *
 * \brief CIPR Memory module defines an abstract buffer object
 * ia_cipr_buffer_t that stores data in contiguos memory region. A memory API
 * is defined to allow platform implementations to either implicitly or
 * explicitly define when the memory being allocated resides in one of the
 * supported devices address space of CIPR and when memory is represented with
 * implementation defined shared memory handle.
 *
 * Migrating ia_cipr_buffer_t from device to another shall be supported by
 * device interfaces in CIPR. While performing migration, the device agent is
 * allowed to alter the information associated with the buffer object.
 *
 * First device receiving newly created ia_cipr_buffer_t object is responsible
 * of carrying out the allocation for host pointer when requested with
 * IA_CIPR_DEVICE_MEMORY_ALLOCATE_CPU_PTR flag.
 *
 * Buffer object also supports user provided and pre-allocated memory. With
 * ia_cipr_buffer_create-function, user can provide ia_cipr_memory_t
 * descriptor with either host pointer or implementation defined handle.
 * Typically, implementation defined handle means OS specific shared memory
 * that device agents may choose to support.
 *
 * Buffer object that is flagged _HW_ONLY is considered "virtual" and does
 * not have accessible memory for host.
 *
 * Mapping operations are implicitly handled by device agents performing
 * operations on data. Device agents are also responsible of data integrity
 * and are allowed to provide different barriers depending on supported
 * granularity.
 */

/**
 * Give indirect dependency for ia_cipr_memory user to our pure posix
 * compatible host memory allocation API.
 */
#include <ia_cipr/ia_cipr.h>
#include <ia_cipr/ia_cipr_alloc.h>

/**
 * Opaque ia_cipr_buffer_t-object
 *
 * \ingroup ia_cipr
 */
typedef struct _cipr_buffer ia_cipr_buffer_t;

/**
 * Memory bitfield definitions to specify type, allocation and usage
 */
typedef uint32_t ia_cipr_memory_flags_t;
#define IA_CIPR_MEMORY_CPU_PTR              (uint32_t)(1 << 0)
#define IA_CIPR_MEMORY_HANDLE               (uint32_t)(1 << 1)
#define IA_CIPR_MEMORY_ALLOCATE_CPU_PTR     (uint32_t)(1 << 2)
#define IA_CIPR_MEMORY_COPY_FROM_USER       (uint32_t)(1 << 3)
#define IA_CIPR_MEMORY_HW_ONLY              (uint32_t)(1 << 4)
#define IA_CIPR_MEMORY_READ_ONLY            (uint32_t)(1 << 5)
#define IA_CIPR_MEMORY_WRITE_ONLY           (uint32_t)(1 << 6)
#define IA_CIPR_MEMORY_UNCACHED             (uint32_t)(1 << 7)
#define IA_CIPR_MEMORY_ALLOC_UNINITIALIZED  (uint32_t)(1 << 8)
#define IA_CIPR_MEMORY_SECURED              (uint32_t)(1 << 9)
#define IA_CIPR_MEMORY_CPU_ONLY             (uint32_t)(1 << 10)
#define IA_CIPR_MEMORY_FLUSH_CPU_CACHE      (uint32_t)(1 << 11)


/**
 * Memory bitfield definitions for memory state
 */
#define IA_CIPR_MEMORY_ALLOCATED            (uint32_t)(1 << 13)
#define IA_CIPR_MEMORY_FROM_USER            (uint32_t)(1 << 14)
#define IA_CIPR_MEMORY_MIGRATED             (uint32_t)(1 << 15)

/**
 * Device specific implementations in CIPR are allowed to extend memory
 * bitfields within their own headers respectively.
 *
 * All CIPR device specific implementations in a single platform are together
 * responsible of integrity.
 */
#define IA_CIPR_MEMORY_DEVICE_MASK       (uint32_t)0xFFFF0000
#define IA_CIPR_MEMORY_DEVICE_FLAG(x)    (uint32_t)(x << 16)

/**
 * Datatype to represent cipr memory to host.
 */
typedef struct {
        uint32_t size;              /**< size in bytes */
        void    *cpu_ptr;           /**< host pointer to allocated data */
        uint64_t handle;            /**< implementation defined handle to
                                         allocated data */
        ia_cipr_memory_flags_t flags; /**< bitfield specifying allocation
                                                  and usage information */
        ia_cipr_buffer_t *anchor;    /**< anchor to origin buffer object */
} ia_cipr_memory_t;

/**
 * Create specified CIPR buffer object
 *
 * \ingroup ia_cipr_memory
 *
 * \param[in]   size    amount of memory in bytes
 * \param[in]   flags   memory flags for new object
 * \param[in]   user_memory  optional user memory to create the buffer from
 */
ia_cipr_buffer_t*
ia_cipr_buffer_create(uint32_t size,
                      ia_cipr_memory_flags_t flags,
                      ia_cipr_memory_t *user_memory);

/**
 * Create CIPR sub-buffer object
 *
 * \ingroup ia_cipr_memory
 *
 * \param[in]   parent buffer object owning the store for the region
 * \param[in]   offset offset to start of the region in parent buffer store
 * \param[in]   size size of the region
 */
ia_cipr_buffer_t*
ia_cipr_buffer_create_region(ia_cipr_buffer_t *parent,
                             uint32_t offset,
                             uint32_t size);

/**
 * Identify if CIPR buffer is of region type
 *
 * \ingroup ia_cipr_memory
 *
 * \param[in]   parent buffer object
 */
bool ia_cipr_buffer_is_region(ia_cipr_buffer_t *buffer);


/**
 * Get CIPR region buffer parent object
 *
 * \ingroup ia_cipr_memory
 *
 * \param[in]   buffer region buffer object
 */
ia_cipr_buffer_t* ia_cipr_buffer_get_parent(ia_cipr_buffer_t *buffer);

/**
 * Allocate memory described by buffer object
 *
 * \ingroup ia_cipr_memory
 *
 * \param[in]   buffer  buffer object
 */
css_err_t
ia_cipr_buffer_allocate(ia_cipr_buffer_t *buffer);

/**
 * Get memory accessor and flags of buffer object
 *
 * \ingroup ia_cipr_memory
 *
 * \param[in]   buffer  buffer object
 * \param[out]  memory  host memory access information
 */
css_err_t
ia_cipr_buffer_get_memory(ia_cipr_buffer_t *buffer,
                          ia_cipr_memory_t *memory);

/**
 * Get memory device identifier
 *
 * \ingroup ia_cipr_memory
 *
 * \param[in]   buffer  buffer object
 */
ia_cipr_device_id_t
ia_cipr_buffer_get_device_id(ia_cipr_buffer_t *buffer);

/**
 * Destroy buffer object
 *
 * \ingroup ia_cipr_memory
 */
void ia_cipr_buffer_destroy(ia_cipr_buffer_t *buf);


#endif /* _IA_CIPR_MEMORY_H_ */

