/*
 * Counter.c
 *
 *  Created on: 6 abr 2023
 *      Author: mgnar
 */
#include "stm32f4xx_hal.h"
#include "counter.h"

TIM_HandleTypeDef HTim2 =
{ 0 };

static CM_CallbackFunction Callback;
static volatile unsigned int CounterVal = 0;



unsigned int CM_GetCounter(void)
{
	return CounterVal;
}

void TIM2_IRQHandler(void)
{

	HAL_TIM_IRQHandler(&HTim2);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	// Interrupt every 500us.
	// Count increase
	CounterVal++;

	// Call the callback
	Callback();

}


void CM_Init(void)
{
	// Enable clock net for timer 2.
	__HAL_RCC_TIM2_CLK_ENABLE();

	// Config tim 2 for interrupts.
	HTim2.Instance = TIM2;
	HTim2.Init.Prescaler = 999; // Ck_CNT = (Clock 64/2) / (1 + Preescaler)
	HTim2.Init.Period = 15; // Freq_int = Ck_CNT / (1 + Period)


	// Enable the interrupt.
	HAL_NVIC_SetPriority(TIM2_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);


}

void CM_Start(CM_CallbackFunction CallbackFunction)
{
	Callback = CallbackFunction;

	// Start it.
	HAL_TIM_Base_Init(&HTim2);
	HAL_TIM_Base_Start_IT(&HTim2);
}
