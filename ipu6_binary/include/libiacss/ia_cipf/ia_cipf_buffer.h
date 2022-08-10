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

#ifndef _IA_CIPF_BUFFER_H_
#define _IA_CIPF_BUFFER_H_

#include "ia_cipf_types.h"

/** \defgroup ia_cipf_buffer Buffer (ia_cipf_buffer_t)
 * \ingroup ia_cipf
 * \brief the ia_cipf_buffer_t object interface
 */

/**
 * \ingroup ia_cipf_buffer
 */
typedef css_err_t (*ia_cipf_buffer_reference_destroy_op)(void *ref);

/**
 * \ingroup ia_cipf_buffer
 */
ia_cipf_buffer_t*
ia_cipf_buffer_create(void);

/**
 * Create CIPF buffer object from user provided payload
 *
 * \ingroup ia_cipf_buffer
 *
 * \param[in] payload user provided payload (descriptor of data reference)
 */
ia_cipf_buffer_t *
ia_cipf_buffer_create_from_payload(ia_cipf_payload_t payload);

/** Replicate association to buffer based on reference buffer
 *
 * All buffers in CIPF need to be associated to some terminal or property
 * container. This is automatic for buffers queried. But usually multiple
 * buffers need to be allocated and separately created. With this function
 * caller can copy association from buffer to another.
 *
 * \ingroup ia_cipf_buffer
 */
css_err_t
ia_cipf_buffer_replicate_association(ia_cipf_buffer_t *buffer,
                                     const ia_cipf_buffer_t *ref);

/** Create a copy of ia_cipf_buffer_t
 *
 * Function creates a copy of ia_cipf_buffer_t including its association
 * and payload when it is allocated using ia_cipf_buffer_allocate_payload().
 *
 * By default ia_cipf_buffer_t::payload is reference owned by the caller.
 * Copying this type of payloads is not supported and caller must use
 * ia_cipf_buffer_replicate_association() added with custom operations
 * to copy the payload.
 *
 * \ingroup ia_cipf_buffer
 */
ia_cipf_buffer_t*
ia_cipf_buffer_create_copy(const ia_cipf_buffer_t *ref);

/** Allocate payload for the buffer
 *
 * By default ia_cipf_buffer_t::payload is reference owned by the caller.
 *
 * This function allocates the payload as data owned by the buffer.
 * This is the only type of payload that gets copied by
 * ia_cipf_buffer_create_copy().
 *
 * \ingroup ia_cipf_buffer
 */
css_err_t
ia_cipf_buffer_allocate_payload(ia_cipf_buffer_t *buffer, uint32_t size);

/**
 * \ingroup ia_cipf_buffer
 */
void
ia_cipf_buffer_destroy(ia_cipf_buffer_t *buffer);

/**
 * \ingroup ia_cipf_buffer
 */
css_err_t
ia_cipf_buffer_get_terminal_type(ia_cipf_buffer_t *buffer,
                                 ia_cipf_terminal_type_t *type);

/**
 * \ingroup ia_cipf_buffer
 */
ia_cipf_terminal_t*
ia_cipf_buffer_get_terminal(ia_cipf_buffer_t *buffer);

/**
 * Get identifier for association of given buffer object
 *
 * Returned identifier is ia_uid of container object, that
 * may derive to either terminal or property buffer requirement
 * of a stage in pipeline.
 *
 * \ingroup ia_cipf_buffer
 */
ia_uid
ia_cipf_buffer_get_association_uid(ia_cipf_buffer_t *buffer);

/** Get stage associated with buffer
 *
 * \ingroup ia_cipf_buffer
 */
ia_cipf_stage_t*
ia_cipf_buffer_get_stage(ia_cipf_buffer_t *buffer);

/** Get frame format associated with buffer
 *
 * In case buffer payload is identified as frame format, the payload
 * data is copied into frame format given as argument.
 *
 * In case buffer payload is something else, function queries the
 * native ia_cipf_frame_format_uid through the association.
 * \see ia_cipf_buffer_associate.
 *
 * \ingroup ia_cipf_buffer
 */
css_err_t
ia_cipf_buffer_get_frame_format(ia_cipf_buffer_t *buffer, ia_cipf_frame_format_t *ff);

/** Get frame stucture refence
 *
 * \ingroup ia_cipf_buffer
 */
ia_cipf_frame_t*
ia_cipf_buffer_get_frame_ref(ia_cipf_buffer_t *buffer);

/** Get payload of buffer section
 *
 * \ingroup ia_cipf_buffer
 *
 * \param[in]       buffer  handle to ia_cipf_buffer_t
 * \param[in]       uid     uid of the payload section to search
 * \param[out]      payload object to fill with relative reference
 *                          to buffer section.
 */
css_err_t
ia_cipf_buffer_get_payload_section_ref(ia_cipf_buffer_t *buffer,
                                       ia_uid uid,
                                       ia_cipf_payload_t *payload);

/** Query associated references from buffer
 *
 * \ingroup ia_cipf_buffer
 *
 * \param[in]       buffer  handle to ia_cipf_buffer_t.
 * \param[in]       uid     uid specifying the type of reference.
 * \param[out]      reference Pointers pointer to updated with reference if
 *                            found.
 */
css_err_t
ia_cipf_buffer_query_reference(const ia_cipf_buffer_t *buffer,
                               ia_uid uid,
                               void **reference);

/** Get buffer payload size
 *
 * Get the total size of the buffer payload. Multiplane buffers return the total
 * cumulated size of all planes.
 *
 * \ingroup ia_cipf_buffer
 *
 * \param[in]       buffer handle to ia_cipf_buffer_t
 * \param[out]      buffer payload size
 *
 * \return          css_err_none if successful
 */
css_err_t
ia_cipf_buffer_get_payload_size(ia_cipf_buffer_t *buffer,
                                uint32_t *size);

/** Get access to buffer payload
 *
 * Fetch payload information including host address to the data associated
 * with buffer object. While payload is public information in buffer object,
 * it may contain payload that requires interpretation or memory operations
 * before the data can be accessed by host code. This function includes the
 * operations for natively identified payloads, like buffer objects of
 * platform runtime.
 *
 * Note: function also skips one dimension with frame object of frame
 *       terminal. In this case, the first the payload of first plane is
 *       chosen. Handling multiplane frame requires specific care from a
 *       stage.
 *
 * \ingroup ia_cipf_buffer
 *
 * \param[in]       buffer handle to ia_cipf_buffer_t
 * \param[out]      payload object to fill with description of
 *                  buffer associated payload data
 *
 * \return          css_err_none if successful
 */
css_err_t
ia_cipf_buffer_access_payload(ia_cipf_buffer_t *buffer,
                              ia_cipf_payload_t *payload);

/** Check if buffer payload is external reference
 *
 * Convenience function to check whether the memory of payload is external
 * to buffer object.
 *
 * Note: In cases of complex CIPF pipelines, there can be memory providers in
 * the backend. Therefore this information is not enough to identify user
 * allocated buffers alone. More sophisticated bookkeeping of buffers is
 * suggested.
 *
 * \ingroup ia_cipf_buffer
 *
 * \param[in]       buffer handle to ia_cipf_buffer_t
 * \param[out]      is_reference true in case payload is external reference
 * \return          css_err_none if successful
 */
css_err_t
ia_cipf_buffer_is_reference_payload(ia_cipf_buffer_t *buffer,
                                    bool *is_reference);

/** Get the association information from the buffer
 *
 * \ingroup ia_cipf_buffer
 *
 * \param[in]       buffer       handle to ia_cipf_buffer_t
 * \param[out]      association  association information from the buffer
 * \return          css_err_none if successful
 */
css_err_t
ia_cipf_buffer_get_association(const ia_cipf_buffer_t *buffer,
                               ia_cipf_association_t *association);

/** Set the association information to the buffer
 *
 * \ingroup ia_cipf_buffer
 *
 * \param[in]       buffer       handle to ia_cipf_buffer_t
 * \param[in]       association  association information to the buffer
 * \return          css_err_none if successful
 */
css_err_t
ia_cipf_buffer_set_association(ia_cipf_buffer_t *buffer,
                               const ia_cipf_association_t *association);

/** Add new reference associated with buffer
 *
 * \ingroup ia_cipf_buffer
 *
 * \param[in]      buffer          ia_cipf_buffer_t handle
 * \param[in]      uid             uid of the reference
 * \param[in]      ref             pointer to the reference
 *
 * \return         css_err_none if successful
 */
css_err_t
ia_cipf_buffer_add_reference(ia_cipf_buffer_t *buffer,
                             ia_uid uid,
                             void *ref);

/** Add a new reference with destroy operation
 *
 * This function is otherwise similar to ia_cipf_buffer_add_reference, except
 * that an additional destroy operation is also included. The destroy operation
 * can be used for e.g. freeing allocated memory.
 *
 * \see ia_cipf_buffer_add_reference
 *
 * \ingroup ia_cipf_buffer
 *
 * \param[in]      buffer          ia_cipf_buffer_t handle
 * \param[in]      uid             uid of the reference
 * \param[in]      ref             pointer to the reference
 * \param[in]      op              function pointer to reference destroy op
 *
 * \return         css_err_none if successful
 */
css_err_t
ia_cipf_buffer_add_reference_with_ops(ia_cipf_buffer_t *buffer,
                                      ia_uid uid,
                                      void *ref,
                                      ia_cipf_buffer_reference_destroy_op op);



#endif /* _IA_CIPF_BUFFER_H_ */
