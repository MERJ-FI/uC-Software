/*
 * ADC.c
 *
 *  Created on: 6 abr 2023
 *      Author: mgnar
 */
#include "stm32f4xx_hal.h"
#include "ADC.h"
#include "math.h"

ADC_HandleTypeDef HADC1 =
{ 0 };

uint8_t initADC(void)
{
	uint8_t returnValue = 0;

	__HAL_RCC_ADC1_CLK_ENABLE();

	HADC1.Instance = ADC1;
	HADC1.Init.ContinuousConvMode = ENABLE;
	//HADC1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	HADC1.Init.ExternalTrigConv = ADC_EXTERNALTRIGCONV_T3_CC1; // ADC_SOFTWARE_START;
	HADC1.Init.NbrOfConversion = 1;
	//HADC1.State = HAL_ADC_STATE_READY;
	HADC1.Init.Resolution = ADC_RESOLUTION_12B;
	HADC1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV8;

	if (HAL_ADC_Init(&HADC1) != HAL_OK)
	{
		returnValue = 1;
	}

	ADC_ChannelConfTypeDef adc_ch0 =
	{ 0 };
	adc_ch0.Channel = ADC_CHANNEL_0;
	adc_ch0.Rank = 1;
	adc_ch0.SamplingTime = ADC_SAMPLETIME_15CYCLES;

	if (HAL_ADC_ConfigChannel(&HADC1, &adc_ch0) != HAL_OK)
	{
		returnValue = 1;
	}

	HAL_ADC_Start(&HADC1);

	return returnValue;
}

double readADC(void)
{
	double returnValue = 0.0;
	uint16_t readValue = 0;

	const double voltageReference = 3.3;
	const uint8_t resolutionBits = 12;
	const double factor = (voltageReference/(pow(2,resolutionBits) - 1));

	readValue = HAL_ADC_GetValue(&HADC1);
	returnValue = readValue * factor;

	return returnValue;
}
