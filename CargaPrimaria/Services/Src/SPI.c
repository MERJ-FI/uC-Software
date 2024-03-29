/*
 * SPI.c
 *
 *  Created on: 6 abr 2023
 *      Author: mgnar
 */

#include "stm32f4xx_hal.h"
#include "SPI.h"
#include <string.h>

SPI_HandleTypeDef HSPI1 = {0};

uint8_t initSPI(void)
{
	uint8_t returnValue = 0;

	__HAL_RCC_SPI1_CLK_ENABLE();

	//2.-
	GPIO_InitTypeDef GPIO =
	{ 0 };
	//Si habilito por software
	//	GPIO.Mode = GPIO_MODE_OUTPUT_PP;
	//	GPIO.Pin = GPIO_PIN_4;
	//	HAL_GPIO_Init(GPIOA, &GPIO);
	GPIO.Pin = GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7;
	GPIO.Mode = GPIO_MODE_AF_PP;
	GPIO.Alternate = GPIO_AF5_SPI1;
	HAL_GPIO_Init(GPIOA, &GPIO);

	//3.-
	HSPI1.Instance = SPI1;
	HSPI1.Init.CLKPhase = SPI_PHASE_1EDGE;
	HSPI1.Init.CLKPolarity = SPI_POLARITY_LOW;
	HSPI1.Init.DataSize = SPI_DATASIZE_8BIT;
	HSPI1.Init.Mode = SPI_MODE_MASTER;
	HSPI1.Init.FirstBit = SPI_FIRSTBIT_MSB;
	HSPI1.Init.NSS = SPI_NSS_HARD_OUTPUT;
	HSPI1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256;
	HSPI1.Init.Direction = SPI_DIRECTION_2LINES;

	if (HAL_SPI_Init(&HSPI1) != HAL_OK)
		returnValue = 1;

	return returnValue;
}

void SPIRx(char *buf, uint8_t len)
{
	HAL_SPI_Receive(&HSPI1, (uint8_t *)buf, len, HAL_MAX_DELAY);
}

void SPITx(char TxBuffer[])
{
	HAL_SPI_Transmit(&HSPI1, (uint8_t *)&TxBuffer, strlen(TxBuffer), HAL_MAX_DELAY);
}
