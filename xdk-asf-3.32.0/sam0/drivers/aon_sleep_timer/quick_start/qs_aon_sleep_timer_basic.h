/**
 * \file
 *
 * \brief SAM AON Sleep Timer Driver Quick Start for SAMB11
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

/**
 * \page asfdoc_samb_aon_sleep_timer_basic_use_case Quick Start Guide for AON Sleep Timer - Basic
 *
 * In this use case, the AON Sleep Timer module is configured for wakeup MCU.
 *
 * \section asfdoc_samb_aon_sleep_timer_basic_use_case_setup Setup
 *
 * \subsection asfdoc_samb_aon_sleep_timer_basic_use_case_setup_prereq Prerequisites
 * There are no special setup requirements for this use-case.
 *
 * \subsection asfdoc_samb_aon_sleep_timer_basic_use_case_setup_code Code
 * Copy-paste the following setup code to your user application:
 * \snippet qs_aon_sleep_timer_basic.c setup
 *
 * Add to user application initialization (typically the start of \c main()):
 * \snippet qs_aon_sleep_timer_basic.c setup_init
 *
 * \subsection asfdoc_samb_aon_sleep_timer_basic_use_case_setup_flow Workflow
 * -# Create a new function \c configure_gpio_pins(), which will be used to configure
 *    the GPIO peripheral.
 *    \snippet qs_aon_sleep_timer_basic.c config_gpio
 *
 *   -# Create a GPIO module configuration struct, which can be filled out to
 *      adjust the configuration of a physical GPIO peripheral.
 *    \snippet qs_aon_sleep_timer_basic.c setup_1
 *   -# Initialize the GPIO configuration struct with the module's default values.
 *    \snippet qs_aon_sleep_timer_basic.c setup_2
 *
 *   -# Configure the GPIO module with the desired settings.
 *    \snippet qs_aon_sleep_timer_basic.c setup_3
 *
 *   -# Set the GPIO module enable.
 *    \snippet qs_aon_sleep_timer_basic.c setup_4
 *
 *   -# Set the LED on.
 *    \snippet qs_aon_sleep_timer_basic.c setup_5
 *
 * -# Create a new function \c configure_aon_sleep_timer(), which will be used to configure
 *    the AON Sleep Timer peripheral.
 *    \snippet qs_aon_sleep_timer_basic.c config_timer
 *
 *   -# Create a AON Sleep Timer module configuration struct, which can be filled out to
 *      adjust the configuration of a physical  AON Sleep Timer peripheral.
 *    \snippet qs_aon_sleep_timer_basic.c setup_6
 *
 *   -# Initialize the  AON Sleep Timer configuration struct with the module's default values.
 *    \snippet qs_aon_sleep_timer_basic.c setup_7
 *
 *   -# Configure the AON Sleep Timer module with the desired settings.
 *    \snippet qs_aon_sleep_timer_basic.c setup_8
 *
 *   -# Initialize and enable the AON Sleep Timer module.
 *    \snippet qs_aon_sleep_timer_basic.c setup_9
 *
 *   -# Enable the AON Sleep Timer interrupt.
 *    \snippet qs_aon_sleep_timer_basic.c setup_10
 *
 * -# Waiting for the AON Sleep Timer module active.
 *    \snippet qs_aon_sleep_timer_basic.c timer_active
 *
 * -# Waiting for the AON Sleep Timer interrupt.
 *    \snippet qs_aon_sleep_timer_basic.c wait_wfi
 *
 *
 * \section asfdoc_samb_aon_sleep_timer_basic_use_case_basic_implement Implementation
 * Add the following to \c main().
 * \snippet qs_aon_sleep_timer_basic.c main_imp
 *
 * \subsection asfdoc_samb_aon_sleep_timer_basic_use_case_basic_workflow Workflow
 * -# Start an infinite loop.
 *    \snippet qs_aon_sleep_timer_basic.c main_loop
 *
 */