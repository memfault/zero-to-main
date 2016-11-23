/**
 * \file
 *
 * \brief SERCOM SPI master with vectored I/O driver quick start
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
 * \page asfdoc_sam0_sercom_spi_master_vec_basic Quick Start Guide for SERCOM SPI Master Driver w/ Vectored I/O
 *
 * This quick start will receive, transmit and transceive bytes on the EXT1
 * header. In this use case the SERCOM SPI will be configured with the following
 * settings:
 * - 200 kHz SCK
 * - SCK, MISO and MOSI on EXT1 header's SPI pins
 * - CPOL = 1 and CPHA = 1 (idle SCK high, setup on falling edge, sample on
 *   rising)
 *
 *
 * \section asfdoc_sam0_sercom_spi_master_vec_basic_setup Setup
 *
 *
 * \subsection asfdoc_sam0_sercom_spi_master_vec_basic_prereq Prerequisites
 *
 * There are no special setup requirements for this use-case.
 *
 *
 * \subsection asfdoc_sam0_sercom_spi_master_vec_basic_setup_code Code
 *
 * Add to the main application source file, outside of any functions:
 * \snippet qs_spi_master_vec_basic.c transceive_buffers
 * \snippet qs_spi_master_vec_basic.c buffer_descriptors
 * \snippet qs_spi_master_vec_basic.c driver_instance
 *
 * If not already present, add to the initialization code:
 * \snippet qs_spi_master_vec_basic.c init_system
 *
 * Add to the initialization code:
 * \snippet qs_spi_master_vec_basic.c config_instance
 * \snippet qs_spi_master_vec_basic.c set_up_config_instance
 * \snippet qs_spi_master_vec_basic.c init_instance
 *
 *
 * \subsection asfdoc_sam0_sercom_spi_master_vec_basic_setup_flow Workflow
 *
 * -# Create data buffers to transfer to/from.
 *    \snippet qs_spi_master_vec_basic.c transceive_buffers
 *    \note These example buffers are in total 6 bytes long for transmit (TX)
 *        and 3 bytes long for receive (RX).
 *
 * -# Create descriptors for the data buffers. For reception, we will discard
 *        two bytes after the first one.
 *    \snippet qs_spi_master_vec_basic.c buffer_descriptors
 *    \attention The last descriptor in the array \e must specify zero length
 *        for the driver to know when it has reached the last buffer.
 *
 * -# Create an instance of the driver to operate on.
 *
 *    \snippet qs_spi_master_vec_basic.c driver_instance
 * -# In the initialization code, add a config struct for the driver.
 *
 *    \snippet qs_spi_master_vec_basic.c driver_instance
 * -# Initialize the config struct and change to the desired configuration.
 *
 *    \snippet qs_spi_master_vec_basic.c set_up_config_instance
 * -# Initialize the device instance with the configuration and SERCOM to use.
 *
 *    \snippet qs_spi_master_vec_basic.c init_instance
 *
 *
 * \subsection asfdoc_sam0_sercom_spi_master_vec_basic_main_code Code
 *
 * Add to the application code:
 * \snippet qs_spi_master_vec_basic.c enable_instance
 * \snippet qs_spi_master_vec_basic.c start_reception_wait
 * \snippet qs_spi_master_vec_basic.c start_transmission
 * \snippet qs_spi_master_vec_basic.c start_transception
 * \snippet qs_spi_master_vec_basic.c wait_transception
 *
 * \subsection asfdoc_sam0_sercom_spi_master_vec_basic_main_flow Workflow
 * -# Enable the SERCOM module before using it.
 *
 *    \snippet qs_spi_master_vec_basic.c enable_instance
 * -# Start and wait for first transfer: receive 5 bytes, 3 of which will be
 *        written into the RX buffers.
 *
 *    \snippet qs_spi_master_vec_basic.c start_reception_wait
 * -# Start transmission of the 6 bytes from TX buffers.
 *
 *    \snippet qs_spi_master_vec_basic.c start_transmission
 * -# Keep trying to start next transfer until it succeeds: transmit the 6 bytes
 *        from the TX buffers and receive 5 bytes, writing 3 of them into the RX
 *        buffers simultaneously.
 *
 *    \snippet qs_spi_master_vec_basic.c start_transception
 * -# Wait for transfer to complete.
 *
 *    \snippet qs_spi_master_vec_basic.c wait_transception
 *//*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
