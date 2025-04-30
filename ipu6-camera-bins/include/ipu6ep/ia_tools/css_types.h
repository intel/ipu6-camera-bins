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

#ifndef __CSS_TYPES_H__
#define __CSS_TYPES_H__

#include <stdint.h>
#include <stdbool.h>

/*!
 * \brief Error codes.
 * \ingroup ia_tools
*/
typedef int32_t css_err_t;
#define css_err_none     0         /*!< No errors*/
#define css_err_general  (-(1 << 1))  /*!< General error*/
#define css_err_nomemory (-(1 << 2))  /*!< Out of memory*/
#define css_err_data     (-(1 << 3))  /*!< Corrupted data*/
#define css_err_internal (-(1 << 4))  /*!< Error in code*/
#define css_err_argument (-(1 << 5))  /*!< Invalid argument for a function*/
#define css_err_noentry  (-(1 << 6))  /*!< No such entry/entity/file */
#define css_err_timeout  (-(1 << 7))  /*!< Time out*/
#define css_err_end      (-(1 << 8))  /*!< End of values*/
#define css_err_full     (-(1 << 9))  /*!< Exchange full */
#define css_err_again    (-(1 << 10)) /*!< Operation requires additional call */
#define css_err_nimpl    (-(1 << 11)) /*!< Not implemented */

#ifndef __cplusplus

/* Define bool type as int for strict C89 */
#ifndef __bool_true_false_are_defined
#define bool int
#define false 0
#define true 1
#endif

/* inline keyword compliance for ansi */
#if (__STDC_VERSION__ < 199901L)
#define inline
#endif

#endif /* __cplusplus */

#endif /* _CSS_TYPES_H_ */
