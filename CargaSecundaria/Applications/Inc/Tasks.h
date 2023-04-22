/*
 * Tasks.h
 *
 *  Created on: 6 abr 2023
 *      Author: mgnar
 */

#ifndef INC_TASKS_H_
#define INC_TASKS_H_

// Tasks prototypes, more can be added here (don't forget to change Scheduler.h tasks value)
void Read_Task (void);
void Processing_Task (void);
void Executing_Task (void);
void Idle_Task(void);

void TaskInit(void);

#endif /* INC_TASKS_H_ */
