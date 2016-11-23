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
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#include <asf.h>

//! [transceive_buffers]
uint8_t tx_buffer_1[3] = {1, 2, 3};
uint8_t tx_buffer_2[2] = {4, 5};
uint8_t tx_buffer_3[1] = {6};

uint8_t rx_buffer_1[1];
uint8_t rx_buffer_2[2];
//! [transceive_buffers]

//! [buffer_descriptors]
struct spi_master_vec_bufdesc tx_buffers[4] = {
			{
				.data = tx_buffer_1,
				.length = 3,
			},
			{
				.data = tx_buffer_2,
				.length = 2,
			},
			{
				.data = tx_buffer_3,
				.length = 1,
			},
			{
				.data = NULL,
				.length = 0,
			},
		};

struct spi_master_vec_bufdesc rx_buffers[4] = {
			{
				.data = rx_buffer_1,
				.length = 1,
			},
			{
				.data = NULL,
				.length = 2,
			},
			{
				.data = rx_buffer_2,
				.length = 2,
			},
			{
				.data = NULL,
				.length = 0,
			},
		};
//! [buffer_descriptors]

//! [driver_instance]
struct spi_master_vec_module spi_master;
//! [driver_instance]

int main (void)
{
//! [config_instance]
	struct spi_master_vec_config spi_config;
//! [config_instance]

//! [init_system]
	system_init();
//! [init_system]

//! [set_up_config_instance]
	spi_master_vec_get_config_defaults(&spi_config);

	spi_config.baudrate = 200000;
	spi_config.transfer_mode = SPI_TRANSFER_MODE_3;
	spi_config.mux_setting = EXT1_SPI_SERCOM_MUX_SETTING;
	spi_config.pinmux_pad0 = EXT1_SPI_SERCOM_PINMUX_PAD0;
	spi_config.pinmux_pad1 = EXT1_SPI_SERCOM_PINMUX_PAD1;
	spi_config.pinmux_pad2 = EXT1_SPI_SERCOM_PINMUX_PAD2;
	spi_config.pinmux_pad3 = EXT1_SPI_SERCOM_PINMUX_PAD3;
//! [set_up_config_instance]

//! [init_instance]
	spi_master_vec_init(&spi_master, EXT1_SPI_MODULE, &spi_config);
//! [init_instance]

//! [enable_instance]
	spi_master_vec_enable(&spi_master);
//! [enable_instance]

//! [start_reception_wait]
	spi_master_vec_transceive_buffer_wait(&spi_master, NULL, rx_buffers);
//! [start_reception_wait]

//! [start_transmission]
	spi_master_vec_transceive_buffer_job(&spi_master, tx_buffers, NULL);
//! [start_transmission]

//! [start_transception]
	while (spi_master_vec_transceive_buffer_job(&spi_master, tx_buffers, rx_buffers) == STATUS_BUSY) {
		/* Try to start transfer until it succeeds. */
	}
//! [start_transception]

//! [wait_transception]
	spi_master_vec_get_job_status_wait(&spi_master);
//! [wait_transception]

	while (1) {
	}
}