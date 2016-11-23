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
#include <asf.h>

void configure_spi_slave(void);

//! [setup]
//! [buf_length]
#define BUF_LENGTH 20
//! [buf_length]

//! [buffer]
static uint8_t buffer_expect[BUF_LENGTH];
static uint8_t buffer_rx[BUF_LENGTH] = {0x00};
//! [buffer]

//! [dev_inst]
struct spi_module spi_slave_instance;
//! [dev_inst]
//! [setup]

//! [configure_gpio]
static void configure_gpio(void)
{
	struct gpio_config config_gpio;

	gpio_get_config_defaults(&config_gpio);

	/* Configure LEDs as outputs, turn them off */
	config_gpio.direction = GPIO_PIN_DIR_OUTPUT;
	gpio_pin_set_config(LED_0_PIN, &config_gpio);
	gpio_pin_set_output_level(LED_0_PIN, LED_0_INACTIVE);
}
//! [configure_gpio]

//! [configure_spi]
void configure_spi_slave(void)
{
//! [config]
	struct spi_config config_spi_slave;
//! [config]
	/* Configure, initialize and enable SPI module */
//! [conf_defaults]
	spi_get_config_defaults(&config_spi_slave);
//! [conf_defaults]
//! [conf_spi_slave_instance]
	config_spi_slave.mode = SPI_MODE_SLAVE;
//! [conf_spi_slave_instance]
//! [transfer_mode]
	config_spi_slave.transfer_mode = CONF_SPI_TRANSFER_MODE;
//! [transfer_mode]
	/* Configure pad 0 */
//! [sck]
	config_spi_slave.pin_number_pad[0] = CONF_SPI_PIN_SCK;
	config_spi_slave.pinmux_sel_pad[0] = CONF_SPI_MUX_SCK;
//! [sck]
	/* Configure pad 1 */
//! [mosi]
	config_spi_slave.pin_number_pad[1] = CONF_SPI_PIN_MOSI;
	config_spi_slave.pinmux_sel_pad[1] = CONF_SPI_MUX_MOSI;
//! [mosi]
	/* Configure pad 2 */
//! [ssn]
	config_spi_slave.pin_number_pad[2] = CONF_SPI_PIN_SSN;
	config_spi_slave.pinmux_sel_pad[2] = CONF_SPI_MUX_SSN;
//! [ssn]
	/* Configure pad 3 */
//! [miso]
	config_spi_slave.pin_number_pad[3] = CONF_SPI_PIN_MISO;
	config_spi_slave.pinmux_sel_pad[3] = CONF_SPI_MUX_MISO;
//! [miso]
//! [init]
	spi_init(&spi_slave_instance, CONF_SPI, &config_spi_slave);
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
	uint16_t i;
	uint32_t delay;

	/* Initialize system */
//! [system_init]
	system_clock_config(CLOCK_RESOURCE_XO_26_MHZ, CLOCK_FREQ_26_MHZ);
	for (i = 0; i < BUF_LENGTH; i++) {
		buffer_expect[i] = i;
		buffer_rx[i] = 0;
	}
//! [system_init]

//! [run_config_gpio]
	configure_gpio();
//! [run_config_gpio]
//! [run_config_spi]
	configure_spi_slave();
//! [run_config_spi]
//! [main_start]

//! [main_use_case]
//! [read]
	memset(buffer_rx, 0x0, BUF_LENGTH);
	while(spi_read_buffer_wait(&spi_slave_instance, buffer_rx, BUF_LENGTH,
		0x00) != STATUS_OK) {
		/* Wait for transfer from the master */
	}
//! [read]
//! [compare]
	for (i = 0; i < BUF_LENGTH; i++) {
		if(buffer_rx[i] != buffer_expect[i]) {
			result++;
		}
	}
//! [compare]
//! [inf_loop]
	while (true) {
		/* Infinite loop */
		if (result) {
			gpio_pin_toggle_output_level(LED_0_PIN);
			/* Add a short delay to see LED toggle */
			delay = 300000;
			while(delay--) {
			}
		} else {
			gpio_pin_toggle_output_level(LED_0_PIN);
			/* Add a short delay to see LED toggle */
			delay = 3000000;
			while(delay--) {
			}
		}
	}
//! [inf_loop]
//! [main_use_case]
}
