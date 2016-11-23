/**
 * \file
 *
 * \brief Clock system example 2
 *
 * Copyright (c) 2014-2015 Atmel Corporation. All rights reserved.
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
 *
 * \section intro Introduction
 * This example shows how to initialize the clock system and output the
 * CPU clock on a dedicated pin.
 *
 * \section files Main files:
 * - clock_example2_xmega.c: clock system example application
 * - conf_board.h: board initialization configuration
 * - conf_clock.h: system clock configuration
 * - conf_example2.h: chip- or board-specific example configuration
 *
 * \section deviceinfo Device Info
 * All AVR XMEGA devices can be used.
 *
 * \section exampledescription Description of the example
 * Pin 7 (\ref IOPORT_PIN) on a configurable port (\ref CLKOUT_PORT) is used for
 * output of the CPU clock signal.
 *
 * The main system clock source and prescalers are defined in conf_clock.h.
 * The port to output the clock signal on is defined in conf_example2.h.
 *
 * Refer to the \ref clk_group API documentation for further information on the
 * clock configuration, and the \ref port_driver_group API documentation for
 * further information on the pin configuration.
 *
 * \section compinfo Compilation Info
 * This software was written for the GNU GCC and IAR for AVR.
 * Other compilers may or may not work.
 *
 * \section contactinfo Contact Information
 * For further information, visit
 * <A href="http://www.atmel.com/">Atmel</A>.\n
 */

//! \name Example configuration
//@{
/**
 * \def CLKOUT_PORT
 * \brief Port to output clock signal on
 *
 * This is the configuration for the clock output port, and must be defined as
 * one of the \c PORTCFG_CLKOUT_t settings of the device header file.
 *
 * \note It is only possible to select the port, not the pin: the clock signal
 * will be output on pin 7 of the configured port.
 */
/**
 * \def IOPORT_PIN
 * \brief Pin to set as output for clock signal
 *
 * This must be defined as IOPORT pin 7 of the port setting in CLKOUT_PORT.
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
//@}

#include <compiler.h>
#include <sysclk.h>
#include <ioport.h>
#include <conf_example2.h>

int main(void)
{
	sysclk_init();
	board_init();

	ioport_configure_pin(IOPORT_PIN, IOPORT_DIR_OUTPUT);
	PORTCFG.CLKEVOUT = CLKOUT_PORT;

	while (1) {
		/* Do nothing */
	}
}
