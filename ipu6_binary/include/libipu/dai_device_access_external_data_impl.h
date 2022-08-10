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

#ifndef HOST_DAI_DEVICE_ACCESS_EXTERNAL_DATA_IMPL_H_
#define HOST_DAI_DEVICE_ACCESS_EXTERNAL_DATA_IMPL_H_

#include <dai/dai_assert.h>
#include <dai/dai_system.h>

#include <vied/vied_subsystem_access.h>

/* Simple device access */
_DAI_DEVICE_ACCESS_INLINE
void dai_external_data_store_8(const dai_device_route_t *route,
			       dai_address_t address, uint8_t data)
{
	dai_device_store_8(route, address, data);
}

_DAI_DEVICE_ACCESS_INLINE
void dai_external_data_store_16(const dai_device_route_t *route,
				dai_address_t address, uint16_t data)
{
	dai_device_store_16(route, address, data);
}

_DAI_DEVICE_ACCESS_INLINE
void dai_external_data_store_32(const dai_device_route_t *route,
				dai_address_t address, uint32_t data)
{
	dai_device_store_32(route, address, data);
}

_DAI_DEVICE_ACCESS_INLINE
void dai_external_data_store(const dai_device_route_t *route,
			     dai_address_t address,
			     const void *data, unsigned int size)
{
	dai_device_store(route, address, data, size);
}

_DAI_DEVICE_ACCESS_INLINE
uint8_t dai_external_data_load_8(const dai_device_route_t *route,
				 dai_address_t address)
{
	return dai_device_load_8(route, address);
}

_DAI_DEVICE_ACCESS_INLINE
uint16_t dai_external_data_load_16(const dai_device_route_t *route,
				   dai_address_t address)
{
	return dai_device_load_16(route, address);
}

_DAI_DEVICE_ACCESS_INLINE
uint32_t dai_external_data_load_32(const dai_device_route_t *route,
				   dai_address_t address)
{
	return dai_device_load_32(route, address);
}

_DAI_DEVICE_ACCESS_INLINE
void dai_external_data_load(const dai_device_route_t *route,
			    dai_address_t address,
			    void *data, unsigned int size)
{
	return dai_device_load(route, address, data, size);
}

/* Device register access */
_DAI_DEVICE_ACCESS_INLINE
void dai_external_data_reg_bank_store_32(const dai_device_route_t *route,
					 dai_device_regbank_id_t bank, int bank_index,
					 dai_device_reg_id_t reg, uint32_t data)
{
	dai_device_reg_bank_store_32(route, bank, bank_index, reg, data);
}

_DAI_DEVICE_ACCESS_INLINE
uint32_t dai_external_data_reg_bank_load_32(const dai_device_route_t *route,
					    dai_device_regbank_id_t bank, int bank_index,
					    dai_device_reg_id_t reg)
{
	return dai_device_reg_bank_load_32(route, bank, bank_index, reg);
}

_DAI_DEVICE_ACCESS_INLINE
void dai_external_data_reg_store_32(const dai_device_route_t *route,
				    dai_device_reg_id_t reg, uint32_t data)
{
	dai_device_reg_store_32(route, reg, data);
}

_DAI_DEVICE_ACCESS_INLINE
uint32_t dai_external_data_reg_load_32(const dai_device_route_t *route,
				       dai_device_reg_id_t reg)
{
	return dai_device_reg_load_32(route, reg);
}

/* Device memory access */
_DAI_DEVICE_ACCESS_INLINE
void dai_external_data_mem_store_8(const dai_device_route_t *route,
				   dai_device_memory_id_t mem, dai_address_t mem_addr,
				   uint8_t data)
{
	dai_device_mem_store_8(route, mem, mem_addr, data);
}

_DAI_DEVICE_ACCESS_INLINE void
dai_external_data_mem_store_16(const dai_device_route_t *route,
			       dai_device_memory_id_t mem, dai_address_t mem_addr,
			       uint16_t data)
{
	dai_device_mem_store_16(route, mem, mem_addr, data);
}

_DAI_DEVICE_ACCESS_INLINE void
dai_external_data_mem_store_32(const dai_device_route_t *route,
			       dai_device_memory_id_t mem, dai_address_t mem_addr,
			       uint32_t data)
{
	dai_device_mem_store_32(route, mem, mem_addr, data);
}

_DAI_DEVICE_ACCESS_INLINE void
dai_external_data_mem_store(const dai_device_route_t *route,
			    dai_device_memory_id_t mem, dai_address_t mem_addr,
			    const void *data, unsigned int size)
{
	dai_device_mem_store(route, mem, mem_addr, data, size);
}

_DAI_DEVICE_ACCESS_INLINE uint8_t
dai_external_data_mem_load_8(const dai_device_route_t *route,
			     dai_device_memory_id_t mem, dai_address_t mem_addr)
{
	return dai_device_mem_load_8(route, mem, mem_addr);
}

_DAI_DEVICE_ACCESS_INLINE uint16_t
dai_external_data_mem_load_16(const dai_device_route_t *route,
			      dai_device_memory_id_t mem, dai_address_t mem_addr)
{
	return dai_device_mem_load_16(route, mem, mem_addr);
}

_DAI_DEVICE_ACCESS_INLINE uint32_t
dai_external_data_mem_load_32(const dai_device_route_t *route,
			      dai_device_memory_id_t mem, dai_address_t mem_addr)
{
	return dai_device_mem_load_32(route, mem, mem_addr);
}

_DAI_DEVICE_ACCESS_INLINE void
dai_external_data_mem_load(const dai_device_route_t *route,
			   dai_device_memory_id_t mem, dai_address_t mem_addr,
			   void *data, unsigned int size)
{
	dai_device_mem_load(route, mem, mem_addr, data, size);
}

#endif  /* HOST_DAI_DEVICE_ACCESS_EXTERNAL_DATA_IMPL_H_ */
