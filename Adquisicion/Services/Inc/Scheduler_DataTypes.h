/*
 * Scheduler_DataTypes.h
 *
 *  Created on: 6 abr 2023
 *      Author: mgnar
 */

#ifndef INC_SCHEDULER_DATATYPES_H_
#define INC_SCHEDULER_DATATYPES_H_

// ID enum
typedef enum
{
	SCHM_TASKID_READGPIOS = 0u,
	SCHM_TASKID_PROCESSING,
	SCHM_TASKID_EXECUTING,
	SCHM_TASKID_IDLE
} SchM_TaskIDType;

// Mask enum
typedef enum
{
	SCHM_MASK_READGPIOS = 0x0000007F,
	SCHM_MASK_PROCESSING = 0x0000007F,
	SCHM_MASK_EXECUTING = 0x0000007F,
	SCHM_MASK_IDLE = 0x00000007
} SchM_TaskMaskType;

// Offset enum
typedef enum
{
	SCHM_OFFSET_READGPIOS = 0u,
	SCHM_OFFSET_PROCESSING,
	SCHM_OFFSET_EXECUTING,
	SCHM_OFFSET_IDLE
} SchM_TaskOffsetType;

// Task state enum
typedef enum
{
	SCHM_TASK_STATE_SUSPENDED = 0u,
	SCHM_TASK_STATE_READY,
	SCHM_TASK_STATE_RUNNING
} SchM_TaskStateType;

// General attributes of the task
typedef struct t_SchM_TaskType
{
	SchM_TaskIDType TaskID;
	SchM_TaskMaskType TaskMask;
	SchM_TaskOffsetType TaskOffset;
	SchM_TaskStateType TaskState;
	void (*SchM_Task)(void);
} SchM_Tasks;

#endif /* INC_SCHEDULER_DATATYPES_H_ */
