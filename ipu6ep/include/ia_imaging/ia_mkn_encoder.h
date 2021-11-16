/*
 * Copyright 2012-2021, Intel Corporation
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
 * \file ia_mkn_encoder.h
 * \brief Definitions of functions to control and add records to Maker Note.
*/

#ifndef IA_MKN_ENCODER_H_
#define IA_MKN_ENCODER_H_

#include <stddef.h>
#include "ia_types.h"
#include "ia_mkn_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Creates Make Note system handle.
 * Allocates and initializes makernote handle. Handle must be given as input parameter to all consequent ia_mkn calls.
 *
 * \param[in] a_mkn_config_bits       Mandatory.\n
 *                                  Configuration flag bits.
 * \param[in] a_mkn_section_1_size    Mandatory.\n
 *                                  Size of Section 1 data buffer.
 * \param[in] a_mkn_section_2_size    Mandatory.\n
 *                                  Size of Section 2 data buffer.
 * \return                          Pointer to the makernote handle.
 */
LIBEXPORT ia_mkn*
ia_mkn_init(ia_mkn_config_bits a_mkn_config_bits,
            size_t a_mkn_section_1_size,
            size_t a_mkn_section_2_size);

/*!
 * \brief Deletes Make Note system handle.
 *
 * \param[in] a_mkn_ptr                Mandatory. \n
 *                               Pointer to makernote handle.
 * \return                       Error code.
 */
LIBEXPORT void
ia_mkn_uninit(ia_mkn *a_mkn_ptr);

/*!
 * \brief Reset Make Note system to default state.
 *
 * \param[in] a_mkn_data_ptr                Mandatory. \n
 *                               Pointer to makernote handle obtained from ia_mkn_init function call.
 * \return                       Error code.
 */
LIBEXPORT ia_err
ia_mkn_reset(ia_mkn *a_mkn_data_ptr);

/*!
 * \brief Adds or updates a data record in the makernote.
 *
 * \param[in] a_mkn_data_ptr     Mandatory. \n
 *                               Pointer to makernote handle obtained from ia_mkn_init function call.
 * \param[in] a_data_format_id   Mandatory.\n
 *                               Record data format ID.
 * \param[in] a_data_name_id     Mandatory.\n
 *                               Record name ID.
 * \param[in] a_data_ptr         Mandatory.\n
 *                               Pointer to record data to be copied into the makernote. Size of data to be copied is calculated
 *                               from on DFID and number of elements.
 * \param[in] a_num_elements     Mandatory.\n
 *                               Number of elements to store.
 * \param[in] a_key              Mandatory.\n
 *                               Packing key (16 bytes). NULL means 'no packing'.
 * \return                       Error code.
*/
LIBEXPORT ia_err
ia_mkn_add_record(ia_mkn *a_mkn_data_ptr,
                  ia_mkn_dfid a_data_format_id,
                  ia_mkn_dnid a_data_name_id,
                  const void *a_data_ptr,
                  uint32_t a_num_elements,
                  const char *a_key);

/*!
 * \brief Deletes a data record from the makernote.
 *
 * \param[in] a_mkn_data_ptr     Mandatory. \n
 *                               Pointer to makernote handle obtained from ia_mkn_init function call.
 * \param[in] a_data_format_id     Mandatory.\n
 *                               Record data format ID.
 * \param[in] a_data_name_id       Mandatory.\n
 *                               Record name ID.
 * \return                       Error code.
*/
LIBEXPORT ia_err
ia_mkn_delete_record(ia_mkn *a_mkn_data_ptr,
                     ia_mkn_dfid a_data_format_id,
                     ia_mkn_dnid a_data_name_id);

/*!
 * \brief Prepares makernote so that it can be included into the EXIF.
 * Based on data target: Section 1 can be used by client for example for EXIF or Section 2 where all (Section 1 & Section 2) records will be included.
 * calculates checksum, updates total size of makernote data, compresses and pack makernote data.
 *
 * \param[in] a_mkn_data_ptr     Mandatory. \n
 *                               Pointer to makernote handle obtained from ia_mkn_init function call.
 * \param[in] a_data_target      Target of the makernote as defined in enum ia_mkn_trg.
 * \return                       Binary data structure with pointer and size of data..
 */
LIBEXPORT ia_binary_data
ia_mkn_prepare(ia_mkn *a_mkn_data_ptr,
               ia_mkn_trg a_data_target);

/*!
 * \brief Enable/Disable makernote data collecting.
 *
 * \param[in] a_mkn_data_ptr     Mandatory. \n
 *                               Pointer to makernote handle obtained from ia_mkn_init function call.
 * \param a_enable_data_collection Mandatory.\n
 *                               Enable/disable data collection.
 * \return                       Error code.
*/
LIBEXPORT ia_err
ia_mkn_enable(ia_mkn *a_mkn_data_ptr,
              bool a_enable_data_collection);

/*!
 * \brief Merge two makernotes.
 * Copies all records from source makernote to the target makernote. Existing same records in the target are overwritten by source record.
 * Both makernotes must be created with the same makernote library ie. have the same internal structure.
 * After merging makernotes, ia_mkn_prepare() function must be called before using the merged makernote.
 *
 * \param[in,out] a_mkn_trg_ptr   Target makernote. Source makernote will be merged into this.
 * \param[in]     a_mkn_src_ptr   Source makernote.
 * \return                       Error code.
 */
LIBEXPORT ia_err
ia_mkn_merge(ia_mkn *a_mkn_trg_ptr,
             const ia_mkn *a_mkn_src_ptr);

/*!
 * \brief Converts makernote (MKNT) binary data to full MKN data.
 *  Allocates full MKN data and copies the content of (MKNT) binary data to MKN.
 *
 * \param[in]     a_mknt_data_ptr  Pointer to the makernote (MKNT) binary data.
 * \return                       Pointer to the makernote handle.
 */
LIBEXPORT ia_mkn*
ia_mknt_to_mkn(const ia_binary_data *a_mknt_data_ptr);

#ifdef __cplusplus
}
#endif

#endif /* IA_MKN_ENCODER_H_ */
