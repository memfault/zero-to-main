/**
 * \file
 *
 * \brief SAM SPI Quick Start for SAMB
 *
 * Copyright (c) 2015 Atmel Corporation. All rights reserved.
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
 * \page asfdoc_samb_spi_master_callback_use Quick Start Guide for SPI Master - Callback
 *
 * In this use case, the SPI on extension header of the Xplained Pro board
 * will configured with the following settings:
 * - Master Mode enabled
 * - MSB of the data is transmitted first
 * - Transfer mode 0
 * - 8-bit character size
 * - Not enabled in sleep mode
 * - Baudrate
 *
 *
 * \section asfdoc_samb_spi_master_callback_use_setup Setup
 *
 * \subsection asfdoc_samb_spi_master_callback_use_prereq Prerequisites
 * There are no special setup requirements for this use-case.
 *
 * \subsection asfdoc_samb_spi_master_callback_use_setup_code Code
 * The following must be added to the user application:
 *
 * A sample buffer to send via SPI.
 * \snippet qs_spi_master_callback.c buffer
 * Number of entries in the sample buffer.
 * \snippet qs_spi_master_callback.c buf_length
 * GPIO pin to use as Slave Select.
 * \snippet qs_spi_master_callback.c slave_select_pin
 * A globally available software device instance struct to store the SPI driver
 * state while it is in use.
 * \snippet qs_spi_master_callback.c dev_inst
 * A globally available peripheral slave software device instance struct.
 * \snippet qs_spi_master_callback.c slave_dev_inst
 * A global variable that can flag to the application that the buffer has been
 * transferred.
 * \snippet qs_spi_master_callback.c var
 * A function for configuring the GPIO.
 * \snippet qs_spi_master_callback.c configure_gpio
 * A function for configuring the SPI.
 * \snippet qs_spi_master_callback.c configure_spi
 * Callback function.
 * \snippet qs_spi_master_callback.c callback
 *
 * Add to user application \c main().
 * \snippet qs_spi_master_callback.c main_setup
 *
 * \section asfdoc_samb_spi_master_callback_use_workflow Workflow
 * -# Initialize system.
 *    \snippet qs_spi_master_callback.c system_init
 * -# Setup the GPIO.
 *    \snippet qs_spi_master_callback.c run_config_gpio
 * -# Setup the SPI.
 *    \snippet qs_spi_master_callback.c run_config_spi
 *   -# Create configuration struct.
 *      \snippet qs_spi_master_callback.c config
 *   -# Create peripheral slave configuration struct.
 *      \snippet qs_spi_master_callback.c slave_config
 *   -# Create peripheral slave software device instance struct.
 *      \snippet qs_spi_master_callback.c slave_dev_inst
 *   -# Get default peripheral slave configuration.
 *      \snippet qs_spi_master_callback.c slave_conf_defaults
 *   -# Set Slave Select pin.
 *      \snippet qs_spi_master_callback.c ss_pin
 *   -# Initialize peripheral slave software instance with configuration.
 *      \snippet qs_spi_master_callback.c slave_init
 *   -# Get default configuration to edit.
 *      \snippet qs_spi_master_callback.c conf_defaults
 *   -# Set transfer mode 0.
 *      \snippet qs_spi_master_callback.c transfer_mode
 *   -# Set clock divider.
 *      \snippet qs_spi_master_basic.c clock_divider
 *   -# Set pinmux for pad 0 (SCK).
 *      \snippet qs_spi_master_callback.c sck
 *   -# Set pinmux for pad 1 (data out (MOSI))
 *      \snippet qs_spi_master_callback.c mosi
 *   -# Set pinmux for pad 2 as unused, so the pin can be used for other purposes.
 *      \snippet qs_spi_master_callback.c ssn
 *   -# Set pinmux for pad 3 (data in (MISO)).
 *      \snippet qs_spi_master_callback.c miso
 *   -# Initialize SPI module with configuration.
 *      \snippet qs_spi_master_callback.c init
 *   -# Enable SPI module.
 *      \snippet qs_spi_master_callback.c enable
 * -# Setup the callback functionality.
 *    \snippet qs_spi_master_callback.c run_callback_config
 *   -# Register callback function for buffer transmitted.
 *      \snippet qs_spi_master_callback.c reg_callback
 *   -# Enable callback for buffer transmitted.
 *      \snippet qs_spi_master_callback.c en_callback
 *
 * \section asfdoc_samb_spi_master_callback_use_case Use Case
 * \subsection asfdoc_samb_spi_master_callback_use_case_code Code
 * Add the following to your user application \c main().
 * \snippet qs_spi_master_callback.c main_use_case
 * \subsection asfdoc_samb_spi_master_callback_use_case_workflow Workflow
 * -# Select slave.
 *    \snippet qs_spi_master_callback.c select_slave
 * -# Write buffer to SPI slave.
 *    \snippet qs_spi_master_callback.c write
 * -# Wait for the transfer to be complete.
 *    \snippet qs_spi_master_callback.c wait
 * -# Deselect slave.
 *    \snippet qs_spi_master_callback.c deselect_slave
 * -# Light up.
 *    \snippet qs_spi_master_callback.c light_up
 * -# Infinite loop.
 *    \snippet qs_spi_master_callback.c inf_loop
 */

