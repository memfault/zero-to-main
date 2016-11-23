/**
 * \file
 *
 * \brief SAM SERCOM I2C Slave Quick Start Guide with Callbacks
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

/**
 * \page asfdoc_sam0_sercom_i2c_slave_callback_use_case Quick Start Guide for SERCOM I2C Slave - Callback
 *
 * In this use case, the I<SUP>2</SUP>C will used and set up as follows:
 *  - Slave mode
 *  - 100KHz operation speed
 *  - Not operational in standby
 *  - 10000 packet timeout value
 *
 * \section asfdoc_sam0_sercom_i2c_slave_callback_use_case_prereq Prerequisites
 * The device must be connected to an I<SUP>2</SUP>C master.
 *
 * \section asfdoc_sam0_sercom_i2c_slave_callback_use_case_setup_code Setup
 *
 * \subsection asfdoc_sam0_sercom_i2c_slave_callback_use_setup_code Code
 * The following must be added to the user application:
 *
 * A sample buffer to write from, a sample buffer to read to and length of buffers:
 * \snippet qs_i2c_slave_callback.c packet_data
 *
 * Address to respond to:
 * \snippet qs_i2c_slave_callback.c address
 *
 * Globally accessible module structure:
 * \snippet qs_i2c_slave_callback.c module
 *
 * Globally accessible packet:
 * \snippet qs_i2c_slave_callback.c packet
 *
 * Function for setting up the module:
 * \snippet qs_i2c_slave_callback.c initialize_i2c
 *
 * Callback function for read request from a master:
 * \snippet qs_i2c_slave_callback.c read_request
 *
 * Callback function for write request from a master:
 * \snippet qs_i2c_slave_callback.c write_request
 *
 * Function for setting up the callback functionality of the driver:
 * \snippet qs_i2c_slave_callback.c setup_i2c_callback
 *
 * Add to user application \c main():
 * \snippet qs_i2c_slave_callback.c run_initialize_i2c
 *
 * \subsection asfdoc_sam0_sercom_i2c_slave_callback_use_setup_workflow Workflow
 * -# Configure and enable module.
 *    \snippet qs_i2c_slave_callback.c config
 *   -# Create and initialize configuration structure.
 *      \snippet qs_i2c_slave_callback.c init_conf
 *   -# Change address and address mode settings in the configuration.
 *      \snippet qs_i2c_slave_callback.c conf_changes
 *   -# Initialize the module with the set configurations.
 *      \snippet qs_i2c_slave_callback.c init_module
 *   -# Enable the module.
 *      \snippet qs_i2c_slave_callback.c enable_module
 * -# Register and enable callback functions.
 *    \snippet qs_i2c_slave_callback.c config_callback
 *   -# Register and enable callbacks for read and write requests from master.
 *      \snippet qs_i2c_slave_callback.c reg_en_i2c_callback
 *
 * \section asfdoc_sam0_sercom_i2c_slave_callback_use_implementation Implementation
 * \subsection asfdoc_sam0_sercom_i2c_slave_callback_use_implementation_code Code
 * Add to user application \c main():
 * \snippet qs_i2c_slave_callback.c while
 * \subsection i2c_slave_callback_use_implementation_workflow Workflow
 * -# Infinite while loop, while waiting for interaction from master.
 *    \snippet qs_i2c_slave_callback.c while
 *
 * \section asfdoc_sam0_sercom_i2c_slave_callback_use_callback Callback
 * When an address packet is received, one of the callback functions will be
  * called, depending on the DIR bit in the received packet.
 *
 * \subsection asfdoc_sam0_sercom_i2c_slave_callback_use_callback_workflow Workflow
 * - Read request callback:
 *  -# Length of buffer and buffer to be sent to master is initialized.
 *     \snippet qs_i2c_slave_callback.c packet_write
 *  -# Write packet to master.
 *     \snippet qs_i2c_slave_callback.c write_packet
 *
 * - Write request callback:
 *  -# Length of buffer and buffer to be read from master is initialized.
 *     \snippet qs_i2c_slave_callback.c packet_read
 *  -# Read packet from master.
 *     \snippet qs_i2c_slave_callback.c read_packet
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#include <asf.h>
#include <conf_clocks.h>

