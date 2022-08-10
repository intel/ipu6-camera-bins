/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2013-2021 Intel Corporation. All Rights Reserved.
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

/**
 * \file ia_cipr_log.h
 *
 * Debug log print header
 *
 * \defgroup ia_log Debug log interface
 * \ingroup ia_cipr
 *
 * Debug log print interface for wrapping platform specific log interfaces.
 */

#ifndef IA_CIPR_LOG_H_
#define IA_CIPR_LOG_H_
#include <stdarg.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum ia_cipr_log_level {
    IA_CSS_LOG_LEVEL_OFF  = 0,   /**< to allow returning a "no logs" level */
    IA_CSS_LOG_LEVEL_D    = 1,
    IA_CSS_LOG_LEVEL_V    = 2,
    IA_CSS_LOG_LEVEL_M    = 4,
    IA_CSS_LOG_LEVEL_ENTRY= 8,
    IA_CSS_LOG_LEVEL_ERR  = 16,
    IA_CSS_LOG_LEVEL_WARN = 32,
    IA_CSS_LOG_LEVEL_DUMP = 64,
    IA_CSS_LOG_LEVEL_SCOPED = 128, /**< reserved for submodule scopes,
                                   do not use this bit directly! */

    /* Make logs persistent, retrying if logcat is busy. Can be combined with
     * other log levels. Aligning with HAL. */
    IA_CSS_LOG_PERSIST    = 4096
} ia_cipr_log_level_t;

/* Define CONTEXT_PRETTY to output four-letter combination instead of pointer */
#define CONTEXT_PRETTY

/* Logging context */
struct log_context {
#ifdef CONTEXT_PRETTY
    char *value;
#else
    void *value;
#endif
    char name[5];
};

#define CSS_DEBUG_ENTRY()           _CSS_DEBUG(IA_CSS_LOG_LEVEL_ENTRY, \
                                               "E:%s", __FUNCTION__)

#if (defined(RNDBUILD) && defined(USE_CSS_IA_TRACE))
void ia_css_trace_begin(unsigned long long tag, const char* name);
void ia_css_trace_end(unsigned long long tag);
#define CSS_IA_TRACE_BEGIN(name) \
        ia_css_trace_begin(1, name)
#define CSS_IA_TRACE_END() \
        ia_css_trace_end(1)
#else
#define CSS_IA_TRACE_BEGIN(...)     ((void)0)
#define CSS_IA_TRACE_END(...)       ((void)0)
#endif //RNDBUILD

#if defined(RNDBUILD)

void* ia_log_create_context(void *ref);
void ia_log_destroy_context(void *context);

void ia_css_vdebug(ia_cipr_log_level_t level,
                   const char *tag,
                   const char *fmt,
                   va_list args);
#ifdef _MSC_VER
void ia_css_vdebug_console(ia_cipr_log_level_t level,
                   const char *tag,
                   const char *fmt,
                   va_list args);
#endif

/* Define CONTEXT_PRETTY to output four-letter combination instead of pointer */
#if defined(CONTEXT_PRETTY)
#define CONTEXT_PREFIX "P[%s] "
#else
#define CONTEXT_PREFIX "P[%p] "
#endif //CONTEXT_PRETTY

#define CONTEXT_ARGS_NOT_NULL(p) ((p) && (p)->context && (p)->context->value)

/* Create and allocate memory for the context. */
#define CSS_CONTEXT_CREATE(p)                                               \
    do {                                                                    \
    if (p) {                                                                \
        (p)->context = ia_log_create_context(p);                            \
        CSS_CONTEXT_DEBUG((p), "Created logging context");                  \
    }                                                                       \
    } while ((void)0,0)

/* Assign the same context to another object */
#define CSS_CONTEXT_SET(to, from)                                           \
    do {                                                                    \
    if((to) && (from) && (from)->context) {                                 \
        (to)->context = (from)->context;                                    \
    }                                                                       \
    } while ((void)0,0)

/* Free allocated memory for context */
#define CSS_CONTEXT_DESTROY(p)                                              \
    do {                                                                    \
    if ((p) && (p)->context) {                                              \
        ia_log_destroy_context((p)->context);                               \
    }                                                                       \
    } while ((void)0,0)

/* Debugging with context */
#define CSS_CONTEXT_DEBUG(p, ...) CSS_CONTEXT_DEBUG_(p, __VA_ARGS__, "")

#define CSS_CONTEXT_DEBUG_(p, msg, ...)                                         \
    do {                                                                        \
    if (CONTEXT_ARGS_NOT_NULL(p)) {                                             \
        CSS_DEBUG(CONTEXT_PREFIX msg "%s", (p)->context->value, __VA_ARGS__);   \
    } else {                                                                    \
        CSS_DEBUG(msg "%s", __VA_ARGS__);                                       \
    }                                                                           \
    } while ((void)0,0)

/* Verbose debugging with context */
#define CSS_CONTEXT_DEBUG_V(p, ...) CSS_CONTEXT_DEBUG_V_(p, __VA_ARGS__, "")

#define CSS_CONTEXT_DEBUG_V_(p, msg, ...)                                       \
    do {                                                                        \
    if (CONTEXT_ARGS_NOT_NULL(p)) {                                             \
        CSS_DEBUG_V(CONTEXT_PREFIX msg "%s", (p)->context->value, __VA_ARGS__); \
    } else {                                                                    \
        CSS_DEBUG_V(msg "%s", __VA_ARGS__);                                     \
    }                                                                           \
    } while ((void)0,0)

/* Memory debugging with context */
#define CSS_CONTEXT_DEBUG_M(p, ...) CSS_CONTEXT_DEBUG_M_(p, __VA_ARGS__, "")

#define CSS_CONTEXT_DEBUG_M_(p, msg, ...)                                       \
    do {                                                                        \
    if (CONTEXT_ARGS_NOT_NULL(p)) {                                             \
        CSS_DEBUG_M(CONTEXT_PREFIX msg "%s", (p)->context->value, __VA_ARGS__); \
    } else {                                                                    \
        CSS_DEBUG_M(msg "%s", __VA_ARGS__);                                     \
    }                                                                           \
    } while ((void)0,0)

/* Error debugging with context */
#define CSS_CONTEXT_DEBUG_ERR(p, ...) \
    CSS_CONTEXT_DEBUG_ERR_(p, __VA_ARGS__, "")

#define CSS_CONTEXT_DEBUG_ERR_(p, msg, ...)                                         \
    do {                                                                            \
    if (CONTEXT_ARGS_NOT_NULL(p)) {                                                 \
        CSS_DEBUG_ERR(CONTEXT_PREFIX msg "%s", (p)->context->value, __VA_ARGS__);   \
    } else {                                                                        \
        CSS_DEBUG_ERR(msg "%s", __VA_ARGS__);                                       \
    }                                                                               \
    } while ((void)0,0)

/* Warn debugging with context */
#define CSS_CONTEXT_DEBUG_WARN(p, ...) \
    CSS_CONTEXT_DEBUG_WARN_(p, __VA_ARGS__, "")

#define CSS_CONTEXT_DEBUG_WARN_(p, msg, ...)                                        \
    do {                                                                            \
    if (CONTEXT_ARGS_NOT_NULL(p)) {                                                 \
        CSS_DEBUG_WARN(CONTEXT_PREFIX msg "%s", (p)->context->value, __VA_ARGS__);  \
    } else {                                                                        \
        CSS_DEBUG_WARN(msg "%s", __VA_ARGS__);                                      \
    }                                                                               \
    } while ((void)0,0)

/* Entry logging with context, argument is object with context member */
#define CSS_CONTEXT_ENTRY(p)        do {                                    \
                                    if (CONTEXT_ARGS_NOT_NULL(p)) {         \
                                        CSS_CONTEXT_ENTRY_(p);              \
                                    } else {                                \
                                        CSS_DEBUG_ENTRY();                  \
                                    }                                       \
                                    } while ((void)0,0)

#define CSS_CONTEXT_ENTRY_(p)                                               \
    _CSS_DEBUG(IA_CSS_LOG_LEVEL_ENTRY, \
               CONTEXT_PREFIX "E:%s", \
               (p)->context->value, \
               __FUNCTION__)

#else
#define CSS_CONTEXT_SET(...)            ((void)0)
#define CSS_CONTEXT_CREATE(...)         ((void)0)
#define CSS_CONTEXT_DESTROY(...)        ((void)0)
#define CSS_CONTEXT_DEBUG(p, ...)       CSS_DEBUG(__VA_ARGS__)
#define CSS_CONTEXT_DEBUG_V(p, ...)     CSS_DEBUG_V(__VA_ARGS__)
#define CSS_CONTEXT_DEBUG_M(p, ...)     CSS_DEBUG_M(__VA_ARGS__)
#define CSS_CONTEXT_DEBUG_ERR(p, ...)   CSS_DEBUG_ERR(__VA_ARGS__)
#define CSS_CONTEXT_DEBUG_WARN(p, ...)  CSS_DEBUG_WARN(__VA_ARGS__)
#define CSS_CONTEXT_ENTRY(...)          CSS_DEBUG_ENTRY()
#endif //RNDBUILD

ia_cipr_log_level_t ia_css_debug_level(void);
const char* ia_css_debug_dump_path(void);
/* getter for log related configuration values. Could be from environment,
   registry or similar source.*/
int32_t ia_log_get_config_int32(const char *id);
/* log level initializer */
void ia_log_common_init(void);

#ifdef RNDBUILD
#define CSS_DEBUG_LEVEL ia_css_debug_level()
#else
#define CSS_DEBUG_LEVEL 0
#endif

#define LIBIACSS_POSTFIX "[XOS]"
#define LIBIACSS_TAG LOG_TAG LIBIACSS_POSTFIX

#if defined(USE_PRINTF_DEBUGGING)
#include <stdio.h>

#if defined(ENABLE_DEBUG_LOG)
#define CSS_DEBUG_ENABLED 2
#else
#define CSS_DEBUG_ENABLED 0
#endif

#ifdef _WIN32
#define PRINTF_HELPER(fmt, ...)     do {                                    \
                                        printf(fmt, __VA_ARGS__);           \
                                        printf("\n");                       \
                                    } while ((void)0,0)
#define _CSS_DEBUG(level, ...)  PRINTF_HELPER("D " LIBIACSS_TAG " " __VA_ARGS__)
#define _CSS_DEBUG_VFMT(level, fmt, ...)  do { printf("D " LIBIACSS_TAG " "); vprintf(fmt, __VA_ARGS__); printf("\n"); } while((void)0,0)
#define CSS_DEBUG(...)          PRINTF_HELPER("D " LIBIACSS_TAG " " __VA_ARGS__)
#define CSS_DEBUG_V(...)        PRINTF_HELPER("V " LIBIACSS_TAG " " __VA_ARGS__)
#define CSS_DEBUG_M(...)        PRINTF_HELPER("M " LIBIACSS_TAG " " __VA_ARGS__)
#define CSS_DEBUG_ERR(...)      PRINTF_HELPER("E " LIBIACSS_TAG " " __VA_ARGS__)
#define CSS_DEBUG_WARN(...)     PRINTF_HELPER("W " LIBIACSS_TAG " " __VA_ARGS__)
#else
#define PRINTF_HELPER(fmt, ...)     do {                                    \
                                        printf(fmt "%s\n", __VA_ARGS__);           \
                                    } while ((void)0,0)
#define _CSS_DEBUG(level, ...)  PRINTF_HELPER("D " LIBIACSS_TAG " " __VA_ARGS__, "")
#define _CSS_DEBUG_VFMT(level, fmt, ...)  do { printf("D " LIBIACSS_TAG " "); vprintf(fmt, __VA_ARGS__); printf("\n"); } while((void)0,0)
#define CSS_DEBUG(...)          PRINTF_HELPER("D " LIBIACSS_TAG " " __VA_ARGS__, "")
#define CSS_DEBUG_V(...)        PRINTF_HELPER("V " LIBIACSS_TAG " " __VA_ARGS__, "")
#define CSS_DEBUG_M(...)        PRINTF_HELPER("M " LIBIACSS_TAG " " __VA_ARGS__, "")
#define CSS_DEBUG_ERR(...)      PRINTF_HELPER("E " LIBIACSS_TAG " " __VA_ARGS__, "")
#define CSS_DEBUG_WARN(...)     PRINTF_HELPER("W " LIBIACSS_TAG " " __VA_ARGS__, "")
#endif
#ifdef RNDBUILD
#define CSS_DEBUG_DUMP(x) \
        if (CSS_DEBUG_LEVEL & IA_CSS_LOG_LEVEL_DUMP) {x;}
#else
#define CSS_DEBUG_DUMP(x)
#endif
#elif defined(RNDBUILD)

#if defined(ENABLE_DEBUG_LOG)
#define CSS_DEBUG_ENABLED 1
#else
#define CSS_DEBUG_ENABLED 0
#endif

/* original log functions. OS implementations varied. Now
   these are called via the common log functions. */
void ia_css_debug(ia_cipr_log_level_t level,
                  const char *tag,
                  const char *fmt,
                  ...);

/* Common log functions. OS teams are not allowed to implement these. */
void ia_log_common_debug(ia_cipr_log_level_t level,
    const char *tag,
    const char *fmt,
    ...);
void ia_log_common_vdebug(ia_cipr_log_level_t level,
    const char *tag,
    const char *fmt,
    va_list args);

/**
 * \ingroup ia_log
 * normal debug
 */
#define _CSS_DEBUG(level, ...) \
        ia_log_common_debug(level, LIBIACSS_TAG, __VA_ARGS__)

/**
* \ingroup ia_log
* normal debug
*/
#define _CSS_DEBUG_VFMT(level, fmt, ...) \
        ia_log_common_vdebug(level, LIBIACSS_TAG, fmt, __VA_ARGS__)

/**
 * \ingroup ia_log
 * normal debug
 */
#define CSS_DEBUG(...) \
        ia_log_common_debug(IA_CSS_LOG_LEVEL_D, LIBIACSS_TAG, __VA_ARGS__)

/**
 * \ingroup ia_log
 * verbose debug
 */
#define CSS_DEBUG_V(...) \
        ia_log_common_debug(IA_CSS_LOG_LEVEL_V, LIBIACSS_TAG, __VA_ARGS__)

/**
 * \ingroup ia_log
 * memory allocation & free debug
 */
#define CSS_DEBUG_M(...) \
        ia_log_common_debug(IA_CSS_LOG_LEVEL_M, LIBIACSS_TAG, __VA_ARGS__)

/**
 * \ingroup ia_log
 * error debug
 */
#define CSS_DEBUG_ERR(...) \
        ia_log_common_debug(IA_CSS_LOG_LEVEL_ERR, LIBIACSS_TAG, __VA_ARGS__)

/**
 * \ingroup ia_log
 * warning debug
 */
#define CSS_DEBUG_WARN(...) \
        ia_log_common_debug(IA_CSS_LOG_LEVEL_WARN, LIBIACSS_TAG, __VA_ARGS__)


/**
 * \ingroup ia_log
 * scope macro for debug dump related code
 */
#define CSS_DEBUG_DUMP(x) \
        if (CSS_DEBUG_LEVEL & IA_CSS_LOG_LEVEL_DUMP) {x;}

#else
#define CSS_DEBUG_ENABLED 0
#define _CSS_DEBUG(level, ...) ((void)0)
#define CSS_DEBUG(...)      ((void)0)
#define CSS_DEBUG_V(...)    ((void)0)
#define CSS_DEBUG_M(...)    ((void)0)
#define CSS_DEBUG_ERR(...)  ((void)0)
#define CSS_DEBUG_WARN(...) ((void)0)
#define CSS_DEBUG_DUMP(x)   ((void)0)
#endif

/**
 * \ingroup ia_log
 * Helper function to get version information.
 */
const char *ia_css_get_version_string(void);

#ifdef __cplusplus
}
#endif

#endif /* IA_LOG_H_ */
