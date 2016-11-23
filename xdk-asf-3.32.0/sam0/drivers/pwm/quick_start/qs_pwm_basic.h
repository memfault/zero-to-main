/**
 * \file
 *
 * \brief SAM PWM Driver Quick Start for SAMB11
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
 * \page asfdoc_samb_pwm_basic_use_case Quick Start Guide for PWM - Basic
 *
 * In this use case, the PWM module is configured for:
 *   \li 1 not to inverse the polarity
 *   \li Sample method 0
 *   \li PWM period is 4
 *   \li Duty cycle is 50%
 *   \li No use agcupdate
 *   \li Clock is 26MHz
 *   \li Output frequency is 25.4KHz
 *   \li Pinmux pad
 *
 * This use case sets up the PWM to configure the PWM output on a physical device
 * pin.
 *
 * \section asfdoc_samb_pwm_basic_use_case_setup Setup
 *
 * \subsection asfdoc_samb_pwm_basic_use_case_setup_prereq Prerequisites
 * There are no special setup requirements for this use-case.
 *
 * \subsection asfdoc_samb_pwm_basic_use_case_setup_code Code
 * Copy-paste the following setup code to your user application:
 * \snippet qs_pwm_basic.c setup
 *
 * Add to user application initialization (typically the start of \c main()):
 * \snippet qs_pwm_basic.c setup_init
 *
 * \subsection asfdoc_samb_pwm_basic_use_case_setup_flow Workflow
 * -# Create a PWM module pin configuration struct, which can be filled out to
 *    adjust the configuration of a single pwm.
 *    \snippet qs_pwm_basic.c setup_1
 * -# Initialize the pwm configuration struct with the module's default values.
 *    \snippet qs_pwm_basic.c setup_2
 *    \note This should always be performed before using the configuration
 *          struct to ensure that all values are initialized to known default
 *          settings.
 *
 * -# Adjust the configuration struct to request an output pin.
 *    \snippet qs_pwm_basic.c setup_3
 * -# Configure the PWM module with the desired settings.
 *    \snippet qs_pwm_basic.c setup_4
 * -# Enable the PWM module to start and begin PWM signal generation.
 *    \snippet qs_pwm_basic.c setup_5
 *
 * \section asfdoc_samb_pwm_basic_use_case_use_main Use Case
 *
 * \subsection asfdoc_samb_pwm_basic_use_case_code Code
 * Copy-paste the following code to your user application:
 * \snippet qs_pwm_basic.c main
 *
 * \subsection asfdoc_samb_pwm_basic_use_case_flow Workflow
 * -# Enter an infinite loop while the PWM wave is generated via the PWM module.
 *    \snippet qs_pwm_basic.c main
 */

