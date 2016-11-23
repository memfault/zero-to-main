/**
 *
 * \file
 *
 * \brief Example of usage of the USART Serial.
 *
 * Copyright (c) 2010-2015 Atmel Corporation. All rights reserved.
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
/*! \mainpage
 * \section intro Introduction
 * This example demonstrates how to use the USART Serial.
 *
 * \section files Main Files
 * - usart_serial_example.c: the example application.
 * - conf_board.h: board configuration
 * - conf_stdio_serial.h: configuration of the usart_serial used by this example
 * - usart_serial.h: Part Specific USART Serial Implementation
 * - usart_serial.c : System implementation functions
 *
 * \section usart_serialapiinfo basic/serial/usart_serial API
 * The usart_serial API can be found \ref usart_serial.h "here".
 *
 * \section deviceinfo Device Info
 * All devices can be used. This example has been tested
 * with the following setup:
 *   - Evaluation kits with a serial interface (RS232 connection).
 *
 * \section exampledescription Description of the example
 *   - Send message on RS232 Com Port.
 *   - Performs echo of any received character
 *
 * \section compinfo Compilation Info
 * This software was written for the GNU GCC and IAR.
 * Other compilers may or may not work.
 *
 * \section contactinfo Contact Information
 * For further information, visit
 * <A href="http://www.atmel.com">Atmel</A>.\n
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#include <asf.h>

/*! \brief Main function.
 */
int main(void)
{
	uint8_t tx_len = 24;
	uint8_t tx_buf[] = "\n\rHello Atmel world ! : ";
	uint8_t rx_buf[] = "0";

	// USART options.
	static usart_serial_options_t USART_SERIAL_OPTIONS =
	{
		.baudrate   = USART_SERIAL_EXAMPLE_BAUDRATE,
		.charlength = USART_SERIAL_CHAR_LENGTH,
		.paritytype = USART_SERIAL_PARITY,
		.stopbits   = USART_SERIAL_STOP_BIT
	};

	sysclk_init();

	// Initialize the board.
	// The board-specific conf_board.h file contains the
	// configuration of the board initialization.
	board_init();

	// Initialize Serial Interface using Stdio Library
	usart_serial_init(USART_SERIAL_EXAMPLE,&USART_SERIAL_OPTIONS);

	// Print welcome message
	usart_serial_write_packet(USART_SERIAL_EXAMPLE, tx_buf, tx_len);

	// Get and echo a character forever, specific '\r' processing.
	while (true) {
		usart_serial_read_packet(USART_SERIAL_EXAMPLE, rx_buf, 1);
		if (rx_buf[0] == '\r') {
			usart_serial_write_packet(USART_SERIAL_EXAMPLE,
					tx_buf, tx_len);
		} else {
			usart_serial_write_packet(USART_SERIAL_EXAMPLE,
					rx_buf, 1);
		}
	}
}

