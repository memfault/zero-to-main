/**
 * \file
 *
 * \brief SAM SDADC Quick Start
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
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#include <asf.h>

void configure_sdadc(void);
void configure_sdadc_callbacks(void);
void sdadc_complete_callback(
		const struct sdadc_module *const module);

//! [result_buffer]
#define SDADC_SAMPLES 128
int32_t sdadc_result_buffer[SDADC_SAMPLES];
//! [result_buffer]

//! [module_inst]
struct sdadc_module sdadc_instance;
//! [module_inst]

//! [job_complete_callback]
volatile bool sdadc_read_done = false;

void sdadc_complete_callback(
		const struct sdadc_module *const module)
{
	sdadc_read_done = true;
}
//! [job_complete_callback]

//! [setup]
void configure_sdadc(void)
{
//! [setup_config]
	struct sdadc_config config_sdadc;
//! [setup_config]
//! [setup_config_defaults]
	sdadc_get_config_defaults(&config_sdadc);
//! [setup_config_defaults]

//! [setup_modify_conf]
	config_sdadc.clock_prescaler = 2;
	config_sdadc.reference.ref_sel = SDADC_REFERENCE_INTREF;
	config_sdadc.osr             = SDADC_OVER_SAMPLING_RATIO1024;
	config_sdadc.mux_input       = SDADC_MUX_INPUT_AIN2;
//! [setup_modify_conf]

//! [setup_set_config]
	sdadc_init(&sdadc_instance, SDADC, &config_sdadc);
//! [setup_set_config]

//! [setup_enable]
	sdadc_enable(&sdadc_instance);
//! [setup_enable]
}

void configure_sdadc_callbacks(void)
{
//! [setup_register_callback]
	sdadc_register_callback(&sdadc_instance,
			sdadc_complete_callback, SDADC_CALLBACK_READ_BUFFER);
//! [setup_register_callback]
//! [setup_enable_callback]
	sdadc_enable_callback(&sdadc_instance, SDADC_CALLBACK_READ_BUFFER);
//! [setup_enable_callback]
}
//! [setup]

int main(void)
{
	system_init();

//! [setup_init]
	configure_sdadc();
	configure_sdadc_callbacks();
//! [setup_init]

//! [main]
//! [enable_global_interrupts]
	system_interrupt_enable_global();
//! [enable_global_interrupts]

//! [start_sdadc_job]
	sdadc_read_buffer_job(&sdadc_instance, sdadc_result_buffer, SDADC_SAMPLES);
//! [start_sdadc_job]

//! [job_complete_poll]
	while (sdadc_read_done == false) {
		/* Wait for asynchronous SDADC read to complete */
	}
//! [job_complete_poll]

//! [inf_loop]
	while (1) {
		/* Infinite loop */
	}
//! [inf_loop]
//! [main]
}
