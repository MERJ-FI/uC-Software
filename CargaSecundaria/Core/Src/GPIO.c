/*
 * GPIO.c
 *
 *  Created on: 6 abr 2023
 *      Author: mgnar
 */
#include "GPIO.h"
#include "stm32f1xx_hal.h"

// Peripheral pins.
GPIO_InitTypeDef SPI =
{ 0 }, USART2_a =
{ 0 };
// Individual pins.
GPIO_InitTypeDef IRQ =
{ 0 }, PPS =
{ 0 }, CE =
{ 0 }, STATUS =
{ 0 }, VBAT =
{ 0 };

void GPIOInit(void)
{
	// Clock net is enabled for ports A and B.
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	// SPI pins configuration.
	SPI.Pin = GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7;
	SPI.Mode = GPIO_MODE_AF_PP;
	//ToDo : Add AF and Input mode port MISO
	//SPI.Alternate = GPIO_AF5_SPI1;
	// Init in the selected port with the above config.
	HAL_GPIO_Init(GPIOA, &SPI);

	// UART pins configuration.
	USART2_a.Pin = GPIO_PIN_2 | GPIO_PIN_3;
	USART2_a.Mode = GPIO_MODE_AF_PP;
	//ToDo: Add AF
	//SPI.Alternate = GPIO_AF5_SPI1;
	// Init in the selected port with the above config.
	HAL_GPIO_Init(GPIOA, &USART2_a);

	// IRQ pin configuration.
	IRQ.Pin = GPIO_PIN_0;
	IRQ.Mode = GPIO_MODE_INPUT;
	HAL_GPIO_Init(GPIOB, &IRQ);

	// CE pin configuration.
	CE.Pin = GPIO_PIN_1;
	CE.Mode = GPIO_MODE_OUTPUT_PP;
	HAL_GPIO_Init(GPIOB, &CE);

	// STATUS pin configuration.
	STATUS.Pin = GPIO_PIN_10;
	STATUS.Mode = GPIO_MODE_OUTPUT_PP;
	HAL_GPIO_Init(GPIOB, &STATUS);

	// PPS pin configuration.
	PPS.Pin = GPIO_PIN_1;
	PPS.Mode = GPIO_MODE_INPUT;
	HAL_GPIO_Init(GPIOA, &PPS);

	// VBAT pin configuration.
	VBAT.Pin = GPIO_PIN_0;
	VBAT.Mode = GPIO_MODE_ANALOG;
	HAL_GPIO_Init(GPIOA, &VBAT);

}
