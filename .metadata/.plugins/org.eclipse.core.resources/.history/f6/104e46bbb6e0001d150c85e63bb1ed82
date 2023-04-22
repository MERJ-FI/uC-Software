/*
 * Time_DataTypes.h
 *
 *  Created on: 9 abr 2023
 *      Author: mgnar
 */

#ifndef INC_TIME_DATATYPES_H_
#define INC_TIME_DATATYPES_H_

// Time base selected for the tasks execution
#define interruptPeriodInUS 1000U
#define FALSE 0U
#define TRUE 1U
typedef unsigned char boolean;

typedef struct t_TIME_UNITS
{
    char TimeUnit;         // Index of the time unit [TimeUnit0, TimeUnit1, ...]
    unsigned int CounterVal;       // Last value counter
    unsigned int TimeSinceCounter; // Last time value
    boolean InitStatus;       // Status of the time unit, is Initialized? [true. false]
} TIME_UNITS;

typedef void (*TM_CallbackFunction) (void);

typedef unsigned int TimeInMicroseconds;

#endif /* INC_TIME_DATATYPES_H_ */
