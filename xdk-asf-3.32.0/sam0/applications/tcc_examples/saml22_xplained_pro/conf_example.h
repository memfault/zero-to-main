/**
 * \file
 *
 * \brief SAM L22 TCC Feature configuration.
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
 /**
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#ifndef CONF_EXAMPLE_H_INCLUDED
#define CONF_EXAMPLE_H_INCLUDED

/*
 * The following are the list of features, supported by this example.
 * The user can enable only one feature at a time, to avoid unnecessary 
 * coding complexity, it is left to the user to ensure that only one 
 * feature is enabled at a time.To enable a feature, the user just enables
 * the feature at the start of feature definitions.
 */
 
// List of Feature definitions, that can be used by this application note.

#undef TCC_MODE_CIRCULAR_BUFFER
#undef TCC_MODE_ONESHOT
#undef TCC_MODE_OTMX_DTI
#undef TCC_MODE_SWAP
#undef TCC_MODE_PATTERN_GENERATION
#undef TCC_MODE_RAMP2
#undef TCC_MODE_RAMP2A
#undef TCC_MODE_DUAL_SLOPE
#undef TCC_MODE_COUNTER
#undef TCC_MODE_FAULT
#undef TCC_MODE_DITHERING
#undef TCC_MODE_CAPTURE

/////////////////////////////////////////////////////////////////////////////

/*
 * Feature definitions used by this project specify which feature
 * needs to be tested .For example, if you want to test the feature 
 * TCC_MODE_CAPTURE, only TCC_MODE_CAPTURE needs to be definied below as
 * #define TCC_MODE_CAPTURE. No other definitions should be done by user.
 */

#define  TCC_MODE_CIRCULAR_BUFFER
 // End of feature definitions. 
 

/////////////////////////////////////////////////////////////////////////////


///////////////////////// START of enumeration constants ////////////////////
/* 
 * The enumeration constant to indicate, which TCC channel is being used by 
 * the system.
 */
enum eTCC_Channel {
	TCC_CHANNEL_NUM_0 = 0,
	TCC_CHANNEL_NUM_1,
	TCC_CHANNEL_NUM_2,
	TCC_CHANNEL_NUM_3,
	TCC_CHANNEL_NUM_4,
	TCC_CHANNEL_NUM_5,
	TCC_CHANNEL_NUM_6
};
///////////////////////// END of enumeration constants ///////////////////


///////////////////////// START of CONFIGURABLE symbolic constants ///////
/* 
 * The below are configurable features, which may be changed based on 
 * board/device specific, like baud rate, TCC module used.
 */

// Configurable TCC Instance
#define CONF_PWM_MODULE             TCC0

// Configurable PWM Channels
#define CONF_PWM_CHANNEL            1
#define CONF_PWM_OUTPUT             0

// Configurable Default PWM PIN and MUX configuration
#define CONF_PWM_OUT_PIN            PIN_PA04E_TCC0_WO0
#define CONF_PWM_OUT_MUX            MUX_PA04E_TCC0_WO0

// Configurable default period and match compare values.
#define CONF_DEFAULT_PERIOD         0x3FF
#define CONF_DEFAULT_MATCH_COMPARE  0x1FF

// Configurable options for Fault operations
#define CONF_FAULT_EIC_PIN          PIN_PA18A_EIC_EXTINT2
#define CONF_FAULT_EIC_PIN_MUX      MUX_PA18A_EIC_EXTINT2
#define CONF_FAULT_EIC_LINE         2

// Configurable options for Capture Mode
#define CONF_TEST_PIN_OUT           PIN_PA07
#define CONF_EVENT_GENERATOR_ID     EVSYS_ID_GEN_EIC_EXTINT_2
#define CONF_EVENT_CAPTURE          EVSYS_ID_GEN_TCC0_MCX_0

// Configurable Fault events used by FAULT Feature and CAPTURE Features.
#define CONF_FAULT_EVENT_USER       EVSYS_ID_USER_TCC0_MC_0
#define CONF_CAPTURE_EVENT_USER     EVSYS_ID_USER_TCC0_MC_1

// Baud Rate configuration
#define CONF_BAUD_RATE              9600
///////////////////////// END of CONFIGURABLE symbolic constants ////////////


//////////// START OF symbolic constants FEATURE SPECIFIC ////////////////////
/* 
 * Symbolic constants used in Circular Buffer Feature 
 *(TCC_MODE_CIRCULAR_BUFFER)
 */
#ifdef TCC_MODE_CIRCULAR_BUFFER
#define GLCK_SOURCE                 GCLK_GENERATOR_3
#define TCC_PERIOD_VALUE            0xFF
#define TCC_CLOCK_DIVIDER           TCC_CLOCK_PRESCALER_DIV1
#define CC0_Value                   0x80
#define CCB0_Value                  0xC0
#endif

// Symbolic constants used in One Shot feature (TCC_MODE_ONESHOT)
#ifdef TCC_MODE_ONESHOT
#define TCC_PERIOD_VALUE            31250
#define GLCK_SOURCE                 GCLK_GENERATOR_3
#define TCC_CLOCK_DIVIDER           TCC_CLOCK_PRESCALER_DIV256
#endif

// Symbolic constants used in DTI Feature (TCC_MODE_OTMX_DTI)
#ifdef TCC_MODE_OTMX_DTI
#define GLCK_SOURCE                 GCLK_GENERATOR_3
#define TCC_PERIOD_VALUE            0XFF
#define TCC_CLOCK_DIVIDER           TCC_CLOCK_PRESCALER_DIV1
#define TCC_MATCH_CHANNEL_DTI_SWAP  0x80
#define DTI_HIGH_TIME               0x10
#define DTI_LOW_TIME                0x40
#endif

// Symbolic constants used in Swap Feature (TCC_MODE_SWAP)
#ifdef TCC_MODE_SWAP
#define GLCK_SOURCE                 GCLK_GENERATOR_3
#define TCC_PERIOD_VALUE            0xFF
#define TCC_CLOCK_DIVIDER           TCC_CLOCK_PRESCALER_DIV1
#define TCC_MATCH_CHANNEL_CCBUF     0x80
#define TCC_SWAP_DT_LS              0x20
#define TCC_SWAP_DT_HS              0x60
#endif

/* Symbolic constants used in Pattern Generation Feature 
(TCC_MODE_PATTERN_GENERATION)*/
#ifdef TCC_MODE_PATTERN_GENERATION
#define GLCK_SOURCE                 GCLK_GENERATOR_0
#define TCC_PERIOD_VALUE            0x7FFF
#define TCC_CLOCK_DIVIDER           TCC_CLOCK_PRESCALER_DIV1
#define TCC_MATCH_VALUE_PATTERN_GEN 0x7F
#define TCC_PATTERN_PAGE_VAL        0x0F
#define PATTERN_SIZE                4
#endif

// Symbolic constants used in RAMP2 feature (TCC_MODE_RAMP2)
#ifdef TCC_MODE_RAMP2
#define GLCK_SOURCE                 GCLK_GENERATOR_0
#define TCC_PERIOD_VALUE            0xFFFF
#define TCC_CLOCK_DIVIDER           TCC_CLOCK_PRESCALER_DIV1
#define TCC_RAMP2_MATCH_CHANNEL_0   0xB333
#define TCC_RAMP2_MATCH_CHANNEL_1   0x4CCC
#endif

// Symbolic constants used in RAMP2A feature (TCC_MODE_RAMP2A)
#ifdef TCC_MODE_RAMP2A
#define GLCK_SOURCE                 GCLK_GENERATOR_0
#define TCC_PERIOD_VALUE            0xFFFF
#define TCC_CLOCK_DIVIDER           TCC_CLOCK_PRESCALER_DIV1
#define TCC_RAMP2_MATCH_CHANNEL_0   0xB333
#endif

// Symbolic constants used in Dual Slope feature (TCC_MODE_DUAL_SLOPE)
#ifdef TCC_MODE_DUAL_SLOPE
#define TCC_PERIOD_VALUE            0x3FF
#define GLCK_SOURCE                 GCLK_GENERATOR_0
#define TCC_CLOCK_DIVIDER           TCC_CLOCK_PRESCALER_DIV1
#endif

// Symbolic constants used in Counter feature (TCC_MODE_COUNTER)
#ifdef TCC_MODE_COUNTER
#define GLCK_SOURCE                 GCLK_GENERATOR_0
#define TCC_PERIOD_VALUE            2000
#define TCC_CLOCK_DIVIDER           TCC_CLOCK_PRESCALER_DIV1024
#define TCC_MODE_COUNTER_MATCH_0    900
#define TCC_MODE_COUNTER_MATCH_1    930
#define TCC_MODE_COUNTER_MATCH_2    1100
#define TCC_MODE_COUNTER_MATCH_3    1250
#endif

// Symbolic constants used in Fault feature (TCC_MODE_FAULT)
#ifdef TCC_MODE_FAULT
#define GLCK_SOURCE                 GCLK_GENERATOR_0
#define TCC_PERIOD_VALUE            0x3FF
#define TCC_CLOCK_DIVIDER           TCC_CLOCK_PRESCALER_DIV1
#endif

// Symbolic constants used in Dithering feature (TCC_MODE_DITHERING)
#ifdef TCC_MODE_DITHERING
#define GLCK_SOURCE                 GCLK_GENERATOR_0
#define TCC_PERIOD_VALUE            0xFFFF
#define TCC_CLOCK_DIVIDER           TCC_CLOCK_PRESCALER_DIV1
#define DITH_CYCLES                 2 // 32 frames
#endif

// Symbolic constants used in Capture feature (TCC_MODE_CAPTURE)
#ifdef TCC_MODE_CAPTURE
#define GLCK_SOURCE                 GCLK_GENERATOR_3
#define TCC_CLOCK_DIVIDER           TCC_CLOCK_PRESCALER_DIV1
#endif
//////////// END OF symbolic constants FEATURE SPECIFIC /////////////////////

//////////// START OF Function Prototypes ///////////////////////////////////
void configure_tcc(void);
void swap_operation(void);
void pattern_generation(void);
void oneshot_operation(void);
void configure_tcc_callback(void);
//////////// END OF Function Prototypes /////////////////////////////////////

#endif /* CONF_EXAMPLE_H_INCLUDED */
