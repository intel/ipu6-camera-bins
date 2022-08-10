/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2013-2014 Intel Corporation. All Rights Reserved.
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

#ifndef _STATIC_DAGS_HELPER_H_
#define _STATIC_DAGS_HELPER_H_

/**
 * This file defines helper utils to fill ia_cipf_dag_descriptor's out
 * from static definitions.
 *
 * The intention is that DAGs are eventually read from external
 * per-platform storage (markup language).
 */

#include <stdlib.h>

#include <ia_cipf/ia_cipf_dag_descriptor.h>

struct _static_dag_item {
    cipf_dag_item_type_t    type;
    ia_uid                  uid;
    ia_cipf_dag_attribute_t *attribute;
};

struct _static_dag_descriptor {
    const char              *uri;
    ia_uid                   uid;
    struct _static_dag_item  *items;
};

ia_cipf_dag_descriptor_t*
load_static_dag_descriptor(struct _static_dag_descriptor *static_desc);

extern struct _static_dag_descriptor* _static_dag_descriptor[];

#endif
