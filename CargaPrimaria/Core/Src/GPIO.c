/*
 * GPIO.c
 *
 *  Created on: 6 abr 2023
 *      Author: mgnar
 */

#include "GPIO.h"
#include "stm32f4xx_hal.h"

// Peripheral pins.
GPIO_InitTypeDef SPI_berry =
{ 0 }, SPI_antena =
{ 0 }, I2C_berry =
{ 0 };

// Individual pins.
GPIO_InitTypeDef IRQ =
{ 0 }, INT1 =
{ 0 }, INT2 =
{ 0 }, CE =
{ 0 }, VBAT =
{ 0 }, OUT1 =
{ 0 }, SERVO =
{ 0 }, STATUS =
{ 0 };

void GPIOInit(void)
{
	// Clock net is enabled for ports A and B.
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	// Antena's SPI pins configuration.
	// ToDO Hay 1 pin de entrada miso, checar.
	SPI_antena.Pin = GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7;
	SPI_antena.Mode = GPIO_MODE_AF_PP;
	SPI_antena.Alternate = GPIO_AF5_SPI1;
	HAL_GPIO_Init(GPIOA, &SPI_antena);

	// Berry's SPI pins configuration.
	// ToDO Hay 1 pin de entrada miso, checar.
	SPI_berry.Pin = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
	SPI_berry.Mode = GPIO_MODE_AF_PP;
	SPI_berry.Alternate = GPIO_AF5_SPI2;
	HAL_GPIO_Init(GPIOB, &SPI_berry);

	// Berry's I2C pins configuration.
	I2C_berry.Pin = GPIO_PIN_6 | GPIO_PIN_7;
	I2C_berry.Mode = GPIO_MODE_AF_OD;
	I2C_berry.Alternate = GPIO_AF4_I2C1;
	//i2c_pin.Pull=GPIO_PULLUP;
	HAL_GPIO_Init(GPIOB, &I2C_berry);

	// IRQ pin configuration.
	IRQ.Pin = GPIO_PIN_2;
	IRQ.Mode = GPIO_MODE_INPUT;
	HAL_GPIO_Init(GPIOA, &IRQ);

	// INT1 pin configuration.
	INT1.Pin = GPIO_PIN_9;
	INT1.Mode = GPIO_MODE_OUTPUT_PP;
	HAL_GPIO_Init(GPIOA, &INT1);

	// INT2 pin configuration.
	INT2.Pin = GPIO_PIN_8;
	INT2.Mode = GPIO_MODE_OUTPUT_PP;
	HAL_GPIO_Init(GPIOA, &INT2);

	// CE pin configuration.
	CE.Pin = GPIO_PIN_1;
	CE.Mode = GPIO_MODE_OUTPUT_PP;
	HAL_GPIO_Init(GPIOA, &CE);

	// STATUS pin configuration.
	STATUS.Pin = GPIO_PIN_3;
	STATUS.Mode = GPIO_MODE_OUTPUT_PP;
	HAL_GPIO_Init(GPIOA, &STATUS);

	// General purpose OUT1 pin configuration.
	OUT1.Pin = GPIO_PIN_3;
	OUT1.Mode = GPIO_MODE_OUTPUT_PP;
	HAL_GPIO_Init(GPIOB, &OUT1);

	// SERVO pin configuration.
	SERVO.Pin = GPIO_PIN_5;
	SERVO.Mode = GPIO_MODE_AF_PP;
	SERVO.Alternate = GPIO_AF2_TIM3;
	HAL_GPIO_Init(GPIOB, &SERVO);

	// VBAT pin configuration.
	VBAT.Pin = GPIO_PIN_0;
	VBAT.Mode = GPIO_MODE_ANALOG;
	HAL_GPIO_Init(GPIOA, &VBAT);

}
