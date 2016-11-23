/**
 * \file
 *
 * \brief SAM RTC Tamper DMA Quick Start
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
 * \page asfdoc_sam0_rtc_tamper_dma_use_case Quick Start Guide for RTC Tamper with DMA
 *
 * In this use case, the RTC is set up in count mode. The quick start
 * configures the RTC in 32-bit mode and .
 * The rest of the configuration is according to the
 * \ref rtc_count_get_config_defaults "default".
 * A callback is implemented for when the RTC capture tamper stamp.
 *
 * \section asfdoc_sam0_rtc_tamper_dma_use_case_setup Setup
 *
 * \subsection asfdoc_sam0_rtc_tamper_dma_use_case_prereq Prerequisites
 * The Generic Clock Generator for the RTC should be configured and enabled; if
 * you are using the System Clock driver, this may be done via \c conf_clocks.h.
 *
 * \subsection asfdoc_sam0_rtc_tamper_dma_use_case_setup_code Code
 * Add to the main application source file, outside of any functions:
 * 
 * \snippet qs_rtc_tamper_dma.c rtc_module_instance
 * \snippet qs_rtc_tamper_dma.c dma_resource
 * \snippet qs_rtc_tamper_dma.c transfer_descriptor
 *
 * The following must be added to the user application:
 * Function for setting up the module:
 * \snippet qs_rtc_tamper_dma.c initialize_rtc
 *
 * Callback function:
 * \snippet qs_rtc_tamper_dma.c callback
 *
 * Function for setting up the callback functionality of the driver:
 * \snippet qs_rtc_tamper_dma.c setup_callback
 *
 * Add to user application initialization (typically the start of \c main()):
 * \snippet qs_rtc_tamper_dma.c main
 *
 * \subsection asfdoc_sam0_rtc_tamper_dma_use_case_setup_workflow Workflow
 * -# Initialize system.
 *    \snippet qs_rtc_tamper_dma.c system_init
 * -# Configure and enable module.
 *    \snippet qs_rtc_tamper_dma.c run_conf
 *  -# Create a RTC configuration structure to hold the desired RTC driver
 *    settings and fill it with the configuration values.
 *    \snippet qs_rtc_tamper_dma.c init_rtc
 *    \note This should always be performed before using the configuration
 *          struct to ensure that all values are initialized to known default
 *          settings.
 *  -# Initialize the RTC module.
 *    \snippet qs_rtc_tamper_dma.c init_rtc
 *
 *  -# Create a RTC tamper configuration structure and fill it with the 
 *    configuration values.
 *    \snippet qs_rtc_tamper_dma.c set_tamper_config
 *
 *  -# Enable the RTC module, so that it may begin counting.
 *    \snippet qs_rtc_tamper_dma.c enable
 *
 * -# Configure callback functionality.
 *    \snippet qs_rtc_tamper_dma.c run_callback
 *  -# Register overflow callback.
 *     \snippet qs_rtc_tamper_dma.c reg_callback
 *  -# Enable overflow callback.
 *     \snippet qs_rtc_tamper_dma.c en_callback
 *
 * -# Configure the DMA.
 *  -# Create a DMA resource configuration structure, which can be filled out to
 *    adjust the configuration of a single DMA transfer.
 *    \snippet qs_rtc_tamper_dma.c setup_dma_config
 *
 *  -# Initialize the DMA resource configuration struct with the module's.
 *    default values.
 *    \snippet qs_rtc_tamper_dma.c setup_dma_set_config_default
 *    \note This should always be performed before using the configuration
 *          struct to ensure that all values are initialized to known default
 *          settings.
 *
 *  -# Set extra configurations for the DMA resource. ADC_DMAC_ID_RESRDY trigger
 *      causes a beat transfer in this example.
 *    \snippet qs_rtc_tamper_dma.c setup_dma_set_config_extra
 *
 *  -# Allocate a DMA resource with the configurations.
 *    \snippet qs_rtc_tamper_dma.c allocate_dma_resource
 *
 *  -# Create a DMA transfer descriptor configuration structure, which can be
 *    filled out to adjust the configuration of a single DMA transfer.
 *    \snippet qs_rtc_tamper_dma.c setup_dma_desc_config
 *
 *  -# Initialize the DMA transfer descriptor configuration struct with the module's
 *    default values.
 *    \snippet qs_rtc_tamper_dma.c setup_dma_desc_config_set_default
 *    \note This should always be performed before using the configuration
 *          struct to ensure that all values are initialized to known default
 *          settings.
 *
 *  -# Set the specific parameters for a DMA transfer with transfer size, source
 *    address, and destination address.
 *    \snippet qs_rtc_tamper_dma.c setup_dma_desc_config_set_extra
 *
 *  -# Create the DMA transfer descriptor.
 *    \snippet qs_rtc_tamper_dma.c setup_dma_desc_config_create
 *
 *  -# Add DMA descriptor to DMA resource.
 *    \snippet qs_rtc_tamper_dma.c add_descriptor_to_resource
 *
 * \section asfdoc_sam0_rtc_tamper_dma_use_case_implementation Implementation
 * \subsection asfdoc_sam0_rtc_tamper_dma_use_case_implementation_code Code
 * Add to user application main:
 * -# Infinite while loop while waiting for callbacks.
 *    \snippet qs_rtc_tamper_dma.c while
 *
 * \subsection asfdoc_sam0_rtc_tamper_dma_use_case_callback Callback
 * When the RTC tamper captured, the callback function will be called.
 * -# LED0 on for RTC tamper capture:
 *    \snippet qs_rtc_tamper_dma.c Tamper_act
 */
