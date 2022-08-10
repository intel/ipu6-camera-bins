/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2017-2018 Intel Corporation. All Rights Reserved.
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

#ifndef __GCSS_FORMATS_H__
#define __GCSS_FORMATS_H__

#ifdef __cplusplus
#include <ia_tools/css_types.h>
#include <ia_cipf/ia_cipf_types.h>

#include <map>
#include <vector>
#include <string>

namespace GCSSFormats {

struct ia_format_plane_t {
    std::string name;
    int32_t bpp;
};
typedef std::vector<ia_format_plane_t> planes_vector_t;

/**
 * Container for common format data. Last member is reserved for user to
 * add own identifier for the format.
 */
struct ia_format_t {
    std::string      name;        /**< format name                            */
    uint32_t         fourcc;      /**< int representation of the format       */
    std::string      type;        /**< format type (BAYER, YUV)               */
    int32_t          bpp;         /**< bits per pixel                         */
    int32_t          precision;   /**< meaningful bits per element            */
    int32_t          bpe;         /**< bits per element                       */
    int32_t          vector_size; /**< 0, if data is not vectorized           */
    bool             packed;      /**< packed yes = true, no = false            */
    bool             compressed;  /**< Format compressed: true, otherwise false */
    planes_vector_t  planes;      /**< vector to contain planes, if available   */
    uint32_t         os_id;       /**< Reserved for user defined id. This is to
                                       associate OS-defined formats with the
                                       common XOS formats */
};

typedef std::vector<ia_format_t> formats_vector_t;


/**
 * Initializes thet GCSSFormats object internal data
 */
void initGCSSFormats();

/**
 * Get format by name

 * \param[in] name
 * \param[out] format
 * \return css_err_none at success
 */
css_err_t getFormatByName(const std::string &name, ia_format_t &format);

/**
* Get format by fourcc

* \param[in] fourcc
* \param[out] format
* \return css_err_none at success
*/
css_err_t getFormatByFourcc(uint32_t fourcc, ia_format_t &format);

/**
* Get plane count by fourcc

* \param[in] fourcc
* \return plane count
*/
int32_t getPlaneCountByFourcc(uint32_t fourcc);

/**
 * set user defined id for format
 *
 * Searches vector of formats by name and sets id. The id is used to associate
 * os defined formats with the formats provided by xos.
 *
 * \param[in] name,     Name of the format to which to set the id
 * \param[in] id,       the user defined id
 */
css_err_t setFormatId(const std::string &name, uint32_t id);

/**
 * Calculate bytes per line(bpl) for a given format
 *
 * \param[in] format
 * \param[in] width, in pixels
 * \return bpl bytes per line
 */
uint32_t getBpl(const ia_format_t &format, uint32_t width);

/**
* Calculate buffer size for format
*
* \param[in] gcssFormat Format of the frame for which the size is to be calculated
* \param[in] width In pixels
* \param[in] height In pixels
* \param[in] bpl Calculated based on format and width, if not given by caller
* \param[out] tsOffsets (Optional) A caller-provided array of size MAX_TS_OFFSETS, for outputting TS offsets (For compressed frames.)
* \param[out] tsSizes (Optional) A caller-provided array of size MAX_TS_OFFSETS, for outputting TS sizes (For compressed frames.)
* \return buffer size
*/
uint32_t calculateBufferSize(
    const ia_format_t &gcssFormat,
    uint32_t width,
    uint32_t height,
    uint32_t bpl = 0,
    unsigned int tsOffsets[] = NULL,
    unsigned int tsSizes[] = NULL);

/**
*  Tells whether a given format is compressed or not
*
*  \param[in] name Format to query for being compressed
*  \return true, if format is a compressed format, false otherwise
*/
bool isCompressedFormat(const std::string &name);

} // namespace

#else
/**
  *  Tells whether a given format is compressed or not
  *
  *  \param[in] fourcc Format to query for being compressed
  *  \return true, if format is a compressed format, false otherwise
*/
bool isCompressedFormat(uint32_t fourcc);

/**
* Calculate bytes per line(bpl) for a given format
*
* \param[in] format
* \param[in] width, in pixels
* \return bpl bytes per line
*/
uint32_t getBpl(uint32_t fourcc, uint32_t width);

#endif // _cplusplus

#endif // __GCSS_FORMATS_H__
