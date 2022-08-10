/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2013-2016 Intel Corporation. All Rights Reserved.
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

#ifndef _IA_CIPR_STRING_H_
#define _IA_CIPR_STRING_H_

/**
 * \file ia_cipr_string.h
 *
 * Tentative CIPR String header
 *
 * \defgroup ia_cipr_string String
 * \ingroup ia_cipr
 *
 */

#include <stddef.h>

/**
 * \ingroup ia_cipr_string
 */
size_t ia_cipr_strnlen(const char *str, size_t size);

/**
 * \ingroup ia_cipr_string
 */
int ia_cipr_snprintf_s(char *str, size_t str_size, size_t n, const char *fmt, ...);


#endif /* _IA_CIPF_FIO_H_ */
