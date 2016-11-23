/**
 * \file
 *
 * \brief SAM CCL Driver Quick Start
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
 * \page asfdoc_sam0_ccl_basic_use_case Quick Start Guide for CCL - Basic
 *
 * In this use case, the LUT0 and LUT1 input source is configured as I/O pin.
 * The LUT0 and LUT1 pair is connected to internal sequential logic, which is configured
 * as D flip flop mode.
 *
 * \section asfdoc_sam0_ccl_basic_use_case_setup Setup
 *
 * \subsection asfdoc_sam0_ccl_basic_use_case_setup_prereq Prerequisites
 * There are no special setup requirements for this use-case.
 *
 * \subsection asfdoc_sam0_ccl_basic_use_case_setup_code Code
 * Copy-paste the following setup code to your user application:
 * \snippet qs_ccl_basic.c setup
 *
 * Add to user application initialization (typically the start of \c main()):
 * \snippet qs_ccl_basic.c setup_init
 * \snippet qs_ccl_basic.c setup_enable
 *
 * \subsection asfdoc_sam0_ccl_basic_use_case_setup_flow Workflow
 * -# Creates a CCL configuration struct, which can be filled out to
 *    adjust the configuration of CCL.
 *    \snippet qs_ccl_basic.c setup_1
 *
 * -# Settings and fill the CCL configuration struct with the default settings.
 *    \snippet qs_ccl_basic.c setup_2
 *
 * -# Initializes CCL module.
 *    \snippet qs_ccl_basic.c setup_3
 *
 * -# Creates a LUT configuration struct, which can be filled out to
 *    adjust the configuration of LUT0.
 *    \snippet qs_ccl_basic.c setup_4
 *
  * -# Fill the LUT0 configuration struct with the default settings.
 *    \snippet qs_ccl_basic.c setup_5
 *
 * -# Adjust the LUT0 configuration struct.
 *    \snippet qs_ccl_basic.c setup_6
 *
 * -# Set up LUT0 input and output pin.
 *    \snippet qs_ccl_basic.c setup_7
 *
 * -# Writes LUT0 configuration to the hardware module.
 *    \snippet qs_ccl_basic.c setup_8
 *
 * -# Creates a LUT configuration struct, which can be filled out to
 *    adjust the configuration of LUT1.
 *    \snippet qs_ccl_basic.c setup_9
 *
  * -# Fill the LUT1 configuration struct with the default settings.
 *    \snippet qs_ccl_basic.c setup_10
 *
 * -# Adjust the LUT1 configuration struct.
 *    \snippet qs_ccl_basic.c setup_11
 *
 * -# Set up LUT1 input and output pin.
 *    \snippet qs_ccl_basic.c setup_12
 *
 * -# Writes LUT1 configuration to the hardware module.
 *    \snippet qs_ccl_basic.c setup_13
 *
 * -# Configure the sequential logic with the D flip flop mode.
 *    \snippet qs_ccl_basic.c setup_14
 *
 * \section asfdoc_sam0_ccl_basic_use_case_use_main Use Case
 *
 * \subsection asfdoc_sam0_ccl_basic_use_case_code Code
 * Copy-paste the following code to your user application:
 * \snippet qs_ccl_basic.c main
 *
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
