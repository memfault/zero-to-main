/**
 * \file
 *
 * \brief SAM Generic Clock Driver Quick Start
 *
 * Copyright (C) 2012-2016 Atmel Corporation. All rights reserved.
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

void configure_gclock_generator(void);
void configure_gclock_channel(void);

//! [setup]
void configure_gclock_generator(void)
{
//! [setup_1]
	struct system_gclk_gen_config gclock_gen_conf;
//! [setup_1]
//! [setup_2]
	system_gclk_gen_get_config_defaults(&gclock_gen_conf);
//! [setup_2]

#if (SAML21) || (SAML22) || (SAMR30)
//! [setup_3]
	gclock_gen_conf.source_clock    = SYSTEM_CLOCK_SOURCE_OSC16M;
	gclock_gen_conf.division_factor = 128;
//! [setup_3]
#elif (SAMC21)
//! [setup_3]
	gclock_gen_conf.source_clock    = SYSTEM_CLOCK_SOURCE_OSC48M;
	gclock_gen_conf.division_factor = 128;
//! [setup_3]
#else
//! [setup_3]
	gclock_gen_conf.source_clock    = SYSTEM_CLOCK_SOURCE_OSC8M;
	gclock_gen_conf.division_factor = 128;
//! [setup_3]
#endif

//! [setup_4]
	system_gclk_gen_set_config(GCLK_GENERATOR_1, &gclock_gen_conf);
//! [setup_4]

//! [setup_5]
	system_gclk_gen_enable(GCLK_GENERATOR_1);
//! [setup_5]
}

void configure_gclock_channel(void)
{
//! [setup_6]
	struct system_gclk_chan_config gclk_chan_conf;
//! [setup_6]
//! [setup_7]
	system_gclk_chan_get_config_defaults(&gclk_chan_conf);
//! [setup_7]

//! [setup_8]
	gclk_chan_conf.source_generator = GCLK_GENERATOR_1;
//! [setup_8]
#if (SAMD10) || (SAMD11) || SAMR30
//! [setup_9]
	system_gclk_chan_set_config(TC1_GCLK_ID, &gclk_chan_conf);
//! [setup_9]

//! [setup_10]
	system_gclk_chan_enable(TC1_GCLK_ID);
//! [setup_10]
#else
//! [setup_9]
	system_gclk_chan_set_config(TC3_GCLK_ID, &gclk_chan_conf);
//! [setup_9]

//! [setup_10]
	system_gclk_chan_enable(TC3_GCLK_ID);
//! [setup_10]
#endif
}
//! [setup]

int main(void)
{
	//! [setup_init]
	configure_gclock_generator();
	configure_gclock_channel();
	//! [setup_init]

	//! [main]
	while (true) {
		/* Nothing to do */
	}
	//! [main]
}
