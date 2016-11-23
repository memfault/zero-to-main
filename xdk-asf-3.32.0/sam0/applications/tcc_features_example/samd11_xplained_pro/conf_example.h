/**
 * \file
 *
 * \brief SAM D11 Xplained Pro board configuration.
 *
 * Copyright (c) 2014-2015 Atmel Corporation. All rights reserved.
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

#ifndef CONF_EXAMPLE_H_INCLUDED
#define CONF_EXAMPLE_H_INCLUDED


#define TCC_MODE_CIRCULAR_BUFFER
#undef TCC_MODE_PATTERN_GENERATION
#undef TCC_MODE_OTMX_DTI
#undef TCC_MODE_SWAP
#undef TCC_MODE_ONESHOT
#undef TCC_MODE_RAMP2

#ifdef TCC_MODE_CIRCULAR_BUFFER
#define GLCK_SOURCE GCLK_GENERATOR_0
#define TCC_PERIOD_VALUE 0xFF
#define TCC_CLOCK_DIVIDER TCC_CLOCK_PRESCALER_DIV1
#define CC0_Value			0x80
#define CCB0_Value			0xC0
#endif 

#ifdef TCC_MODE_PATTERN_GENERATION
#define GLCK_SOURCE GCLK_GENERATOR_1
#define TCC_PERIOD_VALUE 0xFFFF
#define TCC_CLOCK_DIVIDER TCC_CLOCK_PRESCALER_DIV1
#endif

#ifdef TCC_MODE_OTMX_DTI
#define GLCK_SOURCE GCLK_GENERATOR_0
#define TCC_PERIOD_VALUE 0xFF
#define TCC_CLOCK_DIVIDER TCC_CLOCK_PRESCALER_DIV1
#endif

#ifdef TCC_MODE_SWAP
#define GLCK_SOURCE GCLK_GENERATOR_0
#define TCC_PERIOD_VALUE 0xFF
#define TCC_CLOCK_DIVIDER TCC_CLOCK_PRESCALER_DIV1
#endif

#ifdef TCC_MODE_ONESHOT
#define TCC_PERIOD_VALUE 31250
#define GLCK_SOURCE GCLK_GENERATOR_3
#define TCC_CLOCK_DIVIDER TCC_CLOCK_PRESCALER_DIV256
#endif

#ifdef TCC_MODE_RAMP2
#define GLCK_SOURCE GCLK_GENERATOR_1
#define TCC_PERIOD_VALUE 0xFFFF
#define TCC_CLOCK_DIVIDER TCC_CLOCK_PRESCALER_DIV1
#endif

/* Function Prototypes for the TCC mode operation */

void configure_tcc(void);
void swap_operation(void);
void pattern_generation(void);
void oneshot_operation(void);

#endif /* CONF_EXAMPLE_H_INCLUDED */
