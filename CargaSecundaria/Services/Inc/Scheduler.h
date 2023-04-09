/*
 * Scheduler.h
 *
 *  Created on: 6 abr 2023
 *      Author: mgnar
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "Scheduler_DataTypes.h"

#define Channel_01    0u
#define NUMBEROFTASKS  1u

void SchM_Init (void);
void SchM_Start (void);
void SchM_Stopo (void);

void SchM_Task_Create (SchM_TaskIDType taskID, SchM_TaskMaskType mask, SchM_TaskOffsetType offset,
    SchM_TaskStateType taskState, void (*callback) (void));

#endif /* INC_SCHEDULER_H_ */
