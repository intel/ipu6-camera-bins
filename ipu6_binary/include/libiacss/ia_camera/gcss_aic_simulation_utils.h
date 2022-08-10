/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2017-2020 Intel Corporation. All Rights Reserved.
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
#ifndef IA_CAMERA_GCSS_GCSS_AIC_SIMULATION_UTILS_H_
#define IA_CAMERA_GCSS_GCSS_AIC_SIMULATION_UTILS_H_

extern "C" {
#include "ia_isp_bxt_types.h"
}
#include <set>
#include "gcss_item.h"

namespace GCSS {

/**
 * Static utilities used only by simulation clients.
 * It allows to perform operations not permitted in normal SW stack but required
 * in simulation environment.
 *
 * Normal client should not need to modify graph setting, only query information
 * from them. The methods in this class allow the modification of the
 * graph settings. It is recommended that you clone the original settings,
 * before modifying
 *
 * Do not use this unless you know the details of constructing graph settings.
 */
class BxtAicSimUtils {
public:

    typedef struct KernelInfo {
        std::string name;
        int pal_uuid;
    } KernelInfo;

    /**
     * Clones an instance of graph settings. This is all the nodes in a tree.
     * This method allocates a new tree and clones the content from the
     * input to the output. the caller is responsible of deleting
     * the cloned settings.
     */
    static css_err_t cloneSettings(const IGraphConfig *in, IGraphConfig **out);

    /**
     * This method does not modify the settings it is purely a query, it will
     * be moved to gcss_utils or gcss_aic_utils
     * For a given graph settings it returns the pal_uuid of a kernel
     * specified by name.
     * It may return error if it does not find the kernel in the settings.
     **/
    static css_err_t getKernelPalUuid(const IGraphConfig *graphSettings,
                                      const std::string &kernelName,
                                      int32_t &palUuid);
    /**
     * This method takes as input the root of a GDF and returns a map
     * with the names and pal_uuids of the kernels inside a given stream-id and
     * graph, also passed as parameters. Kernels in the map are ordered similarly
     * as they appear in the run kernels list.
     *
     * \param[in] graphDescriptor Pointer to a node at the root of the parsed GDF
     * \param[in] graphId Target graph id to be analyzed
     * \param[in] streamId Target stream id to be analyzed
     * \param[out] kernelInfo vector with kernel names and uuid in a struct
     */
    static css_err_t getKernelList(const IGraphConfig *graphDescriptor,
                                   int32_t graphId, int32_t streamId,
                                   std::vector<KernelInfo> &kernelInfo);
    /**
     * From the root node of a GDF, and with the graph id this method
     * retrieves the list of program group nodes included in that graph.
     */
    static css_err_t getPgsInGraph(const IGraphConfig *graphDescriptor,
                                   int32_t graphId,
                                   std::set<IGraphConfig *> &pgs);
    /**
     * From graph settings this method retrieves list of routing elements in a
     * given stream id.
     * For each routing element(mux/demux) the name and the active route
     * is provided.
     * \param[in] settings   Pointer to the graph setting to analyze
     * \param[in] streamId   Stream id to target.
     * \param[out] muxConfig map with the results. key is the mux name, value
     *                       is the active route
     */
    static css_err_t getMuxConfiguration(const IGraphConfig *graphSettings,
                                         int32_t streamId,
                                         std::map<std::string, uint32_t>& muxConfig);

private:
    static css_err_t setValue(IGraphConfig *output, ia_uid, int value);
    static css_err_t getKernelInfoList(const GCSS::IGraphConfig &pg,
        std::vector<KernelInfo> &kernelInfos);
};
}

#endif /* IA_CAMERA_GCSS_GCSS_AIC_SIMULATION_UTILS_H_ */
