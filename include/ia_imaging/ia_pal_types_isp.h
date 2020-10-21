/*
* INTEL CONFIDENTIAL
* Copyright (c) 2016-2018 Intel Corporation
* All Rights Reserved.
*
* The source code contained or described herein and all documents related to
* the source code (Material) are owned by Intel Corporation or its
* suppliers or licensors. Title to the Material remains with Intel
* Corporation or its suppliers and licensors. The Material may contain trade
* secrets and proprietary and confidential information of Intel Corporation
* and its suppliers and licensors, and is protected by worldwide copyright
* and trade secret laws and treaty provisions. No part of the Material may be
* used, copied, reproduced, modified, published, uploaded, posted,
* transmitted, distributed, or disclosed in any way without Intel's prior
* express written permission.
*
* No license under any patent, copyright, trade secret or other intellectual
* property right is granted to or conferred upon you by disclosure or
* delivery of the Materials, either expressly, by implication, inducement,
* estoppel or otherwise. Any license under such intellectual property rights
* must be express and approved by Intel in writing.
*
* Unless otherwise agreed by Intel in writing, you may not remove or alter
* this notice or any other notice embedded in Materials by Intel or Intel's
* suppliers or licensors in any way.
*/

#ifndef IA_PAL_TYPES_ISP_H_
#define IA_PAL_TYPES_ISP_H_

#ifdef __cplusplus
extern "C"{
#endif

/*!
 * \brief Common header for all PAL output data structures.
 */
typedef struct
{
    int uuid;                   /*!< UUID of PAL output. Indicates, which ISP block configuration this record contains. */
    int size;                   /*!< Size of PAL output for a particular kernel. */
    bool update;                /*!< Flag indicating if PAL calculations updated results. */
    char enable;                /*!< Three-state kernel enable (passthrough, enable, disable) */
    unsigned int run_time_diff; /*!< Time difference since these PAL results were previously calculated. */
    unsigned short width;       /*!< Input width of frame for this ISP block. */
    unsigned short height;      /*!< Input height of frame for this ISP block. */
} ia_pal_record_header;


#ifdef __cplusplus
}
#endif

#endif /* IA_PAL_TYPES_ISP_H_ */
