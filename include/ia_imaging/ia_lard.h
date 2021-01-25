/*
 * Copyright 2012 - 2018 Intel Corporation
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
 * \file ia_lard.h
 * \brief Lard PCF parser specific implementation.
 */

#ifndef _IA_LARD_H_
#define _IA_LARD_H_

#include "ia_types.h"
#include "ia_mkn_types.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief available group tags, each group contains all of the tuning modes,
 * each mode, contains all of the records which are used for the different filters tunings.
 */
#define LCMC_TAG IA_MKN_CHTOUL('L','C','M','C')  /*!< CMC group header tag. */
#define LAIQ_TAG IA_MKN_CHTOUL('L','A','I','Q')  /*!< 3A+ group header tag. */
#define LISP_TAG IA_MKN_CHTOUL('L','I','S','P')  /*!< ISP group header tag. */
#define LTHR_TAG IA_MKN_CHTOUL('L','T','H','R')  /*!< Others group header tag. */


typedef struct ia_lard_t ia_lard;

/*!
 * \brief Initialize IA_LARD.
 * This function must be called before any other function in the library. It allocates needed memory and
 * parses given Lard CPF data. Initialization returns a handle to data of all parsed items, if given
 * data is valid Lard CPF data.
 *
 * \param[in]     lard_data_ptr    Mandatory although function will not return error, if it not given.\n
 * \return                         IA_LARD handle. Use the returned handle as input parameter for the consequent IA_LARD calls.
 */
LIBEXPORT ia_lard*
ia_lard_init(const ia_binary_data *lard_data_ptr);

/*!
 * \brief De-initialize IA_LARD.
 * All memory allocated by LARD is freed. LARD handle can no longer be used.
 *
 * \param[in] ia_lard              Mandatory.\n
 *                                 LARD instance handle.
 */
LIBEXPORT void
ia_lard_deinit(ia_lard *ia_lard_ptr);

/*!
 * \brief Input parameter structure for Lard run.
 * Please NOTICE!
 * the ISP group can use either index OR tag, the other groups are using tags to get
 * the correct thing mode.
 * for example
 * cmc_mode_tag = 'D','F','L','T'
 * aiq_mode_tag = 'L','O','W','L' (low light tunings which the user made up)
 * isp_mode_index = 1 OR 'D', 'F', 'L', 'T'
 * others_mode_tag = 'D','F','L','T'
 *
 *
 */
typedef struct
{
    unsigned int cmc_mode_tag;      /*!< Mandatory. CMC mode tag (4 letters) to be used with ia_lard_run. */
    unsigned int aiq_mode_tag;      /*!< Mandatory. AIQ mode tag (4 letters) to be used with ia_lard_run. */
    unsigned int isp_mode_index;    /*!< Mandatory. ISP mode index (number) or tag (4 letters) to be used with ia_lard_run. */
    unsigned int others_mode_tag;   /*!< Mandatory. Other mode tag (4 letters)to be used with ia_lard_run. */
} ia_lard_input_params;

/*!
* \brief Output parameter structure for ia_lard_run.
* Pointers to aiqb data of requested mode for each of the groups.
*/
typedef struct ia_lard_results
{
    ia_binary_data aiqb_cmc_data;      /*!< Mandatory. Aiqb binary data struct for CMC data. */
    ia_binary_data aiqb_aiq_data;      /*!< Mandatory. Aiqb binary data struct for AIQ data. */
    ia_binary_data aiqb_isp_data;      /*!< Mandatory. Aiqb binary data struct for ISP data. */
    ia_binary_data aiqb_other_data;    /*!< Mandatory. Aiqb binary data struct for Other data. */
} ia_lard_results;

/*!
 * \brief Lard run will give pointers to aiqb data of the requested modes of each group.
 *
 * \param[in] ia_lard_ptr               Mandatory.\n
 *                                      Lard instance handle.
 * \param[in] lard_input_params_ptr     Mandatory.\n
 *                                      Input parameters to tell modes that client is requesting.
 * \param[in/out] lard_results_ptr      Mandatory. \n
 *                                      Output pointer to aiqb data blocks of specific modes
 *                                      that client were requested with lard_input_params_ptr. NULL will
 *                                      be set if no modes are requested in some group or data for that
 *                                      mode can't be found.
 * \return                              Error code.
 */
LIBEXPORT ia_err
ia_lard_run(
    ia_lard *ia_lard_ptr,
    ia_lard_input_params *lard_input_params_ptr,
    ia_lard_results **lard_results_ptr);

/*!
 * \brief Get version.
 * Get version from version header.
 *
 * \return                              Lard version string.
 */
LIBEXPORT const char*
ia_lard_get_version(void);


/*!
 * \brief Get a list of all of the available tags for a given group
 * \param[in] ia_lard_ptr               Mandatory.\n
 *                                      Lard instance handle.
 * \param[in] mode_tag                  Mandatory.\n
 *                                      Mode tag (LAIQ, LISP, LCMC, LTHR)
 * \param[out] num_tags                 Mandatory.\n
 *                                      number of tunings available for given mode tag
 * \param[out] tags                     Mandatory.\n
 *                                      tags of available tunings for given mode tag
 * \return                              Error code.
 */
LIBEXPORT ia_err ia_lard_get_tag_list(ia_lard* ia_lard_ptr, const unsigned int mode_tag, unsigned int* num_tags, const unsigned int** tags);


#ifdef __cplusplus
}
#endif

#endif /* _IA_LARD_H_ */
