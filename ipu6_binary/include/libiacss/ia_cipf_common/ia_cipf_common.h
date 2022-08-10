/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2013-2018 Intel Corporation. All Rights Reserved.
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

#ifndef _IA_CIPF_COMMON_H_
#define _IA_CIPF_COMMON_H_

#include <ia_cipf/ia_cipf_types.h>

#define ia_cipf_external_mask            ia_fourcc(0xFF,0,0xFF,0xFF)
#define ia_cipf_external_mask_idx        ia_fourcc(0xFF,0,0xFF,0)
#define ia_cipf_external_source_uid(idx) ia_fourcc('@','S','R',idx)
#define ia_cipf_external_sink_uid(idx)   ia_fourcc('@','S','N',idx)
#define ia_cipf_external_source_terminal_uid(idx) \
                                         ia_cipf_external_source_uid(idx)
#define ia_cipf_external_sink_terminal_uid(idx) \
                                         ia_cipf_external_sink_uid(idx)

/* support external source and sink with parameter terminal types */
#define ia_cipf_external_param_source_uid(idx) \
        ia_fourcc('@','P','R',idx)
#define ia_cipf_external_param_sink_uid(idx) \
        ia_fourcc('@','P','N',idx)
#define ia_cipf_external_param_source_terminal_uid(idx) \
        ia_cipf_external_param_source_uid(idx)
#define ia_cipf_external_param_sink_terminal_uid(idx) \
        ia_cipf_external_param_sink_uid(idx)

#define is_external_source(uid) ((ia_cipf_external_mask_idx & uid) == \
                                 (ia_cipf_external_mask \
                                  & ia_cipf_external_source_uid(0)))
#define is_external_sink(uid) ((ia_cipf_external_mask_idx & uid) == \
                               (ia_cipf_external_mask \
                                & ia_cipf_external_sink_uid(0)))
#define is_external_param(uid) (( is_external_source(uid) \
                                 || is_external_sink(uid)) \
                                && (char)(uid>>16) == 'P')

#define ia_cipf_external_stage_uid(id) ia_fourcc(((id & 0xFF00) >> 8),id,'E','X')
#define external_stage_id_from_uid(uid) ((uid & 0xFFFF0000) >> 16)
#define is_external_stage_uid(uid) ((uid & 0x0000FFFF) == ia_cipf_external_stage_uid(0))

/* Backward compatibility for deprecated external source & sink uids */
/** \todo Remove these uids when not used anymore */
static const uint32_t
ia_cipf_external_source_uid = ia_cipf_external_source_uid(0);
static const uint32_t
ia_cipf_external_sink_uid = ia_cipf_external_sink_uid(0);
static const uint32_t
ia_cipf_external_secondary_sink_uid = ia_cipf_external_sink_uid(1);
static const uint32_t
ia_cipf_external_third_sink_uid = ia_cipf_external_sink_uid(2);

static const uint32_t
ia_cipf_external_source_terminal_uid = ia_cipf_external_source_terminal_uid(0);
static const uint32_t
ia_cipf_external_sink_terminal_uid = ia_cipf_external_sink_terminal_uid(0);
static const uint32_t
ia_cipf_external_secondary_sink_terminal_uid = ia_cipf_external_sink_terminal_uid(1);
static const uint32_t
ia_cipf_external_third_sink_terminal_uid = ia_cipf_external_sink_terminal_uid(2);

/** END backward compatibility */
#define ia_cipf_common_stage_uid        ia_fourcc('C','M','M','N')

/* File-Sink */
#define ia_cipf_filesink_uid            ia_fourcc('F','S','N','K')
#define ia_cipf_filesink_terminal_uid   ia_fourcc('F','S','N','K')
#define filesink_prefix_info_uid        ia_fourcc('S','N','K','P')

#endif
