/**
 * \file
 *
 * \mainpage
 *
 * \section title Serial Standard I/O (stdio) Example
 *
 * \section file File(s)
 * - \ref stdio_serial_example.c
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

/**
 * \defgroup group_common_utils_stdio_stdio_serial_stdio_serial_example Serial Standard I/O (stdio) Example
 *
 * \section intro Introduction
 * This example demonstrates how to use the Serial Stdio.
 *
 * \section files Main Files
 * - stdio_serial_example.c: the example application.
 * - conf_board.h: board configuration
 * - conf_clock.h: clock configuration
 * - conf_usart_serial.h: configuration of the stdio serial used by this example
 * - stdio_serial.h: Part Specific Stdio Serial Implementation
 * - read.c : System implementation function used by standard library
 * - write.c : System implementation function used by standard library
 *
 * \section stdio_serialapiinfo utils/stdio/stdio_serial API
 * The stdio_serial API can be found \ref stdio_serial.h "here".
 *
 * \section deviceinfo Device Info
 * All Atmel devices can be used. This example has been tested
 * with the following setup:
 *   - ATXMEGA128A1 XMEGA-A1 Xplained (USB connection to host virtual com port).
 *   - AT32UC3L064 UC3-L0 Xplained (USB connection to host virtual com port).
 *   - SAM4E evaluation kit.
 *
 * \section exampledescription Description of the example
 *   - Send message on serial communication port.
 *   - Performs echo of any received character
 *
 * \section compinfo Compilation Info
 * This software was written for the GNU GCC and IAR for AVR and ARM.
 * Other compilers may or may not work.
 *
 * \section contactinfo Contact Information
 * For further information, visit
 * <A href="http://www.atmel.com">Atmel</A>.\n
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#include <board.h>
#include <sysclk.h>
#include <stdio_serial.h>

#if SAM
#include <conf_uart_serial.h>
#else
#include <conf_usart_serial.h>
#endif

/*! \brief Main function.
 */
int main(void)
{
	uint32_t ch;

	const usart_serial_options_t usart_serial_options = {
		.baudrate     = USART_SERIAL_EXAMPLE_BAUDRATE,
		.charlength   = USART_SERIAL_CHAR_LENGTH,
		.paritytype   = USART_SERIAL_PARITY,
		.stopbits     = USART_SERIAL_STOP_BIT
	};

	sysclk_init();

	/* Initialize the board.  The board-specific conf_board.h file contains
	 * the configuration of the board initialization.
	 */
	board_init();

	// Initialize Serial Interface using Stdio Library
	stdio_serial_init(USART_SERIAL_EXAMPLE, &usart_serial_options);

	// Print welcome message
	printf("\n\rHello ATMEL World!\n\r");

	// Get and echo a character forever.
	while (true) {
		scanf("%c",(char*)&ch);

		if (ch) {
			printf("%c",(char)ch);
		}
	}
}

