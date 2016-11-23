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

/**
 * \page asfdoc_sam0_rtc_calendar_callback_use_case Quick Start Guide for RTC (CAL) - Callback
 * In this use case, the RTC is set up in calendar mode. The time is set and an
 * alarm is enabled, as well as a callback for when the alarm time is hit. Each
 * time the callback fires, the alarm time is reset to five seconds in the future
 * and the board LED toggled.
 *
 * \section asfdoc_sam0_rtc_calendar_callback_use_case_prereq Prerequisites
 * The Generic Clock Generator for the RTC should be configured and enabled; if
 * you are using the System Clock driver, this may be done via \c conf_clocks.h.
 *
 * \subsection asfdoc_sam0_rtc_calendar_callback_use_case_setup_clocks Clocks and Oscillators
 * The \c conf_clock.h file needs to be changed with the following values to
 * configure the clocks and oscillators for the module.
 *
 * The following oscillator settings are needed:
 * \snippet conf_clocks.h oscillator_settings
 * The following generic clock settings are needed:
 * \snippet conf_clocks.h gclk_settings
 *
 * \section asfdoc_sam0_rtc_calendar_callback_use_case_setup Setup
 *
 * \subsection asfdoc_sam0_rtc_calendar_callback_use_case_setup_code Code
 * Create an rtc_module struct and add to the main application source file,
 * outside of any functions:
 * \snippet qs_rtc_calendar_callback.c rtc_module_instance
 *
 * The following must be added to the user application:
 *
 * Function for setting up the module:
 * \snippet qs_rtc_calendar_callback.c initialize_rtc
 *
 * Callback function:
 * \snippet qs_rtc_calendar_callback.c callback
 *
 * Function for setting up the callback functionality of the driver:
 * \snippet qs_rtc_calendar_callback.c setup_callback
*
 * Add to user application \c main():
 * \snippet qs_rtc_calendar_callback.c run_initialize_rtc
 *
 * \subsection asfdoc_sam0_rtc_calendar_callback_use_case_setup_workflow Workflow
 * -# Initialize system.
 *    \snippet qs_rtc_calendar_callback.c system_init
 * -# Create and initialize a time structure.
 *    \snippet qs_rtc_calendar_callback.c time
 * -# Configure and enable module.
 *    \snippet qs_rtc_calendar_callback.c run_conf
 *  -# Create an RTC configuration structure to hold the desired RTC driver
 *     settings and fill it with the default driver configuration values.
 *     \snippet qs_rtc_calendar_callback.c init_conf
 *     \note This should always be performed before using the configuration
 *           struct to ensure that all values are initialized to known default
 *           settings.
 *
 *  -# Create and initialize an alarm.
 *     \snippet qs_rtc_calendar_callback.c time_struct
 *  -# Change settings in the configuration and set alarm.
 *     \snippet qs_rtc_calendar_callback.c set_config
 *  -# Initialize the module with the set configurations.
 *     \snippet qs_rtc_calendar_callback.c init_rtc
 *  -# Enable the module.
 *     \snippet qs_rtc_calendar_callback.c enable
 * -# Configure callback functionality.
 *    \snippet qs_rtc_calendar_callback.c run_callback
 *  -# Register overflow callback.
 *     \snippet qs_rtc_calendar_callback.c reg_callback
 *  -# Enable overflow callback.
 *     \snippet qs_rtc_calendar_callback.c en_callback
 * -# Set time of the RTC calendar.
 *    \snippet qs_rtc_calendar_callback.c set_time
 *
 * \section asfdoc_sam0_rtc_calendar_callback_use_case_implementation Implementation
 * \subsection asfdoc_sam0_rtc_calendar_callback_use_case_implementation_code Code
 * Add to user application main:
 * \snippet qs_rtc_calendar_callback.c while
 * \subsection asfdoc_sam0_rtc_calendar_callback_use_case_implementation_workflow Workflow
 * -# Infinite while loop while waiting for callbacks.
 *    \snippet qs_rtc_calendar_callback.c main_loop
 *
 * \section asfdoc_sam0_rtc_calendar_callback_use_case_callback Callback
 * Each time the RTC time matches the configured alarm, the callback function
 * will be called.
 * \subsection asfdoc_sam0_rtc_calendar_callback_use_case_callback_workflow Workflow
 * -# Create alarm struct and initialize the time with current time.
 *    \snippet qs_rtc_calendar_callback.c alarm_struct
 * -# Set alarm to trigger on seconds only.
 *    \snippet qs_rtc_calendar_callback.c alarm_mask
 * -# Add one second to the current time and set new alarm.
 *    \snippet qs_rtc_calendar_callback.c set_alarm
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

