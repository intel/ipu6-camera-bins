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

#ifndef _IA_CIPF_TERMINAL_BASE_H_
#define _IA_CIPF_TERMINAL_BASE_H_

#include "ia_cipf_types.h"

/** \defgroup terminal_base Terminal Base
 * \ingroup ia_cipf_backend
 * \brief Terminal base (terminal_base) implements functionality common between all stage
 * terminals realized using CIPF. This includes handling of terminal formats
 * and propagation of operations to different realizations with common rules.
 *
 * \mscfile cipf_terminal.signalling Terminal connection sequences
 */

typedef enum terminal_format_state {
     terminal_format_state_na,           /* format not set */
     terminal_format_state_hosting,      /* format being negotiated, terminal hosting the format selection */
     terminal_format_state_validating,   /* format being negotiated, terminal validating the remote format */
     terminal_format_state_propagating,  /* format being propagated to connected terminal */
     terminal_format_state_active        /* format set and stored as current */
} terminal_format_state_t;

typedef struct terminal_format
{
    ia_cipf_frame_format_t format;
    terminal_format_state_t state;
} terminal_format_t;

/* function pointer type definitions
 * for terminal operations*/
typedef css_err_t (*terminal_buffer_op)(ia_cipf_terminal_t*, ia_cipf_buffer_t*);
typedef css_err_t (*terminal_buffer_ref_op)(ia_cipf_terminal_t*, ia_cipf_buffer_t**);
typedef css_err_t (*terminal_set_format_op)(ia_cipf_terminal_t*, const ia_cipf_frame_format_t*);
typedef css_err_t (*terminal_get_format_op)(ia_cipf_terminal_t*, ia_cipf_frame_format_t*);
typedef css_err_t (*terminal_set_property_op)(ia_cipf_terminal_t*, ia_uid uid, const ia_cipf_property_t*);
typedef css_err_t (*terminal_get_property_op)(ia_cipf_terminal_t*, ia_uid uid, ia_cipf_property_t*);

/** Create terminal base
 *
 * \ingroup terminal_base
 *
 * \param[in]      stage           ia_cipf_stage_t handle
 * \param[in]      terminal_uid    uid of the terminal
 * \param[in]      type            type of the terminal
 *
 * \return         pointer to the created terminal, NULL if failed
 */
ia_cipf_terminal_t*
terminal_base_create(ia_cipf_stage_t *stage,
                     ia_uid terminal_uid,
                     ia_cipf_terminal_type_t type);

/** Set terminal buffer operations
 *
 * With this function, the stage realization can associate handlers for buffer
 * operations on its terminal.
 *
 * \ingroup terminal_base
 *
 * \param[in]      terminal           ia_cipf_terminal handle
 * \param[in]      pull_op            function pointer for buffer pull() operation
 * \param[in]      push_op            function pointer for buffer push() operation
 * \param[in]      get_requirement_op function pointer for buffer get_requirement() operation
 * \param[in]      register_op        function pointer for buffer register() operation
 * \param[in]      unregister_op      function pointer for buffer unregister() operation
 *
 * \return         css_err_none if successful
 */
css_err_t
terminal_base_set_buffer_operations(ia_cipf_terminal_t *terminal,
                                    terminal_buffer_ref_op pull_op,
                                    terminal_buffer_op push_op,
                                    terminal_buffer_op get_requirement_op,
                                    terminal_buffer_op register_op,
                                    terminal_buffer_op unregister_op);

/** Set terminal format operations
 *
 * With this function, the stage realization can associate handlers for format
 * operations on its terminal.
 *
 * \ingroup terminal_base
 *
 * \param[in]      terminal         ia_cipf_terminal handle
 * \param[in]      set_format_op    function pointer for set_format() operation
 * \param[in]      get_format_op    function pointer for get_format() operation
 *
 * \return         css_err_none if successful
 */
css_err_t
terminal_base_set_format_operations(ia_cipf_terminal_t *terminal,
                                    terminal_set_format_op set_format_op,
                                    terminal_get_format_op get_format_op);

/** Set terminal format operations
 *
 * With this function, the stage realization can associate handlers for property
 * operations on its terminal.
 *
 * \ingroup terminal_base
 *
 * \param[in]      terminal         ia_cipf_terminal handle
 * \param[in]      set_property_op  function pointer for set_property() operation
 * \param[in]      get_property_op  function pointer for get_property() operation
 *
 * \return         css_err_none if successful
 */
css_err_t
terminal_base_set_property_operations(ia_cipf_terminal_t *terminal,
                                      terminal_set_property_op set_property_op,
                                      terminal_get_property_op get_property_op);

/** Set terminal to delay mode
 *
 * Sets up the terminal to use ring buffer for delayed buffers exchange
 * operation. Terminal will require delay + 1 buffers to operate at minimum.
 * Push- and pull-operations and other stage semantics remain equivalent.
 *
 * \ingroup terminal_base
 * \param[in] terminal  ia_cipf_terminal_t handle
 * \param[in] delay number of buffers to delay
 */
css_err_t
terminal_base_set_delay_mode(ia_cipf_terminal_t *terminal,
                             uint32_t delay);

/** Set connection to terminal
 *
 * \ingroup terminal_base
 *
 * \param[in]      terminal         ia_cipf_terminal_t handle
 * \param[in]      connection       pointer to connection
 *
 * \return         css_err_none if successful
 */
css_err_t
terminal_base_set_connection(ia_cipf_terminal_t *terminal,
                             ia_cipf_connection_t *connection);

/** Get connection from terminal
 *
 * \ingroup terminal_base
 *
 * \param[in]      terminal         ia_cipf_terminal_t handle
 *
 * \return         pointer to connection
 */
ia_cipf_connection_t*
terminal_base_get_connection(ia_cipf_terminal_t *terminal);

/** Get format from terminal
 *
 * \ingroup terminal_base
 *
 * \param[in]      terminal         ia_cipf_terminal_t handle
 *
 * \return         pointer to terminal format struct
 */
struct terminal_format*
terminal_base_get_format(ia_cipf_terminal_t *terminal);

/** Set terminal format
 *
 * \ingroup terminal_base
 *
 * \param[in]      terminal         ia_cipf_terminal_t handle
 * \param[in]      ff               const pointer to frame format
 *
 * \return         css_err_none if successful
 */
css_err_t
terminal_base_set_format(ia_cipf_terminal_t *terminal,
                         const ia_cipf_frame_format_t *ff);

/** Get remote terminal from terminal
 *
 * If terminal is connected, returns the connected terminal.
 *
 * \ingroup terminal_base
 *
 * \param[in]      terminal         ia_cipf_terminal_t handle
 *
 * \return         pointer to the connected terminal, NULL if failed
 */
ia_cipf_terminal_t*
terminal_base_get_remote(ia_cipf_terminal_t *terminal);

/** Get remote terminal if argument is the host terminal
 *
 * If terminal is connected and the argument terminal is the host, returns
 * the connected terminal.
 *
 * \ingroup terminal_base
 *
 * \param[in]      terminal         ia_cipf_terminal_t handle
 *
 * \return         pointer to the connected terminal, NULL if failed
 */
ia_cipf_terminal_t*
terminal_base_get_remote_if_host(ia_cipf_terminal_t *terminal);

/** Store frame format to terminal
 *
 * \ingroup terminal_base
 *
 * \param[in]      terminal         ia_cipf_terminal_t handle
 * \param[in]      ff               const pointer to frame format
 * \param[in]      state            terminal format state
 *
 * \return         css_err_none if successful
 */
css_err_t
terminal_base_store_format(ia_cipf_terminal_t *terminal,
                           const ia_cipf_frame_format_t *ff,
                           terminal_format_state_t state);

/**
 * Add terminal associated property to terminal
 *
 * \ingroup terminal_base
 *
 * \param[in]      terminal    ia_cipf_terminal handle
 * \param[in]      uid         uid for property
 * \param[in]      property    property to be added
 *
 * \return         css_err_none if successful
 */
css_err_t
terminal_base_add_property(ia_cipf_terminal_t *terminal,
                           ia_uid uid,
                           ia_cipf_property_t *property);

/**
* Remove terminal associated property from terminal
*
* \ingroup terminal_base
*
* \param[in]      terminal    ia_cipf_terminal handle
* \param[in]      property    property to be removed
*
* \return         css_err_none if successful
*/
css_err_t
terminal_base_remove_property(ia_cipf_terminal_t *terminal,
                              ia_cipf_property_t *property);

/**
 * Add buffer associated property to terminal
 *
 * \ingroup terminal_base
 *
 * \param[in]      terminal    ia_cipf_terminal handle
 * \param[in]      uid         uid for property
 * \param[in]      property    property to be added
 *
 * \return         css_err_none if successful
 */
css_err_t
terminal_base_add_buffer_descriptor_property(ia_cipf_terminal_t *terminal,
                                             ia_uid uid,
                                             ia_cipf_property_t *property);

/**
 * Get terminal property reference
 *
 * \ingroup terminal_base
 *
 * \param[in]      terminal    ia_cipf_terminal handle
 * \param[in]      uid         uid for property
 *
 * \return         pointer to property
 */
ia_cipf_property_t*
terminal_base_get_property_ref(ia_cipf_terminal_t *terminal,
                               ia_uid uid);

ia_cipf_property_t*
terminal_base_get_property_ref_by_index(ia_cipf_terminal_t *terminal,
                                        uint32_t index);

uint32_t
terminal_base_get_num_properties(ia_cipf_terminal_t *terminal);

/**
 * Get remote terminal property reference
 *
 * \ingroup terminal_base
 *
 * \param[in]      terminal    ia_cipf_terminal handle
 * \param[in]      uid         uid for property
 *
 * \return         pointer to property
 */
ia_cipf_property_t*
terminal_base_get_remote_property_ref(ia_cipf_terminal_t *terminal,
                                      ia_uid uid);

/**
 * Get terminal property
 *
 * \ingroup terminal_base
 *
 * \param[in]      terminal    ia_cipf_terminal handle
 * \param[in]      property    property object where contents will be copied
 *
 * \return         css_err_none if successful
 */
css_err_t
terminal_base_get_property(ia_cipf_terminal_t *terminal,
                           ia_cipf_property_t *property);

/**
 * Get terminal property
 *
 * \ingroup terminal_base
 *
 * \param[in]      terminal    ia_cipf_terminal handle
 * \param[in]      uid         uid of property to get
 * \param[in]      property    property object where contents will be copied
 *
 * \return         css_err_none if successful
 */
css_err_t
terminal_base_get_property_by_uid(ia_cipf_terminal_t *terminal,
                                  ia_uid uid,
                                  ia_cipf_property_t *property);

/**
 * Set terminal property
 *
 * \ingroup terminal_base
 *
 * \param[in]      terminal    ia_cipf_terminal handle
 * \param[in]      property    property to set
 *
 * \return         css_err_none if successful
 */
css_err_t
terminal_base_set_property(ia_cipf_terminal_t *terminal,
                           const ia_cipf_property_t *property);

/** Base implementation for assigning terminal property
 *
 * This is the base implementation for property assign, and can be used by stage
 * implementations for general property assign, * i.e. setting properties that
 * do not need special handling.
 *
 * \ingroup terminal_base
 *
 * \param[in]      terminal        ia_cipf_terminal_t handle
 * \param[in]      uid             uid of the terminal property to be assigned to
 * \param[in]      property        handle of the property being assigned
 *
 * \return         css_err_none if successful
 */
css_err_t
terminal_base_assign_property(ia_cipf_terminal_t *terminal,
                              ia_uid uid,
                              const ia_cipf_property_t *property);
/**
 * Set terminal property by uid
 *
 * \ingroup terminal_base
 *
 * \param[in]      terminal    ia_cipf_terminal handle
 * \param[in]      uid         uid of property to set
 * \param[in]      property    property to set
 *
 * \return         css_err_none if successful
 */
css_err_t
terminal_base_set_property_by_uid(ia_cipf_terminal_t *terminal,
                                  ia_uid uid,
                                  const ia_cipf_property_t *property);

/**
 * Add terminal description for buffer section
 *
 * Buffer sections can be added to parameter terminal. Sections become
 * accessible to user via ia_cipf_buffer_get_payload_section().
 * Offset defines a sub-region in every ia_cipf_buffer_t payload that is
 * registered with the terminal. Terminal base implementation takes care of
 * buffer requirement calculation and the pointer arithmetic.
 *
 * \ingroup terminal_base
 *
 * \param[in]      terminal    ia_cipf_terminal handle
 * \param[in]      uid         uid of section to set
 * \param[in]      offset      Optional offset from base buffer address.
 *                             With 0, terminal base uses cumulated sizes of
 *                             preceeding properties in terminal for offset.
 * \param[in]      size        size of property region
 *
 * \return         css_err_none if successful
 */
css_err_t
terminal_base_add_buffer_section(ia_cipf_terminal_t *terminal,
                                 ia_uid uid,
                                 uint32_t offset,
                                 uint32_t size);

/**
 * Add new unidentified property to terminal
 *
 * Unidentified property represents data payload requirement which size is not
 * initially known and needs further user actions. Enumeration for unidentified
 * properties in pipeline is mandatory step in pipeline setup
 * (See ia_cipf_pipe_next_unidentified_property())
 *
 * \ingroup terminal_base
 *
 * \param[in]      terminal    ia_cipf_terminal handle
 * \param[in]      uid         uid of property to add
 *
 * \return         css_err_none if successful
 */
css_err_t
terminal_base_add_unidentified_property(ia_cipf_terminal_t *terminal,
                                        ia_uid property_uid);

/**
 * Get buffer from terminal
 *
 * This function is intended for execute phase of stage realizations.
 * Stage implementations MUST call this function in order to correctly
 * fetch the buffers from terminals. Call is routed according to terminal
 * connection type and may block in pull operation of remote terminal.
 *
 * \ingroup terminal_base
 *
 * \param[in]       terminal ia_cipf_terminal_t handle
 * \param[out]      buffer  pointer to buffer object handle
 *
 * \return          css_err_none if successful
 */
css_err_t
terminal_base_get_buffer(ia_cipf_terminal_t *terminal,
                         ia_cipf_buffer_t **buffer);

/**
 * Get type from terminal
 *
 * \ingroup terminal_base
 *
 * \param[in]       terminal ia_cipf_terminal_t handle
 *
 * \return          terminal type
 */
ia_cipf_terminal_type_t
terminal_base_get_type(ia_cipf_terminal_t *terminal);

css_err_t
terminal_base_set_enabled(ia_cipf_terminal_t *terminal,
                          bool enabled);

#endif /* _IA_CIPF_TERMINAL_BASE_H_ */
