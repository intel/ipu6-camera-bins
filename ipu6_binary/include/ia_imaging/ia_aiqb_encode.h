/*
* INTEL CONFIDENTIAL
* Copyright (c) 2016-2017 Intel Corporation
* All Rights Reserved.
*
* The source code contained or described herein and all documents related to
* the source code ("Material") are owned by Intel Corporation or its
* suppliers or licensors. Title to the Material remains with Intel
* Corporation or its suppliers and licensors. The Material may contain trade
* secrets and proprietary and confidential information of Intel Corporation
* and its suppliers and licensors, and is protected by worldwide copyright
* and trade secret laws and treaty provisions. No part of the Material may be
* used, copied, reproduced, modified, published, uploaded, posted,
* transmitted, distributed, or disclosed in any way without Intel's prior
* express written permission.
*
* No license under any patent, copyright, trade secret or other intellectual
* property right is granted to or conferred upon you by disclosure or
* delivery of the Materials, either expressly, by implication, inducement,
* estoppel or otherwise. Any license under such intellectual property rights
* must be express and approved by Intel in writing.
*
* Unless otherwise agreed by Intel in writing, you may not remove or alter
* this notice or any other notice embedded in Materials by Intel or Intels
* suppliers or licensors in any way.
*/

/*!
 * \file ia_aiqb_encode.h
 * \brief Helper functtions to encode records into AIQB.
 */


#ifndef IA_AIQB_ENCODE_H_
#define IA_AIQB_ENCODE_H_

#include "ia_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_NUM_MAPS 20
typedef struct
{
    ia_aiqd_parser_offset_map offset_maps[MAX_NUM_MAPS];
    ia_aiqd_parser_maps_info maps_info;
} pointer_map;

/*!
 * \brief Copies data from source data pointer to target data pointer and updates pointer address
 * param[in]     data_end     End address of output buffer. Used to make sure that data is not copied beyond allocated memory.
 * param[in]     data_input   Input buffer to copy.
 * param[in]     data_size    Size of data to copy.
 * param[in/out] data_current Target data pointer (where to copy data).
 * param[in/out] data_target  Target address pointer (where to update address of copied data).
 */
ia_err memory_assign_and_copy(
    const char *data_end,
    const void *data_input,
    size_t data_size,
    char **data_current,
    char **data_target);

ia_err update_pointer_map(
    const char *data_start,
    const char *pointer_to_pointer,
    const char *pointer_to_data,
    pointer_map *maps);

ia_err append_pointer_map(
    char *data_start,
    char *data_end,
    pointer_map *maps,
    char **data_current);

#ifdef __cplusplus
}
#endif

#endif /* IA_AIQB_ENCODE_H_ */
