/**
 * \file
 *
 * \brief SAM TIMER Driver Quick Start for SAMB11
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
 * \page asfdoc_samb_timer_basic_use_case Quick Start Guide for TIMER - Basic
 *
 * In this use case, the TIMER module is configured for general downward timer.
 * The TIMER module will be set up as follows:
 * - Disable external input as enable
 * - Disable external input as clock
 * - Enable interrupt
 *
 * \section asfdoc_samb_timer_basic_use_case_setup Setup
 *
 * \subsection asfdoc_samb_timer_basic_use_case_setup_prereq Prerequisites
 * There are no special setup requirements for this use-case.
 *
 * \subsection asfdoc_samb_timer_basic_use_case_setup_code Code
 * Copy-paste the following setup code to your user application:
 * \snippet qs_timer_basic.c setup
 *
 * Add to user application initialization (typically the start of \c main()):
 * \snippet qs_timer_basic.c setup_init
 *
 * \subsection asfdoc_samb_timer_basic_use_case_setup_flow Workflow
 * -# Create a new function \c configure_gpio_pins(), which will be used to configure
 *    the GPIO peripheral.
 *    \snippet qs_timer_basic.c config_gpio
 * -# Create a new function \c configure_timer(), which will be used to configure
 *    the TIMER peripheral.
 *    \snippet qs_timer_basic.c config_timer
 * -# Create a GPIO module pin configuration struct, which can be filled out to
 *    adjust the configuration of a single gpio pin.
 *    \snippet qs_timer_basic.c setup_gpio_1
 * -# Initialize the pin configuration struct with the module's default values.
 *    \snippet qs_timer_basic.c setup_gpio_2
 *
 * -# Adjust the configuration struct to request an output pin.
 *    \snippet qs_timer_basic.c setup_gpio_3
 * -# Configure LED pin with the initialized pin configuration struct, to enable
 *    the output driver on the pin.
 *    \snippet qs_timer_basic.c setup_gpio_4
 *
 * -# Create a TIMER module configuration struct, which can be filled out to
 *    adjust the configuration of a physical TIMER peripheral.
 *    \snippet qs_timer_basic.c setup_timer_1
 * -# Initialize the TIMER configuration struct with the module's default values.
 *    \snippet qs_timer_basic.c setup_timer_2
 *
 * -# Configure the TIMER module with the desired settings.
 *    \snippet qs_timer_basic.c setup_timer_3
 * -# Configure TIMER module with the initialized configuration struct.
 *    \snippet qs_timer_basic.c setup_timer_4
 *
 * -# Set the TIMER module enable.
 *    \snippet qs_timer_basic.c setup_timer_5
 *
 * \section asfdoc_samb_timer_basic_use_case_use_main Use Case
 *
 * \subsection asfdoc_samb_timer_basic_use_case_code Code
 * Copy-paste the following code to your user application:
 * \snippet qs_timer_basic.c main_loop
 *
 */