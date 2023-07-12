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

#ifndef _IA_CIPF_CSS_H_
#define _IA_CIPF_CSS_H_

#include <ia_cipf/ia_cipf_types.h>

/* Note:
 * PSYS Library is considered to query UIDs from binary releases
 * or from other external definition (markup language?)
 *
 * Here we would define only the ones statically integrated
 */

#define psys_2401_vfpp_pg_uid       ia_fourcc('V','F','P','P')
#define psys_2401_vfpp_in_uid       psys_2401_vfpp_pg_uid + 1
#define psys_2401_vfpp_out_uid      psys_2401_vfpp_pg_uid + 2
#define psys_2401_vfpp_params_uid   psys_2401_vfpp_pg_uid + 3

#define psys_2401_preview_pg_uid     ia_fourcc('P','R','E','0')
#define psys_2401_preview_in_uid     psys_2401_preview_pg_uid + 1
#define psys_2401_preview_out_uid    psys_2401_preview_pg_uid + 2
#define psys_2401_preview_params_uid psys_2401_preview_pg_uid + 3

#define psys_2401_capture_pg_uid                ia_fourcc('P','R','I','0')
#define psys_2401_capture_in_uid                psys_2401_capture_pg_uid + 1
#define psys_2401_capture_params_uid            psys_2401_capture_pg_uid + 2
#define psys_2401_capture_main_output_uid       psys_2401_capture_pg_uid + 3
#define psys_2401_capture_vfpp_output_uid       psys_2401_capture_pg_uid + 4

#define psys_2401_codec_uid               ia_fourcc('2','4','C','O')
#define psys_2401_3A_grid_info_uid        psys_2401_codec_uid + 1
#define psys_2401_3A_statistics_uid       psys_2401_codec_uid + 2

#define psys_2401_lsc_table_uid         ia_fourcc('2','4','P','A')
#define psys_2401_3A_statistics_hi_uid  psys_2401_lsc_table_uid + 1
#define psys_2401_3A_statistics_lo_uid  psys_2401_lsc_table_uid + 2
#define psys_2401_3A_histogram_uid      psys_2401_lsc_table_uid + 3

/* 2600 UIDS */
#define psys_2600_small_uid         ia_fourcc('S','M','A','0')
#define psys_2600_small_input_uid   psys_2600_small_uid + 1
#define psys_2600_small_output_uid  psys_2600_small_uid + 2
#define psys_2600_small_param_uid   psys_2600_small_uid + 3
#define psys_2600_small_secondary_output_uid psys_2600_small_uid + 4

#define psys_2600_pg_uid(id) ia_fourcc(((id & 0xFF00) >> 8),id,'G','0')
#define psys_2600_pg_id_from_uid(uid) ((uid & 0xFFFF0000) >> 16)
#define is_psys_stage_uid(uid) ((uid & 0x0000FFFF) == psys_2600_pg_uid(0))

#define psys_2600_4k60_pg_id        107
#define psys_2600_4k60_uid          psys_2600_pg_uid(psys_2600_4k60_pg_id)
#define psys_2600_4k60_param_uid    psys_2600_4k60_uid + 1
#define psys_2600_4k60_input_uid    psys_2600_4k60_uid + 2
#define psys_2600_4k60_output_uid   psys_2600_4k60_uid + 3
#define psys_2600_4k60_secondary_output_uid psys_2600_4k60_uid + 4

#define psys_2600_uvswap_pg_id        119
#define psys_2600_uvswap_uid          psys_2600_pg_uid(psys_2600_uvswap_pg_id)
#define psys_2600_uvswap_param_uid    psys_2600_uvswap_uid + 1
#define psys_2600_uvswap_input_uid    psys_2600_uvswap_uid + 2
#define psys_2600_uvswap_output_uid   psys_2600_uvswap_uid + 3

#define psys_2600_popg_pg_id                201
#define psys_2600_popg_uid                  psys_2600_pg_uid(psys_2600_popg_pg_id)
#define psys_2600_popg_param_uid            psys_2600_popg_uid + 1
#define psys_2600_popg_program_uid          psys_2600_popg_uid + 2
#define psys_2600_popg_input_uid            psys_2600_popg_uid + 3
#define psys_2600_popg_output_uid           psys_2600_popg_uid + 4
#define psys_2600_popg_secondary_output_uid psys_2600_popg_uid + 5

/* \todo Temporarily switched to use still post-gdc PG */
#define psys_2600_post_gdc_pg_id                118
#define psys_2600_post_gdc_uid                  psys_2600_pg_uid(psys_2600_post_gdc_pg_id)
#define psys_2600_post_gdc_param_uid            psys_2600_post_gdc_uid + 1
#define psys_2600_post_gdc_program_uid          psys_2600_post_gdc_uid + 2
#define psys_2600_post_gdc_input_uid            psys_2600_post_gdc_uid + 3
#define psys_2600_post_gdc_spatial_param_uid    psys_2600_post_gdc_uid + 4
#define psys_2600_post_gdc_output_uid           psys_2600_post_gdc_uid + 5
#define psys_2600_post_gdc_secondary_output_uid psys_2600_post_gdc_uid + 6
#define psys_2600_post_gdc_third_output_uid     psys_2600_post_gdc_uid + 7

#define psys_2600_video_post_gdc_pg_id                114
#define psys_2600_video_post_gdc_uid                  psys_2600_pg_uid(psys_2600_video_post_gdc_pg_id)
#define psys_2600_video_post_gdc_param_uid            psys_2600_video_post_gdc_uid + 1
#define psys_2600_video_post_gdc_program_uid          psys_2600_video_post_gdc_uid + 2
#define psys_2600_video_post_gdc_input_uid            psys_2600_video_post_gdc_uid + 3
#define psys_2600_video_post_gdc_spatial_param_uid    psys_2600_video_post_gdc_uid + 4
#define psys_2600_video_post_gdc_output_uid           psys_2600_video_post_gdc_uid + 5
#define psys_2600_video_post_gdc_secondary_output_uid psys_2600_video_post_gdc_uid + 6
#define psys_2600_video_post_gdc_third_output_uid     psys_2600_video_post_gdc_uid + 7
#define psys_2600_video_post_gdc_tnr_input_uid        psys_2600_video_post_gdc_uid + 8
#define psys_2600_video_post_gdc_tnr_output_uid       psys_2600_video_post_gdc_uid + 9

#define psys_2600_video_post_gdc_v2_pg_id                129
#define psys_2600_video_post_gdc_v2_uid                  psys_2600_pg_uid(psys_2600_video_post_gdc_v2_pg_id)
#define psys_2600_video_post_gdc_v2_param_uid            psys_2600_video_post_gdc_v2_uid + 1
#define psys_2600_video_post_gdc_v2_program_uid          psys_2600_video_post_gdc_v2_uid + 2
#define psys_2600_video_post_gdc_v2_input_uid            psys_2600_video_post_gdc_v2_uid + 3
#define psys_2600_video_post_gdc_v2_spatial_param_uid    psys_2600_video_post_gdc_v2_uid + 4
#define psys_2600_video_post_gdc_v2_output_uid           psys_2600_video_post_gdc_v2_uid + 5
#define psys_2600_video_post_gdc_v2_secondary_output_uid psys_2600_video_post_gdc_v2_uid + 6
#define psys_2600_video_post_gdc_v2_third_output_uid     psys_2600_video_post_gdc_v2_uid + 7
#define psys_2600_video_post_gdc_v2_tnr_input_uid        psys_2600_video_post_gdc_v2_uid + 8
#define psys_2600_video_post_gdc_v2_tnr_output_uid       psys_2600_video_post_gdc_v2_uid + 9

#define psys_2600_video_post_gdc_mbr_pg_id                132
#define psys_2600_video_post_gdc_mbr_uid                  psys_2600_pg_uid(psys_2600_video_post_gdc_mbr_pg_id)
#define psys_2600_video_post_gdc_mbr_param_uid            psys_2600_video_post_gdc_mbr_uid + 1
#define psys_2600_video_post_gdc_mbr_program_uid          psys_2600_video_post_gdc_mbr_uid + 2
#define psys_2600_video_post_gdc_mbr_input_uid            psys_2600_video_post_gdc_mbr_uid + 3
#define psys_2600_video_post_gdc_mbr_spatial_param_uid    psys_2600_video_post_gdc_mbr_uid + 4
#define psys_2600_video_post_gdc_mbr_output_uid           psys_2600_video_post_gdc_mbr_uid + 5
#define psys_2600_video_post_gdc_mbr_secondary_output_uid psys_2600_video_post_gdc_mbr_uid + 6
#define psys_2600_video_post_gdc_mbr_third_output_uid     psys_2600_video_post_gdc_mbr_uid + 7
#define psys_2600_video_post_gdc_mbr_tnr_input_uid        psys_2600_video_post_gdc_mbr_uid + 8
#define psys_2600_video_post_gdc_mbr_tnr_output_uid       psys_2600_video_post_gdc_mbr_uid + 9

#define psys_2600_video_post_gdc_v2_mbr_pg_id                172
#define psys_2600_video_post_gdc_v2_mbr_uid                  psys_2600_pg_uid(psys_2600_video_post_gdc_v2_mbr_pg_id)
#define psys_2600_video_post_gdc_v2_mbr_param_uid            psys_2600_video_post_gdc_v2_mbr_uid + 1
#define psys_2600_video_post_gdc_v2_mbr_program_uid          psys_2600_video_post_gdc_v2_mbr_uid + 2
#define psys_2600_video_post_gdc_v2_mbr_input_uid            psys_2600_video_post_gdc_v2_mbr_uid + 3
#define psys_2600_video_post_gdc_v2_mbr_spatial_param_uid    psys_2600_video_post_gdc_v2_mbr_uid + 4
#define psys_2600_video_post_gdc_v2_mbr_output_uid           psys_2600_video_post_gdc_v2_mbr_uid + 5
#define psys_2600_video_post_gdc_v2_mbr_secondary_output_uid psys_2600_video_post_gdc_v2_mbr_uid + 6
#define psys_2600_video_post_gdc_v2_mbr_third_output_uid     psys_2600_video_post_gdc_v2_mbr_uid + 7
#define psys_2600_video_post_gdc_v2_mbr_tnr_input_uid        psys_2600_video_post_gdc_v2_mbr_uid + 8
#define psys_2600_video_post_gdc_v2_mbr_tnr_output_uid       psys_2600_video_post_gdc_v2_mbr_uid + 9

#define psys_2600_video_pre_gdc_pg_id        116
#define psys_2600_video_pre_gdc_uid          psys_2600_pg_uid(psys_2600_video_pre_gdc_pg_id)
#define psys_2600_video_pre_gdc_param_uid    psys_2600_video_pre_gdc_uid + 1
#define psys_2600_video_pre_gdc_program_uid  psys_2600_video_pre_gdc_uid + 2
#define psys_2600_video_pre_gdc_input_uid    psys_2600_video_pre_gdc_uid + 3
#define psys_2600_video_pre_gdc_output_uid   psys_2600_video_pre_gdc_uid + 4

#define psys_2600_ipu5_video_pre_gdc_pg_id                  140
#define psys_2600_ipu5_video_pre_gdc_uid                    psys_2600_pg_uid(psys_2600_ipu5_video_pre_gdc_pg_id)
#define psys_2600_ipu5_video_pre_gdc_param_uid              psys_2600_ipu5_video_pre_gdc_uid + 1
#define psys_2600_ipu5_video_pre_gdc_program_uid            psys_2600_ipu5_video_pre_gdc_uid + 2
#define psys_2600_ipu5_video_pre_gdc_param_spatial_in_uid   psys_2600_ipu5_video_pre_gdc_uid + 3
#define psys_2600_ipu5_video_pre_gdc_input_uid              psys_2600_ipu5_video_pre_gdc_uid + 4
#define psys_2600_ipu5_video_pre_gdc_output_uid             psys_2600_ipu5_video_pre_gdc_uid + 5

#define psys_ipu5_video_pre_gdc_vpless_pg_id                    167
#define psys_ipu5_video_pre_gdc_vpless_uid                      psys_2600_pg_uid(psys_ipu5_video_pre_gdc_vpless_pg_id)
#define psys_ipu5_video_pre_gdc_vpless_param_uid                psys_ipu5_video_pre_gdc_vpless_uid + 1
#define psys_ipu5_video_pre_gdc_vpless_program_uid              psys_ipu5_video_pre_gdc_vpless_uid + 2
#define psys_ipu5_video_pre_gdc_vpless_program_control_init_uid psys_ipu5_video_pre_gdc_vpless_uid + 3
#define psys_ipu5_video_pre_gdc_vpless_input_uid                psys_ipu5_video_pre_gdc_vpless_uid + 4
#define psys_ipu5_video_pre_gdc_vpless_output_uid               psys_ipu5_video_pre_gdc_vpless_uid + 5
#define psys_ipu5_video_pre_gdc_gammastar_grid_uid              psys_ipu5_video_pre_gdc_vpless_uid + 6
#define psys_ipu5_video_pre_gdc_dvs_mv_out_l0_uid               psys_ipu5_video_pre_gdc_vpless_uid + 7
#define psys_ipu5_video_pre_gdc_dvs_mv_out_l1_uid               psys_ipu5_video_pre_gdc_vpless_uid + 8
#define psys_ipu5_video_pre_gdc_dvs_mv_out_l2_uid               psys_ipu5_video_pre_gdc_vpless_uid + 9
#define psys_ipu5_video_pre_gdc_dvs_fe_in_l0_uid                psys_ipu5_video_pre_gdc_vpless_uid + 10
#define psys_ipu5_video_pre_gdc_dvs_fe_in_l1_uid                psys_ipu5_video_pre_gdc_vpless_uid + 11
#define psys_ipu5_video_pre_gdc_dvs_fe_in_l2_uid                psys_ipu5_video_pre_gdc_vpless_uid + 12
#define psys_ipu5_video_pre_gdc_dvs_fe_out_l0_uid               psys_ipu5_video_pre_gdc_vpless_uid + 13
#define psys_ipu5_video_pre_gdc_dvs_fe_out_l1_uid               psys_ipu5_video_pre_gdc_vpless_uid + 14
#define psys_ipu5_video_pre_gdc_dvs_fe_out_l2_uid               psys_ipu5_video_pre_gdc_vpless_uid + 15

#define psys_2600_ipu6_lb_video_pg_id                  182
#define psys_2600_ipu6_lb_video_uid                    psys_2600_pg_uid(psys_2600_ipu6_lb_video_pg_id)
#define psys_2600_ipu6_lb_video_param_uid              psys_2600_ipu6_lb_video_uid + 1
#define psys_2600_ipu6_lb_video_program_uid            psys_2600_ipu6_lb_video_uid + 2
#define psys_2600_ipu6_lb_video_program_control_uid    psys_2600_ipu6_lb_video_uid + 3
#define psys_2600_ipu6_lb_video_input_uid              psys_2600_ipu6_lb_video_uid + 4
#define psys_2600_ipu6_lb_video_output_uid             psys_2600_ipu6_lb_video_uid + 5

#define psys_ipu6_bb_pg_id                 189
#define psys_ipu6_bb_uid                   psys_2600_pg_uid(psys_ipu6_bb_pg_id)
#define psys_ipu6_bb_input_uid             (psys_ipu6_bb_uid + 1)
#define psys_ipu6_bb_mp_uid                (psys_ipu6_bb_uid + 2)
#define psys_ipu6_bb_dp_uid                (psys_ipu6_bb_uid + 3)
#define psys_ipu6_bb_ppp_uid               (psys_ipu6_bb_uid + 4)
#define psys_ipu6_bb_tnr_ref_in_uid        (psys_ipu6_bb_uid + 5)
#define psys_ipu6_bb_tnr_recsim_in_uid     (psys_ipu6_bb_uid + 6)
#define psys_ipu6_bb_tnr_ref_out_uid       (psys_ipu6_bb_uid + 7)
#define psys_ipu6_bb_tnr_recsim_out_uid    (psys_ipu6_bb_uid + 8)
#define psys_ipu6_bb_program_control_uid   (psys_ipu6_bb_uid + 9)
#define psys_ipu6_bb_param_in_uid          (psys_ipu6_bb_uid + 10)
#define psys_ipu6_bb_program_uid           (psys_ipu6_bb_uid + 11)

#define psys_ipu6_lb_rbm_pg_id                183
#define psys_ipu6_lb_rbm_uid                  psys_2600_pg_uid(psys_ipu6_lb_rbm_pg_id)
#define psys_ipu6_lb_rbm_param_uid            (psys_ipu6_lb_rbm_uid + 1)
#define psys_ipu6_lb_rbm_program_uid          (psys_ipu6_lb_rbm_uid + 2)
#define psys_ipu6_lb_rbm_program_control_uid  (psys_ipu6_lb_rbm_uid + 3)
#define psys_ipu6_lb_rbm_input_uid            (psys_ipu6_lb_rbm_uid + 4)
#define psys_ipu6_lb_rbm_output_uid           (psys_ipu6_lb_rbm_uid + 5)
#define psys_ipu6_lb_rbm_gammastar_grid_uid   (psys_ipu6_lb_rbm_uid + 6)
#define psys_ipu6_lb_rbm_dvs_mv_out_l0_uid    (psys_ipu6_lb_rbm_uid + 7)
#define psys_ipu6_lb_rbm_dvs_mv_out_l1_uid    (psys_ipu6_lb_rbm_uid + 8)
#define psys_ipu6_lb_rbm_dvs_mv_out_l2_uid    (psys_ipu6_lb_rbm_uid + 9)
#define psys_ipu6_lb_rbm_dvs_fe_in_l0_uid     (psys_ipu6_lb_rbm_uid + 10)
#define psys_ipu6_lb_rbm_dvs_fe_in_l1_uid     (psys_ipu6_lb_rbm_uid + 11)
#define psys_ipu6_lb_rbm_dvs_fe_in_l2_uid     (psys_ipu6_lb_rbm_uid + 12)
#define psys_ipu6_lb_rbm_dvs_fe_out_l0_uid    (psys_ipu6_lb_rbm_uid + 13)
#define psys_ipu6_lb_rbm_dvs_fe_out_l1_uid    (psys_ipu6_lb_rbm_uid + 14)
#define psys_ipu6_lb_rbm_dvs_fe_out_l2_uid    (psys_ipu6_lb_rbm_uid + 15)

#define psys_ipu6_isa_rbm_pg_id                185
#define psys_ipu6_isa_rbm_uid                  psys_2600_pg_uid(psys_ipu6_isa_rbm_pg_id)
#define psys_ipu6_isa_rbm_param_uid            (psys_ipu6_isa_rbm_uid + 1)
#define psys_ipu6_isa_rbm_program_uid          (psys_ipu6_isa_rbm_uid + 2)
#define psys_ipu6_isa_rbm_program_control_uid  (psys_ipu6_isa_rbm_uid + 3)
#define psys_ipu6_isa_rbm_input_uid            (psys_ipu6_isa_rbm_uid + 4)
#define psys_ipu6_isa_rbm_blc_input_uid        (psys_ipu6_isa_rbm_uid + 5)
#define psys_ipu6_isa_rbm_lsc_input_uid        (psys_ipu6_isa_rbm_uid + 6)
#define psys_ipu6_isa_rbm_output_bayer_uid     (psys_ipu6_isa_rbm_uid + 7)
#define psys_ipu6_isa_rbm_output_yuv_a_uid     (psys_ipu6_isa_rbm_uid + 8)
#define psys_ipu6_isa_rbm_output_yuv_b_uid     (psys_ipu6_isa_rbm_uid + 9)
#define psys_ipu6_isa_rbm_output_full_uid      (psys_ipu6_isa_rbm_uid + 10)
#define psys_ipu6_isa_rbm_output_ir_uid        (psys_ipu6_isa_rbm_uid + 11)
#define psys_ipu6_isa_rbm_output_sis_a_uid     (psys_ipu6_isa_rbm_uid + 12)
#define psys_ipu6_isa_rbm_output_sis_b_uid     (psys_ipu6_isa_rbm_uid + 13)
#define psys_ipu6_isa_rbm_output_af_uid        (psys_ipu6_isa_rbm_uid + 14)
#define psys_ipu6_isa_rbm_output_awb_uid       (psys_ipu6_isa_rbm_uid + 15)
#define psys_ipu6_isa_rbm_output_paf_uid       (psys_ipu6_isa_rbm_uid + 16)
#define psys_ipu6_isa_rbm_param_out_uid        (psys_ipu6_isa_rbm_uid + 17)
#define psys_ipu6_isa_rbm_input_short_uid      (psys_ipu6_isa_rbm_uid + 18)
#define psys_ipu6_isa_rbm_input_medium_uid     (psys_ipu6_isa_rbm_uid + 19)
#define psys_ipu6_isa_rbm_input_paf_uid        (psys_ipu6_isa_rbm_uid + 20)

#define psys_ipu6s_isa_pg_id                198
#define psys_ipu6s_isa_uid                  psys_2600_pg_uid(psys_ipu6s_isa_pg_id)
#define psys_ipu6s_isa_param_uid            (psys_ipu6s_isa_uid + 1)
#define psys_ipu6s_isa_program_uid          (psys_ipu6s_isa_uid + 2)
#define psys_ipu6s_isa_program_control_uid  (psys_ipu6s_isa_uid + 3)
#define psys_ipu6s_isa_input_uid            (psys_ipu6s_isa_uid + 4)
#define psys_ipu6s_isa_blc_input_uid        (psys_ipu6s_isa_uid + 5)
#define psys_ipu6s_isa_lsc_input_uid        (psys_ipu6s_isa_uid + 6)
#define psys_ipu6s_isa_output_bayer_uid     (psys_ipu6s_isa_uid + 7)
#define psys_ipu6s_isa_output_yuv_a_uid     (psys_ipu6s_isa_uid + 8)
#define psys_ipu6s_isa_output_yuv_b_uid     (psys_ipu6s_isa_uid + 9)
#define psys_ipu6s_isa_output_full_uid      (psys_ipu6s_isa_uid + 10)
#define psys_ipu6s_isa_output_af_uid        (psys_ipu6s_isa_uid + 11)
#define psys_ipu6s_isa_output_awb_uid       (psys_ipu6s_isa_uid + 12)
#define psys_ipu6s_isa_output_paf_uid       (psys_ipu6s_isa_uid + 13)
#define psys_ipu6s_isa_out_ae_stat_uid      (psys_ipu6s_isa_uid + 14)
#define psys_ipu6s_isa_input_paf_uid        (psys_ipu6s_isa_uid + 15)

#define psys_fake_ipu6s_isa_pg_id                199
#define psys_fake_ipu6s_isa_uid                  psys_2600_pg_uid(psys_fake_ipu6s_isa_pg_id)
#define psys_fake_ipu6s_isa_param_uid            (psys_fake_ipu6s_isa_uid + 1)
#define psys_fake_ipu6s_isa_program_uid          (psys_fake_ipu6s_isa_uid + 2)
#define psys_fake_ipu6s_isa_program_control_uid  (psys_fake_ipu6s_isa_uid + 3)
#define psys_fake_ipu6s_isa_input_uid            (psys_fake_ipu6s_isa_uid + 4)
#define psys_fake_ipu6s_isa_blc_input_uid        (psys_fake_ipu6s_isa_uid + 5)
#define psys_fake_ipu6s_isa_lsc_input_uid        (psys_fake_ipu6s_isa_uid + 6)
#define psys_fake_ipu6s_isa_output_bayer_uid     (psys_fake_ipu6s_isa_uid + 7)
#define psys_fake_ipu6s_isa_output_yuv_a_uid     (psys_fake_ipu6s_isa_uid + 8)
#define psys_fake_ipu6s_isa_output_yuv_b_uid     (psys_fake_ipu6s_isa_uid + 9)
#define psys_fake_ipu6s_isa_output_full_uid      (psys_fake_ipu6s_isa_uid + 10)
#define psys_fake_ipu6s_isa_output_af_uid        (psys_fake_ipu6s_isa_uid + 11)
#define psys_fake_ipu6s_isa_output_awb_uid       (psys_fake_ipu6s_isa_uid + 12)
#define psys_fake_ipu6s_isa_output_paf_uid       (psys_fake_ipu6s_isa_uid + 13)

#if !defined(IPU_SYSVER_ipu6v5) && !defined (IPU_SYSVER_ipu6v6)
#define psys_ipu6_isa_lb_pg_id                     187
#define psys_ipu6_isa_lb_uid                       psys_2600_pg_uid(psys_ipu6_isa_lb_pg_id)
#define psys_ipu6_isa_lb_param_in_uid              (psys_ipu6_isa_lb_uid + 1)
#define psys_ipu6_isa_lb_program_uid               (psys_ipu6_isa_lb_uid + 2)
#define psys_ipu6_isa_lb_program_control_init_uid  (psys_ipu6_isa_lb_uid + 3)
#define psys_ipu6_isa_lb_input_high_uid            (psys_ipu6_isa_lb_uid + 4)
#define psys_ipu6_isa_lb_blc_grid_uid              (psys_ipu6_isa_lb_uid + 5)
#define psys_ipu6_isa_lb_lsc_grid_uid              (psys_ipu6_isa_lb_uid + 6)
#define psys_ipu6_isa_lb_gammastar_grid_uid        (psys_ipu6_isa_lb_uid + 7)
#define psys_ipu6_isa_lb_output_uid                (psys_ipu6_isa_lb_uid + 8)
#define psys_ipu6_isa_lb_output_bayer_uid          (psys_ipu6_isa_lb_uid + 9)
#define psys_ipu6_isa_lb_output_yuv_b_uid          (psys_ipu6_isa_lb_uid + 10)
#define psys_ipu6_isa_lb_output_sis_a_uid          (psys_ipu6_isa_lb_uid + 11)
#define psys_ipu6_isa_lb_output_sis_b_uid          (psys_ipu6_isa_lb_uid + 12)
#define psys_ipu6_isa_lb_output_full_uid           (psys_ipu6_isa_lb_uid + 13)
#define psys_ipu6_isa_lb_output_ir_depth_uid       (psys_ipu6_isa_lb_uid + 14)
#define psys_ipu6_isa_lb_spt_af_uid                (psys_ipu6_isa_lb_uid + 15)
#define psys_ipu6_isa_lb_spt_awb_uid               (psys_ipu6_isa_lb_uid + 16)
#define psys_ipu6_isa_lb_spt_paf_uid               (psys_ipu6_isa_lb_uid + 17)
#define psys_ipu6_isa_lb_dvs_mv_out_l0_uid         (psys_ipu6_isa_lb_uid + 18)
#define psys_ipu6_isa_lb_dvs_mv_out_l1_uid         (psys_ipu6_isa_lb_uid + 19)
#define psys_ipu6_isa_lb_dvs_mv_out_l2_uid         (psys_ipu6_isa_lb_uid + 20)
#define psys_ipu6_isa_lb_ae_stat_uid               (psys_ipu6_isa_lb_uid + 21)
#define psys_ipu6_isa_lb_dvs_fe_in_l0_uid          (psys_ipu6_isa_lb_uid + 22)
#define psys_ipu6_isa_lb_dvs_fe_in_l1_uid          (psys_ipu6_isa_lb_uid + 23)
#define psys_ipu6_isa_lb_dvs_fe_in_l2_uid          (psys_ipu6_isa_lb_uid + 24)
#define psys_ipu6_isa_lb_dvs_fe_out_l0_uid         (psys_ipu6_isa_lb_uid + 25)
#define psys_ipu6_isa_lb_dvs_fe_out_l1_uid         (psys_ipu6_isa_lb_uid + 26)
#define psys_ipu6_isa_lb_dvs_fe_out_l2_uid         (psys_ipu6_isa_lb_uid + 27)
#define psys_ipu6_isa_lb_input_short_uid           (psys_ipu6_isa_lb_uid + 28)
#define psys_ipu6_isa_lb_input_medium_uid          (psys_ipu6_isa_lb_uid + 29)
#define psys_ipu6_isa_lb_paf_uid                   (psys_ipu6_isa_lb_uid + 30)
#else
#define psys_ipu6_isa_lb_pg_id                     187
#define psys_ipu6_isa_lb_uid                       psys_2600_pg_uid(psys_ipu6_isa_lb_pg_id)
#define psys_ipu6_isa_lb_param_in_uid              (psys_ipu6_isa_lb_uid + 1)
#define psys_ipu6_isa_lb_program_uid               (psys_ipu6_isa_lb_uid + 2)
#define psys_ipu6_isa_lb_program_control_init_uid  (psys_ipu6_isa_lb_uid + 3)
#define psys_ipu6_isa_lb_input_high_uid            (psys_ipu6_isa_lb_uid + 4)
#define psys_ipu6_isa_lb_blc_grid_uid              (psys_ipu6_isa_lb_uid + 5)
#define psys_ipu6_isa_lb_lsc_grid_uid              (psys_ipu6_isa_lb_uid + 6)
#define psys_ipu6_isa_lb_gammastar_grid_uid        (psys_ipu6_isa_lb_uid + 7)
#define psys_ipu6_isa_lb_output_uid                (psys_ipu6_isa_lb_uid + 8)
#define psys_ipu6_isa_lb_output_bayer_uid          (psys_ipu6_isa_lb_uid + 9)
#define psys_ipu6_isa_lb_output_sis_a_uid          (psys_ipu6_isa_lb_uid + 10)
#define psys_ipu6_isa_lb_output_sis_b_uid          (psys_ipu6_isa_lb_uid + 11)
#define psys_ipu6_isa_lb_output_full_uid           (psys_ipu6_isa_lb_uid + 12)
#define psys_ipu6_isa_lb_output_ir_depth_uid       (psys_ipu6_isa_lb_uid + 13)
#define psys_ipu6_isa_lb_spt_af_uid                (psys_ipu6_isa_lb_uid + 14)
#define psys_ipu6_isa_lb_spt_awb_uid               (psys_ipu6_isa_lb_uid + 15)
#define psys_ipu6_isa_lb_spt_paf_uid               (psys_ipu6_isa_lb_uid + 16)
#define psys_ipu6_isa_lb_dvs_mv_out_l0_uid         (psys_ipu6_isa_lb_uid + 17)
#define psys_ipu6_isa_lb_dvs_mv_out_l1_uid         (psys_ipu6_isa_lb_uid + 18)
#define psys_ipu6_isa_lb_dvs_mv_out_l2_uid         (psys_ipu6_isa_lb_uid + 19)
#define psys_ipu6_isa_lb_ae_stat_uid               (psys_ipu6_isa_lb_uid + 20)
#define psys_ipu6_isa_lb_dvs_fe_in_l0_uid          (psys_ipu6_isa_lb_uid + 21)
#define psys_ipu6_isa_lb_dvs_fe_in_l1_uid          (psys_ipu6_isa_lb_uid + 22)
#define psys_ipu6_isa_lb_dvs_fe_in_l2_uid          (psys_ipu6_isa_lb_uid + 23)
#define psys_ipu6_isa_lb_dvs_fe_out_l0_uid         (psys_ipu6_isa_lb_uid + 24)
#define psys_ipu6_isa_lb_dvs_fe_out_l1_uid         (psys_ipu6_isa_lb_uid + 25)
#define psys_ipu6_isa_lb_dvs_fe_out_l2_uid         (psys_ipu6_isa_lb_uid + 26)
#define psys_ipu6_isa_lb_paf_uid                   (psys_ipu6_isa_lb_uid + 27)

#endif


#define psys_ipu6_bb_gdc_pg_id                 196
#define psys_ipu6_bb_gdc_uid                   psys_2600_pg_uid(psys_ipu6_bb_gdc_pg_id)
#define psys_ipu6_bb_gdc_input_uid             (psys_ipu6_bb_gdc_uid + 1)
#define psys_ipu6_bb_gdc_mp_uid                (psys_ipu6_bb_gdc_uid + 2)
#define psys_ipu6_bb_gdc_dp_uid                (psys_ipu6_bb_gdc_uid + 3)
#define psys_ipu6_bb_gdc_ppp_uid               (psys_ipu6_bb_gdc_uid + 4)
#define psys_ipu6_bb_gdc_program_control_uid   (psys_ipu6_bb_gdc_uid + 5)
#define psys_ipu6_bb_gdc_param_in_uid          (psys_ipu6_bb_gdc_uid + 6)
#define psys_ipu6_bb_gdc_program_uid           (psys_ipu6_bb_gdc_uid + 7)

#define psys_2600_video_pre_gdc_hq_pg_id             122
#define psys_2600_video_pre_gdc_hq_uid               psys_2600_pg_uid(psys_2600_video_pre_gdc_hq_pg_id)
#define psys_2600_video_pre_gdc_hq_param_uid         psys_2600_video_pre_gdc_hq_uid + 1
#define psys_2600_video_pre_gdc_hq_program_uid       psys_2600_video_pre_gdc_hq_uid + 2
#define psys_2600_video_pre_gdc_hq_input_uid         psys_2600_video_pre_gdc_hq_uid + 3
#define psys_2600_video_pre_gdc_hq_output_uid        psys_2600_video_pre_gdc_hq_uid + 4
#define psys_2600_video_pre_gdc_hq_spatial_in_0_uid  psys_2600_video_pre_gdc_hq_uid + 5
#define psys_2600_video_pre_gdc_hq_spatial_in_1_uid  psys_2600_video_pre_gdc_hq_uid + 6
#define psys_2600_video_pre_gdc_hq_spatial_in_2_uid  psys_2600_video_pre_gdc_hq_uid + 7
#define psys_2600_video_pre_gdc_hq_spatial_out_0_uid psys_2600_video_pre_gdc_hq_uid + 8
#define psys_2600_video_pre_gdc_hq_spatial_out_1_uid psys_2600_video_pre_gdc_hq_uid + 9
#define psys_2600_video_pre_gdc_hq_spatial_out_2_uid psys_2600_video_pre_gdc_hq_uid + 10

#define psys_2600_video_pre_gdc_hq_vcr2_pg_id             148
#define psys_2600_video_pre_gdc_hq_vcr2_uid               psys_2600_pg_uid(psys_2600_video_pre_gdc_hq_vcr2_pg_id)
#define psys_2600_video_pre_gdc_hq_vcr2_param_uid         psys_2600_video_pre_gdc_hq_vcr2_uid + 1
#define psys_2600_video_pre_gdc_hq_vcr2_program_uid       psys_2600_video_pre_gdc_hq_vcr2_uid + 2
#define psys_2600_video_pre_gdc_hq_vcr2_input_uid         psys_2600_video_pre_gdc_hq_vcr2_uid + 3
#define psys_2600_video_pre_gdc_hq_vcr2_output_uid        psys_2600_video_pre_gdc_hq_vcr2_uid + 4
#define psys_2600_video_pre_gdc_hq_vcr2_spatial_in_0_uid  psys_2600_video_pre_gdc_hq_vcr2_uid + 5
#define psys_2600_video_pre_gdc_hq_vcr2_spatial_in_1_uid  psys_2600_video_pre_gdc_hq_vcr2_uid + 6
#define psys_2600_video_pre_gdc_hq_vcr2_spatial_in_2_uid  psys_2600_video_pre_gdc_hq_vcr2_uid + 7
#define psys_2600_video_pre_gdc_hq_vcr2_spatial_out_0_uid psys_2600_video_pre_gdc_hq_vcr2_uid + 8
#define psys_2600_video_pre_gdc_hq_vcr2_spatial_out_1_uid psys_2600_video_pre_gdc_hq_vcr2_uid + 9
#define psys_2600_video_pre_gdc_hq_vcr2_spatial_out_2_uid psys_2600_video_pre_gdc_hq_vcr2_uid + 10

#define psys_2600_ipu5_still_pre_gdc_pg_id        143
#define psys_2600_ipu5_still_pre_gdc_uid          psys_2600_pg_uid(psys_2600_ipu5_still_pre_gdc_pg_id)
#define psys_2600_ipu5_still_pre_gdc_param_uid    psys_2600_ipu5_still_pre_gdc_uid + 1
#define psys_2600_ipu5_still_pre_gdc_program_uid  psys_2600_ipu5_still_pre_gdc_uid + 2
#define psys_2600_ipu5_still_pre_gdc_gammstar_acc_ctrl_uid    psys_2600_ipu5_still_pre_gdc_uid + 3
#define psys_2600_ipu5_still_pre_gdc_input_uid   psys_2600_ipu5_still_pre_gdc_uid + 4
#define psys_2600_ipu5_still_pre_gdc_output_uid   psys_2600_ipu5_still_pre_gdc_uid + 5


#define psys_2600_ipu5_still_pre_gdc_no_xnr_pg_id        144
#define psys_2600_ipu5_still_pre_gdc_no_xnr_uid          psys_2600_pg_uid(psys_2600_ipu5_still_pre_gdc_no_xnr_pg_id)
#define psys_2600_ipu5_still_pre_gdc_no_xnr_param_uid    psys_2600_ipu5_still_pre_gdc_no_xnr_uid + 1
#define psys_2600_ipu5_still_pre_gdc_no_xnr_program_uid  psys_2600_ipu5_still_pre_gdc_no_xnr_uid + 2
#define psys_2600_ipu5_still_pre_gdc_no_xnr_gammstar_acc_ctrl_uid    psys_2600_ipu5_still_pre_gdc_no_xnr_uid + 3
#define psys_2600_ipu5_still_pre_gdc_no_xnr_input_uid    psys_2600_ipu5_still_pre_gdc_no_xnr_uid + 4
#define psys_2600_ipu5_still_pre_gdc_no_xnr_output_uid   psys_2600_ipu5_still_pre_gdc_no_xnr_uid + 5

#define psys_2600_ipu5_still_pre_gdc_vpless_pg_id                       168
#define psys_2600_ipu5_still_pre_gdc_vpless_uid                         psys_2600_pg_uid(psys_2600_ipu5_still_pre_gdc_vpless_pg_id)
#define psys_2600_ipu5_still_pre_gdc_vpless_param_uid                   psys_2600_ipu5_still_pre_gdc_vpless_uid + 1
#define psys_2600_ipu5_still_pre_gdc_vpless_program_uid                 psys_2600_ipu5_still_pre_gdc_vpless_uid + 2
#define psys_2600_ipu5_still_pre_gdc_vpless_gammstar_acc_ctrl_uid       psys_2600_ipu5_still_pre_gdc_vpless_uid + 3
#define psys_2600_ipu5_still_pre_gdc_vpless_input_uid                   psys_2600_ipu5_still_pre_gdc_vpless_uid + 4
#define psys_2600_ipu5_still_pre_gdc_vpless_output_uid                  psys_2600_ipu5_still_pre_gdc_vpless_uid + 5
#define psys_2600_ipu5_still_pre_gdc_vpless_spt_gammstar_grid           psys_2600_ipu5_still_pre_gdc_vpless_uid + 6

#define psys_ipu5_still_post_gdc_v4_pg_id                162
#define psys_ipu5_still_post_gdc_v4_uid                  psys_2600_pg_uid(psys_ipu5_still_post_gdc_v4_pg_id)
#define psys_ipu5_still_post_gdc_v4_param_uid            psys_ipu5_still_post_gdc_v4_uid + 1
#define psys_ipu5_still_post_gdc_v4_program_uid          psys_ipu5_still_post_gdc_v4_uid + 2
#define psys_ipu5_still_post_gdc_v4_input_uid            psys_ipu5_still_post_gdc_v4_uid + 3
#define psys_ipu5_still_post_gdc_v4_spatial_param_uid    psys_ipu5_still_post_gdc_v4_uid + 4
#define psys_ipu5_still_post_gdc_v4_output_uid           psys_ipu5_still_post_gdc_v4_uid + 5
#define psys_ipu5_still_post_gdc_v4_secondary_output_uid psys_ipu5_still_post_gdc_v4_uid + 6
#define psys_ipu5_still_post_gdc_v4_third_output_uid     psys_ipu5_still_post_gdc_v4_uid + 7

#define psys_ipu5_video_post_gdc_pg_id                151
#define psys_ipu5_video_post_gdc_uid                  psys_2600_pg_uid(psys_ipu5_video_post_gdc_pg_id)
#define psys_ipu5_video_post_gdc_param_uid            psys_ipu5_video_post_gdc_uid + 1
#define psys_ipu5_video_post_gdc_program_uid          psys_ipu5_video_post_gdc_uid + 2
#define psys_ipu5_video_post_gdc_input_uid            psys_ipu5_video_post_gdc_uid + 3
#define psys_ipu5_video_post_gdc_spatial_param_uid    psys_ipu5_video_post_gdc_uid + 4
#define psys_ipu5_video_post_gdc_output_uid           psys_ipu5_video_post_gdc_uid + 5
#define psys_ipu5_video_post_gdc_secondary_output_uid psys_ipu5_video_post_gdc_uid + 6
#define psys_ipu5_video_post_gdc_third_output_uid     psys_ipu5_video_post_gdc_uid + 7
#define psys_ipu5_video_post_gdc_tnr_input_uid        psys_ipu5_video_post_gdc_uid + 8
#define psys_ipu5_video_post_gdc_tnr_output_uid       psys_ipu5_video_post_gdc_uid + 9

#define psys_ipu5_video_post_gdc_v4_pg_id                169
#define psys_ipu5_video_post_gdc_v4_uid                  psys_2600_pg_uid(psys_ipu5_video_post_gdc_v4_pg_id)
#define psys_ipu5_video_post_gdc_v4_param_uid            psys_ipu5_video_post_gdc_v4_uid + 1
#define psys_ipu5_video_post_gdc_v4_program_uid          psys_ipu5_video_post_gdc_v4_uid + 2
#define psys_ipu5_video_post_gdc_v4_input_uid            psys_ipu5_video_post_gdc_v4_uid + 3
#define psys_ipu5_video_post_gdc_v4_spatial_param_uid    psys_ipu5_video_post_gdc_v4_uid + 4
#define psys_ipu5_video_post_gdc_v4_output_uid           psys_ipu5_video_post_gdc_v4_uid + 5
#define psys_ipu5_video_post_gdc_v4_secondary_output_uid psys_ipu5_video_post_gdc_v4_uid + 6
#define psys_ipu5_video_post_gdc_v4_third_output_uid     psys_ipu5_video_post_gdc_v4_uid + 7
#define psys_ipu5_video_post_gdc_v4_tnr_input_uid        psys_ipu5_video_post_gdc_v4_uid + 8
#define psys_ipu5_video_post_gdc_v4_tnr_output_uid       psys_ipu5_video_post_gdc_v4_uid + 9

#define psys_ipu5_video_post_gdc_10bit_pg_id                193
#define psys_ipu5_video_post_gdc_10bit_uid                  psys_2600_pg_uid(psys_ipu5_video_post_gdc_10bit_pg_id)
#define psys_ipu5_video_post_gdc_10bit_param_uid            psys_ipu5_video_post_gdc_10bit_uid + 1
#define psys_ipu5_video_post_gdc_10bit_program_uid          psys_ipu5_video_post_gdc_10bit_uid + 2
#define psys_ipu5_video_post_gdc_10bit_input_uid            psys_ipu5_video_post_gdc_10bit_uid + 3
#define psys_ipu5_video_post_gdc_10bit_spatial_param_uid    psys_ipu5_video_post_gdc_10bit_uid + 4
#define psys_ipu5_video_post_gdc_10bit_output_uid           psys_ipu5_video_post_gdc_10bit_uid + 5
#define psys_ipu5_video_post_gdc_10bit_secondary_output_uid psys_ipu5_video_post_gdc_10bit_uid + 6
#define psys_ipu5_video_post_gdc_10bit_third_output_uid     psys_ipu5_video_post_gdc_10bit_uid + 7
#define psys_ipu5_video_post_gdc_10bit_tnr_input_uid        psys_ipu5_video_post_gdc_10bit_uid + 8
#define psys_ipu5_video_post_gdc_10bit_tnr_output_uid       psys_ipu5_video_post_gdc_10bit_uid + 9
#define psys_ipu5_video_post_gdc_10bit_main_output_uid      psys_ipu5_video_post_gdc_10bit_uid + 10
#define psys_ipu5_video_post_gdc_10bit_display_output_uid   psys_ipu5_video_post_gdc_10bit_uid + 11

#define psys_ipu5_still_post_gdc_10bit_pg_id                197
#define psys_ipu5_still_post_gdc_10bit_uid                  psys_2600_pg_uid(psys_ipu5_still_post_gdc_10bit_pg_id)
#define psys_ipu5_still_post_gdc_10bit_param_uid            psys_ipu5_still_post_gdc_10bit_uid + 1
#define psys_ipu5_still_post_gdc_10bit_program_uid          psys_ipu5_still_post_gdc_10bit_uid + 2
#define psys_ipu5_still_post_gdc_10bit_input_uid            psys_ipu5_still_post_gdc_10bit_uid + 3
#define psys_ipu5_still_post_gdc_10bit_spatial_param_uid    psys_ipu5_still_post_gdc_10bit_uid + 4
#define psys_ipu5_still_post_gdc_10bit_output_uid           psys_ipu5_still_post_gdc_10bit_uid + 5
#define psys_ipu5_still_post_gdc_10bit_secondary_output_uid psys_ipu5_still_post_gdc_10bit_uid + 6
#define psys_ipu5_still_post_gdc_10bit_third_output_uid     psys_ipu5_still_post_gdc_10bit_uid + 7
#define psys_ipu5_still_post_gdc_10bit_main_output_uid      psys_ipu5_still_post_gdc_10bit_uid + 8
#define psys_ipu5_still_post_gdc_10bit_display_output_uid   psys_ipu5_still_post_gdc_10bit_uid + 9


#ifdef _MSC_VER
    #define psys_2600_still_pre_gdc_pg_id    136
#else //_MSC_VER
    #define psys_2600_still_pre_gdc_pg_id    131
#endif
#define psys_2600_still_pre_gdc_uid          psys_2600_pg_uid(psys_2600_still_pre_gdc_pg_id)
#define psys_2600_still_pre_gdc_param_uid    psys_2600_still_pre_gdc_uid + 1
#define psys_2600_still_pre_gdc_program_uid  psys_2600_still_pre_gdc_uid + 2
#define psys_2600_still_pre_gdc_input_uid    psys_2600_still_pre_gdc_uid + 3
#define psys_2600_still_pre_gdc_output_uid   psys_2600_still_pre_gdc_uid + 4

#define psys_2600_still_pre_gdc_vcr2_pg_id        150
#define psys_2600_still_pre_gdc_vcr2_uid          psys_2600_pg_uid(psys_2600_still_pre_gdc_vcr2_pg_id)
#define psys_2600_still_pre_gdc_vcr2_param_uid    psys_2600_still_pre_gdc_vcr2_uid + 1
#define psys_2600_still_pre_gdc_vcr2_program_uid  psys_2600_still_pre_gdc_vcr2_uid + 2
#define psys_2600_still_pre_gdc_vcr2_input_uid    psys_2600_still_pre_gdc_vcr2_uid + 3
#define psys_2600_still_pre_gdc_vcr2_output_uid   psys_2600_still_pre_gdc_vcr2_uid + 4

/* \todo dummy definition for Windows only until we can sort out the conflict
 * needed to continue patch porting, this allows the conflicts to only be present in this file
 */
#ifdef _MSC_VER
    #define psys_2600_still_pre_gdc_v3_uid          ia_fourcc('D','U','M','Y') // DUMMY
#else
    #define psys_2600_still_pre_gdc_v3_pg_id        136
    #define psys_2600_still_pre_gdc_v3_uid          psys_2600_pg_uid(psys_2600_still_pre_gdc_v3_pg_id)
    #define psys_2600_still_pre_gdc_v3_param_uid    psys_2600_still_pre_gdc_v3_uid + 1
    #define psys_2600_still_pre_gdc_v3_program_uid  psys_2600_still_pre_gdc_v3_uid + 2
    #define psys_2600_still_pre_gdc_v3_input_uid    psys_2600_still_pre_gdc_v3_uid + 3
    #define psys_2600_still_pre_gdc_v3_output_uid   psys_2600_still_pre_gdc_v3_uid + 4
#endif

#define psys_2600_still_post_gdc_pg_id                118
#define psys_2600_still_post_gdc_uid                  psys_2600_pg_uid(psys_2600_still_post_gdc_pg_id)
#define psys_2600_still_post_gdc_param_uid            psys_2600_still_post_gdc_uid + 1
#define psys_2600_still_post_gdc_program_uid          psys_2600_still_post_gdc_uid + 2
#define psys_2600_still_post_gdc_input_uid            psys_2600_still_post_gdc_uid + 3
#define psys_2600_still_post_gdc_spatial_param_uid    psys_2600_still_post_gdc_uid + 4
#define psys_2600_still_post_gdc_output_uid           psys_2600_still_post_gdc_uid + 5
#define psys_2600_still_post_gdc_secondary_output_uid psys_2600_still_post_gdc_uid + 6
#define psys_2600_still_post_gdc_third_output_uid     psys_2600_still_post_gdc_uid + 7

#define psys_2600_still_post_gdc_v2_pg_id                128
#define psys_2600_still_post_gdc_v2_uid                  psys_2600_pg_uid(psys_2600_still_post_gdc_v2_pg_id)
#define psys_2600_still_post_gdc_v2_param_uid            psys_2600_still_post_gdc_v2_uid + 1
#define psys_2600_still_post_gdc_v2_program_uid          psys_2600_still_post_gdc_v2_uid + 2
#define psys_2600_still_post_gdc_v2_input_uid            psys_2600_still_post_gdc_v2_uid + 3
#define psys_2600_still_post_gdc_v2_spatial_param_uid    psys_2600_still_post_gdc_v2_uid + 4
#define psys_2600_still_post_gdc_v2_output_uid           psys_2600_still_post_gdc_v2_uid + 5
#define psys_2600_still_post_gdc_v2_secondary_output_uid psys_2600_still_post_gdc_v2_uid + 6
#define psys_2600_still_post_gdc_v2_third_output_uid     psys_2600_still_post_gdc_v2_uid + 7

#define psys_2600_still_post_gdc_mbr_pg_id                133
#define psys_2600_still_post_gdc_mbr_uid                  psys_2600_pg_uid(psys_2600_still_post_gdc_mbr_pg_id)
#define psys_2600_still_post_gdc_mbr_param_uid            psys_2600_still_post_gdc_mbr_uid + 1
#define psys_2600_still_post_gdc_mbr_program_uid          psys_2600_still_post_gdc_mbr_uid + 2
#define psys_2600_still_post_gdc_mbr_input_uid            psys_2600_still_post_gdc_mbr_uid + 3
#define psys_2600_still_post_gdc_mbr_spatial_param_uid    psys_2600_still_post_gdc_mbr_uid + 4
#define psys_2600_still_post_gdc_mbr_output_uid           psys_2600_still_post_gdc_mbr_uid + 5
#define psys_2600_still_post_gdc_mbr_secondary_output_uid psys_2600_still_post_gdc_mbr_uid + 6
#define psys_2600_still_post_gdc_mbr_third_output_uid     psys_2600_still_post_gdc_mbr_uid + 7

#define psys_2600_still_post_gdc_v2_mbr_pg_id                173
#define psys_2600_still_post_gdc_v2_mbr_uid                  psys_2600_pg_uid(psys_2600_still_post_gdc_v2_mbr_pg_id)
#define psys_2600_still_post_gdc_v2_mbr_param_uid            psys_2600_still_post_gdc_v2_mbr_uid + 1
#define psys_2600_still_post_gdc_v2_mbr_program_uid          psys_2600_still_post_gdc_v2_mbr_uid + 2
#define psys_2600_still_post_gdc_v2_mbr_input_uid            psys_2600_still_post_gdc_v2_mbr_uid + 3
#define psys_2600_still_post_gdc_v2_mbr_spatial_param_uid    psys_2600_still_post_gdc_v2_mbr_uid + 4
#define psys_2600_still_post_gdc_v2_mbr_output_uid           psys_2600_still_post_gdc_v2_mbr_uid + 5
#define psys_2600_still_post_gdc_v2_mbr_secondary_output_uid psys_2600_still_post_gdc_v2_mbr_uid + 6
#define psys_2600_still_post_gdc_v2_mbr_third_output_uid     psys_2600_still_post_gdc_v2_mbr_uid + 7

#define psys_2600_video_isa_pg_id                127
#define psys_2600_video_isa_uid                  psys_2600_pg_uid(psys_2600_video_isa_pg_id)
#define psys_2600_video_isa_param_uid            psys_2600_video_isa_uid + 1
#define psys_2600_video_isa_program_uid          psys_2600_video_isa_uid + 2
#define psys_2600_video_isa_input_uid            psys_2600_video_isa_uid + 3
#define psys_2600_video_isa_output_uid           psys_2600_video_isa_uid + 4
#define psys_2600_video_isa_secondary_output_uid psys_2600_video_isa_uid + 5
#define psys_2600_video_isa_ae_output_uid        psys_2600_video_isa_uid + 6
#define psys_2600_video_isa_blc_type0_input_uid  psys_2600_video_isa_uid + 7
#define psys_2600_video_isa_blc_type1_input_uid  psys_2600_video_isa_uid + 8
#define psys_2600_video_isa_blc_type2_input_uid  psys_2600_video_isa_uid + 9
#define psys_2600_video_isa_lsc_type0_input_uid  psys_2600_video_isa_uid + 10
#define psys_2600_video_isa_lsc_type1_input_uid  psys_2600_video_isa_uid + 11
#define psys_2600_video_isa_lsc_type2_input_uid  psys_2600_video_isa_uid + 12
#define psys_2600_video_isa_awb_output_uid       psys_2600_video_isa_uid + 13
#define psys_2600_video_isa_af_output_uid        psys_2600_video_isa_uid + 14

#define psys_2600_video_rgbir_isa_pg_id                130
#define psys_2600_video_rgbir_isa_uid                  psys_2600_pg_uid(psys_2600_video_rgbir_isa_pg_id)
#define psys_2600_video_rgbir_isa_param_uid            psys_2600_video_rgbir_isa_uid + 1
#define psys_2600_video_rgbir_isa_program_uid          psys_2600_video_rgbir_isa_uid + 2
#define psys_2600_video_rgbir_isa_input_uid            psys_2600_video_rgbir_isa_uid + 3
#define psys_2600_video_rgbir_isa_output_uid           psys_2600_video_rgbir_isa_uid + 4
#define psys_2600_video_rgbir_isa_secondary_output_uid psys_2600_video_rgbir_isa_uid + 5
#define psys_2600_video_rgbir_isa_ae_output_uid        psys_2600_video_rgbir_isa_uid + 6
#define psys_2600_video_rgbir_isa_blc_type0_input_uid  psys_2600_video_rgbir_isa_uid + 7
#define psys_2600_video_rgbir_isa_blc_type1_input_uid  psys_2600_video_rgbir_isa_uid + 8
#define psys_2600_video_rgbir_isa_blc_type2_input_uid  psys_2600_video_rgbir_isa_uid + 9
#define psys_2600_video_rgbir_isa_lsc_type0_input_uid  psys_2600_video_rgbir_isa_uid + 10
#define psys_2600_video_rgbir_isa_lsc_type1_input_uid  psys_2600_video_rgbir_isa_uid + 11
#define psys_2600_video_rgbir_isa_lsc_type2_input_uid  psys_2600_video_rgbir_isa_uid + 12
#define psys_2600_video_rgbir_isa_awb_output_uid       psys_2600_video_rgbir_isa_uid + 13
#define psys_2600_video_rgbir_isa_af_output_uid        psys_2600_video_rgbir_isa_uid + 14


#define psys_2600_ipu5_video_isa_pg_id                141
#define psys_2600_ipu5_video_isa_uid                  psys_2600_pg_uid(psys_2600_ipu5_video_isa_pg_id)
#define psys_2600_ipu5_video_isa_param_uid            psys_2600_ipu5_video_isa_uid + 1
#define psys_2600_ipu5_video_isa_program_uid          psys_2600_ipu5_video_isa_uid + 2
#define psys_2600_ipu5_video_isa_input_uid            psys_2600_ipu5_video_isa_uid + 3
#define psys_2600_ipu5_video_isa_output_uid           psys_2600_ipu5_video_isa_uid + 4
#define psys_2600_ipu5_video_isa_secondary_output_uid psys_2600_ipu5_video_isa_uid + 5
#define psys_2600_ipu5_video_isa_sis_output_uid       psys_2600_ipu5_video_isa_uid + 6
#define psys_2600_ipu5_video_isa_ae_output_uid        psys_2600_ipu5_video_isa_uid + 7
#define psys_2600_ipu5_video_isa_blc_type0_input_uid  psys_2600_ipu5_video_isa_uid + 8
#define psys_2600_ipu5_video_isa_blc_type1_input_uid  psys_2600_ipu5_video_isa_uid + 9
#define psys_2600_ipu5_video_isa_blc_type2_input_uid  psys_2600_ipu5_video_isa_uid + 10
#define psys_2600_ipu5_video_isa_lsc_type0_input_uid  psys_2600_ipu5_video_isa_uid + 11
#define psys_2600_ipu5_video_isa_lsc_type1_input_uid  psys_2600_ipu5_video_isa_uid + 12
#define psys_2600_ipu5_video_isa_lsc_type2_input_uid  psys_2600_ipu5_video_isa_uid + 13
#define psys_2600_ipu5_video_isa_awb_output_uid       psys_2600_ipu5_video_isa_uid + 14
#define psys_2600_ipu5_video_isa_af_output_uid        psys_2600_ipu5_video_isa_uid + 15

#define psys_ipu5_dfm_isa_to_psa_yuv_vmem_pg_id                174
#define psys_ipu5_dfm_isa_to_psa_yuv_vmem_uid                  psys_2600_pg_uid(psys_ipu5_dfm_isa_to_psa_yuv_vmem_pg_id)
#define psys_ipu5_dfm_isa_to_psa_yuv_vmem_param_uid            psys_ipu5_dfm_isa_to_psa_yuv_vmem_pg_id + 1
#define psys_ipu5_dfm_isa_to_psa_yuv_vmem_program_uid          psys_ipu5_dfm_isa_to_psa_yuv_vmem_pg_id + 2
#define psys_ipu5_dfm_isa_to_psa_yuv_vmem_bayer_output_uid     psys_ipu5_dfm_isa_to_psa_yuv_vmem_pg_id + 3
#define psys_ipu5_dfm_isa_to_psa_yuv_vmem_sis_output_uid       psys_ipu5_dfm_isa_to_psa_yuv_vmem_pg_id + 4
#define psys_ipu5_dfm_isa_to_psa_yuv_vmem_ae_output_uid        psys_ipu5_dfm_isa_to_psa_yuv_vmem_pg_id + 5
#define psys_ipu5_dfm_isa_to_psa_yuv_vmem_blc_type0_input_uid  psys_ipu5_dfm_isa_to_psa_yuv_vmem_pg_id + 6
#define psys_ipu5_dfm_isa_to_psa_yuv_vmem_blc_type1_input_uid  psys_ipu5_dfm_isa_to_psa_yuv_vmem_pg_id + 7
#define psys_ipu5_dfm_isa_to_psa_yuv_vmem_blc_type2_input_uid  psys_ipu5_dfm_isa_to_psa_yuv_vmem_pg_id + 8
#define psys_ipu5_dfm_isa_to_psa_yuv_vmem_lsc_type0_input_uid  psys_ipu5_dfm_isa_to_psa_yuv_vmem_pg_id + 9
#define psys_ipu5_dfm_isa_to_psa_yuv_vmem_lsc_type1_input_uid  psys_ipu5_dfm_isa_to_psa_yuv_vmem_pg_id + 10
#define psys_ipu5_dfm_isa_to_psa_yuv_vmem_lsc_type2_input_uid  psys_ipu5_dfm_isa_to_psa_yuv_vmem_pg_id + 11
#define psys_ipu5_dfm_isa_to_psa_yuv_vmem_awb_output_uid       psys_ipu5_dfm_isa_to_psa_yuv_vmem_pg_id + 12
#define psys_ipu5_dfm_isa_to_psa_yuv_vmem_af_output_uid        psys_ipu5_dfm_isa_to_psa_yuv_vmem_pg_id + 13
#define psys_ipu5_dfm_isa_to_psa_yuv_vmem_gammastar_input_uid  psys_ipu5_dfm_isa_to_psa_yuv_vmem_pg_id + 14
#define psys_ipu5_dfm_isa_to_psa_yuv_vmem_input_uid            psys_ipu5_dfm_isa_to_psa_yuv_vmem_pg_id + 15
#define psys_ipu5_dfm_isa_to_psa_yuv_vmem_output_uid           psys_ipu5_dfm_isa_to_psa_yuv_vmem_pg_id + 16

#define psys_ipu5_isa_lb_pg_id                          194
#define psys_ipu5_isa_lb_uid                            psys_2600_pg_uid(psys_ipu5_isa_lb_pg_id)
#define psys_ipu5_isa_lb_param_uid                      psys_ipu5_isa_lb_uid + 1
#define psys_ipu5_isa_lb_program_uid                    psys_ipu5_isa_lb_uid + 2
#define psys_ipu5_isa_lb_program_control_init_uid       psys_ipu5_isa_lb_uid + 3
#define psys_ipu5_isa_lb_input_uid                      psys_ipu5_isa_lb_uid + 4
#define psys_ipu5_isa_lb_input_paf_uid                  psys_ipu5_isa_lb_uid + 5
#define psys_ipu5_isa_lb_bayer_output_uid               psys_ipu5_isa_lb_uid + 6
#define psys_ipu5_isa_lb_sis_output_uid                 psys_ipu5_isa_lb_uid + 7
#define psys_ipu5_isa_lb_yuv_output_uid                 psys_ipu5_isa_lb_uid + 8
#define psys_ipu5_isa_lb_cached_out_param_uid           psys_ipu5_isa_lb_uid + 9
#define psys_ipu5_isa_lb_blc_type0_uid                  psys_ipu5_isa_lb_uid + 10
#define psys_ipu5_isa_lb_blc_type1_uid                  psys_ipu5_isa_lb_uid + 11
#define psys_ipu5_isa_lb_blc_type2_uid                  psys_ipu5_isa_lb_uid + 12
#define psys_ipu5_isa_lb_lsc_type0_uid                  psys_ipu5_isa_lb_uid + 13
#define psys_ipu5_isa_lb_lsc_type1_uid                  psys_ipu5_isa_lb_uid + 14
#define psys_ipu5_isa_lb_lsc_type2_uid                  psys_ipu5_isa_lb_uid + 15
#define psys_ipu5_isa_lb_3a_stat_awb_uid                psys_ipu5_isa_lb_uid + 16
#define psys_ipu5_isa_lb_3a_stat_af_uid                 psys_ipu5_isa_lb_uid + 17
#define psys_ipu5_isa_lb_3a_stat_paf_uid                psys_ipu5_isa_lb_uid + 18
#define psys_ipu5_isa_lb_gammastar_grid_uid             psys_ipu5_isa_lb_uid + 19
#define psys_ipu5_isa_lb_dvs_mv_out_l0_uid              psys_ipu5_isa_lb_uid + 20
#define psys_ipu5_isa_lb_dvs_mv_out_l1_uid              psys_ipu5_isa_lb_uid + 21
#define psys_ipu5_isa_lb_dvs_mv_out_l2_uid              psys_ipu5_isa_lb_uid + 22
#define psys_ipu5_isa_lb_dvs_fe_in_l0_uid               psys_ipu5_isa_lb_uid + 23
#define psys_ipu5_isa_lb_dvs_fe_in_l1_uid               psys_ipu5_isa_lb_uid + 24
#define psys_ipu5_isa_lb_dvs_fe_in_l2_uid               psys_ipu5_isa_lb_uid + 25
#define psys_ipu5_isa_lb_dvs_fe_out_l0_uid              psys_ipu5_isa_lb_uid + 26
#define psys_ipu5_isa_lb_dvs_fe_out_l1_uid              psys_ipu5_isa_lb_uid + 27
#define psys_ipu5_isa_lb_dvs_fe_out_l2_uid              psys_ipu5_isa_lb_uid + 28

#define psys_ipu5_dfm_isl_ps_vpless_pg_id                          166
#define psys_ipu5_dfm_isl_ps_vpless_uid                            psys_2600_pg_uid(psys_ipu5_dfm_isl_ps_vpless_pg_id)
#define psys_ipu5_dfm_isl_ps_vpless_param_uid                      psys_ipu5_dfm_isl_ps_vpless_uid + 1
#define psys_ipu5_dfm_isl_ps_vpless_program_uid                    psys_ipu5_dfm_isl_ps_vpless_uid + 2
#define psys_ipu5_dfm_isl_ps_vpless_program_control_init_uid       psys_ipu5_dfm_isl_ps_vpless_uid + 3
#define psys_ipu5_dfm_isl_ps_vpless_input_uid                      psys_ipu5_dfm_isl_ps_vpless_uid + 4
#define psys_ipu5_dfm_isl_ps_vpless_input_paf_uid                  psys_ipu5_dfm_isl_ps_vpless_uid + 5
#define psys_ipu5_dfm_isl_ps_vpless_yuv_output_uid                 psys_ipu5_dfm_isl_ps_vpless_uid + 6
#define psys_ipu5_dfm_isl_ps_vpless_bayer_output_uid               psys_ipu5_dfm_isl_ps_vpless_uid + 7
#define psys_ipu5_dfm_isl_ps_vpless_sis_output_uid                 psys_ipu5_dfm_isl_ps_vpless_uid + 8
#define psys_ipu5_dfm_isl_ps_vpless_cached_out_param_uid           psys_ipu5_dfm_isl_ps_vpless_uid + 9
#define psys_ipu5_dfm_isl_ps_vpless_blc_type0_uid                  psys_ipu5_dfm_isl_ps_vpless_uid + 10
#define psys_ipu5_dfm_isl_ps_vpless_blc_type1_uid                  psys_ipu5_dfm_isl_ps_vpless_uid + 11
#define psys_ipu5_dfm_isl_ps_vpless_blc_type2_uid                  psys_ipu5_dfm_isl_ps_vpless_uid + 12
#define psys_ipu5_dfm_isl_ps_vpless_lsc_type0_uid                  psys_ipu5_dfm_isl_ps_vpless_uid + 13
#define psys_ipu5_dfm_isl_ps_vpless_lsc_type1_uid                  psys_ipu5_dfm_isl_ps_vpless_uid + 14
#define psys_ipu5_dfm_isl_ps_vpless_lsc_type2_uid                  psys_ipu5_dfm_isl_ps_vpless_uid + 15
#define psys_ipu5_dfm_isl_ps_vpless_3a_stat_awb_uid                psys_ipu5_dfm_isl_ps_vpless_uid + 16
#define psys_ipu5_dfm_isl_ps_vpless_3a_stat_af_uid                 psys_ipu5_dfm_isl_ps_vpless_uid + 17
#define psys_ipu5_dfm_isl_ps_vpless_3a_stat_paf_uid                psys_ipu5_dfm_isl_ps_vpless_uid + 18

#define psys_2600_video_isa_pre_gdc_pg_id               137
#define psys_2600_video_isa_pre_gdc_uid                 psys_2600_pg_uid(psys_2600_video_isa_pre_gdc_pg_id)
#define psys_2600_video_isa_pre_gdc_param_uid           psys_2600_video_isa_pre_gdc_uid + 1
#define psys_2600_video_isa_pre_gdc_ae_output_uid       psys_2600_video_isa_pre_gdc_uid + 2
#define psys_2600_video_isa_pre_gdc_program_uid         psys_2600_video_isa_pre_gdc_uid + 3
#define psys_2600_video_isa_pre_gdc_input_uid           psys_2600_video_isa_pre_gdc_uid + 4
#define psys_2600_video_isa_pre_gdc_output_uid          psys_2600_video_isa_pre_gdc_uid + 5
#define psys_2600_video_isa_pre_gdc_blc_type0_input_uid psys_2600_video_isa_pre_gdc_uid + 6
#define psys_2600_video_isa_pre_gdc_blc_type1_input_uid psys_2600_video_isa_pre_gdc_uid + 7
#define psys_2600_video_isa_pre_gdc_blc_type2_input_uid psys_2600_video_isa_pre_gdc_uid + 8
#define psys_2600_video_isa_pre_gdc_lsc_type0_input_uid psys_2600_video_isa_pre_gdc_uid + 9
#define psys_2600_video_isa_pre_gdc_lsc_type1_input_uid psys_2600_video_isa_pre_gdc_uid + 10
#define psys_2600_video_isa_pre_gdc_lsc_type2_input_uid psys_2600_video_isa_pre_gdc_uid + 11
#define psys_2600_video_isa_pre_gdc_awb_output_uid      psys_2600_video_isa_pre_gdc_uid + 12
#define psys_2600_video_isa_pre_gdc_af_output_uid       psys_2600_video_isa_pre_gdc_uid + 13
#define psys_2600_video_isa_pre_gdc_dvs_in_0_uid        psys_2600_video_isa_pre_gdc_uid + 14
#define psys_2600_video_isa_pre_gdc_dvs_in_1_uid        psys_2600_video_isa_pre_gdc_uid + 15
#define psys_2600_video_isa_pre_gdc_dvs_in_2_uid        psys_2600_video_isa_pre_gdc_uid + 16
#define psys_2600_video_isa_pre_gdc_dvs_out_0_uid       psys_2600_video_isa_pre_gdc_uid + 17
#define psys_2600_video_isa_pre_gdc_dvs_out_1_uid       psys_2600_video_isa_pre_gdc_uid + 18
#define psys_2600_video_isa_pre_gdc_dvs_out_2_uid       psys_2600_video_isa_pre_gdc_uid + 19

#define psys_2600_video_isl_pre_gdc_hq_pg_id                156
#define psys_2600_video_isl_pre_gdc_hq_uid                  psys_2600_pg_uid(psys_2600_video_isl_pre_gdc_hq_pg_id)
#define psys_2600_video_isl_pre_gdc_hq_param_uid            psys_2600_video_isl_pre_gdc_hq_uid + 1
#define psys_2600_video_isl_pre_gdc_hq_ae_output_uid        psys_2600_video_isl_pre_gdc_hq_uid + 2
#define psys_2600_video_isl_pre_gdc_hq_program_uid          psys_2600_video_isl_pre_gdc_hq_uid + 3
#define psys_2600_video_isl_pre_gdc_hq_input_uid            psys_2600_video_isl_pre_gdc_hq_uid + 4
#define psys_2600_video_isl_pre_gdc_hq_output_uid           psys_2600_video_isl_pre_gdc_hq_uid + 5
#define psys_2600_video_isl_pre_gdc_hq_blc_type0_input_uid  psys_2600_video_isl_pre_gdc_hq_uid + 6
#define psys_2600_video_isl_pre_gdc_hq_blc_type1_input_uid  psys_2600_video_isl_pre_gdc_hq_uid + 7
#define psys_2600_video_isl_pre_gdc_hq_blc_type2_input_uid  psys_2600_video_isl_pre_gdc_hq_uid + 8
#define psys_2600_video_isl_pre_gdc_hq_lsc_type0_input_uid  psys_2600_video_isl_pre_gdc_hq_uid + 9
#define psys_2600_video_isl_pre_gdc_hq_lsc_type1_input_uid  psys_2600_video_isl_pre_gdc_hq_uid + 10
#define psys_2600_video_isl_pre_gdc_hq_lsc_type2_input_uid  psys_2600_video_isl_pre_gdc_hq_uid + 11
#define psys_2600_video_isl_pre_gdc_hq_awb_output_uid       psys_2600_video_isl_pre_gdc_hq_uid + 12
#define psys_2600_video_isl_pre_gdc_hq_af_output_uid        psys_2600_video_isl_pre_gdc_hq_uid + 13
#define psys_2600_video_isl_pre_gdc_hq_dvs_in_0_uid         psys_2600_video_isl_pre_gdc_hq_uid + 14
#define psys_2600_video_isl_pre_gdc_hq_dvs_in_1_uid         psys_2600_video_isl_pre_gdc_hq_uid + 15
#define psys_2600_video_isl_pre_gdc_hq_dvs_in_2_uid         psys_2600_video_isl_pre_gdc_hq_uid + 16
#define psys_2600_video_isl_pre_gdc_hq_dvs_out_0_uid        psys_2600_video_isl_pre_gdc_hq_uid + 17
#define psys_2600_video_isl_pre_gdc_hq_dvs_out_1_uid        psys_2600_video_isl_pre_gdc_hq_uid + 18
#define psys_2600_video_isl_pre_gdc_hq_dvs_out_2_uid        psys_2600_video_isl_pre_gdc_hq_uid + 19

#define psys_2600_video_pre_gdc_hp_pg_id                 1002
#define psys_2600_video_pre_gdc_hp_uid                   psys_2600_pg_uid(psys_2600_video_pre_gdc_hp_pg_id)
#define psys_2600_video_pre_gdc_hp_param_uid             psys_2600_video_pre_gdc_hp_uid + 1
#define psys_2600_video_pre_gdc_hp_program_uid           psys_2600_video_pre_gdc_hp_uid + 2
#define psys_2600_video_pre_gdc_hp_input_uid             psys_2600_video_pre_gdc_hp_uid + 3
#define psys_2600_video_pre_gdc_hp_output_uid            psys_2600_video_pre_gdc_hp_uid + 4
#define psys_2600_video_pre_gdc_hp_ae_output_uid         psys_2600_video_pre_gdc_hp_uid + 5
#define psys_2600_video_pre_gdc_hp_blc_type0_input_uid   psys_2600_video_pre_gdc_hp_uid + 6
#define psys_2600_video_pre_gdc_hp_blc_type1_input_uid   psys_2600_video_pre_gdc_hp_uid + 7
#define psys_2600_video_pre_gdc_hp_blc_type2_input_uid   psys_2600_video_pre_gdc_hp_uid + 8
#define psys_2600_video_pre_gdc_hp_lsc_type0_input_uid   psys_2600_video_pre_gdc_hp_uid + 9
#define psys_2600_video_pre_gdc_hp_lsc_type1_input_uid   psys_2600_video_pre_gdc_hp_uid + 10
#define psys_2600_video_pre_gdc_hp_lsc_type2_input_uid   psys_2600_video_pre_gdc_hp_uid + 11
#define psys_2600_video_pre_gdc_hp_hw3a_awb_output_uid   psys_2600_video_pre_gdc_hp_uid + 12
#define psys_2600_video_pre_gdc_hp_hw3a_af_output_uid    psys_2600_video_pre_gdc_hp_uid + 13
#define psys_2600_video_pre_gdc_hp_fw3a_rgby_uid         psys_2600_video_pre_gdc_hp_uid + 14
#define psys_2600_video_pre_gdc_hp_fw3a_rgbs_uid         psys_2600_video_pre_gdc_hp_uid + 15
#define psys_2600_video_pre_gdc_hp_fw3a_ydrc_uid         psys_2600_video_pre_gdc_hp_uid + 16
#define psys_2600_video_pre_gdc_hp_drc_mapin_uid         psys_2600_video_pre_gdc_hp_uid + 17

#define psys_2600_video_post_gdc_hp_pg_id                1003
#define psys_2600_video_post_gdc_hp_uid                  psys_2600_pg_uid(psys_2600_video_post_gdc_hp_pg_id)
#define psys_2600_video_post_gdc_hp_param_uid            psys_2600_video_post_gdc_hp_uid + 1
#define psys_2600_video_post_gdc_hp_program_uid          psys_2600_video_post_gdc_hp_uid + 2
#define psys_2600_video_post_gdc_hp_input_uid            psys_2600_video_post_gdc_hp_uid + 3
#define psys_2600_video_post_gdc_hp_spatial_param_uid    psys_2600_video_post_gdc_hp_uid + 4
#define psys_2600_video_post_gdc_hp_output_uid           psys_2600_video_post_gdc_hp_uid + 5
#define psys_2600_video_post_gdc_hp_secondary_output_uid psys_2600_video_post_gdc_hp_uid + 6
#define psys_2600_video_post_gdc_hp_third_output_uid     psys_2600_video_post_gdc_hp_uid + 7
#define psys_2600_video_post_gdc_hp_tnr_input_uid        psys_2600_video_post_gdc_hp_uid + 8
#define psys_2600_video_post_gdc_hp_tnr_sim_input_uid    psys_2600_video_post_gdc_hp_uid + 9
#define psys_2600_video_post_gdc_hp_tnr_output_uid       psys_2600_video_post_gdc_hp_uid + 10
#define psys_2600_video_post_gdc_hp_tnr_sim_output_uid   psys_2600_video_post_gdc_hp_uid + 11

#define psys_2600_video_hdr_pre_proc_pg_id                1005
#define psys_2600_video_hdr_pre_proc_uid                  psys_2600_pg_uid(psys_2600_video_hdr_pre_proc_pg_id)
#define psys_2600_video_hdr_pre_proc_param_uid            psys_2600_video_hdr_pre_proc_uid + 1
#define psys_2600_video_hdr_pre_proc_program_uid          psys_2600_video_hdr_pre_proc_uid + 2
#define psys_2600_video_hdr_pre_proc_input_uid            psys_2600_video_hdr_pre_proc_uid + 3
#define psys_2600_video_hdr_pre_proc_output_uid           psys_2600_video_hdr_pre_proc_uid + 4
#define psys_2600_video_hdr_pre_proc_secondary_output_uid psys_2600_video_hdr_pre_proc_uid + 5
#define psys_2600_video_hdr_pre_proc_ae_output_uid        psys_2600_video_hdr_pre_proc_uid + 6
#define psys_2600_video_hdr_pre_proc_blc_type0_input_uid  psys_2600_video_hdr_pre_proc_uid + 7
#define psys_2600_video_hdr_pre_proc_blc_type1_input_uid  psys_2600_video_hdr_pre_proc_uid + 8
#define psys_2600_video_hdr_pre_proc_blc_type2_input_uid  psys_2600_video_hdr_pre_proc_uid + 9
#define psys_2600_video_hdr_pre_proc_lsc_type0_input_uid  psys_2600_video_hdr_pre_proc_uid + 10
#define psys_2600_video_hdr_pre_proc_lsc_type1_input_uid  psys_2600_video_hdr_pre_proc_uid + 11
#define psys_2600_video_hdr_pre_proc_lsc_type2_input_uid  psys_2600_video_hdr_pre_proc_uid + 12
#define psys_2600_video_hdr_pre_proc_hw3a_awb_output_uid  psys_2600_video_hdr_pre_proc_uid + 13
#define psys_2600_video_hdr_pre_proc_hw3a_af_output_uid   psys_2600_video_hdr_pre_proc_uid + 14
#define psys_2600_video_hdr_pre_proc_fw3a_rgby_uid        psys_2600_video_hdr_pre_proc_uid + 15
#define psys_2600_video_hdr_pre_proc_fw3a_rgbs_uid        psys_2600_video_hdr_pre_proc_uid + 16
#define psys_2600_video_hdr_pre_proc_fw3a_ydrc_uid        psys_2600_video_hdr_pre_proc_uid + 17
#define psys_2600_video_hdr_pre_proc_drc_mapin_uid        psys_2600_video_hdr_pre_proc_uid + 18

#define psys_2600_video_pre_gdc_hq_ns_pg_id                1007
#define psys_2600_video_pre_gdc_hq_ns_uid                  psys_2600_pg_uid(psys_2600_video_pre_gdc_hq_ns_pg_id)
#define psys_2600_video_pre_gdc_hq_ns_param_uid            psys_2600_video_pre_gdc_hq_ns_uid + 1
#define psys_2600_video_pre_gdc_hq_ns_program_uid          psys_2600_video_pre_gdc_hq_ns_uid + 2
#define psys_2600_video_pre_gdc_hq_ns_input_uid            psys_2600_video_pre_gdc_hq_ns_uid + 3
#define psys_2600_video_pre_gdc_hq_ns_output_uid           psys_2600_video_pre_gdc_hq_ns_uid + 4
#define psys_2600_video_pre_gdc_hq_ns_noise_output_uid     psys_2600_video_pre_gdc_hq_ns_uid + 5
#define psys_2600_video_pre_gdc_hq_ns_dvs_in_l0_uid        psys_2600_video_pre_gdc_hq_ns_uid + 6
#define psys_2600_video_pre_gdc_hq_ns_dvs_in_l1_uid        psys_2600_video_pre_gdc_hq_ns_uid + 7
#define psys_2600_video_pre_gdc_hq_ns_dvs_in_l2_uid        psys_2600_video_pre_gdc_hq_ns_uid + 8
#define psys_2600_video_pre_gdc_hq_ns_dvs_out_l0_uid       psys_2600_video_pre_gdc_hq_ns_uid + 9
#define psys_2600_video_pre_gdc_hq_ns_dvs_out_l1_uid       psys_2600_video_pre_gdc_hq_ns_uid + 10
#define psys_2600_video_pre_gdc_hq_ns_dvs_out_l2_uid       psys_2600_video_pre_gdc_hq_ns_uid + 11

#define psys_2600_video_post_gdc_hq_ns_pg_id                1008
#define psys_2600_video_post_gdc_hq_ns_uid                  psys_2600_pg_uid(psys_2600_video_post_gdc_hq_ns_pg_id)
#define psys_2600_video_post_gdc_hq_ns_param_uid            psys_2600_video_post_gdc_hq_ns_uid + 1
#define psys_2600_video_post_gdc_hq_ns_program_uid          psys_2600_video_post_gdc_hq_ns_uid + 2
#define psys_2600_video_post_gdc_hq_ns_input_uid            psys_2600_video_post_gdc_hq_ns_uid + 3
#define psys_2600_video_post_gdc_hq_ns_spatial_param_uid    psys_2600_video_post_gdc_hq_ns_uid + 4
#define psys_2600_video_post_gdc_hq_ns_output_uid           psys_2600_video_post_gdc_hq_ns_uid + 5
#define psys_2600_video_post_gdc_hq_ns_secondary_output_uid psys_2600_video_post_gdc_hq_ns_uid + 6
#define psys_2600_video_post_gdc_hq_ns_third_output_uid     psys_2600_video_post_gdc_hq_ns_uid + 7
#define psys_2600_video_post_gdc_hq_ns_tnr_input_uid        psys_2600_video_post_gdc_hq_ns_uid + 8
#define psys_2600_video_post_gdc_hq_ns_tnr_output_uid       psys_2600_video_post_gdc_hq_ns_uid + 9
#define psys_2600_video_post_gdc_hq_ns_tnr_sim_input_uid    psys_2600_video_post_gdc_hq_ns_uid + 10
#define psys_2600_video_post_gdc_hq_ns_tnr_sim_output_uid   psys_2600_video_post_gdc_hq_ns_uid + 11
#define psys_2600_video_post_gdc_hq_ns_input_ns_uid         psys_2600_video_post_gdc_hq_ns_uid + 12

#define psys_2600_video_post_gdc_hq_4k_pg_id                1011
#define psys_2600_video_post_gdc_hq_4k_uid                  psys_2600_pg_uid(psys_2600_video_post_gdc_hq_4k_pg_id)
#define psys_2600_video_post_gdc_hq_4k_param_uid            psys_2600_video_post_gdc_hq_4k_uid + 1
#define psys_2600_video_post_gdc_hq_4k_program_uid          psys_2600_video_post_gdc_hq_4k_uid + 2
#define psys_2600_video_post_gdc_hq_4k_input_uid            psys_2600_video_post_gdc_hq_4k_uid + 3
#define psys_2600_video_post_gdc_hq_4k_spatial_param_uid    psys_2600_video_post_gdc_hq_4k_uid + 4
#define psys_2600_video_post_gdc_hq_4k_output_uid           psys_2600_video_post_gdc_hq_4k_uid + 5
#define psys_2600_video_post_gdc_hq_4k_secondary_output_uid psys_2600_video_post_gdc_hq_4k_uid + 6
#define psys_2600_video_post_gdc_hq_4k_third_output_uid     psys_2600_video_post_gdc_hq_4k_uid + 7
#define psys_2600_video_post_gdc_hq_4k_tnr_input_uid        psys_2600_video_post_gdc_hq_4k_uid + 8
#define psys_2600_video_post_gdc_hq_4k_tnr_output_uid       psys_2600_video_post_gdc_hq_4k_uid + 9
#define psys_2600_video_post_gdc_hq_4k_tnr_sim_input_uid    psys_2600_video_post_gdc_hq_4k_uid + 10
#define psys_2600_video_post_gdc_hq_4k_tnr_sim_output_uid   psys_2600_video_post_gdc_hq_4k_uid + 11
#define psys_2600_video_post_gdc_hq_4k_input_ns_uid         psys_2600_video_post_gdc_hq_4k_uid + 12

#define psys_2600_gaussian_pg_id          123
#define psys_2600_gaussian_uid            psys_2600_pg_uid(psys_2600_gaussian_pg_id)
#define psys_2600_gaussian_param_uid      psys_2600_gaussian_uid + 1
#define psys_2600_gaussian_program_uid    psys_2600_gaussian_uid + 2
#define psys_2600_gaussian_input_uid      psys_2600_gaussian_uid + 3
#define psys_2600_gaussian_output_h_uid   psys_2600_gaussian_uid + 4
#define psys_2600_gaussian_output_v_uid   psys_2600_gaussian_uid + 5

#define psys_2600_video_isa_pre_gdc_hq_4k_pg_id         1012
#define psys_2600_video_isa_pre_gdc_hq_4k_uid           psys_2600_pg_uid(psys_2600_video_isa_pre_gdc_hq_4k_pg_id)

#define psys_2600_video_hdr_pre_gdc_hp_pg_id                 1015
#define psys_2600_video_hdr_pre_gdc_hp_uid                   psys_2600_pg_uid(psys_2600_video_hdr_pre_gdc_hp_pg_id)
#define psys_2600_video_hdr_pre_gdc_hp_isl_input_uid         psys_2600_video_hdr_pre_gdc_hp_uid + 4
#define psys_2600_video_hdr_pre_gdc_hp_isl_output_uid        psys_2600_video_hdr_pre_gdc_hp_uid + 5

#define psys_2600_video_pre_gdc_ll_pg_id                1004
#define psys_2600_video_pre_gdc_ll_uid                  psys_2600_pg_uid(psys_2600_video_pre_gdc_ll_pg_id)
#define psys_2600_video_pre_gdc_ll_param_uid            psys_2600_video_pre_gdc_ll_uid + 1
#define psys_2600_video_pre_gdc_ll_program_uid          psys_2600_video_pre_gdc_ll_uid + 2
#define psys_2600_video_pre_gdc_ll_input_uid            psys_2600_video_pre_gdc_ll_uid + 3
#define psys_2600_video_pre_gdc_ll_output_uid           psys_2600_video_pre_gdc_ll_uid + 4

//NCR mono-ds pg
#define psys_2600_ncr_monods_gdc_pg_id                1150
#define psys_2600_ncr_monods_gdc_uid                  psys_2600_pg_uid(psys_2600_ncr_monods_gdc_pg_id)
#define psys_2600_ncr_monods_gdc_param_uid            psys_2600_ncr_monods_gdc_uid + 1
#define psys_2600_ncr_monods_gdc_program_uid          psys_2600_ncr_monods_gdc_uid + 2
#define psys_2600_ncr_monods_gdc_input_uid            psys_2600_ncr_monods_gdc_uid + 3
#define psys_2600_ncr_monods_gdc_output_uid           psys_2600_ncr_monods_gdc_uid + 4
#define psys_2600_ncr_monods_gdc_output_ds4_uid       psys_2600_ncr_monods_gdc_uid + 5
#define psys_2600_ncr_monods_gdc_output_ds16_uid      psys_2600_ncr_monods_gdc_uid + 6

#define stilltnr_stage_id             103
#define stilltnr_stage_uid            ia_cipf_external_stage_uid(stilltnr_stage_id)
#define tnr_stage_id                  102
#define tnr_stage_uid                 ia_cipf_external_stage_uid(tnr_stage_id)
#define veboxtnr_stage_id             101
#define veboxtnr_stage_uid            ia_cipf_external_stage_uid(veboxtnr_stage_id)

#define dol_stage_id                  104
#define dol_stage_uid                 ia_cipf_external_stage_uid(dol_stage_id)

#define gtm_stage_id                  105
#define gtm_stage_uid                 ia_cipf_external_stage_uid(gtm_stage_id)

#define psys_interleaved_code_uid     ia_fourcc('I','L','C','S')
#define psys_interleaved_code_in_uid  psys_interleaved_code_uid + 1
#define psys_interleaved_code_out_uid psys_interleaved_code_uid + 2

#define psys_command_psys_frequency_uid ia_fourcc('P','S','C','F')
#define psys_command_priority_uid       ia_fourcc('P','S','C','P')
#define psys_command_timeout_ms_uid     ia_fourcc('P','S','C','T')
#define psys_stage_operation_mode_uid   ia_fourcc('P','S','O','P')
#define psys_stage_routing_bitmap_uid   ia_fourcc('R','B','M','0')

#define psys_software_terminal_uid(pg_id)               ia_fourcc('P','S',((pg_id & 0xFF00) >> 8),pg_id)
#define psys_software_terminal_uid_from_stage_uid(uid)  psys_software_terminal_uid(psys_2600_pg_id_from_uid(uid))
#define is_psys_software_terminal_uid(uid)              ((uid & 0xFFFF0000) == psys_software_terminal_uid(0))

#define is_post_gdc_uid(uid)    (uid == psys_2600_post_gdc_uid \
                              || uid == psys_2600_video_post_gdc_uid \
                              || uid == psys_2600_video_post_gdc_v2_uid \
                              || uid == psys_2600_video_post_gdc_mbr_uid \
                              || uid == psys_2600_video_post_gdc_v2_mbr_uid \
                              || uid == psys_2600_video_post_gdc_hq_ns_uid \
                              || uid == psys_2600_still_post_gdc_uid \
                              || uid == psys_2600_still_post_gdc_v2_uid \
                              || uid == psys_2600_still_post_gdc_mbr_uid \
                              || uid == psys_2600_still_post_gdc_v2_mbr_uid \
                              || uid == psys_ipu5_still_post_gdc_v4_uid \
                              || uid == psys_ipu5_video_post_gdc_v4_uid \
                              || uid == psys_ipu5_video_post_gdc_uid \
                              || uid == psys_ipu6_bb_uid \
                              || uid == psys_ipu6_bb_gdc_uid \
                              || uid == psys_ipu5_video_post_gdc_10bit_uid \
                              || uid == psys_ipu5_still_post_gdc_10bit_uid)

#define is_pre_gdc_uid(uid)     (uid == psys_2600_video_pre_gdc_uid \
                              || uid == psys_2600_video_pre_gdc_hq_uid \
                              || uid == psys_2600_video_pre_gdc_hq_vcr2_uid \
                              || uid == psys_2600_video_pre_gdc_ll_uid \
                              || uid == psys_2600_ipu5_video_pre_gdc_uid \
                              || uid == psys_2600_ipu6_lb_video_uid \
                              || uid == psys_ipu6_lb_rbm_uid \
                              || uid == psys_2600_still_pre_gdc_uid \
                              || uid == psys_2600_still_pre_gdc_vcr2_uid \
                              || uid == psys_2600_still_pre_gdc_v3_uid \
                              || uid == psys_2600_ipu5_still_pre_gdc_uid \
                              || uid == psys_2600_ipu5_still_pre_gdc_no_xnr_uid \
                              || uid == psys_2600_ipu5_still_pre_gdc_vpless_uid)

#define is_combined_pg_uid(uid) (uid == psys_2600_video_isa_pre_gdc_uid \
                              || uid == psys_2600_video_isl_pre_gdc_hq_uid \
                              || uid == psys_ipu5_dfm_isa_to_psa_yuv_vmem_uid \
                              || uid == psys_ipu5_isa_lb_uid \
                              || uid == psys_ipu6_isa_lb_uid)

#define is_isl_pg_uid(uid)    (uid == psys_ipu6_isa_rbm_uid \
                            || uid == psys_ipu6s_isa_uid \
                            || uid == psys_fake_ipu6s_isa_uid \
                            || uid == psys_ipu5_dfm_isl_ps_vpless_uid)

#define is_gpu_stage_uid(uid) (uid == burstisp_stage_uid \
                            || uid == tnr_stage_uid \
                            || uid == veboxtnr_stage_uid \
                            || uid == stilltnr_stage_uid)

/* COMMON CSS UIDS */
#define css_program_group_params_uid        ia_fourcc('C','S','S','P')
#define css_frame_descriptor_uid            ia_fourcc('C','S','S','F')
#define css_sc_descriptor_uid               ia_fourcc('C','S','S','C')
#define css_frame_max_resolution_uid        ia_fourcc('C','S','M','A')
#define css_frame_min_resolution_uid        ia_fourcc('C','S','M','I')
#define css_program_group_manifest_uid      ia_fourcc('C','S','S','M')
#define css_process_group_uid               ia_fourcc('C','S','P','G')
#define css_process_group_size_uid          ia_fourcc('C','S','P','S')
#define css_cipr_context_uid                ia_fourcc('C','S','C','C')
#define css_create_ppg_uid                  ia_fourcc('C','S','C','P')
#define css_fragment_max_uid                ia_fourcc('C','S','F','<')
#define css_fragment_min_uid                ia_fourcc('C','S','F','>')
#define css_fragment_uid                    ia_fourcc('C','S','F','S')
#define css_fragment_overlap_uid            ia_fourcc('C','S','F','O')
#define css_fragment_count_uid              ia_fourcc('C','S','F','C')
#define css_terminal_descriptor_uid         ia_fourcc('C','S','S','T')
#define css_kernel_bitmap_uid               ia_fourcc('C','S','S','K')
#define css_dynamic_kernel_bitmap_uid       ia_fourcc('C','S','S','D')
#define css_fragment_grid_desc_uid          ia_fourcc('C','S','F','G')
#define css_frame_grid_param_desc_uid       ia_fourcc('C','S','F','P')
#define css_param_section_desc_uid          ia_fourcc('C','S','P','D')
#define css_frag_param_section_desc_uid     ia_fourcc('C','S','F','D')
#define css_kernel_disable_uid              ia_fourcc('C','S','K','D')
#define css_terminal_link_id_uid            ia_fourcc('C','S','N','K')
#define css_pg_manifest_uid                 ia_fourcc('C','S','M','F')
#define css_terminal_connection_type_uid    ia_fourcc('C','S','C','T')
#define css_terminal_stream2gen_buffer_size_uid    ia_fourcc('C','S','S','B')


/* Encode 8bit vied_nci_resource_id_t into least significant byte of UID */
#define css_vied_nci_kernel_id_uid_mask ia_fourcc(0xFF,0xFF,0xFF,0)
#define css_vied_nci_kernel_id_uid(x)   ia_fourcc('K','I','#', x)

/** PSYS stage operation modes
 *
 * Controllable via psys_stage_operation_mode_uid property
 */
typedef enum _psys_stage_opmode {
    _psys_stage_opmode_na_,         /**< not set, defaults to raw */
    _psys_stage_opmode_raw_,        /**< basic operation */
    _psys_stage_opmode_coupled_,    /**< Couple stage with downstream.
                                         Note: With coupling the IPU commands
                                         of consequent stages can be re-ordered
                                         for optimal scheduling with IPU
                                         parallelism. Delay queues are added
                                         between stages to sustain SDF.
                                        */
    _psys_stage_opmode_coupled_relay_, /**< Relay coupling towards downstream
                                         Note: When more than 2 stages
                                         participate in custom scheduling
                                         discipline. Stages can be used to
                                         relay the command-list (bundle) ahead
                                         to stages in downstream.
                                        */
    _psys_stage_opmode_delay_only_,  /**< Delay outputs by one.
                                         Note: Uses delays with default
                                         scheduling discipline. Used to expose
                                         aligned delay queue semantics as with
                                         coupled mode but without changes to
                                         command queueing.
                                        */
    _psys_stage_opmode_incomplete_  /**< no fragmenting and PG creation */
} psys_stage_opmode_t;

/*** User control utils for PSYS stage ***/

/** Calculate sizeof unidentified PSYS stage property
 *
 * This function is intended for generalizing the calculus of stage property
 * sizes when they need to be identified by user, but PSYS library provides
 * helper utilities for the purpose.
 *
 * Property sizes may dependent on other configuration details of a stage. In
 * such case the order of sequence needs to be derived from PSYS PG
 * specification.
 *
 * Returns 0 when property cannot be identified or size calculus misses input.
 * Note: value 0 cannot be set as size of property payload and hence the
 * property identification loop will fail unless user handles the case.
 *
 * \param[in]   property    property object to identify
 */
uint32_t psys_library_control_sizeof_property(ia_cipf_property_t *property);

/** Preset data of PSYS stage buffer
 *
 * This function is intended to be called when new buffers are allocated and
 * registered for use of PSYS stage.
 *
 * In case of parameter buffers, this function can be expected to take care
 * of setting the defaults when available.
 *
 * Buffer preset function may be dependent on other configuration details of
 * a stage. This function can be expected to fetch the information from the
 * stage that user has configured according to PSYS PG specification as a
 * precondition (e.g terminal formats need to be configured).
 *
 * \param[in,out] buffer    buffer object to preset
 */
css_err_t psys_library_control_preset_buffer(ia_cipf_buffer_t *buffer);

/** Preset parameter terminal buffer section sizes in Windows use case
 *
 * This function is intended to be called during identify loop to handle
 * parameter terminal properties exposed from PSYS stage.
 *
 * This function will set buffer section sizes according to specification
 * from manifest.
 *
 * \param[in,out] terminal    terminal object to preset
 */
css_err_t
psys_library_control_preset_terminal_sections(ia_cipf_terminal_t *terminal);

#endif
