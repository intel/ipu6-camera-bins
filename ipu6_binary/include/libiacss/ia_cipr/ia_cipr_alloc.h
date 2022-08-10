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
 * ia_cipr_alloc.h
 */

#ifndef IA_CIPR_ALLOC_H_
#define IA_CIPR_ALLOC_H_

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/** \file ia_cipr_alloc.h
 *
 * \brief posix compatible host memory allocation API
 */

#ifdef RNDBUILD
#define IACIPR_FUNC __FUNCTION__
#define IACIPR_FILE __FILE__
#define IACIPR_LINE __LINE__
#else
#define IACIPR_FUNC ""
#define IACIPR_FILE ""
#define IACIPR_LINE 0
#endif

/**
 * \ingroup ia_cipr_memory
 * wrapper-macro for getting page size.
 *
 * Note: This is only code style addition to be used with
 * _ALLOC_ALIGNED-macro:
 * * IA_CIPR_ALLOC_ALIGNED(size, IA_CIPR_PAGESIZE())
 */
#define IA_CIPR_PAGESIZE() \
    ia_cipr_pagesize()

/**
 * \ingroup ia_cipr_memory
 * malloc wrapper-macro. Logs the caller among other things.
 */
#define IA_CIPR_MALLOC(size) \
    ia_cipr_malloc(size, IACIPR_FUNC, IACIPR_FILE, IACIPR_LINE)

/**
 * \ingroup ia_cipr_memory
 * calloc wrapper-macro. Logs the caller among other things.
 */
#define IA_CIPR_CALLOC(nmemb, size) \
    ia_cipr_calloc(nmemb, size, IACIPR_FUNC, IACIPR_FILE, IACIPR_LINE)

/**
 * \ingroup ia_cipr_memory
 * alloc_aligned wrapper-macro. Logs the caller among other things.
 */
#define IA_CIPR_ALLOC_ALIGNED(size, alignment) \
    ia_cipr_alloc_aligned(size, alignment, IACIPR_FUNC, IACIPR_FILE, IACIPR_LINE)

/**
 * \ingroup ia_cipr_memory
 * free wrapper-macro. Logs the caller among other things.
 */
#define IA_CIPR_FREE(ptr) \
    ia_cipr_free(ptr, IACIPR_FUNC)

/**
 * \ingroup ia_cipr_memory
 * memcpy wrapper-macro.
 */
#define IA_CIPR_MEMCOPY(dest, dest_size, src, n) \
    ia_cipr_memcopy(dest, dest_size, src, n)

/**
 * \ingroup ia_cipr_memory
 */
size_t ia_cipr_pagesize(void);

/**
 * \param size as in malloc
 * \param logmsg entered by macro IA_CIPR_MALLOC. The caller function.
 * \ingroup ia_cipr_memory
 */
void* ia_cipr_malloc(size_t size,
                     const char *logmsg,
                     const char *file_name,
                     int line);

/**
 * \param nmemb as in calloc
 * \param size as in calloc
 * \param logmsg entered by macro IA_CIPR_CALLOC. The caller function.
 * \ingroup ia_cipr_memory
 */
void* ia_cipr_calloc(size_t nmemb,
                     size_t size,
                     const char *logmsg,
                     const char *file_name,
                     int line);

/** Allocate aligned memory (as defined in posix_memalign())
 *
 * Returns pointer to free()'able memory or zero.
 *
 * \param size as in malloc
 * \param alignment as in posix_memalign
 * \param logmsg entered by macro IA_CIPR_CALLOC. The caller function.
 * \ingroup ia_cipr_memory
 */
void* ia_cipr_alloc_aligned(size_t size,
                            size_t alignment,
                            const char *logmsg,
                            const char *file_name,
                            int line);

/**
 * \param *ptr as in free
 * \param logmsg entered by macro IA_CIPR_FREE. The caller function.
 * \ingroup ia_cipr_memory
 */
void ia_cipr_free(void *ptr, const char *logmsg);

/**
 * \param dest as in memcpy
 * \param dest_size as in memcpy_s, max number of bytes to modify in destination
 * \param src as in memcpy
 * \param n as in memcpy
 * \ingroup ia_cipr_memory
 */
void ia_cipr_memcopy(void *dest,
                     size_t dest_size,
                     const void *src,
                     size_t n);

#ifdef __cplusplus
}
#endif


#endif /* IA_CIPR_ALLOC_H_ */
