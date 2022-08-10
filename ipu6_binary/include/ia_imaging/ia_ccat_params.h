/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2021 Intel Corporation
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
 * \file ia_ccat_params.h
 * \brief Definitions of CCAT constants.
*/

#ifndef CCAT_PARAMS_H_
#define CCAT_PARAMS_H_

#ifdef __cplusplus
extern "C" {
#endif

#define MANUAL_CONVERGENCE_TIME_GRANULARITY 0.01f
#define TIMED_TRIMMED_FILTER_SIZE 34
#define DEFAULT_MODULE_ISO 100
#define MAX_IR_WEIGHT_GRID_SIZE 480u /* Max IR weight grid size = ir_width x ir_height*/
#define MAX_NUM_SECTORS 36u
#define MAX_NUM_IR_WEIGHT_GRIDS 30u
#define PI_2 1.57079f
#define IA_AEC_FLASHES_NUM 2
#define MAX_NUM_PERCENTILES 20

#define MIN_LUMINANCE_SATURATED_TARGET 92
#define MIN_LUMINANCE_BRIGHT_TARGET 50
#define LUMINANCE_BASED_MOTION_THRESHOLD 8

#ifdef __cplusplus
}
#endif

#endif /* CCAT_PARAMS_H_ */