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

#ifndef _IA_CIPF_ITERATOR_H_
#define _IA_CIPF_ITERATOR_H_

#include "ia_cipf_types.h"

/** \defgroup ia_cipf_iterator Iterator (ia_cipf_iterator_t)
 * \ingroup ia_cipf
 * \brief the ia_cipf_iterator_t object interface
 */

/**
 * \ingroup ia_cipf_iterator
 */
ia_cipf_iterator_t*
ia_cipf_iterator_create(ia_cipf_pipe_t *pipe);

/**
 * \ingroup ia_cipf_iterator
 */
void
ia_cipf_iterator_destroy(ia_cipf_iterator_t *iterator);

/** Enumerate stages in iteration
 *
 * This function provides convenient way to associate user control flows
 * over multiple stages in single iteration. User can identify stages in the
 * pipeline at pipeline setup phase using UIDs and then scatter the controls
 * over each iteration the way suitable for pipeline execution model.
 *
 * \ingroup ia_cipf_iterator
 *
 * \param[in] iterator handle to iterator object
 * \param[in] index index of stage in iterator
 * \return    UID of the stage at index. Zero in case of error or index out of
 *            bounds
 */
ia_uid
ia_cipf_iteration_enumerate_stages(ia_cipf_iterator_t *iterator,
                                   uint32_t index);

/** Set buffer object for iteration execute
 *
 * User must set all the buffers required by the iterator
 * object before calling ia_cipf_iteration_execute().
 *
 * Note: It is not a CIPF requirement that buffer objects passed with this
 *       function were pre-registered with ia_cipf_pipe_register_buffer(),
 *       but the objects must be pre-associated with the association
 *       information available via ia_cipf_pipe_next_buffer_requirement()
 *       enumeration.
 *
 * \ingroup ia_cipf_iterator
 */
css_err_t
ia_cipf_iteration_set_buffer(ia_cipf_iterator_t *iterator,
                             ia_cipf_buffer_t   *buffer);

/** Get result buffer from iteration execute
 *
 * This function takes pointers pointer to buffer pre-associated with the
 * stage and its buffer purpose in before hand. Usually, this pointer is the
 * one previously set using ia_cipf_iteration_set_buffer(). Function shall be
 * called only after ia_cipf_iteration_wait().
 *
 * When the stage realization being used is known to not to introduce delays,
 * the call is functionally redundant. Therefore, it is not hard requirement
 * to use this function, but preferred for consistency. In scenarios where
 * delays are introduced, the user of iterator is required to cycle buffers
 * per pipeline requirements.
 *
 * \ingroup ia_cipf_iterator
 *
 * \param[in]       iterator  ia_cipf_iterator_t object handle
 * \param[in,out]   buffer    pointer to ia_cipf_buffer_t object handle
 */
css_err_t
ia_cipf_iteration_get_buffer(ia_cipf_iterator_t *iterator,
                             ia_cipf_buffer_t   **buffer);

/** Get result buffer from iteration execute
 *
 * Similar to ia_cipf_iteration_get_buffer but instead of using an already
 * existing buffer, use ia_cipf_association_t struct to identify the terminal
 * the buffer is being queried from.
 *
 * \ingroup ia_cipf_iterator
 *
 * \param[in]    iterator    ia_cipf_iterator_t object handle
 * \param[in]    association pointer to ia_cipf_association_t struct
 * \param[out]   buffer      pointer to ia_cipf_buffer_t object handle
 */
css_err_t
ia_cipf_iteration_get_buffer_by_association(ia_cipf_iterator_t *iterator,
                                            const ia_cipf_association_t *association,
                                            ia_cipf_buffer_t **buffer);

/** Execute iteration
 *
 * All the buffers must be set to the iterator object before execute.
 *
 * This function takes care of executing the individual stages according to the
 * graph. If single iterator covers the whole graph, it means execution of one
 * cycle.
 *
 * Iterator object consists of one or more stages from the graph in
 * ia_cipf_pipe_t object originally used to create it.
 *
 * Model of execution depends on DAG descriptor and support for different
 * execution models is exposed by the stage realizations used in graph.
 * Execute calls to individual stage realizations in single iterator are
 * always serialized and done in fixed order traversal through the graph.
 *
 * The stage execute itself can be asynchronous and hence two or more stages
 * can be preset in graph for parallel execution. However, iterator with
 * parallel stages always needs a final stage joining the inputs and offering
 * a single synchronization point for ia_cipf_iteration_wait().
 *
 * TODO: Multi-iteration, user threaded and interleaved execution models
 *
 * \ingroup ia_cipf_iterator
 */
css_err_t
ia_cipf_iteration_execute(ia_cipf_iterator_t *iterator);

/**
 * \ingroup ia_cipf_iterator
 */
css_err_t
ia_cipf_iteration_wait(ia_cipf_iterator_t *iterator);

/**
 * \ingroup ia_cipf_iterator
 */
ia_cipf_iterator_t*
ia_cipf_iteration_next(ia_cipf_iterator_t *iterator);

#endif /* _IA_CIPF_ITERATOR_H_ */
