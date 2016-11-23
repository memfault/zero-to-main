/**
 * \file
 *
 * \brief SAM Watchdog Driver Quick Start
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

/**
 * \page asfdoc_sam0_wdt_basic_use_case Quick Start Guide for WDT - Basic
 *
 * In this use case, the Watchdog module is configured for:
 *  \li System reset after 2048 clocks of the Watchdog generic clock
 *  \li Always on mode disabled
 *  \li Basic mode, with no window or early warning periods
 *
 * This use case sets up the Watchdog to force a system reset after every 2048
 * clocks of the Watchdog's Generic Clock channel, unless the user periodically
 * resets the Watchdog counter via a button before the timer expires. If the
 * Watchdog resets the device, a LED on the board is turned off.
 *
 * \section asfdoc_sam0_wdt_basic_use_case_setup Setup
 *
 * \subsection asfdoc_sam0_wdt_basic_use_case_setup_prereq Prerequisites
 * There are no special setup requirements for this use-case.
 *
 * \subsection asfdoc_sam0_wdt_basic_use_case_setup_code Code
 * Copy-paste the following setup code to your user application:
 * \snippet qs_wdt_basic.c setup
 *
 * Add to user application initialization (typically the start of \c main()):
 * \snippet qs_wdt_basic.c setup_init
 *
 * \subsection asfdoc_sam0_wdt_basic_use_case_setup_flow Workflow
 * -# Create a Watchdog module configuration struct, which can be filled out to
 *    adjust the configuration of the Watchdog.
 *    \snippet qs_wdt_basic.c setup_1
 * -# Initialize the Watchdog configuration struct with the module's default
 *    values.
 *    \snippet qs_wdt_basic.c setup_2
 *    \note This should always be performed before using the configuration
 *          struct to ensure that all values are initialized to known default
 *          settings.
 *
 * -# Adjust the configuration struct to set the timeout period and lock mode
 *    of the Watchdog.
 *    \snippet qs_wdt_basic.c setup_3
 * -# Setups the WDT hardware module with the requested settings.
 *    \snippet qs_wdt_basic.c setup_4
 *
 * \section asfdoc_sam0_wdt_basic_use_case Use Case
 *
 * \subsection asfdoc_sam0_wdt_basic_use_case_code Code
 * Copy-paste the following code to your user application:
 * \snippet qs_wdt_basic.c main
 *
 * \subsection asfdoc_sam0_wdt_basic_use_case_main Workflow
 * -# Retrieve the cause of the system reset to determine if the Watchdog module
 *    was the cause of the last reset.
 *    \snippet qs_wdt_basic.c main_1
 * -# Turn on or off the board LED based on whether the Watchdog reset the device.
 *    \snippet qs_wdt_basic.c main_2
 * -# Enter an infinite loop to hold the main program logic.
 *    \snippet qs_wdt_basic.c main_3
 * -# Test to see if the board button is currently being pressed.
 *    \snippet qs_wdt_basic.c main_4
 * -# If the button is pressed, turn on the board LED and reset the Watchdog
 *    timer.
 *    \snippet qs_wdt_basic.c main_5
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
