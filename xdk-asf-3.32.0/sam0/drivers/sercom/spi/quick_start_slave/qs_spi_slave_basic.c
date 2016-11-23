/**
 * \file
 *
 * \brief SAM SPI Quick Start
 *
 * Copyright (c) 2012-2016 Atmel Corporation. All rights reserved.
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

void configure_spi_slave(void);

//! [setup]
//! [buf_length]
#define BUF_LENGTH 20
//! [buf_length]

//! [buffer]
static uint8_t buffer_expect[BUF_LENGTH] = {
		0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,
		 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13
};
static uint8_t buffer_rx[BUF_LENGTH] = {0x00};
//! [buffer]

//! [dev_inst]
struct spi_module spi_slave_instance;
//! [dev_inst]
//! [setup]

//! [configure_spi]
void configure_spi_slave(void)
{
//! [config]
	struct spi_config config_spi_slave;
//! [config]
	/* Configure, initialize and enable SERCOM SPI module */
//! [conf_defaults]
	spi_get_config_defaults(&config_spi_slave);
//! [conf_defaults]
//! [conf_spi_slave_instance]
	config_spi_slave.mode = SPI_MODE_SLAVE;
//! [conf_spi_slave_instance]
//! [conf_preload]
	config_spi_slave.mode_specific.slave.preload_enable = true;
//! [conf_preload]
//! [conf_format]
	config_spi_slave.mode_specific.slave.frame_format = SPI_FRAME_FORMAT_SPI_FRAME;
//! [conf_format]
//! [mux_setting]
	config_spi_slave.mux_setting = CONF_SLAVE_MUX_SETTING;
//! [mux_setting]

	config_spi_slave.pinmux_pad0 = CONF_SLAVE_PINMUX_PAD0;
	config_spi_slave.pinmux_pad1 = CONF_SLAVE_PINMUX_PAD1;
	config_spi_slave.pinmux_pad2 = CONF_SLAVE_PINMUX_PAD2;
	config_spi_slave.pinmux_pad3 = CONF_SLAVE_PINMUX_PAD3;

//! [init]
	spi_init(&spi_slave_instance, CONF_SLAVE_SPI_MODULE, &config_spi_slave);
//! [init]

//! [enable]
	spi_enable(&spi_slave_instance);
//! [enable]

}
//! [configure_spi]

int main(void)
{
//! [main_start]
	uint8_t result = 0;
	
	/* Initialize system */
//! [system_init]
	system_init();
//! [system_init]

//! [run_config]
	configure_spi_slave();
//! [run_config]
//! [main_start]

//! [main_use_case]
//! [read]
	while(spi_read_buffer_wait(&spi_slave_instance, buffer_rx, BUF_LENGTH,
		0x00) != STATUS_OK) {
		/* Wait for transfer from the master */
	}
//! [read]
//! [compare]
	for (uint8_t i = 0; i < BUF_LENGTH; i++) {
		if(buffer_rx[i] != buffer_expect[i]) {
			result++;
		}
	}
//! [compare]
//! [inf_loop]
	while (true) {
		/* Infinite loop */		
		if (result) {
			port_pin_toggle_output_level(LED_0_PIN);
			/* Add a short delay to see LED toggle */
			volatile uint32_t delay = 30000;
			while(delay--) {
			}
		} else {
			port_pin_toggle_output_level(LED_0_PIN);
			/* Add a short delay to see LED toggle */
			volatile uint32_t delay = 600000;
			while(delay--) {
			}
		}
	}
//! [inf_loop]
//! [main_use_case]
}
