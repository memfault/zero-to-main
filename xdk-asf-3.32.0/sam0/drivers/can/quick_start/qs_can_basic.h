/**
 * \file
 *
 * \brief SAM CAN basic Quick Start
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
 * \page asfdoc_sam0_can_basic_use_case Quick Start Guide for CAN normal mode
 *
 * The supported board list:
 *    - SAMC21 Xplained Pro
 *
 * This quick start need two SAMC21 Xplained Pro boards with CAN interface
 * connected by the jump wire: CANH - CANH and CANL - CANL.
 *
 * It show how to handle standard message in a normal CAN network
 * with filter setting, message sending, receive buffer and FIFO usage and
 * interrupt handling.
 *
 * User can choose to set up two standard filter id and two extended filter id
 * as receive filter.
 * And then user can choose to send messages with the standard or
 * extended filter id.
 * If the message has been received, it will print the received data on the
 * console.
 * The configuration is defined in conf_can.h file with message max data
 * length 8 and baudrate 500KHz.
 *
 * \section asfdoc_sam0_can_basic_use_case_setup Setup
 *
 * \subsection asfdoc_sam0_can_basic_use_case_prereq Prerequisites
 * There are no special setup requirements for this use-case.
 *
 * \subsection asfdoc_sam0_can_basic_use_case_setup_code Code
 * Add to the main application source file, outside of any functions:
 * \snippet qs_can_basic.c module_var
 *
 * Copy-paste the following setup code to your user application:
 * \snippet qs_can_basic.c setup
 *
 * Add to user application initialization (typically the start of \c main()):
 * \snippet qs_can_basic.c setup_init
 *
 * \subsection asfdoc_sam0_can_basic_use_case_setup_flow Workflow
 * -# Create USART CDC module and CAN module software instance structure.
 *    \snippet qs_can_basic.c module_inst
 *
 * -# Define CAN standard filter setting.
 *    \snippet qs_can_basic.c can_filter_setting
 *
 * -# Define CAN standard transfer message setting.
 *    \snippet qs_can_basic.c can_transfer_message_setting
 *
 * -# Define CAN standard receive message setting.
 *    \snippet qs_can_basic.c can_receive_message_setting
 *
 * -# Configure the USART CDC for output message.
 *     \snippet qs_can_basic.c cdc_setup
 *
 * -# Configure the CAN module.
 *     \snippet qs_can_basic.c can_init_setup
 *
 * -# Configure the CAN standard receive filter.
 *     \snippet qs_can_basic.c can_receive_filter_setup
 *
 * -# Configure the CAN transfer message.
 *     \snippet qs_can_basic.c can_transfer_message_setup
 *
 * -# Implement the interrupt handler function.
 *     \snippet qs_can_basic.c can_interrupt_handler
 *
 * -# User menu function.
 *     \snippet qs_can_basic.c user_menu
 *
 * \section asfdoc_sam0_can_basic_use_case_main Use Case
 *
 * \subsection asfdoc_sam0_can_basic_use_case_main_code Code
 * Copy-paste the following code to your user application:
 * \snippet qs_can_basic.c main_setup
 *
 * \subsection asfdoc_sam0_can_basic_use_case_main_flow Workflow
 * -# Set up CAN module.
 *     \snippet qs_can_basic.c configure_can
 * -# Display user menu .
 *     \snippet qs_can_basic.c display_user_menu
 * -# Enter the main loop, wait for the user input .
 *     \snippet qs_can_basic.c main_loop
 */
