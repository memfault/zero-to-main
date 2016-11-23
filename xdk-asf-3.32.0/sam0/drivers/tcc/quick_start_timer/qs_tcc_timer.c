/**
 * \file
 *
 * \brief SAM TCC - Timer Counter for Control Applications Driver Quick Start
 *
 * Copyright (C) 2014-2015 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
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

static void configure_tcc(void);
static void configure_tcc_callbacks(void);
static void tcc_callback_to_toggle_led(
		struct tcc_module *const module_inst);


//! [module_inst]
struct tcc_module tcc_instance;
//! [module_inst]

//! [callback_funcs]
static void tcc_callback_to_toggle_led(
		struct tcc_module *const module_inst)
{
	port_pin_toggle_output_level(LED0_PIN);
}
//! [callback_funcs]

//! [setup]
static void configure_tcc(void)
{
	//! [setup_config]
	struct tcc_config config_tcc;
	//! [setup_config]
	//! [setup_config_defaults]
	tcc_get_config_defaults(&config_tcc, TCC0);
	//! [setup_config_defaults]

	//! [setup_change_config]
	config_tcc.counter.clock_source = GCLK_GENERATOR_1;
	config_tcc.counter.clock_prescaler = TCC_CLOCK_PRESCALER_DIV64;
	config_tcc.counter.period =   2000;
	config_tcc.compare.match[0] =  900;
	config_tcc.compare.match[1] =  930;
	config_tcc.compare.match[2] = 1100;
	config_tcc.compare.match[3] = 1250;
	//! [setup_change_config]

	//! [setup_set_config]
	tcc_init(&tcc_instance, TCC0, &config_tcc);
	//! [setup_set_config]

	//! [setup_enable]
	tcc_enable(&tcc_instance);
	//! [setup_enable]
}

static void configure_tcc_callbacks(void)
{
	//! [setup_register_callback]
	tcc_register_callback(&tcc_instance, tcc_callback_to_toggle_led,
			TCC_CALLBACK_OVERFLOW);
	tcc_register_callback(&tcc_instance, tcc_callback_to_toggle_led,
			TCC_CALLBACK_CHANNEL_0);
	tcc_register_callback(&tcc_instance, tcc_callback_to_toggle_led,
			TCC_CALLBACK_CHANNEL_1);
	tcc_register_callback(&tcc_instance, tcc_callback_to_toggle_led,
			TCC_CALLBACK_CHANNEL_2);
	tcc_register_callback(&tcc_instance, tcc_callback_to_toggle_led,
			TCC_CALLBACK_CHANNEL_3);
	//! [setup_register_callback]

	//! [setup_enable_callback]
	tcc_enable_callback(&tcc_instance, TCC_CALLBACK_OVERFLOW);
	tcc_enable_callback(&tcc_instance, TCC_CALLBACK_CHANNEL_0);
	tcc_enable_callback(&tcc_instance, TCC_CALLBACK_CHANNEL_1);
	tcc_enable_callback(&tcc_instance, TCC_CALLBACK_CHANNEL_2);
	tcc_enable_callback(&tcc_instance, TCC_CALLBACK_CHANNEL_3);
	//! [setup_enable_callback]
}
//! [setup]

int main(void)
{
	system_init();

//! [setup_init]
	configure_tcc();
	configure_tcc_callbacks();
//! [setup_init]

//! [main]
	//! [enable_global_interrupts]
	system_interrupt_enable_global();
	//! [enable_global_interrupts]

	//! [main_loop]
	while (true) {
	}
	//! [main_loop]
//! [main]
}
