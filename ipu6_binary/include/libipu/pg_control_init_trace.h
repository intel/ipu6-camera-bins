/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2017 - 2018 Intel Corporation.
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

#ifndef __PG_CONTROL_INIT_TRACE_H
#define __PG_CONTROL_INIT_TRACE_H

#include "ia_css_trace.h"

/******************************************************************************
*                Module: Program control init
******************************************************************************/
#define PG_CONTROL_INIT_TRACE_LOG_LEVEL_OFF 0
#define PG_CONTROL_INIT_TRACE_LOG_LEVEL_NORMAL 1
#define PG_CONTROL_INIT_TRACE_LOG_LEVEL_DEBUG 2

/* prog control init and all the submodules in it
 * will have the default tracing level set to this level
 */
#define PG_CONTROL_INIT_TRACE_CONFIG_DEFAULT PG_CONTROL_INIT_TRACE_LOG_LEVEL_NORMAL

/* In case PG_CONTROL_INIT_TRACE_CONFIG is not defined, set it to default level */
#if !defined(PG_CONTROL_INIT_TRACE_CONFIG)
	#define PG_CONTROL_INIT_TRACE_CONFIG PG_CONTROL_INIT_TRACE_CONFIG_DEFAULT
#endif

#if (defined(PG_CONTROL_INIT_TRACE_CONFIG))
	/* TRACE_OFF */
	#if PG_CONTROL_INIT_TRACE_CONFIG == PG_CONTROL_INIT_TRACE_LOG_LEVEL_OFF
		#define PG_CONTROL_INIT_TRACE_METHOD              IA_CSS_TRACE_METHOD_NATIVE
		#define PG_CONTROL_INIT_TRACE_LEVEL_ASSERT        IA_CSS_TRACE_LEVEL_DISABLED
		#define PG_CONTROL_INIT_TRACE_LEVEL_ERROR         IA_CSS_TRACE_LEVEL_DISABLED
		#define PG_CONTROL_INIT_TRACE_LEVEL_WARNING       IA_CSS_TRACE_LEVEL_DISABLED
		#define PG_CONTROL_INIT_TRACE_LEVEL_INFO          IA_CSS_TRACE_LEVEL_DISABLED
		#define PG_CONTROL_INIT_TRACE_LEVEL_DEBUG         IA_CSS_TRACE_LEVEL_DISABLED
		#define PG_CONTROL_INIT_TRACE_LEVEL_VERBOSE       IA_CSS_TRACE_LEVEL_DISABLED
	/* TRACE_NORMAL */
	#elif PG_CONTROL_INIT_TRACE_CONFIG == PG_CONTROL_INIT_TRACE_LOG_LEVEL_NORMAL
		#define PG_CONTROL_INIT_TRACE_METHOD              IA_CSS_TRACE_METHOD_NATIVE
		#define PG_CONTROL_INIT_TRACE_LEVEL_ASSERT        IA_CSS_TRACE_LEVEL_ENABLED
		#define PG_CONTROL_INIT_TRACE_LEVEL_ERROR         IA_CSS_TRACE_LEVEL_ENABLED
		#define PG_CONTROL_INIT_TRACE_LEVEL_WARNING       IA_CSS_TRACE_LEVEL_ENABLED
		#define PG_CONTROL_INIT_TRACE_LEVEL_INFO          IA_CSS_TRACE_LEVEL_ENABLED
		#define PG_CONTROL_INIT_TRACE_LEVEL_DEBUG         IA_CSS_TRACE_LEVEL_DISABLED
		#define PG_CONTROL_INIT_TRACE_LEVEL_VERBOSE       IA_CSS_TRACE_LEVEL_DISABLED
	/* TRACE_DEBUG */
	#elif PG_CONTROL_INIT_TRACE_CONFIG == PG_CONTROL_INIT_TRACE_LOG_LEVEL_DEBUG
		#define PG_CONTROL_INIT_TRACE_METHOD              IA_CSS_TRACE_METHOD_NATIVE
		#define PG_CONTROL_INIT_TRACE_LEVEL_ASSERT        IA_CSS_TRACE_LEVEL_ENABLED
		#define PG_CONTROL_INIT_TRACE_LEVEL_ERROR         IA_CSS_TRACE_LEVEL_ENABLED
		#define PG_CONTROL_INIT_TRACE_LEVEL_WARNING       IA_CSS_TRACE_LEVEL_ENABLED
		#define PG_CONTROL_INIT_TRACE_LEVEL_INFO          IA_CSS_TRACE_LEVEL_ENABLED
		#define PG_CONTROL_INIT_TRACE_LEVEL_DEBUG         IA_CSS_TRACE_LEVEL_ENABLED
		#define PG_CONTROL_INIT_TRACE_LEVEL_VERBOSE       IA_CSS_TRACE_LEVEL_ENABLED
	#else
		#error "Incorrect PG_CONTROL_INIT_TRACE_CONFIG Tracing level defined"
	#endif
#endif

#endif /*__PG_CONTROL_INIT_TRACE_H*/
