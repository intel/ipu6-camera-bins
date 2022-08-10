/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2017 - 2018 Intel Corporation.
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

#ifndef __NCI_MBR_INLINE_LOCAL_H
#define __NCI_MBR_INLINE_LOCAL_H

#include "nci_mbr_storage_class.h"
#include "nci_mbr_types.h"

#include "type_support.h"
#include "misc_support.h"
#include "assert_support.h"
#include <ipu_device_subsystem_ids.h> /* for SSID values */
#include <dai/dai_device_access.h>
#include "dai_ipu_top_devices.h"
#include "ipu_device_mbr_devices.h"
#include "ia_css_kernel_user_param_instance_types.h"

#define NCI_MBR_MASK(val, bits)                       ((val) & ((1 << (bits)) -1))

/* activate_command:
 *
 *   [16]    |[15-14]|[13-12]|[11-10]|   [9-8]    |   [7]   |    [6-5]   |   [4-1]  |  [0]
 * Dev. Mode | Op. 2 | Op. 1 | Op. 0 | Proc. mode | *Buf ID | Channel ID | GOB size | Trigger
 */
#define NCI_MBR_ACTIVATE_COMMAND_REG_TRIGGER_BITS                 1
#define NCI_MBR_ACTIVATE_COMMAND_REG_GOB_SIZE_BITS                4
#define NCI_MBR_ACTIVATE_COMMAND_REG_CHAN_ID_BITS                 2
#define NCI_MBR_ACTIVATE_COMMAND_REG_BUF_ID_BITS                  1
#define NCI_MBR_ACTIVATE_COMMAND_REG_PROC_MODE_BITS               2
#define NCI_MBR_ACTIVATE_COMMAND_REG_OP_0_BITS                    2
#define NCI_MBR_ACTIVATE_COMMAND_REG_OP_1_BITS                    2
#define NCI_MBR_ACTIVATE_COMMAND_REG_OP_2_BITS                    2
#define NCI_MBR_ACTIVATE_COMMAND_REG_DEV_MODE_BITS                1

#define NCI_MBR_ACTIVATE_COMMAND_REG_TRIGGER_BIT_OFFSET           0
#define NCI_MBR_ACTIVATE_COMMAND_REG_GOB_SIZE_BIT_OFFSET          (NCI_MBR_ACTIVATE_COMMAND_REG_TRIGGER_BIT_OFFSET + NCI_MBR_ACTIVATE_COMMAND_REG_TRIGGER_BITS)
#define NCI_MBR_ACTIVATE_COMMAND_REG_CHAN_ID_BIT_OFFSET           (NCI_MBR_ACTIVATE_COMMAND_REG_GOB_SIZE_BIT_OFFSET + NCI_MBR_ACTIVATE_COMMAND_REG_GOB_SIZE_BITS)
#define NCI_MBR_ACTIVATE_COMMAND_REG_BUF_ID_BIT_OFFSET            (NCI_MBR_ACTIVATE_COMMAND_REG_CHAN_ID_BIT_OFFSET + NCI_MBR_ACTIVATE_COMMAND_REG_CHAN_ID_BITS)
#define NCI_MBR_ACTIVATE_COMMAND_REG_PROC_MODE_BIT_OFFSET         (NCI_MBR_ACTIVATE_COMMAND_REG_BUF_ID_BIT_OFFSET + NCI_MBR_ACTIVATE_COMMAND_REG_BUF_ID_BITS)
#define NCI_MBR_ACTIVATE_COMMAND_REG_OP_0_BIT_OFFSET              (NCI_MBR_ACTIVATE_COMMAND_REG_PROC_MODE_BIT_OFFSET + NCI_MBR_ACTIVATE_COMMAND_REG_PROC_MODE_BITS)
#define NCI_MBR_ACTIVATE_COMMAND_REG_OP_1_BIT_OFFSET              (NCI_MBR_ACTIVATE_COMMAND_REG_OP_0_BIT_OFFSET + NCI_MBR_ACTIVATE_COMMAND_REG_OP_0_BITS)
#define NCI_MBR_ACTIVATE_COMMAND_REG_OP_2_BIT_OFFSET              (NCI_MBR_ACTIVATE_COMMAND_REG_OP_1_BIT_OFFSET + NCI_MBR_ACTIVATE_COMMAND_REG_OP_1_BITS)
#define NCI_MBR_ACTIVATE_COMMAND_REG_DEV_MODE_BIT_OFFSET          (NCI_MBR_ACTIVATE_COMMAND_REG_OP_2_BIT_OFFSET + NCI_MBR_ACTIVATE_COMMAND_REG_OP_2_BITS)

/* frame_init:
 *
 *    [5]    |         [4-1]         |  [0]
 *  IPU Mode | Channel Enable bitmap | Trigger
 */
#define NCI_MBR_FRAME_INIT_REG_TRIGGER_BITS                       1
#define NCI_MBR_FRAME_INIT_REG_CHAN_EN_BITS                       4
#define NCI_MBR_FRAME_INIT_REG_IPU_MODE_BITS                      1

#define NCI_MBR_FRAME_INIT_REG_TRIGGER_BIT_OFFSET                 0
#define NCI_MBR_FRAME_INIT_REG_CHAN_EN_BIT_OFFSET                 (NCI_MBR_FRAME_INIT_REG_TRIGGER_BIT_OFFSET + NCI_MBR_FRAME_INIT_REG_TRIGGER_BITS)
#define NCI_MBR_FRAME_INIT_REG_IPU_MODE_BIT_OFFSET                (NCI_MBR_FRAME_INIT_REG_CHAN_EN_BIT_OFFSET + NCI_MBR_FRAME_INIT_REG_CHAN_EN_BITS)

/* general_cntl_register:
 *
 *         [8-5]        |         [4-1]        |    [0]
 *   DMA_int Batch size | DMA_HBfrX Batch size | Clock Gating
 */
#define NCI_MBR_GENERAL_CTRL_REG_CLOCK_GATING_BITS                1
#define NCI_MBR_GENERAL_CTRL_REG_DMA_HB_BATCH_SIZE_BITS           4
#define NCI_MBR_GENERAL_CTRL_REG_DMA_INT_BATCH_SIZE_BITS          4

#define NCI_MBR_GENERAL_CTRL_REG_CLOCK_GATING_BIT_OFFSET          0
#define NCI_MBR_GENERAL_CTRL_REG_DMA_HB_BATCH_SIZE_BIT_OFFSET     (NCI_MBR_GENERAL_CTRL_REG_CLOCK_GATING_BIT_OFFSET + NCI_MBR_GENERAL_CTRL_REG_CLOCK_GATING_BITS)
#define NCI_MBR_GENERAL_CTRL_REG_DMA_INT_BATCH_SIZE_BIT_OFFSET    (NCI_MBR_GENERAL_CTRL_REG_DMA_HB_BATCH_SIZE_BIT_OFFSET + NCI_MBR_GENERAL_CTRL_REG_DMA_HB_BATCH_SIZE_BITS)

/* coord_ratio :
 *
 *       [7-4]     |     [3-0]
 *   coord_ratio_Y | coord_ratio_X
 */
#define NCI_MBR_COORD_RATIO_REG_COORD_RATIO_X_BITS                4
#define NCI_MBR_COORD_RATIO_REG_COORD_RATIO_Y_BITS                4

#define NCI_MBR_COORD_RATIO_REG_COORD_RATIO_X_BIT_OFFSET          0
#define NCI_MBR_COORD_RATIO_REG_COORD_RATIO_Y_BIT_OFFSET          (NCI_MBR_COORD_RATIO_REG_COORD_RATIO_X_BIT_OFFSET + NCI_MBR_COORD_RATIO_REG_COORD_RATIO_X_BITS)

/* cmd:
 *
 *           [16]         |   [15]   |     [14-12]      |   [11-9]   |   [8-6]   |    [5-3]   |  [2-0]
 *  Read-post-write check | NND MODE | Filter Padding   |  Unused_1  | Algo Type |  Unused_0  | MBR BPP
 */
#define NCI_MBR_CMD_REG_MBR_BPP_BITS                              3
#define NCI_MBR_CMD_REG_UNUSED_0_BITS                             3
#define NCI_MBR_CMD_REG_ALGO_TYPE_BITS                            3
#define NCI_MBR_CMD_REG_UNUSED_1_BITS                             3
#define NCI_MBR_CMD_REG_FILTER_PAD_BITS                           3
#define NCI_MBR_CMD_REG_NND_MODE_BITS                             1
#define NCI_MBR_CMD_REG_RPW_CHECK_BITS                            1

#define NCI_MBR_CMD_REG_MBR_BPP_BIT_OFFSET                        0
#define NCI_MBR_CMD_REG_UNUSED_0_BIT_OFFSET                       (NCI_MBR_CMD_REG_MBR_BPP_BIT_OFFSET + NCI_MBR_CMD_REG_MBR_BPP_BITS)
#define NCI_MBR_CMD_REG_ALGO_TYPE_BIT_OFFSET                      (NCI_MBR_CMD_REG_UNUSED_0_BIT_OFFSET + NCI_MBR_CMD_REG_UNUSED_0_BITS)
#define NCI_MBR_CMD_REG_UNUSED_1_BIT_OFFSET                       (NCI_MBR_CMD_REG_ALGO_TYPE_BIT_OFFSET + NCI_MBR_CMD_REG_ALGO_TYPE_BITS)
#define NCI_MBR_CMD_REG_FILTER_PAD_BIT_OFFSET                     (NCI_MBR_CMD_REG_UNUSED_1_BIT_OFFSET + NCI_MBR_CMD_REG_UNUSED_1_BITS)
#define NCI_MBR_CMD_REG_NND_MODE_BIT_OFFSET                       (NCI_MBR_CMD_REG_FILTER_PAD_BIT_OFFSET + NCI_MBR_CMD_REG_FILTER_PAD_BITS)
#define NCI_MBR_CMD_REG_RPW_CHECK_BIT_OFFSET                      (NCI_MBR_CMD_REG_NND_MODE_BIT_OFFSET + NCI_MBR_CMD_REG_NND_MODE_BITS)

NCI_MBR_STORAGE_CLASS_C void
__dummy_mbr_device_id(void)
{
	/* Assert that "enum nci_mbr_device_id" is equivalent to "dai_ipu_top_mbr_instances_t" */

	COMPILATION_ERROR_IF((unsigned)NCI_MBR_DEVICE_ID_DEV_MBR_GDC != (unsigned)DAI_IPU_TOP_GDC_TOP_GDC_MBR);
	COMPILATION_ERROR_IF((unsigned)NCI_MBR_DEVICE_ID_DEV_MBR_TNR != (unsigned)DAI_IPU_TOP_TNR_TOP_TNR_MBR);
	COMPILATION_ERROR_IF((unsigned)NCI_MBR_DEVICE_MBR_NUM_DEVS != (unsigned)NUM_DAI_IPU_TOP_MBR_INSTANCES);
}

NCI_MBR_STORAGE_CLASS_C uint32_t
nci_mbr_get_reg_addr(
		const uint32_t dev_id,
		const uint32_t reg_id)
{
	assert(NUM_DAI_IPU_TOP_MBR_INSTANCES > dev_id);
	assert(NUM_DAI_MBR_CRQ_IN_REGISTERS > reg_id);

	const dai_device_route_t *dai_handle = dai_device_get_route(DAI_TYPE_MBR, dev_id, DAI_MBR_CRQ_IN);

	return (dai_handle->slave_address + dai_handle->address_map[reg_id]);
}

NCI_MBR_STORAGE_CLASS_C uint32_t
nci_mbr_get_ack_addr_dma_hb(
		enum nci_mbr_device_id dev_id)
{
	return nci_mbr_get_reg_addr(dev_id, DAI_MBR_REG_MBR_REGS_REG_DMA_HB_DONE_ACK_INFO);
}

NCI_MBR_STORAGE_CLASS_C uint32_t
nci_mbr_get_ack_addr_dma_lb(
		enum nci_mbr_device_id dev_id)
{
	return nci_mbr_get_reg_addr(dev_id, DAI_MBR_REG_MBR_REGS_REG_DMA_LB_DONE_ACK_INFO);
}

NCI_MBR_STORAGE_CLASS_C uint32_t
nci_mbr_get_ack_addr_dma_int(
		enum nci_mbr_device_id dev_id)
{
	return nci_mbr_get_reg_addr(dev_id, DAI_MBR_REG_MBR_REGS_REG_DMA_INT_DONE_ACK_INFO);
}

NCI_MBR_STORAGE_CLASS_C uint32_t
nci_mbr_get_de_queue_ack_addr_dma_int(
		enum nci_mbr_device_id dev_id)
{
	return nci_mbr_get_reg_addr(dev_id, DAI_MBR_REG_MBR_REGS_REG_DMA_INT_DE_QUEUE_ACK_INFO);
}

NCI_MBR_STORAGE_CLASS_C uint32_t
nci_mbr_get_de_queue_ack_addr_dma_hb(
		enum nci_mbr_device_id dev_id)
{
	return nci_mbr_get_reg_addr(dev_id, DAI_MBR_REG_MBR_REGS_REG_DMA_HB_DE_QUEUE_ACK_INFO);
}

NCI_MBR_STORAGE_CLASS_C uint32_t
nci_mbr_get_de_queue_ack_addr_dma_lb(
		enum nci_mbr_device_id dev_id)
{
	return nci_mbr_get_reg_addr(dev_id, DAI_MBR_REG_MBR_REGS_REG_DMA_LB_DE_QUEUE_ACK_INFO);
}

NCI_MBR_STORAGE_CLASS_C uint32_t
nci_mbr_get_grid_point_top0_X0_addr(
		enum nci_mbr_device_id dev_id)
{
	return nci_mbr_get_reg_addr(dev_id, DAI_MBR_REG_MBR_REGS_REG_GRID_POINT_TOP0_X0_INFO);
}

NCI_MBR_STORAGE_CLASS_C uint32_t
nci_mbr_get_grid_point_bot0_X0_addr(
		enum nci_mbr_device_id dev_id)
{
	return nci_mbr_get_reg_addr(dev_id, DAI_MBR_REG_MBR_REGS_REG_GRID_POINT_BOT0_X0_INFO);
}


NCI_MBR_STORAGE_CLASS_C uint32_t
nci_mbr_get_activate_command_addr(
		enum nci_mbr_device_id dev_id)
{
	return nci_mbr_get_reg_addr(dev_id, DAI_MBR_REG_MBR_REGS_REG_ACTIVATE_COMMAND_INFO);
}

NCI_MBR_STORAGE_CLASS_C uint32_t
nci_mbr_get_nof_sections(void)
{
	return NCI_MBR_NUM_SECTIONS;
}

NCI_MBR_STORAGE_CLASS_C uint32_t
nci_mbr_get_sizeof_section(
		enum nci_mbr_sections section)
{
	uint32_t size = 0;

	switch (section) {
	case NCI_MBR_GLBL0_SECTION:
		size = sizeof(struct nci_mbr_global0_cfg);
		break;
	case NCI_MBR_GLBL1_SECTION:
		size = sizeof(struct nci_mbr_global1_cfg);
		break;
	case NCI_MBR_CHAN0_SECTION:
	case NCI_MBR_CHAN1_SECTION:
	case NCI_MBR_CHAN2_SECTION:
		size = sizeof(struct nci_mbr_channel_cfg);
		break;
	default:
		assert(0);
		break;
	}

	return size;
}

NCI_MBR_STORAGE_CLASS_C uint32_t
nci_mbr_get_sizeof_blob(void)
{
	return sizeof(struct nci_mbr_cfg);
}

NCI_MBR_STORAGE_CLASS_C enum nci_mbr_device_mode
nci_mbr_device_id_to_device_mode(
		enum nci_mbr_device_id dev_id)
{
	enum nci_mbr_device_mode dev_mode = NCI_MBR_DEVICE_MODE_GDC;

	switch (dev_id) {
	case NCI_MBR_DEVICE_ID_DEV_MBR_GDC:
		dev_mode = NCI_MBR_DEVICE_MODE_GDC;
		break;
	case NCI_MBR_DEVICE_ID_DEV_MBR_TNR:
		dev_mode = NCI_MBR_DEVICE_MODE_TNR;
		break;
	default:
		assert(0);
	}

	return dev_mode;
}

NCI_MBR_STORAGE_CLASS_C uint32_t
nci_mbr_pack_activate_command_register(
		uint32_t gob_size,
		enum nci_mbr_device_mode device_mode,
		uint32_t processing_mode,
		uint32_t operation_0,
		uint32_t operation_1,
		uint32_t operation_2)
{
	uint32_t retval = 0;

	retval |= (NCI_MBR_MASK(gob_size, NCI_MBR_ACTIVATE_COMMAND_REG_GOB_SIZE_BITS)
			<< NCI_MBR_ACTIVATE_COMMAND_REG_GOB_SIZE_BIT_OFFSET);

	retval |= (NCI_MBR_MASK(processing_mode, NCI_MBR_ACTIVATE_COMMAND_REG_PROC_MODE_BITS)
			<< NCI_MBR_ACTIVATE_COMMAND_REG_PROC_MODE_BIT_OFFSET);

	retval |= (NCI_MBR_MASK(operation_0, NCI_MBR_ACTIVATE_COMMAND_REG_OP_0_BITS)
			<< NCI_MBR_ACTIVATE_COMMAND_REG_OP_0_BIT_OFFSET);

	retval |= (NCI_MBR_MASK(operation_1, NCI_MBR_ACTIVATE_COMMAND_REG_OP_1_BITS)
			<< NCI_MBR_ACTIVATE_COMMAND_REG_OP_1_BIT_OFFSET);

	retval |= (NCI_MBR_MASK(operation_2, NCI_MBR_ACTIVATE_COMMAND_REG_OP_2_BITS)
			<< NCI_MBR_ACTIVATE_COMMAND_REG_OP_2_BIT_OFFSET);

	retval |= (NCI_MBR_MASK(device_mode, NCI_MBR_ACTIVATE_COMMAND_REG_DEV_MODE_BITS)
			<< NCI_MBR_ACTIVATE_COMMAND_REG_DEV_MODE_BIT_OFFSET);

	/* Note that "Trigger", "Channel ID", and "Buf ID" bits are all set to zero as per MBR HAS */
	return retval;
}

NCI_MBR_STORAGE_CLASS_C uint32_t
nci_mbr_pack_frame_init_register(
		uint32_t nof_chans)
{
	uint32_t retval = 0;
	uint32_t channel_bitmap = (1 << nof_chans) -1;

	retval |= (NCI_MBR_MASK(channel_bitmap, NCI_MBR_FRAME_INIT_REG_CHAN_EN_BITS)
			<< NCI_MBR_FRAME_INIT_REG_CHAN_EN_BIT_OFFSET);

	/* Note that "Trigger" and "IPU mode" are all set to zero as per MBR HAS*/
	return retval;
}

NCI_MBR_STORAGE_CLASS_C uint32_t
nci_mbr_pack_general_cntl_register(
		uint32_t clock_gating,
		uint32_t dma_hb_batch_size,
		uint32_t dma_int_batch_size)
{
	uint32_t retval = 0;

	retval |= (NCI_MBR_MASK(clock_gating, NCI_MBR_GENERAL_CTRL_REG_CLOCK_GATING_BITS)
			<< NCI_MBR_GENERAL_CTRL_REG_CLOCK_GATING_BIT_OFFSET);

	retval |= (NCI_MBR_MASK(dma_hb_batch_size, NCI_MBR_GENERAL_CTRL_REG_DMA_HB_BATCH_SIZE_BITS)
			<< NCI_MBR_GENERAL_CTRL_REG_DMA_HB_BATCH_SIZE_BIT_OFFSET);

	retval |= (NCI_MBR_MASK(dma_int_batch_size, NCI_MBR_GENERAL_CTRL_REG_DMA_INT_BATCH_SIZE_BITS)
			<< NCI_MBR_GENERAL_CTRL_REG_DMA_INT_BATCH_SIZE_BIT_OFFSET);

	return retval;
}

NCI_MBR_STORAGE_CLASS_C uint32_t
nci_mbr_pack_coord_ratio_register(
		uint32_t coord_ratio_x,
		uint32_t coord_ratio_y)
{
	uint32_t retval = 0;

	retval |= (NCI_MBR_MASK(coord_ratio_x, NCI_MBR_COORD_RATIO_REG_COORD_RATIO_X_BITS)
			<< NCI_MBR_COORD_RATIO_REG_COORD_RATIO_X_BIT_OFFSET);

	retval |= (NCI_MBR_MASK(coord_ratio_y, NCI_MBR_COORD_RATIO_REG_COORD_RATIO_Y_BITS)
			<< NCI_MBR_COORD_RATIO_REG_COORD_RATIO_Y_BIT_OFFSET);

	return retval;
}

NCI_MBR_STORAGE_CLASS_C uint32_t
nci_mbr_pack_cmd_register(
		enum nci_mbr_bpp mbr_bpp,
		enum nci_mbr_algo_type algo_type,
		uint32_t filter_padding,
		uint32_t nnd_mode)
{
	uint32_t retval = 0;

	retval |= (NCI_MBR_MASK(mbr_bpp, NCI_MBR_CMD_REG_MBR_BPP_BITS)
			<< NCI_MBR_CMD_REG_MBR_BPP_BIT_OFFSET);

	retval |= (NCI_MBR_MASK(algo_type, NCI_MBR_CMD_REG_ALGO_TYPE_BITS)
			<< NCI_MBR_CMD_REG_ALGO_TYPE_BIT_OFFSET);

	retval |= (NCI_MBR_MASK(filter_padding, NCI_MBR_CMD_REG_FILTER_PAD_BITS)
			<< NCI_MBR_CMD_REG_FILTER_PAD_BIT_OFFSET);

	retval |= (NCI_MBR_MASK(nnd_mode, NCI_MBR_CMD_REG_NND_MODE_BITS)
			<< NCI_MBR_CMD_REG_NND_MODE_BIT_OFFSET);

	/* TODO: Set "RPW check" to valid values. Now set to zero */

	return retval;
}

#endif /* __NCI_MBR_INLINE_LOCAL_H */

