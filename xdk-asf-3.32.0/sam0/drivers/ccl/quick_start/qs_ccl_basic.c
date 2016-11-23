/**
 * \file
 *
 * \brief SAM CCL Driver Quick Start
 *
 * Copyright (C) 2014-2015 Atmel Corporation. All rights reserved.
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

void configure_ccl(void);
void configure_ccl_lut0(void);
void configure_ccl_lut1(void);

//! [setup]
void configure_ccl(void)
{
	/** Creates a new configuration structure for the CCL. */
	//! [setup_1]
	struct ccl_config conf;
	//! [setup_1]

	/** Settings and fill with the default settings. */
	//! [setup_2]
	ccl_get_config_defaults(&conf);
	//! [setup_2]

	/** Initialize the CCL with the user settings. */
	//! [setup_3]
	ccl_init(&conf);
	//! [setup_3]
}

void configure_ccl_lut0(void)
{
	/** Creates a new configuration structure for the LUT0. */
	//! [setup_4]
	struct ccl_lut_config conf;
	//! [setup_4]

	/** Settings and fill with the default settings. */
	//! [setup_5]
	ccl_lut_get_config_defaults(&conf);
	//! [setup_5]

	/** Set the LUT0. */
	//! [setup_6]
	conf.truth_table_value = 0x02;
	conf.input0_src_sel = CCL_LUT_INPUT_SRC_IO;
	conf.input1_src_sel = CCL_LUT_INPUT_SRC_IO;
	conf.input2_src_sel = CCL_LUT_INPUT_SRC_IO;
	conf.filter_sel = CCL_LUTCTRL_FILTSEL_FILTER;
	//! [setup_6]

	/** Set up LUT0 input and output pin. */
	//! [setup_7]
	struct system_pinmux_config lut0_input_pin0_conf, lut0_input_pin1_conf, lut0_input_pin2_conf;
	system_pinmux_get_config_defaults(&lut0_input_pin0_conf);
	system_pinmux_get_config_defaults(&lut0_input_pin1_conf);
	system_pinmux_get_config_defaults(&lut0_input_pin2_conf);
	lut0_input_pin0_conf.direction    = SYSTEM_PINMUX_PIN_DIR_INPUT;
	lut0_input_pin0_conf.mux_position = CCL_LUT0_IN0_MUX;
	lut0_input_pin1_conf.direction    = SYSTEM_PINMUX_PIN_DIR_INPUT;
	lut0_input_pin1_conf.mux_position = CCL_LUT0_IN1_MUX;
	lut0_input_pin2_conf.direction    = SYSTEM_PINMUX_PIN_DIR_INPUT;
	lut0_input_pin2_conf.mux_position = CCL_LUT0_IN2_MUX;
	system_pinmux_pin_set_config(CCL_LUT0_IN0_PIN, &lut0_input_pin0_conf);
	system_pinmux_pin_set_config(CCL_LUT0_IN1_PIN, &lut0_input_pin1_conf);
	system_pinmux_pin_set_config(CCL_LUT0_IN2_PIN, &lut0_input_pin2_conf);
	struct system_pinmux_config lut0_out_pin_conf;
	system_pinmux_get_config_defaults(&lut0_out_pin_conf);
	lut0_out_pin_conf.direction    = SYSTEM_PINMUX_PIN_DIR_OUTPUT;
	lut0_out_pin_conf.mux_position = CCL_LUT0_OUT_MUX;
	system_pinmux_pin_set_config(CCL_LUT0_OUT_PIN, &lut0_out_pin_conf);
	//! [setup_7]

	/** Initialize and enable the LUT0 with the user settings. */
	//! [setup_8]
	ccl_lut_set_config(CCL_LUT_0, &conf);
	//! [setup_8]
}

void configure_ccl_lut1(void)
{
	/** Creates a new configuration structure for the LUT1. */
	//! [setup_9]
	struct ccl_lut_config conf;
	//! [setup_9]

	/** Settings and fill with the default settings. */
	//! [setup_10]
	ccl_lut_get_config_defaults(&conf);
	//! [setup_10]

	/** Set the LUT1. */
	//! [setup_11]
	conf.truth_table_value = 0x02;
	conf.input0_src_sel = CCL_LUT_INPUT_SRC_IO;
	conf.input1_src_sel = CCL_LUT_INPUT_SRC_IO;
	conf.input2_src_sel = CCL_LUT_INPUT_SRC_IO;
	conf.filter_sel = CCL_LUTCTRL_FILTSEL_FILTER;
	//! [setup_11]

	/** Set up LUT1 input and output pin. */
	//! [setup_12]
	struct system_pinmux_config lut1_input_pin0_conf, lut1_input_pin1_conf, lut1_input_pin2_conf;
	system_pinmux_get_config_defaults(&lut1_input_pin0_conf);
	system_pinmux_get_config_defaults(&lut1_input_pin1_conf);
	system_pinmux_get_config_defaults(&lut1_input_pin2_conf);
	lut1_input_pin0_conf.direction    = SYSTEM_PINMUX_PIN_DIR_INPUT;
	lut1_input_pin0_conf.mux_position = CCL_LUT1_IN0_MUX;
	lut1_input_pin1_conf.direction    = SYSTEM_PINMUX_PIN_DIR_INPUT;
	lut1_input_pin1_conf.mux_position = CCL_LUT1_IN1_MUX;
	lut1_input_pin2_conf.direction    = SYSTEM_PINMUX_PIN_DIR_INPUT;
	lut1_input_pin2_conf.mux_position = CCL_LUT1_IN2_MUX;
	system_pinmux_pin_set_config(CCL_LUT1_IN0_PIN, &lut1_input_pin0_conf);
	system_pinmux_pin_set_config(CCL_LUT1_IN1_PIN, &lut1_input_pin1_conf);
	system_pinmux_pin_set_config(CCL_LUT1_IN2_MUX, &lut1_input_pin2_conf);
	struct system_pinmux_config lut1_out_pin_conf;
	system_pinmux_get_config_defaults(&lut1_out_pin_conf);
	lut1_out_pin_conf.direction    = SYSTEM_PINMUX_PIN_DIR_OUTPUT;
	lut1_out_pin_conf.mux_position = CCL_LUT1_OUT_MUX;
	system_pinmux_pin_set_config(CCL_LUT1_OUT_PIN, &lut1_out_pin_conf);
	//! [setup_12]

	/** Initialize and enable the LUT1 with the user settings. */
	//! [setup_13]
	ccl_lut_set_config(CCL_LUT_1, &conf);
	//! [setup_13]
}
//! [setup]

int main(void)
{
	system_init();

	//! [setup_init]
	configure_ccl();
	configure_ccl_lut0();
	configure_ccl_lut1();
	/** Configure the sequential logic with the D flip flop mode. */
	//! [setup_14]
	ccl_seq_config(CCL_SEQ_0, CCL_SEQ_D_FLIP_FLOP);
	//! [setup_14]
	//! [setup_init]

	//! [setup_enable]
	/** Enable CCL module. */
	ccl_lut_enable(CCL_LUT_0);
	ccl_lut_enable(CCL_LUT_1);
	ccl_module_enable();
	//! [setup_enable]

	//! [main]
	while (true) {
		/* Do nothing */
	}
	//! [main]
}
