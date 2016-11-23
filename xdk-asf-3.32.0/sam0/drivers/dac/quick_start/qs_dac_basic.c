/**
 * \file
 *
 * \brief SAM DAC Quick Start
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

void configure_dac(void);
void configure_dac_channel(void);

//! [module_inst]
struct dac_module dac_instance;
//! [module_inst]

//! [setup]
void configure_dac(void)
{
//! [setup_config]
	struct dac_config config_dac;
//! [setup_config]
//! [setup_config_defaults]
	dac_get_config_defaults(&config_dac);
//! [setup_config_defaults]

//! [setup_set_config]
	dac_init(&dac_instance, DAC, &config_dac);
//! [setup_set_config]
}

void configure_dac_channel(void)
{
//! [setup_ch_config]
	struct dac_chan_config config_dac_chan;
//! [setup_ch_config]
//! [setup_ch_config_defaults]
	dac_chan_get_config_defaults(&config_dac_chan);
//! [setup_ch_config_defaults]

//! [setup_ch_set_config]
	dac_chan_set_config(&dac_instance, DAC_CHANNEL_0, &config_dac_chan);
//! [setup_ch_set_config]

//! [setup_ch_enable]
	dac_chan_enable(&dac_instance, DAC_CHANNEL_0);
//! [setup_ch_enable]
}
//! [setup]

int main(void)
{
	system_init();

//! [setup_init]
	configure_dac();
	configure_dac_channel();
//! [setup_init]

//! [setup_enable]
	dac_enable(&dac_instance);
//! [setup_enable]

//! [main]
//! [main_output_var]
	uint16_t i = 0;
//! [main_output_var]

//! [main_loop]
	while (1) {
//! [main_loop]
//! [main_write]
		dac_chan_write(&dac_instance, DAC_CHANNEL_0, i);
//! [main_write]

//! [main_inc_val]
		if (++i == 0x3FF) {
			i = 0;
		}
//! [main_inc_val]
	}
//! [main]
}
