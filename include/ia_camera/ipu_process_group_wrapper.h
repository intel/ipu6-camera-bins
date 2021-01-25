/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2013-2018 Intel Corporation. All Rights Reserved.
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

/** \file ipu_process_group_wrapper.h
 *
 * \defgroup ipu_process_group_wrapper IPU Process Group Wrapper
 * \ingroup ia_camera
 * \brief Tentative wrapper for process group create and steps to encode to
 * and decode from its terminal payloads.
 *
 * The intention of this wrapper is to make OS dependent code agnostic
 * of PG specification internals (the kernels) operated by cross-os imaging
 * stack. OS dependent code (HAL) is responsible to query and allocate the
 * memory requirements, construct the process group object as well as give
 * data address mappings for P2P to encode to and decode from the terminal
 * payloads. In proposed architecture this type of interface would be owned
 * by the imaging libraries.
 */
#ifndef __IPU4_PROCESS_GROUP_WRAPPER_H__
#define __IPU4_PROCESS_GROUP_WRAPPER_H__

#include <ia_tools/css_types.h>
#include <ia_p2p_types.h>

/* @todo Terminal memory shall be dynamically allocated */
#define IPU_MAX_TERMINAL_COUNT 40
#define IPU_MAX_KERNELS_PER_PG 64 /*!< DEPRECATED, max number of kernels is
                                       defined by fw in ia_css_kernel_bitmap.h
                                       as IA_CSS_KERNEL_BITMAP_BITS */

typedef struct ipu_pg_die_s* ipu_pg_die_t;

typedef struct ipu_pg_die_fragment_desc_s
{
    uint16_t fragment_width;    /*!< The width of the fragment. */
    uint16_t fragment_height;   /*!< The height of the fragment. */
    uint16_t fragment_start_x;  /*!< The x offset from the top-left corner of the full image. */
    uint16_t fragment_start_y;  /*!< The y offset from the top-left corner of the full image. */
} ipu_pg_die_fragment_desc_t;

/** Initialize wrapper
 *
 * Needs to be provided with IPU parameters data from PAL output for the
 * kernels covered by the given program group specification.
 *
 * Init retrieves the memory requirement information for a process group
 * with configuration using P2P.
 *
 * Available program group specifications can be queried runtime using CIPR.
 *
 * Note: No configuration for process group is applied here, the parameters
 *       given shall result in worst case terminal count and payload memory
 *       requirements for the lifetime of the wrapper (e.g. stream).
 *
 * \ingroup ipu_process_group_wrapper
 *
 * \param[in] ipu_parameters IPU parameters in PAL binary format
 * \param[in] pg  program group specification ID
 * \param[in] fragment_count P2P fragment count
 * \param[in] fragment_desc P2P fragment descriptors
 */
ipu_pg_die_t
ipu_pg_die_init(const ia_binary_data *ipu_parameters,
                const uint32_t pg_specification,
                const uint8_t fragment_count,
                const ipu_pg_die_fragment_desc_t *fragment_desc);

/** Destroy wrapper
 *
 * \ingroup ipu_process_group_wrapper
 * \param pg_die wrapper handle
 */
void
ipu_pg_die_destroy(ipu_pg_die_t pg_die);

/**
 * DEPRECATED
 * Set process group kernel bitmap
 *
 * \ingroup ipu_process_group_wrapper
 * \param pg_die wrapper handle
 * \param kbitmap kernel bitmap
 */
css_err_t
ipu_pg_die_set_kernel_bitmap(ipu_pg_die_t pg_die,
                             uint64_t kbitmap);

/** Query memory requirement for process group object
 *
 * \ingroup ipu_process_group_wrapper
 * \param pg_die wrapper handle
 */
uint32_t
ipu_pg_die_sizeof_process_group(ipu_pg_die_t pg_die);

/** Create process group structure
 *
 * \ingroup ipu_process_group_wrapper
 *
 * \param pg_die wrapper handle
 * \param[in,out] process_group ia_binary_data pointing to memory allocated
 *                              for process group object
 */
css_err_t
ipu_pg_die_create_process_group(ipu_pg_die_t pg_die,
                                ia_binary_data *process_group);

/** Get number of terminals
 *
 * Retrieve the number of terminals in a process group. This information
 * is encoded in the process group object but was cached in the wrapper
 * based on p2p input configuration.
 *
 * \ingroup ipu_process_group_wrapper
 *
 * \param pg_die wrapper handle
 */
uint32_t
ipu_pg_die_get_number_of_terminals(ipu_pg_die_t pg_die);

/** DEPRECATED: Get memory requirement for a terminal payload
 *
 * Retrieve the size for payload that is required by a terminal.
 *
 * \ingroup ipu_process_group_wrapper
 *
 * \param pg_die wrapper handle
 */
uint32_t
ipu_pg_die_sizeof_terminal_payload(ipu_pg_die_t pg_die,
                                   uint8_t terminal_index);

/** Get memory requirement for a terminal payload
 *
 * Retrieve the size for payload that is required by a terminal.
 *
 * \ingroup ipu_process_group_wrapper
 *
 * \param [in] pg_die wrapper handle
 * \param [in] terminal_index terminal index
 * \param [out] size size of the terminal payload
 */
css_err_t
ipu_pg_die_get_terminal_payload_size(ipu_pg_die_t pg_die,
                                     ia_binary_data *process_group,
                                     uint8_t terminal_index,
                                     uint32_t *size);

/** Get terminal direction
 *
 * Retrieve the direction of terminal data
 *
 * \ingroup ipu_process_group_wrapper
 *
 * \param pg_die wrapper handle
 * \param terminal_index index of the terminal
 */
bool
ipu_pg_die_is_input_terminal(ipu_pg_die_t pg_die,
                             uint8_t terminal_index);

/** Get info if pg_init terminal
 *
 * Retrieve true if pg_init terminal
 *
 * \ingroup ipu_process_group_wrapper
 *
 * \param pg_die wrapper handle
 * \param terminal_index index of the terminal
 */
bool
ipu_pg_die_is_pg_init_terminal(ipu_pg_die_t pg_die,
                               uint8_t terminal_index);

/** Get terminal index of a terminal with specific use
 *
 * Returns terminal index by given unique identifier. By default, all the
 * terminal data can be encoded and decoded transparently to the purpose of
 * the data. In other words, user can enumerate through all the terminals to
 * encode and decode the data between process group payloads and P2P.
 *
 * Decode operations for 3A statistics are currently implemented in P2P with
 * explicit result binary datas and there is dedicated library from ia_imaging
 * to convert it further to AIQ input.
 *
 * When data from or to process group needs special handling, the terminal of
 * a program group specification needs to be uniquely mapped with ID's that
 * shall include version handling of the data interface.
 *
 * Note: For back and forward compatibility unsigned 32-bit value is used as
 *       ID. Current implementation for ISYS ISA responds to kernel ID's
 *       directly when the terminal is associated with only one kernel:
 *       IA_CSS_ISYS_KERNEL_ID_3A_STAT_AE,
 *       IA_CSS_ISYS_KERNEL_ID_3A_STAT_AWB,
 *       IA_CSS_ISYS_KERNEL_ID_3A_STAT_AF
 *       (vied_parameters/support/ia_css_isys_parameter_defs.h).
 *
 * \ingroup ipu_process_group_wrapper
 *
 * \param pg_die wrapper handle
 * \param[in] uid unique ID of the terminal
 * \param[out] terminal_index index of the terminal
 */
css_err_t
ipu_pg_die_get_terminal_by_uid(ipu_pg_die_t pg_die,
                               uint32_t uid,
                               int *terminal_index);

/** Set parameters to encode for process group execution
 *
 * This function parsers and caches the input parameters for following calls
 * to ipu_pg_die_encode_terminal_payload().
 *
 * \param[in] pg_die wrapper handle
 * \param[in] ipu_parameters IPU parameters to encode
 */
css_err_t
ipu_pg_die_set_parameters(ipu_pg_die_t pg_die,
                          const ia_binary_data *ipu_parameters);

/** Start performance measurements for encode
*
* \param[in] pg_die wrapper handle
*/
void ipu_pg_die_start_perf_meas(ipu_pg_die_t pg_die);

/** Stop performance measurements for encode
*
* \param[in] pg_die wrapper handle
*/
void ipu_pg_die_stop_perf_meas(ipu_pg_die_t pg_die);

/** Set feedback cache to be used in encode or decode operation
 *
 * When multiple instances are used for consequent compute units,
 * the parameter adaptation may need to exchange cache memory between the
 * instances. This is opaque data to client and must follow data flow
 * specified by the compute unit. Client must ensure the coherency of data by
 * not allowing re-entrancy or concurrent encode and decode.
 *
 * \param[in] pg_die wrapper handle
 * \param[in] cache feedback cache
 */
css_err_t
ipu_pg_die_set_feedback_cache(ipu_pg_die_t pg_die,
                              const ia_binary_data *cache);

/** Get feedback cache to be shared
 *
 * \param[in] pg_die wrapper handle
 * \param[out] cache feedback cache
 */
css_err_t
ipu_pg_die_get_feedback_cache(ipu_pg_die_t pg_die,
                              ia_binary_data **cache);

/** Encode a terminal payload
 *
 * In process group there are input and output terminals. For input terminals
 * P2P is used to encode all the parameter data into the payloads that user
 * allocates. P2P is also responsible to fill in the terminal descriptors
 * in the process group object. Filling the terminal descriptors is also
 * needed with output terminals before submitting the process group to IPU
 * FW. Therefore user needs to enumerate through all of the terminal buffers.
 * In P2P API the operation for output terminals is called preparing.
 *
 * PG specification and manifest shall be used internally to control what
 * kernels are covered by the program group.
 *
 * \ingroup ipu_process_group_wrapper
 *
 * \param pg_die wrapper handle
 * \param[in,out] process_group process group context data
 * \param[in] terminal_index index of the terminal
 * \param[out] payload memory for the payload to encode to
 * \param[in] terminal_offset offset from the base of the payload buffer to the
 *            start of the payload sections specific for this terminal
 */
css_err_t
ipu_pg_die_encode_terminal_payload(ipu_pg_die_t pg_die,
                                   ia_binary_data *process_group,
                                   uint8_t terminal_index,
                                   ia_binary_data *payload,
                                   uint64_t terminal_offset);

/** Encode a pg control init terminal payload
 *
 * Same as ipu_pg_die_encode_terminal_payload()
 * but for pg_control_init terminals
 *
 * \ingroup ipu_process_group_wrapper
 *
 * \param pg_die wrapper handle
 * \param[in] terminal_index index of the terminal
 * \param[in,out] process_group process group context data
 * \param[out] payload memory for the payload to encode to
 */
css_err_t
ipu_pg_die_encode_pg_control(ipu_pg_die_t pg_die,
                             uint8_t terminal_index,
                             ia_binary_data *process_group,
                             ia_binary_data *payload);

/** Decode a terminal payload
 *
 * Decodes a process group terminal payload into binary results compatible
 * with other ia_imaging component.
 *
 * \ingroup ipu_process_group_wrapper
 *
 * \param pg_die wrapper handle
 * \param[in,out] process_group process group context data
 * \param[in] terminal_index index of the terminal
 * \param[in] payload memory for the payload to decode from
 * \param[out] result binary data struct for the results.
 *                    Caller provides the ia_binary_data struct, which
 *                    is returned filled with address to memory owned by
 *                    the wrapper (P2P).
 */
css_err_t
ipu_pg_die_decode_terminal_payload(ipu_pg_die_t pg_die,
                                   ia_binary_data *process_group,
                                   uint8_t terminal_index,
                                   ia_binary_data *payload,
                                   ia_binary_data *result);

/** Decode a terminal payload into internal cache
 *
 * Decodes a process group terminal payload into internal cache. After
 * decoding ipu_pg_die_serialize_decode_cache() can be used to read the data
 * into binary results compatible with ia_imaging component. Decode to cache +
 * serialize functions are intended for serializing data from multiple
 * terminals into single result binary.
 *
 * \ingroup ipu_process_group_wrapper
 *
 * \param pg_die wrapper handle
 * \param[in,out] process_group process group context data
 * \param[in] terminal_index index of the terminal
 * \param[in] payload memory for the payload to decode from
 */
css_err_t
ipu_pg_die_decode_terminal_payload_cached(ipu_pg_die_t pg_die,
                                          ia_binary_data *process_group,
                                          uint32_t terminal_index,
                                          ia_binary_data *payload);

/** Serialize the decode cache into binary
 *
 * Writes internal cache into result binary.
 * See ipu_pg_die_decode_terminal_payload_cached().
 *
 * \ingroup ipu_process_group_wrapper
 *
 * \param pg_die wrapper handle
 * \param[out] result binary data struct for the results.
 *                    Caller provides the ia_binary_data struct, which
 *                    is returned filled with address to memory owned by
 *                    the wrapper (P2P).
*/
css_err_t
ipu_pg_die_serialize_decode_cache(ipu_pg_die_t pg_die, ia_binary_data *result);

/** Get fragmentation
 *
 * Gets the P2P fragment descriptors and count.
 *
 * \ingroup ipu_process_group_wrapper
 *
 * \param pg_die wrapper handle
 * \param[out] fragment_count fragment count
 * \param[out] fragment_descs fragment descriptors
*/
css_err_t
ipu_pg_die_get_fragmentation(ipu_pg_die_t pg_die,
                             uint8_t *fragment_count,
                             const ipu_pg_die_fragment_desc_t **fragment_descs);

/** Get fragment descriptors from a terminal
 *
 * Gets the fragment descriptors from a terminal.
 *
 * \ingroup ipu_process_group_wrapper
 *
 * \param pg_die wrapper handle
 * \param[in] terminal_index terminal index
 * \return fragment descriptors
*/
const ipu_pg_die_fragment_desc_t *
ipu_pg_die_get_fragment_descriptors(ipu_pg_die_t pg_die,
                                    uint32_t terminal_index);

/** Set fragment descriptors to a terminal
 *
 * Sets the fragment descriptors to a terminal. Ownership is passed to pg_die.
 * If the given terminal index is UINT32_MAX, fragment descriptors are written
 * to be used by P2P instead of a terminal.
 *
 * \ingroup ipu_process_group_wrapper
 *
 * \param pg_die wrapper handle
 * \param[in] terminal_index terminal index
 * \param[in] fragment_descs fragment descriptors
*/
css_err_t
ipu_pg_die_set_fragment_descriptors(ipu_pg_die_t pg_die,
        uint32_t terminal_index,
        ipu_pg_die_fragment_desc_t *fragment_descs);

/** Return index of the program control init terminal.
 *
 * \param pg_die wrapper handle
*/
uint8_t
ipu_pg_die_get_program_control_init_terminal_index(ipu_pg_die_t pg_die);

/** Dump to traces the information about process group
 *
 * Used only for debugging purposes.
 * For the given P2P wrapper it prints the size of the process group
 * the number of terminals
 * For each terminal it reports the type and the payload size.
 *
 * In case process_group binary is provided, it is interpreted and dumped into
 * logs as well.
 *
 * \ingroup ipu_process_group_wrapper
 *
 * \param[in] pg_die wrapper handle
 */
css_err_t
ipu_pg_die_dump_info(ipu_pg_die_t pg_die, ia_binary_data *process_group);

/** Dump to text file the PG content in hex
 *
 * Used only for debugging purposes.
 * This is also known as Charalampos format. The resulting file can be shared
 * with the FW team for further debugging.
 *
 * \ingroup ipu_process_group_wrapper
 *
 * \param[in] pg_die wrapper handle
 * \param[in] created process group
 * \param[in] payload buffer
 * \param[in] File Name
 */
css_err_t
ipu_pg_die_dump_hexfile(ipu_pg_die_t pg_die,
                        ia_binary_data *process_group,
                        ia_binary_data *payload,
                        const char *file_name);

void
ipu_pg_die_create_pg_file(ipu_pg_die_t pg_die);

#endif
