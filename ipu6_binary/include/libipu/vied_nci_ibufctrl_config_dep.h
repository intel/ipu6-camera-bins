/**
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

#ifndef __VIED_NCI_IBUFCTRL_CONFIG_DEP_H
#define __VIED_NCI_IBUFCTRL_CONFIG_DEP_H

#include "vied_nci_ibufctrl_config_types.h"
#include "vied_nci_ibufctrl_storage_class.h"

/* v4 has additional functions meant for updating only the necessary registers
 * when switching between off-line and on-line modes (and vice versa)
 */

VIED_NCI_IBUFCTRL_STORAGE_CLASS_H
int vied_nci_ibufctrl_config_dma_flush_cntr(
	unsigned int dev_id,
	unsigned int dma_flush_cntr,
	unsigned int dest_id);

VIED_NCI_IBUFCTRL_STORAGE_CLASS_H
int vied_nci_ibufctrl_config_frame_check_enable(
	unsigned int dev_id,
	unsigned int frame_check_enable,
	unsigned int frame_check_addr,
	unsigned int frame_check_id);

VIED_NCI_IBUFCTRL_STORAGE_CLASS_H
int vied_nci_ibufctrl_config_dest_otf(
	unsigned int dev_id,
	const vied_nci_ibufctrl_dest_otf_cfg_s * const dest_otf_cfg,
	unsigned int dest_id);

VIED_NCI_IBUFCTRL_STORAGE_CLASS_H
int vied_nci_ibufctrl_config_proc_otf(
	unsigned int dev_id,
	const vied_nci_ibufctrl_proc_otf_cfg_s * const proc_otf_cfg,
	unsigned int proc_id);

VIED_NCI_IBUFCTRL_STORAGE_CLASS_H
int vied_nci_ibufctrl_config_invert_gda_en(
	unsigned int dev_id,
	unsigned int proc_id,
	unsigned int invert_gda_en);

#endif /* __VIED_NCI_IBUFCTRL_CONFIG_DEP_H */
