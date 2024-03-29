/*
 * Time.h
 *
 *  Created on: 9 abr 2023
 *      Author: mgnar
 */

#ifndef INC_TIME_H_
#define INC_TIME_H_

#include "Time_DataTypes.h"

// Initialized by scheduler
void TIME_SetUpModule (TimeInMicroseconds Time);
void TIME_StartModule (TM_CallbackFunction CallbackFunction);
void TIME_StopModule (TM_CallbackFunction CallbackFunction);

// Used by scheduler
void TIME_SaveTimeCounter (unsigned int* const counterTime);

// General purpose for measure time lapse
void TIME_StartChannel (unsigned short TimeChannel);
void TIME_StopChannel (unsigned short Channel);
float TIME_GetTimeSinceChannelStarted (unsigned short Channel);

#endif /* INC_TIME_H_ */
