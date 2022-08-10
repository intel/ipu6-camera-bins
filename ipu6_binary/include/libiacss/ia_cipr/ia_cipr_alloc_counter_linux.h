/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2013-2014 Intel Corporation. All Rights Reserved.
 *
 * The source code contained or described herein and all documents related to
 * the source code ("Material") are owned by Intel Corporation or its suppliers
 * or licensors. Title to the Material remains with Intel Corporation or its
 * suppliers and licensors. The Material contains trade secrets and proprietary
 * and confidential information of Intel or its suppliers and licensors. The
 * Material is protected by worldwide copyright and trade secret laws and
 * treaty provisions. No part of the Material may be used, copied, reproduced,
 * modified, published, uploaded, posted, transmitted, distributed, or
 * disclosed in any way without Intel's prior express written permission.
 *
 * No license under any patent, copyright, trade secret or other intellectual
 * property right is granted to or conferred upon you by disclosure or delivery
 * of the Materials, either expressly, by implication, inducement, estoppel or
 * otherwise. Any license under such intellectual property rights must be
 * express and approved by Intel in writing.
 */

/*
 * ia_cipr_alloc_counter_linux.h
 */

#ifndef IA_CIPR_ALLOC_COUNTER_LINUX_H_
#define IA_CIPR_ALLOC_COUNTER_LINUX_H_

void ia_cipr_inc_free_counter(void *ptr);

void ia_cipr_inc_alloc_counter(void *ptr, const char *file, int line);

int ia_cipr_check_alloc_error(void);

#endif /* IA_CIPR_ALLOC_COUNTER_LINUX_H_ */
