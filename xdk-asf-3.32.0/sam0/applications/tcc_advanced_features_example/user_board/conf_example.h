/**
 * \file
 *
 * \brief SAM D21 TCC Advanced Features example configuration
 *
 * Copyright (C) 2015 Atmel Corporation. All rights reserved.
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


#ifndef CONFIG_EXAMPLE_H_
#define CONFIG_EXAMPLE_H_

/* enable the feature */
#define ENABLE_RAMP2C_MODE				true
#define ENABLE_RAMP2_DMA				false

/* Enable fault blanking feature in RAMP2C mode */
/* Enable when RAMP2C mode is Enabled
	ENABLE_RAMP2C_MODE				true
*/
#define ENABLE_FAULT_BALNKING			true
#define AC_SCALING_FACTOR				32

#if ENABLE_RAMP2C_MODE == true
#define CC0_Value						2500
#define CCB0_Value						0

#define CC1_Value						1250
#define CCB1_Value						0

#define CC2_Value						1250
#define CCB2_Value						0

#define PER_Value						5000
#define PERB_Value						0

#else

#define CC0_Value						250
#define CCB0_Value						250

#define CC1_Value						250
#define CCB1_Value						250

#define CC2_Value						250
#define CCB2_Value						250

#define PER_Value						500
#define PERB_Value						500
#endif

#define GLCK_SOURCE						GCLK_GENERATOR_1
#define TCC_CLOCK_DIVIDER				TCC_CLOCK_PRESCALER_DIV1

/* if enabled RAMP2C mode */ 
#if (ENABLE_RAMP2C_MODE == true)

#define TRIGGER_PIN						PIN_PA02
#define FAULT_INPUT_PIN					PIN_PA14
#define BLANKPRESC						15

#elif (ENABLE_RAMP2_DMA == true)

#define TRIGGER_PIN						PIN_PA10

#endif

/* function prototypes*/
void config_ramp2c(void);
void config_ramp2_dma(void);
void trigger_generation(void);
void trigger_fault(void);

#endif /* CONFIG_EXAMPLE_H_ */