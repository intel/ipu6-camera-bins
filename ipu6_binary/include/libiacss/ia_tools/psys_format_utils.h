/*
* INTEL CONFIDENTIAL
* Copyright (c) 2018-2019 Intel Corporation. All Rights Reserved.
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
#ifndef _PSYS_FORMAT_UTILS_H_
#define _PSYS_FORMAT_UTILS_H_


#include <ia_css_program_group_data_defs.h>
#include <ia_tools/css_types.h>
#ifdef __cplusplus
extern "C" {
#endif


/* Get css frame format type for fourcc */
css_err_t fourcc_to_css_frame_format(const uint32_t fourcc,
    ia_css_frame_format_type_t *css_frame_format_out,
    bool *raw_bayer_out,
    bool *packed_out);

#ifdef __cplusplus
}
#endif

#endif
