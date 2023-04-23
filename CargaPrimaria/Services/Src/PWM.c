/*
 * PWM.c
 *
 *  Created on: 6 abr 2023
 *      Author: mgnar
 */

#include "stm32f4xx_hal.h"
#include "PWM.h"

TIM_HandleTypeDef HTim3 =
{ 0 };

uint8_t initPWM(void)
{
	uint8_t returnValue = 0;

	__HAL_RCC_TIM3_CLK_ENABLE();

	HTim3.Instance = TIM3;
	HTim3.Init.CounterMode = TIM_COUNTERMODE_UP;
	HTim3.Init.Prescaler = 34; // Ck_CNT = Ck_PSC / (1 + Preescaler)
	HTim3.Init.Period = 127;  // Freq_int = Ck_CNT / (1 + Period)

	if (HAL_TIM_PWM_Init(&HTim3) != HAL_OK)
		returnValue = 1;

	// Canal 1.
	TIM_OC_InitTypeDef TimCh2 =
	{ 0 };
	TimCh2.OCPolarity = TIM_OCPOLARITY_HIGH;
	TimCh2.OCMode = TIM_OCMODE_PWM1;
	TimCh2.Pulse = 0;

	if (HAL_TIM_PWM_ConfigChannel(&HTim3, &TimCh2, TIM_CHANNEL_2) != HAL_OK)
		returnValue = 1;

	HAL_TIM_PWM_Start(&HTim3, TIM_CHANNEL_2);

	return returnValue;
}

void setPWM(uint8_t value)
{
	__HAL_TIM_SET_COMPARE(&HTim3, TIM_CHANNEL_2, value);
}
