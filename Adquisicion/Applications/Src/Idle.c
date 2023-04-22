/*
 * Idle.c
 *
 *  Created on: 6 abr 2023
 *      Author: mgnar
 */
#include "stm32f4xx_hal.h"
#include "Idle.h"

void Idle(void)
{
	//STATUS PIN, need to manually input.
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_3);
}
