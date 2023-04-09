/*
 * Counter.h
 *
 *  Created on: 6 abr 2023
 *      Author: mgnar
 */

#ifndef INC_COUNTER_H_
#define INC_COUNTER_H_

#include "counter_DataTypes.h"


// Exported global functions
unsigned int CM_GetCounter(void);
void CM_Init(void);
void CM_Start(CM_CallbackFunction CallbackFunction);

#endif /* INC_COUNTER_H_ */
