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
#ifndef GCSS_UTILS_H_
#define GCSS_UTILS_H_

#include "gcss.h"
#include <set>
#include <utility>
#include <string>
#include <limits>
#include "gcss_item.h"

namespace GCSS {
/**
 * \enum GdfVersion
 * Enum to identify the different IPU versions
 */
enum GdfVersion {
    GDF_VERSION_NONE,
    GDF_VERSION_IPU4 = 4,
    GDF_VERSION_IPU5,
    GDF_VERSION_IPU6,
    GDF_VERSION_IPU7
};
/**
 * \class GraphCameraUtil
 * Class that holds utility functions to derive information from
 * GraphConfig container for Camera runtime.
 *
 * Utilities are separated from GraphConfig interface in order to
 * specialize the XML-schema that Camera runtime is dependent of
 * from the generic concept of graph information.
 *
 * These specializations include execCtxs, ports, execCtx edges
 * as well as sensor and imaging kernel details that are nested
 * in generic graph elements hierarchy.
 */
class GraphCameraUtil
{
public: // types
   /**
    * \struct PortDescriptor
    * Information of a port from an XML graph node
    */
    struct PortDescriptor {
        std::string    name;
        std::string    pgName;
        int32_t        direction;
        int32_t        enabled;
        uint32_t       terminalId; /**< Unique terminal id (is a fourcc code)
                                         this is relevant only when the node
                                         is a PG and then the port is a terminal */
        uint32_t        width;    /**< Width of the frame in pixels */
        uint32_t        height;   /**< Height of the frame in lines */
        std::string     format;   /**< Frame format name, use gcss_format
                                       utilities to query more information */
    };

public:
    virtual ~GraphCameraUtil() {}

    static const int32_t PORT_DIRECTION_INPUT = 0;
    static const int32_t PORT_DIRECTION_OUTPUT = 1;
    //pair of source and sink between either 2 pg, or 2 execution context.
    typedef std::pair<std::string, std::string> StreamConnection;

    /*
     * Generic Dimensions prototype:
     *
     * Port-elements, kernels as well as sensor entities input and output
     * elements reuse the common dimensions prototype including
     *  GCSS_KEY_WIDTH, GCSS_KEY_HEIGHT, GCSS_KEY_BYTES_PER_LINE,
     *  GCSS_KEY_LEFT, GCSS_KEY_TOP, GCSS_KEY_RIGHT, GCSS_KEY_BOTTOM
     */

    /**
     * Get width, height, bpl and cropping values from the given element
     *
     * \ingroup gcss
     *
     * \param[in] node the node to read the values from
     * \param[out] w width
     * \param[out] h height
     * \param[out] l left crop
     * \param[out] t top crop
     * \param[out] r right crop
     * \param[out] b bottom crop
     */
    static css_err_t getDimensions(const IGraphConfig *node,
                                   int32_t *w = NULL,
                                   int32_t *h = NULL,
                                   int32_t *l = NULL,
                                   int32_t *t = NULL,
                                   int32_t *r = NULL,
                                   int32_t *b = NULL);

    /*
     * NODE-specialization
     */
    static IGraphConfig* nodeGetPortById(const IGraphConfig *node, int32_t id);

    /*
     * PORT-specialization
     */

    /**
     * Check if port is at the edge
     *
     * \ingroup gcss
     *
     * A port is at the edge of the video execCtx (pipeline) if its peer is in a PG
     * that has a different execCtxID (a.k.a. pipeline id) or if its peer is a
     * virtual sink.
     *
     * Here we check for both conditions and return true if this port is at either
     * edge of a pipeline
     * \param[in] port Reference to port Graph node
     * \return true if it is edge port
     */
    static bool isEdgePort(const IGraphConfig* port);

    /**
     * Check if port is virtual
     *
     * \ingroup gcss
     *
     * Check if the port is a virtual port. this is the end point
     * of the graph. Virtual ports are the nodes of type sink.
     *
     * \param[in] port Reference to port Graph node
     * \return true if it is a virtual port
     * \return false if it is not a virtual port
     */
    static bool portIsVirtual(const IGraphConfig* port);
    /**
     * return child node full name, this is pg-name:child-name
     *
     * This makes the child name unique in the graph, because multiple
     * nodes may have children named same way (ex: input)
     *
     * \ingroup gcss
     *
     * \param[in] port Reference to port Graph node
     * \return string with the full name
     */
    static std::string getFullName(const IGraphConfig &child);

    /**
     * Return the port descriptor
     *
     * \ingroup gcss
     *
     * \param[in] port
     * \param[out] descriptor
     * \return 0 if it is an input port
     * \return 1 if it is an output port
     */
    static css_err_t portGetDescriptor(const IGraphConfig* port,
                                       PortDescriptor &desc);
    /**
     * Return the port direction
     *
     * \ingroup gcss
     *
     * \param[in] port
     * \return 0 if it is an input port
     * \return 1 if it is an output port
     */
    static int portGetDirection(const IGraphConfig* port);

    /**
     * For a given port node it constructs the fourCC code used in the connection
     * object. This is constructed from the program group id.
     *
     * \ingroup gcss
     *
     * \param[in] portNode
     * \param[out] stageId Fourcc code that describes the PG where this node is
     *                     contained
     * \param[out] terminalID Fourcc code that describes the port, in FW jargon,
     *                        this is a PG terminal.
     * \return css_err_none in case of no error
     * \return css_err_argument in case some error is found
     */
    static css_err_t portGetFourCCInfo(const IGraphConfig *portNode,
                                      ia_uid& stageId,
                                      uint32_t& terminalId);

    /**
     * Retrieve the graph config node of the port that is connected to a given port.
     *
     * \ingroup gcss
     *
     * \param[in] port Node with the info of the port that we want to find its peer.
     * \param[out] peer Pointer to a node where the peer node reference will be
     *                  stored
     * \return css_err_none
     * \return css_err_argument if any of the graph settings is incorrect.
     */
    static css_err_t portGetPeer(const IGraphConfig* port, IGraphConfig** peer);

    /**
     * Finds the stream id of the program group that the port is in.
     *
     * \ingroup gcss
     *
     * \param[in] port The port whose stream id is being returned
     * \return valid stream id, or -1 in case of error.
     */
    static int portGetStreamId(const IGraphConfig *port);
    /**
     * Finds the execCtx id of the program group that the port is in.
     *
     * \ingroup gcss
     *
     * \param[in] port The port whose execCtx is being returned
     * \return valid execCtx id, or -1 in case of error.
     */
    static int portGetExecCtxId(const IGraphConfig *port);
    static int getExecCtxIds(const IGraphConfig &setting,
                             std::set<int32_t> &execCtxIds);
    static int getExecCtxIdsTuningMap(const IGraphConfig &settings,
                                      std::map<int32_t,int32_t> &execCtxIdsTuningMap);
    static int portGetKey(const IGraphConfig *port, ia_uid uid);

    /**
    * Retrieves the basic information of a port. Uses the peer port (i.e. the
    * port connected to this one) to get the information if not found from the
    * given port.
    *
    * Returns an error if some of the information is missing unless it is a
    * private port.
    *
    * \ingroup gcss
    *
    * \param[in] port        Port to query the format.
    * \param[out] enabled    Passthrough, enabled or disabled status
    * \param[out] terminalId Unique terminal id
    */
    static css_err_t portGetInfo(const GCSS::IGraphConfig *port,
                                 uint32_t &enabled,
                                 uint32_t &terminalId);

    /**
    * Retrieves the format information of a port. Uses the peer port (i.e. the
    * port connected to this one) to get the information if not found from the
    * given port.
    *
    * Returns an error if some of the information is missing unless it is a
    * private port.
    *
    * \ingroup gcss
    *
    * \param[in] port        Port to query the format.
    * \param[out] enabled    Passthrough, enabled or disabled status
    * \param[out] terminalId Unique terminal id
    * \param[out] width      Width of the frame in pixels
    * \param[out] height     Height of the frame in lines
    * \param[out] fourcc     Frame format
    * \param[out] bpl        Bytes per line
    * \param[out] bpp        Bits per pixel
    */
    static css_err_t portGetFormat(const GCSS::IGraphConfig *port,
                                   uint32_t &enabled,
                                   uint32_t &terminalId,
                                   uint32_t &width,
                                   uint32_t &height,
                                   uint32_t &fourcc,
                                   uint32_t &bpl,
                                   uint32_t &bpp);

    /** Apply given format to output port
     *
     * \ingroup gcss
     *
     * Applies given format to the port that the sink is connected to.
     * The given format has to be present in the options list of the pg where the
     * port belongs to. If there is no options list for the pg, then no error is
     * returned and no format applied.
     *
     * \param[in] sink    Pointer to the sink in the graph.
     * \param[in] format  Name of the format that is being applied
     * \return css_err_none   in case of success
     * \return css_err_data   in case the given format is not in the options list
     */
    static css_err_t applyFormat(const IGraphConfig *sink,
                                 const std::string &format);
    /**
    *Get PeerFormat by port name.
    *If not found from given port, try defaulting to YUV420_8_SP(NV12).
    *
    * \param[in] port use port name to query format.
    * \return string  gcssFormat name
    */
    static std::string portGetPeerFormat(const IGraphConfig *port);

    /**
     * SENSOR-specialization
     */

    /**
     * Get binning factor values from the given node
     *
     * \ingroup gcss
     *
     * \param[in] node the node to read the values from
     * \param[out] hBin horizontal binning factor
     * \param[out] vBin vertical binning factor
     */
    static css_err_t sensorGetBinningFactor(const IGraphConfig *node,
                                           int &hBin, int &vBin);

    /**
     * Get scaling factor values from the given node
     *
     * \ingroup gcss
     *
     * \param[in] node the node to read the values from
     * \param[out] scalingNum scaling ratio
     * \param[out] scalingDenom scaling ratio
     */
    static css_err_t sensorGetScalingFactor(const IGraphConfig *node,
                                           int &scalingNum,
                                           int &scalingDenom);
    /**
    * sensorGetType
    *
    * Returns the sensor type as a string. Sensor types are typically
    * BAYER, SVE, MD etc..
    * The input is a valid graph settings (output of createGraph)
    *
    * \param[in] settings
    * \param[out[ sensorType
    * \return css_err_argument if the inputs arguments are invalid
    * \return css_err_noentry if it could not find the sensor type
    * \return css_err_none if everything went ok.
    */
    static css_err_t sensorGetType(const IGraphConfig *settings,
                                   std::string &sensorType);

    /**
    * Get content type
    *
    * By default if content_type tag is not found will return pixel_data
    *
    * \ingroup gcss
    *
    * \param[in] node the node to read the values from
    * \return content type string
    */
    static std::string portGetContentType(const IGraphConfig *node);

    /**
     * Analyse all connections between execution context.
     * Generates 3 lists:
     * - list of pair of names of inter-connections between execution contexts
     * - list of input ports names associated with input streams
     * - list of output ports names associated with output streams
     *
     * \ingroup gcss
     *
     * \param[in] graphHandle pointer to any node in the graph
     * \param[out] connections set connections with edges pair
     * \param[out] pixel_sources pixel data sources
     * \param[out] pixel_sinks pixel data sinks
     */
    static css_err_t getExecCtxConnectionPorts(const IGraphConfig *graphHandle,
                                               std::vector<StreamConnection> &connections,
                                               std::vector<std::string> &pixel_sources,
                                               std::vector<std::string> &pixel_sinks);
    /**
     * Finds input ports for the given execCtx or stream id
     *
     * \ingroup gcss
     *
     * \param[in] uid key identifying whether the next value is a stream id or
     *                a exec ctx id.
     * \param[in] execCtxId id of the execCtx OR stream id
     * \param[in] graphHandle pointer to any node in the graph
     * \param[out] ports reference to a vector of IGraphConfig where to store the
     *                   found ports
     * \param[in] computeKey GCSS key of compute element (usually PG or CB)
     */
    static css_err_t getInputPorts(ia_uid uid,
                                   int32_t execCtxId,
                                   const IGraphConfig &graphHandle,
                                   std::vector<IGraphConfig *> &ports,
                                   ia_uid computeKey = GCSS_KEY_PROGRAM_GROUP);
    /**
     * Finds output ports for the given execCtx or stream id
     *
     * \ingroup gcss
     *
     * \param[in] uid key identifying whether the next value is a stream id or
     *                a exec ctx id.
     * \param[in] execCtxId id of the execCtx OR stream id
     * \param[in] graphHandle pointer to any node in the graph
     * \param[out] ports reference to a vector of IGraphConfig where to store the
     *                   found ports
     * \param[in] computeKey GCSS key of compute element (usually PG or CB)
     */
    static css_err_t getOutputPorts(ia_uid uid,
                                    int32_t execCtxId,
                                    const IGraphConfig &graphHandle,
                                    std::vector<IGraphConfig *> &ports,
                                    ia_uid computeKey = GCSS_KEY_PROGRAM_GROUP);
    /**
     * Finds input port for the given execCtx or stream id
     *
     * \ingroup gcss
     *
     * \param[in] uid key identifying whether the next value is a stream id or
     *                a exec ctx id.
     * \param[in] execCtxId id of the execCtx OR stream id
     * \param[in] graphHandle pointer to any node in the graph
     * \param[out] port input port
     * \param[in] computeKey GCSS key of compute element (usually PG or CB)
     */
    static css_err_t getInputPort(ia_uid uid,
                                  int32_t execCtxId,
                                  const IGraphConfig *graphHandle,
                                  IGraphConfig **port,
                                  ia_uid computeKey = GCSS_KEY_PROGRAM_GROUP);

    /**
     * getSubgraphPorts
     *
     * For a given subgraph, specified via stream id or exec-ctx id, retrieve the
     * ports that cross subgraph boundaries.
     *
     * \ingroup gcss
     * \param[in] uid Key to specify whether we are looking for stream id or exec ctx
     *                ids input port. Possible values are GCSS_KEY_STREAM_ID or
     *                GCSS_KEY_EXEC_CTX_ID
     * \param[in] execCtxId Value of the stream/exec-ctx id
     * \param[in] direction Either PORT_DIRECTION_INPUT or PORT_DIRECTION_OUTPUT
     * \param[in] graphHandle Reference to the root node of the tree
     * \param[in] computeKey
     * \param[out] ports vector of pointers where to store the found port nodes.
     *
     * \return  css_err_argument in case of any of the input parameters being invalid
     *                           or in case it did not find any port.
     */
    static css_err_t getSubgraphPorts(ia_uid uid,
                                      int32_t execCtxId,
                                      int32_t direction,
                                      const IGraphConfig &graphHandle,
                                      std::vector<IGraphConfig *> &ports,
                                      ia_uid computeKey = GCSS_KEY_PROGRAM_GROUP);

    /**
     *
     * Retrieve a list of program groups that belong to a given execCtx id or
     * stream id.
     * Iterates through the graph configuration storing the program groups
     * that match this execCtx id into the provided vector.
     *
     * \param[in] uid Used to determine if we search the PG per stream-id or exec
     *                ctx-id
     * \param[in] value Depending on the key parameter this is the value of the
     *                  stream-id or execCtx-id to match.
     * \param[in] GCHandle Handle to get graph result.
     * \param[out] programGroups Vector with the nodes that match the criteria.
     */
    static css_err_t getProgramGroups(ia_uid uid,
                                     int32_t value,
                                     const GCSS::IGraphConfig *GCHandle,
                                     std::vector<IGraphConfig*> &pgs);

    /**
     * Retrieve the number of kernels inside a PG
     *
     * \param[in] pgNode Pointer to a IGraphConfig node that represents a PG.
     * \param[out] kernelCount number of kernels found inside.
     */
    static css_err_t getKernelCountInPg(const GCSS::IGraphConfig *pgNode,
                                        uint32_t &kernelCount);
    /**
     * Helper function to get values from the kernel settings
     * \todo Moved to bxt aic utils, will be removed from here after hal has
     *       adapted to changes.
     * \ingroup gcss
     *
     * \param[in] kernelNode
     * \param[out] palUuid
     * \param[out] kernelId
     * \param[out] metadata
     * \param[out] enable
     * \param[out] rcb
     * \param[out] branchPoint
     */
    static css_err_t kernelGetValues(const IGraphConfig *kernelNode,
                                    int32_t *palUuid = NULL,
                                    int32_t *kernelId = NULL,
                                    uint32_t *metadata = NULL,
                                    int32_t *enable = NULL,
                                    int32_t *rcb = NULL,
                                    int32_t *branchPoint = NULL,
                                    int32_t *sinkPort = NULL);

    /**
     * Return pointer to active source
     *
     * Graph descriptor may define multiple sources. This function returns
     * pointer to source node that is set active.
     *
     * \ingroup gcss
     *
     * \param[in]  settings,   pointer to gc graph
     * \param[out] sourceNode, vector of pointers to active sources
     */
    static css_err_t getSourceNode(const IGraphConfig *gcHandle,
            std::vector<IGraphConfig*> &sourceNodes);


    /**
    * Retrieve all the sinks in the current graph configuration that match the
    * input parameter string in their name attribute.
    *
    * If the name to match is empty it returns all the nodes of type sink
    *
    * \param[in] name String containing the name to match.
    * \param[in] gcHandle pointer to the graph
    * \param[out] sink List of sinks that match that name
    * \return css_err_none in case of success
    * \return css_err_noentry if no sinks were found in the graph config.
    * \return css_err_argument if graph config handle is nullptr
    */
    static css_err_t graphGetSinksByName(const std::string &name,
                                         const IGraphConfig *gcHandle,
                                         std::vector<IGraphConfig*> &sinks);

    /**
     * Debug utils
     */

    /**
     * Pretty print any recognized element: node, port, kernel
     *
     * \ingroup gcss
     *
     * \param[in] node of which name to print
     */
    static std::string print(const IGraphConfig *node);

    /**
     * Dumps the whole tree of nodes and attributes.
     *
     * \ingroup gcss
     *
     * \param node Node to dump
     * \param depth Depth level of the dump. Default(whole tree) is 0
     */
    static void dumpNodeTree(const IGraphConfig* node, int depth = 0);

    /**
     * Convert string containing a number to a binary blob.
     *
     * \ingroup gcss
     *
     * \param[in] str String containing a number in decimal or hex (prefix "0x").
     * \param[out] bytes Size of the new binary data in bytes.
     *
     * \return void* Pointer to the newly allocated binary data.
     *               The format is little-endian, least significant bytes first.
     *               Caller must free with IA_CIPR_FREE()
     */
    static void *numString2binary(const std::string &str, unsigned int *bytes = NULL);

    /**
     * Free the memory allocated by IA_CIPR_CALLOC()
     *
     * \ingroup gcss
     *
     * \param[in] Pointer to the memory allocated by IA_CIPR_CALLOC()
     */
    static void releaseBinary(void *binary);

    /**
     * Process the attribute overrides tags in the graph.
     * The apply tag allows a graph to modify an attribute of a member node.
     * The syntax is:
     * <apply target="" value=""/>
     * - Target is the fully qualified name of the  attribute we want to override.
     *  By fully qualified we mean that it contains the names of all the nodes in the
     *  hierarchy until the attribute. The names are separated by colon (:).
     *   Ex, to change the attribute of a kernel the target  would be:
     *   "node:kernel:attribute"
     * - Value is the value to give the the attribute.
     *
     * Please note that this logic does not insert new attributes to a given node
     * it just modifies an existing. The parsing of the graph will fail if
     * the override tries to add a new attribute.
     *
     * This mechanism is useful to reduce the number of duplicated nodes that only
     * differ in a few attributes. This is the case for example for the 8/10 bpp
     * PSA node.
     *
     * \param[in] graphNode Node to the GDF graph
     * \param[out] result Node to the resulting tree of combining the settings with
     *                    the graph.
     *
     * \return css_err_none in case no error
     *         css_err_data in case the node or attribute are not present in the
     *                      current graph.
     */
    static css_err_t processGraphOverrides(GraphConfigNode& graphNode, GraphConfigNode& results);
};

/**
 * \brief Rounds the given number up to the next power of 2
 *
 * Rounds given number up to the next power two. Up to number
 * of bits in 'unsigned int' type.
 *
 * \returns Value of 'a' rounded up to the next power of two.
 *          Zero in case of an overflow.
*/
inline unsigned ceil_pow2(unsigned a)
{
    // Maximum number of possible bit shifts, to avoid error situations
    const int maxNumShifts = std::numeric_limits<unsigned>::digits - 1;

    unsigned result = 1;
    int shifts = 0;
    while (result < a && shifts <= maxNumShifts) {
        result <<= 1;
        ++shifts;
    }

    if (shifts > maxNumShifts) {
        // Overflow, return zero.
        result = 0;
    }

    return result;
}

} // namespace GCSS

#endif /* GCSS_UTILS_H_ */
