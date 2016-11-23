/**
 * \file
 *
 * \brief SAM TC Driver Quick Start
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
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

/**
 * \page asfdoc_sam0_tc_dma_use_case Quick Start Guide for Using DMA with TC
 *
 * The supported kit list:
 *    - SAM D21/R21/D11/L21/L22/DA1/C21 Xplained Pro
 *
 * In this use case, the TC will be used to generate a PWM signal. Here
 * the pulse width is set to one quarter of the period. Once the counter value
 * matches the values in the Compare/Capture Value register, an event will be
 * tiggered for a DMA memory to memory transfer.
 * The TC module will be set up as follows:
 *
 * \li GCLK generator 0 (GCLK main) clock source
 * \li 16-bit resolution on the counter
 * \li No prescaler
 * \li Normal PWM wave generation
 * \li GCLK reload action
 * \li Don't run in standby
 * \li No inversion of waveform output
 * \li No capture enabled
 * \li Count upward
 * \li Don't perform one-shot operations
 * \li No event input enabled
 * \li No event action
 * \li No event generation enabled
 * \li Counter starts on 0
 * \li Capture compare channel 0 set to 0xFFFF/4
 *
 * The DMA module is configured for:
 *  \li Move data from memory to memory
 *  \li Using peripheral trigger of TC6 Match/Compare 0
 *  \li Using DMA priority level 0
 * \section asfdoc_sam0_tc_dma_use_case_setup Quick Start
 *
 * \subsection asfdoc_sam0_tc_dma_use_case_prereq Prerequisites
 * There are no prerequisites for this use case.
 *
 * \subsection asfdoc_sam0_tc_dma_use_case_setup_code Code
 *
 * Add to the main application source file, before any functions, according to
 * the kit used:
 * - SAM D21 Xplained Pro.
 *   \snippet quick_start_dma/samd21_xplained_pro/conf_quick_start.h definition_pwm
 *   \snippet quick_start_dma/samd21_xplained_pro/conf_quick_start.h definition_dma
 * - SAM R21 Xplained Pro.
 *   \snippet quick_start_dma/samr21_xplained_pro/conf_quick_start.h definition_pwm
 *   \snippet quick_start_dma/samr21_xplained_pro/conf_quick_start.h definition_dma
 * - SAM D11 Xplained Pro.
 *   \snippet quick_start_dma/samd11_xplained_pro/conf_quick_start.h definition_pwm
 *   \snippet quick_start_dma/samd11_xplained_pro/conf_quick_start.h definition_dma
 * - SAM L21 Xplained Pro.
 *   \snippet quick_start_dma/saml21_xplained_pro/conf_quick_start.h definition_pwm
 *   \snippet quick_start_dma/saml21_xplained_pro/conf_quick_start.h definition_dma
 * - SAM L22 Xplained Pro.
 *   \snippet quick_start_dma/saml22_xplained_pro/conf_quick_start.h definition_pwm
 *   \snippet quick_start_dma/saml22_xplained_pro/conf_quick_start.h definition_dma
 * - SAM DA1 Xplained Pro.
 *   \snippet quick_start_dma/samda1_xplained_pro/conf_quick_start.h definition_pwm
 *   \snippet quick_start_dma/samda1_xplained_pro/conf_quick_start.h definition_dma
 * - SAM C21 Xplained Pro.
 *   \snippet quick_start_dma/samc21_xplained_pro/conf_quick_start.h definition_pwm
 *   \snippet quick_start_dma/samc21_xplained_pro/conf_quick_start.h definition_dma 
 *
 * Add to the main application source file, outside of any functions:
 * \snippet qs_tc_dma.c module_inst
 * \snippet qs_tc_dma.c dma_resource
 * \snippet qs_tc_dma.c transfer_length
 * \snippet qs_tc_dma.c transfer_counter
 * \snippet qs_tc_dma.c source_memory
 * \snippet qs_tc_dma.c destination_memory
 * \snippet qs_tc_dma.c transfer_done_flag
 * \snippet qs_tc_dma.c example_descriptor
 *
 * Copy-paste the following setup code to your user application:
 * \snippet qs_tc_dma.c setup
 *
 * Add to user application initialization (typically the start of \c main()):
 * \snippet qs_tc_dma.c setup_init
 *
 * \subsection asfdoc_sam0_tc_dma_use_case_setup_flow Workflow
 * \subsubsection asfdoc_sam0_tc_dma_use_case_setup_flow_inst Create variables
 * -# Create a module software instance structure for the TC module to store
 *    the TC driver state while it is in use.
 *    \snippet qs_tc_dma.c module_inst
 *    \note This should never go out of scope as long as the module is in use.
 *          In most cases, this should be global.
 *
 * -# Create a module software instance structure for DMA resource to store
 *    the DMA resource state while it is in use.
 *    \snippet qs_tc_dma.c dma_resource
 *    \note This should never go out of scope as long as the module is in use.
 *          In most cases, this should be global.
 *
 * \subsubsection asfdoc_sam0_tc_dma_use_case_setup_flow_tc Configure TC
 * -# Create a TC module configuration struct, which can be filled out to
 *    adjust the configuration of a physical TC peripheral.
 *    \snippet qs_tc_dma.c setup_config
 * -# Initialize the TC configuration struct with the module's default values.
 *    \snippet qs_tc_dma.c setup_config_defaults
 *    \note This should always be performed before using the configuration
 *          struct to ensure that all values are initialized to known default
 *          settings.
 *
 * -# Alter the TC settings to configure the counter width, wave generation
 *    mode, and the compare channel 0 value.
 *    \snippet qs_tc_dma.c setup_change_config
 * -# Alter the TC settings to configure the PWM output on a physical device
 *    pin.
 *    \snippet qs_tc_dma.c setup_change_config_pwm
 * -# Configure the TC module with the desired settings.
 *    \snippet qs_tc_dma.c setup_set_config
 * -# Enable the TC module to start the timer and begin PWM signal generation.
 *    \snippet qs_tc_dma.c setup_enable
 *
 * \subsubsection asfdoc_sam0_tc_dma_use_case_setup_flow_dma Configure DMA
 * -# Create a DMA resource configuration structure, which can be filled out to
 *    adjust the configuration of a single DMA transfer.
 *    \snippet qs_tc_dma.c dma_setup_1
 *
 * -# Initialize the DMA resource configuration struct with the module's
 *    default values.
 *    \snippet qs_tc_dma.c dma_setup_2
 *    \note This should always be performed before using the configuration
 *          struct to ensure that all values are initialized to known default
 *          settings.
 *
 * -# Allocate a DMA resource with the configurations.
 *    \snippet qs_tc_dma.c dma_setup_3
 *
 * -# Create a DMA transfer descriptor configuration structure, which can be
 *    filled out to adjust the configuration of a single DMA transfer.
 *    \snippet qs_tc_dma.c dma_setup_4
 *
 * -# Initialize the DMA transfer descriptor configuration struct with the module's
 *    default values.
 *    \snippet qs_tc_dma.c dma_setup_5
 *    \note This should always be performed before using the configuration
 *          struct to ensure that all values are initialized to known default
 *          settings.
 *
 * -# Set the specific parameters for a DMA transfer with transfer size, source
 *    address, and destination address.
 *    \snippet qs_tc_dma.c dma_setup_6
 *
 * -# Create the DMA transfer descriptor.
 *    \snippet qs_tc_dma.c dma_setup_7
 *
 * -# Add the DMA transfer descriptor to the allocated DMA resource.
 *    \snippet qs_tc_dma.c add_descriptor_to_resource
 *
 * -# Register a callback to indicate transfer status.
 *    \snippet qs_tc_dma.c setup_callback_register
 *
 * -# The transfer done flag is set in the registered callback function.
 *    \snippet qs_tc_dma.c _transfer_done
 *
 * \subsubsection asfdoc_sam0_tc_dma_use_case_setup_flow_data Prepare data
 * -# Setup memory content for validate transfer.
 *    \snippet qs_tc_dma.c setup_source_memory_content
 *
 * \section asfdoc_sam0_tc_dma_use_case_main Use Case
 *
 * \subsection asfdoc_sam0_tc_dma_use_case_main_code Code
 * Copy-paste the following code to your user application:
 * \snippet qs_tc_dma.c main
 *
 * \subsection asfdoc_sam0_tc_dma_use_case_main_flow Workflow
 * -# Start the loop for transfer.
 *    \snippet qs_tc_dma.c main_transfer_loop
 *
 * -# Set the transfer done flag as false.
 *    \snippet qs_tc_dma.c main_1
 *
 * -# Start the transfer job.
 *    \snippet qs_tc_dma.c main_2
 *
 * -# Wait for transfer done.
 *    \snippet qs_tc_dma.c main_3
 *
 * -# Update the source and destination address for next transfer.
 *    \snippet qs_tc_dma.c main_4
 *
 * -# Enter endless loop.
 *    \snippet qs_tc_dma.c endless_loop
 */
