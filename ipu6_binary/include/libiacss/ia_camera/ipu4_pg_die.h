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

#ifndef __IPU4_PG_DIE_H__
#define __IPU4_PG_DIE_H__

#include "ipu_process_group_wrapper.h"
#include <ia_css_kernel_bitmap.h>
#include <ia_css_rbm.h>
#include <ia_cipf/ia_cipf_types.h>

#define MAX_KERNEL_BITS_PER_PG IA_CSS_KERNEL_BITMAP_BITS

enum ipu_pg_subsystem
{
    IPU_PG_SUBSYSTEM_ISYS,
    IPU_PG_SUBSYSTEM_PSYS
};

typedef struct ipu_pg_kernel_param_requirements_s
{
    ia_p2p_terminal_requirements_t sections[MAX_KERNEL_BITS_PER_PG];
    ia_p2p_payload_desc payloads[MAX_KERNEL_BITS_PER_PG];
} ipu_pg_kernel_param_requirements_t;

typedef struct ipu_pg_terminal_kernel_manifest_s
{
    uint8_t  id;
    uint8_t  sections;
    uint32_t size;
    bool     initialize;
} ipu_pg_terminal_kernel_info_t;

typedef struct ipu_pg_terminal_requirements_s
{
    ia_css_terminal_type_t type;
    uint32_t terminal_size;
    uint32_t payload_size;
    uint32_t user_param_size;
    uint8_t *user_param_address;
    ia_css_kernel_bitmap_t kernel_bitmap;
    uint32_t section_count;
    ipu_pg_terminal_kernel_info_t *kernel_order;
    ipu_pg_die_fragment_desc_t *fragment_descs;
} ipu_pg_terminal_requirements_t;

typedef struct ipu_pg_requirements_s
{
    uint32_t process_group_size;
    uint32_t terminal_count;
    ipu_pg_terminal_requirements_t terminals[IPU_MAX_TERMINAL_COUNT];
} ipu_pg_requirements_t;

#define MAX_PERF_MEAS_SLOTS        6
#define PERF_CACHED_IN_TERM_SLOT   0
#define PERF_CACHED_OUT_TERM_SLOT  1
#define PERF_PROGRAM_TERM_SLOT     2
#define PERF_SPATIAL_IN_TERM_SLOT  3
#define PERF_SPATIAL_OUT_TERM_SLOT 4
#define PERF_ENCODE_TOTAL_SLOT     5

struct ipu_pg_die_s
{
    ia_p2p_handle p2p;
    ia_binary_data p2p_cache_buffer;
    ia_binary_data ext_cache_buffer;
    enum ipu_pg_subsystem subsystem;
    uint32_t specification;
    ipu_pg_requirements_t reqs;
    ipu_pg_kernel_param_requirements_t kernels; /* needed due p2p call flow */
    uint16_t fragment_count;
    /* Fragment descriptor array used by P2P */
    ia_p2p_fragment_configuration_t *fragment_config;
    ia_p2p_fragment_desc *fragment_desc; /* deprecated */
    ia_css_kernel_bitmap_t kernel_bitmap;

    /* Fragment descriptor arrays of all terminals */
    ipu_pg_die_fragment_desc_t *input_frag_descs; /* deprecated */
    uint8_t input_count; /* deprecated */
    ipu_pg_die_fragment_desc_t *output_frag_descs; /* deprecated */
    uint8_t output_count; /* deprecated */

    /* pg manifest & params not used by isys,
     * declaring as void due to PSYS specific indirects */
    void *manifest;
    void *params;

    uint8_t program_control_init_terminal_index;
    uint32_t perf_meas_slots[MAX_PERF_MEAS_SLOTS];
};

/* isys */
uint32_t
ipu4_isys_pg_get_requirements(ipu_pg_die_t pg_die,
                              ia_p2p_handle p2p,
                              uint16_t fragment_count);

css_err_t ipu4_isys_pg_print(void *pg,
                          const uint32_t pg_total_size);

css_err_t ipu4_isys_pg_create(void *pg,
                           const uint32_t pg_total_size,
                           const uint16_t fragment_count,
                           const ipu_pg_requirements_t *pg_reqs);

css_err_t ipu4_isys_pg_dump_hexfile(ipu_pg_die_t pg_die,
                                 ia_binary_data *process_group,
                                 ia_binary_data *payload,
                                 const char *file_name);

ia_css_terminal_t*
ipu4_isys_pg_get_terminal_descriptor(void *pg, uint32_t terminal_index);


/* psys */
css_err_t
ipu4_psys_pg_init(ipu_pg_die_t pg_die,
                void *pg,
                int term_index,
                ia_css_program_control_init_terminal_t *terminal,
                void *payload,
                ia_cipf_buffer_t *buffer);

uint32_t
ipu4_psys_pg_get_requirements(ia_p2p_handle p2p,
                              ipu_pg_die_t pg_die);

css_err_t ipu4_psys_pg_create(ipu_pg_die_t pg_die,
                           void *pg,
                           const uint32_t pg_total_size);

ia_css_terminal_t*
ipu4_psys_pg_get_terminal_descriptor(ipu_pg_die_t pg_die,
                                     void *pg,
                                     uint32_t terminal_index);

css_err_t
ipu_psys_die_set_kernel_bitmap(ipu_pg_die_t pg_die,
                               ia_css_kernel_bitmap_t kbitmap);

css_err_t
ipu_psys_die_get_kernel_bitmap(ipu_pg_die_t pg_die,
                               ia_css_kernel_bitmap_t *kbitmap);

css_err_t
ipu_psys_die_get_fragment_descriptors(ipu_pg_die_t pg_die,
                                      uint8_t fragment_count,
                                      ipu_pg_die_fragment_desc_t **input_desc,
                                      uint8_t *input_terminal_count,
                                      ipu_pg_die_fragment_desc_t **output_desc,
                                      uint8_t *output_terminal_count,
                                      void *pg, const ia_css_rbm_t *rbm);

uint8_t
ipu_pg_die_get_program_control_init_terminal_index(ipu_pg_die_t pg_die);

/* common (uses cipr) */
css_err_t ipu4_get_p2p_platform(ia_p2p_platform_t *platform);

#endif

