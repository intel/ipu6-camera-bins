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

#ifndef _IA_CIPF_CONTAINER_H_
#define _IA_CIPF_CONTAINER_H_

#include "ia_cipf_types_internal.h"

/** \defgroup ia_cipf_container Container (ia_cipf_container_t)
 * \ingroup ia_cipf
 * \brief the ia_cipf_container_t object inteface
 */

/**
 * \ingroup ia_cipf_container
 */
ia_cipf_container_t*
ia_cipf_container_create(void *owner);

/**
 * \ingroup ia_cipf_container
 */
void
ia_cipf_container_destroy(ia_cipf_container_t *container);

/**
 * \ingroup ia_cipf_container
 */
void*
ia_cipf_container_add_private(ia_cipf_container_t *container, uint32_t size);

/**
 * \ingroup ia_cipf_container
 */
void*
ia_cipf_container_get_private(ia_cipf_container_t *container);

/** Add property into container
 *
 * \ingroup ia_cipf_container
 *
 * Adds ia_cipf_property_t object reference into container object. Once the
 * function returns, the ownership of property object is passed to container
 * and given property will be destroyed with the container.
 *
 * Added property is exposed and accessible via container interface property
 * functions using enumeration or the given uid.
 *
 * \param[in]   container   handle to container object
 * \param[in]   uid         identifier of property
 * \param[in]   property    property to add
 *
 * \return      css_err_none if successful
 */
css_err_t
ia_cipf_container_add_property(ia_cipf_container_t *container,
                               ia_uid uid,
                               ia_cipf_property_t *property,
                               property_association_type_t patype);

/** Remove property from container
 *
 * \ingroup ia_cipf_container
 *
 * Removes and destroys ia_cipf_property_t object from container object.
 *
 * \param[in]   container   handle to container object
 * \param[in]   property    property to be removed
 *
 * \return      css_err_none if successful
 */
css_err_t
ia_cipf_container_remove_property(ia_cipf_container_t *container,
                                  ia_cipf_property_t *property);

/** Get reference to the container property by index
 *
 * \ingroup ia_cipf_container
 *
 * \param[in]   container   handle to container object
 * \param[in]   index       index of the property
 *
 * \return      requested property reference
 */
ia_cipf_property_t*
ia_cipf_container_get_property_ref_by_index(ia_cipf_container_t *container, uint32_t index);

/** Get reference to the container property by uid
 *
 * \ingroup ia_cipf_container
 *
 * \param[in]   container   handle to container object
 * \param[in]   uid         UID of the property
 *
 * \return      requested property reference
 */
ia_cipf_property_t*
ia_cipf_container_get_property_ref(ia_cipf_container_t *container, ia_uid uid);

/** Get copy of container property
 *
 * Gets a copy of a property found with the association information present
 * in the given property object. Property without the association info is
 * considered an error. Supports only getting container properties. The
 * received property can be used in the set functions.
 *
 * \ingroup ia_cipf_container
 *
 * \param[in]       container   handle to the container
 * \param[in,out]   prop        property object where copy will be stored
 *
 * \return          css_err_none if successful
 */
css_err_t
ia_cipf_container_get_property(ia_cipf_container_t *container,
                               ia_cipf_property_t *prop);

/** Get copy of container property by uid
 *
 * Gets a copy of a container property found by the given uid. The contents and
 * the association information of the property found are copied into a property
 * object given by the user. The received property can be used in the set
 * functions.
 *
 * \ingroup ia_cipf_container
 *
 * \param[in]       container   handle to the container
 * \param[in]       uid         UID of property to get
 * \param[in,out]   prop        property object where copy will be stored
 *
 * \return          css_err_none if successful
 */
css_err_t
ia_cipf_container_get_property_by_uid(ia_cipf_container_t *container,
                                      ia_uid uid,
                                      ia_cipf_property_t *prop);

/** Set container property
 *
 * Sets the property found by the association information present in the
 * property given by the user. Given property is assigned to the property
 * already existing. Ownership of the property is not transferred, the user must
 * destroy it after the function returns.
 *
 * \param[in]   container   handle to the container
 * \param[in]   prop        property to assign
 *
 * \return      css_err_none if successful
 *
 * \ingroup ia_cipf_container
 */
css_err_t
ia_cipf_container_set_property(ia_cipf_container_t *container,
                               const ia_cipf_property_t *prop);

/** Set property of container by uid
 *
 * Sets the pipe property with the given uid. Any association information
 * present in the property given by the user is ignored. Given property is
 * assigned to the property already existing. Ownership of the property is not
 * transferred, the user must destroy it after the function returns.
 *
 * \ingroup ia_cipf_container
 *
 * \param[in]  container   handle to the container
 * \param[in]  uid         UID of property to set
 * \param[in]  prop        property to assign
 *
 * \return     css_err_none if successful
 */
css_err_t
ia_cipf_container_set_property_by_uid(ia_cipf_container_t *container,
                                      ia_uid uid,
                                      const ia_cipf_property_t *prop);

/**
 * \ingroup ia_cipf_container
 */
uint32_t
ia_cipf_container_get_num_properties(ia_cipf_container_t *container);

#endif /* _IA_CIPF_CONTAINER_H_ */
