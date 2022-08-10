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

#ifndef __IA_CSS_SC_TNR_TYPES_H
#define __IA_CSS_SC_TNR_TYPES_H

/** @file
* CSS-API header file for 2500/Skycam Temporal Noise Reduction (TNR) kernel/accelerator.
*/

/** Temporal Noise Reduction (TNR) configuration.
 *
 *  When difference between current frame and previous frame is less than or
 *  equal to threshold, TNR works and current frame is mixed
 *  with previous frame.
 *  When difference between current frame and previous frame is greater
 *  than threshold, we judge motion is detected. Then, TNR does not work and
 *  current frame is outputted as it is.
 *  Therefore, when threshold_y and threshold_uv are set as 0, TNR can be disabled.
 *
 *  ISP block: TNR1
 *  ISP1: TNR1 is used.
 *  ISP2: TNR1 is used.
 */
struct ia_css_2500_tnr_kernel_config {
	unsigned short sensegain_y;
	unsigned short sensegain_u;
	unsigned short sensegain_v;
};

#endif /* __IA_CSS_SC_TNR_TYPES_H */

