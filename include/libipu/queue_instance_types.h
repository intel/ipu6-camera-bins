/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2017 - 2017 Intel Corporation.
 * All Rights Reserved.
 *
 * The source code contained or described herein and all documents
 * related to the source code ("Material") are owned by Intel Corporation
 * or licensors. Title to the Material remains with Intel
 * Corporation or its licensors. The Material contains trade
 * secrets and proprietary and confidential information of Intel or its
 * licensors. The Material is protected by worldwide copyright
 * and trade secret laws and treaty provisions. No part of the Material may
 * be used, copied, reproduced, modified, published, uploaded, posted,
 * transmitted, distributed, or disclosed in any way without Intel's prior
 * express written permission.
 *
 * No License under any patent, copyright, trade secret or other intellectual
 * property right is granted to or conferred upon you by disclosure or
 * delivery of the Materials, either expressly, by implication, inducement,
 * estoppel or otherwise. Any license under such intellectual property rights
 * must be express and approved by Intel in writing.
 */

#ifndef __QUEUE_INSTANCE_TYPES_H
#define __QUEUE_INSTANCE_TYPES_H

#include "type_support.h"
#include "bufqueue.shared.h"

typedef enum {
	int_queue
} queue_rsc_type_t;

typedef enum {
	queue_local,
} queue_rsc_id_t;

typedef __register struct {
	queue_rsc_type_t type;
	queue_rsc_id_t   id;
	unsigned         value;
} queue_rsc_t;

#define MAX_BUF_PER_QUEUE_ELEM 5

#endif /* __QUEUE_INSTANCE_TYPES_H */
