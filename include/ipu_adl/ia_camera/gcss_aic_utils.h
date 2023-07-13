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
#ifndef GCSS_AIC_UTILS_H_
#define GCSS_AIC_UTILS_H_

extern "C" {
#include "ia_isp_bxt_types.h"
#include "ia_view_types.h"
}

#include "gcss.h"
#include "gcss_item.h"
#include "graph_utils.h"
#include "gcss_isp_utils.h"

namespace GCSS {

typedef std::map<GCSS::IGraphConfig*, ia_isp_bxt_resolution_info_t> portResHistoryMap;
typedef std::vector<GCSS::IGraphConfig*> NodesVector;
typedef std::vector<int32_t> StreamIdVector;
/*
* Map with the information for each stream id of the RBM for each PG
* the key of the map is the stream id (60000, 60001, etc..)
* the Values in the map is a vector with tuples that have the PG/CB id as integer
* and the RBM as a string.
*/
typedef std::map<int32_t, std::vector<std::tuple<int32_t, std::string> > > GraphRoutingInfo;
/*
 * Maps the execution context id to index of the vector mKernels  where the
 * pre-allocated arrays of ia_isp_bxt_run_kernels_t are stored. <exec_ctx_id, idx>
 */
typedef std::map<int32_t, uint32_t> ExecCtxIdsMap;
/**
* \class BxtAicUtils
* GCSS AIC dependent utility functions
* */
class BxtAicUtils {
public: /*  methods */
    /**
     * \param legacy true if stream id is used instead of execution context
     */
    BxtAicUtils(bool legacy = true);
    ~BxtAicUtils();
    /**
     * Init aic utils
     *
     * Reserves memory, and creates kernel lists for each stream
     *
     * \ingroup gcss
     *
     * \param[in] GCHandle a handle to createGraph result
     * \return css_err_none when successful
     */
    css_err_t initAicUtils(const IGraphConfig *GCHandle);

    /**
     * get the list of stream Ids available in the graph settings initialized
     * in this object.
     *
     * \param[out] streamIds vector with the stream id's
     * \param[in] active boolean to specify whether the list of stream ids will
     *                   have all the stream ids in the graph or only the ones
     *                   with valid settings. Those are considered as active
     *                   streams
     * \return css_err_none
     */

    css_err_t getStreamIds(std::vector<int32_t> &streamIds, bool active = false) const;

    /**
     * Get program group by stream id
     *
     * \ingroup gcss
     *
     * Returns pointer to program group struct, which is allocated as a
     * member of this class. So the ownership of the memory remains in the instance
     * of this class. The user does not need to free the memory.
     *
     * \param[in] stremId a stream id of the program group being requested
     * \param[out] pg Reference to a program group struct being populated
     */
    void getProgramGroup(int32_t streamId, ia_isp_bxt_program_group &pg);

    /**
    * Returns the structure required by ia_isp (aka PAL) to run
    *
    * \ingroup gcss
    * Unfortunate name, program group. This is the array of structures
    * ia_isp_bxt_run_kernels_t that describes the input/output resolution for
    * each kernel.
    * This version of the API takes as input a concrete IGraphConfig node that
    * represents a PG. The other API takes the stream-id and returns all the kernels
    * in all the PG's that belong to them.
    * In both cases the list of kernels is returned inside the AIC structure
    * ia_isp_bxt_program_group.
    * The memory allocated is owned by this instance. The user of this API must not
    * de-allocate the pg.run_kernels pointer.
    *
    * NOTE: The current implementation only supports IPU6, not yet IPU5
    *
    * \param[in] pgNode IGraphConfig node representing a particular PG
    * \param[out] pg Reference to a program group struct being populated
    */
    css_err_t getProgramGroup(const IGraphConfig* pgNode, ia_isp_bxt_program_group &pg);

    /**
     * Get cmc mode tag associated with the sensor
     * \ingroup gcss
     *
     * This will be used to retieve the CMC section of a multi-tune file. This
     * is done using ia_lard.
     *
     * \param[out] cmcTag
     * \return css_err_none if everything goes ok
     * \return css_err_internal if settigns do no thave sensor node
     * \return css_err_data if sensor node does node have the attribure cmc_tag
     */
    css_err_t getSensorCmcId(std::string &cmcTag);

    /* Get Information about the DOL mode of the sensor
     * \ingroup gcss
     *
     * This will be used to retieve the conversion gain and the DOL mode from
     * the settings of the sensor mode.
     * if sensor mode does not have the attribute the method does not fail but
     * returns gain 1 and mode none.
     *
     * TODO: Mode should come as an enum and not as string, this requires
     * addition of dol mode in ia_isp_bxt
     *
     * \param[out] gain conversion gain
     * \param[out] mode DOL mode, only 4 possible values
     * \return css_err_none if everything goes ok
     * \return css_err_internal if settigns do no thave sensor node or instance
     *                          is not initialized
     */
    css_err_t getDolInfo(float &gain, std::string &mode);

    /* Get MBR Tool data
    * \ingroup gcss
    *
    * Retrieve the limits of MBR tool stored in the settings. This information
    * is required for WFOV mode.
    *
    * \param[in] stream_id Value of the stream_id associated with the MBR limits
    * \param[out] data Pointer to valid structure where to store the MBR limits
    * \return css_err_none if everything goes ok
    * \return css_err_data if settigns do not have enough data to fill the mbr limits structure
    * \return css_err_internal if settigns do not have mbr limits data
    *
    */
    css_err_t getMbrData(int32_t stream_id, ia_isp_bxt_gdc_limits *data);

    /**
     * Get the IGraphConfig root node that was used to initialize this utility
     * class. This allows users to perform other queries to the IGraphConfig
     * interface.
     * \ingroup gcss
     *
     */
    const IGraphConfig* getGraphConfig() { return mGCHandle; }

    css_err_t getSourceResolutionHistory(ia_isp_bxt_resolution_info_t &history);

    /**
    * Retrieves the list of all the RBM's in all the stream-ids present in the
    * settings. The RBM's are listed per PG/CB
    * \see GraphRoutingInfo
    * \ingroup gcss
    *
    */
    css_err_t getRoutingInfo(GraphRoutingInfo &routingInfo);

    /**
     * Dumps the list of kernels for given stream
     *
     * \ingroup gcss
     *
     * \param[in] streamId
     */
    void dumpKernels(int32_t streamId);
    /**
     * Dumps the information from a list of kernels descriptors
     *
     * \ingroup gcss
     *
     * \param[in] streamId
     */
    static void dumpKernels(ia_isp_bxt_run_kernels_t *kernelList,
                            uint32_t kernel_count);

    static void dumpResInfo(ia_isp_bxt_run_kernels_t &kernelInfo);
    static void dumpResHistory(ia_isp_bxt_resolution_info_t &resInfo,
                               const char* name);
private:
    /* pair of execution context id and port */
    typedef std::pair<int32_t, IGraphConfig*> StreamPort;
    typedef ia_isp_bxt_resolution_info_t ResolutionInfo;

    /* Helper classes to store sensor and kernel information */
    struct Scaler: public ResolutionInfo {
        Scaler() : num(1), denom(1) {} /**< avoid possible division by 0 */
        int32_t num;  /**< scaling factor numerator */
        int32_t denom; /**< scaling factor denominator */
    };
    struct Binner : public ResolutionInfo {
        Binner() : hFactor(1), vFactor(1) {} /**< avoid possible division by 0 */
        int32_t hFactor;  /**< horizontal binning factor */
        int32_t vFactor; /**< Vertical binning factor */
    };
    struct SensorModeInfo {
        ResolutionInfo pixelArray;
        Binner binner;
        Scaler scaler;
    };
    struct ResolutionMemPool {
           std::vector<ResolutionInfo *> resHistorys;
           std::vector<ResolutionInfo *> resInfos;
    };
    struct KernelGroupInfo {
        KernelGroupInfo() : runKernels(nullptr), kernelCount(0) {}
        KernelGroupInfo(uint32_t kCount) : runKernels(nullptr), kernelCount(kCount) {}
        ia_isp_bxt_run_kernels_t *runKernels;
        uint32_t kernelCount = 0;
    };
    // Storage for kernel info extensions to AIC requirements
    struct KernelInfo {
        int32_t rcb;
        int32_t branchPoint;
        int32_t sinkPortId;
        int32_t restorePoint;
        IGraphConfig *sinkPort;
        IGraphConfig *srcPort;
    };

    css_err_t collectNodesIntAttribute(std::vector<int32_t> &pgsAttribute,
                                       ia_uid attributeKey,
                                       ia_uid nodeType) const;
    int32_t getUpstreamStreamId(int32_t streamId,
                                IGraphConfig **upstreamPort);

    css_err_t createKernelListStructures();
    css_err_t createPerPgKernelListStructures(const IGraphConfig *pg, uint32_t);
    static css_err_t getSensorModeInfo(IGraphConfig &sensorNode, SensorModeInfo &sensorInfo);
    static css_err_t sourceGetResolutionHistory(ResolutionInfo &history,
                                                IGraphConfig &sourceNode);
    static css_err_t  calculateSensorResolutionHistory(IGraphConfig &sensorNode,
                                                       ResolutionInfo &history);
    static css_err_t  calculateTPGResolutionHistory(IGraphConfig &sensorNode,
                                                    ResolutionInfo &history);
    static css_err_t calculateBufSrcResolutionHistory(IGraphConfig &tpgNode,
                                                      ResolutionInfo &history);
    static css_err_t getCsiDimensions(IGraphConfig &sensorNode,
                                      ResolutionInfo &pixFormat);
    css_err_t populateKernelArray(int32_t streamId,
                                  ia_isp_bxt_run_kernels_t *kernelList,
                                  uint32_t index,
                                  portResHistoryMap &portResHistory);

    css_err_t getStreamChains(std::map<int32_t, std::vector<StreamPort>> &streamChains);
    css_err_t generateKernelListsForExecCtxs();

    css_err_t getResHistoryForIntermediatePg(const IGraphConfig *pg,
        ResolutionInfo &resolutionHistory,
                                             portResHistoryMap &portResHistory);
    css_err_t handleSinkPort(KernelInfo &kInfo, const IGraphConfig *pg, std::vector<int32_t> &, int32_t);
    static css_err_t kernelGetValues(const GCSS::IGraphConfig *kernelNode,
                                     int32_t *palUuid = NULL,
                                     int32_t *kernelId = NULL,
                                     uint32_t *metadata = NULL,
                                     int32_t *enable = NULL,
                                     int32_t *rcb = NULL,
                                     int32_t *branchPoint = NULL,
                                     int32_t *sinkPort = NULL,
                                     int32_t *restorePoint = NULL);

    static css_err_t kernelGetResolutions(const IGraphConfig *kernelNode,
                                          std::map<std::string, ResolutionInfo> &resInfos);
    static css_err_t kernelGetResolutions(const GCSS::IGraphConfig *kernelNode,
        ResolutionInfo *resInfo);

    static css_err_t kernelGetBppInfo(const IGraphConfig &kernelNode,
                                      ia_isp_bxt_run_kernels_t &runKernel);
    static void accumulateCrop(ia_rectangle &in, const ia_rectangle &toAccumulate,
                                       int32_t scaleNum = 1, int32_t scaleDenom = 1);
    css_err_t kernelIdSanityCheck(uint32_t checksum, uint32_t kernelCount);

    // IPU6/7 new logic - start
    bool nodesHaveKernelLinks();
    bool detectNewGraphVersion();
    // IPU6 new logic - end
    static bool kernelHasResolutions(GCSS::IGraphConfig *kernelNode);
    void deleteKernelInfo();
    static void dumpPortResHistoryMap (portResHistoryMap &m);
    static const char* resInfoToStr(ResolutionInfo &resInfo);
    void applyKernelConfigs(const KernelConfigs &kernelConf,
                            ia_isp_bxt_run_kernels_t &runKernels);
    friend class GraphUtil;
    ExecCtxIdsMap mExecCtxIds;
    std::vector<ResolutionMemPool> mResMems;
    std::map<const IGraphConfig*, KernelGroupInfo> mRunKernelsPerPg;
    std::map<int32_t, KernelGroupInfo> mRunKernelsPerStream;
    ResolutionInfo mSourceHistory;

    const IGraphConfig *mGCHandle;
    bool mUseStreamId;
    GraphUtil mGraphUtil;
    GdfVersion mGdfVersion;
    std::shared_ptr<IspUtils> mISPUtils;
};
} // namespace
#endif
