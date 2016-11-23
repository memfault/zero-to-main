/**
 * \file
 *
 * \brief SAM RTC Calendar Callback Quick Start
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

void rtc_match_callback(void);
void configure_rtc_callbacks(void);
void configure_rtc_calendar(void);

//! [rtc_module_instance]
struct rtc_module rtc_instance;
//! [rtc_module_instance]

//! [alarm_struct]
struct rtc_calendar_alarm_time alarm;
//! [alarm_struct]

//! [callback]
void rtc_match_callback(void)
{
	/* Do something on RTC alarm match here */
	port_pin_toggle_output_level(LED_0_PIN);

	/* Set new alarm in 5 seconds */
	//! [alarm_mask]
	alarm.mask = RTC_CALENDAR_ALARM_MASK_SEC;
	//! [alarm_mask]

	//! [set_alarm]
	alarm.time.second += 5;
	alarm.time.second = alarm.time.second % 60;

	rtc_calendar_set_alarm(&rtc_instance, &alarm, RTC_CALENDAR_ALARM_0);
	//! [set_alarm]
}
//! [callback]

//! [setup_callback]
void configure_rtc_callbacks(void)
{
	//! [reg_callback]
	rtc_calendar_register_callback(
			&rtc_instance, rtc_match_callback, RTC_CALENDAR_CALLBACK_ALARM_0);
	//! [reg_callback]
	//! [en_callback]
	rtc_calendar_enable_callback(&rtc_instance, RTC_CALENDAR_CALLBACK_ALARM_0);
	//! [en_callback]
}
//! [setup_callback]

//! [initialize_rtc]
void configure_rtc_calendar(void)
{
	/* Initialize RTC in calendar mode. */
//! [init_conf]
	struct rtc_calendar_config config_rtc_calendar;
	rtc_calendar_get_config_defaults(&config_rtc_calendar);
//! [init_conf]

//! [time_struct]
	alarm.time.year      = 2013;
	alarm.time.month     = 1;
	alarm.time.day       = 1;
	alarm.time.hour      = 0;
	alarm.time.minute    = 0;
	alarm.time.second    = 4;
//! [time_struct]

//! [set_config]
	config_rtc_calendar.clock_24h = true;
	config_rtc_calendar.alarm[0].time = alarm.time;
	config_rtc_calendar.alarm[0].mask = RTC_CALENDAR_ALARM_MASK_YEAR;
//! [set_config]

//! [init_rtc]
	rtc_calendar_init(&rtc_instance, RTC, &config_rtc_calendar);
//! [init_rtc]

//! [enable]
	rtc_calendar_enable(&rtc_instance);
//! [enable]
}
//! [initialize_rtc]

int main(void)
{
//! [run_initialize_rtc]
//! [system_init]
	system_init();
//! [system_init]

//! [time]
	struct rtc_calendar_time time;
	rtc_calendar_get_time_defaults(&time);
	time.year   = 2012;
	time.month  = 12;
	time.day    = 31;
	time.hour   = 23;
	time.minute = 59;
	time.second = 59;
//! [time]

	/* Configure and enable RTC */
//! [run_conf]
	configure_rtc_calendar();
//! [run_conf]

	/* Configure and enable callback */
//! [run_callback]
	configure_rtc_callbacks();
//! [run_callback]

	/* Set current time. */
//! [set_time]
	rtc_calendar_set_time(&rtc_instance, &time);
//! [set_time]
//! [run_initialize_rtc]

//! [while]
//! [main_loop]
	while (true) {
//! [main_loop]
		/* Infinite loop */
	}
//! [while]
}
