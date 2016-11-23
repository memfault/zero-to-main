/**
 * \file
 *
 * \brief Example application 1 for calendar functionality
 *
 * Copyright (C) 2011-2015 Atmel Corporation. All rights reserved.
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
#include <stdint.h>
#include <calendar.h>
#include <asf.h>
#include <led.h>

/**
 * \mainpage
 *
 * \section intro Introduction
 * This is an example application for the \ref calendar_group "calendar"
 * functionality.
 *
 * \section device_info Device Info
 * All AVR devices can be used.
 * This example has been tested with the following setup:
 * - XMEGA-A1 Xplain
 * - UC3-L0 Xplained
 * - STK600+RCUC3L4
 * - STK600 with RCUC3D extension board (Connect STK600.PORTA.PA4 -> STK600.LEDS.LED0)
 *
 * \section description Description of the example application
 * This application will convert a date to a known timestamp, and turn on a
 * LED if the timestamp is correct.
 *
 * \section dependencies Dependencies
 * Relevant module dependencies for this application are:
 * - \ref calendar_group
 *
 * \section compinfo Compilation info
 * This software was written for the GNU GCC and IAR for AVR. Other compilers
 * may or may not work.
 *
 * \section contactinfo Contact Information
 * For further information, visit <a href="http://www.atmel.com/">Atmel</a>.\n
 * Support and FAQ: http://www.atmel.com/design-support/
 */

/**
 * \brief Main entry of example application
 */
int main(void)
{
	board_init();
	sysclk_init();

	// Initialize the platform LED's.
	LED_Off(LED0_GPIO);

	// Randomly selected date to convert to timestamp
	struct calendar_date date = {
		.second = 12,
		.minute = 1,
		.hour = 22,
		.date = 8,
		.month = 2,
		.year = 1985
	};
	uint32_t timestamp = 479253672;

	// Convert date to timestamp
	uint32_t timestamp2 = calendar_date_to_timestamp(&date);

	/*
	* Check that generated timestamp matches provided timestamp and turn on LED
	*/
	if (timestamp == timestamp2) {
		LED_On(LED0_GPIO);
	}

	// Infinite loop
	while(1) {
		// Intentionally left empty.
	};
}
