/**
 * \file
 *
 * \brief SAM SPI Flash Driver Quick Start for SAMB11
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
#include <asf.h>

//! [buffer]
#define len_buf    FLASH_PAGE_SIZE

volatile uint8_t read_buf[len_buf];
volatile uint8_t write_buf[len_buf];
//! [buffer]

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

int main(void)
{
	uint32_t delay = 0;
	uint32_t i;
	
//! [system_init]
	system_clock_config(CLOCK_RESOURCE_XO_26_MHZ, CLOCK_FREQ_26_MHZ);
//! [system_init]
//! [run_config_gpio]
	configure_gpio();
//! [run_config_gpio]

//! [setup_init]
//!   [setup_1]
	for (i = 0; i < len_buf; i++) {
		write_buf[i] = i;
	}
//!   [setup_1]
//!   [setup_2]
	spi_flash_init();
//!   [setup_2]
//! [setup_init]

//! [main_use_case]
//!   [main_1]
	while(spi_flash_erase((unsigned long)FLASH_NVDS_START_ADDRESS, len_buf)) {
		gpio_pin_toggle_output_level(LED_0_PIN);
		/* Add a short delay to see LED toggle */
		delay = 300000;
		while(delay--) {
		}
	}
//!  [main_1]

//!  [main_2]
	spi_flash_read((unsigned char *)read_buf, \
				(unsigned long)FLASH_NVDS_START_ADDRESS, \
				len_buf);
//!  [main_2]

//!  [main_3]
	for (i = 0; i < len_buf; i++) {
		if(read_buf[i] != 0xFF) {
			while(1) {
				gpio_pin_toggle_output_level(LED_0_PIN);
				/* Add a short delay to see LED toggle */
				delay = 300000;
				while(delay--) {
				}
			}
		}
	}
//!  [main_3]

//!  [main_4]
	spi_flash_write((unsigned char *)write_buf, \
				(unsigned long)FLASH_NVDS_START_ADDRESS, \
				len_buf);
//!  [main_4]

//!  [main_5]
	spi_flash_read((unsigned char *)read_buf, \
				(unsigned long)FLASH_NVDS_START_ADDRESS, \
				len_buf);
//!  [main_5]

//!  [main_6]
	for (i = 0; i < len_buf; i++) {
		if(read_buf[i] != write_buf[i]) {
			while(1) {
				gpio_pin_toggle_output_level(LED_0_PIN);
				/* Add a short delay to see LED toggle */
				delay = 300000;
				while(delay--) {
				}
			}
		}
	}
//!  [main_6]

//!  [inf_loop]
	while (true) {
		gpio_pin_toggle_output_level(LED_0_PIN);
		/* Add a short delay to see LED toggle */
		delay = 5000000;
		while(delay--) {
		}
	}
//!  [inf_loop]
//! [main_use_case]
}
