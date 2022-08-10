/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2013-2017 Intel Corporation. All Rights Reserved.
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

/*
 * ia_trace_linux.h
 *
 */

#ifndef _IA_TRACE_H
#define _IA_TRACE_H

#ifndef LOG_TAG
#define LOG_TAG "IA_TRACE"
#endif

#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/cdefs.h>
#include <sys/types.h>
#include <unistd.h>
#include "ia_cipr_log.h"

#define CAMERA_PRId32 "d"
#define CAMERA_PRId64 "I64d"
#define IA_TRACE_MESSAGE_LENGTH 1024
#define IA_TRACE_TAG_ALWAYS           (1 << 0)
#define IA_TRACE_TAG_NOT_READY        (1ULL << 63)
#define IA_TRACE_TAG IA_TRACE_TAG_ALWAYS

#define IA_TRACE_INIT() ia_trace_init()
#define IA_TRACE_ENABLED() ia_trace_is_tag_enabled(IA_TRACE_TAG)
#define IA_TRACE_BEGIN(name) ia_trace_begin(IA_TRACE_TAG, name)
#define IA_TRACE_END() ia_trace_end(IA_TRACE_TAG)

#define IA_TRACE_DECLSPEC static inline

void ia_trace_setup(void);
extern volatile int32_t ia_trace_is_ready;
extern uint64_t ia_trace_enabled_tags;
extern int ia_trace_marker_fd;

IA_TRACE_DECLSPEC __attribute__((always_inline)) int32_t
ia_trace_atomic_acquire_load(volatile const int32_t *ptr)
{
    int32_t value = *ptr;
    __asm__ __volatile__ ("" : : : "memory");
    return value;
}
IA_TRACE_DECLSPEC void ia_trace_init(void)
{
    if (!ia_trace_atomic_acquire_load(&ia_trace_is_ready)) {
        ia_trace_setup();
    }
}
IA_TRACE_DECLSPEC uint64_t ia_trace_is_tag_enabled(uint64_t tag)
{
    ia_trace_init();
    return ia_trace_enabled_tags & tag;
}
IA_TRACE_DECLSPEC void ia_trace_begin(uint64_t tag, const char *name)
{
    if (ia_trace_is_tag_enabled(tag)) {
        char buf[IA_TRACE_MESSAGE_LENGTH];
        ssize_t len;
        len = snprintf(buf, IA_TRACE_MESSAGE_LENGTH, "B|%d|%s", getpid(), name);
        if (len < 0) {
            CSS_DEBUG_ERR("snprintf error!");
            return;
        }
        if (write(ia_trace_marker_fd, buf, (size_t)len) != len)
            CSS_DEBUG_ERR("write error!");
    }
}
IA_TRACE_DECLSPEC void ia_trace_end(uint64_t tag)
{
    if (ia_trace_is_tag_enabled(tag)) {
        char c = 'E';
        if (write(ia_trace_marker_fd, &c, 1) !=1)
            CSS_DEBUG_ERR("write error!");
    }
}
#endif //_IA_TRACE_H
