/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2016 - 2020 Intel Corporation.
 * All Rights Reserved.
 *
 * The source code contained or described herein and all documents
 * related to the source code ("Material") are owned by Intel Corporation
 * or licensors. Title to the Material remains with Intel
 * Corporation or its licensors. The Material contains trade
 * secrets and proprietary and confidential information of Intel or its
 * licensors. The Material is protected by worldwide copyright
 * and trade secret laws and treaty provisions. No part of the Material may
 * be used, copied, reproduced, modified, published, uploaded, posted,
 * transmitted, distributed, or disclosed in any way without Intel's prior
 * express written permission.
 *
 * No License under any patent, copyright, trade secret or other intellectual
 * property right is granted to or conferred upon you by disclosure or
 * delivery of the Materials, either expressly, by implication, inducement,
 * estoppel or otherwise. Any license under such intellectual property rights
 * must be express and approved by Intel in writing.
 */

#ifndef __DFM_RESOURCES_H
#define __DFM_RESOURCES_H

#include "dfm_resource_types.h"

#define DFM_CONS_DMA_BAYER_OUTPUT_PORT_NUM_VPLESS	(32) /* For Consumer DMA, FULL port selected */

/**
 * THIS FILE IS FOR INTERMEDIATE STEP FOR PSS.
 * IT CAN BE USED IN FUTURE DEPENDING RESOURCE ALLOCATION DESIGN IN VPLESS PG
 */

/**
 * ------------- STATIC ALLOCATION FOR DFM LB PORTS--------------
 *  Reference: DFM HAS and MAS
 */
/** * * * TYPE 1x1 * * * /
 * 1 Sequence (Begin)
 * 1 Command token (64bits) =>  1 -> 32bits Address, 1 -> 32bits command
 * In memory:
 *           { Address_0,
 *  	       Command_0}
 * This type is at two different places in the address space.
 * Total Number TYPE 1x1 ports pairs 5+1 = 6
 * For TYPE 1x1 empty ports are from 0...4 and 24
 * For TYPE 1x1 full ports are from 32...36 and 56
 * Ref: MAS DFM
 */
/* # # # # #  TYPE 1x1 EMPTY PORTS (Producer ports) # # # # # */
#define DFM_LB_MANY_TO_ONE_CONV_PORT             (3)

/* # # # # #  TYPE 1x1 FULL PORTS (Consumer ports) # # # # # */
#define DFM_PSA_V2S_INPUT_PORT_Y                 (34)
#define DFM_PSA_V2S_INPUT_PORT_U                 (35)
#define DFM_PSA_V2S_INPUT_PORT_V                 (36)
#define DFM_PSA_V2S_INPUT_PORT                    DFM_PSA_V2S_INPUT_PORT_Y

#define DFM_PSA_BAYER_INPUT_PORT_GR               DFM_PSA_V2S_INPUT_PORT_Y
#define DFM_PSA_BAYER_INPUT_PORT_R                DFM_PSA_V2S_INPUT_PORT_U
#define DFM_PSA_BAYER_INPUT_PORT_G                DFM_PSA_V2S_INPUT_PORT_V
#define DFM_PSA_BAYER_INPUT_PORT_GB               (37)

#define DFM_PSA_DMA_OUTPUT_PORT_Y_TOP_DUMMY_LINES    (0)
#define DFM_PSA_DMA_OUTPUT_PORT_U_TOP_DUMMY_LINES    (1)
#define DFM_PSA_DMA_OUTPUT_PORT_V_TOP_DUMMY_LINES    (2)
#define DFM_PSA_YUV_PLANAR_DMA_INPUT_PORT_Y	  (3)
#define DFM_PSA_YUV_PLANAR_DMA_INPUT_PORT_U	  (4)
#define DFM_PSA_YUV_PLANAR_DMA_INPUT_PORT_V	  (5)

#define DFM_PSA_BAYER_DMA_IN_PORT_GR     DFM_PSA_YUV_PLANAR_DMA_INPUT_PORT_Y
#define DFM_PSA_BAYER_DMA_IN_PORT_R      DFM_PSA_YUV_PLANAR_DMA_INPUT_PORT_U
#define DFM_PSA_BAYER_DMA_IN_PORT_G      DFM_PSA_YUV_PLANAR_DMA_INPUT_PORT_V
#define DFM_PSA_BAYER_DMA_IN_PORT_GB     (6)

#define DFM_PSA_S2V_YUV_ISA2PSA_PORT (11)
#define DFM_PSA_V2S_YUV_ISA2PSA_PORT (32)

#define DFM_PROD_DMA_BAYER_INPUT_PORT_NUM         (DFM_PSA_YUV_PLANAR_DMA_INPUT_PORT_Y)
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/** * * * TYPE 2x2 * * * /
 * 2 Sequences (Begin, Middle)
 * 2 Command tokens (64 bits each = 128bits) = 2 -> 32bits Addresses, 2 -> 32bits commands
 *                         OR               = 1 -> 32bits Address, 3 -> 32bits commands
 * In  memory:
 *           { Address_0,
 *             Command_0,
 *             Address_1,
 *             Command_1,}
 * 	OR
 *           { Address_0,
 *             Command_0,
 *             Command_1,
 *             Command_2,}
 *
 * Each sequence will have 2 command tokens.
 * This type is at two different places in the address space.
 * Total Number ports pairs 7+3 = 10.
 * For TYPE 2x2, empty ports are from 17...23 and 25...27.
 * For TYPE 2x2, full ports are from 49...55 and 57...59.
 * Ref: MAS DFM
 */
/* # # # # TYPE 2x2 EMPTY PORTS (Producer ports) # # # # */
#define DFM_LBPS_DMA_GAMMASTAR_GRID_PORT          (10)
#define DFM_PSA_S2V_OUTPUT_PORT_Y                 (13)
#define DFM_PSA_S2V_OUTPUT_PORT_U                 (14)
#define DFM_PSA_S2V_OUTPUT_PORT_V                 (15)

/*  # # # # TYPE 2x2 FULL PORTS (Consumer ports) # # # # */
#define DFM_CONS_DMA_BAYER_INPUT_PORT_NUM         (39)

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/** * * * TYPE 3x1 * * * /
 * 3 Sequences (Begin, Middle, End)
 * 1 Command tokens (64bits) =>  1 -> 32bits Address, 1 -> 32bits command
 * In memory:
 *           { Address_0,
 *  	       Command_0}
 * Each Sequence will have 1 command token.
 * TOTAL TYPE 3x1 port pairs = 2.
 * For TYPE 3x1, empty ports are from 5...6.
 * For TYPE 3x1, full ports are from 37...38.
 * Reference MAS DFM
 */
/* # # # # TYPE 3x1 EMPTY PORTS (Producer ports) # # # # */
/* none */

/* # # # # TYPE 3x1 FULL PORTS (Consumer ports) # # # # */
#define DFM_LBPS_GAMMASTAR_PORT                    (38)

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/** * * * TYPE 3x2 * * * /
 * 3 Sequences (Begin, Middle, End)
 * 2 Command tokens (64 bits each = 128bits) = 2 -> 32bits Addresses, 2 -> 32bits commands
 *                          OR               = 1 -> 32bits Address, 3 -> 32bits commands
 * In  memory:
 *           { Address_0,
 *             Command_0,
 *             Address_1,
 *             Command_1,}
 * 	OR
 *           { Address_0,
 *             Command_0,
 *             Command_1,
 *             Command_2,}
 *
 * Each sequence will have 2 command tokens.
 * TOTAL TYPE 3x2 port pairs = 10.
 * For TYPE 3x2, empty ports are from 7...16.
 * For TYPE 3x2, full ports are from 39...48.
 * Reference MAS DFM
 */
/* # # # # TYPE 3x2 EMPTY PORTS LB (Producer ports) # # # # */
#define DFM_PSA_DVS_STATS_MV_L0_EMPTY_PORT           (7)
#define DFM_PSA_DVS_STATS_MV_L1_EMPTY_PORT           (8)
#define DFM_PSA_DVS_STATS_MV_L2_EMPTY_PORT           (9)

/* # # # # TYPE 3x2 FULL PORTS LB (Consumer ports) # # # # */
#define DFM_PSA_DVS_STATS_MV_L0_FULL_PORT            (39)
#define DFM_PSA_DVS_STATS_MV_L1_FULL_PORT            (40)
#define DFM_PSA_DVS_STATS_MV_L2_FULL_PORT            (41)
#define DFM_PSA_DMA_OUTPUT_PORT_Y                    (42)
#define DFM_PSA_DMA_OUTPUT_PORT_U                    (43)
#define DFM_PSA_DMA_OUTPUT_PORT_V                    (44)
#define DFM_PSA_DMA_OUTPUT_PORT_Y_BOTTOM_DUMMY_LINES (45)
#define DFM_PSA_DMA_OUTPUT_PORT_U_BOTTOM_DUMMY_LINES (46)
#define DFM_PSA_DMA_OUTPUT_PORT_V_BOTTOM_DUMMY_LINES (47)

/***************************************************************************************************************/
/* ################# Block Based DFM Resources #############
 * Only 9 ports are available
 * All ports are of same type 3x2.
 */
/* EMPTY PORTS DFM BB */
#define DFM_GDC_PROC_OUT_0_PORT         (1) /* used only in pg_bb_mbr_gdc_ofs */
#define DFM_GDC_PROC_OUT_1_PORT         (2)
#define DFM_GDC_PROC_OUT_2_PORT         (3)
#define DFM_GDC_REL_OUT_0_PORT          (4) /* used only in pg_bb_mbr_gdc_ofs */
#define DFM_GDC_REL_OUT_1_PORT          (5)
#define DFM_GDC_REL_OUT_2_PORT          (6)

/* FULL PORTS DFM BB */
#define DFM_OFS_INPUT_0_PORT            (32)
#define DFM_OFS_INPUT_1_PORT            (33)
#define DFM_OFS_INPUT_2_PORT            (34)
#define DFM_OFS_INPUT_MULTICAST_PORT    (35)
#define DFM_OFS_REL_IN_0_PORT           (36)
#define DFM_OFS_REL_IN_1_PORT           (37)
#define DFM_OFS_REL_IN_2_PORT           (38)
#define DFM_OFS_REL_IN_GATHER_PORT      (39)

/**
 * ------------- STATIC ALLOCATION FOR DFM ISL PORTS----
 * All ports are of TYPE 3x2
 * Available ports: 0-20, 32-52
 * 3 Sequences (Begin, Middle, End)
 * 2 Command tokens (64 bits each = 128bits) =
 *      2 -> 32bits Addresses, 2 -> 32bits commands
 *      OR
 *      1 > 32bits Address, 3 -> 32bits commands
 *      In  memory:
 *           { Address_0,
 *             Command_0,
 *             Address_1,
 *             Command_1,}
 * 	OR
 *           { Address_0,
 *             Command_0,
 *             Command_1,
 *             Command_2,}
 *
 * Each sequence will have 2 command tokens.
 * Reference MAS DFM
 */

/* Empty ports */
/* IN */
/* Due to HW bug, register read from DFM port 0 doesnt work on FPGA.
 * For buffer chasing, BCPR read modify write support is needed,
 * so port number 4 is used */
#define DFM_ISL_PROD_DMA_BAYER_INPUT_PORT_NUM	(4)
/* OUT ORIG */
#define DFM_ISL_S2V_BAYER_PORT_GR		(0)
#define DFM_ISL_S2V_BAYER_PORT_R		(1)
#define DFM_ISL_S2V_BAYER_PORT_B		(2)
#define DFM_ISL_S2V_BAYER_PORT_GB		(3)
#define DFM_ISL_S2V_BAYER_PORT			(DFM_ISL_S2V_BAYER_PORT_GR)
/* #OUT VIDEO */
#define DFM_ISA_VIDEO_FULL_S2V_OUTPUT_PORT_Y	(0)
#define DFM_ISA_VIDEO_FULL_S2V_OUTPUT_PORT_U	(1)
#define DFM_ISA_VIDEO_FULL_S2V_OUTPUT_PORT_V	(2)
/* OUT SCALED A/B */
#define DFM_ISA_SCALED_A_S2V_OUTPUT_PORT_Y	(8)
#define DFM_ISA_SCALED_A_S2V_OUTPUT_PORT_U	(9)
#define DFM_ISA_SCALED_A_S2V_OUTPUT_PORT_V	(10)
#define DFM_ISA_SCALED_B_S2V_OUTPUT_PORT_Y	(11)
#define DFM_ISA_SCALED_B_S2V_OUTPUT_PORT_U	(12)
#define DFM_ISA_SCALED_B_S2V_OUTPUT_PORT_V	(13)
/* OUT SIS 0/1 */
#define DFM_ISL_PS_SIS_STR2MMIO_OUT_PORT	(14)
#define DFM_ISL_PS_SIS_STR2MMIO_OUT_PORT_B	(15)
/* OUT 3A STATS */
#define DFM_ISA_3A_AF_0_PORT			(16)
#define DFM_ISA_3A_AF_1_PORT			(17)
#define DFM_ISA_3A_AWB_0_PORT			(18)
#define DFM_ISA_3A_AWB_1_PORT			(19)
/* IN LSC SPATIAL */
#define DFM_ISA_DMA_LSC_GRID_PORT		(20)
/* OUT PAF STATS */
#define DFM_ISA_PAF_0_PORT			(5)
#if HAS_FF_DOL_DOL
/* DOL */
#define DFM_ISL_PROD_DMA_BAYER_INPUT_DOL_HIGH_PORT_NUM	 (DFM_ISL_PROD_DMA_BAYER_INPUT_PORT_NUM)
#define DFM_ISL_PROD_DMA_BAYER_INPUT_DOL_SHORT_PORT_NUM	 (6)
#define DFM_ISL_PROD_DMA_BAYER_INPUT_DOL_MEDIUM_PORT_NUM (7)
#endif
/* PAF */
#define DFM_ISL_PROD_DMA_BAYER_INPUT_PAF_PORT_NUM	 (DFM_ISL_PS_SIS_STR2MMIO_OUT_PORT_B)
#define DFM_ISL_PROD_DMA_BAYER_INPUT_PAF_ISA_LB_PORT_NUM	 (DFM_ISA_SCALED_A_S2V_OUTPUT_PORT_Y)
/* OUT IR */
/*IR OUT and DOL short share port as they are MUTEX use cases*/
#define DFM_ISL_PS_IR_STR2MMIO_OUT_PORT		(6)

/* Full ports */
/* IN */
#define DFM_ISL_CONS_DMA_BAYER_INPUT_PORT_NUM	(32)
/* OUT ORIG */
#define DFM_ISL_DMA_BAYER_OUT_PORT_GR		(33)
#define DFM_ISL_DMA_BAYER_OUT_PORT_R		(34)
#define DFM_ISL_DMA_BAYER_OUT_PORT_B		(35)
#define DFM_ISL_DMA_BAYER_OUT_PORT_GB		(36)
#define DFM_ISL_DMA_BAYER_OUT_PORT		(DFM_ISL_DMA_BAYER_OUT_PORT_GR)
/* OUT VIDEO */
#define DFM_ISA_VIDEO_FULL_DMA_OUTPUT_PORT_Y	(33)
#define DFM_ISA_VIDEO_FULL_DMA_OUTPUT_PORT_U	(34)
#define DFM_ISA_VIDEO_FULL_DMA_OUTPUT_PORT_V	(35)
/* OUT SCALED A/B */
#define DFM_ISA_SCALED_A_DMA_OUTPUT_PORT_Y	(40)
#define DFM_ISA_SCALED_A_DMA_OUTPUT_PORT_U	(41)
#define DFM_ISA_SCALED_A_DMA_OUTPUT_PORT_V	(42)
#define DFM_ISA_SCALED_B_DMA_OUTPUT_PORT_Y	(43)
#define DFM_ISA_SCALED_B_DMA_OUTPUT_PORT_U	(44)
#define DFM_ISA_SCALED_B_DMA_OUTPUT_PORT_V	(45)
/* OUT SIS 0/1 */
#define DFM_ISL_PS_SIS_DMA_OUT_PORT		(46)
#define DFM_ISL_PS_SIS_DMA_OUT_PORT_B		(47)
/* OUT 3A STATS */
#define DFM_ISA_DMA_3A_AF_STAT_CH_0_PORT	(48)
#define DFM_ISA_DMA_3A_AF_STAT_CH_1_PORT	(49)
#define DFM_ISA_DMA_3A_AWB_STAT_CH_0_PORT	(50)
#define DFM_ISA_DMA_3A_AWB_STAT_CH_1_PORT	(51)
/* IN LSC SPATIAL */
#define DFM_ISA_LSC_GRID_PORT			(52)
/* OUT PAF STATS */
#define DFM_ISA_DMA_PAF_STAT_CH_0_PORT		(37)
#if HAS_FF_DOL_DOL
/* DOL */
#define DFM_ISL_CONS_DMA_BAYER_INPUT_DOL_HIGH_PORT_NUM	 (DFM_ISL_CONS_DMA_BAYER_INPUT_PORT_NUM)
#define DFM_ISL_CONS_DMA_BAYER_INPUT_DOL_SHORT_PORT_NUM	 (38)
#define DFM_ISL_CONS_DMA_BAYER_INPUT_DOL_MEDIUM_PORT_NUM (39)
#endif
/* PAF */
#define DFM_ISL_CONS_DMA_BAYER_INPUT_PAF_PORT_NUM	 (DFM_ISL_PS_SIS_DMA_OUT_PORT_B)
#define DFM_ISL_CONS_DMA_BAYER_INPUT_PAF_ISA_LB_PORT_NUM	 (DFM_ISA_SCALED_A_DMA_OUTPUT_PORT_Y)
/* OUT IR*/
/*IR OUT and DOL short share port as they are MUTEX use cases*/
#define DFM_ISL_PS_IR_DMA_OUT_PORT		(38)

#endif /* __DFM_RESOURCES_H */
