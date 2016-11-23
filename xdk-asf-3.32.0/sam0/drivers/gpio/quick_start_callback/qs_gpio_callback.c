/**
 * \file
 *
 * \brief GPIO Quick Start Guide with Callbacks for SAMB
 *
 * Copyright (C) 2016 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
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
#include "conf_uart_serial.h"

//! [module_inst]
struct uart_module uart_instance;
//! [module_inst]

//! [callback_func]
static void aon_gpio_0_callback(void)
{
	puts("AO_GPIO_0 callback\r\n"); 
}

static void aon_gpio_1_callback(void)
{
	puts("AO_GPIO_1 callback\r\n");
}

static void aon_gpio_2_callback(void)
{
	puts("AO_GPIO_2 callback\r\n");
}
//! [callback_func]

//! [setup]
static void configure_uart(void)
{
	//! [setup_uart_1]
	struct uart_config config_uart;
	//! [setup_uart_1]
	//! [setup_uart_2]
	uart_get_config_defaults(&config_uart);
	//! [setup_uart_2]
	//! [setup_uart_3]
	config_uart.baud_rate	      = CONF_STDIO_BAUDRATE;
	config_uart.pin_number_pad[0] = CONF_STDIO_PIN_PAD0;
	config_uart.pin_number_pad[1] = CONF_STDIO_PIN_PAD1;
	config_uart.pin_number_pad[2] = CONF_STDIO_PIN_PAD2;
	config_uart.pin_number_pad[3] = CONF_STDIO_PIN_PAD3;
	
	config_uart.pinmux_sel_pad[0] = CONF_STDIO_MUX_PAD0;
	config_uart.pinmux_sel_pad[1] = CONF_STDIO_MUX_PAD1;
	config_uart.pinmux_sel_pad[2] = CONF_STDIO_MUX_PAD2;
	config_uart.pinmux_sel_pad[3] = CONF_STDIO_MUX_PAD3;
	//! [setup_uart_3]
	//! [setup_uart_4]
	stdio_serial_init(&uart_instance, CONF_STDIO_USART_MODULE, &config_uart);
	//! [setup_uart_4]
}

static void configure_gpio(void)
{
	//! [setup_gpio_1]
	struct gpio_config config_gpio_pin;
	gpio_get_config_defaults(&config_gpio_pin);
	//! [setup_gpio_1]
	
	//! [setup_gpio_2]
	config_gpio_pin.direction  = GPIO_PIN_DIR_INPUT;
	config_gpio_pin.input_pull = GPIO_PIN_PULL_NONE;
	config_gpio_pin.aon_wakeup = true;
	//! [setup_gpio_2]
	//! [setup_gpio_3]
	gpio_pin_set_config(PIN_AO_GPIO_0, &config_gpio_pin);
	gpio_pin_set_config(PIN_AO_GPIO_1, &config_gpio_pin);
	gpio_pin_set_config(PIN_AO_GPIO_2, &config_gpio_pin);
	//! [setup_gpio_3]
}

static void configure_gpio_callbacks(void)
{
	/* Register callback function. */
//! [callback_init]
	gpio_init();
//! [callback_init]
	//! [callback_reg]
	gpio_register_callback(PIN_AO_GPIO_0, aon_gpio_0_callback,
			GPIO_CALLBACK_RISING);
	gpio_register_callback(PIN_AO_GPIO_1, aon_gpio_1_callback,
			GPIO_CALLBACK_RISING);
	gpio_register_callback(PIN_AO_GPIO_2, aon_gpio_2_callback,
			GPIO_CALLBACK_RISING);
	//! [callback_reg]
	//! [callback_en]
	gpio_enable_callback(PIN_AO_GPIO_0);
	gpio_enable_callback(PIN_AO_GPIO_1);
	gpio_enable_callback(PIN_AO_GPIO_2);
	//! [callback_en]
}
//! [setup]

int main(void)
{
	//! [run_initialize_i2c]
	system_clock_config(CLOCK_RESOURCE_XO_26_MHZ, CLOCK_FREQ_26_MHZ);

	//! [setup_init]
	configure_uart();

	configure_gpio();

	configure_gpio_callbacks();
	//! [setup_init]

	//! [main]
	while (true){
		
	}
	//! [main]
}