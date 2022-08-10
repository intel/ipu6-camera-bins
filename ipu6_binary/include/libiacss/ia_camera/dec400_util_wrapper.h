/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2018 Corporation. All Rights Reserved.
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
#ifndef _DEC400_UTIL_WRAPPER_H_
#define _DEC400_UTIL_WRAPPER_H_

#include <stdint.h>

// This needs to stay in sync with IA_CSS_CMPRS_MAX_TS_OFFSETS from nci_dec400_util_inline.h
#define MAX_TS_OFFSETS 3

namespace dec400util {

unsigned calcBufferSize(
    const uint32_t fourcc,
    unsigned bitDepth,
    bool isTnr,
    unsigned stride,
    unsigned height,
    unsigned extraMem,
    unsigned tsOffsets[MAX_TS_OFFSETS],
    unsigned tsSizes[MAX_TS_OFFSETS]);

unsigned numberOfPlanes(const uint32_t fourcc);

} // namespace dec400util

#endif // _DEC400_UTIL_WRAPPER_H_

