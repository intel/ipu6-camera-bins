/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2019 - 2020 Intel Corporation.
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

#ifndef __IPU_DEVICE_CIO2STR_PROPERTIES_IMPL_H
#define __IPU_DEVICE_CIO2STR_PROPERTIES_IMPL_H

#include "ipu_device_cio2str_devices.h"
#include "ipu_device_cio2str_properties_defs.h"
#include "ipu_device_cio2str_properties_storage_class.h"
#include "ipu_device_cio2str_properties_struct.h"
#include <cio2stream_defs.h> /* for _CIO2STR_MAX_CIO_IN_WIDTH */

CIO2STR_PROPERTIES_DATA_STORAGE_CLASS_C struct ipu_device_cio2str_properties_s
ipu_device_cio2str_properties[IPU_DEVICE_CIO2STR_NUM_DEVS] = {
	{/*CIO2STR PAF*/
		IPU_DEVICE_CIO2STR_PAF_SP_CIO2STR_ADDR,
		IPU_DEVICE_CIO2STR_PAF_DMA_ISL_CIO2STR_ADDR,
		_CIO2STR_MAX_CIO_IN_WIDTH
	},
	{/* CIO2STR High*/
		IPU_DEVICE_CIO2STR_SP_CIO2STR_ADDR,
		IPU_DEVICE_CIO2STR_DMA_ISL_CIO2STR_ADDR,
		_CIO2STR_MAX_CIO_IN_WIDTH
	},
};
#endif /* __IPU_DEVICE_CIO2STR_PROPERTIES_IMPL_H */
