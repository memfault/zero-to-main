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

void configure_rtc_calendar(void);

//! [rtc_module_instance]
struct rtc_module rtc_instance;
//! [rtc_module_instance]

//! [initiate]
void configure_rtc_calendar(void)
{
	/* Initialize RTC in calendar mode. */
//! [set_conf]
	struct rtc_calendar_config config_rtc_calendar;
//! [set_conf]
//! [get_default]
	rtc_calendar_get_config_defaults(&config_rtc_calendar);
//! [get_default]

//! [time_struct]
	struct rtc_calendar_time alarm;
	rtc_calendar_get_time_defaults(&alarm);
	alarm.year   = 2013;
	alarm.month  = 1;
	alarm.day    = 1;
	alarm.hour   = 0;
	alarm.minute = 0;
	alarm.second = 4;
//! [time_struct]

//! [set_config]
	config_rtc_calendar.clock_24h     = true;
	config_rtc_calendar.alarm[0].time = alarm;
	config_rtc_calendar.alarm[0].mask = RTC_CALENDAR_ALARM_MASK_YEAR;
//! [set_config]

//! [init_rtc]
	rtc_calendar_init(&rtc_instance, RTC, &config_rtc_calendar);
//! [init_rtc]

//! [enable]
	rtc_calendar_enable(&rtc_instance);
//! [enable]
}
//! [initiate]

int main(void)
{
//! [add_main]
	system_init();

	struct rtc_calendar_time time;
	time.year   = 2012;
	time.month  = 12;
	time.day    = 31;
	time.hour   = 23;
	time.minute = 59;
	time.second = 59;

	configure_rtc_calendar();

	/* Set current time. */
	rtc_calendar_set_time(&rtc_instance, &time);

	rtc_calendar_swap_time_mode(&rtc_instance);
//! [add_main]

//! [main_imp]
//! [main_loop]
	while (true) {
//! [main_loop]
//! [check_alarm_match]
		if (rtc_calendar_is_alarm_match(&rtc_instance, RTC_CALENDAR_ALARM_0)) {
//! [check_alarm_match]
//! [alarm_match_action]
			/* Do something on RTC alarm match here */
			port_pin_toggle_output_level(LED_0_PIN);
//! [alarm_match_action]

//! [clear_alarm_match]
			rtc_calendar_clear_alarm_match(&rtc_instance, RTC_CALENDAR_ALARM_0);
//! [clear_alarm_match]
		}
	}
//! [main_imp]
}
