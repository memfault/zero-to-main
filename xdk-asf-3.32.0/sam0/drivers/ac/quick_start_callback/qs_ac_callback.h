/**
 * \file
 *
 * \brief SAM Analog Comparator Driver Quick Start
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
 * \page asfdoc_sam0_ac_callback_use_case Quick Start Guide for AC - Callback
 *
 * In this use case, the Analog Comparator module is configured for:
 *  \li Comparator peripheral in manually triggered (e.g. "Single Shot" mode)
 *  \li One comparator channel connected to input MUX pin 0 and compared to a
 *      scaled V<SUB>CC</SUB>/2 voltage
 *
 * This use case sets up the Analog Comparator to compare an input voltage fed
 * into a GPIO pin of the device against a scaled voltage of the
 * microcontroller's V<SUB>CC</SUB> power rail. The comparisons are made on-demand in
 * single-shot mode, and the result stored into a local variable which is then
 * output to the board LED to visually show the comparison state.
 *
 * \section asfdoc_sam0_ac_callback_use_case_setup Setup
 *
 * \subsection asfdoc_sam0_ac_callback_use_case_setup_prereq Prerequisites
 * There are no special setup requirements for this use-case.
 *
 * \subsection asfdoc_sam0_ac_callback_use_case_setup_code Code
 * Copy-paste the following setup code to your user application:
 * \snippet qs_ac_callback.c setup
 *
 * Add to user application initialization (typically the start of \c main()):
 * \snippet qs_ac_callback.c setup_init
 *
 * \subsection asfdoc_sam0_ac_callback_use_case_setup_flow Workflow
 * -# Create an AC device instance struct, which will be associated with an
 *    Analog Comparator peripheral hardware instance.
 *    \snippet qs_ac_callback.c setup_1
 *    \note Device instance structures shall \i never go out of scope when in
 *          use.
 *
 * -# Define a macro to select the comparator channel that will be sampled, for
 *    convenience.
 *    \snippet qs_ac_callback.c setup_2
 * -# Create a new function \c configure_ac(), which will be used to configure
 *    the overall Analog Comparator peripheral.
 *    \snippet qs_ac_callback.c setup_3
 * -# Create an Analog Comparator peripheral configuration structure that will
 *    be filled out to set the module configuration.
 *    \snippet qs_ac_callback.c setup_4
 * -# Fill the Analog Comparator peripheral configuration structure with the
 *    default module configuration values.
 *    \snippet qs_ac_callback.c setup_5
 * -# Initialize the Analog Comparator peripheral and associate it with the
 *    software instance structure that was defined previously.
 *    \snippet qs_ac_callback.c setup_6
 *
 * -# Create a new function \c configure_ac_channel(), which will be used to
 *    configure the overall Analog Comparator peripheral.
 *    \snippet qs_ac_callback.c setup_7
 * -# Create an Analog Comparator channel configuration structure that will
 *    be filled out to set the channel configuration.
 *    \snippet qs_ac_callback.c setup_8
 * -# Fill the Analog Comparator channel configuration structure with the
 *    default channel configuration values.
 *    \snippet qs_ac_callback.c setup_9
 * -# Alter the channel configuration parameters to set the channel to one-shot
 *    mode, with the correct negative and positive MUX selections and the
 *    desired voltage scaler.
 *    \note The voltage scalar formula is documented in description for
 *          \ref ac_chan_config "ac_chan_config::vcc_scale_factor".
 * -# Select when the interrupt should occur. In this case an interrupt will occur
 *    at every finished conversion.
 *    \snippet qs_ac_callback.c setup_10
 *
 * -# Configure the physical pin that will be routed to the AC module channel 0.
 *    \snippet qs_ac_callback.c setup_11
 *
 * -# Initialize the Analog Comparator channel and configure it with the desired
 *    settings.
 *    \snippet qs_ac_callback.c setup_12
 * -# Enable the initialized Analog Comparator channel.
 *    \snippet qs_ac_callback.c setup_13
 *
 * -# Create a new callback function.
 *    \snippet qs_ac_callback.c callback_1
 * -# Create a callback status software flag.
 *    \snippet qs_ac_callback.c callback_3
 * -# Let the callback function set the calback_status flag to true.
 *    \snippet qs_ac_callback.c callback_2
 *
 * -# Create a new function \c configure_ac_callback(), which will be used to
 *    configure the callbacks.
 *    \snippet qs_ac_callback.c setup_14
 * -# Register callback function.
 *    \snippet qs_ac_callback.c setup_15
 * -# Enable the callbacks.
 *    \snippet qs_ac_callback.c setup_16
 *
 * -# Enable the now initialized Analog Comparator peripheral.
 *    \snippet qs_ac_callback.c setup_17
 *    \note This should not be done until after the AC is setup and ready
 *       to be used.
 *
 * \section asfdoc_sam0_ac_callback_use_case_imp Implementation
 *
 * \subsection asfdoc_sam0_ac_callback_use_case_imp_code Code
 * Copy-paste the following code to your user application:
 * \snippet qs_ac_callback.c main
 *
 * \subsection asfdoc_sam0_ac_callback_use_case_imp_flow Workflow
 * -# Trigger the first comparison on the comparator channel.
 *    \snippet qs_ac_callback.c main_1
 * -# Create a local variable to maintain the current comparator state. Since no
 *    comparison has taken place, it is initialized to \ref AC_CHAN_STATUS_UNKNOWN.
 *    \snippet qs_ac_callback.c main_2
 * -# Make the application loop infinitely, while performing triggered
 *    comparisons.
 *    \snippet qs_ac_callback.c main_3
 * -# Check if a new comparison is complete.
 *    \snippet qs_ac_callback.c main_4
 * -# Check if the comparator is ready for the last triggered comparison result
 *    to be read.
 *    \snippet qs_ac_callback.c main_5
 * -# Read the comparator output state into the local variable for application
 *    use, re-trying until the comparison state is ready.
 *    \snippet qs_ac_callback.c main_5
 * -# Set the board LED state to mirror the last comparison state.
 *    \snippet qs_ac_callback.c main_6
 * -# After the interrupt is handled, set the software callback flag to false.
 *    \snippet qs_ac_callback.c main_7
 * -# Trigger the next conversion on the Analog Comparator channel.
 *    \snippet qs_ac_callback.c main_8
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
