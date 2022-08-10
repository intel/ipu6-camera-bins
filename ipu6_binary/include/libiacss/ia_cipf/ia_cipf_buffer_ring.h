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

#ifndef __IA_CIPF_BUFFER_RING_H__
#define __IA_CIPF_BUFFER_RING_H__

#include "ia_cipf_types_internal.h"

/** CIPF Ring-buffer
 * Note: the routines are made overloadable mainly to allow threadsafe
 *       implementations to be platform/OS specific. Each mode is
 *       tentatively considered to have its own implementation.
 *       Blocking mode is meant for scenarios where ring-buffer in CIPF
 *       terminal is used as data synchronization barrier between two
 *       threaded iterations. Also non-blocking lockfree solution can be
 *       provided.
 *
 * \todo overloading with platform specific create
 *
 * \todo document ia_cipf_buffer_ring
 */

ia_cipf_buffer_ring_t*
ia_cipf_buffer_ring_create(unsigned int depth,
                           ia_cipf_buffer_ring_mode_t mode,
                           bool overwrite);

void
ia_cipf_buffer_ring_destroy(ia_cipf_buffer_ring_t *ring);

css_err_t
ia_cipf_buffer_ring_push(ia_cipf_buffer_ring_t *ring,
                         ia_cipf_buffer_t *buffer);

css_err_t
ia_cipf_buffer_ring_pop(ia_cipf_buffer_ring_t *ring,
                        ia_cipf_buffer_t **buffer);

bool ia_cipf_buffer_ring_full(ia_cipf_buffer_ring_t *ring);

bool ia_cipf_buffer_ring_empty(ia_cipf_buffer_ring_t *ring);

uint32_t ia_cipf_buffer_ring_depth(ia_cipf_buffer_ring_t *ring);

uint32_t ia_cipf_buffer_ring_count(ia_cipf_buffer_ring_t *ring);

typedef struct _cipf_buffer_ring_impl ia_cipf_buffer_ring_impl_t;

typedef void (*cipf_ring_destroy_op)(ia_cipf_buffer_ring_impl_t *ring);
typedef css_err_t (*cipf_ring_push_op)(ia_cipf_buffer_ring_impl_t *ring,
                                      ia_cipf_buffer_t *buffer);
typedef bool (*cipf_ring_full_op)(ia_cipf_buffer_ring_impl_t *ring);
typedef bool (*cipf_ring_empty_op)(ia_cipf_buffer_ring_impl_t *ring);
typedef uint32_t (*cipf_ring_depth_op)(ia_cipf_buffer_ring_impl_t *ring);
typedef uint32_t (*cipf_ring_count_op)(ia_cipf_buffer_ring_impl_t *ring);
typedef css_err_t (*cipf_ring_pop_op)(ia_cipf_buffer_ring_impl_t *ring,
                                     ia_cipf_buffer_t **buffer);

struct _cipf_buffer_ring {
    ia_cipf_buffer_ring_impl_t *impl;
    /* Overloadable operations */
    cipf_ring_destroy_op    destroy_op;
    cipf_ring_push_op       push_op;
    cipf_ring_pop_op        pop_op;
    cipf_ring_full_op       full_op;
    cipf_ring_empty_op      empty_op;
    cipf_ring_depth_op      depth_op;
    cipf_ring_count_op      count_op;
};


#endif
