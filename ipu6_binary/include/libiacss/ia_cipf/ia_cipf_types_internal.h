/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2013-2020 Intel Corporation. All Rights Reserved.
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

#ifndef _IA_CIPF_TYPES_INTERNAL_H_
#define _IA_CIPF_TYPES_INTERNAL_H_

#include "ia_cipf_types.h"

/**
 * \ingroup ia_cipf_internals
 */
struct ia_cipf_pipe {
    ia_list_t              *stages;
    ia_list_t              *connections;
    ia_list_t              *properties;
    log_context_t          *context;
};

/**
 * \ingroup ia_cipf_internals
 */
struct _cipf_stage {
    uint32_t            id;
    ia_uid              uid;
    ia_list_t           *input_terminals;    /* shortcut pointers to frame input terminals */
    ia_list_t           *output_terminals;   /* shortcut pointers to frame output terminals */
    ia_list_t           *terminals;          /* stage terminals */
    ia_list_t           *properties;         /* stage level properties */
    ia_list_t           *completion_ops;     /* stage completion operations */
    uint32_t            iteration;
    css_err_t            (*load)(struct _cipf_stage*);
    css_err_t            (*execute)(struct _cipf_stage*);
    css_err_t            (*wait)(struct _cipf_stage*);
    css_err_t            (*destroy)(struct _cipf_stage*);
    css_err_t            (*set_property)(struct _cipf_stage*,
                                        ia_uid uid,
                                        const ia_cipf_property_t *);
    css_err_t            (*get_property)(struct _cipf_stage*,
                                        ia_uid uid,
                                        ia_cipf_property_t *);
    log_context_t       *context;
    bool                 skip;
    uint64_t            execute_context;    /* windows driver sets execute context before execute the stage each time */
};

typedef css_err_t (*container_set_property_op)(struct _cipf_container*,
                                              ia_uid uid,
                                              const ia_cipf_property_t *);
typedef css_err_t (*container_get_property_op)(struct _cipf_container*,
                                              ia_uid uid,
                                              ia_cipf_property_t *);

typedef struct _cipf_buffer_ring ia_cipf_buffer_ring_t;

typedef enum _cipf_buffer_ring_mode {
    CIPF_BUFFER_RING_SYNC,
    CIPF_BUFFER_RING_ASYNC,         /* asynchronous consumer */
    CIPF_BUFFER_RING_ASYNC_BLOCK    /* async, block consumer */
} ia_cipf_buffer_ring_mode_t;

/**
 * \ingroup ia_cipf_internals
 */
struct _cipf_terminal {
    ia_cipf_terminal_type_t  type;
    ia_uid                   uid;
    uint32_t                 id;
    bool                     enabled;
    ia_cipf_buffer_t         *buffer;
    ia_cipf_buffer_ring_t    *ring;
    ia_cipf_stage_t          *stage;
    ia_cipf_container_t      *property_container;
    void                     (*destroy)(struct _cipf_terminal*);
    log_context_t            *context;
};

/**
 * \ingroup ia_cipf_internals
 */
struct _cipf_container {
    ia_uid                   uid;
    uint32_t                 id;
    ia_list_t                *properties;
    void                     *owner;
    container_set_property_op set_property;
    container_get_property_op get_property;
    void                    (*destroy)(struct _cipf_container*);
    log_context_t            *context;
};

/**
 * \ingroup ia_cipf_internals
 */
struct _cipf_connection {
    ia_cipf_connection_type_t type;
    ia_cipf_terminal_t        *source_terminal;
    ia_cipf_terminal_t        *sink_terminal;
    int32_t                   branch_id; /* negative when no parallel branches */
};

/**
 * \ingroup ia_cipf_internals
 *
 * Note: the intention with property association is to provide common
 *       mechanisms for describing cross-dependencies between stage
 *       properties and a way to implement handlers that stay
 *       agnostic of property purpose and datatype. For example when
 *       property data is part of terminal data payload or when certain
 *       properties are needed as precondition to others.
 */
typedef enum property_association_type {
    property_association_na = 0,
    property_association_pipeline_ref, /* pipeline level property */
    property_association_stage_ref,    /* stage level property */
    property_association_terminal_ref, /* terminal level property */
    property_association_buffer_ref,   /* reference to client buffer or part of
                                          it. Also stored in terminal object */
    property_association_locator       /* association given with uids */
} property_association_type_t;

/**
 * \ingroup ia_cipf_internals
 */
typedef struct property_association {
    union {
        ia_cipf_association_t locator;
        void* ptr;
    } value;
    property_association_type_t type;
} property_association_t;

/** \brief Internal property datatype for ia_cipf_property_t
 *
 * \ingroup ia_cipf_internals
 */
struct _cipf_property {
    uint32_t               id;      /**< index of property */
    uint32_t               uid;     /**< identifier of property */
    bool                   copy;    /**< property is copy of original */
    bool                   reference; /**< property payload is reference to
                                       *   external data */
    ia_cipf_payload_t      payload;   /**< payload data of the property */
    property_association_t association; /**< property association info */
    void                   (*destroy)(struct _cipf_property*);
                                    /**< destroy operation called via
                                     *   ia_cipf_property_destroy() before
                                     *   freeing anything */
};

/**
 * \ingroup ia_cipf_internals
 */
typedef struct _ia_cipf_iteration_parcel {
    ia_cipf_pipe_t         *pipe;
    ia_cipf_stage_t        *stage;
    ia_cipf_terminal_t    *terminal;
} ia_cipf_iteration_parcel_t;

/** ia_cipf_iterator_t internal datatype
 *
 * \ingroup ia_cipf_internals
 */
struct ia_cipf_iterator {
    uint32_t                index;
    ia_list_t               *parcels; /**< list of accessors available via iterator */
    ia_cipf_pipe_t          *pipe; /**< accessor to pipe */
    struct ia_cipf_iterator *head; /**< head iterator object */
    struct ia_cipf_iterator *next; /**< next iterator object */
    ia_cipf_stage_t         *executed_stage; /**< last executed stage */
};

#endif
