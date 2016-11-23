/**
 * \file
 *
 * \brief SAM OPAMP Driver Quick Start
 *
 * Copyright (C) 2014-2015 Atmel Corporation. All rights reserved.
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
 * \page asfdoc_sam0_opamp_basic_use_case Quick Start Guide for OPAMP - Basic
 *
 * In this use case, the OPAMP0 is configured as "Non-Inverting PGA" mode,
 * refer to the second mode of "Built-in Modes" in the device datasheet.
 *
 * You can give a signal on OA0POS and watch the output on OA0OUT
 * through an oscilloscope.
 *
 * \section asfdoc_sam0_opamp_basic_use_case_setup Setup
 *
 * \subsection asfdoc_sam0_opamp_basic_use_case_setup_prereq Prerequisites
 * There are no special setup requirements for this use case.
 *
 * \subsection asfdoc_sam0_opamp_basic_use_case_setup_code Code
 * Copy-paste the following setup code to your user application:
 * \snippet qs_opamp_basic.c setup
 *
 * Add to user application initialization (typically the start of \c main()):
 * \snippet qs_opamp_basic.c setup_init
 *
 * \subsection asfdoc_sam0_opamp_basic_use_case_setup_flow Workflow
 * -# Create an OPAMP0 configuration struct, which can be filled out to
 *    adjust the configuration of OPAMP0.
 *    \snippet qs_opamp_basic.c setup_1
 *
 * -# Initialize the OPAMP module.
 *    \snippet qs_opamp_basic.c setup_2
 *
 * -# Initialize the OPAMP0 configuration struct with the module's default values.
 *    \snippet qs_opamp_basic.c setup_3
 *    \note This should always be performed before using the configuration
 *          struct to ensure that all values are initialized to known default
 *          settings.
 *
 * -# Adjust the configuration struct to set the OPAMP0 as "Non-Inverting PGA" mode.
 *    \snippet qs_opamp_basic.c setup_4
 *    \note The existing configuration struct may be re-used, as long as any
 *          values that have been altered from the default settings are taken
 *          into account by the user application.
 *
 * -# Set up OA0POS pin and OA0OUT pin.
 *    \snippet qs_opamp_basic.c setup_5
 *
 * -# Write OPAMP0 configuration to the hardware module.
 *    \snippet qs_opamp_basic.c setup_6
 *
 * -# Enable OPAMP0.
 *    \snippet qs_opamp_basic.c setup_7
 *
 * -# Wait for the output ready.
 *    \snippet qs_opamp_basic.c setup_8
 *
 * \section asfdoc_sam0_opamp_basic_use_case_use_main Use Case
 *
 * \subsection asfdoc_sam0_opamp_basic_use_case_code Code
 * Copy-paste the following code to your user application:
 * \snippet qs_opamp_basic.c main
 *
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
