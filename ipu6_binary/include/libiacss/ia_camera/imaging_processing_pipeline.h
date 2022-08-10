/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2017-2018 Intel Corporation. All Rights Reserved.
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

/** \file imaging_processing_pipeline.h
 *
 * \ingroup imaging_processing_pipeline
 *
 * \brief C++ utility classes to build IPU graphs from GCSS representation
 *  Functionality:
 *   - build pipeline. Construct CIPF stages
 *   - Allocates resources: queries memory needs and allocates buffers
 *   - Provides execution context (threads) to handle events from the pipeline
 */

#ifndef IA_CAMERA_IMAGING_PROCESSING_PIPELINE_H_
#define IA_CAMERA_IMAGING_PROCESSING_PIPELINE_H_

#include "processing_pipeline.h"
#include "i_imaging_pipe_controller.h"
#include <gcss_item.h>
#include <gcss_utils.h>
#include <gcss_aic_utils.h>
extern "C" {
#include <ia_isp_bxt.h>
#include <ia_cmc_types.h>
}
#include <string>
#include <list>
#include <memory>

// Forward declaration to avoid include
class ParamAdaptor;
class IPUStatistics;

/**
 * \class
 *
 * This class manages the execution of CIPF pipeline with imaging stages
 *
 */
class ImagingProcessingPipeline: private ProcessingPipeline {
public: // types
    class ConnectionConfig {
    public:
        ConnectionConfig(): mSourceStage(0),
                            mSourceTerminal(0),
                            mSourceIteration(0),
                            mSinkStage(0),
                            mSinkTerminal(0),
                            mSinkIteration(0),
                            mConnectionType(connection_type_push) {}

        ConnectionConfig(ia_uid sourceStage,
                         ia_uid sourceTerminal,
                         uint32_t sourceIteration,
                         ia_uid sinkStage,
                         ia_uid sinkTerminal,
                         uint32_t sinkIteration,
                         ia_cipf_connection_type_t connectionType):
                            mSourceStage(sourceStage),
                            mSourceTerminal(sourceTerminal),
                            mSourceIteration(sourceIteration),
                            mSinkStage(sinkStage),
                            mSinkTerminal(sinkTerminal),
                            mSinkIteration(sinkIteration),
                            mConnectionType(connectionType) {}
        void dump();

        ia_uid mSourceStage;
        ia_uid mSourceTerminal;
        uint32_t mSourceIteration;
        ia_uid mSinkStage;
        ia_uid mSinkTerminal;
        uint32_t mSinkIteration;
        ia_cipf_connection_type_t mConnectionType;
    };
    /**
     * \struct PipePortDescriptor
     * Information of a port that represents  CIPF stage terminal.
     * - desc contains the information retrieve from configuration, it is
     *        generic for any graph-node port
     * - cipfFormat represents same info but in ready-to-use cipf format.
     */
     struct PipePortDescriptor {
        GCSS::GraphCameraUtil::PortDescriptor desc;
        ia_cipf_frame_format_t cipfFormat;
     };

    /**
     * \struct PSysPipelineConnection
     * Group port info, connection, edge port for
     * pipeline configuration
     */
     struct PSysPipelineConnection {
         PipePortDescriptor portInfo;
         ConnectionConfig connectionConfig;
         bool hasEdgePort;
         PSysPipelineConnection() {
             hasEdgePort = false;
         }
     };
     /**
      * \struct JobDescriptor
      * Contains all required information to start a job in the pipeline.
      * All buffers are passed in a map were the key is the fully qualified
      * name of the port (pg-name:port-name). This map should have buffers
      * that are required by the edge ports of the pipeline.
      * The output of AIC (PAL) is also included.
      */
      struct JobDescriptor {
          uint32_t id;
          std::map<std::string, ia_cipf_buffer_t*> frameBuffers;
          ia_binary_data params; /* output of AIC */
          void *pSimulationControls;
      };

public:  //members
    ImagingProcessingPipeline();
    virtual ~ImagingProcessingPipeline();

    css_err_t init(int32_t execCtxId,
                   GCSS::BxtAicUtils &aicUtils,
                   ia_isp_bxt_input_params_v2 &initial3Aresults,
                   ia_binary_data &tunings,
                   ia_cmc_t &cmc);
    css_err_t reInit(ia_binary_data &tunings,
                     ia_cmc_t &cmc,
                     ia_isp_bxt_input_params_v2 &initial3Aresults);
    /* pipeline query methods */
    int32_t getCtxId() { return mExecCtxId; };
    css_err_t getAvailableStats(std::vector<ia_uid> &stats_ids);
    css_err_t getEdgePortNames(std::vector<std::string> &portNames);
    css_err_t getEdgePortsInfo(std::vector<GCSS::GraphCameraUtil::PortDescriptor*> &portDescriptors);
    css_err_t getPortBufferRequirement(std::string portName,
                                       ia_cipf_buffer_t **bufferReq);
    css_err_t registerBuffer(ia_cipf_buffer_t *buffer);
    css_err_t unregisterBuffer(ia_cipf_buffer_t *buffer);

    /* asynchronous execution API's */
    css_err_t queueJob(std::shared_ptr<JobDescriptor> &job);
    css_err_t waitForJob(std::shared_ptr<JobDescriptor> &job, IPUStatistics *pStats);
    css_err_t runIspAdapt(ia_isp_bxt_input_params_v2 &input,
                          const char *dumpName,
                          ia_binary_data *outputIpuParameters);

private:  // methods
    css_err_t build();
    css_err_t prepare(ia_isp_bxt_input_params_v2 &initalParams);
    css_err_t detectStatisticPorts(const GCSS::IGraphConfig &gc);

    /* build helper methods */
    css_err_t getInternalConnections(const GCSS::IGraphConfig &graphConfig,
                                     std::vector<PSysPipelineConnection> &confVector,
                                     std::vector<GCSS::IGraphConfig*> &programGroups);
    css_err_t portGetInfo(GCSS::IGraphConfig &port,
                          PipePortDescriptor &info);
    css_err_t portGetConnection(const GCSS::IGraphConfig *port,
            ConnectionConfig &connectionInfo,
            GCSS::IGraphConfig **peerPort);
    css_err_t setStageProperty(ia_uid stageUid,
                               ia_uid propertyUid,
                               uint32_t value);
    css_err_t setDisableProperty(uint32_t terminalId);
    void amendEdgeConnectionInfo(ConnectionConfig &ci);
    void simulationCheck(ia_cipf_stage_t *stage);
    css_err_t getBooleanPropertyValue(ia_cipf_stage_t *stage, bool &value, ia_uid uid);

    /* prepare helper methods */
    css_err_t handleCipfAttributes(std::vector<GCSS::IGraphConfig*> &programGroups);
    css_err_t configureTerminals();
    css_err_t identifyProperties();
    css_err_t bufferRequirements(bool realTerminals);
    css_err_t handleBufferRequirement(ia_cipf_buffer_t *reqBuffer,
                                      bool realTerminals);
    ia_cipf_buffer_t *allocateFrameBuffer(ia_cipf_buffer_t *req_buffer);
    css_err_t allocateParamBuffer(ia_cipf_buffer_t *req_buffer);
    uint32_t getPayloadSize(ia_cipf_buffer_t *buffer,
                            ia_cipf_frame_format_t *format);

private:  // members
    int32_t mExecCtxId;  /**< Execution context id. */
    std::unique_ptr<IImagingPipeController> mImagingPipeCtrl;  /**< Imaging pipe controller */
    ia_binary_data mCurrentTunings;    /**< Binary blob to the parsed cpf.
                                            We do not own the memory */
    std::map<ia_uid, ia_cipf_frame_format_t> mTermConfigMap;
    std::vector<ConnectionConfig> mConnectionConfigVec;
    std::vector<uint32_t> mDisabledTerminalVec;
    std::map<std::string, PipePortDescriptor> mEdgePorts;

    typedef std::list<ia_cipf_buffer_t*> TermBuflist_t;
    typedef std::map<ia_uid, TermBuflist_t> BufferRequirementMap_t;
    BufferRequirementMap_t mTermBufferMap;  /**< Map of cipf frame buffers registered
                                                 as terminal requirement during
                                                 the pipe creation */

    /**
     * Map to find the ia_uids of the ports of the pipeline that produce some
     * type of statistics.
     * Key is the uid of one of the named statistics sinks, like
     * GCSS_KEY_AWB_STATS_SINK
     * Value is the uid of the port, this is the fourcc code that can be used
     * in CIPF api to retrieve the ia_cipf_terminal_t
     */
    std::map<ia_uid, ia_uid> mStatisticsPorts;
    std::unique_ptr<ParamAdaptor> mParamAdaptor;

    /** Pointer to an initialized AIC utility class. It has been initialized
     * with the current IGraphConfig. It is used to retrieve the PG information
     * that AIC needs associated with this execution context.
     *  We don't own the memory
     */
    GCSS::BxtAicUtils *mBxtAicUtils;
    ia_cmc_t mCmc; /** We don't own the memory */
    bool mSimulation;
};

#endif /* IA_CAMERA_IMAGING_PROCESSING_PIPELINE_H_ */
