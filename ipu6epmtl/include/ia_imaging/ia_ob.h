/*
 * Copyright 2017-2018 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/*!
 * \mainpage IA OB API documentation
 *
 * Browse Files and Classes tabs for details.
 *
 */
/*!
 * \file ia_ob.h
 * \brief Definitions and declarations of IA OB library.
 */
#ifndef _IA_OB_H_
#define _IA_OB_H_

#include "ia_types.h"

#define IA_OB_DEBUG
#if defined IA_OB_DEBUG
#define IA_OB_LOG(fmt, ...)       IA_LOG(ia_log_debug, "IAOB: " fmt, ## __VA_ARGS__)
#define IA_OB_LOG_ERROR(fmt, ...) IA_LOG(ia_log_error, "IAOB: ERROR: " fmt, ## __VA_ARGS__)
#define DEBUG_BUFFER_SIZE 1024*7
#else
#define IA_OB_LOG            IA_NOLOG
#define IA_OB_LOG_ERROR      IA_NOLOG
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define IA_OB_VERSION "1.0.0.0"
typedef struct ia_ob_t ia_ob;

typedef enum
{
    ia_ob_interleave_none,
    ia_ob_interleave_two,
} ia_ob_interleave_mode;

/*!
 * \brief OB runtime input.
 */
typedef struct {
    short *frame_data;       /*!< fixed point image */
    unsigned int frame_width;         /*!< current frame width (might be cropped) */
    unsigned int frame_height;        /*!< current frame height (might be cropped) */
    unsigned int ob_top;
    unsigned int ob_left;
    unsigned int ob_width;
    unsigned int ob_height;
    ia_ob_interleave_mode interleave_step;
} ia_ob_input;

/*!
 * \brief OB per-run output.
 */
typedef struct {
    float cc00;
    float cc01;
    float cc10;
    float cc11;
} ia_ob_output;                 /*!< OB ouput for 4 color components */

LIBEXPORT ia_ob*
ia_ob_init(void);

LIBEXPORT void
ia_ob_deinit(ia_ob *ia_ob);

LIBEXPORT ia_err
ia_ob_run(ia_ob *ia_ob,
          const ia_ob_input *ob_input,
          ia_ob_output *ob_output);

#ifdef __cplusplus
}
#endif
#endif /* _IA_OB_H_ */
