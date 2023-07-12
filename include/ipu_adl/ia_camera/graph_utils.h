
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
#ifndef IA_CAMERA_GCSS_GRAPH_UTILS_GRAPH_UTILS_H_
#define IA_CAMERA_GCSS_GRAPH_UTILS_GRAPH_UTILS_H_

#include <memory>
#include <functional>
#include <set>

extern "C" {
#include "ia_isp_bxt_types.h"
}
#include "gcss.h"
#include "gcss_utils.h"

namespace GCSS {


/**
 * \class GraphUtil
 *
 * This class implements similar functionality as BxtAicUtils. It is meant as
 * a replacement for IPU6 graphs that contain more explicit graph information.
 * It is then an internal implementation detail of BxtAicUtils that has more
 * capabilities.
 *
 * This class analyses the graph settings and creates a representation
 * of the graph and inner imaging graphs.
 *
 * This representation does not duplicate data, just stores it in a more
 * convenient way to perform graph operations.
 *
 * We need to separate conceptually the XML data stored in IGraphConfig containers
 * (that is also stored as a tree of nodes) from the actual graph that represents
 * the information stored, the graph that represents an imaging system.
 * For that we formalise the following concepts:
 * - Container graph: This is the graph made out of IGraphConfig nodes. It is a
 *   representation of the XML hierarchical structure. The information stored
 *   in this graph is a 1:1 mapping with the XML data. IGraphConfig methods
 *   helps us to traverse this graph and find information from the nodes (xml
 *   tags) and xml attributes.
 *
 * - Camera Graph: this is the graph that represents a camera subsystem. The nodes
 *   in this graph are sensor, buffer source/sinks and processing nodes like
 *   Program Groups (FW).
 *
 * - Imaging Graph: This is the graph that represents the image processing
 * nodes inside the camera graph processing nodes (ex: PG). The nodes of
 * this graph are imaging kernels (PAL/ATE), routing elements (mux/demux/split)
 * and also PG ports because one imaging graph may expand multiple PG's
 *
 * - Meta-graph: This is the graph made out of camera subgraphs. The Camera graph
 * may group its nodes in two different ways:
 *   - stream-id: this traditionally aligns with the video/still/IR pipes.
 *   - execution context id: This grouping is done to split the nodes in separate
 *   threads (execution contexts). Only used by CISU.
 *
 * Conceptually the last three graphs are nested, the metagraph is at the top,
 * then the camera graph and finally the imaging graph.
 *
 * The imaging graphs are split per subgraph id because the structures given to
 * PAL are also grouped by subgraph id, whatever this may be (stream-id or exec-ctx)
 *
 * The container graph is the data storage that is passed during the initialisation
 * of this class, but the other three graphs are now represented by the
 * following member variables of this class:
 * - Camera Graph: mGraphNodes
 * - MetaGraph : mSubGraphInfoMap
 * - Imaging Graph: inside a a subgraph info map entry as imagingGraph.
 *
 * All the nodes of these three graphs derived from the same base struct that
 * contains the needed fields to traverse those graphs in topological order.
 * This is, a bi-directional adjacently list.
 * With this representation it is very easy to perform any type of operation in
 * topological order. We use the same algorithm (Graph Depth First) implemented
 * in method traverseGraph with different visitor functions.
 * Same scheme can be used at any of those 3 levels.
 *
 * At the moment the visitors are used for:
 * - Dumping information in traces for each node (for the 3 graphs)
 * - Calculating the resolution history of the imaging kernels
 * - detecting subgraph boundaries at the camera graph
 *
 * Any new operation on the graph only requires a new visitor function at the
 * correct level of detail (meta-graph, graph or imaging-graph)
 *
 */
class GraphUtil
{
public:
    GraphUtil();
    ~GraphUtil();
    /**
     * Initialise the GraphUtils class.
     * During this call the class will analyse the graph settings and create
     * structures to store the information of the imaging kernels found.
     * It creates
     * \param[in] subgraphType either GCSS_KEY_STREAM_ID or GCSS_ID_EXEC_CTX
     *                         It determines what type of subgraph will be used
     *                         to group the kernels.
     * \param[in] ipuVer IPU version
     *
     * \param[out] gcHandle Pointer to a IGraphConfig Object that represents
     *                      some graph-settings.
     * \return css_err_none if everything is fine
     * \return css_err_no_memory if there is some problem allocating the new
     *                           structures.
     * \return css_err_internal if there is some problem with the graph settings
     *                          being analysed
     */
    css_err_t init(ia_uid subgraphType, const IGraphConfig *gcHandle,
                   GdfVersion ipuVer = GdfVersion::GDF_VERSION_IPU6);

    /* Query methods */
    /**
     * isInitialized
     * returns true if the class was initialised with some settings
     */
    inline bool isInitialized() { return (mGraphSettings != nullptr); }
    /**
     * Get program group by execution context Id or stream id
     *
     *
     * Fills the provided structure with the relevant data for that subgraph
     * id provided. This id needs to be align with the construction time parameter.
     * i.e. you cannot construct this object with GCSS_KEY_STREAM_ID and then
     * pass a execution ctx id to this method.
     *
     * The granularity of the subgraphs is different and it should match the
     * granularity of the AIC execution.
     *
     * \param[in] subgraphId A stream id (or exec Ctx) of the program group
     *                      being requested.
     *                      The concrete value needs to be in sync with the input
     *                      parameter during initialisation call.
     * \param[out] pg reference to a program group struct being populated
     *
     * \return css_err_none if everything is fine.
     * \return css_err_data if the subgraph does not contain any subgraphs with
     *                      the requested id.
     */
    css_err_t getAicData(int32_t subgraphId, ia_isp_bxt_program_group &pg);

    /**
    * Get the AIC PG info from a IGraphConfig PG node.
    * The PG node must be part of the settings that where used to initialize this
    * instance.
    *
    * \param[in] pgNode A IGraphConfig Node that represents the PG whose kernels
    *                   we want to retrieve.
    * \param[out] pg reference to a program group struct being populated
    *
    * \return css_err_none if everything is fine.
    * \return css_err_data if the PG is not in the settings used during initialization
    */
    css_err_t getPgAicData(const IGraphConfig *pgNode, ia_isp_bxt_program_group &pg);

    css_err_t getSourceResolutionHistory(ia_isp_bxt_resolution_info_t &history) {
        history = mSourceHistory;
        return css_err_none;
    };
    /**
     * Debugging tool to dump to error traces the AIC structures of the given
     * subgraph id.
     * \param[in] subgraphId
     */
    void dumpKernels(int32_t subgraphId);

private: // types
    /**
     * \struct KernelInfoMemPool
     * structure to associate the array of run kernel structs for each
     * subgraph-id or PG,
     * and the resolution info structures allocated for each kernel.
     * Each kernel needs two, the size of these vector should
     * match the number of kernels in a given subgraph-id.
     * This struct is used only for memory management purposes (allocate/free).
     * We need this for two reasons:
     * - because the structure ia_isp_bxt_run_kernels_t has pointers to two
     *   structures of type ia_isp_bxt_resolution_info_t that may be null.
     * - because the interface of AIC requires a C-style array of run kernels
     *   structures
     */
    struct KernelInfoMemPool {
           ia_isp_bxt_run_kernels_t *runKernels;
           size_t kernelCount;
           std::vector<ia_isp_bxt_resolution_info_t *> resHistorys;
           std::vector<ia_isp_bxt_resolution_info_t *> resInfos;
    };
    /**
     * \enum
     * Type of the inner graph nodes
     */
    enum ImagingNodeType {
            IMAGING_NODE_KERNEL,
            IMAGING_NODE_MUX,
            IMAGING_NODE_DEMUX,
            IMAGING_NODE_SPLIT,
            IMAGING_NODE_PG_PORT_IN,
            IMAGING_NODE_PG_PORT_OUT,
            IMAGING_NODE_NONE
    };
    /**
     * \struct BaseGraphNode
     * Base structure that is used for the three types of nodes that
     * the camera graph has at different levels
     * Top level meta-graph made out of subgraphs
     * Medium level graph made out of sources, PG's, sink etc..
     * Inner graph that represent the imaging elements inside the Program Group
     * nodes the inner graph is made out of kernels, mux/demux and ports of the
     * PG's
     * This structure has the basics to traverse the graph in any direction
     * using standard graph traversal algorithms.
     */

    struct BaseGraphNode {
        std::string name;
        IGraphConfig* data;
        bool visited;
        std::map<BaseGraphNode*, std::string > parents;
        std::map<BaseGraphNode*, std::string> children;
        BaseGraphNode(): data(nullptr), visited(false) {}
        void addParent(BaseGraphNode *p, std::string pinId) {
            parents.insert(std::pair<BaseGraphNode*, std::string>(p, pinId));
        }
        void addChild(BaseGraphNode *c, std::string pinId) {
            children.insert(std::pair<BaseGraphNode*, std::string>(c, pinId));
        }
        void removeChild(BaseGraphNode *c) {
            auto it = children.find(c);
            if (it != children.end()) {
                children.erase(it);
            }
        }
        void removeParent(BaseGraphNode *p) {
            auto it = parents.find(p);
            if (it != parents.end()) {
                parents.erase(it);
            }
        }
        void emanzipate() {
            for (auto &p : parents) {
                p.first->removeChild(this);
            }
            for (auto &c : children) {
                c.first->removeParent(this);
            }
        }
    };

    struct GraphNode : public BaseGraphNode {
        ia_uid type;    /**<GCSS_KEY_HW, GCSS_KEY_PROGRAM_GROUP, GCSS_KEY_SINK */
        int32_t streamId;
        int32_t exeCtxId;
        GraphNode(): BaseGraphNode(),
                     type(GCSS_KEY_PROGRAM_GROUP),
                     streamId(-1),
                     exeCtxId(-1){}
    };
    typedef std::shared_ptr<GraphNode> GraphNodePtr;

    enum ImagingNodeFlags {
        IMAGING_NODE_FLAG_NONE,
        IMAGING_NODE_FLAG_RCB            = (0x1 << 0),      /*<! if this imaging node kernel is a Resolution Changing Block or not*/
        IMAGING_NODE_FLAG_PRIVATE_PORT   = (0x1 << 1),
        IMAGING_NODE_FLAG_DISABLED       = (0x1 << 2),  /*<! This flag has the same meaning as the kernel enabled field, but is generic for all types of imaging nodes */
        IMAGING_NODE_FLAG_MAX            = (0x1 << 3)
    };
    /**
     * \struct ImagingNode
     * Node in the pipe of imaging elements (kernels)
     * This struct is used to create a graph of nodes and perform operations
     * in topological order, like the resolution history calculation.
     * The information of the links is derived from kernel links(klink)
     * The resolution history used for the run_kernel struct is usually filled
     * from the parent. The modifications of the history from this node
     * are stored in the member nextresolutionHistory. They are meant for the children
     * nodes.
     * In order to suport kernels with more than 1 child we have the resoltuion
     * info and nextresolutionHistory as vectors, one per output klink
     */
    struct ImagingNode : public BaseGraphNode {
        ImagingNodeType type;
        int32_t flags;
        std::map<std::string, ia_isp_bxt_resolution_info_t> resolutionInfo;  /*<! resolution info for each of the outputs of this kernel, key is kernel output pin name */
        std::map<std::string, ia_isp_bxt_resolution_info_t> nextResolutionHistory; /*<! resolution history for the NEXT kernels (children nodes) ,  key is kernel output pin name*/
        ia_isp_bxt_resolution_info_t currentHistory;
        ia_isp_bxt_run_kernels_t kernelInfo; /*<! local copy used for temporary operations */
        ia_isp_bxt_run_kernels_t *outKInfo; /*<! preallocated run_kernels for output towards AIC.*/
        int32_t routingActivePath; /*<! In case this node is a routing element (mux/demux) this member stores the active input/output */
        ImagingNode();
    };
    typedef std::shared_ptr<ImagingNode> ImagingNodePtr;

    /**
     * \struct SubGraphInfo
     * Container for the information of a single subgraph.
     * The type of subgraph can be stream-id or exec-ctx.
     * It can be also considered a node of a meta-graph made out of subgraphs.
     */
    struct SubGraphInfo : public BaseGraphNode {
        ia_uid subgraphType;  /**< gcss key for exec-ctx or stream-id */
        int32_t id;           /**< id fo the subgraph */
        /**< if the subgraph type is stream id this value is the same as id,
         * if subgraph type is execution context then this value is the stream
         * id of all the nodes inside the subgraph, there cannot be more than 1
         **/
        int32_t streamId;
        uint32_t ispTuningMode;
        std::vector<GraphNode*> nodes;
        std::vector<IGraphConfig*> pgs;
        std::vector<IGraphConfig*> inputPorts;
        std::vector<IGraphConfig*> outputPorts;
        size_t kernelCount;
        ia_isp_bxt_run_kernels_t *kernelMemory;
        std::map<std::string, ImagingNodePtr> imagingGraph;
        SubGraphInfo() : BaseGraphNode(),
                         subgraphType(GCSS_KEY_STREAM_ID),
                         id(0), streamId(-1),
                         ispTuningMode(0),kernelCount(0),
                         kernelMemory(nullptr) {}
    };
    typedef std::shared_ptr<SubGraphInfo> SubGraphInfoPtr;

    struct KernelLink {
        KernelLink(IGraphConfig &kl);
        bool isSrcAPort() { return srcPin.empty(); }
        bool isDstAPort() { return dstPin.empty(); }
        std::string toStr() { return srcNode + ":" + srcPin + "->" + dstNode + ":" + dstPin; }
        std::string srcNode;
        std::string srcPin;
        std::string dstNode;
        std::string dstPin;
    };
private: //methods
    css_err_t analyzeGraphSettings();
    css_err_t allocateAicData();
    void deleteAicStructs();
    css_err_t populateAicData();
    css_err_t removeUnusedNodes();
    css_err_t disableKernelsToDisabledTerminals(SubGraphInfo &sgInfo);
    css_err_t analyzeSubGraphs(std::map<int32_t, SubGraphInfoPtr> &infoMap);
    css_err_t addGraphNode(IGraphConfig &node);
    css_err_t addGraphConnection(IGraphConfig &node);
    css_err_t addImagingNode(SubGraphInfo& sgInfo, IGraphConfig& kernel, std::string pgName);
    css_err_t addImagingLink(SubGraphInfo &ctxInfo, IGraphConfig &klink,
                             IGraphConfig &pg);
    css_err_t addRoutingNode(SubGraphInfo &sgInfo, IGraphConfig &routing,
                             ImagingNodeType type, std::string pgName);
    css_err_t collectPgInnerGraph(SubGraphInfo &sgi, IGraphConfig &pg);
    css_err_t collectSourceInnerGraph(SubGraphInfo &sgi);
    css_err_t collectInterPgConnections(SubGraphInfo &sgi);
    css_err_t collectSubgraphConnections();
    css_err_t traverseGraph(BaseGraphNode *item,
                            std::function<css_err_t(BaseGraphNode*)> &f,
                            bool forward = true);
    css_err_t getDownstreamSubgraphs(IGraphConfig *src,
                                    std::vector<int32_t> &subgraphIds);
    css_err_t calculateSourceResHistory(SubGraphInfo &sgi,
                                       ia_isp_bxt_resolution_info_t &resHistory);
    css_err_t fillAicRunKernels(SubGraphInfo &sgi);
    css_err_t getUpstreamResHistory(ImagingNode &portNode);
    css_err_t getCrossSgInPorts(GraphNode &node,
                                std::vector<IGraphConfig *> &ports);
    css_err_t getParentHistory(ImagingNode &child,
                               ia_isp_bxt_resolution_info_t &parentHistory);
    css_err_t getKernelResolutionInfos(ImagingNode &kNode);
    css_err_t disableDisconnectedKernels(SubGraphInfo &sgi);
    void getAvailableSubgraphs(std::set<int32_t> &ids);
    void resetGraph();
    void resetInnerGraph(SubGraphInfo &sgi, bool reportUnvisited = true);
    void resetMetaGraph();
    css_err_t subgraphConnectionVisitor(BaseGraphNode *n);
    css_err_t resHistoryCalcVisitor(BaseGraphNode *n);
    css_err_t resHistoryINodeVisitor(BaseGraphNode *n);
    css_err_t kernelDisableVisitor(BaseGraphNode *n, bool forward = false);
    css_err_t kernelDisconectedVisitor(BaseGraphNode *n, bool forward = false);
    css_err_t activeNodeVisitor(BaseGraphNode *n, std::vector<std::string> *nodes);
    css_err_t getUnvisitedInputPortsPeers(SubGraphInfo &sgi, std::vector<ImagingNode*> &internalInputPeers);
    // Debug utils
    void dumpSubGraphInfos();
    void dumpInnerGraph(int32_t id);
    void dumpOuterGraph();
    void dumpAicStructs();
    static css_err_t dumpInnerNodeVisitor(BaseGraphNode *item, ImagingNodeType type);
    static css_err_t printOuterNode(BaseGraphNode *item);
private: // members
    const IGraphConfig *mGraphSettings;
    ia_uid mSubgraphType;   /**< GCSS_KEY_STREAM_ID, GCSS_KEY_EXEC_CTX_ID */
    ia_isp_bxt_resolution_info_t mSourceHistory;

    /**
     * map with the Info for each subgraph, the key is the subgraph id.
     * The concrete subrgraph type is passed in the constructor
     * we can use stream-id or execution-context-id
     * The inner graphs are stored in the SubgraphInfo structure
     */
    std::map<int32_t, SubGraphInfoPtr> mSubgraphInfoMap;

    /**
     * outer graph as represented by the lighter GraphNode structures.
     * The key is the name of the node.
     */
    std::map<std::string, GraphNodePtr> mGraphNodes;
    std::vector<IGraphConfig*> mConnections;
    /**
     * map used to store the memory for the AIC structs associated with a given
     * subgraph id. The key of the map is the subgraph-id
     * This map is used only for memory management (alloc/free).
     * The arrays stored here are used via the SubgraphInfo::kernelMemory field
     */
    std::map<int32_t, KernelInfoMemPool> mKernelMemoryMap;
    /**
    * map used to store the memory for the AIC structs associated with a given
    * PG id. The key of the map is the IGraphConfig Node address that represents
    * each node.
    * This map is used only for memory management (alloc/free).
    */
    std::map<const IGraphConfig*, KernelInfoMemPool> mPGKernelMemoryMap;
    /**
     * IPU version
     */
    GCSS::GdfVersion mIpuVer;
    /**
     * if IPU version is < than 7 the computeKey is GCSS_KEY_PROGRAM_GROUP
     * in IPU7 the concept of PG was replace with compute blocks. in this
     * case the mComputeKeyUid id GCSS_KEY_COMPUTE_BLOCK
     */
    ia_uid mComputeKeyUid;
};

} //namespace GCSS


#endif /* IA_CAMERA_GCSS_GRAPH_UTILS_GRAPH_UTILS_H_ */
