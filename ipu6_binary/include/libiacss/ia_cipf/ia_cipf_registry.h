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

#ifndef _IA_CIPF_REGISTRY_H_
#define _IA_CIPF_REGISTRY_H_

#include <ia_cipf/ia_cipf_types.h>
#include <ia_tools/css_types.h>

/** \defgroup ia_cipf_registry Registry (ia_cipf_registry_t)
 * \ingroup ia_cipf
 * \brief Registry for unique Stage constructors
 */

typedef ia_cipf_stage_t* (*stage_create_op)(ia_cipf_pipe_t *pipe,
                                            ia_uid uid,
                                            const ia_cipf_property_t *arg);

/** Create CIPF registry
 *
 * \ingroup ia_cipf_registry
 */
ia_cipf_registry_t* ia_cipf_registry_create(void);

/** Destroy CIPF registry
 *
 * \ingroup ia_cipf_registry
 */
void ia_cipf_registry_destroy(ia_cipf_registry_t *registry);

/** Publish stage via CIPF registry.
 *
 * As an argument, ia_cipf_property_t can be passed to the registry, which will
 * be then passed to the create op once the stage is created. Ownership of this
 * property will be transferred to the registry, and must not be destroyed by
 * the caller once the stage is properly published. Stage create ops using this
 * argument may only use it during the create. If property is needed later, it
 * needs to be copied.
 *
 * \ingroup ia_cipf_registry
 *
 * \param[in]   registry       handle to ia_cipf_registry
 * \param[in]   stage_uid      unique identifier for the stage
 * \param[in]   create_op      standard function pointer to create the stage
 * \param[in]   create_op_arg  optional argument to the stage create operation
 */
css_err_t ia_cipf_registry_publish_stage(ia_cipf_registry_t *registry,
                                        ia_uid stage_uid,
                                        stage_create_op create_op,
                                        ia_cipf_property_t *create_op_arg);

/** Publish unique terminal identifier via CIPF registry
 *
 * \ingroup ia_cipf_registry
 *
 * \param[in]   registry        handle to ia_cipf_registry
 * \param[in]   stage_uid       unique identifier for the stage
 * \param[in]   terminal_uid    unique identifier for the terminal
 */
css_err_t ia_cipf_registry_publish_terminal(ia_cipf_registry_t *registry,
                                           ia_uid stage_uid,
                                           ia_uid terminal_uid);

/** Create stage via CIPF registry
 *
 * \ingroup ia_cipf_registry
 *
 * \param[in]   registry    handle to ia_cipf_registry
 * \param[in]   pipe        handle to ia_cipf_pipe where stage is going to be
 *                          added.
 * \param[in]   stage_uid   unique identifier for the stage
 */
ia_cipf_stage_t*
ia_cipf_registry_create_stage(ia_cipf_registry_t *registry,
                              ia_cipf_pipe_t *pipe,
                              ia_uid stage_uid);

#endif
