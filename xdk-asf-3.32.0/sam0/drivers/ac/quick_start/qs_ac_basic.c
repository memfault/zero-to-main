/**
 * \file
 *
 * \brief SAM Analog Comparator Driver Quick Start
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

void configure_ac(void);
void configure_ac_channel(void);

//! [setup]
/* AC module software instance (must not go out of scope while in use) */
//! [setup_1]
static struct ac_module ac_instance;
//! [setup_1]

/* Comparator channel that will be used */
//! [setup_2]
#define AC_COMPARATOR_CHANNEL   AC_CHAN_CHANNEL_0
//! [setup_2]

//! [setup_3]
void configure_ac(void)
//! [setup_3]
{
	/* Create a new configuration structure for the Analog Comparator settings
	 * and fill with the default module settings. */
	//! [setup_4]
	struct ac_config config_ac;
	//! [setup_4]
	//! [setup_5]
	ac_get_config_defaults(&config_ac);
	//! [setup_5]

	/* Alter any Analog Comparator configuration settings here if required */

	/* Initialize and enable the Analog Comparator with the user settings */
	//! [setup_6]
	ac_init(&ac_instance, AC, &config_ac);
	//! [setup_6]
}

//! [setup_7]
void configure_ac_channel(void)
//! [setup_7]
{
	/* Create a new configuration structure for the Analog Comparator channel
	 * settings and fill with the default module channel settings. */
	//! [setup_8]
	struct ac_chan_config ac_chan_conf;
	//! [setup_8]
	//! [setup_9]
	ac_chan_get_config_defaults(&ac_chan_conf);
	//! [setup_9]

	/* Set the Analog Comparator channel configuration settings */
	//! [setup_10]
	ac_chan_conf.sample_mode      = AC_CHAN_MODE_SINGLE_SHOT;
	ac_chan_conf.positive_input   = AC_CHAN_POS_MUX_PIN0;
	ac_chan_conf.negative_input   = AC_CHAN_NEG_MUX_SCALED_VCC;
	ac_chan_conf.vcc_scale_factor = 32;
	//! [setup_10]

	/* Set up a pin as an AC channel input */
	//! [setup_11]
	struct system_pinmux_config ac0_pin_conf;
	system_pinmux_get_config_defaults(&ac0_pin_conf);
	ac0_pin_conf.direction    = SYSTEM_PINMUX_PIN_DIR_INPUT;
	ac0_pin_conf.mux_position = CONF_AC_MUX;
	system_pinmux_pin_set_config(CONF_AC_PIN, &ac0_pin_conf);
	//! [setup_11]

	/* Initialize and enable the Analog Comparator channel with the user
	 * settings */
	//! [setup_12]
	ac_chan_set_config(&ac_instance, AC_COMPARATOR_CHANNEL, &ac_chan_conf);
	//! [setup_12]
	//! [setup_13]
	ac_chan_enable(&ac_instance, AC_COMPARATOR_CHANNEL);
	//! [setup_13]
}
//! [setup]

int main(void)
{
	//! [setup_init]
	system_init();
	configure_ac();
	configure_ac_channel();
	//! [setup_14]
	ac_enable(&ac_instance);
	//! [setup_14]
	//! [setup_init]

	//! [main]
	//! [main_1]
	ac_chan_trigger_single_shot(&ac_instance, AC_COMPARATOR_CHANNEL);
	//! [main_1]

	//! [main_2]
	uint8_t last_comparison = AC_CHAN_STATUS_UNKNOWN;
	//! [main_2]

	//! [main_3]
	while (true) {
	//! [main_3]
	//! [main_4]
		if (ac_chan_is_ready(&ac_instance, AC_COMPARATOR_CHANNEL)) {
	//! [main_4]
			//! [main_5]
			do {
				last_comparison = ac_chan_get_status(&ac_instance,
						AC_COMPARATOR_CHANNEL);
			} while (last_comparison & AC_CHAN_STATUS_UNKNOWN);
			//! [main_5]

			//! [main_6]
			port_pin_set_output_level(LED_0_PIN,
					(last_comparison & AC_CHAN_STATUS_NEG_ABOVE_POS));
			//! [main_6]

			//! [main_7]
			ac_chan_trigger_single_shot(&ac_instance, AC_COMPARATOR_CHANNEL);
			//! [main_7]
		}
	}
	//! [main]
}
