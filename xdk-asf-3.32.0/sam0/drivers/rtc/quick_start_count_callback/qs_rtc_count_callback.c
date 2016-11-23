/**
 * \file
 *
 * \brief SAM RTC Count Callback Quick Start
 *
 * Copyright (C) 2013-2015 Atmel Corporation. All rights reserved.
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

void rtc_overflow_callback(void);
void configure_rtc_count(void);
void configure_rtc_callbacks(void);

//! [rtc_module_instance]
struct rtc_module rtc_instance;
//! [rtc_module_instance]

//! [callback]
void rtc_overflow_callback(void)
{
//! [overflow_act]
	/* Do something on RTC overflow here */
	port_pin_toggle_output_level(LED_0_PIN);
//! [overflow_act]
}
//! [callback]

//! [initialize_rtc]
void configure_rtc_count(void)
{
//! [init_conf]
	struct rtc_count_config config_rtc_count;
	rtc_count_get_config_defaults(&config_rtc_count);
//! [init_conf]

//! [set_config]
	config_rtc_count.prescaler           = RTC_COUNT_PRESCALER_DIV_1;
	config_rtc_count.mode                = RTC_COUNT_MODE_16BIT;
#ifdef FEATURE_RTC_CONTINUOUSLY_UPDATED
	config_rtc_count.continuously_update = true;
#endif
//! [set_config]
//! [init_rtc]
	rtc_count_init(&rtc_instance, RTC, &config_rtc_count);
//! [init_rtc]

//! [enable]
	rtc_count_enable(&rtc_instance);
//! [enable]
}
//! [initialize_rtc]

//! [setup_callback]
void configure_rtc_callbacks(void)
{
	//! [reg_callback]
	rtc_count_register_callback(
			&rtc_instance, rtc_overflow_callback, RTC_COUNT_CALLBACK_OVERFLOW);
	//! [reg_callback]
	//! [en_callback]
	rtc_count_enable_callback(&rtc_instance, RTC_COUNT_CALLBACK_OVERFLOW);
	//! [en_callback]
}
//! [setup_callback]

int main(void)
{
//! [run_initialize_rtc]
	/* Initialize system. Must configure conf_clocks.h first. */
//! [system_init]
	system_init();
//! [system_init]

	/* Configure and enable RTC */
//! [run_conf]
	configure_rtc_count();
//! [run_conf]

	/* Configure and enable callback */
//! [run_callback]
	configure_rtc_callbacks();
//! [run_callback]

	/* Set period */
//! [period]
	rtc_count_set_period(&rtc_instance, 2000);
//! [period]
//! [run_initialize_rtc]

//! [while]
	while (true) {
		/* Infinite while loop */
	}
//! [while]
}
