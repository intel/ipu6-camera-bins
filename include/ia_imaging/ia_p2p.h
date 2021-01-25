/*
 * Copyright 2015-2020 Intel Corporation
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
 * \file ia_p2p.h
 * \brief Declares the public2private converter API interface.
 */

/*! \mainpage
 *
 *  Public2Private (P2P) is a component designed for converting algorithm-related parameters between the ISP algo API and the actual
 *  register layouts what firmware expects in its terminals. In the context of P2P, ISP algo parameters are referred as public data
 *  and the register layouts as private data.
 *
 *  P2P has three main responsibilities:
 *   - Converting public data to private data (encoding parameters)
 *   - Converting private data to public data (decoding statistics)
 *   - Filling the actual terminal descriptors accordingly
 *
 *  \section deps Dependencies
 *
 *  P2P has dependencies to other repositories:
 *   - \b include: contains include files that are common to all AIQ libraries
 *   - \b ia_log: the log library used in all AIQ libraries
 *   - \b ia_pal: contains the public parameter definitions
 *   - \b vied-viedifw-ispfw: P2P uses the CSS functions related to accessing data inside terminals
 *
 *  \section supported_kernels Supported Platforms and Kernels
 *
 *  Supported platforms:
 *   - BXT B0
 *   - CNL A0
 *   - CNL B0
 *   - GLV A0
 *
 *  P2P implementation currently supports the following kernels from ISYS:
 *   - INL
 *   - BLC_GLOBAL
 *   - BLC_SENSOR_TYPE_0
 *   - BLC_SENSOR_TYPE_1
 *   - BLC_SENSOR_TYPE_2
 *   - PCLN
 *   - LSC_SENSOR_TYPE_0
 *   - LSC_SENSOR_TYPE_1
 *   - LSC_SENSOR_TYPE_2
 *   - 3A_STAT_AWB
 *   - 3A_STAT_AF
 *   - 3A_STAT_AE_CCM
 *   - 3A_STAT_AE
 *   - IDS
 *   - 3A_STAT_PAF
 *
 *  P2P implementation currently supports the following kernels from VPREGDC:
 *   - WBA_WBA
 *   - RYNR_VCUD
 *   - RYNR_BNLM
 *   - DEMOSAIC_DEMOSAIC
 *   - ACM_CCM
 *   - ACM_ACM
 *   - GTC_CSC_CDS
 *   - GTC_GTM
 *   - YUV1_IEFD
 *   - YUV1_YDS (defaults)
 *   - YUV1_TCC (defaults)
 *   - DVS_YBIN
 *   - DVS_DVS
 *   - DVS_L0
 *   - DVS_L1
 *   - DVS_L2
 *   - XNR4-MH
 *   - XNR4-M
 *   - XNR4_2_Video
 *
 *  P2P implementation currently supports the following kernels from VPREGDC_HQ_NS:
 *   - WBA_WBA
 *   - RYNR_VCUD
 *   - RYNR_BNLM
 *   - DEMOSAIC_DEMOSAIC
 *   - ACM_CCM
 *   - ACM_ACM
 *   - GTC_CSC_CDS
 *   - GTC_GTM
 *   - YUV1_IEFD
 *   - YUV1_YDS (defaults)
 *   - YUV1_TCC (defaults)
 *   - DVS_YBIN
 *   - DVS_DVS
 *   - DVS_L0
 *   - DVS_L1
 *   - DVS_L2
 *   - EXY
 *   - XNR42_Video
 *
 *  P2P implementation currently supports the following kernels from VPREGDC_HQ_NS_DVS:
 *   - WBA_WBA
 *   - RYNR_VCUD
 *   - RYNR_BNLM
 *   - DEMOSAIC_DEMOSAIC
 *   - ACM_CCM
 *   - ACM_ACM
 *   - GTC_CSC_CDS
 *   - GTC_GTM
 *   - YUV1_IEFD
 *   - YUV1_YDS (defaults)
 *   - YUV1_TCC (defaults)
 *   - DVS_YBIN
 *   - DVS_DVS
 *   - DVS_L0
 *   - DVS_L1
 *   - DVS_L2
 *   - EXY
 *   - XNR42_Video
 *
 *  P2P implementation currently supports the following kernels from VPREGDC_ISL_HQ_4K:
 *   - INL
 *   - BLC_GLOBAL
 *   - BLC_SENSOR_TYPE_0
 *   - BLC_SENSOR_TYPE_1
 *   - BLC_SENSOR_TYPE_2
 *   - PCLN
 *   - LSC_SENSOR_TYPE_0
 *   - LSC_SENSOR_TYPE_1
 *   - LSC_SENSOR_TYPE_2
 *   - 3A_STAT_AWB
 *   - 3A_STAT_AF
 *   - 3A_STAT_AE_CCM
 *   - 3A_STAT_AE
 *   - 3A_STAT_PAF
 *   - WBA_WBA
 *   - RYNR_VCUD
 *   - RYNR_BNLM
 *   - DEMOSAIC_DEMOSAIC
 *   - ACM_CCM
 *   - ACM_ACM
 *   - GTC_CSC_CDS
 *   - GTC_GTM
 *   - YUV1_IEFD
 *   - YUV1_YDS (defaults)
 *   - YUV1_TCC (defaults)
 *   - DVS_YBIN
 *   - DVS_DVS
 *   - DVS_L0
 *   - DVS_L1
 *   - DVS_L2
 *   - XNR42_Video
 *
 *  P2P implementation currently supports the following kernels from VHDR_PREGDC_HP: // TODO: Update list.
 *   - INL
 *   - BLC_GLOBAL
 *   - BLC_SENSOR_TYPE_0
 *   - BLC_SENSOR_TYPE_1
 *   - BLC_SENSOR_TYPE_2
 *   - PCLN
 *   - LSC_V1_0_SENSOR_TYPE_0
 *   - LSC_V1_0_SENSOR_TYPE_1
 *   - LSC_V1_0_SENSOR_TYPE_2
 *   - DPC_1_0_1
 *   - IDS_V2_1
 *   - 3A_STAT_AWB
 *   - 3A_STAT_AF
 *   - 3A_STAT_AE_CCM
 *   - 3A_STAT_AE
 *   - BLC_SENSOR_TYPE_0
 *   - BLC_SENSOR_TYPE_1
 *   - BLC_SENSOR_TYPE_2
 *   - LSC_V1_0_SENSOR_TYPE_0
 *   - LSC_V1_0_SENSOR_TYPE_1
 *   - LSC_V1_0_SENSOR_TYPE_2
 *   - 3A_STAT_AWB
 *   - 3A_STAT_AF
 *   - OUTPUT_CROP
 *   - HDR_STATS
 *   - HDR_STATS_RGBY_OUT
 *   - HDR_STATS_YDRC_OUT
 *   - HDR_STATS_RGBS_OUT
 *
 *  P2P implementation currently supports the following kernels from VPOSTGDC:
 *   - DVS_COORDS
 *   - DVS_CONFIG
 *   - OFS_OF
 *   - OFS_SC0
 *   - OFS_SC1
 *   - OFS_ISP
 *   - TNR5
 *
 *  P2P implementation currently supports the following kernels from VPOSTGDC_HQ_NS:
 *   - DVS_COORDS
 *   - DVS_CONFIG
 *   - OFS_OF
 *   - OFS_SC0
 *   - OFS_SC1
 *   - OFS_ISP
 *   - TNR5_2_1
 *
 *  P2P implementation currently supports the following kernels from VPOSTGDC_HQ_NS_DVS2:
 *   - DVS_COORDS
 *   - DVS_CONFIG
 *   - OFS_OF
 *   - OFS_SC0
 *   - OFS_SC1
 *   - OFS_ISP
 *   - TNR5_2_1
 *
 *  P2P implementation currently supports the following kernels from VPOSTGDC_HQ_NS_DVS3:
 *   - DVS_COORDS
 *   - DVS_CONFIG
 *   - OFS_OF
 *   - OFS_SC0
 *   - OFS_SC1
 *   - OFS_ISP
 *   - TNR5_2_1
 *
 *  P2P implementation currently supports the following kernels from VPOSTGDC_HQ_4K: with DVS2
 *   - DVS_COORDS
 *   - DVS_CONFIG
 *   - OFS_OF
 *   - OFS_SC0
 *   - OFS_SC1
 *   - OFS_ISP
 *   - TNR5_2_2
 *
 *  P2P implementation currently supports the following kernels from YUV_CSC:
 *   - CSC_YUV2RGB
 *
 *  \section init Initialization and deinitialization
 *
 *  P2P must be initialized before its conversion functions can be used. Initialization happens during the camera start-up with ia_p2p_init().
 *  This function returns a handle to the created P2P instance, required by the encoding and decoding functions. When cleaning up, P2P must be
 *  deinitialized with ia_p2p_deinit().
 *
 *  The user has to allocate a cache buffer which is used during encoding and decoding to store parameters which are cached between frames.
 *  The cache buffer is specific to a stream, so each stream must have its own cache buffer. The user takes care of giving the correct cache
 *  buffer to P2P. The size of the cache buffer must be queried with ia_p2p_get_cache_buffer_size().
 *
 *  \section runtime Runtime use
 *
 *  The high-level execution flow during runtime is illustrated in Figure 1. On each frame, P2P expects to get public data from PAL. The user
 *  is responsible for calling pal_run() to produce the public data as a binary data chunk and give this as an input to ia_p2p_parse() which
 *  parses the data to a form that is more easily accessible by the encoding functions. ia_p2p_parse() also requires the pointer to the cache
 *  buffer to use for encoding the cached data. After parsing the public data, the requirements for the terminals and the payload can be queried
 *  from P2P in order to allocate memory for the payload and to create terminals.
 *
 *  \mscfile overview.signalling Figure 1. Using P2P at runtime.
 *
 *  After the terminals have been created, the encoding functions can be used to fill the terminals and their payload with private data.
 *
 *  \subsection runtime_terminal_creation Querying requirements and creating terminals
 *
 *  There are five different terminal types relevant to P2P: three input terminals and two output terminals.
 *
 *  Input terminals:
 *      - <b>Parameter input terminal</b>: contains global kernel parameters
 *      - <b>Program terminal</b>: contains program-specific information, i.e. information related to fragmentation and fragment-specific kernel parameters
 *      - <b>Spatial parameter input terminal</b>: contains spatial kernel parameters, e.g. 2D lookup tables for LSC and GridBLC
 *
 *  Output terminals:
 *      - <b>Parameter output terminal</b>: contains global statistics, e.g. histograms
 *      - <b>Spatial parameter output terminal</b>: contains spatial statistics, e.g. RGBS grid
 *
 *  Parameter input terminal contains global parameters for all kernels, so only one parameter input terminal is required. The order of the sections
 *  in the parameter input terminal usually comes from a FW terminal manifest except for ISYS which does not have a manifest.
 *
 *  Program terminal contains program-specific information, i.e. parameters which are not global but fragment-specific. The user can decide into how many
 *  fragments the full frame is split. Only one program terminal is needed, and it contains fragment-specific parameters for all kernels and for each and every
 *  fragment. The order of the sections in the program terminal is such that first comes all the sections of all kernels for the first fragment (similar to
 *  parameter input terminal) and then for the second fragment and so on.
 *
 *  Spatial parameter input terminals are kernel-specific, so there is one for each kernel which requires spatial input parameters. The spatial parameter
 *  input terminal contains lookup tables e.g. LSC table.
 *
 *  Parameter output terminal contains global statistics, such as the histograms. There is only one parameter output terminal which contains statistics
 *  data for all kernels producing global statistics. Since the image might be fragmented, parameter output terminal contains the statistics for each
 *  fragment individually. The order of the sections is such that first comes the statistics of all kernels for the first fragment, then for the second
 *  fragment and so on.
 *
 *  Spatial parameter output terminal contains spatial statistics, such as the RGBS grid. There is one spatial parameter output terminal for each kernel
 *  which produces spatial statistics and it contains only the data for that specific kernel.
 *
 *  Figure 2 illustrates the process of querying terminal and payload requirements and creating the terminals. The number of sections in the
 *  terminals must be queried from P2P using ia_p2p_get_kernel_terminal_requirements(). Since this function returns the requirements for a single
 *  kernel, the user is responsible for looping it over all kernels and accumulating the results to determine the total number of sections in the
 *  parameter terminal and program terminal.
 *
 *  In order to calculate how much memory should be allocated for the actual payload, ia_p2p_get_kernel_payload_desc() is used. This function returns
 *  the required payload size for a single kernel for each terminal type. The user must accumulate the payload sizes over all kernels to determine the
 *  total amount of memory required for payload.
 *
 *  \mscfile terminal_creation.signalling Figure 2. Querying requirements and creating terminals.
 *
 *  After requirements for the terminals and the payload have been determined, memory should be allocated for the terminals and the payload.
 *  Terminals are created using the functions provided by the firmware. As previously explained, only one parameter input terminal, one parameter
 *  output terminal and one program terminal is needed, whereas there must be one spatial parameter input terminal for each kernel having spatial
 *  input parameters. The same applies to spatial output terminals.
 *
 *  \subsection runtime_encoding Encoding
 *
 *  Figure 3 illustrates the encoding process. P2P expects that the user will keep track of the section index where to write the parameters for each
 *  kernel. For each terminal, encoding is performed kernel by kernel in the order of increasing kernel identifier. The first kernel will write to section 0.
 *  The results of ia_p2p_get_kernel_requirements() define how much to increment the section index counter between loop iterations. E.g., if the first
 *  kernel requires 3 sections, the second kernel will be written to section index 3 and so on. The following pseudo code shows how the loop could look like
 *  for the parameter input terminal in case of ISYS:
 *
 *  \code{.c}
 *  unsigned int cur_section = 0;
 *  unsigned int cur_offset = 0;
 *
 *  for (kernel = 0; kernel < N_IA_CSS_ISYS_KERNEL_ID; ++kernel)
 *  {
 *      ia_p2p_parameter_terminal_encode(ia_p2p, IA_P2P_PG_ISYS, kernel, terminal, cur_section, payload_buffer, cur_offset);
 *
 *      ia_p2p_get_kernel_terminal_requirements(ia_p2p, IA_P2P_PG_ISYS, kernel, &reqs); // These could be cached before the loop.
 *      cur_section += reqs.parameter_section_count;
 *
 *      ia_p2p_get_kernel_payload_desc(ia_p2p, IA_P2P_PG_ISYS, kernel, fragment_count, &desc); // These could be cached before the loop.
 *      cur_offset += desc.parameter_payload_size;
 *  }
 *  \endcode
 *
 *  \mscfile encoding.signalling 3. Encoding process.
 *
 *  Parameter terminal does not have any dependencies, so it can be encoded at any point of execution by looping through all kernel identifiers using
 *  ia_p2p_param_in_terminal_encode(). Same is true for the parameter output terminal which is prepared using ia_p2p_param_out_terminal_prepare() at any time.
 *  Preparation only fills in the payload offsets so that firmware knows where to write the statistics.
 *
 *  Program terminal encoding must be started with ia_p2p_program_terminal_init(). This is executed only once per frame. Then, ia_p2p_program_terminal_encode()
 *  needs to be run for each kernel individually, just as was with ia_p2p_param_in_terminal_encode(). Program terminal encode needs the fragment descriptors,
 *  which define which part of the full frame the fragment contains.
 *
 *  Spatial param terminals are encoded/prepared with ia_p2p_spatial_param_in_terminal_encode() / ia_p2p_spatial_param_out_terminal_prepare(). Each kernel has its
 *  own spatial terminals, so the function is called only once per terminal for each kernel.
 *
 *  \subsection runtime_decoding_stats Decoding statistics
 *
 *  Figure 4 illustrates the decoding process for statistics. Decoding the parameter output terminal should be done with a similar loop as encoding the parameter
 *  input terminal and keeping track of the current section index. ia_p2p_param_out_terminal_decode() is used to decode the global statistics. Spatial statistics are
 *  decoded similarly with ia_p2p_spatial_param_out_terminal_decode() with the exception that every statistics block producing spatial statistics has its own spatial
 *  param output terminal.
 *
 *  \mscfile decoding_stats.signalling 4. Decoding process for statistics.
 *
 *  After all statistics have been decoded, the statistics buffer can be requested from P2P by ia_p2p_serialize_statistics(). The returned ia_binary_data buffer is
 *  owned by P2P and remains valid until ia_p2p_serialize_statistics() is called the next time. The user is responsible of copying the data from the ia_binary_data
 *  structure to another location to preserve it over several frames.
 *
 *  \subsection runtime_decoding_inputs Decoding input parameters (only for debugging purposes)
 *
 *  P2P offers functions for decoding also the input parameters. This is meant only for debugging purposes and should not be used on a real device. Decoding input
 *  parameters has strict requirements for the order of executing the decoding functions. It is mandatory to first decode the parameter terminal with
 *  ia_p2p_param_in_terminal_encode() since the parameter terminal contains the information about which kernels have been enabled. This is needed to determine
 *  how the other terminals are decoded. Before the program terminal can be decoded, the sequencer fragment grid descriptors for a specific kernel must be retrieved
 *  from the spatial parameter input terminal using ia_p2p_spatial_param_in_terminal_decode_grid_descriptors(). After this step, ia_p2p_program_terminal_decode()
 *  can be used to decode program-specific parameters. Finally, ia_p2p_spatial_param_in_terminal_decode() is used to decode the spatial input terminals.
 *
 *  \mscfile decoding.signalling 5. Decoding process for input parameters.
 *
 *  \page integration_guide Integration Guide
 *
 *  This page explains how to integrate P2P for each program group.
 *
 *  The following table summarizes the supported program groups in P2P:
 *
 *  SV = meaning supported for internal System Validation only (not released for driver)
 *
 *  Program Group             | P2P Constant                         | PG ID | Fragmentation Support | BXT B0 | CNL B0 | GLV A0 | IPU6 | IPU6S
 *  ------------------------- | ------------------------------------ | ----- | --------------------- | ------ | ------ | ------ | ---- | ------
 *  ISYS                      | IA_P2P_PG_ISYS                       | 0     | Yes                   | X      | X      | -      | -    | -
 *  ISL PS HIRES              | IA_P2P_PG_ISL_PS_HIRES               | 127   | Yes                   | X      | -      | -      | -    | -
 *  ISL PS INPUT CROP         | IA_P2P_PG_ISL_PS_INPUT_CROP          | 127   | Yes                   | -      | X      | -      | -    | -
 *  ISL PS GLV VPLESS         | IA_P2P_PG_ISL_PS_GLV_VPLESS          | 166   | Yes                   | -      | -      | X      | -    | -
 *  ISA LB GLV VPLESS         | IA_P2P_PG_ISA_LB_GLV_VPLESS          | 194   | Yes                   | -      | -      | X      | -    | -
 *  Video PreGDC HQ           | IA_P2P_PG_VPREGDC_HQ                 | 122   | Yes                   | X      | X      | -      | -    | -
 *  IPU5 Video PreGDC VPless  | IA_P2P_PG_IPU5_VPREGDC_VPLESS        | 167   | Yes                   | -      | -      | X      | -    | -
 *  Still PreGDC              | IA_P2P_PG_SPREGDC                    | 117   | No                    | -      | -      | -      | -    | -
 *  IPU5 Still PreGDC VPless  | IA_P2P_PG_IPU5_SPREGDC_VPLESS        | 168   | Yes                   | -      | -      | X      | -    | -
 *  Still PreGDC XNR          | IA_P2P_PG_SPREGDC_XNR                | 125   | No                    | -      | -      | -      | -    | -
 *  Still PreGDC XNR V2       | IA_P2P_PG_SPREGDC_XNR_V2             | 131   | Yes                   | X      | X      | -      | -    | -
 *  Still PreGDC XNR V3       | IA_P2P_PG_SPREGDC_XNR_V3             | 136   | Yes                   | X      | X      | -      | -    | -
 *  Still PostGDC             | IA_P2P_PG_SPOSTGDC                   | 118   | Yes                   | X      | X      | X      | -    | -
 *  Still PostGDC IN8         | IA_P2P_PG_SPOSTGDC_IN8               | 152   | Yes                   |        |        | X      | -    | -
 *  Still PostGDC V4          | IA_P2P_PG_SPOSTGDC_V4                | 161   | No                    |        |        | SV     | -    | -
 *  Still PostGDC IN8 V4      | IA_P2P_PG_SPOSTGDC_IN8_V4            | 162   | Yes                   | -      | -      | X      | -    | -
 *  Still PostGDC V4 10BIT    | IA_P2P_PG_IPU5_SPOSTGDC_V4_10BIT     | 197   | Yes                   | -      | -      | X      | -    | -
 *  Video PostGDC V1          | IA_P2P_PG_IPU5_VPOSTGDC_V1           | 151   | No                    | -      | -      | X      | -    | -
 *  Video PostGDC V4          | IA_P2P_PG_IPU5_VPOSTGDC_V4           | 169   | No                    | -      | -      | X      | -    | -
 *  Video PostGDC V4 HDR10    | IA_P2P_PG_IPU5_VPOSTGDC_V4           | 193   | No                    | -      | -      | X      | -    | -
 *  Video PostGDC V2          | IA_P2P_PG_VPOSTGDC_V2                | 129   | No                    | X      | X      | -      | -    | -
 *  Video PostGDC V2 MBR      | IA_P2P_PG_VPOSTGDC_V2_MBR            | 172   | No                    | -      | X      | -      | -    | -
 *  Still PostGDC V2 MBR      | IA_P2P_PG_SPOSTGDC_V2_MBR            | 173   | Yes                   | -      | X      | -      | -    | -
 *  Video PostGDC MBR         | IA_P2P_PG_VPOSTGDC_MBR               | 132   | No                    | -      | X      | -      | -    | -
 *  Still PostGDC MBR         | IA_P2P_PG_SPOSTGDC_MBR               | 133   | Yes                   | -      | X      | -      | -    | -
 *  Video PreGDC HQ VCR2      | IA_P2P_PG_VPREGDC_HQ_VCR2            | 148   | Yes                   | -      | X      | -      | -    | -
 *  Video ISL PreGDC HQ VCR2  | IA_P2P_PG_VIDEO_ISL_PREGDC_HQ_VCR2   | 156   | Yes                   | -      | X      | -      | -    | -
 *  Still PreGDC XNR V2 VCR2  | IA_P2P_PG_SPREGDC_XNR_V2_VCR2        | 149   | Yes                   | -      | X      | -      | -    | -
 *  Still PreGDC XNR V3 VCR2  | IA_P2P_PG_SPREGDC_XNR_V3_VCR2        | 150   | Yes                   | -      | X      | -      | -    | -
 *  LB PSA Bypass             | IA_P2P_PG_IPU6_LB_PSA_BYPASS         | 182   | No                    | -      | -      | -      | X    | -
 *  LB PSA                    | IA_P2P_PG_IPU6_LB_PSA                | 183   | No                    | -      | -      | -      | X    | -
 *  ISL RBM                   | IA_P2P_PG_IPU6_ISL_RBM               | 185   | No                    | -      | -      | -      | X    | -
 *  ISA combined LB PG        | IA_P2P_PG_IPU6_ISA_LB                | 187   | No                    | -      | -      | -      | X    | -
 *  ISA PG                    | IA_P2P_PG_IPU6S_ISA                  | 198   | No                    | -      | -      | -      | -    | X
 *  Video PreGDC HQ NS        | IA_P2P_PG_VPREGDC_HQ_NS              | 1000  | Yes                   | X      | -      | -      | -    | -
 *  Video PostGDC HQ NS       | IA_P2P_PG_VPOSTGDC_HQ_NS             | 1001  | Yes                   | X      | -      | -      | -    | -
 *  Video PreGDC HP           | IA_P2P_PG_VPREGDC_HP                 | 1002  | Yes                   | X      | -      | -      | -    | -
 *  Video PostGDC HP          | IA_P2P_PG_VPOSTGDC_HP                | 1003  | Yes                   | X      | -      | -      | -    | -
 *  Video PreGDC LL           | IA_P2P_PG_VPREGDC_LL                 | 1004  | Yes                   | X      | -      | -      | -    | -
 *  VHDR PreProc V2           | IA_P2P_PG_VHDR_PREPROC_V2            | 1005  | Yes                   | X      | -      | -      | -    | -
 *  Video PreGDC HQ NS DVS    | IA_P2P_PG_VPREGDC_HQ_NS_DVS          | 1007  | Yes                   | X      | -      | -      | -    | -
 *  Video PostGDC HQ NS DVS2  | IA_P2P_PG_VPOSTGDC_HQ_NS_DVS2        | 1008  | Yes                   | X      | -      | -      | -    | -
 *  Video PostGDC HQ NS DVS3  | IA_P2P_PG_VPOSTGDC_HQ_NS_DVS3        | 1009  | Yes                   | X      | -      | -      | -    | -
 *  Video PreGDC HP 2FR       | IA_P2P_PG_VPREGDC_HP_2FR             | 1010  | Yes                   | X      | -      | -      | -    | -
 *  Video PostGDC HQ 4K       | IA_P2P_PG_VPOSTGDC_HQ_4K             | 1011  | No                    | X      | -      | -      | -    | -
 *  Video PreGDC ISL HQ 4K    | IA_P2P_PG_VPREGDC_ISL_HQ_4K          | 1012  | Yes                   | X      | -      | -      | -    | -
 *  VHDR PreProc Stats HP     | IA_P2P_PG_VHDR_PREPROC_Stats hp      | 1013  | Yes                   | X      | -      | -      | -    | -
 *  Video PreGDC HP DRC       | IA_P2P_PG_VPREGDC_HP_DRC             | 1014  | Yes                   | X      | -      | -      | -    | -
 *  VHDR PreGDC HP            | IA_P2P_PG_VHDR_PREGDC_HP             | 1015  | Yes                   | X      | -      | -      | -    | -
 *  YUYV SCALE                | IA_P2P_PG_YUYV_SCALE                 | 1051  | No                    | X      | -      | -      | -    | -
 *  YUV_CSC                   | IA_P2P_PG_YUV_CSC                    | 1052  | No                    | X      | -      | -      | -    | -
 *  YUYV_LDC                  | IA_P2P_PG_YUYV_LDC                   | 1053  | No                    | X      | -      | -      | -    | -
 *
 *  \section isys Input System Program Groups
 *
 *  Program groups involved
 *   - ISYS
 *   - ISL PS GLV
 *   - ISL PS HIRES
 *   - ISL PS INPUT CROP
 *
 *  ISYS is the only program group which does not have a terminal manifest to use. This is why all control logic for P2P integration must be done by calling P2P
 *  encode functions in the increasing kernel id order defined in the IA_CSS_ISA_KERNEL_ID enumeration in FW code. This ordering holds true for both param in and
 *  program terminals. Spatial terminals use individual kernel ids and they utilize the same numbering as the param in and program terminal kernel ids.
 *
 *  ISL PS GLV, ISL PS INPUT CROP and ISL PS HIRES program groups are similar to ISYS program group, but they are run on PSYS and are meant for multi-camera setups.
 *  This also means that there is a manifest available. All encoding logic should follow the manifest to achieve correct section order.
 *
 *  One difference compared to the ISYS program group is also that the spatial terminals have different kernel ids than the param in and program terminal. A good
 *  example of this is LSC: param in and program terminals use kernel id 7 for LSC sensor type 1, but the corresponding LSC spatial terminal is using kernel id 28.
 *
 *  Since P2P needs to support both ISYS and ISL PS program groups at the same time, P2P internally uses the common logic and this is why kernel requirements
 *  and payload descriptors should not be calculated for spatial terminal kernel ids (kernel_id >= 24). The required payload is already calculated when calling
 *  ia_p2p_get_kernel_terminal_requirements() and ia_p2p_get_kernel_payload_desc() functions for the non-spatial kernel ids (kernel_id < 24). This is not critical,
 *  since the only downside of calling the functions is that too much memory is allocated, but should anyway be optimized.
 *
 * The following chapters list the required PAL records for each Input System program group.
 *
 *  \subsection ipu5_pre_gdc_pgs IPU5 Input System Program Group PALs
 *

 *  \subsubsection isl_ps_glv_vpless IA_P2P_PG_ISL_PS_GLV_VPLESS (PG id 166)
 *
 *   - ia_pal_uuid_isp_pixelformatter
 *   - ia_pal_uuid_isp_bxt_norm_lin
 *   - ia_pal_uuid_isp_bxt_gridbaseob
 *   - ia_pal_uuid_isp_bxt_linearization
 *   - ia_pal_uuid_isp_bxt_lsc
 *   - ia_pal_uuid_isp_dpc_1_3
 *   - ia_pal_uuid_isp_pafstatistics_1
 *   - ia_pal_uuid_isp_lca_1_0
 *   - ia_pal_uuid_isp_bxt_blc
 *   - ia_pal_uuid_isp_bxt_disparity
 *   - ia_pal_uuid_isp_bxt_applycorrection
 *   - ia_pal_uuid_isp_bxt_awbstatistics
 *   - ia_pal_uuid_isp_bxt_af_awb_fr_statistics
 *   - ia_pal_uuid_isp_bxt_3a_ccm
 *   - ia_pal_uuid_isp_bxt_aestatistics
 *   - ia_pal_uuid_isp_bxt_pixprecadapter_precropstills
 *   - ia_pal_uuid_isp_pxl_crop_bayer_a
 *   - ia_pal_uuid_isp_padder_bayer_a
 *   - ia_pal_uuid_isp_bxt_inputscalerv2
 *   - ia_pal_uuid_isp_bxt_vcsc
 *   - ia_pal_uuid_isp_bxt_pixprecadapter_precropvideo
 *   - ia_pal_uuid_isp_pxl_crop_yuv_a
 *   - ia_pal_uuid_isp_padder_yuv_a
 *   - ia_pal_uuid_isp_crop_sis
 *   - ia_pal_uuid_isp_wb_sis
 *   - ia_pal_uuid_isp_sis_1
 *   - ia_pal_uuid_isp_pixprecadapter_post_sis
 *   - ia_pal_uuid_isp_pxl_crop_sis_a
 *
 *  \subsubsection isl_ps_dfm_lb_glv IA_P2P_PG_ISA_LB_GLV_VPLESS (PG id 194)
 *
 *   - ia_pal_uuid_isp_bxt_pixelformatter
 *   - ia_pal_uuid_isp_bxt_norm_lin
 *   - ia_pal_uuid_isp_bxt_gridbaseob
 *   - ia_pal_uuid_isp_bxt_linearization
 *   - ia_pal_uuid_isp_bxt_lsc
 *   - ia_pal_uuid_isp_dpc_1_3
 *   - ia_pal_uuid_isp_pafstatistics_1
 *   - ia_pal_uuid_isp_lca_1_0
 *   - ia_pal_uuid_isp_bxt_blc
 *   - ia_pal_uuid_isp_bxt_disparity
 *   - ia_pal_uuid_isp_bxt_applycorrection
 *   - ia_pal_uuid_isp_bxt_awbstatistics
 *   - ia_pal_uuid_isp_bxt_af_awb_fr_statistics
 *   - ia_pal_uuid_isp_bxt_3a_ccm
 *   - ia_pal_uuid_isp_bxt_aestatistics
 *   - ia_pal_uuid_isp_bxt_pixprecadapter_precropstills
 *   - ia_pal_uuid_isp_pxl_crop_bayer_a
 *   - ia_pal_uuid_isp_padder_bayer_a
 *   - ia_pal_uuid_isp_bxt_inputscalerv2
 *   - ia_pal_uuid_isp_bxt_vcsc
 *   - ia_pal_uuid_isp_bxt_pixprecadapter_precropvideo
 *   - ia_pal_uuid_isp_pxl_crop_yuv_a
 *   - ia_pal_uuid_isp_padder_yuv_a
 *   - ia_pal_uuid_isp_crop_sis
 *   - ia_pal_uuid_isp_wb_sis
 *   - ia_pal_uuid_isp_sis_1
 *   - ia_pal_uuid_isp_pixprecadapter_post_sis
 *   - ia_pal_uuid_isp_pxl_crop_sis_a
 *   - ia_pal_uuid_isp_bnlm_3_0
 *   - ia_pal_uuid_isp_bxt_wb
 *   - ia_pal_uuid_isp_b2i_dm_1_0
 *   - ia_pal_uuid_isp_bxt_vcsc
 *   - ia_pal_uuid_isp_gltm_1_0
 *   - ia_pal_uuid_isp_xnr_5_1
 *   - ia_pal_uuid_isp_bxt_vcr2
 *   - ia_pal_uuid_isp_bxt_ccm
 *   - ia_pal_uuid_isp_glim_1_0
 *   - ia_pal_uuid_isp_bxt_acm
 *   - ia_pal_uuid_isp_gammastar_1
 *   - ia_pal_uuid_isp_gammatm_v3
 *   - ia_pal_uuid_isp_bxt_csc
 *   - ia_pal_uuid_isp_sc_iefd_v2
 *   - ia_pal_uuid_isp_strm_crop_psa
 *   - ia_pal_uuid_isp_espa_1_0
 *   - ia_pal_uuid_isp_dvsstatistics_2
 *
 *  \section pregdc_pgs Pre-GDC Program Groups
 *
 *  Program groups involved
 *   - Video PreGDC
 *   - Video PreGDC HQ
 *   - Video PreGDC HQ VCR2
 *   - ISL Video PreGDC HQ VCR2
 *   - Still PreGDC
 *   - Still PreGDC XNR
 *   - Still PreGDC XNR V2
 *   - Still PreGDC XNR V3
 *   - Still PreGDC XNR V2 VCR2
 *   - Still PreGDC XNR V3 VCR2
 *   - Video PreGDC HQ NS
 *   - Video PreGDC HQ NS DVS
 *   - Video PreGDC LL
 *   - Video PreGDC HP
 *   - Video PreGDC HP 2FR
 *   - Video ISL PreGDC HQ 4K
 *   - Video HDR PreGDC HP
 *
 *  All PreGDC program groups have a manifest which should be used when calling P2P encoding functionality. Because of the DMA packing feature,
 *  the input and output fragment's "bits per elements" or "bpe" can be freely chosen by the driver. Hence the alignment requirements are different
 *  between input and output fragments. For P2P to configure the output crop parameters, it should to know the fragment descriptor calculation logic
 *  Hence P2P must be used to calculate the fragment descriptors for preGDC and driver would need to call the ia_p2p_calculate_pregdc_fragments()
 *  for that purpose.
 *
 *  Because the input and output alignments can be different, p2p maintains an internal cache about the pixels to be cropped for each fragment.
 *  The driver must call ia_p2p_calculate_pregdc_fragments() with input and output fragment bpe, frame width, fragment count and input and output
 *  fragment descriptors. P2P will use the cached output crop pixel offsets for subsequent configuring of the output crop parameters.
 *
 *  To simplify the fragment descriptor calculations, P2P assumes the maximum number of fragments to be supported as 20.
 *
 * The following chapters list the required PAL records for each Pre-GDC program group.
 *
 *  \subsection ipu5_pre_gdc_pgs IPU5 Pre-GDC Program Group PALs
 *
 *  \subsubsection  vpregdc IA_P2P_PG_IPU5_VPREGDC_VPLESS (PG id 167)
 *
 *   - ia_pal_uuid_isp_bnlm_3_0
 *   - ia_pal_uuid_isp_gltm_1_0
 *   - ia_pal_uuid_isp_xnr_5_1
 *   - ia_pal_uuid_isp_bxt_vcr2
 *   - ia_pal_uuid_isp_bxt_ccm
 *   - ia_pal_uuid_isp_glim_1_0
 *   - ia_pal_uuid_isp_bxt_acm
 *   - ia_pal_uuid_isp_gammastar_1
 *   - ia_pal_uuid_isp_gammatm_v3
 *   - ia_pal_uuid_isp_bxt_csc
 *   - ia_pal_uuid_isp_sc_iefd_v2
 *   - ia_pal_uuid_isp_strm_crop_psa
 *   - ia_pal_uuid_isp_espa_1_0
 *   - ia_pal_uuid_isp_dvsstatistics_2
 *
 *  \subsubsection  spregdc_vpless IA_P2P_PG_IPU5_SPREGDC_VPLESS (PG id 168)
 *
 *   - ia_pal_uuid_isp_bnlm_3_0
 *   - ia_pal_uuid_isp_bxt_wb_stills
 *   - ia_pal_uuid_isp_bxt_demosaic
 *   - ia_pal_uuid_isp_bxt_rynr_splitter
 *   - ia_pal_uuid_isp_bxt_rynr_collector
 *   - ia_pal_uuid_isp_bxt_vcsc_stills
 *   - ia_pal_uuid_isp_gltm_1_0
 *   - ia_pal_uuid_isp_xnr_5_1
 *   - ia_pal_uuid_isp_bxt_vcr2
 *   - ia_pal_uuid_isp_bxt_ccm
 *   - ia_pal_uuid_isp_glim_1_0
 *   - ia_pal_uuid_isp_bxt_acm
 *   - ia_pal_uuid_isp_gammastar_1
 *   - ia_pal_uuid_isp_gammatm_v3
 *   - ia_pal_uuid_isp_bxt_csc
 *   - ia_pal_uuid_isp_sc_iefd_v2
 *   - ia_pal_uuid_isp_strm_crop_psa
 *   - ia_pal_uuid_isp_espa_1_0
 *
 *  \subsection ipu4p_pre_gdc_pgs IPU4P Pre-GDC Program Group PALs
 *
 *  \subsubsection  vpregdc_hq_kernels IA_P2P_PG_VPREGDC_HQ (PG id 122)
 *
 *   - ia_pal_uuid_isp_bxt_wb
 *   - ia_pal_uuid_isp_bxt_rynr_splitter
 *   - ia_pal_uuid_isp_bxt_rynr_collector,
 *   - ia_pal_uuid_isp_bxt_ccm,
 *   - ia_pal_uuid_isp_bxt_acm
 *   - ia_pal_uuid_isp_bxt_demosaic
 *   - ia_pal_uuid_isp_bxt_gammatm
 *   - ia_pal_uuid_isp_bxt_csc
 *   - ia_pal_uuid_isp_bxt_csc2
 *   - ia_pal_uuid_isp_bxt_vcud
 *   - ia_pal_uuid_isp_sc_iefd_v2
 *   - ia_pal_uuid_isp_bxt_vcr2
 *   - ia_pal_uuid_isp_bxt_bnlm
 *   - ia_pal_uuid_isp_bxt_xnr4_m
 *   - ia_pal_uuid_isp_bxt_dvsstatistics
 *
 *  \subsubsection  vpregdc_hq_vcr2_kernels IA_P2P_PG_VPREGDC_HQ_VCR2 (PG id 148)
 *
 *   - ia_pal_uuid_isp_bxt_wb
 *   - ia_pal_uuid_isp_bxt_rynr_splitter
 *   - ia_pal_uuid_isp_bxt_rynr_collector,
 *   - ia_pal_uuid_isp_bxt_ccm,
 *   - ia_pal_uuid_isp_bxt_acm
 *   - ia_pal_uuid_isp_bxt_demosaic
 *   - ia_pal_uuid_isp_bxt_gammatm
 *   - ia_pal_uuid_isp_bxt_csc
 *   - ia_pal_uuid_isp_bxt_csc2
 *   - ia_pal_uuid_isp_bxt_vcud
 *   - ia_pal_uuid_isp_sc_iefd_v2
 *   - ia_pal_uuid_isp_bxt_vcr2
 *   - ia_pal_uuid_isp_bxt_bnlm
 *   - ia_pal_uuid_isp_bxt_xnr4_m
 *   - ia_pal_uuid_isp_bxt_dvsstatistics
 *
 *  \subsubsection  video_isl_pregdc_hq_vcr2_kernels IA_P2P_PG_VIDEO_ISL_PREGDC_HQ_VCR2 (PG id 156)
 *
 *   - ia_pal_uuid_isp_bxt_norm_lin
 *   - ia_pal_uuid_isp_bxt_blc
 *   - ia_pal_uuid_isp_bxt_gridbaseob
 *   - ia_pal_uuid_isp_bxt_linearization
 *   - ia_pal_uuid_isp_bxt_lsc
 *   - ia_pal_uuid_isp_bxt_applycorrection
 *   - ia_pal_uuid_isp_bxt_disparity
 *   - ia_pal_uuid_isp_dpc_1_1
 *   - ia_pal_uuid_isp_bxt_awbstatistics
 *   - ia_pal_uuid_isp_bxt_af_awb_fr_statistics
 *   - ia_pal_uuid_isp_bxt_3a_ccm
 *   - ia_pal_uuid_isp_bxt_aestatistics
 *   - ia_pal_uuid_isp_bxt_wb
 *   - ia_pal_uuid_isp_bxt_rynr_splitter
 *   - ia_pal_uuid_isp_bxt_rynr_collector
 *   - ia_pal_uuid_isp_bxt_ccm
 *   - ia_pal_uuid_isp_bxt_acm
 *   - ia_pal_uuid_isp_bxt_demosaic
 *   - ia_pal_uuid_isp_bxt_gammatm
 *   - ia_pal_uuid_isp_bxt_csc
 *   - ia_pal_uuid_isp_bxt_csc2
 *   - ia_pal_uuid_isp_sc_iefd_v2
 *   - ia_pal_uuid_isp_bxt_bnlm
 *   - ia_pal_uuid_isp_bxt_xnr4_mh
 *   - ia_pal_uuid_isp_bxt_dvsstatistics
 *
 *  \subsubsection  spregdc_xnr_v2_kernels IA_P2P_PG_SPREGDC_XNR_V2 (PG id 131)
 *   - ia_pal_uuid_isp_bxt_wb
 *   - ia_pal_uuid_isp_bxt_rynr_splitter
 *   - ia_pal_uuid_isp_bxt_rynr_collector
 *   - ia_pal_uuid_isp_bxt_ccm
 *   - ia_pal_uuid_isp_bxt_acm
 *   - ia_pal_uuid_isp_bxt_demosaic
 *   - ia_pal_uuid_isp_bxt_gammatm
 *   - ia_pal_uuid_isp_bxt_csc
 *   - ia_pal_uuid_isp_bxt_csc2
 *   - ia_pal_uuid_isp_sc_iefd_v2
 *   - ia_pal_uuid_isp_bxt_vcr2
 *   - ia_pal_uuid_isp_bxt_bnlm
 *   - ia_pal_uuid_isp_bxt_xnr4_mh
 *   - ia_pal_uuid_isp_bxt_dvsstatistics
 *
 *  \subsubsection  spregdc_xnr_v2_kernels IA_P2P_PG_SPREGDC_XNR_V2_VCR2 (PG id 149)
 *
 *   - ia_pal_uuid_isp_bxt_wb
 *   - ia_pal_uuid_isp_bxt_rynr_splitter
 *   - ia_pal_uuid_isp_bxt_rynr_collector
 *   - ia_pal_uuid_isp_bxt_ccm
 *   - ia_pal_uuid_isp_bxt_acm
 *   - ia_pal_uuid_isp_bxt_demosaic
 *   - ia_pal_uuid_isp_bxt_gammatm
 *   - ia_pal_uuid_isp_bxt_csc
 *   - ia_pal_uuid_isp_bxt_csc2
 *   - ia_pal_uuid_isp_sc_iefd_v2
 *   - ia_pal_uuid_isp_bxt_vcr2
 *   - ia_pal_uuid_isp_bxt_bnlm
 *   - ia_pal_uuid_isp_bxt_xnr4_mh
 *   - ia_pal_uuid_isp_bxt_dvsstatistics
 *
 *  \subsubsection  vpregdc_hq_ns_dvs_kernels IA_P2P_PG_VPREGDC_HQ_NS_DVS (PG id 1007)
 *
 *   - ia_pal_uuid_isp_bxt_wb
 *   - ia_pal_uuid_isp_bxt_rynr_splitter
 *   - ia_pal_uuid_isp_bxt_rynr_collector
 *   - ia_pal_uuid_isp_bxt_bnlm
 *   - ia_pal_uuid_isp_bxt_vcud
 *   - ia_pal_uuid_isp_bxt_demosaic
 *   - ia_pal_uuid_isp_bxt_ccm
 *   - ia_pal_uuid_isp_bxt_acm
 *   - ia_pal_uuid_isp_bxt_csc
 *   - ia_pal_uuid_isp_bxt_gammatm
 *   - ia_pal_uuid_isp_sc_iefd
 *   - ia_pal_uuid_isp_exy
 *   - ia_pal_uuid_isp_bxt_csc2
 *   - ia_pal_uuid_isp_bxt_xnr_dss
 *   - ia_pal_uuid_isp_exy
 *   - ia_pal_uuid_isp_bxt_dvsstatistics
 *
 *  \section postgdc_pgs Post-GDC Program Groups
 *
 *  Program groups involved
 *   - Video PostGDC
 *   - Video PostGDC V2
 *   - Video PostGDC V2 MBR
 *   - Still PostGDC
 *   - Still PostGDC V2
 *   - Still PostGDC V2 MBR
 *   - Video PostGDC MBR
 *   - Still PostGDC MBR
 *   - Video PostGDC HQ NS
 *   - Video PostGDC HQ NS DVS2
 *   - Video PostGDC HQ NS DVS3
 *   - Video PostGDC HQ 4K
 *   - Video PostGDC HP
 *   - YUYV Scale
 *   - YUYV LDC
 *
 *  Both PostGDC program groups have a manifest which should be used when calling P2P encoding functionality. The driver should call ia_p2p_calculate_postgdc_fragments()
 *  to calculate proper fragmentation for PostGDC. This function can be used even when there is no fragmentation, i.e. the fragment count is 1. This way the integration
 *  can be done in the same way for both unfragmented and fragmented use cases.
 *
 *  The function ia_p2p_calculate_postgdc_fragments() calculates multiple fragment descriptors. Some of this data needs to be used when configuring the data terminals.
 *  The following table describes how to configure each data terminal in the program group:
 *
 *  Terminal                     | Fragment Descriptors
 *  ---------------------------- | ---------------------------------------------------------------------------------------------------------------
 *  Data input terminal          | Configure always to full frame
 *  Data output terminal (pin 0) | Use output_pixel_fragment_descs_display_pin descriptors calculated by ia_p2p_calculate_postgdc_fragments()
 *  Data output terminal (pin 1) | Use output_pixel_fragment_descs_main_pin descriptors calculated by ia_p2p_calculate_postgdc_fragments()
 *  Data output terminal (pin 2) | Use output_pixel_fragment_descs_postprocess_pin descriptors calculated by ia_p2p_calculate_postgdc_fragments()
 *
 *  The input_pixel_fragment_descs descriptors returned by ia_p2p_calculate_postgdc_fragments() must be given as input to the P2P encoding functions.
 *
 * The following chapters list the required PAL records for each Post-GDC program group.
 *
 *  \subsection ipu5_post_gdc_pgs IPU5 Post-GDC Program Group PALs
 *
 *  \subsubsection vpostgdc IA_P2P_PG_IPU5_VPOSTGDC_V4 (PG ID 169)
 *
 *   - ia_pal_uuid_isp_gdc4_2
 *   - ia_pal_uuid_isp_ofa_1
 *   - ia_pal_uuid_isp_dma_cropper_mp
 *   - ia_pal_uuid_isp_sc_outputscaler_dp
 *   - ia_pal_uuid_isp_dma_cropper_dp
 *   - ia_pal_uuid_isp_sc_outputscaler_ppp
 *   - ia_pal_uuid_isp_dma_cropper_ppp
 *   - ia_pal_uuid_isp_tnr5_3
 *
 *  \subsubsection vpostgdc IA_P2P_PG_IPU5_VPOSTGDC_V4_10BIT (PG ID 193)
 *
 *   - ia_pal_uuid_isp_gdc4_2
 *   - ia_pal_uuid_isp_ofa_1
 *   - ia_pal_uuid_isp_dma_cropper_mp
 *   - ia_pal_uuid_isp_sc_outputscaler_dp
 *   - ia_pal_uuid_isp_dma_cropper_dp
 *   - ia_pal_uuid_isp_sc_outputscaler_ppp
 *   - ia_pal_uuid_isp_dma_cropper_ppp
 *   - ia_pal_uuid_isp_tnr5_3_1
 *
 *  \subsubsection spostgdc_v4 IA_P2P_PG_SPOSTGDC_V4 (PG id 161)
 *
 *   - ia_pal_uuid_isp_gdc4_2
 *   - ia_pal_uuid_isp_ofa_1
 *   - ia_pal_uuid_isp_dma_cropper_mp
 *   - ia_pal_uuid_isp_sc_outputscaler_dp
 *   - ia_pal_uuid_isp_dma_cropper_dp
 *   - ia_pal_uuid_isp_sc_outputscaler_ppp
 *   - ia_pal_uuid_isp_dma_cropper_ppp
 *
 *  \subsubsection spostgdc_in8_v4 IA_P2P_PG_SPOSTGDC_IN8_V4 (PG id 162)
 *
 *   - ia_pal_uuid_isp_gdc4_2
 *   - ia_pal_uuid_isp_ofa_1
 *   - ia_pal_uuid_isp_dma_cropper_mp
 *   - ia_pal_uuid_isp_sc_outputscaler_dp
 *   - ia_pal_uuid_isp_dma_cropper_dp
 *   - ia_pal_uuid_isp_sc_outputscaler_ppp
 *   - ia_pal_uuid_isp_dma_cropper_ppp
 *
 *  \subsubsection spostgdc_v4_10bit IA_P2P_PG_IPU5_SPOSTGDC_V4_10BIT (PG id 197)
 *
 *   - ia_pal_uuid_isp_gdc4_2
 *   - ia_pal_uuid_isp_ofa_1
 *
 *  \subsection ipu4p_post_gdc_pgs IPU4P Post-GDC Program Group PALs
 *
 *  \subsubsection vpostgdc_dvs2 IA_P2P_PG_VPOSTGDC_HQ_NS_DVS2 (PG id 1008)
 *
 *   - ia_pal_uuid_isp_gdc3_1
 *   - ia_pal_uuid_isp_ofa_1
 *   - ia_pal_uuid_isp_sc_outputscaler_ppp
 *   - ia_pal_uuid_isp_sc_outputscaler_dp
 *   - ia_pal_uuid_isp_dma_cropper_ppp
 *   - ia_pal_uuid_isp_dma_cropper_mp
 *   - ia_pal_uuid_isp_dma_cropper_dp
 *   - ia_pal_uuid_isp_tnr5_21
 *
 *  \subsubsection vpostgdc_dvs3 IA_P2P_PG_VPOSTGDC_HQ_NS_DVS3 (PG id 1009)
 *
 *   - ia_pal_uuid_isp_gdc3_1
 *   - ia_pal_uuid_isp_ofa_1
 *   - ia_pal_uuid_isp_sc_outputscaler_ppp
 *   - ia_pal_uuid_isp_sc_outputscaler_dp
 *   - ia_pal_uuid_isp_dma_cropper_ppp
 *   - ia_pal_uuid_isp_dma_cropper_mp
 *   - ia_pal_uuid_isp_dma_cropper_dp
 *   - ia_pal_uuid_isp_tnr5_21
 *
 *  \subsubsection vpostgdc_4K IA_P2P_PG_VPOSTGDC_HQ_4K (PG id 1011)
 *
 *   - ia_pal_uuid_isp_gdc3_1
 *   - ia_pal_uuid_isp_ofa_1
 *   - ia_pal_uuid_isp_sc_outputscaler_ppp
 *   - ia_pal_uuid_isp_sc_outputscaler_dp
 *   - ia_pal_uuid_isp_dma_cropper_ppp
 *   - ia_pal_uuid_isp_dma_cropper_mp
 *   - ia_pal_uuid_isp_dma_cropper_dp
 *   - ia_pal_uuid_isp_tnr5_22
 *
 *  \subsubsection vpostgdc IA_P2P_PG_VPOSTGDC_V2_MBR (PG id 172)
 *
 *   - ia_pal_uuid_isp_gdc3_1
 *   - ia_pal_uuid_isp_ofa_1
 *   - ia_pal_uuid_isp_sc_outputscaler_ppp
 *   - ia_pal_uuid_isp_sc_outputscaler_dp
 *   - ia_pal_uuid_isp_dma_cropper_ppp
 *   - ia_pal_uuid_isp_dma_cropper_mp
 *   - ia_pal_uuid_isp_dma_cropper_dp
 *   - ia_pal_uuid_isp_bxt_tnr5v1
 *
 *  \subsection IPU6 PGs
 *
 *  \subsubsection LB PSA Bypass PG IA_P2P_PG_IPU6_LB_PSA_BYPASS (PG id 182)
 *
 *   - ia_pal_uuid_isp_bnlm_3_0
 *   - ia_pal_uuid_isp_bxt_ccm
 *   - ia_pal_uuid_isp_bxt_acm
 *   - ia_pal_uuid_isp_bxt_vcr2
 *   - ia_pal_uuid_isp_gammastar_1
 *   - ia_pal_uuid_isp_bxt_csc
 *   - ia_pal_uuid_isp_gammatm_v3
 *   - ia_pal_uuid_isp_yuv_splitter
 *   - ia_pal_uuid_isp_sc_iefd_v2
 *   - ia_pal_uuid_isp_gltm_1_0
 *   - ia_pal_uuid_isp_xnr_5_1
 *   - ia_pal_uuid_isp_espa_1_0
 *   - ia_pal_uuid_isp_xnr_5_1
 *   - ia_pal_uuid_isp_espa_1_0
 *   - ia_pal_uuid_isp_glim_1_0
 *
 *  \subsubsection LB PSA Bypass PG IA_P2P_PG_IPU6_LB (PG id 183)
 *
 *   - ia_pal_uuid_isp_bnlm_3_0
 *   - ia_pal_uuid_isp_bxt_demosaic
 *   - ia_pal_uuid_isp_bxt_vcsc
 *   - ia_pal_uuid_isp_bxt_ccm
 *   - ia_pal_uuid_isp_bxt_acm
 *   - ia_pal_uuid_isp_bxt_vcr2
 *   - ia_pal_uuid_isp_gammastar_1
 *   - ia_pal_uuid_isp_bxt_csc
 *   - ia_pal_uuid_isp_gammatm_v3
 *   - ia_pal_uuid_isp_yuv_splitter
 *   - ia_pal_uuid_isp_sc_iefd_v2
 *   - ia_pal_uuid_isp_gltm_1_0
 *   - ia_pal_uuid_isp_xnr_5_1
 *   - ia_pal_uuid_isp_espa_1_0
 *   - ia_pal_uuid_isp_xnr_5_1
 *   - ia_pal_uuid_isp_espa_1_0
 *   - ia_pal_uuid_isp_glim_1_0
 *
 *  \subsubsection LB ISA RBM PG IA_P2P_PG_IPU6_ISL_RBM (PG id 185)
 *
 *   - ia_pal_uuid_isp_bxt_pixelformatter
 *   - ia_pal_uuid_isp_bxt_norm_lin
 *   - ia_pal_uuid_isp_bxt_blc
 *   - ia_pal_uuid_isp_bxt_gridbaseob
 *   - ia_pal_uuid_isp_linearization2_0
 *   - ia_pal_uuid_isp_lsc_1_1
 *   - ia_pal_uuid_isp_dpc_2_0
 *   - ia_pal_uuid_isp_bxt_disparity
 *   - ia_pal_uuid_isp_bxt_applycorrection
 *   - ia_pal_uuid_isp_af_awb_frstatistics_2_0
 *   - ia_pal_uuid_isp_awbstatistics_2_0
 *   - ia_pal_uuid_isp_ccm_3a_2_0
 *   - ia_pal_uuid_isp_aestatistics_2_0
 *   - ia_pal_uuid_isp_bxt_wb
 *   - ia_pal_uuid_isp_lca_1_0
 *   - ia_pal_uuid_isp_strm_crop_sis_a
 *   - ia_pal_uuid_isp_sis_1_0_a
 *   - ia_pal_uuid_isp_espa_sis_a
 *   - ia_pal_uuid_isp_pxl_crop_sis_a
 *   - ia_pal_uuid_isp_strm_crop_sis_b
 *   - ia_pal_uuid_isp_sis_1_0_b
 *   - ia_pal_uuid_isp_espa_sis_b
 *   - ia_pal_uuid_isp_pxl_crop_sis_b
 *   - ia_pal_uuid_isp_espa_bayer_a
 *   - ia_pal_uuid_isp_padder_bayer_a
 *   - ia_pal_uuid_isp_pxl_crop_bayer_a
 *   - ia_pal_uuid_isp_b2i_bnr_1_0
 *   - ia_pal_uuid_isp_b2i_dm_1_0
 *   - ia_pal_uuid_isp_b2i_sie_1_0
 *   - ia_pal_uuid_isp_b2i_ds_1_0_0
 *   - ia_pal_uuid_isp_espa_yuv_a
 *   - ia_pal_uuid_isp_padder_yuv_a
 *   - ia_pal_uuid_isp_pxl_crop_yuv_a
 *   - ia_pal_uuid_isp_b2i_ds_1_0_1
 *   - ia_pal_uuid_isp_espa_yuv_b
 *   - ia_pal_uuid_isp_padder_yuv_b
 *   - ia_pal_uuid_isp_pxl_crop_yuv_b
 *   - ia_pal_uuid_isp_espa_yuv_c
 *   - ia_pal_uuid_isp_padder_yuv_c
 *   - ia_pal_uuid_isp_pxl_crop_yuv_c
 *
 *  \subsubsection IPU6 combined ISA PG IA_P2P_PG_IPU6_ISA_LB (PG id 187)
 *   - ia_pal_uuid_espa_isa_sis_a
 *   - ia_pal_uuid_espa_isa_sis_b
 *   - ia_pal_uuid_ycbcrcombine
 *   - ia_pal_uuid_pxl_crop_sis_a
 *   - ia_pal_uuid_linearization2_0
 *   - ia_pal_uuid_pxl_crop_sis_b
 *   - ia_pal_uuid_pixelformatter
 *   - ia_pal_uuid_dpc_2_0
 *   - ia_pal_uuid_packer_isa_yuv_b
 *   - ia_pal_uuid_bxt_acm
 *   - ia_pal_uuid_espa_isa_bayer_a
 *   - ia_pal_uuid_awbstatistics_2_0
 *   - ia_pal_uuid_pxl_crop_yuv_c
 *   - ia_pal_uuid_strm_crop_psa_c
 *   - ia_pal_uuid_strm_crop_psa_d
 *   - ia_pal_uuid_strm_crop_psa_e
 *   - ia_pal_uuid_strm_crop_psa_f
 *   - ia_pal_uuid_pxl_crop_yuv_b
 *   - ia_pal_uuid_strm_crop_psa_h
 *   - ia_pal_uuid_b2i_dm_1_0
 *   - ia_pal_uuid_pxl_crop_yuv_a
 *   - ia_pal_uuid_sve_1_0
 *   - ia_pal_uuid_espa_isa_yuv_c
 *   - ia_pal_uuid_espa_isa_yuv_b
 *   - ia_pal_uuid_espa_isa_yuv_a
 *   - ia_pal_uuid_linearization2_0_c
 *   - ia_pal_uuid_linearization2_0_b
 *   - ia_pal_uuid_bxt_vcsc_stills
 *   - ia_pal_uuid_sis_1_0_b
 *   - ia_pal_uuid_lsc_1_1
 *   - ia_pal_uuid_espa_psa_e
 *   - ia_pal_uuid_sis_1_0_a
 *   - ia_pal_uuid_espa_psa_c
 *   - ia_pal_uuid_pix_crop_ir_md
 *   - ia_pal_uuid_espa_psa_h
 *   - ia_pal_uuid_bxt_vcr2
 *   - ia_pal_uuid_bxt_gridbaseob
 *   - ia_pal_uuid_xnr_5_2
 *   - ia_pal_uuid_bxt_norm_lin_c
 *   - ia_pal_uuid_bxt_blc_b
 *   - ia_pal_uuid_bxt_csc
 *   - ia_pal_uuid_padder_yuv_a
 *   - ia_pal_uuid_padder_yuv_b
 *   - ia_pal_uuid_padder_yuv_c
 *   - ia_pal_uuid_ccm_3a_2_0
 *   - ia_pal_uuid_bxt_blc_c
 *   - ia_pal_uuid_espa_psa_4
 *   - ia_pal_uuid_x2i_md_1_0
 *   - ia_pal_uuid_espa_psa_1
 *   - ia_pal_uuid_b2i_sie_1_0
 *   - ia_pal_uuid_bxt_applycorrection
 *   - ia_pal_uuid_packer_isa_yuv_c
 *   - ia_pal_uuid_padder_bayer_a
 *   - ia_pal_uuid_packer_isa_yuv_a
 *   - ia_pal_uuid_pxl_crop_bayer_a
 *   - ia_pal_uuid_dvsstatistics_2
 *   - ia_pal_uuid_sc_iefd_v2
 *   - ia_pal_uuid_packer_isa_bayer_a
 *   - ia_pal_uuid_b2i_bnr_1_0
 *   - ia_pal_uuid_af_awb_frstatistics_2_0
 *   - ia_pal_uuid_rgb_ir_2_0
 *   - ia_pal_uuid_glim_1_0
 *   - ia_pal_uuid_strm_crop_sis_b
 *   - ia_pal_uuid_strm_crop_sis_a
 *   - ia_pal_uuid_espa_isa_wb
 *   - ia_pal_uuid_bxt_blc
 *   - ia_pal_uuid_bxt_gridbaseob_b
 *   - ia_pal_uuid_bxt_gridbaseob_c
 *   - ia_pal_uuid_espa_psa_f
 *   - ia_pal_uuid_bxt_norm_lin
 *   - ia_pal_uuid_bxt_norm_lin_b
 *   - ia_pal_uuid_gltm_1_0
 *   - ia_pal_uuid_pixelformatter_c
 *   - ia_pal_uuid_pixelformatter_b
 *   - ia_pal_uuid_bxt_ccm
 *   - ia_pal_uuid_vertical_padding_1_0
 *   - ia_pal_uuid_b2i_ds_1_0_1
 *   - ia_pal_uuid_b2i_ds_1_0_0
 *   - ia_pal_uuid_espa_psa_d
 *   - ia_pal_uuid_pafstatistics_1
 *   - ia_pal_uuid_strm_crop_psa_g
 *   - ia_pal_uuid_bxt_demosaic
 *   - ia_pal_uuid_lca_1_0
 *   - ia_pal_uuid_bxt_disparity
 *   - ia_pal_uuid_gammastar_1
 *   - ia_pal_uuid_espa_psa_g
 *   - ia_pal_uuid_dol_1_0
 *   - ia_pal_uuid_aestatistics_2_0
 *   - ia_pal_uuid_espa_isa_ir_md
 *   - ia_pal_uuid_gammatm_v3
 *   - ia_pal_uuid_bnlm_3_0
 *   - ia_pal_uuid_bxt_wb
 *
 *  \page debugging Debugging
 *
 *  This page explains how P2P can be debugged. There are three ways to debug P2P operation.
 *
 *  \section simulator P2P simulator
 *
 *  P2P simulator (also known as PG dump utility), which originally was done for FW validation purposes, is a test case which can be used to run whole P2P encoding cycle
 *  for a program group based on a PAL output binary. The simulator takes the PAL output binary as an input and produces terminal payload dumps as an output. By attaching
 *  a debugger, the whole P2P encoding can be debugged. This is useful for checking if the input parameters valid and encoded correctly. Since the P2P simulator can only
 *  run encoding, it is not suitable for debugging statistics related issues.
 *
 *  All test case files needed by the P2P simulator can be found under <i>validation</i> folder. File <i>dumpgen.test</i> is the main test case file for running the dump
 *  generation. In addition to the generator, the simulator needs to know which program group to run (defined by a .pg file) and what kind of fragmentation scheme to run
 *  (defined by a .frag file). The simulator produces two files for each terminal: terminal descriptor and terminal payload. There can be directly used by FW for validation
 *  purposes.
 *
 *  The generic syntax of running the P2P simulator is as follows:
 *
 *  \code
 *  bin/testframework -D Validate=<boolean> -D OutputDir=<string> -D FrameWidth=<int> -D FrameHeight=<int> -D FragmentCount=<int> -D PalDataFile=<string> <Frag_file> <Pg_file> validation/dumpgen.test GenerateDump
 *  \endcode
 *
 *  Parameters:
 *  - <b>Validate</b>: Defines whether PAL output binary values will be validated or not. Possible values:
 *      - <i>true</i>: P2P validates all PAL output binary values and stops if there is even a single invalid value. No P2P dumps are produced in case that the validation fails.
 *      - <i>false</i>: Validation is skipped and the P2P dumps are produced always. If there is invalid values, it might lead to a crash in the worst case.
 *  - <b>OutputDir</b>: Specifies the folder where the P2P dumps are written.
 *  - <b>FrameWidth</b>: Defines the full input frame width. Only needed when using single.frag for fragmentation.
 *  - <b>FrameHeight</b>: Defines the full input frame height. Only needed when using single.frag for fragmentation.
 *  - <b>FragmentCount</b>: Defines the number of fragments to use. Only needed when using postgdc_auto.frag for fragmentation.
 *  - <b>PalDataFile</b>: Specifies the location of the PAL output binary to use as the input.
 *  - <b>Frag_file</b>: The file which defines the fragmentation scheme (.frag file). Currently, there are two possible schemes:
 *      - <i>validation/single.frag</i>: Runs a single fragment which covers the full frame. Uses FrameWidth and FrameHeight parameters.
 *      - <i>validation/postgdc_auto.frag</i>: Runs automatic fragmentation calculation for postgdc. Uses FragmentCount parameter to define into how many fragments the full frame is split.
 *      - <i>validation/auto.fraq</i>: Runs automatic fragment calculation for all program groups. THIS SHOULD BE USED in all PGs for IPU5.5.
 *  - <b>Pg_file</b>: The file which defines which program group to run (.pg file).
 *  - <b>ShowVersion</b>: Displays simulator version in output log. The version number is generated for pre-compiled binaries.
 *
 *  Example use for vpregdc using one fragment and resolution 2048x1536:
 *  \code
 *  bin/testframework -D Validate=true -D OutputDir=p2p_output -D FrameWidth=2048 -D FrameHeight=1536 -D PalDataFile=PAL.bin validation/single.frag validation/vpregdc.pg validation/dumpgen.test GenerateDump
 *  \endcode
 *
 *  Example use for spostgdc using automatic fragmentation:
 *  \code
 *  bin/testframework -D Validate=true -D OutputDir=p2p_output -D FragmentCount=2 -D PalDataFile=PAL.bin validation/postgdc_auto.frag validation/spostgdc.pg validation/dumpgen.test GenerateDump
 *  \endcode
 *
 *  Example use for querying version number:
 *  \code
 *  bin/testframework validation/dumpgen.test ShowVersion
 *  \endcode
 *
 *  \section p2pdecoder P2P decoder
 *
 *  P2P decoder can be used to interpret P2P outputs received from FW or driver teams. The decoder supports both pgdump and parambins formats. PG dump is a file which
 *  contains the P2P output as a single text file. Parambins, on the other hand, is a collection of binary files which define the terminal descriptor and payload for each
 *  terminal.
 *
 *  P2P decoder interprets the P2P output and prints all found parameters into the log output. In a sense, it is doing the P2P simulation to the other direction (from
 *  private to public). This can be used to check what kind of configuration parameters were sent to the FW. Also, if the pgdump is created after running the program
 *  group, the decoder can be used for inspecting statistics issues.
 *
 *  The version number is the same for P2P simulator and decoder. However, it is possible to query the version by running decoder.test with the same option as the simulator.
 *
 *  \subsection decode_from_pgdump Decoding From Pgdump
 *
 *  The syntax of running the decoder using a pgdump as input is as follows:
 *
 *  \code
 *  bin/testframework -D PGDumpFile=<string> <Pg_file> validation/decoder.test DecodePGDump
 *  \endcode
 *
 *  Parameters:
 *  - <b>PGDumpFile</b>: Specifies the location of the PG dump file to use as the input.
 *  - <b>Pg_file</b>: The file which defines for which program group the dump was made (.pg file).
 *
 *  Example use for spostgdc:
 *  \code
 *  bin/testframework -D PGDumpFile=pgdump.txt validation/spostgdc.pg validation/decoder.test DecodePGDump
 *  \endcode
 *
 *  \subsection decode_from_parambins Decoding From Parambins
 *
 *  The syntax of running the decoder using parambins as input is as follows:
 *
 *  \code
 *  bin/testframework -D ParamBinsFolder=<string> <Pg_file> validation/decoder.test DecodeParamBins
 *  \endcode
 *
 *  Parameters:
 *  - <b>ParamBinsFolder</b>: Specifies the folder which contains the parambins for all terminals to use as the input.
 *  - <b>Pg_file</b>: The file which defines for which program group the dump was made (.pg file).
 *
 *  Example use for spostgdc:
 *  \code
 *  bin/testframework -D ParamBinsFolder=p2p_output validation/spostgdc.pg validation/decoder.test DecodeParamBins
 *  \endcode
 *
 *  \section filedebug P2P File Debug
 *
 *  P2P contains similar file debug functionality as the other libraries (AIQ and IA_ISP). By enabling the file debug feature in the builds by defining the pre-compiler flag
 *  INPUT_IN_FILE, P2P will store all function calls to ia_p2p_usecase.bin files, which allows reproducing the exact same execution than what was run in real hardware.
 *
 *  Unlike the file debug in other libraries, P2P file debug cannot be run independently. Both IA_ISP_BXT and P2P file debug dumps are required in order to run the full
 *  simulation. This means that INPUTS_IN_FILE needs to be enabled in both ia_p2p and ia_isp_bxt libraries. The HAL/driver also instantiates multiple instances of P2P to
 *  be able to run encoding for different frames concurrently. This means that it is not enough to copy only one of the P2P file debug dumps. For full file debug simulation,
 *  all P2P file debug dumps produced from the same system startup are required.
 *
 *  \subsection filedebug_windows Capturing P2P File Debug Dumps on Windows
 *
 *  On Windows, P2P file debug dumps are produced in folder <i>C:\\Windows\\system32\\drivers</i>. Windows version of P2P is run in kernel mode which means that P2P is initialized
 *  already during system startup and uninitialized only when the system is shut down. Since the file debug file handles remain open until the uninitialization, the system needs
 *  to be restarted in order to be able to copy the ia_p2p_usecase_xxx.bin files to another location.
 *

 *
 *  \subsection filedebug_testframework Running File Debug in Testframework
 *
 *  Running the simulation is done via ia_isp repository. On Windows side, this happens using the testframework_isp_with_p2p.sln solution file which enables P2P builds in the
 *  same environment and expects to get P2P dumps as input as well as the ia_isp_bxt dump. P2P dumps are read by the file debug test case using a wild card, so it is enough
 *  to copy all P2P file debug dumps to the <i>testdata</i> folder. There is no need to change the file names. The IA_ISP_BXT dump is set up in the same way as when debugging
 *  IA_ISP.
 */

#ifndef IA_P2P_H_
#define IA_P2P_H_

#include "ia_isp_bxt_types.h"
#include "ia_css_terminal_types.h"
#include "ia_css_terminal.h"
#include "ia_css_kernel_bitmap.h"
#include "ia_p2p_types.h"
#include <ia_css_rbm.h>

#ifdef IA_P2P_ENABLE_DEBUG_SUPPORT
#include "ia_p2p_private.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Following definitions are used regardless if the IA_AIC is compiled in or not.
 * Keep this part self-contained until the proper IA_AIC implementation exists for these
 */
#define PAC_P2P_SECTIONS MAX_NUM_SECTIONS_PER_KERNEL //private buffer layout calculated by p2p also for PAC proto
#define PAC_P2P_MAX_FRAGMENTS IA_P2P_MAX_FRAGMENTS

struct ia_pac_fragment_desc_p2p {
        uint16_t fragment_width;    /*!< The width of the fragment. */
        uint16_t fragment_height;   /*!< The height of the fragment. */
        uint16_t fragment_start_x;  /*!< The x offset from the top-left corner of the full image. */
        uint16_t fragment_start_y;  /*!< The y offset from the top-left corner of the full image. */
};

struct ia_aic_section_info
{
    uint32_t param_in_size[PAC_P2P_SECTIONS];
    uint32_t param_sec_count;
    uint32_t program_size[PAC_P2P_SECTIONS];
    uint32_t program_sec_count;
    uint32_t spatial_in_size[PAC_P2P_SECTIONS];
    uint32_t spatial_sec_count;
    uint32_t uuid[MAX_NUM_ASSOCIATED_PALS_PER_DEVICE];
    uint32_t uuid_count;
    uint32_t logical_k_id;
    uint32_t p2p_kernel_id;
    struct ia_pac_fragment_desc_p2p pixel_fragment_descs[PAC_P2P_MAX_FRAGMENTS];
};

/*!
 *  Initializes IA_P2P module for the given platform.
 *
 *  \param [in] platform The platform for which to initialize P2P.
 *
 *  \return The IA_P2P instance handle, or NULL if errors.
 */
ia_p2p_handle ia_p2p_init(ia_p2p_platform_t platform);

/*!
 *  De-initializes IA_P2P module.
 *
 *  \param [in] ia_p2p IA_P2P instance handle.
 */
void ia_p2p_deinit(ia_p2p_handle ia_p2p);

/*!
 *  Returns the required size for the cache buffer.
 *
 *  \param [in] ia_p2p IA_P2P instance handle.
 */
uint32_t ia_p2p_get_cache_buffer_size(ia_p2p_handle ia_p2p);

/*!
 *  Returns the required size for the statistics buffer.
 *
 *  \param [in] ia_p2p IA_P2P instance handle.
 */
int32_t ia_p2p_get_statistics_buffer_size(ia_p2p_handle ia_p2p);

/*!
 *  Set statistics buffer pointer.
 *
 *  \param [in] ia_p2p            IA_P2P instance handle.
 *  \param [in] statistics_buffer A pointer to statistics buffer. The buffer is allocated and managed by the user. The internal buffer will be used if it is NULL.
 */
void ia_p2p_set_statistics_buffer(ia_p2p_handle ia_p2p, void* statistics_buffer);

/*!
 *  Parses the public data ready to be used for encoding.
 *
 *  \param [in] ia_p2p          IA_P2P instance handle.
 *  \param [in] public_data     The public data to parse (from PAL output).
 *  \param [in] cache_buffer    A pointer to the cache buffer. The buffer is allocated and managed by the user (query the required size with ia_p2p_get_cache_buffer_size()).
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 *          ia_err_data, if public_data doesn't contain enough data.
 */
ia_err ia_p2p_parse(
    ia_p2p_handle ia_p2p,
    const ia_binary_data* public_data,
    void* cache_buffer);

/*!
 *  Serializes the statistics to a single binary blob.
 *
 *  \param [in]  ia_p2p     IA_P2P instance handle.
 *  \param [out] statistics The resulting statistics data.
 *  \param [out] included   Flags which indicate what statistics are included in the data.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 *
 *  \remarks The returned data buffer is owned by P2P and is valid as long as any P2P decode functions are not called.
 */
ia_err ia_p2p_serialize_statistics(
    ia_p2p_handle ia_p2p,
    ia_binary_data* statistics,
    ia_p2p_statistics_included_t* included);

/*!
 *  Generates a kernel bitmap for the requested program group.
 *
 *  \param [in] ia_p2p  IA_P2P instance handle.
 *  \param [in] pg_id   The program group id.
 *
 *  \return The kernel bitmap where set bit means that the kernel is an imaging kernel and should be encoded by P2P.
 */
ia_css_kernel_bitmap_t ia_p2p_get_kernel_bitmap(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id);

/*!
*  Generates a kernel bitmap for enabled kernels of the requested program group.
*
*  \param [in] ia_p2p  IA_P2P instance handle.
*  \param [in] pg_id   The program group id.
*
*  \return The kernel bitmap where set bit means that the kernel is enabled and should be encoded by P2P.
*/
ia_css_kernel_bitmap_t ia_p2p_get_kernel_enable_bitmap(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id);

/*!
*  Generates a kernel bitmap for disabled kernels of the requested program group.
*
*  \param [in] ia_p2p  IA_P2P instance handle.
*  \param [in] pg_id   The program group id.
*
*  \return The kernel bitmap where set bit means that the kernel need to be disabled for the PG.
*/
ia_css_kernel_bitmap_t ia_p2p_get_kernel_disable_bitmap(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id);

/*!
 * Check if the kernel bitmaps is empty.
 *
 * \param [in] bitmap Kernel bitmap.
 *
 * \return bitmap == 0.
 */
bool ia_p2p_is_kernel_bitmap_empty(ia_css_kernel_bitmap_t bitmap);

/*!
 *  Calculates proper fragments for ISL.
 *
 *  \param [in]   ia_p2p                                     IA_P2P instance handle.
 *  \param [in]   fragment_count                             The number of fragments.
 *  \param [out]  input_pixel_fragment_descs                 The resulting array of fragment descriptors, one for each fragment.
 *  \param [out]  input_pixel_fragment_descs_display_pin     The resulting array of output fragment descriptors for Bayer (non-scaled) output.
 *  \param [out]  input_pixel_fragment_descs_main_pin        The resulting array of output fragment descriptors for YUV (scaled) output.
 */
ia_err ia_p2p_calculate_isl_fragments(
    ia_p2p_handle ia_p2p,
    unsigned int fragment_count,
    ia_p2p_fragment_desc* input_pixel_fragment_descs,
    ia_p2p_fragment_desc* output_pixel_fragment_descs_bayer,
    ia_p2p_fragment_desc* output_pixel_fragment_descs_yuv);

/*!
 *  Calculates proper fragments for post-GDC.
 *
 *  \param [in]   ia_p2p                                     IA_P2P instance handle.
 *  \param [in]   fragment_count                             The number of fragments.
 *  \param [out]  input_pixel_fragment_descs                 The resulting array of fragment descriptors, one for each fragment.
 *  \param [out]  input_pixel_fragment_descs_display_pin     The resulting array of output fragment descriptors for display pin, one for each fragment.
 *  \param [out]  input_pixel_fragment_descs_main_pin        The resulting array of output fragment descriptors for main pin, one for each fragment.
 *  \param [out]  input_pixel_fragment_descs_postprocess_pin The resulting array of output fragment descriptors for post-process pin, one for each fragment.
 */
ia_err ia_p2p_calculate_postgdc_fragments(
    ia_p2p_handle ia_p2p,
    unsigned int fragment_count,
    ia_p2p_fragment_desc* input_pixel_fragment_descs,
    ia_p2p_fragment_desc* output_pixel_fragment_descs_display_pin,
    ia_p2p_fragment_desc* output_pixel_fragment_descs_main_pin,
    ia_p2p_fragment_desc* output_pixel_fragment_descs_postprocess_pin);

/*!
 *  Calculates proper fragments for pre-GDC.
 *
 *  \param [in]   ia_p2p                                     IA_P2P instance handle.
 *  \param [in]   fragment_count                             The number of fragments.
 *  \param [in]   frame_width                                Frame width
 *  \param [in]   frame_height                               Frame height
 *  \param [in]   input_bpe                                  Input bits per element because of DMA packing
 *  \param [in]   output_bpe                                 Output bits per element because of DMA packing
 *  \param [out]  input_pixel_fragment_descs                 The resulting array of fragment descriptors, one for each fragment.
 *  \param [out]  output_pixel_fragment_descs                The resulting array of fragment descriptors, one for each fragment.
 */
ia_err ia_p2p_calculate_pregdc_fragments(
    ia_p2p_handle ia_p2p,
    unsigned int fragment_count,
    unsigned int frame_width,
    unsigned int frame_height,
    unsigned int input_bpe,
    unsigned int output_bpe,
    ia_p2p_fragment_desc* input_pixel_fragment_descs,
    ia_p2p_fragment_desc* output_pixel_fragment_descs);

/*!
 *  Calculates proper fragments for a program group with pipe graph.
 *
 *  \param [in]   ia_p2p            IA_P2P instance handle.
 *  \param [in]   pg_id             The program group id.
 *  \param [in]   fragment_count    The number of fragments.
 *  \param [in]   pipe              The pipe graph.
 *  \param [in]   fragment_reqs     The constraints to align fragments.
 *  \param [out]  configuration     The resulting fragment configuration.
 */
ia_err ia_p2p_calculate_fragments_pipe(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    unsigned int fragment_count,
    const ia_isp_bxt_pipe_t *pipe,
    ia_p2p_fragment_reqs *fragment_reqs,
    ia_p2p_fragment_configuration_t* configuration);

/*!
 *  Calculates proper fragments for a program group.
 *  DEPRECATED. Use ia_p2p_calculate_fragments_pipe instead.
 *
 *  \param [in]   ia_p2p            IA_P2P instance handle.
 *  \param [in]   pg_id             The program group id.
 *  \param [in]   fragment_count    The number of fragments.
 *  \param [out]  configuration     The resulting fragment configuration.
 */
ia_err ia_p2p_calculate_fragments(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    unsigned int fragment_count,
    ia_p2p_fragment_configuration_t* configuration);

/*!
 *  Calculates proper fragments for a program group with routing bitmap.
 *  DEPRECATED. Use ia_p2p_calculate_fragments_pipe instead.
 *
 *  \param [in]   ia_p2p            IA_P2P instance handle.
 *  \param [in]   pg_id             The program group id.
 *  \param [in]   fragment_count    The number of fragments.
 *  \param [in]   rbm               The routing bitmap.
 *  \param [in]   fragment_reqs     The constraints to align fragments.
 *  \param [out]  configuration     The resulting fragment configuration.
 */
ia_err ia_p2p_calculate_fragments_rbm(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    unsigned int fragment_count,
    const ia_css_rbm_t *rbm,
    ia_p2p_fragment_reqs *fragment_reqs,
    ia_p2p_fragment_configuration_t* configuration);

/*!
 *  Calculates the required number of section descriptors for each terminal type for the given kernel.
 *
 *  \param [in]  ia_p2p                 IA_P2P instance handle.
 *  \param [in]  pg_id                  The program group id.
 *  \param [in]  kernel_id              The program group specific identifier of the kernel whose descriptor to calculate.
 *  \param [out] kernel_requirements    The calculated requirements for each terminal for the given kernel.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 */
ia_err ia_p2p_get_kernel_terminal_requirements(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    uint32_t kernel_id,
    ia_p2p_terminal_requirements_t* kernel_requirements);

/*!
 *  Calculates the total size of payload for each terminal type for the given kernel.
 *
 *  \param [in]  ia_p2p                 IA_P2P instance handle.
 *  \param [in]  pg_id                  The program group id.
 *  \param [in]  kernel_id              The program group specific identifier of the kernel whose payload sizes to calculate.
 *  \param [in]  fragment_count         The number of fragments.
 *  \param [in]  pixel_fragment_descs   An array of fragment descriptors, one for each fragment.
 *  \param [out] kernel_payload_desc    The calculated total payload size for each terminal for the given kernel.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 */
ia_err ia_p2p_get_kernel_payload_desc(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    uint32_t kernel_id,
    unsigned int fragment_count,
    const ia_p2p_fragment_desc* pixel_fragment_descs,
    ia_p2p_payload_desc* kernel_payload_desc);

/*!
 * Interface for IPU7 PAC. Caller needs more information about the sections.
 * IPU7 PAC still borrows some services from P2P.
 *
 * Interface is the same as for ia_p2p_get_kernel_payload_desc but
 * \ param[out] s_info                  Section information
 */
ia_err ia_pac_get_kernel_payload_desc(
        ia_p2p_handle ia_p2p,
        uint32_t pg_id,
        uint32_t kernel_id,
        unsigned int fragment_count,
        const ia_p2p_fragment_desc* pixel_fragment_descs,
        ia_p2p_payload_desc* kernel_payload_desc,
        struct ia_aic_section_info *s_info);


/*!
 *  Encodes data for a single kernel in a parameter terminal.
 *
 *  \param [in]     ia_p2p              IA_P2P instance handle.
 *  \param [in]     pg_id               The program group id.
 *  \param [in]     kernel_id           The program group specific identifier of the kernel to encode.
 *  \param [in,out] terminal            The parameter terminal.
 *  \param [in]     section_index       The index of the first section where the data for this kernel is written to the terminal.
 *  \param [in,out] payload_buffer      A pointer to the beginning of the payload buffer.
 *  \param [in]     payload_buffer_size The total size of the given payload buffer, in bytes.
 *  \param [in]     payload_base_offset The base offset in the payload buffer for this kernel.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 */
ia_err ia_p2p_param_in_terminal_encode(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    uint32_t kernel_id,
    ia_css_param_terminal_t* terminal,
    unsigned int section_index,
    unsigned char* payload_buffer,
    unsigned int payload_buffer_size,
    unsigned int payload_base_offset);

/*!
 *  Initializes the program terminal sequencer with fragment information.
 *
 *  \param [in]     ia_p2p                  IA_P2P instance handle.
 *  \param [in]     pg_id                   The program group id.
 *  \param [in]     fragment_count          The number of fragments.
 *  \param [in]     pixel_fragment_descs    An array of fragment descriptors, one for each fragment.
 *  \param [in,out] terminal                The program terminal.
 */
ia_err ia_p2p_program_terminal_init(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    unsigned int fragment_count,
    const ia_p2p_fragment_desc* pixel_fragment_descs,
    ia_css_program_terminal_t* terminal);

/*!
 *  Initializes the program terminal sequencer with fragment information.
 *
 *  \param [in]     ia_p2p                  IA_P2P instance handle.
 *  \param [in]     pg_id                   The program group id.
 *  \param [in]     configuration           Fragment configuration calculated with ia_p2p_calculate_fragments().
 *  \param [in,out] terminal                The program terminal.
 */
ia_err ia_p2p_program_terminal_init_v2(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    const ia_p2p_fragment_configuration_t* configuration,
    ia_css_program_terminal_t* terminal);

/*!
 *  Encodes data for a single kernel in a program terminal.
 *
 *  \param [in]     ia_p2p                          IA_P2P instance handle.
 *  \param [in]     pg_id                           The program group id.
 *  \param [in]     kernel_id                       The program group specific identifier of the kernel to encode.
 *  \param [in]     fragment_count                  The number of fragments.
 *  \param [in]     pixel_fragment_descs            An array of fragment descriptors, one for each fragment.
 *  \param [in,out] terminal                        The program terminal.
 *  \param [in]     section_index                   The index of the first section where the data for this kernel is written to the terminal.
 *  \param [in]     total_section_count             The total number of sections for one fragment including all kernels.
 *  \param [in,out] payload_buffer                  A pointer to the beginning of the payload buffer.
 *  \param [in]     payload_buffer_size             The total size of the given payload buffer, in bytes.
 *  \param [in]     payload_base_offset             The base offset in the payload buffer for this kernel.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 */
ia_err ia_p2p_program_terminal_encode(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    uint32_t kernel_id,
    unsigned int fragment_count,
    const ia_p2p_fragment_desc* pixel_fragment_descs,
    ia_css_program_terminal_t* terminal,
    unsigned int section_index,
    unsigned int total_section_count,
    unsigned char* payload_buffer,
    unsigned int payload_buffer_size,
    unsigned int payload_base_offset);

/*!
 *  Encodes data for a single kernel in a spatial param input terminal.
 *
 *  \param [in]     ia_p2p                          IA_P2P instance handle.
 *  \param [in]     pg_id                           The program group id.
 *  \param [in]     kernel_id                       The program group specific identifier of the kernel to encode.
 *  \param [in]     fragment_count                  The number of fragments.
 *  \param [in]     pixel_fragment_descs            An array of fragment descriptors, one for each fragment.
 *  \param [in,out] terminal                        The spatial param input terminal.
 *  \param [in]     section_index                   The index of the first section where the data for this kernel is written to the terminal.
 *  \param [in,out] payload_buffer                  A pointer to the beginning of the payload buffer.
 *  \param [in]     payload_buffer_size             The total size of the given payload buffer, in bytes.
 *  \param [in]     payload_base_offset             The base offset in the payload buffer for this kernel.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 */
ia_err ia_p2p_spatial_param_in_terminal_encode(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    uint32_t kernel_id,
    unsigned int fragment_count,
    const ia_p2p_fragment_desc* pixel_fragment_descs,
    ia_css_spatial_param_terminal_t* terminal,
    unsigned int section_index,
    unsigned char* payload_buffer,
    unsigned int payload_buffer_size,
    unsigned int payload_base_offset);

/*!
 *  Encodes data for a single kernel in a spatial param output terminal.
 *
 *  \param [in]     ia_p2p                          IA_P2P instance handle.
 *  \param [in]     pg_id                           The program group id.
 *  \param [in]     kernel_id                       The program group specific identifier of the kernel to encode.
 *  \param [in]     fragment_count                  The number of fragments.
 *  \param [in]     pixel_fragment_descs            An array of fragment descriptors, one for each fragment.
 *  \param [in,out] terminal                        The spatial param output terminal.
 *  \param [in]     section_index                   The index of the first section where the data for this kernel is written to the terminal.
 *  \param [in]     payload_buffer_size             The total size of the given payload buffer, in bytes.
 *  \param [in]     payload_base_offset             The base offset in the payload buffer for this kernel.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 */
ia_err ia_p2p_spatial_param_out_terminal_prepare(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    uint32_t kernel_id,
    unsigned int fragment_count,
    const ia_p2p_fragment_desc* pixel_fragment_descs,
    ia_css_spatial_param_terminal_t* terminal,
    unsigned int section_index,
    unsigned int payload_buffer_size,
    unsigned int payload_base_offset);

/*!
 *  Decodes spatial parameter data for a single kernel from a spatial param output terminal.
 *
 *  \param [in]     ia_p2p              IA_P2P instance handle.
 *  \param [in]     pg_id               The program group id.
 *  \param [in]     kernel_id           The program group specific identifier of the kernel to decode.
 *  \param [in]     terminal            The spatial param output terminal.
 *  \param [in]     section_index       The index of the first section where the data for this kernel is available in the terminal.
 *  \param [in]     payload_buffer      A pointer to the beginning of the payload buffer.
 *  \param [in]     payload_buffer_size The total size of the given payload buffer, in bytes.
 *  \param [in,out] cache_buffer        A pointer to the cache buffer for storing the cached outputs.
 *                                      The buffer is allocated and managed by the user (query the required size with ia_p2p_get_cache_buffer_size()).
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 */
ia_err ia_p2p_spatial_param_out_terminal_decode(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    uint32_t kernel_id,
    ia_css_spatial_param_terminal_t* terminal,
    unsigned int section_index,
    const unsigned char* payload_buffer,
    unsigned int payload_buffer_size,
    void* cache_buffer);

/*!
*  Decodes spatial parameter data for a single kernel from a spatial param output terminal with fragment information.
*
*  \param [in]     ia_p2p               IA_P2P instance handle.
*  \param [in]     pg_id                The program group id.
*  \param [in]     kernel_id            The program group specific identifier of the kernel to decode.
*  \param [in]     fragments_count      To apply offsets to subsequent fragments.
*  \param [in]     pixel_fragment_descs Pixel fragment descriptors that were used when encoding current frame.
*  \param [in]     terminal             The spatial param output terminal.
*  \param [in]     section_index        The index of the first section where the data for this kernel is available in the terminal.
*  \param [in]     payload_buffer       A pointer to the beginning of the payload buffer.
*  \param [in]     payload_buffer_size  The total size of the given payload buffer, in bytes.
*  \param [in,out] cache_buffer         A pointer to the cache buffer for storing the cached outputs.
*                                       The buffer is allocated and managed by the user (query the required size with ia_p2p_get_cache_buffer_size()).
*
*
*  \return ia_err_none, if no errors.
*          ia_err_argument, if the arguments are invalid.
*/
ia_err ia_p2p_spatial_param_out_terminal_decode_v2(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    uint32_t kernel_id,
    unsigned int fragments_count,
    const ia_p2p_fragment_desc* pixel_fragment_descs,
    ia_css_spatial_param_terminal_t* terminal,
    unsigned int section_index,
    const unsigned char* payload_buffer,
    unsigned int payload_buffer_size,
    void* cache_buffer);

/*!
 *  Prepares payload for a single kernel in a parameter output terminal.
 *
 *  \param [in]     ia_p2p              IA_P2P instance handle.
 *  \param [in]     pg_id               The program group id.
 *  \param [in]     kernel_id           The program group specific identifier of the kernel whose descriptors to prepare.
 *  \param [in]     fragment_count      The number of fragments.
 *  \param [in,out] terminal            The param output terminal.
 *  \param [in]     section_index       The index of the first section where the data for this kernel is written to the terminal.
 *  \param [in]     total_section_count The total number of sections for one fragment including all kernels.
 *  \param [in]     payload_buffer_size The total size of the payload buffer, in bytes.
 *  \param [in]     payload_base_offset The base offset in the payload buffer for this kernel.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 */
ia_err ia_p2p_param_out_terminal_prepare(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    uint32_t kernel_id,
    unsigned int fragment_count,
    const ia_p2p_fragment_desc* pixel_fragment_descs,
    ia_css_param_terminal_t* terminal,
    unsigned int section_index,
    unsigned int total_section_count,
    unsigned int payload_buffer_size,
    unsigned int payload_base_offset);

/*!
 *  Decodes param out data for a single kernel in a parameter output terminal.
 *
 *  \param [in]     ia_p2p              IA_P2P instance handle.
 *  \param [in]     pg_id               The program group id.
 *  \param [in]     kernel_id           The program group specific identifier of the kernel to decode.
 *  \param [in]     fragment_count      The number of fragments.
 *  \param [in]     terminal            The param output terminal.
 *  \param [in]     section_index       The index of the first section where the data for this kernel is written to the terminal.
 *  \param [in]     total_section_count The total number of sections for one fragment including all kernels.
 *  \param [in]     payload_buffer_size The total size of the given payload buffer, in bytes.
 *  \param [in]     payload_buffer      A pointer to the beginning of the payload buffer.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 */
ia_err ia_p2p_param_out_terminal_decode(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    uint32_t kernel_id,
    unsigned int fragment_count,
    const ia_css_param_terminal_t* terminal,
    unsigned int section_index,
    unsigned int total_section_count,
    const unsigned char* payload_buffer,
    unsigned int payload_buffer_size);

/*!
 *  Returns the size of kernel user parameters for all the kernels in the given Program Group.
 *  This is used in VP-less environment where some of the parameter calculation is done in P2P
 *  instead of firmware.
 *
 *  \param [in]  ia_p2p                 IA_P2P instance handle.
 *  \param [in]  pg_id                  The program group id.
 *  \param [in]  fragment_count         The number of fragments.
 *  \param [out] user_parameter_size    Size of the kernel user parameters in the given PG.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 */
ia_err ia_p2p_get_kernel_user_parameter_size(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    unsigned int fragment_count,
    unsigned int* user_parameter_size);

/*!
 *  Returns the size of kernel user parameters descriptor and payload size separately for the
 *  parambin generation purpose.
 *
 *  \param [in]  ia_p2p                 IA_P2P instance handle.
 *  \param [in]  pg_id                  The program group id.
 *  \param [in]  fragment_count         The number of fragments.
 *  \param [out] kup_desc_size          Size of the kernel user parameter descriptor for a given PG
 *  \param [out] kup_payload_size       Size of the kernel user parameter payload for a given PG.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 */
ia_err ia_p2p_get_kup_desc_and_payload_size(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    unsigned int fragment_count,
    unsigned int* kup_desc_size,
    unsigned int* kup_payload_size);

/*!
 *  Initializes the Program Group with kernel specific user parameters.
 *  This is used in VP-less environment where some of the parameter calculation is done in P2P
 *  instead of firmware.
 *
 *  \param [in]     ia_p2p                   IA_P2P instance handle.
 *  \param [in]     pg_id                    The program group id.
 *  \param [in]     fragment_count           The number of fragments.
 *  \param [in]     pixel_fragment_descs     An array of fragment descriptors, one for each fragment.
 *  \param [in,out] user_parameters          A pointer to the beginning of user parameters.
 */
ia_err ia_p2p_get_kernel_user_parameters(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    unsigned int fragment_count,
    const ia_p2p_fragment_desc* pixel_fragment_descs,
    unsigned char* user_parameters);

/*!
*  Initializes the Program Group with kernel specific user parameters.
*  This is used in VP-less environment where some of the parameter calculation is done in P2P
*  instead of firmware.
*
*  \param [in]     ia_p2p                   IA_P2P instance handle.
*  \param [in]     pg_id                    The program group id.
*  \param [in]     fragment_count           The number of fragments.
*  \param [in]     frag_configuration       Fragment configuration calculated with ia_p2p_calculate_fragments().
*  \param [in,out] user_parameters          A pointer to the beginning of user parameters.
*/
ia_err ia_p2p_get_kernel_user_parameters_v2(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    unsigned int fragment_count,
    const ia_p2p_fragment_configuration_t* frag_configuration,
    unsigned char* user_parameters);

/*!
 * \brief Get version.
 * Get version from version header.
 *
 * \return                                  Version string.
 */
const char* ia_p2p_get_version(void);

/*!
*  Decodes kernel user parameters for all kernels in the program group.
*  The result is printout of each parameter.
*
*  \param [in]     ia_p2p                   IA_P2P instance handle.
*  \param [in]     pg_id                    The program group id.
*  \param [in]     kup_descriptor           The kernel user parameter payload layout information.
*  \param [in]     payload_buffer           Kernel user parameter binary.
*/
ia_err ia_p2p_decode_kup(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    const unsigned char* kup_descriptor,
    const unsigned char* payload_buffer);


#ifdef IA_P2P_ENABLE_DEBUG_SUPPORT
/*!
 *  Decodes data for a single kernel in a parameter terminal.
 *
 *  \param [in]     ia_p2p              IA_P2P instance handle.
 *  \param [in]     pg_id               The program group id.
 *  \param [in]     kernel_id           The program group specific identifier of the kernel to encode.
 *  \param [in,out] terminal            The parameter terminal.
 *  \param [in]     section_index       The index of the first section where the data for this kernel is available in the terminal.
 *  \param [in,out] payload_buffer      A pointer to the beginning of the payload buffer.
 *  \param [in]     payload_buffer_size The total size of the given payload buffer, in bytes.
 *  \param [out]    public_data_out     A structure for the public data output.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 */
ia_err ia_p2p_param_in_terminal_decode(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    uint32_t kernel_id,
    const ia_css_param_terminal_t* terminal,
    unsigned int section_index,
    const unsigned char* payload_buffer,
    unsigned int payload_buffer_size,
    ia_p2p_public_data_t* public_data_out);

/*!
 *  Encodes data for a single kernel in a program terminal.
 *
 *  \param [in]     ia_p2p                          IA_P2P instance handle.
 *  \param [in]     pg_id                           The program group id.
 *  \param [in]     kernel_id                       The program group specific identifier of the kernel to decode.
 *  \param [in]     fragment_count                  The number of fragments.
 *  \param [in,out] terminal                        The program terminal.
 *  \param [in]     section_index                   The index of the first section where the data for this kernel is available in the terminal.
 *  \param [in]     total_section_count             The total number of sections for one fragment including all kernels.
 *  \param [in]     payload_buffer                  A pointer to the beginning of the payload buffer.
 *  \param [in]     payload_buffer_size             The total size of the given payload buffer, in bytes.
 *  \param [out]    public_data_out                 A structure for the decoded output.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 */
ia_err ia_p2p_program_terminal_decode(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    uint32_t kernel_id,
    unsigned int fragment_count,
    ia_css_program_terminal_t* terminal,
    unsigned int section_index,
    unsigned int total_section_count,
    const unsigned char* payload_buffer,
    unsigned int payload_buffer_size,
    ia_p2p_public_data_t* public_data_out);

/*!
 *  Decodes fragment grid descriptors for a single kernel from a spatial param input terminal.
 *
 *  \param [in]     ia_p2p                          IA_P2P instance handle.
 *  \param [in]     pg_id                           The program group id.
 *  \param [in]     kernel_id                       The program group specific identifier of the kernel to decode.
 *  \param [in]     fragment_count                  The number of fragments.
 *  \param [in]     terminal                        The spatial param input terminal.
 *  \param [in]     public_data_out                 A structure for the decoded output.
 *  \param [out]    sequencer_fragment_descs        The resulting array of fragment grid descriptors.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 */
ia_err ia_p2p_spatial_param_in_terminal_decode_grid_descriptors(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    uint32_t kernel_id,
    unsigned int fragment_count,
    ia_css_spatial_param_terminal_t* terminal,
    ia_p2p_public_data_t* public_data_out,
    ia_css_fragment_grid_desc_t* sequencer_fragment_descs);

/*!
 *  Decodes spatial parameter data for a single kernel from a spatial param input terminal.
 *
 *  \param [in]     ia_p2p                          IA_P2P instance handle.
 *  \param [in]     pg_id                           The program group id.
 *  \param [in]     kernel_id                       The program group specific identifier of the kernel to decode.
 *  \param [in]     terminal                        The spatial param input terminal.
 *  \param [in]     section_index                   The index of the first section where the data for this kernel is available in the terminal.
 *  \param [in]     payload_buffer                  A pointer to the beginning of the payload buffer.
 *  \param [in]     payload_buffer_size             The total size of the given payload buffer, in bytes.
 *  \param [in,out] public_data_out                 A structure for the decoded output.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 */
ia_err ia_p2p_spatial_param_in_terminal_decode(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    uint32_t kernel_id,
    ia_css_spatial_param_terminal_t* terminal,
    unsigned int section_index,
    const unsigned char* payload_buffer,
    unsigned int payload_buffer_size,
    ia_p2p_public_data_t* public_data_out);

/*!
 *  Decodes fragment grid descriptors for a single kernel from a spatial param output terminal.
 *
 *  \param [in]     ia_p2p                          IA_P2P instance handle.
 *  \param [in]     pg_id                           The program group id.
 *  \param [in]     kernel_id                       The program group specific identifier of the kernel to decode.
 *  \param [in]     fragment_count                  The number of fragments.
 *  \param [in]     terminal                        The spatial param output terminal.
 *  \param [in]     public_data_out                 A structure for the decoded output.
 *  \param [out]    sequencer_fragment_descs        The resulting array of fragment grid descriptors.
 *
 *  \return ia_err_none, if no errors.
 *          ia_err_argument, if the arguments are invalid.
 */
ia_err ia_p2p_spatial_param_out_terminal_decode_grid_descriptors(
    ia_p2p_handle ia_p2p,
    uint32_t pg_id,
    uint32_t kernel_id,
    unsigned int fragment_count,
    ia_css_spatial_param_terminal_t* terminal,
    ia_p2p_public_data_t* public_data_out,
    ia_css_fragment_grid_desc_t* sequencer_fragment_descs);

#endif

#ifdef __cplusplus
}
#endif

#endif /* IA_P2P_H_ */
