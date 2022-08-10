/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2016-2021 Intel Corporation
 * All Rights Reserved.
 *
 * The source code contained or described herein and all documents related to
 * the source code ("Material") are owned by Intel Corporation or its
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
 * this notice or any other notice embedded in Materials by Intel or Intels
 * suppliers or licensors in any way.
 */

/*!
 * \file ia_aiqb_parser.h
 * \brief Generic parser of new AIQB file format.
 *
 * New AIQB format assumes that records can be typecasted directly into structures. This means that when using some variable data types in
 * 32 or 64 bit environments, they occupy different amount of space. Thus AIQB needs to be contructed differently for those environments.
 * See https://en.wikipedia.org/wiki/Data_structure_alignment#Typical_alignment_of_C_structs_on_x86 for reference.
 *
 * Also, structure (and enum) packing must be disabled when constructing AIQB file (or structure packing needs taken into account when creating AIQB).
 * See https://en.wikipedia.org/wiki/Data_structure_alignment#Default_packing_and_.23pragma_pack for reference.
 *
 */


#ifndef IA_AIQB_PARSER_H_
#define IA_AIQB_PARSER_H_

#include "ia_types.h"
#include "ia_mkn_decoder.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _DEBUG
#ifdef __ANDROID__
#include <utils/Log.h>
#define IA_AIQB_LOG(...)      ((void)ALOG(LOG_DEBUG, "IA_AIQB: ", __VA_ARGS__))
#define IA_AIQB_LOG_ERR(...)  ((void)ALOG(LOG_ERROR, "IA_AIQB: ", __VA_ARGS__))
#else
#include <stdio.h>
#define IA_AIQB_LOG(fmt, ...)     fprintf(stdout, "IA_AIQB: " fmt "\n", ## __VA_ARGS__)
#define IA_AIQB_LOG_ERR(fmt, ...) fprintf(stderr, "IA_AIQB: " fmt "\n", ## __VA_ARGS__)
#endif
#else
#define IA_AIQB_LOG(...) ((void)0)
#define IA_AIQB_LOG_ERR(...) ((void)0)
#endif

/*!
 * \brief Offset information about pointers and data tables inside AIQB record.
 *
 * Using the offset information parser inserts correct memory address into structures' pointer values.
 */
typedef struct
{
    uint32_t offset_to_pointer;  /*!< Offset from the beginning of the record to a pointer in the typecasted structure. */
    uint32_t offset_to_data;     /*!< Offset from the beginning of the record to data where offset_to_pointer needs to reference. */
} ia_aiqd_parser_offset_map;

/*!
 * \brief Tells how many offset maps there are.
 *
 * AIQB file contains as many maps as there are pointers in the tuning structure.
 */
typedef struct
{
    uint32_t checksum;         /*!< Checksum of record data after ia_mkn_header and before ia_aiqd_parserr_offset_map and ia_aiqd_parserr_maps_info calculated with function ia_aiqb_parse_checksum(). */
    uint32_t num_maps;         /*!< Number of ia_aiqd_parserr_offset_map (maps) structures after the record data. */
} ia_aiqd_parser_maps_info;

/*!
 * \brief Calculates checksum of given memory using unsigned 32 bit values.
 *
 * Function will round down number of elements to sum, if size given is not multiple of 4 bytes. However this should never happen because sizeof(struct) is always multiple of 4 bytes.
 *
 * \param[in] data  Buffer from where checksum is calculated.
 * \param[in] count Size of buffer to sum in bytes.
 * \return          Calculated checksum.
 */
LIBEXPORT uint32_t
ia_aiqb_parse_calculate_checksum(void * a_data_ptr, size_t a_size);


/*!
* \brief Replace pointers in the AIQB data from map.
*
* Modifies contents of the given AIQB record data buffer by updating pointer values in the record to valid memory address.
* Map in the end of the record tells offset to pointers which need to be updated. Record has following structure:
*
* ia_mkn_record_header record_header;
* char record_data[record_header.size - (maps_info.num_maps * sizeof(ia_aiqd_parser_offset_map) + sizeof(ia_aiqd_parser_maps_info))];
* ia_aiqd_parser_offset_map maps[maps_info.num_maps];
* ia_aiqd_parser_maps_info maps_info;
*
* \param[in,out] record AIQB record buffer including all data listed above (header + data).
* \return               Error code.
*/
LIBEXPORT ia_err
ia_aiqb_parse_record(ia_mkn_record_header * a_record_ptr);

/*!
 * \brief Replace pointers in the AIQB data from map.
 *
 * Modifies contents of the given AIQB data buffer by updating pointer values in all records to valid memory address.
 *
 * \param[in,out] aiqb_binary AIQB data buffer
 * \return                    Error code.
 */
LIBEXPORT ia_err
ia_aiqb_parse(ia_binary_data * a_aiqb_binary_ptr);

#ifdef __cplusplus
}
#endif

#endif /* IA_AIQB_PARSER_H_ */
