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

/** \file ia_cipr_psys.h
 *
 * CIPR PSYS Command Queue device header
 *
 * \defgroup ia_cipr_command_queue_device Command Queue Device
 * \ingroup ia_cipr
 * \brief Command Queue Device abstraction module exists only in documentation
 * since there is only PSYS command queue device supported in CIPR.
 * \see ia_cipr_psys.
 *
 * \defgroup ia_cipr_psys Processing System (PSYS)
 * \ingroup ia_cipr_command_queue_device
 * \brief CIPR PSYS implements command queue interface on top of IPU
 * processing system hardware. Interface calls are used to manage compute
 * on IPU in atomic units of execution. Each command includes memory objects
 * dealt opaquely as indexed array of ia_cipr_buffer_t's.
 *
 * CIPR PSYS command queue lies on top of low level scheduler that manages
 * work from multiple queues of concurrent CIPR clients. Semantics of the
 * array and data transmission between compute kernels and CIPR clients is
 * further specified by IPU firmware architecture.
 *
 * \note Current datatypes for the command specification are tentative and
 *       expose naming conventions derived from firmware architecture, namely
 *       program group manifest and parameters. These are specific to
 *       existing IPU4 implementation and subject to change. Conceptually
 *       CIPR command is a bundle of buffers that may consist of both memory
 *       and program objects.
 */

#ifndef _IA_CIPR_PSYS_H_
#define _IA_CIPR_PSYS_H_

#include "ia_tools/css_types.h"
#include <ia_cipr/ia_cipr_memory_device.h>

/**
 * CIPR Device ID definition for PSYS device
 */
#define CIPR_DEVICE_PSYS    (ia_cipr_device_id_t)0xFE

/**
 * CIPR PSYS initialization flags
 * CIPR_PSYS_INIT_FLAG_NONE: normal situation, empty flag
 * CIPR_PSYS_INIT_FLAG_DEBUG: initialize cipr in debug
 * mode. All cipr frame buffers can get a cpu_ptr in
 * debug mode even for HW_ONLY flag buffer
 */
#define CIPR_PSYS_INIT_FLAG_NONE  (0 << 0)
#define CIPR_PSYS_INIT_FLAG_DEBUG (1 << 0)

/**
 * CIPR Memory device flags
 */
#ifndef IA_CIPR_MEMORY_NO_FLUSH
#define IA_CIPR_MEMORY_NO_FLUSH IA_CIPR_MEMORY_DEVICE_FLAG(1)
#endif
/** Memory device flag to indicate that buffer uses versioned API datatype
 * defined in this header.
 * \todo this is used for backward compliance and can be removed once legacy
 *       support is dropped.
 */
#define IA_CIPR_MEMORY_PSYS_API IA_CIPR_MEMORY_DEVICE_FLAG(1<<15)


typedef uint32_t ia_cipr_psys_init_flags_t;

/**
 * \ingroup ia_cipr_psys
 */
typedef struct _psys_context* ia_cipr_psys_context_t;

/**
 * \ingroup ia_cipr_psys
 */
typedef struct _psys_command* ia_cipr_psys_command_t;

/**
 * \ingroup ia_cipr_psys
 */
typedef struct _psys_event* ia_cipr_psys_event_t;

/**
 * Configuration of event object
 *
 * !DEPRECATION WARNING!
 *
 * This API has been ambiguous and has caused technical debt. Only user
 * configuration of event object is the timeout-field. The rest are fields
 * set by the CIPR implementation in ia_cipr_psys_wait_for_event() as
 * operation consuming an event from events queue.
 *
 * Original documentation allows user to specify issue_id to associate a
 * blocking call for a specific command issued. This feature was never
 * utilized in client code, but has been misunderstood in CIPR implementation
 * for Windows - which expects CIPR client to relay association between
 * command and event object.
 *
 * \ingroup ia_cipr_psys
 */
typedef struct ia_cipr_psys_event_config {
    uint32_t type;      /* TODO create enums for this?*/
    uint64_t id; /*!< DEPRECATED */
    uint64_t command_token; /*!< Token of command the event is associated with
                             */
    uint64_t command_issue_id; /*!< Issue id of command the event is associated
                                    with */
    uint64_t buffer_handover_bitmap; /*!< Bitmap of buffer indexes in
                                          associated command of which ownership
                                          is passed back to user with this
                                          event */
    uint32_t error; /*!< Error code in case error occured with associated
                         command */
    int32_t timeout; /*!< How long to wait for event before timing out */
} ia_cipr_psys_event_config_t;

/**
 * Command instructions extension buffer
 *
 * With IPU5 process group has evolved from atomic execution unit into a
 * persistent stream processor. It is no longer covering all information needed
 * as per command transaction unit from host to embedded processor(s). This
 * information needed with persistent process group is also not considered
 * final.
 *
 * Command instructions extension is tentative way to support implementation
 * defined versions of per command transaction unit used. Extension
 * datatypes defined accordingly must use IA_CIPR_MEMORY_PSYS_API flag to
 * indicate that data starts with header defined below. Legacy extension buffer
 * is of datatype ia_css_program_group_param_t and must NOT use the flag.
 *
 * Ideally command types, programs and payload buffers should be enough to
 * specify all transactions and operations between CIPR client and embedded
 * processors as well as memory primitives, special instructions to control
 * low-level scheduler or other attributes of IPU device driver. This approach
 * would mimic OpenCL more closely. However, process group and payload buffers
 * have special purpose specified in IPU firmware architecture. CIPR avoids
 * to overspecify and instead reflects the programmability that exists as
 * direct as possible reflected with the key design princible to keep IPU as
 * general-purpose command based device.
 *
 * \todo device attributes query may be used to determine whether extension
 *       datatype buffer should be migrated to device (mapped to kernel/ipu
 *       address space).
 *
 * \ingroup ia_cipr_psys
 */
typedef enum _cmd_ext {
    psys_command_ext_na,
    psys_command_ext_ppg_0,
    psys_command_ext_ppg_1
} ia_cipr_psys_cmd_ext_version_t;

typedef struct _cmd_ext_header_s {
    uint32_t offset; /*!< sizeof(ia_cipr_psys_cmd_ext_header_t) */
    uint64_t size; /*!< sizeof buffer carrying the header */
    ia_cipr_psys_cmd_ext_version_t version; /*!< one of the valid versions from
                                             *   ia_cipr_psys_cmd_ext_version_t
                                             */
} ia_cipr_psys_cmd_ext_header_t;


/**
 * Persistent process group command extension
 *
 * Complies with _cmd_ext_header_s::version == psys_command_ext_ppg_0
 *
 * \ingroup ia_cipr_psys
 */
typedef struct ia_cipr_process_group_command_s {
    ia_cipr_psys_cmd_ext_header_t header;
    uint8_t frame_counter; /*!< Frame synchronization index */
    uint8_t queue_id;      /*!< Queue index to use as offset from base in
                                process group */
    uint16_t fragment_state; /*!< Fragment of process group to process with
                                  command */
    uint64_t event_req_bitmap; /*!< Partial completion events enable bits per
                                    terminal. Non-zero for plain command
                                    completion, when partial events not
                                    supported */
    uint64_t irq_req_bitmap; /*!< Request interrupt on events enabled by event
                                  request bitmap. */
    uint32_t dynamic_kernel_bitmap[4]; /*!< pass dynamic keb to cipr */
} ia_cipr_process_group_command_t;

/**
*  PPG command type
*
*  Enumeration to specify the different persistent program group commands.
*  Used in the ID field of the command config.
*/
typedef enum _ppg_cmd_type {
    ppg_cmd_start,
    ppg_cmd_enqueue,
    ppg_cmd_stop,
    ppg_cmd_stop_eos
} ia_cipr_ppg_cmd_type_t;

/**
 * User configuration of command object
 *
 * \ingroup ia_cipr_psys
 */
typedef struct ia_cipr_psys_command_config {
    uint64_t id; /*!< PPG command type */
    uint64_t token; /*!< User token (responce events associated) */
    uint64_t issue_id; /*!< Issued command identifier
                            (responce events associated) */
    uint32_t priority; /*!< Queue priority to use when at head */
    uint32_t psys_frequency; /*!< Frequency to apply when interpret */
    uint32_t bufcount; /*!< Number of buffers with command */
    ia_cipr_buffer_t **buffers; /*!< Buffers array */
    ia_cipr_buffer_t *ext_buf; /*!< Command extension buffer */
    ia_cipr_buffer_t *pg_params_buf; /*!< DEPRECATED */
    ia_cipr_buffer_t *pg_manifest_buf; /*!< Copy of program group manifest of
                                            which the process group in command
                                            is assembled */
    ia_cipr_buffer_t *pg; /*!< Process group to execute with command.
                               Note: With persistent protocol, after successful
                                     start command, this reflects a read only
                                     trasaction unit associated with started
                                     process group */
    uint64_t execute_context;    /*!< windows driver uses execute context throughout the execution flow of this command */
} ia_cipr_psys_command_config_t;

#define CIPR_PSYS_CAP_DRIVER_FIELD_LENGTH        20
#define CIPR_PSYS_CAP_DEVMODEL_FIELD_LENGTH      32

/**
 * \ingroup ia_cipr_psys
 */
typedef struct ia_cipr_psys_capability_s {
    uint32_t version;
    uint8_t driver[CIPR_PSYS_CAP_DRIVER_FIELD_LENGTH];
    uint8_t dev_model[CIPR_PSYS_CAP_DEVMODEL_FIELD_LENGTH];
    uint32_t program_group_count;
} ia_cipr_psys_capability_t;

/**
 * Create PSYS context
 *
 * Returns handle to PSYS context that can be used to access
 * ia_cipr_psys interface. Single command queue gets created
 * per each create and following functions are bound to this
 * queue:
 *
 * ia_cipr_psys_queue_command()
 *
 * ia_cipr_psys_wait_for_event()
 *
 * The rest of interface operations are independent from the
 * queue and for example the buffer objects are interchangeable
 * between the contexts of the same process. For memory sharing
 * between processes, per process ia_cipr_buffer_t object needs
 * to be used in combination with shared memory handle.
 *
 * \see ia_cipr_memory
 *
 * \ingroup ia_cipr_psys
 */
ia_cipr_psys_context_t ia_cipr_psys_create_context(ia_cipr_context_t cipr_ctx);

/**
 * Destroy PSYS context
 *
 * \ingroup ia_cipr_psys
 *
 * \param ctx ia_cipr_psys_context_t handle
 */

void ia_cipr_psys_destroy_context(ia_cipr_psys_context_t ctx);

/**
 * Get CIPR Memory device handle
 *
 * Returns ia_cipr_memory_device_t handle that can be used
 * with CIPR Memory interface for memory primitives offered
 * by the device.
 *
 * \ingroup ia_cipr_psys
 *
 * \param ctx ia_cipr_psys_context_t handle
 */
ia_cipr_memory_device_t*
ia_cipr_psys_get_memory_device(ia_cipr_psys_context_t ctx);

/**
 * Get CIPR device capabilities
 *
 * Fills ia_cipr_psys_capability_t with information supported by the
 * device.
 *
 * \todo make this direct query of capability info data, having separate
 *       _config_t does not make sense.
 *
 * \ingroup ia_cipr_psys
 *
 * \param ctx ia_cipr_psys_context_t handle
 * \param[out] capability pointer to ia_cipr_psys_capability_t
 */
css_err_t ia_cipr_psys_get_capabilities(ia_cipr_psys_context_t ctx,
                                       ia_cipr_psys_capability_t *capability);

/**
 * Get Program Group manifest
 *
 * Fills ia_css_program_group_manifest_t for given index.
 * Needs to be used to query size of the manifest first using NULL as manifest
 *
 * \ingroup ia_cipr_psys
 *
 * \param ctx ia_cipr_psys_context_t handle
 * \param[in] index index of the manifest in platform
 * \param[in,out] size_of_manifest pointer to the size of manifest
 *                                 gets filled with correct size in case
 *                                 \manifest is NULL.
 * \param[in,out] manifest pointer to memory to hold the manifest
 */
css_err_t ia_cipr_psys_get_manifest(ia_cipr_psys_context_t ctx,
                                   uint32_t index,
                                   uint32_t *manifest_size,
                                   void *manifest);

/**
 * Queue compute command for PSYS execution
 *
 * Places the command object in queue to be scheduled and executed
 * asynchronously in the PSYS device. Completion of each command issued
 * can be tracked with ia_cipr_psys_wait_for_event() using issue-id's.
 *
 * \todo introduce bitflags to control wakeup events.
 *       wakeup control flag can be used also for bundling commands for
 *       the l-scheduler.
 *
 * \ingroup ia_cipr_psys
 *
 * \param ctx ia_cipr_psys_context_t handle
 * \param[in] cmd ia_cipr_psys_command_t object
 */
css_err_t ia_cipr_psys_queue_command(ia_cipr_psys_context_t ctx,
                                    ia_cipr_psys_command_t cmd);
/**
 * Cancel compute command
 *
 * Cancels the compute command or removes the corresponding command
 * from command queue in case the command didn't reach execution.
 *
 * \note Canceling command that has reached execution introduces
 *       device dependent latencies. Currently not supported.
 *
 * \ingroup ia_cipr_psys
 *
 * \param ctx ia_cipr_psys_context_t handle
 * \param[in] cmd ia_cipr_psys_command_t object
 */
css_err_t ia_cipr_psys_cancel_command(ia_cipr_psys_context_t ctx,
                                     ia_cipr_psys_command_t cmd);
/**
 * Wait for specific command completion
 *
 * Returns after the command specified by ia_cipr_psys_event_t
 * completes or there was an error in execution.
 *
 * \ingroup ia_cipr_psys
 *
 * \param ctx ia_cipr_psys_context_t handle
 * \param[in,out] event ia_cipr_psys_event_t object
 */
css_err_t ia_cipr_psys_wait_for_event(ia_cipr_psys_context_t ctx,
                                     ia_cipr_psys_event_t event);

/**
 * Create PSYS event object
 *
 * Returns ia_cipr_psys_event_t object handle. Object is created based on
 * ia_cipr_psys_event_config_t specification and can be further used with
 * ia_cipr_psys_wait_for_event()
 *
 * \ingroup ia_cipr_psys
 *
 * \param[in] cfg ia_cipr_psys_event_config_t event config specification
 */
ia_cipr_psys_event_t
ia_cipr_psys_create_event(ia_cipr_psys_event_config_t *cfg);

/**
 * Destroy PSYS event object
 *
 * \ingroup ia_cipr_psys
 * \param[in] event event object handle
 */
void ia_cipr_psys_destroy_event(ia_cipr_psys_event_t event);

/**
 * Read event config specification from event object
 *
 * \ingroup ia_cipr_psys
 * \param[in] event event object handle
 * \param[in] cfg ia_cipr_psys_event_config_t
 */
css_err_t
ia_cipr_psys_get_event_config(ia_cipr_psys_event_t event,
                              ia_cipr_psys_event_config_t *cfg);

/**
 * Update event config specification of event object
 *
 * \ingroup ia_cipr_psys
 * \param[in] event event object handle
 * \param[in] cfg ia_cipr_psys_event_config_t
 */
css_err_t
ia_cipr_psys_set_event_config(ia_cipr_psys_event_t event,
                              const ia_cipr_psys_event_config_t *cfg);

/**
 * Create PSYS command object
 *
 * Returns ia_cipr_psys_command_t object handle. Object is created based on
 * ia_cipr_psys_command_config_t specification and can be further used with
 * ia_cipr_psys_queue_command()
 *
 * A command object created with non-zero buffer count can be re-used to queue
 * commands with any number of buffers not exceeding the count used at
 * creation phase.
 *
 * A command object created with zero buffer count can be only used as command
 * without buffers. Such command object can contain process group or other
 * fixed fields to transmit info with the platform.
 *
 * IPU5/6 Persistent PG semantics include explicit start and stop commands.
 * A command with empty array of buffers with count according to terminal count
 * of process group is interpreted as start. A command with buffer count zero
 * is interpreted as stop.
 *
 * \ingroup ia_cipr_psys
 *
 * \param[in] cfg ia_cipr_psys_command_config_t command config specification
 */
ia_cipr_psys_command_t
ia_cipr_psys_create_command(ia_cipr_psys_command_config_t *cfg);

/**
 * Destroy PSYS command object
 *
 * \ingroup ia_cipr_psys
 * \param[in] cmd command object handle
 */
void ia_cipr_psys_destroy_command(ia_cipr_psys_command_t cmd);

/**
 * Read command config specification from command object
 *
 * \ingroup ia_cipr_psys
 *
 * \param[in] cmd command object handle
 * \param[out] cfg ia_cipr_psys_command_config_t
 */
css_err_t
ia_cipr_psys_get_command_config(ia_cipr_psys_command_t cmd,
                                ia_cipr_psys_command_config_t *cfg);
/**
 * Update command config specification of command object
 *
 * \ingroup ia_cipr_psys
 *
 * \param[in] cmd command object handle
 * \param[in] cfg ia_cipr_psys_command_config_t
 */
css_err_t
ia_cipr_psys_set_command_config(ia_cipr_psys_command_t cmd,
                                const ia_cipr_psys_command_config_t *cfg);

/* obsolete
 * \todo replace by memory_device ops
 */
css_err_t ia_cipr_psys_register_buffer(ia_cipr_psys_context_t ctx,
                                      ia_cipr_buffer_t *buffer);

/* obsolete
 * \todo replace by memory_device ops
 */
css_err_t ia_cipr_psys_unregister_buffer(ia_cipr_psys_context_t ctx,
                                        ia_cipr_buffer_t *buffers);
css_err_t ia_cipr_pg_control_init(ia_cipr_buffer_t *buffer,void *pg, size_t pg_size,
                                uint8_t *kup, unsigned int kup_size);


#endif  /* _IA_CIPR_PSYS_H_ */
