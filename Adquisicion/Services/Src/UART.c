/*
 * UART.c
 *
 *  Created on: 6 abr 2023
 *      Author: mgnar
 */
#include "stm32f4xx_hal.h"
#include "UART.h"
#include <string.h>

UART_HandleTypeDef UART1 = {0};

uint8_t initUART(void)
{
	uint8_t returnValue = 0;

	__HAL_RCC_USART1_CLK_ENABLE();

	//Bajo nivel
	GPIO_InitTypeDef UARTPin =
	{ 0 };
	UARTPin.Pin = GPIO_PIN_9 | GPIO_PIN_10;
	UARTPin.Mode = GPIO_MODE_AF_PP;
	UARTPin.Alternate = GPIO_AF7_USART1;
	HAL_GPIO_Init(GPIOA, &UARTPin);

	//Alto nivel
	UART1.Instance = USART1;
	UART1.Init.Mode = UART_MODE_TX_RX;
	UART1.Init.BaudRate = 115200;
	UART1.Init.Parity = UART_PARITY_NONE;
	UART1.Init.StopBits = UART_STOPBITS_1;

	if (HAL_UART_Init(&UART1) != HAL_OK)
		returnValue = 1;

	return returnValue;
}

void UARTTx(char TxBuffer[])
{
	HAL_UART_Transmit(&UART1, (uint8_t *) &TxBuffer, strlen(TxBuffer), HAL_MAX_DELAY);
}

void UARTRx(char *buf, uint8_t len)
{
	HAL_UART_Receive(&UART1, (uint8_t *)buf, len, HAL_MAX_DELAY);
}
