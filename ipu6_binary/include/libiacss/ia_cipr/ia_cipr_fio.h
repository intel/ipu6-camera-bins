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

#ifndef _IA_CIPR_FIO_H_
#define _IA_CIPR_FIO_H_

/**
 * \file ia_cipr_fio.h
 *
 * Tentative CIPR File IO Header
 *
 * \defgroup ia_cipr_fio File-IO
 * \ingroup ia_cipr
 *
 * CIPR File IO is inteded for wrapping basic stdio file operations.
 * This is mainly needed for Windows kernel mode compilation. The rest of CIPR
 * build scenarions are using stdio directly via declarations below.
 */

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void ia_cipr_file_t;

/**
 * \ingroup ia_cipr_fio
 */
ia_cipr_file_t* ia_cipr_fopen(const char *, const char *);

/**
 * \ingroup ia_cipr_fio
 */
int ia_cipr_fclose(ia_cipr_file_t *);

/**
 * \ingroup ia_cipr_fio
 */
size_t ia_cipr_fread(void *, size_t, size_t, ia_cipr_file_t *);

/**
 * \ingroup ia_cipr_fio
 */
size_t ia_cipr_fwrite(const void *, size_t, size_t, ia_cipr_file_t *);

/**
 * \ingroup ia_cipr_fio
 */
int ia_cipr_fseek(ia_cipr_file_t *, long int, int);

/**
 * \ingroup ia_cipr_fio
 */
long int ia_cipr_ftell(ia_cipr_file_t *);

/**
 * \ingroup ia_cipr_fio
 */
int ia_cipr_ferror(ia_cipr_file_t *);

/**
 * \ingroup ia_cipr_fio
 */
void ia_cipr_clearerr(ia_cipr_file_t *);

#ifdef __cplusplus
}
#endif


#endif /* _IA_CIPF_FIO_H_ */
