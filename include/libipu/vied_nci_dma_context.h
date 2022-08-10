/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2016 - 2018 Intel Corporation.
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

#ifndef __VIED_NCI_DMA_CONTEXT_H
#define __VIED_NCI_DMA_CONTEXT_H

#include "type_support.h"
#include "storage_class.h"
#include "assert_support.h"
#include "vied_nci_dma_types.h"
#include "vied_nci_dma_trace.h"
#include "vied_nci_dma_descriptor_ids.h"
#include "ipu_device_dma_devices.h"
#include "ipu_device_dma_properties_func.h"

enum nci_dma_context_descriptor_type {
	NCI_DMA_CONTEXT_DESCRIPTOR_CHANNEL,
	NCI_DMA_CONTEXT_DESCRIPTOR_TERMINAL,
	NCI_DMA_CONTEXT_DESCRIPTOR_UNIT,
	NCI_DMA_CONTEXT_DESCRIPTOR_SPAN,
	NCI_DMA_CONTEXT_DESCRIPTOR_CMEM_BASE
};
#define N_NCI_DMA_CONTEXT_DESCRIPTOR_TYPE 5

extern struct nci_dma_dev dma_dev[NCI_DMA_NUM_DEVICES];

STORAGE_CLASS_INLINE struct nci_dma_dev *nci_dma_get_dev_ptr(
	const enum nci_dma_device_id dev_id)
{
	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);
	IA_CSS_TRACE_2(NCI_DMA, DEBUG, "nci_dma_get_dev_ptr: dev_id %d return 0x%016lx\n",
		dev_id, (unsigned long)&dma_dev[dev_id]);
	return &dma_dev[dev_id];
}

STORAGE_CLASS_INLINE struct nci_dma_chan *nci_dma_get_chan_ptr_cached(
	const enum nci_dma_device_id dev_id,
	const uint32_t chan_id)
{
	uint32_t per_mode_channel_id = vied_nci_dma_get_per_mode_channel_id(dev_id, chan_id, NCI_DMA_BANK_MODE_CACHED);

	IA_CSS_TRACE_2(NCI_DMA, DEBUG, "nci_dma_get_chan_ptr_cached: dev_id %d chan_id %d\n", dev_id, chan_id);
	IA_CSS_TRACE_1(NCI_DMA, DEBUG, "ipu_device_dma_channel_banks(dev_id) %d\n",
		ipu_device_dma_channel_banks(dev_id));
	IA_CSS_TRACE_1(NCI_DMA, DEBUG, "ipu_device_dma_channels(dev_id) %d\n", ipu_device_dma_channels(dev_id));

	/* assert(ipu_device_dma_channel_banks(dev_id) <= (unsigned int)chan_id); */
	/* assert(ipu_device_dma_channels(dev_id) > (unsigned int)chan_id); */

	IA_CSS_TRACE_1(NCI_DMA, DEBUG, "nci_dma_get_chan_ptr: returning &dma_dev[dev_id].chans[%d]\n", per_mode_channel_id);
	return &dma_dev[dev_id].chans[per_mode_channel_id];
}

STORAGE_CLASS_INLINE struct nci_dma_chan *nci_dma_get_chan_ptr_non_cached(
	const enum nci_dma_device_id dev_id,
	const uint32_t chan_id)
{
	uint32_t per_mode_channel_id = vied_nci_dma_get_per_mode_channel_id(dev_id, chan_id, NCI_DMA_BANK_MODE_NON_CACHED);

	IA_CSS_TRACE_2(NCI_DMA, DEBUG, "nci_dma_get_chan_ptr_non_cached: dev_id %d chan_id %d\n", dev_id, chan_id);

	assert(ipu_device_dma_channel_banks(dev_id) > (unsigned int)chan_id);

	return &dma_dev[dev_id].chans[per_mode_channel_id];
}

STORAGE_CLASS_INLINE struct nci_dma_chan *nci_dma_get_chan_ptr(
	const enum nci_dma_device_id dev_id,
	const uint32_t chan_id)
{
	IA_CSS_TRACE_2(NCI_DMA, DEBUG, "nci_dma_get_chan_ptr: dev_id %d chan_id %d\n", dev_id, chan_id);

	assert(NULL != dma_dev[dev_id].chans);

	if (NCI_DMA_BANK_MODE_CACHED == dma_dev[dev_id].bank_mode) {
		return nci_dma_get_chan_ptr_cached(dev_id, chan_id);
	} else {
		return nci_dma_get_chan_ptr_non_cached(dev_id, chan_id);
	}
}

STORAGE_CLASS_INLINE enum nci_dma_device_id nci_dma_get_dev_id(
	const enum nci_dma_device_id dev_id)
{
	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);
	IA_CSS_TRACE_2(NCI_DMA, DEBUG, "nci_dma_get_dev_id: dev_id %d return %d\n", dev_id, dma_dev[dev_id].dev_id);
	return dma_dev[dev_id].dev_id;
}

STORAGE_CLASS_INLINE void nci_dma_set_dev_id(
	const enum nci_dma_device_id dev_id,
	const uint32_t value)
{
	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);
	dma_dev[dev_id].dev_id = (enum nci_dma_device_id)value;
	IA_CSS_TRACE_2(NCI_DMA, DEBUG, "nci_dma_set_dev_id: dev_id %d return %d\n", dev_id, dma_dev[dev_id].dev_id);
}

STORAGE_CLASS_INLINE uint32_t nci_dma_get_chan_id(
	const enum nci_dma_device_id dev_id,
	const uint32_t chan_id)
{
	const struct nci_dma_chan * const chan = nci_dma_get_chan_ptr(dev_id, chan_id);

	assert(NULL != chan);
	IA_CSS_TRACE_3(NCI_DMA, DEBUG, "nci_dma_get_chan_id: dev_id %d chan_id %d value %d\n",
		dev_id, chan_id, chan->chan_id);
	return chan->chan_id;
}

STORAGE_CLASS_INLINE void nci_dma_set_chan_id(
	const enum nci_dma_device_id dev_id,
	const uint32_t chan_id,
	const uint32_t value)
{
	struct nci_dma_chan * const chan = nci_dma_get_chan_ptr(dev_id, chan_id);

	assert(NULL != chan);
	chan->chan_id = value;
	IA_CSS_TRACE_3(NCI_DMA, DEBUG, "nci_dma_set_chan_id: dev_id %d chan_id %d value %d\n",
		dev_id, chan_id, chan->chan_id);
}

STORAGE_CLASS_INLINE void nci_dma_get_dma_chan(
	const enum nci_dma_device_id dev_id,
	const uint32_t chan_id,
	struct nci_dma_chan *chan_out)
{
	const struct nci_dma_chan * const chan = nci_dma_get_chan_ptr(dev_id, chan_id);

	assert(NULL != chan);
	assert(NULL != chan_out);
	chan_out->dev_id = chan->dev_id;
	chan_out->chan_id = chan->chan_id;
	chan_out->requestor_id = chan->requestor_id;
	chan_out->request_descr.descriptor_id_setup_1 = chan->request_descr.descriptor_id_setup_1;
	chan_out->request_descr.descriptor_id_setup_2 = chan->request_descr.descriptor_id_setup_2;
#if NCI_DMA_TERMINAL_REPLACEMENT_POLICY_BITS == 0
	chan_out->invalidate_instruction_terminal_A_B = chan->invalidate_instruction_terminal_A_B;
	chan_out->invalidate_instruction_span_A_B = chan->invalidate_instruction_span_A_B;
	chan_out->invalidate_instruction_unit = chan->invalidate_instruction_unit;
#endif
	IA_CSS_TRACE_7(NCI_DMA, DEBUG,
		"nci_dma_get_dma_chan: dev_id %d chan_id %d values 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x\n",
		dev_id,
		chan_id,
		chan_out->dev_id,
		chan_out->chan_id,
		chan_out->requestor_id,
		chan_out->request_descr.descriptor_id_setup_1,
		chan_out->request_descr.descriptor_id_setup_2);
#if NCI_DMA_TERMINAL_REPLACEMENT_POLICY_BITS == 0
	IA_CSS_TRACE_3(NCI_DMA, DEBUG, "nci_dma_get_dma_chan: values 0x%08x 0x%08x 0x%08x\n",
		chan_out->invalidate_instruction_terminal_A_B,
		chan_out->invalidate_instruction_span_A_B,
		chan_out->invalidate_instruction_unit);
#endif
}

STORAGE_CLASS_INLINE void nci_dma_set_dma_chan(
	const enum nci_dma_device_id dev_id,
	const uint32_t chan_id,
	struct nci_dma_chan *chan_in)
{
	struct nci_dma_chan * const chan = nci_dma_get_chan_ptr(dev_id, chan_id);

	assert(NULL != chan);
	assert(NULL != chan_in);
	chan->dev_id = chan_in->dev_id;
	chan->chan_id = chan_in->chan_id;
	chan->requestor_id = chan->requestor_id;
	chan->request_descr.descriptor_id_setup_1 = chan_in->request_descr.descriptor_id_setup_1;
	chan->request_descr.descriptor_id_setup_2 = chan_in->request_descr.descriptor_id_setup_2;
#if NCI_DMA_TERMINAL_REPLACEMENT_POLICY_BITS == 0
	chan->invalidate_instruction_terminal_A_B = chan_in->invalidate_instruction_terminal_A_B;
	chan->invalidate_instruction_span_A_B = chan_in->invalidate_instruction_span_A_B;
	chan->invalidate_instruction_unit = chan_in->invalidate_instruction_unit;
#endif
	IA_CSS_TRACE_7(NCI_DMA, DEBUG,
		"nci_dma_set_dma_chan: dev_id %d chan_id %d values 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x\n",
		dev_id,
		chan_id,
		chan->dev_id,
		chan->chan_id,
		chan->requestor_id,
		chan->request_descr.descriptor_id_setup_1,
		chan->request_descr.descriptor_id_setup_2);
#if NCI_DMA_TERMINAL_REPLACEMENT_POLICY_BITS == 0
	IA_CSS_TRACE_3(NCI_DMA, DEBUG, "nci_dma_set_dma_chan: values 0x%08x 0x%08x 0x%08x\n",
		chan->invalidate_instruction_terminal_A_B,
		chan->invalidate_instruction_span_A_B,
		chan->invalidate_instruction_unit);
#endif
}

STORAGE_CLASS_INLINE enum nci_dma_requestor_id nci_dma_get_requestor_id_cached(
	const enum nci_dma_device_id dev_id,
	const uint32_t chan_id)
{
	uint32_t per_mode_channel_id = vied_nci_dma_get_per_mode_channel_id(dev_id, chan_id, NCI_DMA_BANK_MODE_CACHED);

	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);
	assert(NULL != dma_dev[dev_id].chans);
	/* Not true anymore for IPU6 */
	 /* assert(NCI_DMA_BANK_MODE_CACHED == dma_dev[dev_id].bank_mode &&
	  *	ipu_device_dma_channel_banks(dev_id) <= (unsigned int)chan_id &&
	  *	ipu_device_dma_channels(dev_id) > (unsigned int)chan_id);
	  */

	IA_CSS_TRACE_3(NCI_DMA, DEBUG, "nci_dma_get_requestor_id: dev_id %d chan_id %d value %d\n",
		dev_id, chan_id, dma_dev[dev_id].chans[per_mode_channel_id].requestor_id);
	return (enum nci_dma_requestor_id)dma_dev[dev_id].chans[per_mode_channel_id].requestor_id;
}

STORAGE_CLASS_INLINE enum nci_dma_requestor_id nci_dma_get_requestor_id_non_cached(
	const enum nci_dma_device_id dev_id,
	const uint32_t chan_id)
{
	uint32_t per_mode_channel_id = vied_nci_dma_get_per_mode_channel_id(dev_id, chan_id, NCI_DMA_BANK_MODE_NON_CACHED);

	IA_CSS_TRACE_2(NCI_DMA, DEBUG, "nci_dma_get_chan_ptr_non_cached: dev_id %d chan_id %d\n", dev_id, chan_id);

	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);
	assert(NULL != dma_dev[dev_id].chans);
	assert(NCI_DMA_BANK_MODE_NON_CACHED == dma_dev[dev_id].bank_mode &&
		ipu_device_dma_channel_banks(dev_id) > (unsigned int)chan_id);

	IA_CSS_TRACE_3(NCI_DMA, DEBUG, "nci_dma_get_requestor_id: dev_id %d chan_id %d value %d\n",
		dev_id, chan_id, dma_dev[dev_id].chans[chan_id].requestor_id);
	return (enum nci_dma_requestor_id)dma_dev[dev_id].chans[per_mode_channel_id].requestor_id;
}

STORAGE_CLASS_INLINE enum nci_dma_requestor_id nci_dma_get_requestor_id(
	const enum nci_dma_device_id dev_id,
	const uint32_t chan_id)
{
	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);
	assert(NULL != dma_dev[dev_id].chans);
	/* Not valid anymore for IPU6 */
	/* assert((NCI_DMA_BANK_MODE_NON_CACHED == dma_dev[dev_id].bank_mode &&
	 * ipu_device_dma_channel_banks(dev_id) > (unsigned int)chan_id) ||
	 * (NCI_DMA_BANK_MODE_CACHED == dma_dev[dev_id].bank_mode &&
	 * ipu_device_dma_channel_banks(dev_id) <= (unsigned int)chan_id &&
	 * ipu_device_dma_channels(dev_id) > (unsigned int)chan_id));
	 */

	if (NCI_DMA_BANK_MODE_CACHED == dma_dev[dev_id].bank_mode) {
		return nci_dma_get_requestor_id_cached(dev_id, chan_id);
	} else {
		return nci_dma_get_requestor_id_non_cached(dev_id, chan_id);
	}
}

STORAGE_CLASS_INLINE void nci_dma_set_requestor_id(
	const enum nci_dma_device_id dev_id,
	const uint32_t chan_id,
	const enum nci_dma_requestor_id requestor_id)
{
	struct nci_dma_chan * const chan = nci_dma_get_chan_ptr(dev_id, chan_id);

	assert(NULL != chan);
	chan->requestor_id = requestor_id;
	IA_CSS_TRACE_3(NCI_DMA, DEBUG, "nci_dma_set_requestor_id: dev_id %d chan_id %d value %d\n",
		dev_id, chan_id, chan->requestor_id);
}

STORAGE_CLASS_INLINE void nci_dma_get_request_descriptor(
	const enum nci_dma_device_id dev_id,
	const uint32_t chan_id,
	struct nci_dma_request_desc * const request_desc)
{
	const struct nci_dma_chan * const chan = nci_dma_get_chan_ptr(dev_id, chan_id);

	assert(NULL != chan);
	request_desc->descriptor_id_setup_1 = chan->request_descr.descriptor_id_setup_1;
	request_desc->descriptor_id_setup_2 = chan->request_descr.descriptor_id_setup_2;
	IA_CSS_TRACE_4(NCI_DMA, DEBUG, "nci_dma_get_request_descriptor: dev_id %d chan_id %d values 0x%08x 0x%08x\n",
		dev_id, chan_id,
		chan->request_descr.descriptor_id_setup_1, chan->request_descr.descriptor_id_setup_2);
}

STORAGE_CLASS_INLINE void nci_dma_set_request_descriptor(
	const enum nci_dma_device_id dev_id,
	const uint32_t chan_id,
	const struct nci_dma_request_desc * const request_descr)
{
	struct nci_dma_chan * const chan = nci_dma_get_chan_ptr(dev_id, chan_id);

	assert(NULL != chan);
	chan->request_descr.descriptor_id_setup_1 = request_descr->descriptor_id_setup_1;
	chan->request_descr.descriptor_id_setup_2 = request_descr->descriptor_id_setup_2;
	IA_CSS_TRACE_4(NCI_DMA, DEBUG, "nci_dma_set_request_descriptor: dev_id %d chan_id %d values 0x%08x 0x%08x\n",
		dev_id, chan_id,
		chan->request_descr.descriptor_id_setup_1, chan->request_descr.descriptor_id_setup_2);
}

STORAGE_CLASS_INLINE void nci_dma_get_descriptor_addresses(
	const enum nci_dma_device_id dev_id,
	struct nci_dma_descriptor_addresses * const descriptor_addresses)
{
	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);
	assert(NULL != descriptor_addresses);

	descriptor_addresses->channel_descriptor_offset =
		dma_dev[dev_id].descriptor_addresses.channel_descriptor_offset;
	descriptor_addresses->terminal_descriptor_offset =
		dma_dev[dev_id].descriptor_addresses.terminal_descriptor_offset;
	descriptor_addresses->unit_descriptor_offset =
		dma_dev[dev_id].descriptor_addresses.unit_descriptor_offset;
	descriptor_addresses->span_descriptor_offset =
		dma_dev[dev_id].descriptor_addresses.span_descriptor_offset;
	descriptor_addresses->cmem_descriptor_base_address =
		dma_dev[dev_id].descriptor_addresses.cmem_descriptor_base_address;
	IA_CSS_TRACE_6(NCI_DMA, DEBUG,
		"nci_dma_get_desc_base_addr: dev_id %d values 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x\n",
		dev_id,
		descriptor_addresses->channel_descriptor_offset,
		descriptor_addresses->terminal_descriptor_offset,
		descriptor_addresses->unit_descriptor_offset,
		descriptor_addresses->span_descriptor_offset,
		descriptor_addresses->cmem_descriptor_base_address);
}

STORAGE_CLASS_INLINE void nci_dma_set_descriptor_addresses(
	const enum nci_dma_device_id dev_id,
	const struct nci_dma_descriptor_addresses * const descriptor_addresses)
{
	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);
	assert(NULL != descriptor_addresses);

	dma_dev[dev_id].descriptor_addresses.channel_descriptor_offset =
		descriptor_addresses->channel_descriptor_offset;
	dma_dev[dev_id].descriptor_addresses.terminal_descriptor_offset =
		descriptor_addresses->terminal_descriptor_offset;
	dma_dev[dev_id].descriptor_addresses.unit_descriptor_offset =
		descriptor_addresses->unit_descriptor_offset;
	dma_dev[dev_id].descriptor_addresses.span_descriptor_offset =
		descriptor_addresses->span_descriptor_offset;
	dma_dev[dev_id].descriptor_addresses.cmem_descriptor_base_address =
		descriptor_addresses->cmem_descriptor_base_address;
	IA_CSS_TRACE_6(NCI_DMA, DEBUG,
		"nci_dma_set_desc_base_addr: dev_id %d values 0x%08x  0x%08x 0x%08x 0x%08x 0x%08x\n",
		dev_id,
		dma_dev[dev_id].descriptor_addresses.channel_descriptor_offset,
		dma_dev[dev_id].descriptor_addresses.terminal_descriptor_offset,
		dma_dev[dev_id].descriptor_addresses.unit_descriptor_offset,
		dma_dev[dev_id].descriptor_addresses.span_descriptor_offset,
		dma_dev[dev_id].descriptor_addresses.cmem_descriptor_base_address);
}

STORAGE_CLASS_INLINE uint32_t nci_dma_get_desc_base_addr(
	const enum nci_dma_device_id dev_id,
	const enum nci_dma_context_descriptor_type descriptor_type)
{
	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);
	assert(N_NCI_DMA_CONTEXT_DESCRIPTOR_TYPE > descriptor_type);
	if (NCI_DMA_CONTEXT_DESCRIPTOR_CHANNEL == descriptor_type) {
		IA_CSS_TRACE_3(NCI_DMA, DEBUG, "nci_dma_get_desc_base_addr: dev_id %d type %d value 0x%08x\n",
			dev_id, descriptor_type, dma_dev[dev_id].descriptor_addresses.channel_descriptor_offset);
		return dma_dev[dev_id].descriptor_addresses.channel_descriptor_offset;
	} else if (NCI_DMA_CONTEXT_DESCRIPTOR_TERMINAL == descriptor_type) {
		IA_CSS_TRACE_3(NCI_DMA, DEBUG, "nci_dma_get_desc_base_addr: dev_id %d type %d value 0x%08x\n",
			dev_id, descriptor_type, dma_dev[dev_id].descriptor_addresses.terminal_descriptor_offset);
		return dma_dev[dev_id].descriptor_addresses.terminal_descriptor_offset;
	} else if (NCI_DMA_CONTEXT_DESCRIPTOR_UNIT == descriptor_type) {
		IA_CSS_TRACE_3(NCI_DMA, DEBUG, "nci_dma_get_desc_base_addr: dev_id %d type %d value 0x%08x\n",
			dev_id, descriptor_type, dma_dev[dev_id].descriptor_addresses.unit_descriptor_offset);
		return dma_dev[dev_id].descriptor_addresses.unit_descriptor_offset;
	} else if (NCI_DMA_CONTEXT_DESCRIPTOR_SPAN == descriptor_type) {
		IA_CSS_TRACE_3(NCI_DMA, DEBUG, "nci_dma_get_desc_base_addr: dev_id %d type %d value 0x%08x\n",
			dev_id, descriptor_type, dma_dev[dev_id].descriptor_addresses.span_descriptor_offset);
		return dma_dev[dev_id].descriptor_addresses.span_descriptor_offset;
	} else if (NCI_DMA_CONTEXT_DESCRIPTOR_CMEM_BASE == descriptor_type) {
		IA_CSS_TRACE_3(NCI_DMA, DEBUG, "nci_dma_get_desc_base_addr: dev_id %d type %d value 0x%08x\n",
			dev_id, descriptor_type, dma_dev[dev_id].descriptor_addresses.cmem_descriptor_base_address);
		return dma_dev[dev_id].descriptor_addresses.cmem_descriptor_base_address;
	}
	IA_CSS_TRACE_2(NCI_DMA, ERROR, "nci_dma_get_desc_base_addr: dev_id %d descriptor_type %d\n",
			dev_id, descriptor_type);
	return 0xFFFFFFFF;
}

STORAGE_CLASS_INLINE void nci_dma_set_desc_base_addr(
	const enum nci_dma_device_id dev_id,
	const enum nci_dma_context_descriptor_type descriptor_type,
	const uint32_t addr)
{
	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);
	assert(N_NCI_DMA_CONTEXT_DESCRIPTOR_TYPE > descriptor_type);
	/* It would be nice to have address range check */
	if (NCI_DMA_CONTEXT_DESCRIPTOR_CHANNEL == descriptor_type) {
		dma_dev[dev_id].descriptor_addresses.channel_descriptor_offset = addr;
	} else if (NCI_DMA_CONTEXT_DESCRIPTOR_TERMINAL == descriptor_type) {
		dma_dev[dev_id].descriptor_addresses.terminal_descriptor_offset = addr;
	} else if (NCI_DMA_CONTEXT_DESCRIPTOR_UNIT == descriptor_type) {
		dma_dev[dev_id].descriptor_addresses.unit_descriptor_offset = addr;
	} else if (NCI_DMA_CONTEXT_DESCRIPTOR_SPAN == descriptor_type) {
		dma_dev[dev_id].descriptor_addresses.span_descriptor_offset = addr;
	} else if (NCI_DMA_CONTEXT_DESCRIPTOR_CMEM_BASE == descriptor_type) {
		dma_dev[dev_id].descriptor_addresses.cmem_descriptor_base_address = addr;
	}
	IA_CSS_TRACE_3(NCI_DMA, DEBUG, "nci_dma_set_desc_base_addr: dev_id %d descriptor_type %d value 0x%08x\n",
		dev_id, descriptor_type, addr);
}

STORAGE_CLASS_INLINE enum nci_dma_bank_mode nci_dma_get_bank_mode(
	const enum nci_dma_device_id dev_id)
{
	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);
	assert(N_NCI_DMA_BANK_MODE > (unsigned int)dma_dev[dev_id].bank_mode);
	IA_CSS_TRACE_2(NCI_DMA, DEBUG, "nci_dma_get_bank_mode: dev_id %d value 0x%08x\n", dev_id,
		dma_dev[dev_id].bank_mode);
	return dma_dev[dev_id].bank_mode;
}

STORAGE_CLASS_INLINE void nci_dma_set_bank_mode(
	const enum nci_dma_device_id dev_id,
	const enum nci_dma_bank_mode bank_mode)
{
	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);
	assert(N_NCI_DMA_BANK_MODE > (unsigned int)dma_dev[dev_id].bank_mode);
	IA_CSS_TRACE_2(NCI_DMA, DEBUG, "nci_dma_set_bank_mode: dev_id %d value 0x%08x\n", dev_id,
		dma_dev[dev_id].bank_mode);
	dma_dev[dev_id].bank_mode = bank_mode;
}

STORAGE_CLASS_INLINE enum nci_dma_request_type nci_dma_get_request_type(
	const enum nci_dma_device_id dev_id)
{
	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);
	assert(N_NCI_DMA_REQUEST_TYPE > (unsigned int)dma_dev[dev_id].request_type);
	IA_CSS_TRACE_2(NCI_DMA, DEBUG, "nci_dma_get_request_type: dev_id %d value 0x%08x\n", dev_id,
		dma_dev[dev_id].request_type);
	return dma_dev[dev_id].request_type;
}

STORAGE_CLASS_INLINE void nci_dma_set_request_type(
	const enum nci_dma_device_id dev_id,
	const enum nci_dma_request_type request_type)
{
	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);
	assert(N_NCI_DMA_REQUEST_TYPE > (unsigned int)dma_dev[dev_id].request_type);
	dma_dev[dev_id].request_type = request_type;
	IA_CSS_TRACE_2(NCI_DMA, DEBUG, "nci_dma_set_request_type: dev_id %d value 0x%08x\n", dev_id,
		dma_dev[dev_id].request_type);
}

STORAGE_CLASS_INLINE uint32_t nci_dma_get_num_of_reserved_channel_banks(
	const enum nci_dma_device_id dev_id)
{
	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);
	IA_CSS_TRACE_2(NCI_DMA, DEBUG, "nci_dma_get_num_of_reserved_channel_banks: dev_id %d value 0x%08x\n",
		dev_id, dma_dev[dev_id].num_of_reserved_channel_banks);
	return dma_dev[dev_id].num_of_reserved_channel_banks;
}

STORAGE_CLASS_INLINE void nci_dma_set_num_of_reserved_channel_banks(
	const enum nci_dma_device_id dev_id,
	const uint32_t reserved_channel_banks)
{
	assert(NCI_DMA_NUM_DEVICES > (unsigned int)dev_id);
	/* It would be nice to have reserved_channel_banks range check */
	dma_dev[dev_id].num_of_reserved_channel_banks = reserved_channel_banks;
	IA_CSS_TRACE_2(NCI_DMA, DEBUG, "nci_dma_set_num_of_reserved_channel_banks: dev_id %d value 0x%08x\n",
		dev_id, dma_dev[dev_id].num_of_reserved_channel_banks);
}

#endif /* __VIED_NCI_DMA_CONTEXT_H */
