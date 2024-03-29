/*
 * Time.c
 *
 *  Created on: 9 abr 2023
 *      Author: mgnar
 */
#include "Time.h"
#include "Counter.h"

#define TIME_CHANNELS 3U
#define TIME_0 0U
#define TIME_1 1U
#define TIME_2 2U

// Static global variables
static TIME_UNITS TimeUnit [TIME_CHANNELS] = {{TIME_0, 0U, 0U, FALSE}, {TIME_1, 0U, 0U, FALSE}, {TIME_2, 0U, 0U, FALSE}};

// SetUp Time Module
void TIME_SetUpModule (TimeInMicroseconds Time)
{
	CM_Init();
}

void TIME_StartModule (TM_CallbackFunction CallbackFunction)
{
  // Start the timer, interrupt based
	CM_Start(CallbackFunction);
}


// Start Time channel
void TIME_StartChannel (unsigned short Channel)
{
  // Start time if has not been started
  if (FALSE == TimeUnit [Channel].InitStatus)
  {
    TimeUnit [Channel].InitStatus = TRUE;
    TimeUnit [Channel].CounterVal = CM_GetCounter ();
  }
  else
  {
    // Do nothing if Channel has been started
  }
}

/* Stop Time channel */
void TIME_StopChannel (unsigned short Channel)
{
  // Stop time if has not been stopped
  if (TRUE == TimeUnit [Channel].InitStatus)
  {
    TimeUnit [Channel].InitStatus = FALSE;
    TimeUnit [Channel].CounterVal = 0u;
    TimeUnit [Channel].TimeSinceCounter = 0u;
  }
  else
  {
    // Do nothing if Channel has been stopped
  }
}

/* Get time since Time channel started in milliseconds*/
float TIME_GetTimeSinceChannelStarted (unsigned short Channel)
{
  unsigned int CurrentTime = 0u;
  double time = 0.0;

  /* Get time since timer started only if channel was started */
  if (TRUE == TimeUnit [Channel].InitStatus)
  {
    CurrentTime = CM_GetCounter ();
    TimeUnit [Channel].TimeSinceCounter = CurrentTime - TimeUnit [Channel].CounterVal;
  }
  else
  {
    TimeUnit [Channel].TimeSinceCounter = 0u;
  }

  time = (interruptPeriodInUS / 1000.0) * (float) (TimeUnit [Channel].TimeSinceCounter);

  return time;
}

void TIME_SaveTimeCounter (unsigned int* const counterTime)
{
  *counterTime = CM_GetCounter ();
}
