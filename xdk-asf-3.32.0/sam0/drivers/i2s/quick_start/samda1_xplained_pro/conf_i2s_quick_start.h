/**
 * \file
 *
 * \brief I2S Quick Start configuration for SAM DA1 Xplained Pro
 *
 * Copyright (c) 2015 Atmel Corporation. All rights reserved.
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

#ifndef CONF_QUICK_START_POLLED_H_INCLUDED
#define CONF_QUICK_START_POLLED_H_INCLUDED

//! [definition_i2s]
/** I2S module to use */
#define CONF_I2S_MODULE      I2S

/** I2S MCK pin */
#define CONF_I2S_MCK_PIN     PIN_PA09G_I2S_MCK0
/** I2S MCK pin mux */
#define CONF_I2S_MCK_MUX     MUX_PA09G_I2S_MCK0
/** I2S SCK pin */
#define CONF_I2S_SCK_PIN     PIN_PA10G_I2S_SCK0
/** I2S SCK pin mux */
#define CONF_I2S_SCK_MUX     MUX_PA10G_I2S_SCK0
/** I2S FS pin */
#define CONF_I2S_FS_PIN      PIN_PA11G_I2S_FS0
/** I2S FS pin mux */
#define CONF_I2S_FS_MUX      MUX_PA11G_I2S_FS0

/** I2S SD pin */
#define CONF_I2S_SD_PIN      PIN_PA07G_I2S_SD0
/** I2S SD pin mux */
#define CONF_I2S_SD_MUX      MUX_PA07G_I2S_SD0
//! [definition_i2s]

#endif /* CONF_QUICK_START_POLLED_H_INCLUDED */
