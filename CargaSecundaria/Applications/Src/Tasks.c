/*
 * Tasks.c
 *
 *  Created on: 6 abr 2023
 *      Author: mgnar
 *      Tasks are configured in Tasks.h
 */

#include "stm32f1xx_hal.h"
#include "Tasks.h"
#include "Time.h"
#include "Scheduler.h"

void Idle_Task(void)
{

	//STATUS PIN, need to manually input.
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_10);

	// Restart the execution of the tasks.
	TIME_StopChannel(0u);
	TIME_StartChannel(0u);

}

void TaskInit(void)
{
	SchM_Task_Create(SCHM_TASKID_IDLE, SCHM_MASK_IDLE, SCHM_OFFSET_IDLE,
			SCHM_TASK_STATE_SUSPENDED, Idle_Task);
}
