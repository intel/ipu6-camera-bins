/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2018 - 2019 Intel Corporation.
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
#ifndef __DEC400_OFS_OUT_CONTROL_INIT_DEFS_H
#define __DEC400_OFS_OUT_CONTROL_INIT_DEFS_H

#include "nci_dec400_vpless_defs.h"
#include "dec400_ofs_config.h"
#include "nci_mmu_stream_id.h"

#if HAS_DEC400 == 1
#define DEC400_OFS_OUT_NUMBER_OF_CONNECT_SECTIONS (DEC400_OFS_OUT_NUMBER_OF_STREAMS * NCI_DEC400_FILL_CONNECT_SECTION_NOF)
#else
#define DEC400_OFS_OUT_NUMBER_OF_CONNECT_SECTIONS 0
#endif

#endif /* __DEC400_OFS_OUT_CONTROL_INIT_DEFS_H */

