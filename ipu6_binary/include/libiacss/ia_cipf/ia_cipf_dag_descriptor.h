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

#ifndef _DAG_DESCRIPTOR_H_
#define _DAG_DESCRIPTOR_H_

/** \defgroup ia_cipf_dag_descriptor DAG Descriptor (ia_cipf_dag_descriptor_t)
 * \ingroup ia_cipf
 */

#define GRAPH_URN_MAX_LENGTH 64

#include <ia_cipf/ia_cipf_types.h>
#include <ia_tools/ia_list.h>
#include <ia_tools/css_types.h>

/**
 * \ingroup ia_cipf_dag_descriptor
 */
typedef enum cipf_dag_item_type
{
    cipf_dag_item_type_na,
    cipf_dag_item_type_stage,
    cipf_dag_item_type_connection
} cipf_dag_item_type_t;

/**
 * \ingroup ia_cipf_dag_descriptor
 */
typedef enum cipf_dag_attribute_type
{
    cipf_dag_attribute_type_na,
    cipf_dag_attribute_type_property,
    /* connnection attributes */
    cipf_dag_attribute_type_connection      = (1 << 8),
    cipf_dag_attribute_type_source          = (1 << 9),
    cipf_dag_attribute_type_source_terminal = (1 << 10),
    cipf_dag_attribute_type_sink            = (1 << 11),
    cipf_dag_attribute_type_sink_terminal   = (1 << 12),
    cipf_dag_attribute_type_iteration       = (1 << 13)
} cipf_dag_attribute_type_t;

/**
 * \ingroup ia_cipf_dag_descriptor
 */
typedef struct cipf_dag_descriptor
{
    char        uri[GRAPH_URN_MAX_LENGTH];
    ia_uid      uid;
    ia_list_t   *item;
} ia_cipf_dag_descriptor_t;

/**
 * \ingroup ia_cipf_dag_descriptor
 */
typedef struct cipf_dag_attribute
{
    cipf_dag_attribute_type_t   type;
    ia_cipf_payload_t           payload;
} ia_cipf_dag_attribute_t;

/**
 * \ingroup ia_cipf_dag_descriptor
 */
typedef struct cipf_dag_item
{
    cipf_dag_item_type_t    type;
    ia_uid                  uid;
    ia_list_t               *attribute;
} ia_cipf_dag_item_t;

/** Descriptor **/

/** Create dag descriptor object
 *
 * \ingroup ia_cipf_dag_descriptor
 */
ia_cipf_dag_descriptor_t* ia_cipf_dag_descriptor_create(void);

/** Add item into dag descriptor
 *
 * \ingroup ia_cipf_dag_descriptor
 *
 * Passes the ownership of item object to the descriptor.
 */
css_err_t ia_cipf_dag_descriptor_add_item(ia_cipf_dag_descriptor_t *dag_desc,
                                         ia_cipf_dag_item_t *item);

/** Destroy dag descriptor object
 *
 *  \ingroup ia_cipf_dag_descriptor
 *
 * Destroys all the child items.
 */
void ia_cipf_dag_descriptor_destroy(ia_cipf_dag_descriptor_t *dag_desc);

/** Item **/

/** Create dag descriptor item
 *
 *  \ingroup ia_cipf_dag_descriptor
 */
ia_cipf_dag_item_t* ia_cipf_dag_item_create(void);

/** Add attribute into dag descriptor item
 *
 * \ingroup ia_cipf_dag_descriptor
 *
 * Passes the ownership of attribute object to the item.
 */
css_err_t ia_cipf_dag_item_add_attribute(ia_cipf_dag_item_t *item,
                                        ia_cipf_dag_attribute_t *attribute);

/** Destroy dag descriptor item
 *
 * \ingroup ia_cipf_dag_descriptor
 *
 * Destroys all the child attributes
 */
void ia_cipf_dag_item_destroy(ia_cipf_dag_item_t *item);

/** Attribute **/

/** Create dag descriptor item attribute
 *
 * \ingroup ia_cipf_dag_descriptor
 */
ia_cipf_dag_attribute_t* ia_cipf_dag_attribute_create(void);

/** Destroy dag descriptor item attribute
 *
 * \ingroup ia_cipf_dag_descriptor
 */
void ia_cipf_dag_attribute_destroy(ia_cipf_dag_attribute_t *attribute);


#endif
