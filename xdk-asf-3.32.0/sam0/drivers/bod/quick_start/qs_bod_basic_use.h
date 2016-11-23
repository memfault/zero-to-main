/**
 * \file
 *
 * \brief SAM BOD Driver Quick Start
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
 */

/**
 * \page asfdoc_sam0_bod_basic_use_case Quick Start Guide for BOD - Basic
 *
 * In this use case, the BOD33 will be configured with the following settings:
 * - Continuous sampling mode
 * - Prescaler setting of two
 * - Reset action on low voltage detect
 *
 * \section asfdoc_sam0_bod_basic_use_case_setup Quick Start
 *
 * \subsection asfdoc_sam0_bod_basic_use_case_prereq Prerequisites
 * There are no special setup requirements for this use-case.
 *
 * \subsection asfdoc_sam0_bod_basic_use_case_setup_code Code
 * Copy-paste the following setup code to your user application:
 * \snippet qs_bod_basic_use.c setup
 *
 * Add to user application initialization (typically the start of \c main()):
 * \snippet qs_bod_basic_use.c setup_init
 *
 * \subsection asfdoc_sam0_bod_basic_use_case_setup_flow Workflow
 * -# Create a BOD module configuration struct, which can be filled out to
 *    adjust the configuration of a physical BOD peripheral.
 *    \snippet qs_bod_basic_use.c setup_config
 * -# Initialize the BOD configuration struct with the module's default values.
 *    \snippet qs_bod_basic_use.c setup_config_defaults
 *    \note This should always be performed before using the configuration
 *          struct to ensure that all values are initialized to known default
 *          settings.
 *
 * -# Configure the BOD module with the desired settings.
 *    \snippet qs_bod_basic_use.c setup_set_config
 * -# Enable the BOD module so that it will monitor the power supply voltage.
 *    \snippet qs_bod_basic_use.c setup_enable
 *
 *
 * \section asfdoc_sam0_bod_basic_use_case_main Use Case
 *
 * \subsection asfdoc_sam0_bod_basic_use_case_main_code Code
 * Copy-paste the following code to your user application:
 * \snippet qs_bod_basic_use.c main
 *
 * \subsection asfdoc_sam0_bod_basic_use_case_main_flow Workflow
 * -# Enter an infinite loop so that the BOD can continue to monitor the supply
 *    voltage level.
 *    \snippet qs_bod_basic_use.c main_loop
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
