/**
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

#ifndef __IPU_DEVICE_BUTTRESS_PROPERTIES_FUNC_H
#define __IPU_DEVICE_BUTTRESS_PROPERTIES_FUNC_H


#include "storage_class.h"
#include "type_support.h"
#include "assert_support.h"
#include "ipu_device_buttress_properties_struct.h"

#define IPU_DEVICE_BUTTRESS_STREAM2GEN_NUMBER_OF_SETS 4
#define IPU_DEVICE_BUTTRESS_REG_SIZE 4 /* Bytes */

STORAGE_CLASS_INLINE unsigned int
ipu_device_buttress_stream2gen_hptr_reg_addr(const unsigned int set_number)
{
	assert(set_number < IPU_DEVICE_BUTTRESS_STREAM2GEN_NUMBER_OF_SETS);

	return IPU_DEVICE_BUTTRESS_STREAM2GEN_HPTR_SET0 +
			(set_number * IPU_DEVICE_BUTTRESS_REG_SIZE);
}

STORAGE_CLASS_INLINE unsigned int
ipu_device_buttress_stream2gen_tptr_reg_addr(const unsigned int set_number)
{
	assert(set_number < IPU_DEVICE_BUTTRESS_STREAM2GEN_NUMBER_OF_SETS);

	return IPU_DEVICE_BUTTRESS_STREAM2GEN_TPTR_SET0 +
			(set_number * IPU_DEVICE_BUTTRESS_REG_SIZE);
}

STORAGE_CLASS_INLINE unsigned int
ipu_device_buttress_stream2gen_sync_reg_addr(const unsigned int set_number)
{
	assert(set_number < IPU_DEVICE_BUTTRESS_STREAM2GEN_NUMBER_OF_SETS);

	return IPU_DEVICE_BUTTRESS_STREAM2GEN_SYNC_SET0 +
			(set_number * IPU_DEVICE_BUTTRESS_REG_SIZE);
}

STORAGE_CLASS_INLINE unsigned int
ipu_device_buttress_stream2gen_consumer_sync_addr_reg_addr(const unsigned int set_number)
{
	assert(set_number < IPU_DEVICE_BUTTRESS_STREAM2GEN_NUMBER_OF_SETS);

	return IPU_DEVICE_BUTTRESS_STREAM2GEN_CONSUMER_SYNC_ADDR_SET0 +
			(set_number * IPU_DEVICE_BUTTRESS_REG_SIZE);
}

STORAGE_CLASS_INLINE unsigned int
ipu_device_buttress_stream2gen_consumer_tptr_addr_reg_addr(const unsigned int set_number)
{
	assert(set_number < IPU_DEVICE_BUTTRESS_STREAM2GEN_NUMBER_OF_SETS);

	return IPU_DEVICE_BUTTRESS_STREAM2GEN_CONSUMER_TPTR_ADDR_SET0 +
			(set_number * IPU_DEVICE_BUTTRESS_REG_SIZE);
}

STORAGE_CLASS_INLINE unsigned int
ipu_device_buttress_stream2gen_producer_hptr_addr_reg_addr(const unsigned int set_number)
{
	assert(set_number < IPU_DEVICE_BUTTRESS_STREAM2GEN_NUMBER_OF_SETS);

	return IPU_DEVICE_BUTTRESS_STREAM2GEN_PRODUCER_HPTR_ADDR_SET0 +
			(set_number * IPU_DEVICE_BUTTRESS_REG_SIZE);
}

STORAGE_CLASS_INLINE unsigned int
ipu_device_buttress_stream2gen_str_ifc_cfg_reg_addr(void)
{
	return IPU_DEVICE_BUTTRESS_STREAM2GEN_STR_IFC_CFG;
}


#endif /* __IPU_DEVICE_BUTTRESS_PROPERTIES_FUNC_H */
