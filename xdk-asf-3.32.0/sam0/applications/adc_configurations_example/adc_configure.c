/**
 * \file
 *
 * \brief ADC Features Configuration file
 *
 * Copyright (C) 2015 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */
 /**
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <asf.h>
#include "conf_example.h"
#include "adc_configure.h"

/* Structure for ADC module instance */
extern struct adc_module adc_instance;

static bool correction_measures_done = false;


/**
* \brief ADC Configuration normal mode.
* This function configures ADC as normal mode with below Settings
*
* GLCK for ADC		-> GCLK_GENERATOR_1 (8MHz)
* CLK_ADC				-> 512 KHz
* REFERENCE			-> 1/2 VDDANA (1.65V)
* POSITIVE INPUT		-> PA02
* NEGATIVE INPUT		-> GND
*/

void configure_adc(void)
{
	struct adc_config conf_adc;
	
	adc_get_config_defaults(&conf_adc);
	
	conf_adc.clock_source = GCLK_GENERATOR_1;
	conf_adc.reference = ADC_REFERENCE_INTVCC1;
	conf_adc.clock_prescaler = ADC_CLOCK_PRESCALER_DIV16;
	conf_adc.positive_input = ADC_POSITIVE_INPUT_PIN0;
	conf_adc.negative_input = ADC_NEGATIVE_INPUT_GND;
	
	adc_init(&adc_instance, ADC, &conf_adc);
	
	adc_enable(&adc_instance);
}

/**
* \brief ADC Differential mode configuration.
* This function configures ADC as differential mode with below Settings
*
* GLCK for ADC		-> GCLK_GENERATOR_1 (8MHz)
* CLK_ADC			-> 512 KHz
* REFERENCE			-> 1/2 VDDANA (1.65V)
* POSITIVE INPUT	-> PA02
* NEGATIVE INPUT	-> PA04
*/

void configure_adc_differential(void)
{
	struct adc_config conf_adc;
	
	adc_get_config_defaults(&conf_adc);
	
	conf_adc.clock_source = GCLK_GENERATOR_1;
	conf_adc.reference = ADC_REFERENCE_INTVCC1;
	conf_adc.clock_prescaler = ADC_CLOCK_PRESCALER_DIV16;
	conf_adc.differential_mode = true;
	conf_adc.positive_input = ADC_POSITIVE_INPUT_PIN0;
	conf_adc.negative_input = ADC_NEGATIVE_INPUT_PIN4;
	
	adc_init(&adc_instance, ADC, &conf_adc);
	
	adc_enable(&adc_instance);
}

/**
* \brief ADC Averaging mode configuration.
* This function configures ADC as Averaging mode with below Settings
*
* GLCK for ADC		-> GCLK_GENERATOR_1 (8MHz)
* CLK_ADC			-> 512 KHz
* REFERENCE			-> 1/2 VDDANA (1.65V)
* POSITIVE INPUT	-> PA02
* NEGATIVE INPUT	-> GND
* SAMPLES			-> 1024
* RESULT_DIV		-> 16
*/

void configure_adc_averaging(void)
{
	struct adc_config conf_adc;
	
	adc_get_config_defaults(&conf_adc);
	
	conf_adc.clock_source = GCLK_GENERATOR_1;
	conf_adc.reference = ADC_REFERENCE_INTVCC1;
	conf_adc.clock_prescaler = ADC_CLOCK_PRESCALER_DIV16;
	conf_adc.positive_input = ADC_POSITIVE_INPUT_PIN0;
	conf_adc.negative_input = ADC_NEGATIVE_INPUT_GND;
	conf_adc.resolution	= ADC_RESOLUTION_CUSTOM;
	conf_adc.accumulate_samples = ADC_ACCUMULATE_SAMPLES_1024;
	conf_adc.divide_result = ADC_DIVIDE_RESULT_16;
	
	adc_init(&adc_instance, ADC, &conf_adc);
	
	adc_enable(&adc_instance);
}

/**
* \brief ADC Oversampling mode configuration.
* This function configures ADC as Oversampling mode with below Settings
*
* GLCK for ADC		-> GCLK_GENERATOR_1 (8MHz)
* CLK_ADC			-> 512 KHz
* REFERENCE			-> 1/2 VDDANA (1.65V)
* RESOLUTION		-> 16 bit 
* POSITIVE INPUT	-> PA02
* NEGATIVE INPUT	-> GND
*/

void configure_adc_sampling(void)
{
	struct adc_config conf_adc;
	
	adc_get_config_defaults(&conf_adc);
	
	conf_adc.clock_source = GCLK_GENERATOR_1;
	conf_adc.reference = ADC_REFERENCE_INTVCC1;
	conf_adc.clock_prescaler = ADC_CLOCK_PRESCALER_DIV16;
	conf_adc.positive_input = ADC_POSITIVE_INPUT_PIN0;
	conf_adc.negative_input = ADC_NEGATIVE_INPUT_GND;
	conf_adc.resolution	= ADC_RESOLUTION_16BIT;
	conf_adc.reference_compensation_enable = true;
	
	adc_init(&adc_instance, ADC, &conf_adc);
	
	adc_enable(&adc_instance);
}

/**
* \brief ADC Window Monitoring mode configuration.
* This function configures ADC as Window Monitoring mode with below Settings
*
* GLCK for ADC			-> GCLK_GENERATOR_1 (8MHz)
* CLK_ADC				-> 512 KHz
* REFERENCE				-> 1/2 VDDANA (1.65V)
* POSITIVE INPUT		-> PA02
* NEGATIVE INPUT		-> GND
* Threshold low level	-> 0.75V
* Monitor mode			-> Above lower threshold
*/

void configure_adc_window_monitor(void)
{
	struct adc_config conf_adc;
	
	adc_get_config_defaults(&conf_adc);
	
	conf_adc.clock_source = GCLK_GENERATOR_1;
	conf_adc.reference = ADC_REFERENCE_INTVCC1;
	conf_adc.clock_prescaler = ADC_CLOCK_PRESCALER_DIV16;
	conf_adc.positive_input = ADC_POSITIVE_INPUT_PIN0;
	conf_adc.negative_input = ADC_NEGATIVE_INPUT_GND;
	conf_adc.window.window_mode = ADC_WINDOW_MODE_ABOVE_LOWER;
	conf_adc.window.window_lower_value = ADC_WINDOW_LOWER_THERSOLD_VALUE;
	
	adc_init(&adc_instance, ADC, &conf_adc);
	
	adc_enable(&adc_instance);
}

/**
* \brief ADC Offset and Gain mode configuration.
* This function starts the ADC correction using offset calibration and gain calibration
*
* GLCK for ADC		-> GCLK_GENERATOR_1 (8MHz)
* CLK_ADC			-> 512 KHz
* REFERENCE			-> 1/2 VDDANA (1.65V)
* POSITIVE INPUT	-> PA02
* NEGATIVE INPUT	-> GND
*/

void adc_correction_start(void)
{
	/* ADC channel configuration structure */
	struct adc_config conf_adc;
	
	uint32_t gain_corr;
	static uint16_t offset_correction;
	
	/* Expected value for gain correction at 1.55V
	 * expected_value = Max. range (12 bits unsigned) * 1.55V / 1.65)
	 */
	const uint16_t expected_value
		= ((ADC_12BIT_FULL_SCALE_VALUE + 1) * ADC_CALIBRATION_IN_VOLTAGE) / (ADC_CALIBRATION_REF_VOLTAGE);
		
	/* Captured value for gain correction */
	static uint16_t captured_value;

	if (correction_measures_done == false) {
		
		printf("\n*ADC offset correction:\n");
		printf("Set PA2 pin to 0 Volt(GND).\n");
		printf("Press any key to trigger measurement.\n");
		
		getchar();

		/* Capture ADC result for 0 Volt */
		
		offset_correction = adc_start_read_result();

		adc_get_config_defaults(&conf_adc);
		
		printf("ADC Offset measurement in progress...\n");
		
		gain_corr = ((ADC_12BIT_FULL_SCALE_VALUE + 1) * 1) / 1;
		
		/* Enable offset correction */
		conf_adc.correction.correction_enable = true;
		conf_adc.correction.gain_correction = gain_corr;
		conf_adc.correction.offset_correction = offset_correction;
		
		adc_init(&adc_instance, ADC, &conf_adc);
		
		adc_enable(&adc_instance);
		printf("ADC Offset measurement complete.\n");
		
		printf("*ADC Gain correction\n");
		printf("Set PA2 pin to 1.55 Volt");
		printf("Press a key to trigger measurement.\n");
		
		getchar();

		/* Capture ADC result for 1.55 Volts */
		captured_value = adc_start_read_result();
		
		correction_measures_done = true;
	}

	/* Enable offset & gain correction */
	adc_get_config_defaults(&conf_adc);
	printf("ADC Gain correction in progress...\n");
	
	gain_corr = (2048L * expected_value) / captured_value;
	
	conf_adc.correction.correction_enable = true;
	conf_adc.correction.gain_correction = gain_corr;
	conf_adc.correction.offset_correction = offset_correction;
	
	adc_init(&adc_instance, ADC, &conf_adc);
	
	adc_enable(&adc_instance);
	
	printf("ADC Gain correction is complete.\n");

	printf("\n* ADC correction enabled:  ");
	
	printf("\nOffset correction = %d,   ", offset_correction);
	
	if (expected_value > captured_value) {
		printf("\nGain correction 1.%03u\n", (uint16_t)
				((((uint32_t)expected_value - captured_value)
				* 1000) / captured_value));
	} 
	
	else {
		printf("\nGain correction 0.%03u\n", (uint16_t)
				(((uint32_t)expected_value
				* 1000) / captured_value));
	}	
}

/**
* \brief ADC Offset and Gain mode configuration.
* This function disable the ADC correction for offset 
* calibration and gain calibration
*
*/

void adc_correction_stop(void)
{	
	struct adc_config conf_adc;
	
	adc_get_config_defaults(&conf_adc);
	
	conf_adc.correction.correction_enable = false;
	correction_measures_done = false;
	
	adc_init(&adc_instance, ADC, &conf_adc);
	
	adc_enable(&adc_instance);
	
}






