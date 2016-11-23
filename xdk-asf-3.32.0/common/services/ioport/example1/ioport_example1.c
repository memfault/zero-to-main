/**
 * \file
 *
 * \brief Common IOPORT service example 1.
 *
 * Copyright (c) 2012-2015 Atmel Corporation. All rights reserved.
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
 * \mainpage
 * \section intro Introduction
 * This example demonstrates how to use the common IOPORT service for port
 * control.
 *
 * \section files Main Files
 *  - ioport.h common gpio definitions
 *  - ioport_example1.c example application
 *  - conf_example.h example definitions
 *
 * \section ioport_service_section services/ioport/ioport.h
 * The common IOPORT service is described in
 * \ref ioport_group section.
 *
 * \section device_info Device Info
 * All Atmel SAM, MEGA, XMEGA and UC3 devices can be used. This example has been
 * tested with the following setup:
 *  - Xplain evaluation kit
 *  - EVK1100 evaluation kit
 *  - SAM3X evaluation kit
 *  - SAM4L evaluation kit
 *  - SAM4L Xplained Pro kit
 *  - SAM4L8 Xplained Pro kit
 *  - SAM4E evaluation kit
 *  - SAM4N Xplained Pro kit
 *  - STK600 evaluation Kit (Tested with STK600-ATMEGA128RFA1)
 *  - ATmega256RFR2 Xplained Pro kit
 *  - SAM4C evaluation kit
 *  - SAM4CP16BMB evaluation board (no button version)
 *  - SAMG53 Xplained Pro kit
 *  - SAMG55 Xplained Pro kit
 *  - SAM4CMP16C demo board
 *  - SAM4CMS16C demo board
 *  - SAMV71 Xplained Ultra kit
 *  - SAME70 Xplained Pro kit
 *
 * \section example_description Description of the example
 * This example flashes a group of LEDs present on a port with flash speed of
 * 1Hz.
 * For STK600 with STK600-ATMEGA128RFA1, need to connect a 10 Pin cable from
 * PORTB to Led header
 * Additionally a group of inputs can inspected from a debug session.
 *
 * \section compinfo Compilation Info
 * This software was written for the GNU GCC and IAR for SAM and AVR.
 * Other compilers may or may not work.
 *
 * \section contactinfo Contact Information
 * For further information, visit <a href="http://www.atmel.com/">Atmel</a>.\n
 * Support and FAQ: http://www.atmel.com/design-support/
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <asf.h>
#include "conf_example.h"

int main(void)
{
	/* Use static volatile to make it available in debug watch */
	static volatile ioport_port_mask_t port_val;

	sysclk_init();
	board_init();
	ioport_init();

	delay_init(sysclk_get_cpu_hz());

	/* Set output direction on the given LED IOPORTs */
	ioport_set_port_dir(EXAMPLE_LED_PORT, EXAMPLE_LED_MASK,
			IOPORT_DIR_OUTPUT);

#ifdef EXAMPLE_BUTTON_PORT
	/* Set direction and pullup on the given button IOPORT */
	ioport_set_port_dir(EXAMPLE_BUTTON_PORT, EXAMPLE_BUTTON_MASK,
			IOPORT_DIR_INPUT);
	ioport_set_port_mode(EXAMPLE_BUTTON_PORT, EXAMPLE_BUTTON_MASK,
			IOPORT_MODE_PULLUP);

	/* Set LED IOPORTs high */
	ioport_set_port_level(EXAMPLE_LED_PORT, EXAMPLE_LED_MASK,
			IOPORT_PIN_LEVEL_HIGH);
#endif

	while (true) {
		/* Toggle LED IOPORTs with half a second interval */
		ioport_toggle_port_level(EXAMPLE_LED_PORT, EXAMPLE_LED_MASK);
		delay_ms(500);

#ifdef EXAMPLE_BUTTON_PORT
		/* Get value from button port */
		/* Use watch with debugger to see it */
		port_val = ioport_get_port_level(EXAMPLE_BUTTON_PORT,
				EXAMPLE_BUTTON_MASK);
#endif
	}
}
