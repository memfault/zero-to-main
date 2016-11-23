/**
 * \file
 *
 * \brief SAM TC - Timer Counter Callback Driver Quick Start
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

/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

/**
 * \page asfdoc_sam0_tc_callback_use_case Quick Start Guide for TC - Callback
 *
 * In this use case, the TC will be used to generate a PWM signal, with a
 * varying duty cycle. Here the pulse width is increased each time the timer
 * count matches the set compare value. The TC module will be set up as follows:
 *
 * - GCLK generator 0 (GCLK main) clock source
 * - 16-bit resolution on the counter
 * - No prescaler
 * - Normal PWM wave generation
 * - GCLK reload action
 * - Don't run in standby
 * - No inversion of waveform output
 * - No capture enabled
 * - Count upward
 * - Don't perform one-shot operations
 * - No event input enabled
 * - No event action
 * - No event generation enabled
 * - Counter starts on 0
 *
 * \section asfdoc_sam0_tc_callback_use_case_setup Quick Start
 *
 * \subsection asfdoc_sam0_tc_callback_use_case_prereq Prerequisites
 * There are no prerequisites for this use case.
 *
 * \subsection asfdoc_sam0_tc_callback_use_case_setup_code Code
 * Add to the main application source file, before any functions:
 * - SAM D21 Xplained Pro.
 *   \snippet samd21_xplained_pro/conf_quick_start_callback.h definition_pwm
 * - SAM D20 Xplained Pro.
 *   \snippet samd20_xplained_pro/conf_quick_start_callback.h definition_pwm
 * - SAM R21 Xplained Pro.
 *   \snippet samr21_xplained_pro/conf_quick_start_callback.h definition_pwm
 * - SAM D11 Xplained Pro.
 *   \snippet samd11_xplained_pro/conf_quick_start_callback.h definition_pwm
 * - SAM L21 Xplained Pro.
 *   \snippet saml21_xplained_pro/conf_quick_start_callback.h definition_pwm
 * - SAM L22 Xplained Pro.
 *   \snippet saml22_xplained_pro/conf_quick_start_callback.h definition_pwm
 * - SAM DA1 Xplained Pro.
 *   \snippet samda1_xplained_pro/conf_quick_start_callback.h definition_pwm
 * - SAM C21 Xplained Pro.
 *   \snippet samc21_xplained_pro/conf_quick_start_callback.h definition_pwm 
 *
 * Add to the main application source file, outside of any functions:
 * \snippet qs_tc_callback.c module_inst
 *
 * Copy-paste the following callback function code to your user application:
 * \snippet qs_tc_callback.c callback_funcs
 *
 * Copy-paste the following setup code to your user application:
 * \snippet qs_tc_callback.c setup
 *
 * Add to user application initialization (typically the start of \c main()):
 * \snippet qs_tc_callback.c setup_init
 *
 * \subsection asfdoc_sam0_tc_callback_use_case_setup_flow Workflow
 * -# Create a module software instance structure for the TC module to store
 *    the TC driver state while it is in use.
 *    \snippet qs_tc_callback.c module_inst
 *    \note This should never go out of scope as long as the module is in use.
 *          In most cases, this should be global.
 *
 * -# Configure the TC module.
 *  -# Create a TC module configuration struct, which can be filled out to
 *     adjust the configuration of a physical TC peripheral.
 *     \snippet qs_tc_callback.c setup_config
 *  -# Initialize the TC configuration struct with the module's default values.
 *     \snippet qs_tc_callback.c setup_config_defaults
 *     \note This should always be performed before using the configuration
 *           struct to ensure that all values are initialized to known default
 *           settings.
 *
 *  -# Alter the TC settings to configure the counter width, wave generation
 *     mode, and the compare channel 0 value.
 *     \snippet qs_tc_callback.c setup_change_config
 *  -# Alter the TC settings to configure the PWM output on a physical device
 *     pin.
 *     \snippet qs_tc_callback.c setup_change_config_pwm
 *  -# Configure the TC module with the desired settings.
 *     \snippet qs_tc_callback.c setup_set_config
 *  -# Enable the TC module to start the timer and begin PWM signal generation.
 *     \snippet qs_tc_callback.c setup_enable
 * -# Configure the TC callbacks.
 *  -# Register the Compare Channel 0 Match callback functions with the driver.
 *     \snippet qs_tc_callback.c setup_register_callback
 *  -# Enable the Compare Channel 0 Match callback so that it will be called by
 *     the driver when appropriate.
 *     \snippet qs_tc_callback.c setup_enable_callback
 *
 *
 * \section asfdoc_sam0_tc_callback_use_case_main Use Case
 *
 * \subsection asfdoc_sam0_tc_callback_use_case_main_code Code
 * Copy-paste the following code to your user application:
 * \snippet qs_tc_callback.c main
 *
 * \subsection asfdoc_sam0_tc_callback_use_case_main_flow Workflow
 * -# Enter an infinite loop while the PWM wave is generated via the TC module.
 *    \snippet qs_tc_callback.c main_loop
 */


#include <asf.h>
#include <conf_clocks.h>
