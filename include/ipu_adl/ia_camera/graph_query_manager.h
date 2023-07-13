/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2015-2018 Intel Corporation. All Rights Reserved.
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

#ifndef GRAPH_QUERY_MANAGER_H
#define GRAPH_QUERY_MANAGER_H

#include "gcss.h"
#include "gcss_item.h"
#include "gcss_utils.h"

namespace GCSS {

class GraphQueryManager
{
public:
    GraphQueryManager() : mStrictQuery(true),
                          mGS(nullptr),
                          mGD(nullptr),
                          mKey(-1){}
    ~GraphQueryManager(){}

    typedef std::map<ItemUID, std::string> GraphQuery;
    typedef std::vector<IGraphConfig*> QueryResult;

    /**
    * isInitialized
    *
    * \ingroup gcss
    *
    * Returns true if the object has been initialized correctly with valid
    * settings and descriptor
    *
    */
    bool isInitialized() { return (mGS != nullptr && mGD != nullptr); };

    /**
     * Create graph
     *
     * \ingroup gcss
     *
     * Takes pointer to one of the settings found with queryGraphs and
     * returns full graph combined with graph descriptor.
     *
     * \param[in] settings
     * \param[out] result
     */
    css_err_t createGraph(IGraphConfig* settingsGraph, IGraphConfig** result);

    /**
     * Destroy graph
     *
     * \ingroup gcss
     *
     * Needs to be called for each graph created with createGraph
     *
     * \param[in] graph
     *
     */
    static void destroyGraph(IGraphConfig* graph);

    /**
    * Query graphs
    *
    * \ingroup gcss
    *
    * Query graph settings file for settings that matches search terms in
    * GraphQuery;
    *
    * \param[in] GraphQuery
    * \param[out] QueryResult
    * \param[optional | in] strict if true, all search terms has to match
    */
    css_err_t queryGraphs(const GraphQuery&,
                          QueryResult&,
                          bool strict = true);
    css_err_t queryGraphs(const GraphQuery&,
                          const QueryResult&,
                          QueryResult&,
                          bool strict = true);

    /**
     * Set graph settings
     *
     * \ingroup gcss
     *
     * Set parsed graph settings to graph query manager for later use.
     *
     * \param[in] settings
     */
    void setGraphSettings(const IGraphConfig* settings);

    /**
     * Set graph descriptor
     *
     * \ingroup gcss
     *
     * Set parsed graph descriptor to graph query manager for later use.
     *
     * \param[in] descriptor
     */
    void setGraphDescriptor(const IGraphConfig* descriptor);
private:
    css_err_t getGraph(GraphConfigNode*, GraphConfigNode*);
    bool mStrictQuery; /**< true by default. True = every search item has to match
                        false = at least one match */
    // Store parsed data into these containers, instead of using a single node
    const IGraphConfig *mGS; // graph settings
    const IGraphConfig *mGD; // graph descriptor
    int32_t mKey; // key of the selected setting

    void goThroughSearchItems(const GraphQuery&, const IGraphConfig*, uint16_t&);

    static css_err_t addSensorModeData(GraphConfigNode *sensorNode,
                                      GraphConfigNode *sensorModesNode,
                                      const std::string &sensorModeID);
    css_err_t getConnectionData(const std::string& source_connection,
                               const std::string& sink_connection,
                               GraphConfigNode *settings,
                               GraphConfigNode *ret_node);
    css_err_t getStaticConnectionData(const std::string& source_connection,
                                      const std::string& sink_connection,
                                      GraphConfigNode *ret_node);
    IGraphConfig *copyNodeToResult(IGraphConfig *descriptorNodes,
                                   ia_uid nodeId,
                                   GraphConfigNode* resultNode);
    css_err_t propagateIntAttribute(IGraphConfig *srcNode,
                                    IGraphConfig *dstNode,
                                    ia_uid attributeId);
    css_err_t propagateStrAttribute(IGraphConfig *srcNode,
                                    IGraphConfig *dstNode,
                                    ia_uid attributeId);
    css_err_t validateSettingsAgainstDescriptor();
    bool nodeHasBaseNode(IGraphConfig &graphNode, std::string &baseNodeName);
    IGraphConfig* constructNodeFromBase(IGraphConfig *derivedNode,
                                        std::string &baseName,
                                        IGraphConfig *gdfNodesRoot);
};
} // namespace
#endif
