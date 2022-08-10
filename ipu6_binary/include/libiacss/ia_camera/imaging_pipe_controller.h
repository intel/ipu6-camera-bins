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

/** \file imaging_pipe_controller.h
 *
 * \defgroup imaging_pipe_ctrl Pipe controller for graphs with IPU
 * \ingroup ia_camera
 * imaging stages
 * \brief Tentative API to unify data-flows between camera control algorithms
 * stack coverned by HAL and CIPF pipelines with IPU stages.
 * TODO: make controller the owner of P2P and pass PAL binary data over the
 *       interface.
 */
#ifndef __IMAGING_PIPE_CONTROLLER_H__
#define __IMAGING_PIPE_CONTROLLER_H__

#include <ia_types.h>
#include <ia_cipf/ia_cipf_pipe.h>
#include "ia_cipr/ia_cipr_dump.h"

typedef struct imaging_pipe_ctrl_s imaging_pipe_ctrl_t;

/** \enum Stage identification status
 * \ingroup imaging_pipe_ctrl
 */
typedef enum _imaging_stage_status
{
    IMAGING_STAGE_UNKNOWN, /*!< Stage not recognized by the controller */
    IMAGING_STAGE_NEW_IPU, /*!< Stage identified as new IPU stage that needs
                            *   preparing */
    IMAGING_STAGE_IPU /*!< Stage ready to be use used */
} imaging_stage_status_t;

/** \enum Available TNR dataflow management routines
 *
 * \ingroup imaging_pipe_ctrl
 */
enum imaging_tnr_dfm_routine
{
    IMAGING_TNR_DATAFLOW_SWAP, /*!< swap IO-buffers for iteration (default) */
    IMAGING_TNR_DATAFLOW_IR,   /*!< buffers for both, normal and IR frames
                                *   \note requires minimum 2 buffers for each,
                                *         input and output terminals. And minimum
                                *         3 for terminals with delay logic.
                                */
    IMAGING_TNR_DATAFLOW_OFF   /*!< disable TNR control
                                *   \note This is for backward compliance meant
                                *         for adaptations that implement TNR
                                *         dataflow in OS specific scope.
                                */
};

/** \enum Available cyclic feedback dataflow management routines
 * \ingroup imaging_pipe_ctrl
 */
enum cyclic_feedback_dfm_routine
{
    CYCLIC_FEEDBACK_DATAFLOW_OFF,   /*!< disable control (default) */
    CYCLIC_FEEDBACK_DATAFLOW_SWAP   /*!< swap IO-buffers for iteration */
};

/** Imaging pipe controller attributes
 *
 * Extension to ipu parameters available for controlling optional
 * realizations of stage execution. This datatype can be optionally
 * added as reference associated to IPU parameters buffer given to
 * prepare stage.
 *
 * \ingroup imaging_pipe_ctrl
 * \see imaging_pipe_ctrl_prepare_stage_v2
 */
typedef struct imaging_ctrl_attributes_s
{
    enum imaging_tnr_dfm_routine tnr_dfm_routine; /*!< TNR dataflow routine */
    bool tnr_user_alloc; /*!< Let user to allocate TNR reference frame buffers
                          *   _prepare_stage() - defaut FALSE
                          *   _prepare_stage_v2() - default TRUE */
    enum cyclic_feedback_dfm_routine cyclic_feedback_routine; /*!< cyclic feedback dataflow routine */
    uint32_t cyclic_feedback_delay; /*!< cyclic feedback delay */

} imaging_ctrl_attributes_t;

/** Controller specific payload datatypes */

/** PAL data reference
 * \ingroup imaging_pipe_ctrl */
#define imaging_ctrl_payload_pal ia_fourcc('I','C','P','P') /*!< DEPRECATED (extra indirection) */
#define imaging_ctrl_payload_pal_data ia_fourcc('I','P','A','L')


/** DVS Statistics cache reference identifier
 * Note: WA to allow client to transfer P2P cache where e.g. dvs statistics
 *       kernel feature vectors are stored over cloned instances of pipelines
 *       and imaging controllers.
 * \todo refactor adaptation to use cloned memory requirements of graph
 *       cycles instead of cloned instances of graph
 * \ingroup imaging_pipe_ctrl
 */
#define imaging_ctrl_payload_feedback_cache ia_fourcc('I','C','P','D')

/** Imaging pipe controller attributes reference identifier
 * \ingroup imaging_pipe_ctrl
 */
#define imaging_ctrl_payload_attributes ia_fourcc('I','C','P','A')

/** Initialize controller
 *
 * \ingroup imaging_pipe_ctrl
 */
imaging_pipe_ctrl_t* imaging_pipe_ctrl_init(ia_cipf_pipe_t *pipe);

/** Destroy controller
 *
 * \ingroup imaging_pipe_ctrl
 * \param ctrl handle
 */
void imaging_pipe_ctrl_destroy(imaging_pipe_ctrl_t *ctrl);

/** Identify CIPF stage
 *
 * Identify stage from pipeline
 *
 * Validates that the stage is among the ones supported by the controller.
 * Reference to newly introduced stage is added to controller. Returns status
 * for the stage that can be used for choosing the correct control path.
 *
 * \ingroup imaging_pipe_ctrl
 *
 * \param[in] ctrl controller handle
 * \param[in] stage_uid stage UID of stage to identify
 * \param[out] status of the identified stage
 */
css_err_t
imaging_pipe_ctrl_identify_stage(imaging_pipe_ctrl_t *ctrl,
                                 ia_uid stage_uid,
                                 imaging_stage_status_t *status);

/** Identify CIPF property
 *
 * Identifies properties of imaging stages in the pipeline and configures
 * the controller accordingly.
 *
 * \ingroup imaging_pipe_ctrl
 *
 * \param[in] ctrl controller handle
 * \param[in] property object to be indentified
 */
css_err_t
imaging_pipe_ctrl_identify_property(imaging_pipe_ctrl_t *ctrl,
                                    ia_cipf_property_t *property);

/** Prepare stage
 *
 * Prepare controller to the state ready to exchange data with the stage.
 *
 * \ingroup imaging_pipe_ctrl
 *
 * \param[in] ctrl controller handle
 * \param[in] stage_uid uid of the stage to be configured
 * \param[in] ipu_parameters IPU parameters to prepare the stage with
 */
css_err_t
imaging_pipe_ctrl_prepare_stage(imaging_pipe_ctrl_t *ctrl,
                                ia_uid stage_uid,
                                const ia_binary_data *ipu_parameters);

/** Prepare stage version 2
 *
 * Prepare controller to the state ready to exchange data with the stage.
 *
 * \ingroup imaging_pipe_ctrl
 *
 * \param[in] ctrl controller handle
 * \param[in] stage_uid uid of the stage to be configured
 * \param[in] ipu_parameters IPU parameters to prepare the stage with
 */
css_err_t
imaging_pipe_ctrl_prepare_stage_v2(imaging_pipe_ctrl_t *ctrl,
                                   ia_uid stage_uid,
                                   ia_cipf_buffer_t *ipu_parameters);

/** Add buffer
 *
 * Add buffer to the controller and preset its payload data
 *
 * \ingroup imaging_pipe_ctrl
 *
 * \param[in] ctrl controller handle
 * \param[in] buffer buffer object to be added
 */
css_err_t
imaging_pipe_ctrl_add_buffer(imaging_pipe_ctrl_t *ctrl,
                             ia_cipf_buffer_t *buffer);

/** Register buffer to pipe through imaging controller
 *
 * Buffers administrated by the controller are cached and internal data-flow
 * managers might be present. Graph definition shall explicitly indicate what
 * payloads user must administrate.
 *
 * \ingroup imaging_pipe_ctrl
 *
 * \param[in] ctrl controller handle
 * \param[in] buffer buffer object to be added
 */
css_err_t
imaging_pipe_ctrl_register_buffer(imaging_pipe_ctrl_t *ctrl,
                                  ia_cipf_buffer_t *buffer);

/** Configure stage for iteration
 *
 * Configure stage for iteration by encoding all parameters to its terminals.
 *
 * \ingroup imaging_pipe_ctrl
 *
 * \param[in] ctrl controller handle
 * \param[in] stage_uid uid of the stage to be configured
 * \param[in] iterator iterator handle
 * \param[in] ipu_parameters IPU parameters to configure the stage with
 */
css_err_t
imaging_pipe_ctrl_configure_stage(imaging_pipe_ctrl_t *ctrl,
                                  ia_uid stage_uid,
                                  ia_cipf_iterator_t *iterator,
                                  const ia_binary_data *ipu_parameters);

/** Configure all stages in iteration
 *
 * Configures all stages in iteration that were identified and prepared by the
 * controller. The rest of stages are skipped.
 *
 * \ingroup imaging_pipe_ctrl
 *
 * \param[in] ctrl controller handle
 * \param[in] iterator iterator handle
 * \param[in] ipu_parameters IPU parameters to configure the stages with
 */
css_err_t
imaging_pipe_ctrl_configure_stages(imaging_pipe_ctrl_t *ctrl,
                                   ia_cipf_iterator_t *iterator,
                                   const ia_binary_data *ipu_parameters);

/** Configure stage for iteration
*
* Configure stage for iteration by encoding all parameters to its terminals.
*
* Note: this is new version of the API that supports extending PAL data with
*       control data specific to data flow operations transparent to
*       algo-pipe. I.e. transferring cached data from instance to another for
*       parallelism or dynamically changing the data flow in TNR
*       buffer-swap (aka TNR DFM)
*
* \ingroup imaging_pipe_ctrl
*
* \param[in] ctrl controller handle
* \param[in] stage_uid uid of the stage to be configured
* \param[in] iterator iterator handle
* \param[in] ipu_parameters IPU parameters to configure the stage with
*/
css_err_t
imaging_pipe_ctrl_configure_stage_v2(imaging_pipe_ctrl_t *ctrl,
                                     ia_uid stage_uid,
                                     ia_cipf_iterator_t *iterator,
                                     ia_cipf_buffer_t *ipu_parameters);

/** Configure all stages in iteration
 *
 * Configures all stages in iteration that were identified and prepared by the
 * controller. The rest of stages are skipped.
 *
 * Note: this is new version of the API that supports extending PAL data with
 *       control data specific to data flow operations transparent to
 *       algo-pipe. I.e. transferring cached data from instance to another for
 *       parallelism or dynamically changing the data flow in TNR
 *       buffer-swap (aka TNR DFM)
 *
 * \ingroup imaging_pipe_ctrl
 *
 * \param[in] ctrl controller handle
 * \param[in] iterator iterator handle
 * \param[in] ipu_parameters IPU parameters to configure the stages with
 */
css_err_t
imaging_pipe_ctrl_configure_stages_v2(imaging_pipe_ctrl_t *ctrl,
                                      ia_cipf_iterator_t *iterator,
                                      ia_cipf_buffer_t *ipu_parameters);


/** Decode statistics from stage in iteration
 *
 * Decodes statistics from all stages in iteration.
 *
 * \ingroup imaging_pipe_ctrl
 *
 * \param[in] ctrl controller handle
 * \param[in] iterator iterator handle
 * \param[in] ipu_parameters IPU parameters to configure the stages with
 */

css_err_t
imaging_pipe_ctrl_decode_statistics(imaging_pipe_ctrl_t *ctrl,
                                    ia_cipf_iterator_t *iterator,
                                    ia_uid stage_uid,
                                    ia_binary_data *statistics);

/** Decode statistics from stage in iteration with file dump capability
 *
 * Decodes statistics from all stages in iteration.
 * Terminal dump generation is optional.
 *
 * \ingroup imaging_pipe_ctrl
 *
 * \param[in] ctrl controller handle
 * \param[in] iterator iterator handle
 * \param[in] stage uid
 * \param[in] binary container of results
 * \param[in] buffer id
 */
css_err_t
imaging_pipe_ctrl_decode_statistics_v2(imaging_pipe_ctrl_t *ctrl,
                                       ia_cipf_iterator_t *iterator,
                                       ia_uid stage_uid,
                                       ia_binary_data *statistics,
                                       int bufid);

#endif
