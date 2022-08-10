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

#ifndef _IA_CIPF_PROPERTY_H_
#define _IA_CIPF_PROPERTY_H_

#include "ia_cipf_types.h"

/** \defgroup ia_cipf_property Property (ia_cipf_property_t)
 * \ingroup ia_cipf
 * \brief the ia_cipf property_t object interface
 */


/** Create property object
 *
 * \ingroup ia_cipf_property
 */
ia_cipf_property_t*
ia_cipf_property_create(void);

/** Create property with one of natively supported type
 *
 * \ingroup ia_cipf_property
 */
ia_cipf_property_t*
ia_cipf_property_create_with_native_payload(ia_uid uid);

/** Copy property
 *
 * Copies the contents of a property into another object created by the user.
 *
 * Note: does not auto-replicate the property association. To do this
 *       user needs to call _replicate_association() for the copy
 *       object.
 *
 * \ingroup ia_cipf_property
 *
 * \param[in,out]  dst  destination property
 * \param[in]      ref  source property
 *
 * \return         css_err_none if successful
 */
css_err_t
ia_cipf_property_copy(ia_cipf_property_t *dst, const ia_cipf_property_t *ref);

/** Replicate property association from given reference
 *
 * By calling this function the property object gets associated
 * to the same CIPF pipeline location & purpose than the reference
 * property. Only property with association is meaningful for the
 * pipeline, stage, terminal and buffer APIs.
 *
 * \ingroup ia_cipf_property
 */
css_err_t
ia_cipf_property_replicate_association(ia_cipf_property_t *property,
                                       const ia_cipf_property_t *ref);

/** Get stage the property is associated to
 *
 * \ingroup ia_cipf_property
 */
ia_cipf_stage_t*
ia_cipf_property_get_stage(const ia_cipf_property_t *property);

/**
 * \ingroup ia_cipf_property
 */
css_err_t
ia_cipf_property_assign(ia_cipf_property_t *dst, const ia_cipf_property_t *src);

/**
 * \ingroup ia_cipf_property
 */
void
ia_cipf_property_destroy(ia_cipf_property_t *property);

/**
 * \ingroup ia_cipf_property
 */
css_err_t
ia_cipf_property_set_uid(ia_cipf_property_t *property, ia_uid uid);

/**
 * \ingroup ia_cipf_property
 */
ia_uid
ia_cipf_property_get_uid(const ia_cipf_property_t *property);

/**
 * \ingroup ia_cipf_property
 */
ia_uid
ia_cipf_property_get_payload_uid(const ia_cipf_property_t *property);

/**
 * \ingroup ia_cipf_property
 */
css_err_t
ia_cipf_property_set_payload_size(ia_cipf_property_t *property, uint32_t size);

/**
 * \ingroup ia_cipf_property
 */
uint32_t
ia_cipf_property_get_payload_size(const ia_cipf_property_t *property);

/**
 * \ingroup ia_cipf_property
 */
css_err_t
ia_cipf_property_set_uint32_value(ia_cipf_property_t *property, uint32_t value);

/**
 * \ingroup ia_cipf_property
 */
css_err_t
ia_cipf_property_get_uint32_value(const ia_cipf_property_t *property, uint32_t *value);

/**
 * \ingroup ia_cipf_property
 */
css_err_t
ia_cipf_property_set_int32_value(ia_cipf_property_t *property, int32_t value);

/**
 * \ingroup ia_cipf_property
 */
css_err_t
ia_cipf_property_get_int32_value(const ia_cipf_property_t *property, int32_t *value);

/**
 * \ingroup ia_cipf_property
 */
css_err_t
ia_cipf_property_set_uint64_value(ia_cipf_property_t *property, uint64_t value);

/**
 * \ingroup ia_cipf_property
 */
css_err_t
ia_cipf_property_get_uint64_value(const ia_cipf_property_t *property, uint64_t *value);

/**
 * \ingroup ia_cipf_property
 */
css_err_t
ia_cipf_property_set_boolean_value(ia_cipf_property_t *property, bool value);

/**
 * \ingroup ia_cipf_property
 */
css_err_t
ia_cipf_property_get_boolean_value(const ia_cipf_property_t *property, bool *value);

/**
 * \ingroup ia_cipf_property
 */
css_err_t
ia_cipf_property_get_value_reference(ia_cipf_property_t *property, void **value);

/**
 * \ingroup ia_cipf_property
 */
css_err_t
ia_cipf_property_read_payload(const ia_cipf_property_t *property,
                              void *data,
                              uint32_t data_size);

/**
 * \ingroup ia_cipf_property
 */
css_err_t
ia_cipf_property_write_payload(ia_cipf_property_t *property,
                               const void *data,
                               uint32_t data_size);

/** Internals
 *
 * TODO: separate interface headers
 */
typedef void (*cipf_property_destroy_op)(ia_cipf_property_t *);

/**
 * \ingroup ia_cipf_property
 */
css_err_t
ia_cipf_property_set_operations(ia_cipf_property_t *property,
                                cipf_property_destroy_op destroy_operation);

/**
 * \ingroup ia_cipf_property
 */
css_err_t
ia_cipf_property_set_value_reference(ia_cipf_property_t *property, void *value);

/**
 * \ingroup ia_cipf_property
 */
css_err_t
ia_cipf_property_set_string_reference(ia_cipf_property_t *property,
                                      const char * const string);

/**
 * \ingroup ia_cipf_property
 */
css_err_t
ia_cipf_property_get_string(const ia_cipf_property_t *property,
                            char *string,
                            const uint32_t size);

/**
 * \ingroup ia_cipf_property
 */
css_err_t
ia_cipf_property_get_string_reference(const ia_cipf_property_t *property,
                                      const char ** const string);

/**
 * \ingroup ia_cipf_property
 */
css_err_t
ia_cipf_property_set_payload_uid(ia_cipf_property_t *property, ia_uid uid);

/**
 * \ingroup ia_cipf_property
 */
css_err_t
ia_cipf_property_allocate_payload(ia_cipf_property_t *property, uint32_t size);

/**
 * \ingroup ia_cipf_property
 */
css_err_t
ia_cipf_property_set_offset_value(ia_cipf_property_t *property, uint32_t offset);

/**
 * \ingroup ia_cipf_property
 */
css_err_t
ia_cipf_property_get_offset_value(const ia_cipf_property_t *property, uint32_t *offset);

/**
 * \ingroup ia_cipf_property
 */
css_err_t
ia_cipf_property_set_resolution_value(ia_cipf_property_t *property,
                                      ia_cipf_resolution_t resolution);

/**
 * \ingroup ia_cipf_property
 */
css_err_t
ia_cipf_property_get_resolution_value(const ia_cipf_property_t *property,
                                      ia_cipf_resolution_t *resolution);

/**
 * \ingroup ia_cipf_property
 */
bool
ia_cipf_property_is_native_type(const ia_cipf_property_t *property);

/**
 * \ingroup ia_cipf_property
 */
css_err_t
ia_cipf_property_get_association(const ia_cipf_property_t *property,
                                 ia_cipf_association_t *association);

/**
 * \ingroup ia_cipf_property
 */
css_err_t
ia_cipf_property_set_association(ia_cipf_property_t *property,
                                 const ia_cipf_association_t *association);

#endif /* _IA_CIPF_PROPERTY_H_ */
