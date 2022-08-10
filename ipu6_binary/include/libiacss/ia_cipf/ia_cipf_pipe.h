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

#ifndef _IA_CIPF_PIPE_H_
#define _IA_CIPF_PIPE_H_

#include "ia_cipf_types.h"

/** \defgroup ia_cipf_pipe Pipe (ia_cipf_pipe_t)
 * \ingroup ia_cipf
 * \brief the ia_cipf_pipe_t object inteface
 */

/**
 * \ingroup ia_cipf_pipe
 */
ia_cipf_pipe_t *
ia_cipf_pipe_create(void);

/**
 * \ingroup ia_cipf_pipe
 */
void
ia_cipf_pipe_destroy(ia_cipf_pipe_t *pipe);

/**
 * Load the pipeline
 * \param pipe the pipeline
 * \return css_err_none if successful
 * \ingroup ia_cipf_pipe
 */
css_err_t
ia_cipf_pipe_load(ia_cipf_pipe_t *pipe);

/** Enumerate input terminals in the pipe
 *
 * Note: Indexes do not necessary follow topological/natural order. Instead the
 * order in current implementation bases on the order of connections.
 * Enumeration function is provided for runtime searching the terminals with
 * some specific information associated to them. If client is after a static
 * accessor to certain terminal, _get_terminal_by_uid() should be used
 * instead.
 *
 * \ingroup ia_cipf_pipe
 */
ia_cipf_terminal_t*
ia_cipf_pipe_get_input_terminal(ia_cipf_pipe_t *pipe,
                                uint32_t index);

/** Enumerate output terminals in the pipe
 *
 * Note: Indexes do not necessary follow topological/natural order. Instead the
 * order in current implementation bases on the order of connections.
 * Enumeration function is provided for runtime searching the terminals with
 * some specific information associated to them. If client is after a static
 * accessor to certain terminal, _get_terminal_by_uid() should be used
 * instead.
 *
 * \ingroup ia_cipf_pipe
 */
ia_cipf_terminal_t*
ia_cipf_pipe_get_output_terminal(ia_cipf_pipe_t *pipe,
                                 uint32_t index);

/**
 * \ingroup ia_cipf_pipe
 */
ia_cipf_terminal_t*
ia_cipf_pipe_get_terminal_by_uid(ia_cipf_pipe_t *pipe,
                                 ia_uid uid);

/**
 * \ingroup ia_cipf_pipe
 */
css_err_t
ia_cipf_pipe_next_unidentified_property(ia_cipf_pipe_t *pipe,
                                        ia_cipf_property_t **property);

/** Get buffers required by pipeline one by one
 *
 * Client can enumerate through pipeline buffer requirements using
 * single loop. That is, next requirement does not return buffers
 * of terminals already satisfied.
 *
 * Typically client places the data pointer into the returned ia_cipf_buffer
 * and then use it to register the allocated memory.
 * Client is responsible to FREE the returned ia_cipf_buffer via
 * ia_cipf_buffer_destroy -function once done using it.
 * ia_cipf_buffer contains the information of terminal where it belongs
 * to, this can be used to target ANY ia_buffer's inside to their places
 * while iterating the pipeline.
 *
 * \ingroup ia_cipf_pipe
 */
css_err_t
ia_cipf_pipe_next_buffer_requirement(ia_cipf_pipe_t *pipe,
                                     ia_cipf_buffer_t **buffer);

/** Add property to the pipe
 *
 * Adds the given property to the pipe object. Once the function returns, the
 * ownership of property object is passed to pipe and given property will be
 * destroyed with the pipe.
 *
 * \ingroup ia_cipf_pipe
 *
 * \param[in]  pipe   handle to the pipe
 * \param[in]  uid    UID of property to add
 * \param[in]  prop   property to be added
 *
 * \return     css_err_none if successful
 */
css_err_t
ia_cipf_pipe_add_property(ia_cipf_pipe_t *pipe,
                          ia_uid uid,
                          ia_cipf_property_t *prop);

/** Set property of pipe
 *
 * Sets the property found by the association information present in the
 * property given by the user. Also stage and terminal properties inside this
 * pipeline can be set. Given property is assigned to the property already
 * existing. Ownership of the property is not transferred, the user must destroy
 * it after the function returns.
 *
 * \ingroup ia_cipf_pipe
 *
 * \param[in]  pipe   handle to the pipe
 * \param[in]  prop   property to assign into associated property in pipe
 *
 * \return     css_err_none if successful
 */
css_err_t
ia_cipf_pipe_set_property(ia_cipf_pipe_t *pipe,
                          const ia_cipf_property_t *prop);

/** Set property of pipe by uid
 *
 * Sets the pipe property with the given uid. Any association information
 * present in the property given by the user is ignored. Given property is
 * assigned to the property already existing. Ownership of the property is not
 * transferred, the user must destroy it after the function returns.
 *
 * \ingroup ia_cipf_pipe
 *
 * \param[in]  pipe   handle to the pipe
 * \param[in]  uid    UID of property to set
 * \param[in]  prop   property to assign into associated property in pipe
 *
 * \return     css_err_none if successful
 */
css_err_t
ia_cipf_pipe_set_property_by_uid(ia_cipf_pipe_t *pipe,
                                 ia_uid,
                                 const ia_cipf_property_t *prop);

/** Get copy of property of pipe
 *
 * Gets a copy of a property found with the association information present
 * in the given property object. Property without the association info is
 * considered an error. Supports getting pipe, stage and terminal level
 * properties. The received property can be used in the set functions.
 *
 * \ingroup ia_cipf_pipe
 *
 * \param[in]       pipe   handle to the pipe
 * \param[in, out]  prop   property object where copy will be stored
 *
 * \return          css_err_none if successful
 */
css_err_t
ia_cipf_pipe_get_property(ia_cipf_pipe_t *pipe,
                          ia_cipf_property_t *prop);

/** Get copy of property of pipe by uid
 *
 * Gets a copy of a pipe property found by the given uid. The contents and the
 * association information of the property found are copied into a property
 * object given by the user. The received property can be used in the set
 * functions.
 *
 * \ingroup ia_cipf_pipe
 *
 * \param[in]       pipe   handle to the pipe
 * \param[in]       uid    UID of property to get
 * \param[in, out]  prop   property object where copy will be stored
 *
 * \return          css_err_none if successful
 */
css_err_t
ia_cipf_pipe_get_property_by_uid(ia_cipf_pipe_t *pipe,
                                 ia_uid uid,
                                 ia_cipf_property_t *prop);

/** Get reference to pipe property by UID
 *
 * Hands over the reference to property from pipe by uid. Only the constant
 * reference to the property is returned.
 *
 * \ingroup ia_cipf_pipe
 *
 * \param[in] pipe    handle to the pipe
 * \param[in] uid     UID of property to fetch
 *
 * \return    reference to requested property
 */
const ia_cipf_property_t*
ia_cipf_pipe_get_property_ref(ia_cipf_pipe_t *pipe, ia_uid uid);

/**
 * \ingroup ia_cipf_pipe
 */
css_err_t
ia_cipf_pipe_register_buffer(ia_cipf_pipe_t *pipe,
                             ia_cipf_buffer_t *buffer);

/**
 * \ingroup ia_cipf_pipe
 */
css_err_t
ia_cipf_pipe_unregister_buffer(ia_cipf_pipe_t *pipe,
                               ia_cipf_buffer_t *buffer);

/**
 * \ingroup ia_cipf_pipe
 */
uint32_t
ia_cipf_pipe_get_num_stages(const ia_cipf_pipe_t *pipe);

/**
 * \ingroup ia_cipf_pipe
 */
ia_cipf_stage_t *
ia_cipf_pipe_enumerate_stages(const ia_cipf_pipe_t *pipe,
                              uint32_t idx);

/**
 * \ingroup ia_cipf_pipe
 */
ia_cipf_stage_t*
ia_cipf_pipe_get_stage_by_uid(const ia_cipf_pipe_t *pipe, ia_uid uid);

/**
 * \ingroup ia_cipf_pipe
 * \return css_err_none if successful
 */
css_err_t
ia_cipf_pipe_add_connection(ia_cipf_pipe_t       *pipe,
                            ia_cipf_connection_t *connection);

/**
 * \ingroup ia_cipf_pipe
 */
css_err_t
ia_cipf_pipe_connect(ia_cipf_pipe_t  *pipe,
                     ia_cipf_stage_t *source_stage,
                     ia_cipf_terminal_t *source_terminal,
                     ia_cipf_stage_t *sink_stage,
                     ia_cipf_terminal_t *sink_terminal,
                     ia_cipf_connection_type_t copnn_type);


/**
 * \ingroup ia_cipf_pipe
 */
ia_cipf_connection_t*
ia_cipf_pipe_get_connection_branch(ia_cipf_pipe_t *pipe,
                                   ia_cipf_stage_t *source_stage,
                                   int32_t branch_id);

#endif /* _IA_CIPF_PIPE_H_ */
