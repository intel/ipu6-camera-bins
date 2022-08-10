/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2017 Intel Corporation. All Rights Reserved.
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

/** \file processing_pipeline.h
 *
 * \defgroup imaging_processing_pipeline Execution context for IPU pipelines
 * \ingroup ia_camera
 *
 * \brief base class to ImagingProcessingPipeline
 * Non imaging functionality is implemented here, where imaging dependent
 * functionality will remain in ImagingProcessingPipeline
 *  Functionality:
 */
#ifndef IA_CAMERA_PROCESSING_PIPELINE_H_
#define IA_CAMERA_PROCESSING_PIPELINE_H_

extern "C" {
// Pipeline framework (CIPF)
#include <ia_cipf/ia_cipf_pipe.h>
#include <ia_cipf/ia_cipf_stage.h>
#include <ia_cipf/ia_cipf_buffer.h>
#include <ia_cipf/ia_cipf_property.h>
#include <ia_cipf/ia_cipf_terminal.h>
#include <ia_cipf/ia_cipf_iterator.h>

// CIPF backends
//#include <ia_cipf_css/ia_cipf_css.h>
#include <ia_cipf_common.h>

// CIPR alloc interface
#include <ia_cipf_css_uids.h>
#include <ia_cipr/ia_cipr_alloc.h>
#include <ia_cipr/ia_cipr_memory.h>

// Pipeline builder
#include <ia_camera/ia_cipb.h>
}
#include <string>
#include <map>

/**
 * \class
 * The processing pipeline class has the non imaging specific functionality
 * needed to use a CIPF pipeline
 */
class ProcessingPipeline {
public:
    ProcessingPipeline();
    virtual ~ProcessingPipeline();

protected:  // members
    std::string mPipeName; /**< helper string for tracing*/
    ia_cipf_pipe_t *mPipe;
    ia_cipf_iterator_t *mPipeIterator;
    ia_cipb_t mBuilder;

    std::map<ia_uid, ia_cipf_buffer_t *> mParamBuffs;

};

#endif /* IA_CAMERA_PROCESSING_PIPELINE_H_ */
