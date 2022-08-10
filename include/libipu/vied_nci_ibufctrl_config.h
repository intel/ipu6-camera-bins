/**
* INTEL CONFIDENTIAL
*
* Copyright (C) 2014 - 2017 Intel Corporation.
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

#ifndef __VIED_NCI_IBUFCTRL_CONFIG_H
#define __VIED_NCI_IBUFCTRL_CONFIG_H

#include "vied_nci_ibufctrl_config_types.h"
#include "vied_nci_ibufctrl_storage_class.h"
#include "vied_nci_ibufctrl_config_dep.h"

STORAGE_CLASS_INLINE
unsigned int vied_nci_ibufctrl_reg_addr_with_base(unsigned int base_address, unsigned int bank_id, unsigned int group_id, unsigned int reg_nr);

VIED_NCI_IBUFCTRL_STORAGE_CLASS_H
unsigned int vied_nci_ibufctrl_get_idrain_receive_addr(
	unsigned int dev_id);

VIED_NCI_IBUFCTRL_STORAGE_CLASS_H
int vied_nci_ibufctrl_config_feeder(unsigned int dev_id,
	const vied_nci_ibufctrl_feeder_cfg_s * const feeder_cfg,
	unsigned int feeder_id);

VIED_NCI_IBUFCTRL_STORAGE_CLASS_H
int vied_nci_ibufctrl_config_frame_check(unsigned int dev_id,
	const vied_nci_ibufctrl_frame_check_cfg_s * const frame_check_cfg,
	unsigned int frame_check_id);

VIED_NCI_IBUFCTRL_STORAGE_CLASS_H
int vied_nci_ibufctrl_config_dest(unsigned int dev_id,
	const vied_nci_ibufctrl_dest_cfg_s * const dest_cfg,
	unsigned int dest_id);

VIED_NCI_IBUFCTRL_STORAGE_CLASS_H
int vied_nci_ibufctrl_config_proc(unsigned int dev_id,
	const vied_nci_ibufctrl_proc_s * const proc,
	unsigned int proc_id);

VIED_NCI_IBUFCTRL_STORAGE_CLASS_H
int vied_nci_ibufctrl_config_ibuf(unsigned int dev_id, vied_nci_ibufctrl_ibuf_s *ibuf);

VIED_NCI_IBUFCTRL_STORAGE_CLASS_H
int vied_nci_ibufctrl_setup_ibuf(unsigned int dev_id, vied_nci_ibufctrl_ibuf_s *ibuf);

VIED_NCI_IBUFCTRL_STORAGE_CLASS_H
int vied_nci_ibufctrl_srst_procs(unsigned int dev_id, unsigned int proc_bitmap);

#ifdef __INLINE_VIED_NCI_IBUFCTRL__
#include "vied_nci_ibufctrl_config_inline.h"
#include "vied_nci_ibufctrl_config_inline_dep.h"
#endif

/* Implementation pasted here because it is always inlined, so always exposed to the interface */
STORAGE_CLASS_INLINE
unsigned int vied_nci_ibufctrl_reg_addr_with_base(
	unsigned int base_address,
	unsigned int bank_id,
	unsigned int group_id,
	unsigned int reg_nr)
{
	return base_address + (((bank_id<<(_IBC_2600_REG_IDX_BITS + _IBC_2600_GROUP_IDX_BITS)) |
		(group_id<<_IBC_2600_REG_IDX_BITS) | (reg_nr)) * _IBC_2600_REG_ALIGN);
}

#endif /* __VIED_NCI_IBUFCTRL_CONFIG_H */
