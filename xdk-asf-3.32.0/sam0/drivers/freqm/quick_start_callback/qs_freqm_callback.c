/**
 * \file
 *
 * \brief SAM Frequency Meter Driver Quick Start
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

//! [setup]

//! [callback_2]
bool volatile freqm_read_done = false;
//! [callback_2]

void configure_freqm(void);
void configure_freqm_callback(void);
void freqm_complete_callback(void);

/* FREQM module software instance (must not go out of scope while in use) */
//! [setup_1]
static struct freqm_module freqm_instance;
//! [setup_1]

//! [setup_2]
void configure_freqm(void)
//! [setup_2]
{
	/* Create a new configuration structure for the FREQM settings
	 * and fill with the default module settings. */
	//! [setup_2_1]
	struct freqm_config config_freqm;
	//! [setup_2_1]
	//! [setup_2_2]
	freqm_get_config_defaults(&config_freqm);
	config_freqm.ref_clock_circles = 255;
	//! [setup_2_2]

	/* Alter any FREQM configuration settings here if required */

	/* Initialize FREQM with the user settings */
	//! [setup_2_3]
	freqm_init(&freqm_instance, FREQM, &config_freqm);
	//! [setup_2_3]
}

//! [callback_1]
void freqm_complete_callback(void)
{
	//! [callback_1_1]
	freqm_read_done = true;
	//! [callback_1_1]
}
//! [callback_1]

//! [setup_3]
void configure_freqm_callback(void)
{
	//! [setup_3_1]
	freqm_register_callback(&freqm_instance, freqm_complete_callback,
			FREQM_CALLBACK_MEASURE_DONE);
	//! [setup_3_1]
	//! [setup_3_2]
	freqm_enable_callback(&freqm_instance, FREQM_CALLBACK_MEASURE_DONE);
	//! [setup_3_2]
}
//! [setup_3]
//! [setup]

int main(void)
{
	//! [setup_init]
	system_init();
	configure_freqm();
	configure_freqm_callback();

	//! [setup_init_1]
	freqm_enable(&freqm_instance);
	//! [setup_init_1]
	//! [setup_init]

	//! [main]
	uint32_t measure_result;
	enum freqm_status status;
	//! [main_1]
	freqm_start_measure(&freqm_instance);
	//! [main_1]

	//! [main_2]
	while (!freqm_read_done) {
	}
	status = freqm_get_result_value(&freqm_instance, &measure_result);
	//! [main_2]
	switch(status) {
	//! [main_3]
		case FREQM_STATUS_MEASURE_DONE:
			LED_On(LED_0_PIN);
			while (true) {
			}
	//! [main_3]
	//! [main_4]
		case FREQM_STATUS_CNT_OVERFLOW:
			freqm_clear_overflow(&freqm_instance);
			while (true) {
				LED_Toggle(LED_0_PIN);
				volatile uint32_t delay = 50000;
				while(delay--) {
				}
			}
	//! [main_4]
		default:
			Assert(false);
			break;
	}
	//! [main]
}
