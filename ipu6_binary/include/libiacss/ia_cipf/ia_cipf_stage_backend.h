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

#ifndef _IA_CIPF_STAGE_BACKEND_H_
#define _IA_CIPF_STAGE_BACKEND_H_

#include <ia_cipf/ia_cipf_types.h>
#include <ia_cipf/ia_cipf_stage.h>

/** \defgroup ia_cipf_stage_backend Stage backend
 *
 * \ingroup ia_cipf_backend
 * \brief CIPF interface for stage realizations
 */

/**
 * \ingroup ia_cipf_stage_backend
 */
typedef css_err_t (*stage_op)(ia_cipf_stage_t*);
typedef css_err_t (*stage_set_property_op)(struct _cipf_stage*,
                                          ia_uid uid,
                                          const ia_cipf_property_t *);
typedef css_err_t (*stage_get_property_op)(struct _cipf_stage*,
                                          ia_uid uid,
                                          ia_cipf_property_t *);

/** Set stage operations
 *
 * With this function, the stage realization can set handlers for its
 * main operations execute(), wait() and destroy() plus for any custom
 * property operations.
 *
 * Note: for basic property handling, the stage can utilize common
 *       implementations in CIPF. This includes creation, adding, querying and
 *       assigning of stage- and buffer-associated properties. Property
 *       operations available via this function are meant for custom handling
 *       of property objects, e.g when property payload size need to change
 *       dynamically and interpretation needs custom implementation.
 *
 * \ingroup ia_cipf_stage_backend
 *
 * \param[in]      stage           ia_cipf_stage_t handle
 * \param[in]      load_op         function pointer for load() operation
 * \param[in]      execute_op      function pointer for execute() operation
 * \param[in]      wait_op         function pointer for wait() operation
 * \param[in]      destroy_op      function pointer for destroy() operation
 * \param[in]      get_property_op function pointer for get_property() operation
 * \param[in]      set_property_op function pointer for set_property() operation
 *
 * \return         css_err_none if successful
 */
css_err_t
ia_cipf_stage_set_operations(ia_cipf_stage_t *stage,
                             stage_op load_op,
                             stage_op execute_op,
                             stage_op wait_op,
                             stage_op destroy_op,
                             stage_get_property_op get_property_op,
                             stage_set_property_op set_property_op);

/** Add a private data section to stage
 *
 * Adds a private data section to the stage that can be used to store stage
 * specific information (e.g. a stage implementation defined struct) and be
 * later queried and used/modified when necessary. Memory allocation is handled
 * by the function call, and ownership of the memory is retained by the stage.
 *
 * \see ia_cipf_stage_get_private
 *
 * \ingroup ia_cipf_stage_backend
 *
 * \param[in]      stage           ia_cipf_stage_t handle
 * \param[in]      size            size of the private section in bytes
 *
 * \return         pointer to the private memory, NULL if failed
 */
void*
ia_cipf_stage_add_private(ia_cipf_stage_t *stage, uint32_t size);

/** Get a pointer to the private section in a stage
 *
 * Gets a pointer to the private section in a stage. Private must be first added
 * successfully before it can be queried. Ownership of the memory is retained by
 * the stage, the caller must not free it.
 *
 * \see ia_cipf_stage_add_private
 *
 * \ingroup ia_cipf_stage_backend
 *
 * \param[in]      stage           ia_cipf_stage_t handle
 *
 * \return         pointer to the private memory, NULL if failed
 */
void*
ia_cipf_stage_get_private(ia_cipf_stage_t *stage);

/** Check a stage needs to be skip or not
 *
 *
 * \return         Bool value, needs skip or not
 */
bool
ia_cipf_stage_needs_skip(ia_cipf_stage_t *stage);

/** Add a terminal to the stage
 *
 * Add a terminal of a given type to the stage. Stage implementation should not
 * use this function directly, but rather use terminal_base.
 *
 * \ingroup ia_cipf_stage_backend
 *
 * \param[in]      stage           ia_cipf_stage_t handle
 * \param[in]      type            type of the container
 *
 * \return         pointer to ia_cipf_terminal_t, NULL if failed
 */
ia_cipf_terminal_t*
ia_cipf_stage_add_terminal(ia_cipf_stage_t *stage,
                           ia_cipf_terminal_type_t type);

/** Remove a terminal from the stage
 *
 * Removes the given terminal from the stage.
 *
 * \ingroup ia_cipf_stage_backend
 *
 * \param[in]      stage           ia_cipf_stage_t handle
 * \param[in]      terminal        ia_cipf_terminal_t handle
 *
 * \return         css_err_none if successful
 */
css_err_t
ia_cipf_stage_remove_terminal(ia_cipf_stage_t *stage,
                              ia_cipf_terminal_t *terminal);

/** Base implementation for assigning a property to a stage
 *
 * Assign a property to a stage. This is the base implementation for property
 * assign, and can be used by stage implementations for general property assign,
 * i.e. setting properties that do not need special handling.
 *
 * \ingroup ia_cipf_stage_backend
 *
 * \param[in]      stage           ia_cipf_stage_t handle
 * \param[in]      uid             uid of the stage property to be assigned to
 * \param[in]      property        handle of the property being assigned
 *
 * \return         css_err_none if successful
 */
css_err_t
stage_base_assign_property(ia_cipf_stage_t *stage,
                           ia_uid uid,
                           const ia_cipf_property_t *property);

/** Base implementation for stage get property
 *
 * Get a copy of a property from a stage. The caller must provide a property
 * object that contains the uid of the requested property either by manually
 * setting it or by reusing an existing property object. This is the base
 * implementation for property get, and can be used by stage implementation for
 * general property getting.
 *
 * \ingroup ia_cipf_stage_backend
 *
 * \param[in]      stage           ia_cipf_stage_t handle
 * \param[in,out]  property        property object containing the property uid
 *
 * \return         css_err_none if successful
 */
css_err_t
stage_base_get_property(ia_cipf_stage_t *stage,
                        ia_cipf_property_t *property);

/** Base implementation for stage get property reference
 *
 * Get a reference to a property in a stage. The ownership of the property is
 * not transferred, and the caller must not free the property. This is the base
 * implementation for get property reference, and can be used by stage
 * implementation for convenient access to internal properties.
 *
 * \ingroup ia_cipf_stage_backend
 *
 * \param[in]      stage           ia_cipf_stage_t handle
 * \param[in]      uid             uid of the property to get
 *
 * \return         pointer to the requested property, NULL if failed
 */
ia_cipf_property_t *
stage_base_get_property_ref(ia_cipf_stage_t *stage,
                            ia_uid uid);

#endif /* _IA_CIPF_STAGE_BACKEND_H_ */
