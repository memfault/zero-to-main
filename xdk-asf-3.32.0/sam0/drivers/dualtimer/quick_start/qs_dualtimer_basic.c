/**
 * \file
 *
 * \brief SAM TIMER Driver Quick Start for SAMB11
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
#include <stdio_serial.h>
#include <string.h>
#include "conf_dualtimer.h"
#include "conf_uart_serial.h"

//! [module_inst]
struct uart_module uart_instance;
//! [module_inst]

//! [callback_funcs]
//! [print_timer1]
static void dualtimer_callback1(void)
{
	puts("Timer1 trigger\r\n");
}
//! [print_timer1]

//! [print_timer2]
static void dualtimer_callback2(void)
{
	puts("Timer2 trigger\r\n");
}
//! [print_timer2]
//! [callback_funcs]

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
	config_uart.baud_rate     = CONF_STDIO_BAUDRATE;
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

static void configure_dualtimer(void)
{
//! [setup_dualtimer_1]
	struct dualtimer_config config_dualtimer;
//! [setup_dualtimer_1]

//! [setup_dualtimer_2]
	dualtimer_get_config_defaults(&config_dualtimer);
//! [setup_dualtimer_2]
//! [setup_dualtimer_3]
	config_dualtimer.timer1.load_value = CONF_DUALTIMER_TIMER1_LOAD;
//! [setup_dualtimer_3]
//! [setup_dualtimer_4]
	config_dualtimer.timer2.load_value = CONF_DUALTIMER_TIMER2_LOAD;
//! [setup_dualtimer_4]

//! [setup_dualtimer_5]
	dualtimer_init(&config_dualtimer);
//! [setup_dualtimer_5]
}

static void configure_dualtimer_callback(void)
{
	//! [setup_register_callback]
	dualtimer_register_callback(DUALTIMER_TIMER1, dualtimer_callback1);
	dualtimer_register_callback(DUALTIMER_TIMER2, dualtimer_callback2);
	//! [setup_register_callback]

	//! [enable_IRQ]
	NVIC_EnableIRQ(DUALTIMER0_IRQn);
	//! [enable_IRQ]
}
//! [setup]

int main(void)
{
//! [setup_init]
	system_clock_config(CLOCK_RESOURCE_XO_26_MHZ, CLOCK_FREQ_26_MHZ);
//! [config_uart]
	configure_uart();
//! [config_uart]
//! [config_dualtimer]
	configure_dualtimer();
//! [config_dualtimer]
//! [config_callback]
	configure_dualtimer_callback();
//! [config_callback]
//! [setup_init]

//! [main_imp]
//! [main_loop]
	while (true) {

	}
//! [main_loop]
//! [main_imp]
}
