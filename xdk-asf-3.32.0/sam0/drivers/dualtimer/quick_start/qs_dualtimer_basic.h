/**
 * \file
 *
 * \brief SAM DUALTIMER Driver Quick Start for SAMB11
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
 * \page asfdoc_samb_dualtimer_basic_use_case Quick Start Guide for DUALTIMER - Basic
 *
 * In this use case, the DUALTIMER module is configured for two general downward timer.
 *
 * \section asfdoc_samb_dualtimer_basic_use_case_setup Setup
 *
 * \subsection asfdoc_samb_dualtimer_basic_use_case_setup_prereq Prerequisites
 * There are no special setup requirements for this use-case.
 *
 * \subsection asfdoc_samb_dualtimer_basic_use_case_setup_code Code
 * Copy-paste the following setup code to your user application:
 * \snippet qs_dualtimer_basic.c setup
 *
 * \subsection asfdoc_samb_dualtimer_basic_use_case_basic_callback Callback
 * -# Print the time1 trigger.
 *    \snippet qs_dualtimer_basic.c print_timer1
 *
 * -# Print the timer2 trigger.
 *    \snippet qs_dualtimer_basic.c print_timer2
 *
 * Add to user application initialization (typically the start of \c main()):
 * \snippet qs_dualtimer_basic.c setup_init
 *
 * \subsection asfdoc_samb_dualtimer_basic_use_case_setup_flow Workflow
 * -# Create a new function \c configure_uart(), which will be used to configure
 *    the UART peripheral.
 *    \snippet qs_dualtimer_basic.c config_uart
 *   -# Create a UART module instance struct.
 *    \snippet qs_dualtimer_basic.c module_inst
 *   -# Create a UART module configuration struct, which can be filled out to
 *      adjust the configuration of a physical UART peripheral.
 *    \snippet qs_dualtimer_basic.c setup_uart_1
 *   -# Initialize the UART configuration struct with the module's default values.
 *    \snippet qs_dualtimer_basic.c setup_uart_2
 *   -# Change configurations uart as desired.
 *    \snippet qs_dualtimer_basic.c setup_uart_3
 *   -# Change configurations uart as desired.
 *    \snippet qs_dualtimer_basic.c setup_uart_4
 *
 * -# Create a new function \c configure_dualtimer(), which will be used to configure
 *    the DUALTIMER peripheral.
 *    \snippet qs_dualtimer_basic.c config_dualtimer
 *   -# Create a DUALTIMER module configuration struct, which can be filled out to
 *    adjust the configuration of a physical DUALTIMER peripheral.
 *    \snippet qs_dualtimer_basic.c setup_dualtimer_1
 *   -# Initialize the DUALTIMER configuration struct with the module's default values.
 *    \snippet qs_dualtimer_basic.c setup_dualtimer_2
 *   -# Change configurations timer1 as desired.
 *    \snippet qs_dualtimer_basic.c setup_dualtimer_3
 *   -# Change configurations timer2 as desired.
 *    \snippet qs_dualtimer_basic.c setup_dualtimer_4
 *   -# Configure the DUALTIMER module with the desired settings.
 *    \snippet qs_dualtimer_basic.c setup_timer_5
 *
 * -# Create a new function \c configure_dualtimer_callback(), which will be used to configure
 *    the DUALTIMER callback.
 *    \snippet qs_dualtimer_basic.c config_callback
 *   -# Register dualtimer1 and dualtimer2 callback
 *    \snippet qs_dualtimer_basic.c setup_register_callback
 *   -# Enable callback
 *    \snippet qs_dualtimer_basic.c enable_IRQ
 *
 * \section asfdoc_samb_dualtimer_basic_use_case_basic_implement Implementation
 * Add the following to \c main().
 * \snippet qs_dualtimer_basic.c main_imp
 *
 * \subsection asfdoc_samb_dualtimer_basic_use_case_basic_workflow Workflow
 * -# Start an infinite loop, to get timer1/timer2 counter.
 *    \snippet qs_dualtimer_basic.c main_loop
 *
 */