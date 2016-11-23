/**
 * \file
 *
 * \brief SAM B11 Xplained Pro board configuration.
 *
 * Copyright (c) 2015-2016 Atmel Corporation. All rights reserved.
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
#ifndef CONF_BOARD_H_INCLUDED
#define CONF_BOARD_H_INCLUDED

#define CONF_QUAD_DECODER_PIN_X_A   PIN_LP_GPIO_15;
#define CONF_QUAD_DECODER_PIN_X_B   PIN_LP_GPIO_16;
#define CONF_QUAD_DECODER_PIN_Y_A   PIN_LP_GPIO_17;
#define CONF_QUAD_DECODER_PIN_Y_B   PIN_LP_GPIO_18;
#define CONF_QUAD_DECODER_PIN_Z_A   PIN_LP_GPIO_19;
#define CONF_QUAD_DECODER_PIN_Z_B   PIN_LP_GPIO_20;

#define CONF_QUAD_DECODER_MUX_X_A	PINMUX_LP_GPIO_15_M_QUAD_DEC0_A;
#define CONF_QUAD_DECODER_MUX_X_B	PINMUX_LP_GPIO_16_M_QUAD_DEC0_B;
#define CONF_QUAD_DECODER_MUX_Y_A	PINMUX_LP_GPIO_17_M_QUAD_DEC1_A;
#define CONF_QUAD_DECODER_MUX_Y_B	PINMUX_LP_GPIO_18_M_QUAD_DEC1_B;
#define CONF_QUAD_DECODER_MUX_Z_A	PINMUX_LP_GPIO_19_M_QUAD_DEC2_A;
#define CONF_QUAD_DECODER_MUX_Z_B	PINMUX_LP_GPIO_20_M_QUAD_DEC2_B;

#endif /* CONF_BOARD_H_INCLUDED */
