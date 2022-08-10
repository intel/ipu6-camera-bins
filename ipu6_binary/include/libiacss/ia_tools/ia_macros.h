/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2013-2018 Intel Corporation. All Rights Reserved.
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

#ifndef _IA_MACROS_H_
#define _IA_MACROS_H_

#include <string.h>

/**
 * Unused x
 * \ingroup ia_tools
 */
#ifndef UNUSED
#define UNUSED(x) (void)(x)
#endif

/**
 * Clear x
 * \ingroup ia_tools
 */
#define CLEAR(x)    memset (&(x), 0, sizeof (x))

/**
* Align to 4 byte boundary
* \ingroup ia_tools
*/
#define ALIGN4(x) (((x) + 3U) & (~3U))

/**
 * Align to 8 byte boundary
 * \ingroup ia_tools
 */
#define ALIGN8(x)   (((x) + 7U) & ~7U)
/**
 * Align to 16 byte boundary
 * \ingroup ia_tools
 */
#define ALIGN16(x)  (((x) + 15U) & ~15U)
/**
 * Align to 32 byte boundary
 * \ingroup ia_tools
 */
#define ALIGN32(x)  (((x) + 31U) & ~31U)
/**
 * Align to 64 byte boundary
 * \ingroup ia_tools
 */
#define ALIGN64(x)  (((x) + 63U) & ~63U)
/**
 * Align to 128 byte boundary
 * \ingroup ia_tools
 */
#define ALIGN128(x) (((x) + 127U) & ~127U)
/**
 * Align to 256 byte boundary
 * \ingroup ia_tools
 */
#define ALIGN256(x) (((x) + 255U) & ~255U)
/**
 * Align to 512 byte boundary
 * \ingroup ia_tools
 */
#define ALIGN512(x) (((x) + 511U) & ~511U)

/**
 * Align to page boundary
 * \ingroup ia_tools
 */
#ifndef PAGE_ALIGN
#define PAGE_ALIGN(x) ((x + 0xfff) & 0xfffff000)
#endif

/* Integer round-up division of a with b */
#define CEIL_DIV(a, b)  ((b) ? (((a) + (b) - 1) / (b)) : 0)
/* Align a to the upper multiple of b */
#define CEIL_MUL(a, b)  CEIL_DIV(a, b) * (b)

/* Number of elements in an array */
#define NOF_ARRAY_ELEMENTS(array) (sizeof(array) / sizeof(array[0]))

/* Return smaller of two values */
#define IA_MIN(a, b) ((a) < (b) ? (a) : (b))
/* Return larger of two values */
#define IA_MAX(a, b) ((a) > (b) ? (a) : (b))

#endif

