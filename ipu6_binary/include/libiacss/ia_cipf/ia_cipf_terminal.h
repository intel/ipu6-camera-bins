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

#ifndef _IA_CIPF_TERMINAL_H_
#define _IA_CIPF_TERMINAL_H_

#include "ia_cipf_types.h"

/** \defgroup ia_cipf_terminal Terminal (ia_cipf_terminal_t)
 * \ingroup ia_cipf
 * \brief the ia_cipf_terminal_t object iterface
 */

/**
 * \ingroup ia_cipf_terminal
 * \todo add comments
 */
ia_cipf_terminal_t *
ia_cipf_terminal_create(void);

/**
 * \ingroup ia_cipf_terminal
 * \todo add comments
 */
void
ia_cipf_terminal_destroy(ia_cipf_terminal_t *terminal);

/** Set terminal frame format
 *
 * \ingroup ia_cipf_terminal
 *
 * \param[in]      terminal    ia_cipf_terminal handle
 * \param[in]      ff          ia_cipf_frame_format to be set
 */
css_err_t
ia_cipf_terminal_set_format(ia_cipf_terminal_t *terminal, ia_cipf_frame_format_t *ff);

/** Get terminal frame format
 *
 * \ingroup ia_cipf_terminal
 *
 * \param[in]       terminal    ia_cipf_terminal handle
 * \param[in,out]   ff          ia_cipf_frame_format to be filled with given terminal
 *                              format
 */
css_err_t
ia_cipf_terminal_get_format(ia_cipf_terminal_t *terminal, ia_cipf_frame_format_t *ff);

/** Get terminal frame format reference
 *
 * Returns direct reference to terminal frame format structure. Returned
 * reference origins from the terminal hosting the connection
 * (source for push type and sink for pull type) - the terminal possessing
 * the pool of buffers. Hence, this reference can be used to determine
 * for what purpose ia_cipf_pipe_next_buffer_requirement() is requesting
 * a buffer.
 *
 * \ingroup ia_cipf_terminal
 *
 * \param[in]       terminal    ia_cipf_terminal handle
 * \return                      pointer to ia_cipf_frame_format,
 *                              or NULL if the terminal is not of 'frame type'
 */
const ia_cipf_frame_format_t*
ia_cipf_terminal_get_format_ref(ia_cipf_terminal_t *terminal);

/** Get terminal's stage
 *
 * \ingroup ia_cipf_terminal
 *
 * \param[in]       terminal    ia_cipf_terminal handle
 */
ia_cipf_stage_t*
ia_cipf_terminal_get_stage(ia_cipf_terminal_t *terminal);

/** Get terminal's index
 *
 * Get enumeration index of terminal in stage. Terminal indexes can be
 * used with ia_cipf_stage interface to access the same terminal again.
 *
 * Returns UINT_MAX in case of an error.
 *
 * \ingroup ia_cipf_terminal
 *
 * \param[in]       terminal    ia_cipf_terminal handle
 */
uint32_t
ia_cipf_terminal_get_index(ia_cipf_terminal_t *terminal);

/** Get remote terminal
 *
 * \ingroup ia_cipf_terminal
 *
 * \param[in]       terminal    ia_cipf_terminal handle
 */
ia_cipf_terminal_t*
ia_cipf_terminal_get_remote(ia_cipf_terminal_t *terminal);

/** Add property to the terminal
 *
 * Adds the given property to the terminal object. Once the function returns,
 * the ownership of property object is passed to terminal and given property
 * will be destroyed with the terminal.
 *
 * \ingroup ia_cipf_terminal
 *
 * \param[in]       terminal  handle to the terminal
 * \param[in]       uid       UID of property to add
 * \param[in]       prop      property to be added
 *
 * \return     css_err_none if successful
 */
css_err_t
ia_cipf_terminal_add_property(ia_cipf_terminal_t *terminal,
                              ia_uid uid,
                              ia_cipf_property_t *prop);

/** Set property of terminal
 *
 * Sets the property found by the association information present in the
 * property given by the user. Given property is assigned to the property
 * already existing. Ownership of the property is not transferred, the user must
 * destroy it after the function returns.
 *
 * \ingroup ia_cipf_terminal
 *
 * \param[in]       terminal    ia_cipf_terminal handle
 * \param[in]       prop        property to assign
 *
 * \return          css_err_none if successful
 */
css_err_t
ia_cipf_terminal_set_property(ia_cipf_terminal_t *terminal,
                              const ia_cipf_property_t *prop);

/** Set property of terminal by uid
 *
 * Sets the terminal property with the given uid. Any association information
 * present in the property given by the user is ignored. Given property is
 * assigned to the property already existing. Ownership of the property is not
 * transferred, the user must destroy it after the function returns.
 *
 * \ingroup ia_cipf_terminal
 *
 * \param[in]  terminal  handle to the terminal
 * \param[in]  uid       UID of property to set
 * \param[in]  prop      property to assign into associated property in pipe
 *
 * \return     css_err_none if successful
 */
css_err_t
ia_cipf_terminal_set_property_by_uid(ia_cipf_terminal_t *terminal,
                                     ia_uid uid,
                                     const ia_cipf_property_t *prop);

/** Get a copy of property of terminal
 *
 * Gets a copy of a property found with the association information present
 * in the given property object. Property without the association info is
 * considered an error. Supports getting terminal level properties. The
 * received property can be used in the set functions.
 *
 * \ingroup ia_cipf_terminal
 *
 * \param[in]       terminal    ia_cipf_terminal handle
 * \param[in, out]  prop        property object where copy will be stored
 *
 * \return          css_err_none if successful
 */
css_err_t
ia_cipf_terminal_get_property(ia_cipf_terminal_t *terminal,
                              ia_cipf_property_t *prop);

/** Get a copy of property of terminal by uid
 *
 * Gets a copy of a container property found by the given uid. The contents and
 * the association information of the property found are copied into a property
 * object given by the user. The received property can be used in the set
 * functions.
 *
 * \ingroup ia_cipf_terminal
 *
 * \param[in]       terminal    ia_cipf_terminal handle
 * \param[in]       uid         uid of property to search
 * \param[in, out]  prop        property object where copy will be stored
 *
 * \return          css_err_none if successful
 */
css_err_t
ia_cipf_terminal_get_property_by_uid(ia_cipf_terminal_t *terminal,
                                     ia_uid uid,
                                     ia_cipf_property_t *prop);

/** Get reference to terminal property by UID
 *
 * Hands over the reference to property from terminal by uid. Only the constant
 * reference to the property is returned.
 *
 * \ingroup ia_cipf_stage
 *
 * \param[in] stage   handle to the stage
 * \param[in] uid     UID of property to fetch
 *
 * \return    reference to requested property
 */
const ia_cipf_property_t*
ia_cipf_terminal_get_property_ref(ia_cipf_terminal_t *terminal, ia_uid uid);

/** Get current buffer of terminal
 *
 * \ingroup ia_cipf_terminal
 *
 * TODO: make it const
 *
 * \param[in]       terminal    ia_cipf_terminal handle
 */
ia_cipf_buffer_t*
ia_cipf_terminal_get_current_buffer(ia_cipf_terminal_t *terminal);

/** Get uid from terminal
 *
 * \ingroup ia_cipf_terminal
 *
 * \param[in]       terminal    ia_cipf_terminal handle
 */
ia_uid
ia_cipf_terminal_get_uid(ia_cipf_terminal_t *terminal);

/** Get enabled status from terminal
 *
 * \ingroup ia_cipf_terminal
 *
 * \param[in]       terminal    ia_cipf_terminal handle
 */
bool
ia_cipf_terminal_is_enabled(ia_cipf_terminal_t *terminal);

/** Get association from terminal
 *
 * Gets the association information of the given terminal to the empty
 * ia_cipf_association_t provided by the user.
 *
 * \ingroup ia_cipf_terminal
 *
 * \param[in]       terminal     ia_cipf_terminal handle
 * \param[out]      association  pointer to ia_cipf_association_t
 */
css_err_t
ia_cipf_terminal_get_association(const ia_cipf_terminal_t *terminal,
                                 ia_cipf_association_t *association);

/** Get type from terminal
 *
 * \ingroup ia_cipf_terminal
 *
 * \param[in]       terminal     ia_cipf_terminal handle
 * \param[out]      type         terminal type
 */
css_err_t
ia_cipf_terminal_get_type(ia_cipf_terminal_t *terminal,
                          ia_cipf_terminal_type_t *type);

#endif /* _IA_CIPF_TERMINAL_H_ */
