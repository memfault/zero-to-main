/**
 * \file
 *
 * \brief SAM GPIO PINMUX Driver Quick Start
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

int main(void)
{
	system_init();

	//! [setup]
	//! [pinmux_config]
	struct system_pinmux_config config_pinmux;
	//! [pinmux_config]
	//! [pinmux_config_defaults]
	system_pinmux_get_config_defaults(&config_pinmux);
	//! [pinmux_config_defaults]

	//! [pinmux_update_config_values]
	config_pinmux.mux_position = SYSTEM_PINMUX_GPIO;
	config_pinmux.direction    = SYSTEM_PINMUX_PIN_DIR_INPUT;
	config_pinmux.input_pull   = SYSTEM_PINMUX_PIN_PULL_UP;
	//! [pinmux_update_config_values]

	//! [pinmux_set_config]
	system_pinmux_pin_set_config(10, &config_pinmux);
	//! [pinmux_set_config]
	//! [setup]

	//! [main]
	//! [pinmux_change_input_sampling]
	system_pinmux_pin_set_input_sample_mode(10,
			SYSTEM_PINMUX_PIN_SAMPLE_ONDEMAND);
	//! [pinmux_change_input_sampling]

	while (true) {
		/* Infinite loop */
	}
	//! [main]
}
