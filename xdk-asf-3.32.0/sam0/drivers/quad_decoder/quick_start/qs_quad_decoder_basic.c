/**
 * \file
 *
 * \brief SAM QUAD DECODER Driver Quick Start for SAMB11
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

volatile int16_t	qdec_axis_x,
					qdec_axis_y,
					qdec_axis_z;
volatile bool       qdec_x_overflow,
					qdec_y_overflow,
					qdec_z_overflow;
					
//! [callback_funcs]
static void quad_decoder0_callback(void)
{
	qdec_x_overflow = true;
}

static void quad_decoder1_callback(void)
{
	qdec_y_overflow = true;
}

static void quad_decoder2_callback(void)
{
	qdec_z_overflow = true;
}
//! [callback_funcs]

//! [setup]
static void configure_quad_decoder(void)
{
//! [set_conf]
	struct quad_decoder_config config_quad_decoder;
//! [set_conf]
//! [get_def]
	quad_decoder_get_config_defaults(&config_quad_decoder);
//! [get_def]
//! [setup_pinmux]
	config_quad_decoder.qdec0.pin_number_pad[0] = CONF_QUAD_DECODER_PIN_X_A;
	config_quad_decoder.qdec0.pin_number_pad[1] = CONF_QUAD_DECODER_PIN_X_B;
	config_quad_decoder.qdec1.pin_number_pad[0] = CONF_QUAD_DECODER_PIN_Y_A;
	config_quad_decoder.qdec1.pin_number_pad[1] = CONF_QUAD_DECODER_PIN_Y_B;
	config_quad_decoder.qdec2.pin_number_pad[0] = CONF_QUAD_DECODER_PIN_Z_A;
	config_quad_decoder.qdec2.pin_number_pad[1] = CONF_QUAD_DECODER_PIN_Z_B;

	config_quad_decoder.qdec0.pinmux_sel_pad[0] = CONF_QUAD_DECODER_MUX_X_A;
	config_quad_decoder.qdec0.pinmux_sel_pad[1] = CONF_QUAD_DECODER_MUX_X_B;
	config_quad_decoder.qdec1.pinmux_sel_pad[0] = CONF_QUAD_DECODER_MUX_Y_A;
	config_quad_decoder.qdec1.pinmux_sel_pad[1] = CONF_QUAD_DECODER_MUX_Y_B;
	config_quad_decoder.qdec2.pinmux_sel_pad[0] = CONF_QUAD_DECODER_MUX_Z_A;
	config_quad_decoder.qdec2.pinmux_sel_pad[1] = CONF_QUAD_DECODER_MUX_Z_B;
//! [setup_pinmux]
//! [init_qdec]
	quad_decoder_init(&config_quad_decoder);
//! [init_qdec]

}

static void configure_quad_decoder_callback(void)
{
//! [setup_register_callback]
	quad_decoder_register_callback(QDEC_AXIS_X, quad_decoder0_callback);
	quad_decoder_register_callback(QDEC_AXIS_Y, quad_decoder1_callback);
	quad_decoder_register_callback(QDEC_AXIS_Z, quad_decoder2_callback);
//! [setup_register_callback]
//! [enable_IRQ]
	NVIC_EnableIRQ(25);
//! [enable_IRQ]
}

//! [setup]

int main(void)
{
//! [add_main]
//! [sys_clock]
	system_clock_config(CLOCK_RESOURCE_XO_26_MHZ, CLOCK_FREQ_26_MHZ);
//! [sys_clock]
//! [conf_qdec]
	configure_quad_decoder();
//! [conf_qdec]
//! [conf_callback]	
	configure_quad_decoder_callback();
//! [conf_callback]
//! [add_main]

//! [main_imp]
//! [main_loop]
	while (true) {
//! [main_loop]

//! [get_counter]
		/* Get x,y,z axis current counter */
		qdec_axis_x = quad_decoder_get_counter(QDEC_AXIS_X);
		qdec_axis_y = quad_decoder_get_counter(QDEC_AXIS_Y);
		qdec_axis_z = quad_decoder_get_counter(QDEC_AXIS_Z);
//! [get_counter]
	}
//! [main_imp]
}
