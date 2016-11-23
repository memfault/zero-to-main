/**
 * \file
 *
 * \brief SAM System Clock Driver Quick Start
 *
 * Copyright (C) 2012-2015 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
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
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <asf.h>

void configure_extosc32k(void);
void configure_dfll_open_loop(void);

//! [setup]
//! [config_extosc32k]
void configure_extosc32k(void)
{
//! [config_extosc32k_config]
	struct system_clock_source_xosc32k_config config_ext32k;
//! [config_extosc32k_config]
//! [config_extosc32k_get_defaults]
	system_clock_source_xosc32k_get_config_defaults(&config_ext32k);
//! [config_extosc32k_get_defaults]

//! [config_extosc32k_change_defaults]
	config_ext32k.startup_time = SYSTEM_XOSC32K_STARTUP_4096;
//! [config_extosc32k_change_defaults]

//! [config_extosc32k_set_config]
	system_clock_source_xosc32k_set_config(&config_ext32k);
//! [config_extosc32k_set_config]
}
//! [config_extosc32k]

#if (!SAMC21)
//! [config_dfll]
void configure_dfll_open_loop(void)
{
//! [config_dfll_config]
	struct system_clock_source_dfll_config config_dfll;
//! [config_dfll_config]
//! [config_dfll_get_defaults]
	system_clock_source_dfll_get_config_defaults(&config_dfll);
//! [config_dfll_get_defaults]

//! [config_dfll_set_config]
	system_clock_source_dfll_set_config(&config_dfll);
//! [config_dfll_set_config]
}
//! [config_dfll]
#endif
//! [setup]

int main(void)
{
//! [main]
	/* Configure the external 32KHz oscillator */
//! [config_extosc32k_main]
	configure_extosc32k();
//! [config_extosc32k_main]

	/* Enable the external 32KHz oscillator */
//! [enable_extosc32k_main]
	enum status_code osc32k_status =
			system_clock_source_enable(SYSTEM_CLOCK_SOURCE_XOSC32K);

	if (osc32k_status != STATUS_OK) {
		/* Error enabling the clock source */
	}
//! [enable_extosc32k_main]

#if (!SAMC21)
	/* Configure the DFLL in open loop mode using default values */
//! [config_dfll_main]
	configure_dfll_open_loop();
//! [config_dfll_main]

	/* Enable the DFLL oscillator */
//! [enable_dfll_main]
	enum status_code dfll_status =
			system_clock_source_enable(SYSTEM_CLOCK_SOURCE_DFLL);

	if (dfll_status != STATUS_OK) {
		/* Error enabling the clock source */
	}
//! [enable_dfll_main]

	/* Configure flash wait states before switching to high frequency clock */
//! [set_sys_wait_states]
	system_flash_set_waitstates(2);
//! [set_sys_wait_states]

	/* Change system clock to DFLL */
//! [set_sys_clk_src]
	struct system_gclk_gen_config config_gclock_gen;
	system_gclk_gen_get_config_defaults(&config_gclock_gen);
	config_gclock_gen.source_clock    = SYSTEM_CLOCK_SOURCE_DFLL;
	config_gclock_gen.division_factor = 1;
	system_gclk_gen_set_config(GCLK_GENERATOR_0, &config_gclock_gen);
//! [set_sys_clk_src]
#endif
//! [main]

	while (true) {

	}
}
