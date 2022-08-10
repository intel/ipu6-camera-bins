/**
* INTEL CONFIDENTIAL
*
* Copyright (C) 2015 - 2016 Intel Corporation.
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

#ifndef __IPU_DEVICE_GP_PROPERTIES_H
#define __IPU_DEVICE_GP_PROPERTIES_H

#include "storage_class.h"
#include "ipu_device_gp_properties_types.h"

STORAGE_CLASS_INLINE unsigned int
ipu_device_gp_mux_addr(const unsigned int device_id, const unsigned int mux_id);

#include "ipu_device_gp_properties_func.h"

#endif /* __IPU_DEVICE_GP_PROPERTIES_H */
