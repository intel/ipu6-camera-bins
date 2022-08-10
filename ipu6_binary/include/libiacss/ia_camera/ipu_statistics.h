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

#ifndef IA_CAMERA_PROCESSING_PIPELINE_IPU_STATISTICS_H_
#define IA_CAMERA_PROCESSING_PIPELINE_IPU_STATISTICS_H_

#include <ia_tools/css_types.h>
#include <ia_aiq_types.h>

/**
 * \class IpuStatistics
 */
class IPUStatistics {
public:
    IPUStatistics():
        mAfGrid(nullptr),
        mRgbsGrid(nullptr),
        mHistogram(nullptr),
        mFrameNumber(0),
        mTimeStamp(0),
        mSelfAllocated(false) {};
    virtual ~IPUStatistics() { free(); }
    void destroy() { delete this; }
    css_err_t allocate(size_t afGridSize, size_t rgbsGridSize, size_t histogramSize);
private:
    void free();
public:
    ia_aiq_af_grid *mAfGrid;
    ia_aiq_rgbs_grid *mRgbsGrid;
    ia_aiq_histogram *mHistogram;
    int32_t mFrameNumber;
    uint64_t mTimeStamp;
private:
    bool mSelfAllocated;
};

#endif /* IA_CAMERA_PROCESSING_PIPELINE_IPU_STATISTICS_H_ */
