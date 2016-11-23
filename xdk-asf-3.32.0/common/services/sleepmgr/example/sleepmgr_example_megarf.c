/**
 * \file
 *
 * \brief Sleep manager example for MegaRF
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
 * This simple example shows how to use the \ref sleepmgr_group.
 *
 * \section files Main files:
 * - sleepmgr_example_megarf.c: Sleep manager example application
 *
 * \section apiinfo Sleep manager API
 * The sleep manager API can be found \ref sleepmgr_group "here".
 *
 * \section deviceinfo Device Info
 * The example has been tested on the STK600 kit.
 *
 * \section exampledescription Description of the example
 * This example puts the device to sleep in sleep modes with increasing "depth"
 * and utilizes the external interrupt to wake it up again.
 *
 * For measuring the current consumption in various sleep mode, an ammeter can
 * be connected on JS2 of ATmega128RFA1-EK1 kit.
 *
 * The device will remain in ACTIVE mode for approximately 3 seconds after wake-
 * up, before it goes to sleep in the next mode.
 *
 * The Yellow Led in ATmega128RFA1-EK1 is On when the device is in active mode
 * and is in off state during sleep. Pressing the pushbutton on the kit will
 * wake the device up and goes to next sleep mode in the following order.
 *		Idle mode.
 *		Power Down mode.
 *	    Power Save mode.
 *		Standby mode.
 *      Extended Standby mode.
 *
 * \section compinfo Compilation Info
 * This software was written for the GNU GCC and IAR for AVR.
 * Other compilers may or may not work.
 *
 * \section contactinfo Contact Information
 * For further information, visit
 * <A href="http://www.atmel.com/">Atmel</A>.\n
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#include <asf.h>
#include "conf_example.h"

/** \brief Main function.
 */
int main(void)
{
	/* Set the sleep mode to initially lock. */
	volatile enum sleepmgr_mode mode = SLEEPMGR_ACTIVE;
    /* Initialize the pins for input and output. */
	board_init();
    /* Initialize the clock and disable clock unused modules */
	sysclk_init();
    /* Initialize the IOPORT */
	ioport_init();
	delay_init(sysclk_get_cpu_hz());

	/* Set the pin sense mode */
	ioport_set_pin_sense_mode(BUTTON_PIN, IOPORT_SENSE_LEVEL);
    
    /* Enable external interrupt */
	external_interrupt_enable(BUTTON_NUMBER);

	/* Turn off the LED		*/
	LED_On(LED_PIN);

	/* Initialize the sleep manager, lock initial mode. */
	sleepmgr_init();
	sleepmgr_lock_mode(mode);

	Enable_global_interrupt();

	do {
		/* Delay for 3 seconds to show the device is awake. */
		delay_ms(3000);

		/* Turn off the LED and go to sleep. */
		LED_Off(LED_PIN);
		sleepmgr_enter_sleep();

		/* Turn on the LED on wake up */
		LED_On(LED_PIN);

		/* Unlock current mode, then lock the next one. */
		sleepmgr_unlock_mode(mode);
		if (++mode < SLEEPMGR_NR_OF_MODES) {
			sleepmgr_lock_mode(mode);
		} else {
			mode = SLEEPMGR_ACTIVE;
			sleepmgr_lock_mode(mode);
		}
	} while (1);
}

ISR(BUTTON_vect)
{
	/* Wait for button release before continuing. */
	delay_ms(10);
	do {
	} while (!ioport_get_pin_level(BUTTON_PIN));
}


