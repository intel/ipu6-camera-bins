/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2013-2017 Intel Corporation. All Rights Reserved.
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
 * ia_cipr_assert.h
 */

#ifndef IA_CIPR_ASSERT_H_
#define IA_CIPR_ASSERT_H_

#ifdef _KERNEL_MODE

#include <wdm.h>
#include <windef.h>
/**
* \ingroup ia_cipr
* assert wrapper-macro. Breaks if expression fails.
*/
#define IA_CIPR_ASSERT(expr) \
    ASSERT(expr)

#else  /* _KERNEL_MODE */

#include <assert.h>

/**
 * \ingroup ia_cipr
 * assert wrapper-macro. Breaks if expression fails.
 */
#ifdef __KLOCWORK__
#define IA_CIPR_ASSERT(expr) do { if (!(expr)) abort(); } while (0)
#else
#define IA_CIPR_ASSERT(expr) assert(expr)
#endif /* __KLOCWORK__ */

#endif /* _KERNEL_MODE */

/**
* \ingroup ia_cipr
* compilation time check. Fails compilation if expression is true
*/
#define IA_CIPR_COMPILATION_FAIL_IF(condition) \
      ((void)sizeof(char[1 - 2*!!(condition)]))

#endif /* IA_CIPR_ASSERT_H_ */
