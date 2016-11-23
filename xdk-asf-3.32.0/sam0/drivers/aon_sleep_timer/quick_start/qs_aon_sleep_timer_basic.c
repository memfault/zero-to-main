/**
 * \file
 *
 * \brief SAM AON Sleep Timer Driver Quick Start for SAMB11
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
#include "conf_aon_sleep_timer.h"

//! [setup]

//! [callback_funcs]
static void aon_sleep_timer_callback(void)
{
	gpio_pin_set_output_level(LED_0_PIN, LED_0_ACTIVE);
}
//! [callback_funcs]

static void configure_gpio_pins(void)
{
//! [setup_1]
	struct gpio_config config_gpio_pin;
//! [setup_1]
//! [setup_2]
	gpio_get_config_defaults(&config_gpio_pin);
//! [setup_2]
//! [setup_3]
	config_gpio_pin.direction = GPIO_PIN_DIR_OUTPUT;
//! [setup_3]
//! [setup_4]
	gpio_pin_set_config(LED_0_PIN, &config_gpio_pin);
//! [setup_4]
//! [setup_5]
	gpio_pin_set_output_level(LED_0_PIN, LED_0_INACTIVE);
//! [setup_5]
}

static void configure_aon_sleep_timer(void)
{
//! [setup_6]
	struct aon_sleep_timer_config config_aon_sleep_timer;
//! [setup_6]
//! [setup_7]
	aon_sleep_timer_get_config_defaults(&config_aon_sleep_timer);
//! [setup_7]
//! [setup_8]
	config_aon_sleep_timer.counter = CONF_AON_SLEEP_COUNTER;
//! [setup_8]
//! [setup_9]
	aon_sleep_timer_init(&config_aon_sleep_timer);
//! [setup_9]

}

static void configure_aon_sleep_timer_callback(void)
{
	//! [setup_register_callback]
	aon_sleep_timer_register_callback(aon_sleep_timer_callback);
	//! [setup_register_callback]

	//! [enable_IRQ]
	NVIC_EnableIRQ(AON_SLEEP_TIMER0_IRQn);
	//! [enable_IRQ]
}

//! [setup]

int main(void)
{
	/**
	 * For make this QS work, disable the systick to stop task switch.
	 * Should not do it if you want the BLE functions.
	 */
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;

	//! [setup_init]
	system_clock_config(CLOCK_RESOURCE_XO_26_MHZ, CLOCK_FREQ_26_MHZ);

	//! [config_gpio]
	configure_gpio_pins();
	//! [config_gpio]

	//! [config_timer]
	configure_aon_sleep_timer();
	//! [config_timer]

	configure_aon_sleep_timer_callback();
	//! [setup_init]

	//! [timer_active]
	while(!aon_sleep_timer_sleep_timer_active());
	//! [timer_active]
	//! [wait_wfi]
	asm volatile ("wfi");
	asm volatile ("nop");
	//! [wait_wfi]

	//! [main_imp]
	//! [main_loop]
	while (true) {
	}
	//! [main_loop]
	//! [main_imp]
}
