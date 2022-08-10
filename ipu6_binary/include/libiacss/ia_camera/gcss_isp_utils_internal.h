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
#ifndef GCSS_ISP_UTILS_INTERNAL_H_
#define GCSS_ISP_UTILS_INTERNAL_H_

#include "gcss_isp_utils.h"

namespace GCSS {

/**
* Isp Utils Common
* \ingroup gcss
*
* Implements utilities common across IPU generations
*/
class IspUtilsCommon : public IspUtils {
public:
    IspUtilsCommon();
    IspUtilsCommon(const IGraphConfig *s, GdfVersion ipuVer);
    virtual ~IspUtilsCommon() {};

    /** Common utilities */
    virtual bool isDvsEnabled();
    virtual GdfVersion getIpuVersion();
    const IGraphConfig *getSettings() { return mSettings; }
private:
    const IGraphConfig *mSettings; /**< member to store settings ptr */
    GdfVersion mIpuVersion;
};

/**
* IPU4 implementations
* \ingroup gcss
*/
class IPU4IspUtils : public IspUtilsCommon {
public:
    IPU4IspUtils() {}
    IPU4IspUtils(const IGraphConfig *s, GdfVersion ipuVer) : IspUtilsCommon(s, ipuVer) {}
    ~IPU4IspUtils() {}

    virtual css_err_t getKernelConfigurations(KernelConfigs &kConfig); /**< not implemented */
    virtual css_err_t applyFormat(const IGraphConfig *sink,
        const std::string &format); /**< not implemented */
    virtual css_err_t applyCompression(const IGraphConfig *sink,
        const std::string &format); /**< not implemented */
};

/**
 * IPU5 implementations
 * \ingroup gcss
 */
class IPU5IspUtils : public IspUtilsCommon {
public:
    IPU5IspUtils() {}
    IPU5IspUtils(const IGraphConfig *s, GdfVersion ipuVer) : IspUtilsCommon(s, ipuVer) {}
    ~IPU5IspUtils() {};

    virtual css_err_t getKernelConfigurations(KernelConfigs &kConfig);
    virtual css_err_t applyFormat(const IGraphConfig *sink,
        const std::string &format);
    virtual css_err_t applyCompression(const IGraphConfig *sink,
        const std::string &format);
};
/**
* IPU6 implementations
* \ingroup gcss
*/
class IPU6IspUtils :  public IspUtilsCommon {
public:
    IPU6IspUtils() {}
    IPU6IspUtils(const IGraphConfig *s, GdfVersion ipuVer) : IspUtilsCommon(s, ipuVer) {}
    ~IPU6IspUtils() {}

    virtual css_err_t getKernelConfigurations(KernelConfigs &kConfig); /**< not implemented */
    virtual css_err_t applyFormat(const IGraphConfig *sink,
        const std::string &format); /**< not implemented */
    virtual css_err_t applyCompression(const IGraphConfig *sink,
        const std::string &format); /**< not implemented */
};
/**
* IPU7 implementations
* \ingroup gcss
*/
class IPU7IspUtils :  public IspUtilsCommon {
public:
    IPU7IspUtils() {}
    IPU7IspUtils(const IGraphConfig *s, GdfVersion ipuVer) : IspUtilsCommon(s, ipuVer) {}
    ~IPU7IspUtils() {}

    virtual css_err_t getKernelConfigurations(KernelConfigs &kConfig); /**< not implemented */
    virtual css_err_t applyFormat(const IGraphConfig *sink,
        const std::string &format); /**< not implemented */
    virtual css_err_t applyCompression(const IGraphConfig *sink,
        const std::string &format); /**< not implemented */
};
} // namespace
#endif