/**
 * \file
 *
 * \brief SAM PAC Quick Start
 *
 * Copyright (C) 2012-2015 Atmel Corporation. All rights reserved.
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

void config_port_pins(void);

//! [pin_setup]
void config_port_pins(void)
{
	struct port_config pin_conf;

	port_get_config_defaults(&pin_conf);

	pin_conf.direction  = PORT_PIN_DIR_INPUT;
	pin_conf.input_pull = PORT_PIN_PULL_UP;
	port_pin_set_config(BUTTON_0_PIN, &pin_conf);

	pin_conf.direction = PORT_PIN_DIR_OUTPUT;
	port_pin_set_config(LED_0_PIN, &pin_conf);
}
//! [pin_setup]

int main (void)
{
//! [main]
	system_init();

//! [init]
	config_port_pins();
//! [init]

//! [init_lock]
	system_peripheral_lock(SYSTEM_PERIPHERAL_ID(PORT),
			~SYSTEM_PERIPHERAL_ID(PORT));
//! [init_lock]

//! [enable_interrupts]
#if (SAML21) || (SAML22) || (SAMC21) || defined(__DOXYGEN__)
	system_pac_enable_interrupt();
#endif
	system_interrupt_enable_global();
//! [enable_interrupts]

//! [button_press]
	while (port_pin_get_input_level(BUTTON_0_PIN)) {
		/* Wait for button press */
	}
//! [button_press]

//! [disable_interrupts]
	system_interrupt_enter_critical_section();
//! [disable_interrupts]

//! [unlock_perph]
	system_peripheral_unlock(SYSTEM_PERIPHERAL_ID(PORT),
			~SYSTEM_PERIPHERAL_ID(PORT));
//! [unlock_perph]

//! [alter_config]
	port_pin_toggle_output_level(LED_0_PIN);
//! [alter_config]

//! [lock_perph]
	system_peripheral_lock(SYSTEM_PERIPHERAL_ID(PORT),
			~SYSTEM_PERIPHERAL_ID(PORT));
//! [lock_perph]

//! [enable_interrupts_2]
	system_interrupt_leave_critical_section();
//! [enable_interrupts_2]

//! [inf_loop]
	while (1) {
		/* Do nothing */
	}
//! [inf_loop]
//! [main]
}
