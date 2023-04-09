/*
 * GPIO.c
 *
 *  Created on: 6 abr 2023
 *      Author: mgnar
 */

#include "GPIO.h"
#include "stm32f4xx_hal.h"

// Peripheral pins.
GPIO_InitTypeDef SPI_primary =
{ 0 }, SPI_secondary =
{ 0 }, USB_interface =
{ 0 }, UART_interface =
{ 0 };

// Individual pins.
GPIO_InitTypeDef IRQ_P =
{ 0 }, IRQ_S =
{ 0 }, CE_P =
{ 0 }, CE_S =
{ 0 }, OUT1 =
{ 0 }, STATUS =
{ 0 };

void GPIOInit(void)
{
	// Clock net is enabled for ports A and B.
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	// Primary Antena's SPI pins configuration.
	// ToDO Hay 1 pin de entrada miso, checar.
	SPI_primary.Pin = GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7;
	SPI_primary.Mode = GPIO_MODE_AF_PP;
	SPI_primary.Alternate = GPIO_AF5_SPI1;
	HAL_GPIO_Init(GPIOA, &SPI_primary);

	// Secondary Antena's SPI pins configuration.
	// ToDO Hay 1 pin de entrada miso, checar.
	SPI_secondary.Pin = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
	SPI_secondary.Mode = GPIO_MODE_AF_PP;
	SPI_secondary.Alternate = GPIO_AF5_SPI2;
	HAL_GPIO_Init(GPIOB, &SPI_secondary);

	// USB pins configuration.
	USB_interface.Pin = GPIO_PIN_11 | GPIO_PIN_12;
	USB_interface.Mode = GPIO_MODE_AF_PP;
	USB_interface.Alternate = GPIO_AF10_OTG_FS;
	//i2c_pin.Pull=GPIO_PULLUP;
	HAL_GPIO_Init(GPIOA, &USB_interface);

	// UART pins configuration.
	UART_interface.Pin = GPIO_PIN_6 | GPIO_PIN_7;
	UART_interface.Mode = GPIO_MODE_AF_PP;
	UART_interface.Alternate = GPIO_AF7_USART1;
	//i2c_pin.Pull=GPIO_PULLUP;
	HAL_GPIO_Init(GPIOB, &UART_interface);

	// Primary IRQ pin configuration.
	IRQ_P.Pin = GPIO_PIN_2;
	IRQ_P.Mode = GPIO_MODE_INPUT;
	HAL_GPIO_Init(GPIOA, &IRQ_P);

	// Secondary IRQ pin configuration.
	IRQ_S.Pin = GPIO_PIN_8;
	IRQ_S.Mode = GPIO_MODE_INPUT;
	HAL_GPIO_Init(GPIOA, &IRQ_S);

	// Primary CE pin configuration.
	CE_P.Pin = GPIO_PIN_1;
	CE_P.Mode = GPIO_MODE_OUTPUT_PP;
	HAL_GPIO_Init(GPIOA, &CE_P);

	// Secondary CE pin configuration.
	CE_S.Pin = GPIO_PIN_9;
	CE_S.Mode = GPIO_MODE_OUTPUT_PP;
	HAL_GPIO_Init(GPIOA, &CE_S);

	// STATUS pin configuration.
	STATUS.Pin = GPIO_PIN_3;
	STATUS.Mode = GPIO_MODE_OUTPUT_PP;
	HAL_GPIO_Init(GPIOA, &STATUS);

	// General purpose OUT1 pin configuration.
	OUT1.Pin = GPIO_PIN_5;
	OUT1.Mode = GPIO_MODE_OUTPUT_PP;
	HAL_GPIO_Init(GPIOB, &OUT1);


}
