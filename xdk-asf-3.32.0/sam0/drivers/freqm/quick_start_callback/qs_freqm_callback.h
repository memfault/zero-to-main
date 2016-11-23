/**
 * \file
 *
 * \brief SAM Frequency Meter Driver Quick Start
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
 * \page asfdoc_sam0_freqm_basic_use_case_callback Quick Start Guide for FREQM - Callback
 *
 * In this use case, the Frequency Meter (FREQM) module is configured for:
 *  \li The FREQM peripheral will not be stopped in standby sleep mode.
 *
 * This use case will read measurement data in interrupt mode repeatly. After reading
 * specific size of buffer data, the board LED will be toggled.
 *
 * \section asfdoc_sam0_freqm_callback_use_case_setup Setup
 *
 * \subsection asfdoc_sam0_freqm_callback_use_case_setup_prereq Prerequisites
 * There are no special setup requirements for this use-case.
 *
 * \subsection asfdoc_sam0_freqm_callback_use_case_setup_code Code
 * Copy-paste the following setup code to your user application:
 * \snippet qs_freqm_callback.c setup
 *
 * Add to user application initialization (typically the start of \c main()):
 * \snippet qs_freqm_callback.c setup_init
 *
 * \subsection asfdoc_sam0_freqm_callback_use_case_setup_flow Workflow
 * -# Create an FREQM device instance struct, which will be associated with an
 *    FREQM peripheral hardware instance.
 *    \snippet qs_freqm_callback.c setup_1
 *    \note Device instance structures shall \b never go out of scope when in
 *          use.
 *
 * -# Create a new function \c configure_freqm(), which will be used to configure
 *    the overall FREQM peripheral.
 *    \snippet qs_freqm_callback.c setup_2
 * -# Create an FREQM peripheral configuration structure that will
 *    be filled out to set the module configuration.
 *    \snippet qs_freqm_callback.c setup_2_1
 * -# Fill the FREQM peripheral configuration structure with the
 *    default module configuration values.
 *    \snippet qs_freqm_callback.c setup_2_2
 * -# Initialize the FREQM peripheral and associate it with the
 *    software instance structure that was defined previously.
 *    \snippet qs_freqm_callback.c setup_2_3
 *
 * -# Create a new callback function.
 *    \snippet qs_freqm_callback.c callback_1
 * -# Create a callback status software flag.
 *    \snippet qs_freqm_callback.c callback_2
 * -# Let the callback function set the flag to true when read job done.
 *    \snippet qs_freqm_callback.c callback_1_1
 *
 * -# Create a new function \c configure_freqm_callback(), which will be used to
 *    configure the callbacks.
 *    \snippet qs_freqm_callback.c setup_3
 * -# Register callback function.
 *    \snippet qs_freqm_callback.c setup_3_1
 * -# Enable the callbacks.
 *    \snippet qs_freqm_callback.c setup_3_2
 *
 * -# Enable the now initialized FREQM peripheral.
 *    \snippet qs_freqm_callback.c setup_init_1
 *    \note This should not be done until after the FREQM is setup and ready
 *       to be used.
 *
 * \section asfdoc_sam0_freqm_callback_use_case_imp Implementation
 *
 * \subsection asfdoc_sam0_freqm_callback_use_case_imp_code Code
 * Copy-paste the following code to your user application:
 * \snippet qs_freqm_callback.c main
 *
 * \subsection asfdoc_sam0_freqm_callback_use_case_imp_flow Workflow
 * -# Start an asynchronous FREQM read job, to store measurement data into the
 *     global buffer and generate a callback when complete.
 *    \snippet qs_freqm_callback.c main_1
 * -# Wait until the asynchronous read job is complete.
 *    \snippet qs_freqm_callback.c main_2
 * -# The board LED on to indicate measurement data read.
 *    \snippet qs_freqm_callback.c main_3
 * -# The board LED toggled to indicate measurement overflow occous.
 *    \snippet qs_freqm_callback.c main_4
 */
