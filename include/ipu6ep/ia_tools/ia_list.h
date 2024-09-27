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

#ifndef _IA_LIST_H_
#define _IA_LIST_H_

#include <stdbool.h>
#include <ia_tools/css_types.h>

/**
 * \ingroup ia_tools
 */
typedef struct ia_list {
    void *data;
    struct ia_list *next;
} ia_list_t;

/**
 * Create a ia_list
 * \ingroup ia_tools
 * \return pointer to the list. NULL if failed.
 */
ia_list_t *
ia_list_create(void);

/**
 * Destroy a ia_list
 * \ingroup ia_tools
 * \param *list the list
 */
void
ia_list_destroy(ia_list_t *list);

/**
 * Add a new element to a list head. If *list is NULL, a new ia_list element is
 * allocated and inserted to *list.
 * \ingroup ia_tools
 * \param **list a pointer to the list pointer
 * \param *data the data for the list element
 * \return css_err_none on success
 * Add data to a ia_list
 */
css_err_t
ia_list_prepend(ia_list_t **list, void *data);

/**
 * Add a new element to a list tail. If *list is NULL, a new ia_list element is
 * allocated and inserted to *list.
 * \ingroup ia_tools
 * \param **list a pointer to the list pointer
 * \param *data the data for the list element
 * \return css_err_none on success
 * Add data to a ia_list
 */
css_err_t
ia_list_append(ia_list_t **list, void *data);

/**
 * Tell whether data is in the list
 * \ingroup ia_tools
 * \param *list handle to the list object
 * \param *data the data pointer
 * \return true if data is in the list, false otherwise
 */
bool
ia_list_contains(const ia_list_t *list, void *data);

/**
 * Remove data if it exists in the list.
 * \ingroup ia_tools
 * \param **list a pointer to the list pointer.
 * \param *data the data to remove from list.
 * \return true if data was removed. False otherwise.
 */
bool
ia_list_remove(ia_list_t **list, void *data);

/**
 * Tell the length of the list.
 * \ingroup ia_tools
 * \param *list a pointer to the list.
 * \return length of the list.
 */
uint32_t
ia_list_length(const ia_list_t *list);

/**
 * Return data at an index of the list.
 * \ingroup ia_tools
 * \param *list a pointer to the list.
 * \param index element index
 * \return pointer to the data at the element at the distance "index" from the
 * given list element
 */
void*
ia_list_data_at(const ia_list_t *list, uint32_t index);

#endif /* _IA_LIST_H_ */
