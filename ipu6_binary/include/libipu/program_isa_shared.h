/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2017 - 2019 Intel Corporation.
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

#ifndef __PROGRAM_ISA_SHARED_H
#define __PROGRAM_ISA_SHARED_H

#include "math_support.h"
#include "ia_css_vmem_resources.h"
#include "isa_shared_defs.h"
#include "program_isa_shared_dep.h"


#define EVQ_ENABLE_STR2MMIO_EVENTS		(1)

/* defines for bayer output kernel */
#define QUEUE_SINGLE_CORE_ONLY

#define S2V_WAIT_FOR_ACK			(0) /* Disable wait for ack, s2v uses precond */
#define BAYER_OUTPUT_WAIT_FOR_ACK		(0) /* Disable wait for ack, bayer output uses precond */

/* Important note - ISL PG is reusing the stream IDs reserved for pre-gdc, since
there are no stream ids reserved for ISL PG.Agreement with driver team is
that ISL PG and pre-gdc PG will not be run concurrently */
/* Warning - Fwapi testbench host code currently does not support MMU configuration,
hence using dma-ext1 results in data corruption on target testing with
fwapi testbench host code (works fine in sched). DMA - ext1 works fine on driver
testing. On target we have to manually switch back to dma-ext0 if using
fwapi testbench*/

/*enable/disable dma_ext1_read for isl bayer input DMA channel*/
#define DFM_DMA_BAYER_INPUT_DMA_RESOURCE_ID	vied_nci_dev_chn_dma_ext1_read


#define DMA_OUT_STILL_ORIG_RES_DMA_ID_API_MODEL	VIED_NCI_DEV_CHN_DMA_EXT1_WRITE_ID

#define DMA_BAYER_IN_RESOURCE_ID		VIED_NCI_DEV_CHN_DMA_EXT1_READ_ID
#define DMA_PAF_IN_RESOURCE_ID			VIED_NCI_DEV_CHN_DMA_EXT1_READ_ID

/* Define our own event queue pid list to reduce dmem usage */
#define CUSTOM_EVQ_PID_LIST
#define EVQ_NO_S2V_EVENTS
#define EVQ_NO_ISL_S2V_EVENTS
#define EVQ_NO_IPF_EVENTS

typedef enum evq_pid {
	EVQ_PID_IPF0,
	EVQ_PID_ISA_INIT,
	EVQ_PID_ISA_NEXT,
	EVQ_PID_ISA_DONE,
	EVQ_PID_STR2MMIO0,
	EVQ_PID_DFM_NEXT,
	EVQ_PID_INVALID,
	EVQ_PID_NUM
} evq_pid_t;

/* Defines for output buffers - TRANSFER VMEM */

#define INNERLOOP_UNROLL_FACTOR		(1)


#endif /* __PROGRAM_ISA_SHARED_H */
