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

//! [setup]
//! [buf_length]
#define BUF_LENGTH 20
//! [buf_length]
//! [slave_select_pin]
#define SLAVE_SELECT_PIN  CONF_PIN_SPI_SSN
//! [slave_select_pin]
//! [buffer]
static uint8_t buffer[BUF_LENGTH];
//! [buffer]

//! [dev_inst]
struct spi_module spi_master_instance;
//! [dev_inst]
//! [slave_dev_inst]
struct spi_slave_inst slave;
//! [slave_dev_inst]
//! [setup]

//! [configure_gpio]
static void configure_gpio(void)
{
	struct gpio_config config_gpio;

	gpio_get_config_defaults(&config_gpio);
	/* Set buttons as inputs */
	config_gpio.direction = GPIO_PIN_DIR_INPUT;
	config_gpio.input_pull = GPIO_PIN_PULL_UP;
	gpio_pin_set_config(BUTTON_0_PIN, &config_gpio);

	/* Configure LEDs as outputs, turn them off */
	config_gpio.direction = GPIO_PIN_DIR_OUTPUT;
	gpio_pin_set_config(LED_0_PIN, &config_gpio);
	gpio_pin_set_output_level(LED_0_PIN, LED_0_INACTIVE);
}
//! [configure_gpio]

//! [configure_spi]
static void configure_spi_master(void)
{
//! [config]
	struct spi_config config_spi_master;
//! [config]
//! [slave_config]
	struct spi_slave_inst_config slave_dev_config;
//! [slave_config]
	/* Configure and initialize software device instance of peripheral slave */
//! [slave_conf_defaults]
	spi_slave_inst_get_config_defaults(&slave_dev_config);
//! [slave_conf_defaults]
//! [ss_pin]
	slave_dev_config.ss_pin = SLAVE_SELECT_PIN;
//! [ss_pin]
//! [slave_init]
	spi_attach_slave(&slave, &slave_dev_config);
//! [slave_init]
	/* Configure, initialize and enable SPI module */
//! [conf_defaults]
	spi_get_config_defaults(&config_spi_master);
//! [conf_defaults]
//! [transfer_mode]
	config_spi_master.transfer_mode = CONF_SPI_TRANSFER_MODE;
//! [transfer_mode]
//! [clock_divider]
	config_spi_master.clock_divider = 154;
//! [clock_divider]
	/* Configure pad 0 */
//! [sck]
	config_spi_master.pin_number_pad[0] = CONF_SPI_PIN_SCK;
	config_spi_master.pinmux_sel_pad[0] = CONF_SPI_MUX_SCK;
//! [sck]
	/* Configure pad 1 */
//! [mosi]
	config_spi_master.pin_number_pad[1] = CONF_SPI_PIN_MOSI;
	config_spi_master.pinmux_sel_pad[1] = CONF_SPI_MUX_MOSI;
//! [mosi]
	/* Configure pad 2 */
//! [ssn]
	config_spi_master.pin_number_pad[2] = PINMUX_UNUSED;
	config_spi_master.pinmux_sel_pad[2] = PINMUX_UNUSED;
//! [ssn]
	/* Configure pad 3 */
//! [miso]
	config_spi_master.pin_number_pad[3] = CONF_SPI_PIN_MISO;
	config_spi_master.pinmux_sel_pad[3] = CONF_SPI_MUX_MISO;
//! [miso]
//! [init]
	spi_init(&spi_master_instance, CONF_SPI, &config_spi_master);
//! [init]

//! [enable]
	spi_enable(&spi_master_instance);
//! [enable]

}
//! [configure_spi]

int main(void)
{
//! [main_setup]
//! [system_init]
	system_clock_config(CLOCK_RESOURCE_XO_26_MHZ, CLOCK_FREQ_26_MHZ);
	for (uint16_t i = 0; i < BUF_LENGTH; i++) {
		buffer[i] = i;
	}
//! [system_init]
//! [run_config_gpio]
	configure_gpio();
//! [run_config_gpio]
//! [run_config_spi]
	configure_spi_master();
//! [run_config_spi]
//! [main_setup]

//! [main_use_case]
//! [inf_loop]
	while (true) {
		/* Infinite loop */
		if(!gpio_pin_get_input_level(BUTTON_0_PIN)) {
			//! [select_slave]
			spi_select_slave(&spi_master_instance, &slave, true);
			//! [select_slave]
			//! [write]
			spi_write_buffer_wait(&spi_master_instance, buffer, BUF_LENGTH);
			//! [write]
			//! [delay]
			for(uint16_t i = 0; i < 0xFF; i++) {
				/* Wait for the last data shift out */
			}
			//! [delay]
			//! [deselect_slave]
			spi_select_slave(&spi_master_instance, &slave, false);
			//! [deselect_slave]
			//! [light_up]
			gpio_pin_set_output_level(LED_0_PIN, LED0_ACTIVE);
			//! [light_up]
		}
	}
//! [inf_loop]
//! [main_use_case]
}
