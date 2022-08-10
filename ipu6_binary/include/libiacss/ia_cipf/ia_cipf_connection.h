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

#ifndef _IA_CIPF_CONNECTION_H_
#define _IA_CIPF_CONNECTION_H_

#include "ia_cipf_types.h"

/** \defgroup ia_cipf_connection Connection (ia_cipf_connection_t)
 * \ingroup ia_cipf
 * \brief the ia_cipf_connection_t object interface
 */

/**
 * \ingroup ia_cipf_connection
 */
ia_cipf_connection_t *
ia_cipf_connection_create(void);

/**
 * \ingroup ia_cipf_connection
 */
void
ia_cipf_connection_destroy(ia_cipf_connection_t *connection);

/**
 * \ingroup ia_cipf_connection
 */
ia_cipf_connection_t *
ia_cipf_connection_create_init(ia_cipf_terminal_t *source,
                               ia_cipf_terminal_t *sink,
                               int32_t          branch_id,
                               ia_cipf_connection_type_t type);
#endif /* _IA_CIPF_CONNECTION_H_ */
