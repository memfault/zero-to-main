/**
 * \file
 *
 * \brief SAM True Random Number Generator Driver Quick Start
 *
 * Copyright (C) 2014-2016 Atmel Corporation. All rights reserved.
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
 * \page asfdoc_sam0_trng_basic_use_case Quick Start Guide for TRNG - Basic
 *
 * In this use case, the True Random Number Generator (TRNG) module is configured for:
 *  \li The TRNG peripheral will not be stopped in standby sleep mode
 *
 * This use case will read random data in polling mode repeatedly. After reading
 * a data, the board LED will be toggled.
 *
 * \section asfdoc_sam0_trng_basic_use_case_setup Setup
 *
 * \subsection asfdoc_sam0_trng_basic_use_case_setup_prereq Prerequisites
 * There are no special setup requirements for this use-case.
 *
 * \subsection asfdoc_sam0_trng_basic_use_case_setup_code Code
 * Copy-paste the following setup code to your user application:
 * \snippet qs_trng_basic.c setup
 *
 * Add to user application initialization (typically the start of \c main()):
 * \snippet qs_trng_basic.c setup_init
 *
 * \subsection asfdoc_sam0_trng_basic_use_case_setup_flow Workflow
 * -# Create a TRNG device instance struct, which will be associated with a
 *    TRNG peripheral hardware instance.
 *    \snippet qs_trng_basic.c setup_1
 *    \note Device instance structures shall \b never go out of scope when in
 *          use.
 *
 * -# Create a new function \c configure_trng(), which will be used to configure
 *    the overall TRNG peripheral.
 *    \snippet qs_trng_basic.c setup_2
 * -# Create a TRNG peripheral configuration structure that will
 *    be filled out to set the module configuration.
 *    \snippet qs_trng_basic.c setup_2_1
 * -# Fill the TRNG peripheral configuration structure with the
 *    default module configuration values.
 *    \snippet qs_trng_basic.c setup_2_2
 * -# Initialize the TRNG peripheral and associate it with the
 *    software instance structure that was defined previously.
 *    \snippet qs_trng_basic.c setup_2_3
 *
 * -# Enable the now initialized TRNG peripheral.
 *    \snippet qs_trng_basic.c setup_init_1
 *
 * \section asfdoc_sam0_trng_basic_use_case_imp Implementation
 *
 * \subsection asfdoc_sam0_trng_basic_use_case_imp_code Code
 * Copy-paste the following code to your user application:
 * \snippet qs_trng_basic.c main
 *
 * \subsection asfdoc_sam0_trng_basic_use_case_imp_flow Workflow
 * -# Make the application loop infinitely.
 *    \snippet qs_trng_basic.c main_1
 * -# Start to read a random data from TRNG until success.
 *    \snippet qs_trng_basic.c main_2
 * -# Toggle the board LED to indicate a random data is read.
 *    \snippet qs_trng_basic.c main_3
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
