/**
 * \file
 *
 * \brief SAM External Interrupt Driver Quick Start
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
 * \page asfdoc_sam0_extint_basic_use_case Quick Start Guide for EXTINT - Basic
 *
 * The supported board list:
 *    - SAM D20 Xplained Pro
 *    - SAM D21 Xplained Pro
 *    - SAM R21 Xplained Pro
 *    - SAM L21 Xplained Pro
 *    - SAM L22 Xplained Pro
 *    - SAM DA1 Xplained Pro
 *    - SAM C21 Xplained Pro
 *
 * In this use case, the EXTINT module is configured for:
 *  - External interrupt channel connected to the board LED is used
 *  - External interrupt channel is configured to detect both input signal edges
 *
 * This use case configures a physical I/O pin of the device so that it is
 * routed to a logical External Interrupt Controller channel to detect rising
 * and falling edges of the incoming signal.
 *
 * When the board button is pressed, the board LED will light up. When the board
 * button is released, the LED will turn off.
 *
 *
 * \section asfdoc_sam0_extint_basic_use_case_setup Setup
 *
 * \subsection asfdoc_sam0_extint_basic_use_case_setup_prereq Prerequisites
 * There are no special setup requirements for this use-case.
 *
 * \subsection asfdoc_sam0_extint_basic_use_case_setup_code Code
 * Copy-paste the following setup code to your user application:
 * \snippet qs_extint_basic.c setup
 *
 * Add to user application initialization (typically the start of \c main()):
 * \snippet qs_extint_basic.c setup_init
 *
 * \subsection asfdoc_sam0_extint_basic_use_case_setup_flow Workflow
 * -# Create an EXTINT module channel configuration struct, which can be filled
 *    out to adjust the configuration of a single external interrupt channel.
 *    \snippet qs_extint_basic.c setup_1
 * -# Initialize the channel configuration struct with the module's default
 *    values.
 *    \snippet qs_extint_basic.c setup_2
 *    \note This should always be performed before using the configuration
 *          struct to ensure that all values are initialized to known default
 *          settings.
 *
 * -# Adjust the configuration struct to configure the pin MUX (to route the
 *    desired physical pin to the logical channel) to the board button, and to
 *    configure the channel to detect both rising and falling edges.
 *    \snippet qs_extint_basic.c setup_3
 * -# Configure external interrupt channel with the desired channel settings.
 *    \snippet qs_extint_basic.c setup_4
 *
 *
 * \section asfdoc_sam0_extint_basic_use_case_main Use Case
 *
 * \subsection asfdoc_sam0_extint_basic_use_case_main_code Code
 * Copy-paste the following code to your user application:
 * \snippet qs_extint_basic.c main
 *
 * \subsection asfdoc_sam0_extint_basic_use_case_main_flow Workflow
 * -# Read in the current external interrupt channel state to see if an edge
 *    has been detected.
 *    \snippet qs_extint_basic.c main_1
 * -# Read in the new physical button state and mirror it on the board LED.
 *    \snippet qs_extint_basic.c main_2
 * -# Clear the detection state of the external interrupt channel so that it
 *    is ready to detect a future falling edge.
 *    \snippet qs_extint_basic.c main_3
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
