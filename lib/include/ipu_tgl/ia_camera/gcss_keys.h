/*
 * INTEL CONFIDENTIAL
 * Copyright (c) 2015-2018 Intel Corporation. All Rights Reserved.
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

GCSS_KEY_SECTION_START (NA, na, 0x0000)
GCSS_KEY (AE_STATS_SINK, ae_stats_sink)
GCSS_KEY (AF_STATS_SINK, af_stats_sink)
GCSS_KEY (AWB_STATS_SINK, awb_stats_sink)
GCSS_KEY (BASE_NODE, base_node)
GCSS_KEY (BASE_TYPE, base_type)
GCSS_KEY (BUFFER_SRC0, buffer_src0)
GCSS_KEY (COMPUTE_BLOCK, compute_block)
GCSS_KEY (CONNECTION, connection)
GCSS_KEY (CONTENT_TYPE, content_type)
GCSS_KEY (CONVERSION_GAIN, conversion_gain)
GCSS_KEY (CMC_TAG, cmc_tag)
GCSS_KEY (DEMUXER, demux)
GCSS_KEY (DESTINATION, destination)
GCSS_KEY (DOL_MODE, dol_mode)
GCSS_KEY (FLOW, flow)
GCSS_KEY (FORMAT, format)
GCSS_KEY (GRAPH, graph)
GCSS_KEY (GRAPHS, graphs)
GCSS_KEY (GRAPH_DESCRIPTOR, graph_descriptor)
GCSS_KEY (GRAPH_SETTINGS, graph_settings)
GCSS_KEY (HW, hw)
GCSS_KEY (INPUT, input)
GCSS_KEY (KERNEL, kernel)
GCSS_KEY (KERNEL_LINK, klink)
GCSS_KEY (MBR_DATA, mbr_data)
GCSS_KEY (METADATA, metadata)
GCSS_KEY (MODE_ID, mode_id)
GCSS_KEY (MUXER, mux)
GCSS_KEY (NAME, name)
GCSS_KEY (NODE, node)
GCSS_KEY (NODES, nodes)
GCSS_KEY (OUTPUT, output)
GCSS_KEY (PEER, peer)
GCSS_KEY (PORT, port)
GCSS_KEY (PROGRAM_GROUP, program_group)
GCSS_KEY (SENSOR, sensor)
GCSS_KEY (SENSOR_MODES, sensor_modes)
GCSS_KEY (PIXEL_ARRAY, pixel_array)
GCSS_KEY (BINNER, binner)
GCSS_KEY (SCALER, scaler)
GCSS_KEY (CSI_BE, csi_be)
GCSS_KEY (CSI_BE_DOL, csi_be_dol)
GCSS_KEY (CSI_BE_SOC, csi_be_soc)
GCSS_KEY (SENSOR_TYPE, sensor_type)
GCSS_KEY (SETTINGS, settings)
GCSS_KEY (SINK, sink)
GCSS_KEY (SOURCE, source)
GCSS_KEY (SPLITTER, split)
GCSS_KEY (STATIC, static)
GCSS_KEY (TARGET, target)
GCSS_KEY (TYPE, type)
GCSS_KEY (VALUE, value)
GCSS_KEY (CIPF, cipf)
GCSS_KEY (ATTRIBUTE, attribute)
GCSS_KEY (OPTIONS, options)
GCSS_KEY (APPLY, apply)
GCSS_KEY (TPG, tpg)
GCSS_KEY (SIMULATION, simulation)
GCSS_KEY (VERSION, version)
GCSS_KEY (FILE_NAME, file_name)
GCSS_KEY (RBM, rbm)
GCSS_KEY (DESCRIPTION, description)
GCSS_KEY (VIDEO_BPP, video_bpp)
GCSS_KEY (STILLS_BPP, stills_bpp)
GCSS_KEY (EXTERNAL_STAGE, external_stage)
GCSS_KEY (PDAF_TYPE, pdaf_type)
GCSS_KEY (SUBSYSTEM, subsystem)
GCSS_KEY (HW_BITMAPS, hw_bitmaps)
GCSS_KEY (DEB, deb)
GCSS_KEY (TEB, teb)
GCSS_KEY (REB, reb)
GCSS_KEY (PIPELINE, pipeline)
/* add new keys to this section above this line */
GCSS_KEY_SECTION_END (GENERIC_KEYS_END, generic_keys_end, 0x0FFF)

/* do not add keys here! */

/* NUMERICAL KEY DEFINITIONS */
GCSS_KEY_SECTION_START (NUMERICAL_START, num_start, 0x2000)
GCSS_KEY (ACTIVE_INPUT, active_input)
GCSS_KEY (ACTIVE_OUTPUTS, active_outputs)
GCSS_KEY (ACTIVE_OUTPUT, active_output)
GCSS_KEY (BINNING_H_FACTOR, h_factor)
GCSS_KEY (BINNING_V_FACTOR, v_factor)
GCSS_KEY (BOTTOM, bottom)
GCSS_KEY (BPP, bpp)
GCSS_KEY (BRANCH_POINT, branch_point)
GCSS_KEY (BYTES_PER_LINE, bpl)
GCSS_KEY (CONCURRENT, concurrent)
GCSS_KEY (DIRECTION, direction)
GCSS_KEY (DVS, dvs)
GCSS_KEY (ENABLED, enabled)
GCSS_KEY (EXEC_CTX_ID, exec_ctx_id)
GCSS_KEY (FLIP_H, flip_h)
GCSS_KEY (FLIP_V, flip_v)
GCSS_KEY (FPS, fps)
GCSS_KEY (FRAGMENT_COUNT, fragment_count)
GCSS_KEY (HEIGHT, height)
GCSS_KEY (ID, id)
GCSS_KEY (KEY, key)
GCSS_KEY (LEFT, left)
GCSS_KEY (LINK_ID, link_id)
GCSS_KEY (OPMODE, operation_mode)
GCSS_KEY (PAL_UUID, pal_uuid)
GCSS_KEY (PG_ID, pg_id)
GCSS_KEY (POWER_FACTOR, power_factor)
GCSS_KEY (PRIVATE, private)
GCSS_KEY (PSYS_FREQ, psys_frequency)
GCSS_KEY (RCB, rcb)
GCSS_KEY (RESTORE_POINT, restore_point)
GCSS_KEY (RIGHT, right)
GCSS_KEY (SCALING_FACTOR_NUM, num_factor)
GCSS_KEY (SCALING_FACTOR_DENOM, denom_factor)
GCSS_KEY (SINK_PORT, sink_port)
GCSS_KEY (STREAM_ID, stream_id)
GCSS_KEY (TNR, tnr)
GCSS_KEY (TOP, top)
GCSS_KEY (TUNING_MODE, tuning_mode)
GCSS_KEY (WIDTH, width)
/* add new keys to this section above this line */
GCSS_KEY_SECTION_END (NUMERICAL_END, num_end, 0x2FFF)

/* do not add keys here, start a new section instead! */
