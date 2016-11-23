/**
 * \file
 *
 * \brief SAM Event System Driver Quick Start
 *
 * Copyright (C) 2013-2015 Atmel Corporation. All rights reserved.
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
#include "conf_qs_events.h"

//! [setup]

static void configure_event_channel(struct events_resource *resource)
{
//! [setup_1]
	struct events_config config;
//! [setup_1]

//! [setup_2]
	events_get_config_defaults(&config);
//! [setup_2]

//! [setup_3]
	config.generator      = CONF_EVENT_GENERATOR;
	config.edge_detect    = EVENTS_EDGE_DETECT_RISING;
	config.path           = EVENTS_PATH_SYNCHRONOUS;
	config.clock_source   = GCLK_GENERATOR_0;
//! [setup_3]

//! [setup_4]
	events_allocate(resource, &config);
//! [setup_4]
}

static void configure_event_user(struct events_resource *resource)
{
//! [setup_5]
	events_attach_user(resource, CONF_EVENT_USER);
//! [setup_5]
}

//! [setup]

int main(void)
{
//! [events_resource_struct]
	struct events_resource example_event;
//! [events_resource_struct]

	system_init();

//! [setup_init]
	configure_event_channel(&example_event);
	configure_event_user(&example_event);
//! [setup_init]

	//! [main]

	//! [main_1]
	while (events_is_busy(&example_event)) {
		/* Wait for channel */
	};
	//! [main_1]

	//! [main_2]
	events_trigger(&example_event);
	//! [main_2]

	while (true) {
		/* Nothing to do */
	}

	//! [main]
}
