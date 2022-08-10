/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2015 - 2016 Intel Corporation.
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

#ifndef __ISP_TRACE_H
#define __ISP_TRACE_H

#include "ia_css_trace.h"

/******************************************************************************
*                ISP Module
******************************************************************************/
#define ISP_TRACE_LOG_LEVEL_OFF 0
#define ISP_TRACE_LOG_LEVEL_NORMAL 1
#define ISP_TRACE_LOG_LEVEL_DEBUG 2

/* ISP and all the submodules in ISP will have
 * the default tracing level set to this level
 */
#define ISP_TRACE_CONFIG_DEFAULT ISP_TRACE_LOG_LEVEL_NORMAL

/* In case ISP_TRACE_CONFIG is not defined, set it to default level */
#if !defined(ISP_TRACE_CONFIG)
	#define ISP_TRACE_CONFIG ISP_TRACE_CONFIG_DEFAULT
#endif

/* ISP Module tracing backend is mapped to TUNIT tracing for target platforms */
#ifdef IA_CSS_TRACE_PLATFORM_CELL
	#ifdef HRT_HW
		#define ISP_TRACE_METHOD IA_CSS_TRACE_METHOD_TRACE
	#else
		#define ISP_TRACE_METHOD IA_CSS_TRACE_METHOD_NATIVE
	#endif
#else
	#define ISP_TRACE_METHOD IA_CSS_TRACE_METHOD_NATIVE
#endif

#if (defined(ISP_TRACE_CONFIG))
	/* TRACE_OFF */
	#if ISP_TRACE_CONFIG == ISP_TRACE_LOG_LEVEL_OFF
		#define ISP_TRACE_LEVEL_ASSERT			IA_CSS_TRACE_LEVEL_DISABLED
		#define ISP_TRACE_LEVEL_ERROR			IA_CSS_TRACE_LEVEL_DISABLED
		#define ISP_TRACE_LEVEL_WARNING			IA_CSS_TRACE_LEVEL_DISABLED
		#define ISP_TRACE_LEVEL_INFO			IA_CSS_TRACE_LEVEL_DISABLED
		#define ISP_TRACE_LEVEL_DEBUG			IA_CSS_TRACE_LEVEL_DISABLED
		#define ISP_TRACE_LEVEL_VERBOSE			IA_CSS_TRACE_LEVEL_DISABLED
	/* TRACE_NORMAL */
	#elif ISP_TRACE_CONFIG == ISP_TRACE_LOG_LEVEL_NORMAL
		#define ISP_TRACE_LEVEL_ASSERT			IA_CSS_TRACE_LEVEL_ENABLED
		#define ISP_TRACE_LEVEL_ERROR			IA_CSS_TRACE_LEVEL_ENABLED
		#define ISP_TRACE_LEVEL_WARNING			IA_CSS_TRACE_LEVEL_ENABLED
		#define ISP_TRACE_LEVEL_INFO			IA_CSS_TRACE_LEVEL_ENABLED
		#define ISP_TRACE_LEVEL_DEBUG			IA_CSS_TRACE_LEVEL_DISABLED
		#define ISP_TRACE_LEVEL_VERBOSE			IA_CSS_TRACE_LEVEL_DISABLED
	/* TRACE_DEBUG */
	#elif ISP_TRACE_CONFIG == ISP_TRACE_LOG_LEVEL_DEBUG
		#define ISP_TRACE_LEVEL_ASSERT			IA_CSS_TRACE_LEVEL_ENABLED
		#define ISP_TRACE_LEVEL_ERROR			IA_CSS_TRACE_LEVEL_ENABLED
		#define ISP_TRACE_LEVEL_WARNING			IA_CSS_TRACE_LEVEL_ENABLED
		#define ISP_TRACE_LEVEL_INFO			IA_CSS_TRACE_LEVEL_ENABLED
		#define ISP_TRACE_LEVEL_DEBUG			IA_CSS_TRACE_LEVEL_ENABLED
		#define ISP_TRACE_LEVEL_VERBOSE			IA_CSS_TRACE_LEVEL_ENABLED
	#else
		#error "No ISP_TRACE_CONFIG Tracing level defined"
	#endif
#else
	#error "ISP_TRACE_CONFIG not defined"
#endif

/* Example:
IA_CSS_TRACE_0(module,severity,format);
IA_CSS_TRACE_0(ISP, severity,format);
*/

/******************************************************************************
*                IPFD Module
******************************************************************************/
#define IPFD_ISP_TRACE_LOG_LEVEL_OFF 0
#define IPFD_ISP_TRACE_LOG_LEVEL_NORMAL 1
#define IPFD_ISP_TRACE_LOG_LEVEL_DEBUG 2

/* In case IPFD_ISP_TRACE_CONFIG is not defined, set it to default level */
#if !defined(IPFD_ISP_TRACE_CONFIG)
	#define IPFD_ISP_TRACE_CONFIG ISP_TRACE_CONFIG_DEFAULT
#endif

/* IPFD Module tracing backend is mapped to TUNIT tracing for target platforms */
#ifdef IA_CSS_TRACE_PLATFORM_CELL
	#ifdef HRT_HW
		#define IPFD_ISP_TRACE_METHOD IA_CSS_TRACE_METHOD_TRACE
	#else
		#define IPFD_ISP_TRACE_METHOD IA_CSS_TRACE_METHOD_NATIVE
	#endif
#else
	#define IPFD_ISP_TRACE_METHOD IA_CSS_TRACE_METHOD_NATIVE
#endif

#if (defined(IPFD_ISP_TRACE_CONFIG))
	/* TRACE_OFF */
	#if IPFD_ISP_TRACE_CONFIG == IPFD_ISP_TRACE_LOG_LEVEL_OFF
		#define IPFD_ISP_TRACE_LEVEL_ASSERT			IA_CSS_TRACE_LEVEL_DISABLED
		#define IPFD_ISP_TRACE_LEVEL_ERROR			IA_CSS_TRACE_LEVEL_DISABLED
		#define IPFD_ISP_TRACE_LEVEL_WARNING			IA_CSS_TRACE_LEVEL_DISABLED
		#define IPFD_ISP_TRACE_LEVEL_INFO			IA_CSS_TRACE_LEVEL_DISABLED
		#define IPFD_ISP_TRACE_LEVEL_DEBUG			IA_CSS_TRACE_LEVEL_DISABLED
		#define IPFD_ISP_TRACE_LEVEL_VERBOSE			IA_CSS_TRACE_LEVEL_DISABLED
	/* TRACE_NORMAL */
	#elif IPFD_ISP_TRACE_CONFIG == IPFD_ISP_TRACE_LOG_LEVEL_NORMAL
		#define IPFD_ISP_TRACE_LEVEL_ASSERT			IA_CSS_TRACE_LEVEL_ENABLED
		#define IPFD_ISP_TRACE_LEVEL_ERROR			IA_CSS_TRACE_LEVEL_ENABLED
		#define IPFD_ISP_TRACE_LEVEL_WARNING			IA_CSS_TRACE_LEVEL_ENABLED
		#define IPFD_ISP_TRACE_LEVEL_INFO			IA_CSS_TRACE_LEVEL_ENABLED
		#define IPFD_ISP_TRACE_LEVEL_DEBUG			IA_CSS_TRACE_LEVEL_DISABLED
		#define IPFD_ISP_TRACE_LEVEL_VERBOSE			IA_CSS_TRACE_LEVEL_DISABLED
	/* TRACE_DEBUG */
	#elif IPFD_ISP_TRACE_CONFIG == IPFD_ISP_TRACE_LOG_LEVEL_DEBUG
		#define IPFD_ISP_TRACE_LEVEL_ASSERT			IA_CSS_TRACE_LEVEL_ENABLED
		#define IPFD_ISP_TRACE_LEVEL_ERROR			IA_CSS_TRACE_LEVEL_ENABLED
		#define IPFD_ISP_TRACE_LEVEL_WARNING			IA_CSS_TRACE_LEVEL_ENABLED
		#define IPFD_ISP_TRACE_LEVEL_INFO			IA_CSS_TRACE_LEVEL_ENABLED
		#define IPFD_ISP_TRACE_LEVEL_DEBUG			IA_CSS_TRACE_LEVEL_ENABLED
		#define IPFD_ISP_TRACE_LEVEL_VERBOSE			IA_CSS_TRACE_LEVEL_ENABLED
	#else
		#error "No IPFD_ISP_TRACE_CONFIG Tracing level defined"
	#endif
#else
	#error "IPFD_ISP_TRACE_CONFIG not defined"
#endif

/* Example:
IA_CSS_TRACE_0(module,severity,format);
IA_CSS_TRACE_0(IPFD_ISP, severity,format);
*/

/******************************************************************************
*                FF KERNEL Module
******************************************************************************/
#define FFKER_ISP_TRACE_LOG_LEVEL_OFF 0
#define FFKER_ISP_TRACE_LOG_LEVEL_NORMAL 1
#define FFKER_ISP_TRACE_LOG_LEVEL_DEBUG 2

/* In case FFKER_ISP_TRACE_CONFIG is not defined, set it to default level */
#if !defined(FFKER_ISP_TRACE_CONFIG)
	#define FFKER_ISP_TRACE_CONFIG ISP_TRACE_CONFIG_DEFAULT
#endif

/* FFKER_ISP Module tracing backend is mapped to TUNIT tracing for target platforms */
#ifdef IA_CSS_TRACE_PLATFORM_CELL
	#ifdef HRT_HW
		#define FFKER_ISP_TRACE_METHOD IA_CSS_TRACE_METHOD_TRACE
	#else
		#define FFKER_ISP_TRACE_METHOD IA_CSS_TRACE_METHOD_NATIVE
	#endif
#else
	#define FFKER_ISP_TRACE_METHOD IA_CSS_TRACE_METHOD_NATIVE
#endif

#if (defined(FFKER_ISP_TRACE_CONFIG))
	/* TRACE_OFF */
	#if FFKER_ISP_TRACE_CONFIG == FFKER_ISP_TRACE_LOG_LEVEL_OFF
		#define FFKER_ISP_TRACE_LEVEL_ASSERT			IA_CSS_TRACE_LEVEL_DISABLED
		#define FFKER_ISP_TRACE_LEVEL_ERROR			IA_CSS_TRACE_LEVEL_DISABLED
		#define FFKER_ISP_TRACE_LEVEL_WARNING			IA_CSS_TRACE_LEVEL_DISABLED
		#define FFKER_ISP_TRACE_LEVEL_INFO			IA_CSS_TRACE_LEVEL_DISABLED
		#define FFKER_ISP_TRACE_LEVEL_DEBUG			IA_CSS_TRACE_LEVEL_DISABLED
		#define FFKER_ISP_TRACE_LEVEL_VERBOSE			IA_CSS_TRACE_LEVEL_DISABLED
	/* TRACE_NORMAL */
	#elif FFKER_ISP_TRACE_CONFIG == FFKER_ISP_TRACE_LOG_LEVEL_NORMAL
		#define FFKER_ISP_TRACE_LEVEL_ASSERT			IA_CSS_TRACE_LEVEL_ENABLED
		#define FFKER_ISP_TRACE_LEVEL_ERROR			IA_CSS_TRACE_LEVEL_ENABLED
		#define FFKER_ISP_TRACE_LEVEL_WARNING			IA_CSS_TRACE_LEVEL_ENABLED
		#define FFKER_ISP_TRACE_LEVEL_INFO			IA_CSS_TRACE_LEVEL_ENABLED
		#define FFKER_ISP_TRACE_LEVEL_DEBUG			IA_CSS_TRACE_LEVEL_DISABLED
		#define FFKER_ISP_TRACE_LEVEL_VERBOSE			IA_CSS_TRACE_LEVEL_DISABLED
	/* TRACE_DEBUG */
	#elif FFKER_ISP_TRACE_CONFIG == FFKER_ISP_TRACE_LOG_LEVEL_DEBUG
		#define FFKER_ISP_TRACE_LEVEL_ASSERT			IA_CSS_TRACE_LEVEL_ENABLED
		#define FFKER_ISP_TRACE_LEVEL_ERROR			IA_CSS_TRACE_LEVEL_ENABLED
		#define FFKER_ISP_TRACE_LEVEL_WARNING			IA_CSS_TRACE_LEVEL_ENABLED
		#define FFKER_ISP_TRACE_LEVEL_INFO			IA_CSS_TRACE_LEVEL_ENABLED
		#define FFKER_ISP_TRACE_LEVEL_DEBUG			IA_CSS_TRACE_LEVEL_ENABLED
		#define FFKER_ISP_TRACE_LEVEL_VERBOSE			IA_CSS_TRACE_LEVEL_ENABLED
	#else
		#error "No FFKER_ISP_TRACE_CONFIG Tracing level defined"
	#endif
#else
	#error "FFKER_ISP_TRACE_CONFIG not defined"
#endif

/* Example:
IA_CSS_TRACE_0(module,severity,format);
IA_CSS_TRACE_0(FFKER_ISP, severity,format);
*/

#endif /* __ISP_TRACE_H */
