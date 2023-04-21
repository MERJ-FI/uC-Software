/*
 * Tasks.c
 *
 *  Created on: 6 abr 2023
 *      Author: mgnar
 *      Tasks are configured in Tasks.h
 */

#include "stm32f4xx_hal.h"
#include "Tasks.h"
#include "Time.h"
#include "Scheduler.h"
static volatile float timeLapse = 0;

void SchM_ReadGPIOs_Task(void)
{
	//HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_3);
}

void SchM_Processing_Task(void)
{
	//HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_3);
}
void SchM_Executing_Task(void)
{
	//HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_3);
}

void Idle_Task(void)
{

	//STATUS PIN, need to manually input.
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_3);

	//STATUS PIN, need to manually input.

	timeLapse = TIME_GetTimeSinceChannelStarted(0u);

	// Restart the execution of the tasks.
	TIME_StopChannel(0u);
	TIME_StartChannel(0u);

}

void TaskInit(void)
{
	SchM_Task_Create(SCHM_TASKID_READGPIOS, SCHM_MASK_READGPIOS,
			SCHM_OFFSET_READGPIOS, SCHM_TASK_STATE_SUSPENDED,
			SchM_ReadGPIOs_Task);
	SchM_Task_Create(SCHM_TASKID_PROCESSING, SCHM_MASK_PROCESSING,
			SCHM_OFFSET_PROCESSING, SCHM_TASK_STATE_SUSPENDED,
			SchM_Processing_Task);
	SchM_Task_Create(SCHM_TASKID_EXECUTING, SCHM_MASK_EXECUTING,
			SCHM_OFFSET_EXECUTING, SCHM_TASK_STATE_SUSPENDED,
			SchM_Executing_Task);
	SchM_Task_Create(SCHM_TASKID_IDLE, SCHM_MASK_IDLE, SCHM_OFFSET_IDLE,
			SCHM_TASK_STATE_SUSPENDED, Idle_Task);
}
