/*
* INTEL CONFIDENTIAL
* Copyright (c) 2018 Intel Corporation. All Rights Reserved.
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
#ifndef GCSS_ISP_UTILS_H_
#define GCSS_ISP_UTILS_H_

#include "gcss.h"
#include "graph_utils.h"

namespace GCSS {

struct KernelConfigContainer {
    int32_t overwriteMode = 0; /**< use this flag to tell which values to update */
    uint32_t kernel_uuid;
    int32_t enable;
    uint32_t metadata[4];
    ia_isp_bxt_bpp_info_t bpp_info;
};

/**
* These modes are used to tell which kernel properties are to be overwritten
*/
enum OverwriteMode {
    OVERWRITE_ENABLE   = 1 << 1,
    OVERWRITE_BPP      = 1 << 2,
    OVERWRITE_METADATA = 1 << 3
};

static const std::string IPU_VER_5("IPU5");
static const std::string IPU_VER_6("IPU6");
static const std::string IPU_VER_7("IPU7");
/**
 * Vector that is used to hold kernelConfig structs per kernel
 */
typedef std::vector<KernelConfigContainer> KernelConfigs;

/** \class IspUtils
 * Provides IPU specific utilities that can be accessed through
 * the pointer constructed with the Factory method.
 */
class IspUtils {

public:
    virtual ~IspUtils() {}

    /**
    * Isp Utils Factory
    *
    * \ingroup gcss
    *
    * Returns pointer that allows access to common and IPU specific utilities.
    * Ipu is automatically selected based on the version attribute in the
    * graph descriptor.
    *
    * \param[in]  settings
    * \return     pointer to one of the ipu specific implementations
    */
    static std::shared_ptr<IspUtils> Factory(const IGraphConfig *settings);

    /**
    * Is dvs enabled
    *
    * \ingroup gcss
    *
    * Returns true if dvs enabled in settings. False otherwise,
    *
    * \return true if dvs is enabled in the settings
    * \return false if dvs disabled in the settings
    */
    virtual bool isDvsEnabled() = 0;

    /**
    * Get IPU version
    *
    * \ingroup gcss
    *
    * Returns ipu version as GdfVersion type
    *
    * \return GdfVersion
    */
    virtual GdfVersion getIpuVersion() = 0;

    /**
    * Get kernel configurations
    *
    * \ingroup gcss
    *
    * Returns map of runtime kernel configurations. KernelConfigurations map
    * contains pal uuid and enable value for kernel. Use through ipu specific
    * implementation.
    *
    * \param[out] KernelConfigContainer populated with kernel configs
    * \return css_err_none on success
    * \return css_err_nimpl if function not implemented
    * \return css_err_general in case of error
    */
    virtual css_err_t getKernelConfigurations(KernelConfigs &kConfig) = 0;

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
    virtual css_err_t applyFormat(const IGraphConfig *sink,
        const std::string &format) = 0;

    /** Applies compression to full pipe and sets given format to output port
    *
    * \ingroup gcss
    *
    * Applies given format to the port that the sink is connected to.
    * The given format has to be present in the options list of the pg where the
    * port belongs to. If there is no options list for the pg, then no error is
    * returned and no format applied. Applies compression also to PSA and to
    * tnr ports if present.
    *
    * \param[in] sink    Pointer to the sink in the graph.
    * \param[in] format  Name of the compressed format that is being applied
    * \return css_err_none       in case of success
    * \return css_err_argument   in case the given format is not compressed
    * \return css_err_data       in case the given format is not in the options list
    */
    virtual css_err_t applyCompression(const IGraphConfig *sink,
        const std::string &format) = 0;
};
} // namespace
#endif