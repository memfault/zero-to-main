/**
 * \file
 *
 * \brief SAM RTC Basic Usage Example
 *
 * Copyright (C) 2012-2015 Atmel Corporation. All rights reserved.
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

void configure_rtc_count(void);

//! [rtc_module_instance]
struct rtc_module rtc_instance;
//! [rtc_module_instance]

//! [initiate]
void configure_rtc_count(void)
{
//! [set_conf]
	struct rtc_count_config config_rtc_count;
//! [set_conf]

//! [get_default]
	rtc_count_get_config_defaults(&config_rtc_count);
//! [get_default]

//! [set_config]
	config_rtc_count.prescaler           = RTC_COUNT_PRESCALER_DIV_1;
	config_rtc_count.mode                = RTC_COUNT_MODE_16BIT;
#ifdef FEATURE_RTC_CONTINUOUSLY_UPDATED
	config_rtc_count.continuously_update = true;
#endif
	config_rtc_count.compare_values[0]   = 1000;
//! [set_config]
//! [init_rtc]
	rtc_count_init(&rtc_instance, RTC, &config_rtc_count);
//! [init_rtc]

//! [enable]
	rtc_count_enable(&rtc_instance);
//! [enable]
}
//! [initiate]

int main(void)
{
	/* Initialize system. Must configure conf_clocks.h first. */
//! [system]
	system_init();
//! [system]

//! [add_main]
	configure_rtc_count();
//! [add_main]

//! [implementation_code]
//! [period]
	rtc_count_set_period(&rtc_instance, 2000);
//! [period]

//! [main_loop]
	while (true) {
//! [main_loop]
//! [check_match]
		if (rtc_count_is_compare_match(&rtc_instance, RTC_COUNT_COMPARE_0)) {
//! [check_match]
//! [compare_match_action]
			/* Do something on RTC count match here */
			port_pin_toggle_output_level(LED_0_PIN);
//! [compare_match_action]

//! [clear_compare_match]
			rtc_count_clear_compare_match(&rtc_instance, RTC_COUNT_COMPARE_0);
//! [clear_compare_match]
		}
	}
//! [implementation_code]

}
