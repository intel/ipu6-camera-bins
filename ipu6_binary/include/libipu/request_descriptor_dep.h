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

#ifndef __REQUEST_DESCRIPTOR_DEP_H
#define __REQUEST_DESCRIPTOR_DEP_H

#include "storage_class.h"
#include "assert_support.h"
#include "type_support.h"
#include "ipu_device_dma_properties.h"

#include "vied_nci_dma_trace.h"
#include "vied_nci_dma_types_dep.h"

#define NCI_DMA_INVALIDATE_RESERVED_BITS     5

STORAGE_CLASS_INLINE uint32_t nci_dma_create_execute_instruction(
	const enum nci_dma_device_id dev_id,
	const enum nci_dma_command command,
	const uint32_t macro_size)
{
	uint32_t instruction;

	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);
	assert(1 <= macro_size);
	assert(macro_size <= ipu_device_dma_max_macro_size(dev_id));
	instruction = bit_slice(macro_size - 1, 0, ipu_device_dma_macro_size_bits(dev_id));
	instruction = bit_lshift_OR(instruction, 13, 0);
	instruction = bit_lshift_OR(instruction, NCI_DMA_EXECUTION_INVAL_MODIFIER_BITS, 0);
	instruction = bit_lshift_OR(instruction, NCI_DMA_EXECUTION_COMMAND_BITS, command);
	instruction = bit_lshift_OR(instruction, NCI_DMA_EXECUTION_FORMAT_BITS, NCI_DMA_REQUEST_EXECUTION_FORMAT);
	return instruction;
}

STORAGE_CLASS_INLINE uint32_t nci_dma_create_slim_next_instruction(
	const enum nci_dma_device_id dev_id,
	const enum nci_dma_command command,
	const uint32_t macro_size,
	const uint32_t chan_id)
{
	uint32_t instruction;
	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);
	assert(N_NCI_DMA_COMMAND > (unsigned int)command);
	assert(1 <= macro_size);
	assert(macro_size <= ipu_device_dma_max_macro_size(dev_id));
	/* To check if chan_id value can be encoded within the channel bit depth limits */
	assert(chan_id == bit_slice(chan_id, 0, ipu_device_dma_channels_bits(dev_id)));
	instruction = bit_slice(macro_size - 1, 0, ipu_device_dma_macro_size_bits(dev_id));
	instruction = bit_lshift_OR(instruction, NCI_DMA_RESERVED_BITS_INSTRUCTION, 0);
	instruction = bit_lshift_OR(instruction, NCI_DMA_CHANNEL_ID_BITS_INSTRUCTION, chan_id);
	instruction = bit_lshift_OR(instruction, NCI_DMA_EXECUTION_TYPE_BITS, NCI_DMA_EXECUTION_TYPE_SLIM_NEXT);
	instruction = bit_lshift_OR(instruction, NCI_DMA_EXECUTION_COMMAND_BITS, command);
	instruction = bit_lshift_OR(instruction, NCI_DMA_EXECUTION_FORMAT_BITS, NCI_DMA_REQUEST_EXECUTION_FORMAT);
	return instruction;
}

STORAGE_CLASS_INLINE uint32_t nci_dma_create_fast_1d_instruction(
	const enum nci_dma_device_id dev_id,
	const enum nci_dma_command command,
	const uint32_t unit_width,
	const uint32_t chan_id)
{
	uint32_t instruction;

	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);
	assert(N_NCI_DMA_COMMAND > (unsigned int)command);
	assert((unsigned int)unit_width < NCI_DMA_MAX_ELEMENTS_FAST_1D);
	/* To check if unit_width value can be encoded within the unit width bit depth limits */
	assert(unit_width == bit_slice(unit_width, 0, ipu_device_dma_unit_width_bits(dev_id)));
	/* To check if chan_id value can be encoded within the channel bit depth limits */
	assert(chan_id == bit_slice(chan_id, 0, ipu_device_dma_channels_bits(dev_id)));
	instruction = bit_slice(unit_width, 0, NCI_DMA_UNIT_WIDTH_BITS_INSTRUCTION);
	instruction = bit_lshift_OR(instruction, NCI_DMA_CHANNEL_ID_BITS_INSTRUCTION, chan_id);
	instruction = bit_lshift_OR(instruction, NCI_DMA_EXECUTION_TYPE_BITS, NCI_DMA_EXECUTION_TYPE_FAST_1D);
	instruction = bit_lshift_OR(instruction, NCI_DMA_EXECUTION_COMMAND_BITS, command);
	instruction = bit_lshift_OR(instruction, NCI_DMA_EXECUTION_FORMAT_BITS, NCI_DMA_REQUEST_EXECUTION_FORMAT);
	return instruction;
}

STORAGE_CLASS_INLINE uint32_t nci_dma_create_invalidate_instruction(
	const uint32_t dev_id,
	const enum nci_dma_descriptor_kind descriptor_kind,
	const uint32_t lower_id,
	const uint32_t upper_id)
{
	uint32_t instruction;

	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);

	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);
	assert((uint32_t)(1 << ipu_device_dma_descriptor_id_bits(dev_id)) > upper_id);
	assert((uint32_t)(1 << ipu_device_dma_descriptor_id_bits(dev_id)) > lower_id);
	assert((1 << NCI_DMA_DESCRIPTOR_KIND_BITS) > descriptor_kind);
	assert((1 << NCI_DMA_EXECUTION_FORMAT_BITS) > NCI_DMA_REQUEST_INVALIDATION_FORMAT);
	/* TODO: Optimize for the new fixed-format instruction scheme */
	instruction = upper_id;
	instruction <<= ipu_device_dma_descriptor_id_bits(dev_id);
	instruction |= lower_id;
	instruction <<= NCI_DMA_INVALIDATE_RESERVED_BITS;
	instruction <<= NCI_DMA_DESCRIPTOR_KIND_BITS;
	instruction |= descriptor_kind;
	instruction <<= NCI_DMA_EXECUTION_FORMAT_BITS;
	instruction |= NCI_DMA_REQUEST_INVALIDATION_FORMAT;

	return instruction;
}

STORAGE_CLASS_INLINE uint32_t nci_dma_descriptor_id_setup_1(
	const enum nci_dma_device_id dev_id,
	const uint32_t unit_id,
	const uint32_t terminal_a_id,
	const uint32_t terminal_b_id,
	const uint32_t channel_id)
{
	uint32_t field;

	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);

	field = bit_slice(channel_id, 0, ipu_device_dma_channels_bits(dev_id));
	field = bit_lshift_OR(field, ipu_device_dma_terminal_bits(dev_id), terminal_b_id);
	field = bit_lshift_OR(field, ipu_device_dma_terminal_bits(dev_id), terminal_a_id);
	field = bit_lshift_OR(field, ipu_device_dma_units_bits(dev_id), unit_id);

	return field;
}

STORAGE_CLASS_INLINE uint32_t nci_dma_descriptor_id_setup_2(
	const enum nci_dma_device_id dev_id,
	const uint32_t span_a_id,
	const uint32_t span_b_id)
{
	uint32_t field;

	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);

	field = bit_slice(span_b_id, 0, ipu_device_dma_spans_bits(dev_id));
	field = bit_lshift_OR(field, ipu_device_dma_spans_bits(dev_id), span_a_id);

	return field;
}

#endif /* __REQUEST_DESCRIPTOR_DEP_H */
