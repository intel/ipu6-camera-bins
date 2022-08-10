/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2014-2016 Intel Corporation
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
 * transmitted, distributed, or disclosed in any way without Intela?s prior
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

#ifndef _IA_ME_CORNER_TYPES_H_
#define _IA_ME_CORNER_TYPES_H_

#include "internal_types.h"
#include "dvs_stat_public.h"

#define NUM_OF_LEVELS 3
#define NUM_OF_MV_ENTRIES 200

typedef struct me_corner_tuning_t
{
    float grid_size_perc[NUM_OF_LEVELS];
    float feroi_size_perc[NUM_OF_LEVELS];
} me_corner_tuning_t;

typedef struct ia_me_corner_t
{
    me_corner_tuning_t tuning_settings;
    /*struct dvs_stat_mv_entry_public dvs_stat_mv[NUM_OF_LEVELS][NUM_OF_MV_ENTRIES];*/
    /*struct dvs_stat_public_config dvs_stat_config;*/
    struct ia_css_dvs_stat_grid_info calculated_stat_config;
    ia_dvs_statistics generic_statistics;
    ia_dvs_bq_resolution isp_resolution;
    float unit_length;
} ia_me_corner_t;

#endif /* _IA_ME_CORNER_TYPES_H_ */
