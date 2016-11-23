/**
 * \file
 *
 * \brief SAM ADC Quick Start
 *
 * Copyright (C) 2013-2016 Atmel Corporation. All rights reserved.
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
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <asf.h>

void configure_adc(void);
void configure_adc_callbacks(void);
void adc_complete_callback(
		struct adc_module *const module);

//! [result_buffer]
#define ADC_SAMPLES 128
uint16_t adc_result_buffer[ADC_SAMPLES];
//! [result_buffer]

//! [module_inst]
struct adc_module adc_instance;
//! [module_inst]

//! [job_complete_callback]
volatile bool adc_read_done = false;

void adc_complete_callback(
		struct adc_module *const module)
{
	adc_read_done = true;
}
//! [job_complete_callback]

//! [setup]
void configure_adc(void)
{
//! [setup_config]
	struct adc_config config_adc;
//! [setup_config]
//! [setup_config_defaults]
	adc_get_config_defaults(&config_adc);
//! [setup_config_defaults]

//! [setup_modify_conf]
#if (!SAML21) && (!SAML22) && (!SAMC21) && (!SAMR30)
	config_adc.gain_factor     = ADC_GAIN_FACTOR_DIV2;
#endif
	config_adc.clock_prescaler = ADC_CLOCK_PRESCALER_DIV8;
	config_adc.reference       = ADC_REFERENCE_INTVCC1;
#if (SAMC21)
	config_adc.positive_input  = ADC_POSITIVE_INPUT_PIN5;
#else
	config_adc.positive_input  = ADC_POSITIVE_INPUT_PIN6;
#endif
	config_adc.resolution      = ADC_RESOLUTION_12BIT;
//! [setup_modify_conf]

//! [setup_set_config]
#if (SAMC21)
	adc_init(&adc_instance, ADC1, &config_adc);
#else
	adc_init(&adc_instance, ADC, &config_adc);
#endif
//! [setup_set_config]

//! [setup_enable]
	adc_enable(&adc_instance);
//! [setup_enable]
}

void configure_adc_callbacks(void)
{
//! [setup_register_callback]
	adc_register_callback(&adc_instance,
			adc_complete_callback, ADC_CALLBACK_READ_BUFFER);
//! [setup_register_callback]
//! [setup_enable_callback]
	adc_enable_callback(&adc_instance, ADC_CALLBACK_READ_BUFFER);
//! [setup_enable_callback]
}
//! [setup]

int main(void)
{
	system_init();

//! [setup_init]
	configure_adc();
	configure_adc_callbacks();
//! [setup_init]

//! [main]
//! [enable_global_interrupts]
	system_interrupt_enable_global();
//! [enable_global_interrupts]

//! [start_adc_job]
	adc_read_buffer_job(&adc_instance, adc_result_buffer, ADC_SAMPLES);
//! [start_adc_job]

//! [job_complete_poll]
	while (adc_read_done == false) {
		/* Wait for asynchronous ADC read to complete */
	}
//! [job_complete_poll]

//! [inf_loop]
	while (1) {
		/* Infinite loop */
	}
//! [inf_loop]
//! [main]
}
