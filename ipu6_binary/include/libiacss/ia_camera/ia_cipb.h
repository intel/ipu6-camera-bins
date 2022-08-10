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

#ifndef IA_CIPB
#define IA_CIPB

#include <ia_cipf/ia_cipf_types.h>
#include <ia_cipr/ia_cipr.h>

/**
 * \ingroup ia_camera
 */
typedef struct ia_cipb_context_t* ia_cipb_t;
typedef void* ia_cipb_graph_t;
typedef css_err_t (*populate_cb)(ia_cipf_registry_t*);

/**
 * \addtogroup ia_camera
 * <b>
 * General expected operation sequence:
 *
 * PIPELINE CREATION AND SETUP
 * </b>
 *
 * 1. Client creates the pipeline builder via ia_cipb_create()
 *
 * 2. Client fetches a native graph via
 *    ia_cipb_get_native_graph(ia_cipb ipb, char const *name)
 *    from the pipeline builder. Alternatively, client can enumerate through
 *    the native graphs via
 *    ia_cipb_enumerate_native_graphs(ia_cipb ipb, uint32_t index). The
 *    latter can be useful if there are multiple pipelines for the same purpose
 *    with different capabilities, and the client could then choose between them
 *    based on the capabilities (TODO: document & create the necessary
 *    capability APIs).
 *
 *    The native graph is a vendor provided pipeline for any pre-described
 *    purpose. The purpose can be freely mapped to use cases, more detailed
 *    features or performance restrictions e.g. preview, capture, video.
 *
 *    The target is that native graphs (or directed acyclic graphs aka DAGs) are
 *    defined in a high level description language like XML which uses a pool
 *    of available stage realizations and their capabilities. For ISP this pool
 *    is to be provided by ISP library aware of binaries and the program groups
 *    within them.
 *
 * 3. Client creates a pipeline via
 *    ia_cipb_create_pipeline(ia_cipb ipb, ia_cipb_graph graph)
 *    from the pipeline builder.
 *
 * 4. Client destroys the pipeline builder if it is not needed anymore via
 *    ia_cipb_destroy(ia_cipb ipb).
 *
 * 5. Client loads the pipeline via
 *    ia_cipf_pipe_load(ia_cipf_pipe *pipe) Load is the first
 *    call that reaches each pipeline stage realization. The stages load all the
 *    resources (backend) they need to commit their execution.
 *
 * 6. Client configures the pipeline terminals (inputs, outputs) by first
 *    fetching the terminals via either
 *    ia_cipf_pipe_get_output_terminal(ia_cipf_pipe *pipe, uint32_t index)
 *    or ia_cipf_pipe_get_input_terminal(ia_cipf_pipe *pipe, uint32_t index),
 *    and then by setting the format of the terminal via
 *    ia_cipf_terminal_set_format(ia_cipf_terminal *terminal, ia_frame_format *ff);
 *    The index param can be used
 *    to enumerate through the terminals in case there are several, and then the
 *    returned terminal structure can be used to identify the terminal.
 *    TODO: fix the enumerating part, the index is not really used yet
 *
 * 7. Client identifies properties via
 *    ia_cipf_pipe_next_unidentified_property(ia_cipf_pipe *pipe)
 *    and sets the size of the
 *    property after which it must call
 *    ia_cipf_pipe_set_property(ia_cipf_pipe *pipe, ia_cipf_property *property).
 *    This is done in a loop until there are no unidentified properties anymore.
 *
 *    During looping the properties, after each property is set the client needs
 *    to destroy each returned unidentified property struct via
 *    ia_cipf_property_destroy(ia_cipf_property *property).
 *
 *    The properties itself are just chunks of data for the pipeline framework
 *    and the client needs to identify and fill the data itself.
 *    TODO: explain the allocation of the data chunk memory (who, when)
 *    TODO: give a practical example where the client uses the property data
 *          chunk to do something
 *
 * 8. Client registers buffers by going through the buffer requirements by
 *    looping via ia_cipf_pipe_next_buffer_requirement(pipe). For each returned
 *    buffer the client needs to identify the type (frame/data).
 *
 *    For frame type buffers, the client can identify the associated terminal
 *    via ia_cipf_buffer_get_terminal(buffer) and then set the buffer size and
 *    data pointer according to the buffer format information etc.
 *
 *    For data type buffers, the client gets directly the size and it can
 *    set the data pointer to point to a sufficient size memory chunk.
 *
 *    For both buffer types the client then needs to do the actual registering
 *    via ia_cipf_pipe_buffer_register(pipe, buffer).
 *
 * 9. Client fetches a pipeline iterator via ia_cipf_iterator_create(pipe)
 *    function.
 *
 * <b>RUNNING THE PIPELINE</b>
 *
 * 10. Client sets the input buffer(s) to the iterator via
 *     ia_cipf_iteration_set_buffer(iterator, inputBuffer)
 *
 * 11. Client sets the output buffer(s) to the iterator via
 *     ia_cipf_iteration_set_buffer(iterator, outputBuffer)
 *
 * 12. Client runs the pipeline by calling
 *     ia_cipf_iteration_execute(iterator)
 *
 * 13. Client waits for pipeline results by calling
 *     ia_cipf_iteration_wait(mPipeIterator)
 *     The pipeline may produce multiple outputs after a single
 *     ia_cipf_iteration_wait depending on pipeline.
 *
 * 14. Client gets the result output buffer(s) via
 *     ia_cipf_iteration_get_buffer(iterator, outputBuffer)
 *
 * 15. (optional) Client calls ia_cipf_iteration_next(iterator). Currently this
 *     is a NOP, with the purpose of switching to the next iterator in the
 *     future. TODO: fix this
 *
 * <b>PIPELINE DESTRUCTION</b>
 *
 * 16. Client destroys the iterator via ia_cipf_iterator_destroy(iterator)
 *
 * 17. Client unregisters buffers via
 *     ia_cipf_pipe_unregister_buffer(pipe, buffer)
 *
 * 18. (optional) client frees buffers it has allocated, if it doesn't need them
 *      anymore
 *
 * 19. Client destroys the pipeline via ia_cipf_pipe_destroy(pipe)
 *
 * 20. Client frees the buffer structures previously returned during buffer
 *     querying (registering).
 *
 */

/**
 * Create pipeline builder
 * \return pipeline builder
 * \ingroup ia_camera
 */
ia_cipb_t ia_cipb_create(void);

 /**
  * Destroy pipeline builder
  * \param ipb the pipeline builder
  * \ingroup ia_camera
  */
css_err_t ia_cipb_destroy(ia_cipb_t ipb);

/**
 * Enumerate through available native graphs
 * \param ipb the pipeline builder
 * \param index the native graph index
 * \ingroup ia_camera
 */
ia_cipb_graph_t ia_cipb_enumerate_native_graphs(ia_cipb_t ipb, uint32_t index);

/**
 * Get graph id by name (or UUID)
 * \param ipb the pipeline builder
 * \param name the native graph name
 * \ingroup ia_camera
 */
ia_cipb_graph_t ia_cipb_get_native_graph(ia_cipb_t ipb, char const *name);

/**
 * Create pipeline
 *
 * Creates the pipeline with the subcontexts (stages and connections) for
 * the given graph and returns it as ia_ipf_pipe.
 *
 * \ingroup ia_camera
 *
 * \param ipb       pipeline builder handle
 * \param graph     native graph identifier of selected pipeline to create
 * \return          CIPF pipeline object handle
 */
ia_cipf_pipe_t* ia_cipb_create_pipeline(ia_cipb_t ipb,
                                        ia_cipb_graph_t graph);

/**
 * Create pipeline with runtime context
 *
 * Creates the pipeline with the subcontexts (stages and connections) for
 * the given graph and returns it as ia_ipf_pipe.
 *
 * \ingroup ia_camera
 *
 * \param ipb       pipeline builder handle
 * \param graph     native graph identifier of selected pipeline to create
 * \param cipr_ctx  runtime context implementation
 * \return          CIPF pipeline object handle
 */
ia_cipf_pipe_t* ia_cipb_create_pipeline_with_context(ia_cipb_t ipb,
                                                     ia_cipb_graph_t graph,
                                                     ia_cipr_context_t cipr_ctx);

/**
 * Create stage
 *
 * Creates a ia_cipf_stage_t object populated to CIPB registry with
 * unique identifier.
 *
 * \ingroup ia_camera
 *
 * \param ipb   pipeline builder handle
 * \param pipe  pipeline handle
 * \param uid   identifier of stage to create
 *
 * \return      CIPF stage object handle
 */
ia_cipf_stage_t* ia_cipb_create_stage(ia_cipb_t ipb,
                                      ia_cipf_pipe_t *pipe,
                                      ia_uid uid);

/**
 * Register CIPF library
 *
 * Via this method user of ia_cipb_t interface is able to populate its
 * own libraries of stage realizations into CIPB registry.
 *
 * \ingroup ia_camera
 *
 * \param ipb           pipeline builder handle
 * \param populate      callback function to populate ia_cipf_registry_t
 */
css_err_t ia_cipb_register_cipf_library(ia_cipb_t ipb, populate_cb populate);

#endif /* _IA_CIPB_H */
