/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2017 - 2017 Intel Corporation.
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

#ifndef __ADI_OFS_TYPES_H
#define __ADI_OFS_TYPES_H

#include "ipu_device_ofs_devices.h"
#include "type_support.h"

struct adi_ofs_pin_dma_resource_id {
	unsigned dma_dev_chn_id;
	unsigned req_bank_id;
	unsigned unit_descr_id;
	unsigned channel_descr_id;
	unsigned spanA_descr_id;
	unsigned spanB_descr_id;
	unsigned terminalA_descr_id;
	unsigned terminalB_descr_id;
};

struct adi_ofs_of_pin_config {
	unsigned enable;
	unsigned format;
	unsigned tiling;
	unsigned scaled;
	unsigned output_width;
	unsigned output_height;
	uint32_t tvmem_out_buf_addr;
	struct adi_ofs_pin_dma_resource_id pin_dma;
};

struct adi_ofs_config {
	unsigned descriptor_rpwc;
	unsigned ofa_control;
	struct adi_ofs_of_pin_config pin_config;
};

#endif /* __ADI_OFS_TYPES_H */
