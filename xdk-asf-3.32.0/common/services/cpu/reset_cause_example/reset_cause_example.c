/**
 * \file
 *
 * \brief CPU reset cause example
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
 * \section intro Introduction
 * This example demonstrates how to use the reset cause interface.
 *
 * \section files Main Files
 *  - reset_cause_example.c example application
 *
 * \section reset_cause_interface_section services/basic/cpu/reset_cause.h interface
 * The reset cause interface is described in the \ref reset_cause_group section.
 *
 * \section device_info Device Info
 * All AVR devices can be used. This example has been tested with the following
 * setup:
 *  - Xplain evaluation kit
 *
 * \section example_description Description of the example
 * The example will set LEDs on the board depending on the reset cause. The
 * LEDs are wired to reset causes in the following order:
 *  - LED0: power-on-reset reset
 *  - LED1: on-chip debug system reset
 *  - LED2: JTAG reset
 *  - LED3: external reset
 *  - LED4: software reset
 *  - LED5: brown-out (on any power domains) detected reset
 *  - LED6: watchdog timeout reset
 *  - LED7: spike detection reset
 *
 * Where boards have less than the number of LEDs given above, the list is
 * shorted to the number of available LEDs.
 *
 * On boards with at least one button, the first available button will be used
 * to trigger a software reset when pressed.
 *
 * Users will observe different LEDs active depending if the device was reset
 * by toggling power, external reset input, reset triggered by programming and
 * debug tools and finally triggered by pressing the on-board button.
 *
 * \section dependencies Dependencies
 * This example depends on the gpio.h interface.
 *
 * \section compinfo Compilation Info
 * This software was written for the GNU GCC and IAR for AVR. Other compilers
 * may or may not work.
 *
 * \section contactinfo Contact Information
 * For further information, visit <A href="http://www.atmel.com/">Atmel</A>.\n
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#include "board.h"
#include "gpio.h"
#include "reset_cause.h"

/**
 * \brief Main function.
 */
int main(void)
{
	board_init();

#ifdef LED0_GPIO
	if (reset_cause_is_power_on_reset())
		gpio_set_pin_low(LED0_GPIO);
#endif
#ifdef LED1_GPIO
	if (reset_cause_is_ocd())
		gpio_set_pin_low(LED1_GPIO);
#endif
#ifdef LED2_GPIO
	if (reset_cause_is_jtag())
		gpio_set_pin_low(LED2_GPIO);
#endif
#ifdef LED3_GPIO
	if (reset_cause_is_external_reset())
		gpio_set_pin_low(LED3_GPIO);
#endif
#ifdef LED4_GPIO
	if (reset_cause_is_software_reset())
		gpio_set_pin_low(LED4_GPIO);
#endif
#ifdef LED5_GPIO
	if (reset_cause_is_brown_out_detected())
		gpio_set_pin_low(LED5_GPIO);
#endif
#ifdef LED6_GPIO
	if (reset_cause_is_watchdog())
		gpio_set_pin_low(LED6_GPIO);
#endif
#ifdef LED7_GPIO
	if (reset_cause_is_spike_detected())
		gpio_set_pin_low(LED7_GPIO);
#endif

	for (;;) {
#if defined(GPIO_PUSH_BUTTON_0)
		if (gpio_pin_is_low(GPIO_PUSH_BUTTON_0)) {
			reset_do_soft_reset();
		}
#elif defined(GPIO_PUSH_BUTTON_SW2)
		if (gpio_pin_is_low(GPIO_PUSH_BUTTON_SW2)) {
			reset_do_soft_reset();
		}
#else
		/* Board has no buttons available, don't do software reset. */
#endif
	}
}
