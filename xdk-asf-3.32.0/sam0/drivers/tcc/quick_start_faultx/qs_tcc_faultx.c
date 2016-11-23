/**
 * \file
 *
 * \brief SAM TCC - Timer Counter for Control Applications Callback Driver Quick Start (with Non-Recoverable Fault)
 *
 * Copyright (C) 2014-2015 Atmel Corporation. All rights reserved.
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
 *
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#include <asf.h>
#include <conf_quick_start_faultx.h>

//! [additional_include]
#include <string.h>
//! [additional_include]

//! [module_inst]
struct tcc_module tcc_instance;
//! [module_inst]

//! [events_resource]
struct events_resource event_resource;
//! [events_resource]

//! [callback_funcs]
static void tcc_callback_to_change_duty_cycle(
		struct tcc_module *const module_inst)
{
	static uint32_t delay = 10;
	static uint32_t i = 0;

	if (--delay) {
		return;
	}
	delay = 10;
	i = (i + 0x0800) & 0xFFFF;
	tcc_set_compare_value(module_inst,
			(enum tcc_match_capture_channel)
					(TCC_MATCH_CAPTURE_CHANNEL_0 + CONF_PWM_CHANNEL),
			i + 1);
}
//! [callback_funcs]

//! [setup]
static void configure_tcc(void)
{
	//! [setup_config]
	struct tcc_config config_tcc;
	//! [setup_config]
	//! [setup_config_defaults]
	tcc_get_config_defaults(&config_tcc, CONF_PWM_MODULE);
	//! [setup_config_defaults]

	//! [setup_change_config]
	config_tcc.counter.period = 0xFFFF;
	config_tcc.compare.wave_generation = TCC_WAVE_GENERATION_SINGLE_SLOPE_PWM;
	config_tcc.compare.match[CONF_PWM_CHANNEL] = 0xFFFF;
	//! [setup_change_config]
	//! [setup_change_config_faults]
	config_tcc.wave_ext.non_recoverable_fault[0].output = TCC_FAULT_STATE_OUTPUT_1;
	//! [setup_change_config_faults]
	//! [setup_change_config_pwm]
	config_tcc.pins.enable_wave_out_pin[CONF_PWM_OUTPUT] = true;
	config_tcc.pins.wave_out_pin[CONF_PWM_OUTPUT]        = CONF_PWM_OUT_PIN;
	config_tcc.pins.wave_out_pin_mux[CONF_PWM_OUTPUT]    = CONF_PWM_OUT_MUX;
	//! [setup_change_config_pwm]

	//! [setup_set_config]
	tcc_init(&tcc_instance, CONF_PWM_MODULE, &config_tcc);
	//! [setup_set_config]

	//! [setup_events]
	struct tcc_events events;
	memset(&events, 0, sizeof(struct tcc_events));
	//! [setup_events]

	//! [setup_change_events_faults]
	events.on_input_event_perform_action[0] = true;
	events.input_config[0].modify_action = true;
	events.input_config[0].action = TCC_EVENT_ACTION_NON_RECOVERABLE_FAULT;
	//! [setup_change_events_faults]

	//! [setup_events_enable]
	tcc_enable_events(&tcc_instance, &events);
	//! [setup_events_enable]

	//! [setup_enable]
	tcc_enable(&tcc_instance);
	//! [setup_enable]
}

static void configure_tcc_callbacks(void)
{
	//! [setup_register_callback]
	tcc_register_callback(
			&tcc_instance,
			tcc_callback_to_change_duty_cycle,
			(enum tcc_callback)(TCC_CALLBACK_CHANNEL_0 + CONF_PWM_CHANNEL));
	//! [setup_register_callback]

	//! [setup_enable_callback]
	tcc_enable_callback(&tcc_instance,
			(enum tcc_callback)(TCC_CALLBACK_CHANNEL_0 + CONF_PWM_CHANNEL));
	//! [setup_enable_callback]
}
//! [setup]

//! [callback_eic]
static void eic_callback_to_clear_halt(void)
{
	if (port_pin_get_input_level(CONF_FAULT_EIC_PIN)) {
		tcc_clear_status(&tcc_instance,
				TCC_STATUS_NON_RECOVERABLE_FAULT_OCCUR(0));
	}
}
//! [callback_eic]

//! [config_eic]
static void configure_eic(void)
{
	//! [eic_chan_setup]
	//! [eic_setup_1]
	struct extint_chan_conf config;
	//! [eic_setup_1]
	//! [eic_setup_2]
	extint_chan_get_config_defaults(&config);
	//! [eic_setup_2]
	//! [eic_setup_3]
	config.filter_input_signal = true;
	config.detection_criteria  = EXTINT_DETECT_BOTH;
	config.gpio_pin     = CONF_FAULT_EIC_PIN;
	config.gpio_pin_mux = CONF_FAULT_EIC_PIN_MUX;
	//! [eic_setup_3]
	//! [eic_setup_4]
	extint_chan_set_config(CONF_FAULT_EIC_LINE, &config);
	//! [eic_setup_4]
	//! [eic_chan_setup]

	//! [eic_event_setup]
	//! [eic_event_setup_1]
	struct extint_events events;
	memset(&events, 0, sizeof(struct extint_events));
	//! [eic_event_setup_1]
	//! [eic_event_setup_2]
	events.generate_event_on_detect[CONF_FAULT_EIC_LINE] = true;
	//! [eic_event_setup_2]
	//! [eic_event_setup_3]
	extint_enable_events(&events);
	//! [eic_event_setup_3]
	//! [eic_event_setup]

	//! [eic_callback_setup]
	//! [eic_callback_setup_1]
	extint_register_callback(eic_callback_to_clear_halt,
			CONF_FAULT_EIC_LINE, EXTINT_CALLBACK_TYPE_DETECT);
	//! [eic_callback_setup_1]
	//! [eic_callback_setup_2]
	extint_chan_enable_callback(CONF_FAULT_EIC_LINE,
			EXTINT_CALLBACK_TYPE_DETECT);
	//! [eic_callback_setup_2]
	//! [eic_callback_setup]
}
//! [config_eic]

//! [config_event]
static void configure_event(void)
{
	//! [event_setup_1]
	struct events_config config;
	//! [event_setup_1]

	//! [event_setup_2]
	events_get_config_defaults(&config);
	//! [event_setup_2]

	//! [event_setup_3]
	config.generator = CONF_FAULT_EVENT_GENERATOR;
	config.path      = EVENTS_PATH_ASYNCHRONOUS;
	//! [event_setup_3]

	//! [event_setup_4]
	events_allocate(&event_resource, &config);
	//! [event_setup_4]

	//! [event_setup_5]
	events_attach_user(&event_resource, CONF_FAULT_EVENT_USER);
	//! [event_setup_5]
}
//! [config_event]

int main(void)
{
	system_init();

//! [setup_init]
	configure_tcc();
	configure_tcc_callbacks();

	configure_eic();
	configure_event();
//! [setup_init]

//! [main]
	//! [enable_global_interrupts]
	system_interrupt_enable_global();
	//! [enable_global_interrupts]

	//! [main_loop]
	while (true) {
	}
	//! [main_loop]
//! [main]
}
