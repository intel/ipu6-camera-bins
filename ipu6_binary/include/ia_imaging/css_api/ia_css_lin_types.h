/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2010 - 2017 Intel Corporation.
 * All Rights Reserved.
 *
 * The source code contained or described herein and all documents
 * related to the source code ("Material") are owned by Intel Corporation
 * or licensors. Title to the Material remains with Intel
 * Corporation or its licensors. The Material contains trade
 * secrets and proprietary and confidential information of Intel or its
 * licensors. The Material is protected by worldwide copyright
 * and trade secret laws and treaty provisions. No part of the Material may
 * be used, copied, reproduced, modified, published, uploaded, posted,
 * transmitted, distributed, or disclosed in any way without Intel's prior
 * express written permission.
 *
 * No License under any patent, copyright, trade secret or other intellectual
 * property right is granted to or conferred upon you by disclosure or
 * delivery of the Materials, either expressly, by implication, inducement,
 * estoppel or otherwise. Any license under such intellectual property rights
 * must be express and approved by Intel in writing.
 */

#ifndef _LIN_PUBLIC_H_
#define _LIN_PUBLIC_H_

/** @file
* CSS-API header file for 2500/Skycam linearization lookup (LIN) kernel.
*/

/** Linearization lookup table size. The number of piecewise linear segments is
 * one less than the table size. */
#define LIN_TABLE_SIZE 65

/** Number of piecewise linear segments */
#define LIN_SEGMENTS    (LIN_TABLE_SIZE - 1)

struct ia_css_2500_lin_kernel_config
{
	short curve_lut_GR[LIN_TABLE_SIZE];
	short curve_lut_R[LIN_TABLE_SIZE];
	short curve_lut_B[LIN_TABLE_SIZE];
	short curve_lut_GB[LIN_TABLE_SIZE];
};


#endif // _LIN_PUBLIC_H_
