/**
 * \file
 *
 * \mainpage
 *
 * \section title Led Chaser example
 *
 * \section file File(s)
 * - \ref led_example.c
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
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */


#include <compiler.h>
#include <sysclk.h>
#include <board.h>
#include <gpio.h>
#include "conf_example.h"
#include "conf_board.h"

#define INTERVAL_MS 80

void light_single_led(uint8_t led_pin);

#if (UC3A || UC3B || UC3C || UC3D ||UC3L)
static void mdelay(unsigned int ms)
{
	int32_t count, count_end;

	count = Get_system_register(AVR32_COUNT);
	count_end = count + ((sysclk_get_cpu_hz() + 999) / 1000) * ms;

	while ((count_end - count) > 0)
		count = Get_system_register(AVR32_COUNT);
}
#elif XMEGA
static void mdelay(uint16_t ms)
{
	uint32_t count;

	// Approximate the number of loop iterations needed.
	count = sysclk_get_cpu_hz() / 6;
	count *= ms;
	count /= 1000;

	do {
		asm("");
	} while (--count);
}
#endif


void light_single_led(uint8_t led_pin){
	//clear all LEDs
	#if XMEGA
	  gpio_set_pin_group_high(LED_CHASER_PORT_ID, LED_CHASER_PORT_MASK);
	#else
	  gpio_set_group_high(LED_CHASER_PORT_ID, LED_CHASER_PORT_MASK);
	#endif
	//set single LED
	gpio_set_pin_low(led_pin);
}

int main(void)
{
	sysclk_init();
	board_init();

	while (1) {
		#if LED_COUNT > 0
		light_single_led(LED0_GPIO);
		mdelay(INTERVAL_MS);
		#endif

		#if LED_COUNT > 1
		light_single_led(LED1_GPIO);
		mdelay(INTERVAL_MS);
		#endif

		#if LED_COUNT > 2
		light_single_led(LED2_GPIO);
		mdelay(INTERVAL_MS);
		#endif

		#if LED_COUNT > 3
		light_single_led(LED3_GPIO);
		mdelay(INTERVAL_MS);
		#endif

		#if LED_COUNT > 4
		light_single_led(LED4_GPIO);
		mdelay(INTERVAL_MS);
		#endif

		#if LED_COUNT > 5
		light_single_led(LED5_GPIO);
		mdelay(INTERVAL_MS);
		#endif

		#if LED_COUNT > 6
		light_single_led(LED6_GPIO);
		mdelay(INTERVAL_MS);
		#endif

		#if LED_COUNT > 7
		light_single_led(LED7_GPIO);
		mdelay(INTERVAL_MS);
		#endif
	}
}
