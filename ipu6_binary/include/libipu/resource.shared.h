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

#ifndef __RESOURCE_SHARED_H
#define __RESOURCE_SHARED_H

#include "resource_types.h"
#include "mem_ptr.h"
#include "storage_class.h"

STORAGE_CLASS_INLINE mem_ptr_t resource_to_memptr(mem_resource_t r);

STORAGE_CLASS_INLINE resource_t resource_t_value_inc(resource_t resource, unsigned inc);

STORAGE_CLASS_INLINE mem_resource_t mem_resource_t_value_inc(mem_resource_t resource, unsigned inc);
STORAGE_CLASS_INLINE dma_chan_resource_t dma_chan_resource_t_value_inc(dma_chan_resource_t resource, unsigned inc);

/**
 * @brief  Return the dma resource for a given channel number
 *
 * @param ch_idx      Channel number
 * @param dma         The dma resource to use
 * @param base        Relocation base of dma channels for this program
 *
 * @return            Dma channel number on dma ext0
 */
STORAGE_CLASS_INLINE resource_t
get_dma_ext_channel(unsigned ch_idx, resource_id_t dma, uint32_t base);

#ifndef PIPE_GENERATION
#include "resource.shared.c"
#endif

#endif /* __RESOURCE_SHARED_H */
