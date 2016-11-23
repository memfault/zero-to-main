/**
 * \file
 *
 * \brief SAM UART Quick Start
 *
 * Copyright (C) 2015-2016 Atmel Corporation. All rights reserved.
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

//! [module_inst]
struct uart_module uart_instance;
//! [module_inst]

//! [variable_inst]
static uint8_t string_input[8];
volatile static bool read_complete_flag = false;
volatile static bool write_complete_flag = false;
//! [variable_inst]

//! [callback_functions]
static void uart_read_complete_callback(struct uart_module *const module)
{
	read_complete_flag = true;
}

static void uart_write_complete_callback(struct uart_module *const module)
{
	write_complete_flag = true;
}
//! [callback_functions]

//! [setup]
static void configure_uart(void)
{
//! [setup_config]
	struct uart_config config_uart;
//! [setup_config]
//! [setup_config_defaults]
	uart_get_config_defaults(&config_uart);
//! [setup_config_defaults]

//! [setup_change_config]
	config_uart.baud_rate = 115200;
	config_uart.pin_number_pad[0] = EDBG_CDC_PIN_PAD0;
	config_uart.pin_number_pad[1] = EDBG_CDC_PIN_PAD1;
	config_uart.pin_number_pad[2] = EDBG_CDC_PIN_PAD2;
	config_uart.pin_number_pad[3] = EDBG_CDC_PIN_PAD3;
	
	config_uart.pinmux_sel_pad[0] = EDBG_CDC_MUX_PAD0;
	config_uart.pinmux_sel_pad[1] = EDBG_CDC_MUX_PAD1;
	config_uart.pinmux_sel_pad[2] = EDBG_CDC_MUX_PAD2;
	config_uart.pinmux_sel_pad[3] = EDBG_CDC_MUX_PAD3;
//! [setup_change_config]

//! [setup_set_config]
	while (uart_init(&uart_instance,
			EDBG_CDC_MODULE, &config_uart) != STATUS_OK) {
	}
//! [setup_set_config]
}
//! [setup]

int main(void)
{
	/**
	 * For make this QS work, disable the systick to stop task switch.
	 * Should not do it if you want the BLE functions.
	 */
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;

	system_clock_config(CLOCK_RESOURCE_XO_26_MHZ, CLOCK_FREQ_26_MHZ);

//! [setup_init]
	configure_uart();
//! [setup_init]

//! [main]
//! [main_send_string1]
	uint8_t string1[] = " Hello World!\r\n";
	uart_write_buffer_wait(&uart_instance, string1, sizeof(string1));
//! [main_send_string1]

//! [test_callback_functions]
	uint8_t string3[] = " Test callback functions, please input 8 number or character!\r\n";
	uart_register_callback(&uart_instance, uart_write_complete_callback,
		UART_TX_COMPLETE);
	uart_enable_callback(&uart_instance, UART_TX_COMPLETE);
	uart_write_buffer_job(&uart_instance, string3, sizeof(string3));
	while (!write_complete_flag);

	uart_register_callback(&uart_instance, uart_read_complete_callback,
		UART_RX_COMPLETE);
	uart_enable_callback(&uart_instance, UART_RX_COMPLETE);
	uart_read_buffer_job(&uart_instance, string_input, sizeof(string_input));
	while (!read_complete_flag);

	uint8_t string4[] = " Data received: ";
	uart_write_buffer_wait(&uart_instance, string4, sizeof(string4));
	uart_write_buffer_wait(&uart_instance, string_input, sizeof(string_input));
//! [test_callback_functions]

//! [main_rec_var]
	uint8_t temp;
//! [main_rec_var]

	uint8_t string2[] = "\r\n Enter while loop, echo back your input!\r\n";
	uart_write_buffer_wait(&uart_instance, string2, sizeof(string2));

//! [main_loop]
	while (true) {
//! [main_read]
		if (uart_read_wait(&uart_instance, &temp) == STATUS_OK) {
//! [main_read]
//! [main_write]
			while (uart_write_wait(&uart_instance, temp) != STATUS_OK) {
			}
//! [main_write]
		}
	}
//! [main_loop]
//! [main]
}
