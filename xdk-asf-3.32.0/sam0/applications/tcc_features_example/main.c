/**
 * \file
 *
 * \brief SAM D11 TCC Features Example Application
 *        Refer following application note for details.
 *        AT42357 - Using the Timer Counter for Control Applications (TCC).
 *
 * Copyright (C) 2014-2016 Atmel Corporation. All rights reserved.
 *
 * \license
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
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <asf.h>
#include "conf_example.h"

struct tcc_module tcc_instance;
enum status_code stat = STATUS_OK;

#ifdef TCC_MODE_PATTERN_GENERATION
/* Generic Pattern for half size Bipolar Stepper Motor */
uint8_t sm_pattern[4] = {8, 2, 4, 1};
uint8_t i = 0;
#endif



/*	Description: This example project helps you to configure the TCC Module 
	for different Features/Modes available in TCC module of SAMD11 */
	
/* Configure the TCC module as per the application requirement */

/* Example - 1. Circular Buffer
             2. Oneshot Operation 
             3. Pattern Generation
             4. PWM with OTMX(Output Matrix) and DTI(Dead Time Insertion) 
             5. RAMP2 Operation
             6. SWAP Operation
*/

void configure_tcc(void)
{
	/* Structure used to store the TCC configuration parameters */
	struct tcc_config config_tcc;

	/* Fill the Structure with the default values */
	tcc_get_config_defaults(&config_tcc, TCC0);
	
	/* Configure the single slope PWM waveform generation for waveform output */
	config_tcc.compare.wave_generation = TCC_WAVE_GENERATION_SINGLE_SLOPE_PWM;
	
	/* Configure the TCC clock source and its divider value */
	config_tcc.counter.clock_source = GLCK_SOURCE;
	config_tcc.counter.clock_prescaler = TCC_CLOCK_DIVIDER;
	
	 /* Configure the value for TOP value */
	 config_tcc.counter.period = TCC_PERIOD_VALUE;


#ifdef TCC_MODE_CIRCULAR_BUFFER	
	/* Configure the TCC Waveform Output pins for waveform generation output */
	config_tcc.pins.enable_wave_out_pin[0] = true;

	config_tcc.pins.wave_out_pin[0] = PIN_PA04F_TCC0_WO0;

	/* Configure the Alternate function of GPIO pins for TCC functionality */ 
	config_tcc.pins.wave_out_pin_mux[0] = MUX_PA04F_TCC0_WO0;

#endif

#ifdef TCC_MODE_ONESHOT

	/* Configure the TCC Waveform Output pins for waveform generation output */
	config_tcc.pins.enable_wave_out_pin[6] = true;
	config_tcc.pins.wave_out_pin[6] = PIN_PA16F_TCC0_WO6;

	/* Configure the alternate function of GPIO pins for TCC functionality */
	config_tcc.pins.wave_out_pin_mux[6] = MUX_PA16F_TCC0_WO6;
	
	/* Configure the Match value for the compare channel 2 for LED0 ON time*/
	config_tcc.compare.match[2] = 31250;
	
	/* Invert the Waveform output[6] channel to drive LED0 */
	config_tcc.wave_ext.invert[6] = true;
	
	/* Enable the One shot Feature */
	config_tcc.counter.oneshot = true;
	
#endif

#ifdef TCC_MODE_OTMX_DTI

	/* Configure the TCC Waveform Output pins for waveform generation output */
	config_tcc.pins.enable_wave_out_pin[0] = true;
	config_tcc.pins.enable_wave_out_pin[1] = true;
	config_tcc.pins.enable_wave_out_pin[2] = true;
	config_tcc.pins.enable_wave_out_pin[6] = true;
	
	config_tcc.pins.wave_out_pin[0] = PIN_PA04F_TCC0_WO0;
	config_tcc.pins.wave_out_pin[1] = PIN_PA05F_TCC0_WO1;
	config_tcc.pins.wave_out_pin[2] = PIN_PA06F_TCC0_WO2;
	config_tcc.pins.wave_out_pin[6] = PIN_PA16F_TCC0_WO6;
	
	/* Configure the Alternate function of GPIO pins for TCC functionality */
	config_tcc.pins.wave_out_pin_mux[0] = MUX_PA04F_TCC0_WO0;
	config_tcc.pins.wave_out_pin_mux[1] = MUX_PA05F_TCC0_WO1;
	config_tcc.pins.wave_out_pin_mux[2] = MUX_PA06F_TCC0_WO2;
	config_tcc.pins.wave_out_pin_mux[6] = MUX_PA16F_TCC0_WO6;
	
	/* Configure the compare channel values for the duty cycle control */
	/* Load the 0x80 value for 50% duty cycle */
	config_tcc.compare.match[0] = 0x80;
	config_tcc.compare.match[1] = 0x80;
	config_tcc.compare.match[2] = 0x80;
	
	/* Invert the Waveform output[1] channel to view the DTI effect */
	config_tcc.wave_ext.invert[1] = true;

#endif

#ifdef TCC_MODE_SWAP

	/* Configure the TCC Waveform Output pins for waveform generation output */
	config_tcc.pins.enable_wave_out_pin[0] = true;
	config_tcc.pins.enable_wave_out_pin[4] = true;
	
	config_tcc.pins.wave_out_pin[0] = PIN_PA04F_TCC0_WO0;
	config_tcc.pins.wave_out_pin[4] = PIN_PA22F_TCC0_WO4;

	/* Configure the alternate function of GPIO pins for TCC functionality */
	config_tcc.pins.wave_out_pin_mux[0] = MUX_PA04F_TCC0_WO0;
	config_tcc.pins.wave_out_pin_mux[4] = MUX_PA22F_TCC0_WO4;

	/* Configure the compare channel values for the duty cycle control */
	/* Load the 0x80 value for 50% duty cycle */
	config_tcc.compare.match[0] = 0x80;
	
#endif


#ifdef TCC_MODE_PATTERN_GENERATION

	/* Configure the TCC Waveform Output pins for waveform generation output */
	config_tcc.pins.enable_wave_out_pin[0] = true;
	config_tcc.pins.enable_wave_out_pin[1] = true;
	config_tcc.pins.enable_wave_out_pin[2] = true;
	config_tcc.pins.enable_wave_out_pin[3] = true;

	config_tcc.pins.wave_out_pin[0] = PIN_PA04F_TCC0_WO0;
	config_tcc.pins.wave_out_pin[1] = PIN_PA05F_TCC0_WO1;
	config_tcc.pins.wave_out_pin[2] = PIN_PA06F_TCC0_WO2;
	config_tcc.pins.wave_out_pin[3] = PIN_PA07F_TCC0_WO3;

	/* Configure the Alternate function of GPIO pins for TCC functionality */
	config_tcc.pins.wave_out_pin_mux[0] = MUX_PA04F_TCC0_WO0;
	config_tcc.pins.wave_out_pin_mux[1] = MUX_PA05F_TCC0_WO1;
	config_tcc.pins.wave_out_pin_mux[2] = MUX_PA06F_TCC0_WO2;
	config_tcc.pins.wave_out_pin_mux[3] = MUX_PA07F_TCC0_WO3;

	config_tcc.double_buffering_enabled = true;

	/* Configure the compare channel values for the duty cycle control */
	/* Load the 0x7FFF value for 50% duty cycle */
	config_tcc.compare.match[0] = 0x7FFF;


#endif

#ifdef TCC_MODE_RAMP2

	/* Configure the TCC Waveform Output pins for waveform generation output */		
	config_tcc.pins.enable_wave_out_pin[0] = true;
	config_tcc.pins.enable_wave_out_pin[1] = true;
	
	config_tcc.pins.wave_out_pin[0] = PIN_PA04F_TCC0_WO0;
	config_tcc.pins.wave_out_pin[1] = PIN_PA05F_TCC0_WO1;

	/* Configure the Alternate function of GPIO pins for TCC functionality */
	config_tcc.pins.wave_out_pin_mux[0] = MUX_PA04F_TCC0_WO0;
	config_tcc.pins.wave_out_pin_mux[1] = MUX_PA05F_TCC0_WO1;
	
	/* Configure the RAMP mode operation as RAMP2 mode */
	config_tcc.compare.wave_ramp = TCC_RAMP_RAMP2;
	
	/* Configure the compare channel values for the duty cycle control */
	/* Load the 0xB333 value for 70% duty cycle */
	config_tcc.compare.match[0] = 0xB333;
	/* Load the 0x4CCC value for 30% duty cycle */
	config_tcc.compare.match[1] = 0x4CCC;
	
#endif

	/* Initialize the TCC0 channel and define the its registers with configuration defined in the config_tcc */
	stat = tcc_init(&tcc_instance, TCC0, &config_tcc);	

	
#ifdef TCC_MODE_CIRCULAR_BUFFER	
	/* Load the CC0 and CCB0 values respectively for the circular buffer operation */	
    stat = tcc_set_double_buffer_compare_values(&tcc_instance, TCC_MATCH_CAPTURE_CHANNEL_0, CC0_Value, CCB0_Value);
	
	/* Enable the Circular Buffer feature for the Compare Channel 0 */
	stat = tcc_enable_circular_buffer_compare(&tcc_instance, TCC_MATCH_CAPTURE_CHANNEL_0);	
#endif


#ifdef TCC_MODE_OTMX_DTI

	/* Enable the Dead Time Insertion Generator for the channel 2 (CC2) */
	TCC0->WEXCTRL.reg |=  TCC_WEXCTRL_DTIEN2;
	/* Define the High side time and Low side time for Dead Time generation */
	TCC0->WEXCTRL.reg |= TCC_WEXCTRL_DTLS(0x40) | TCC_WEXCTRL_DTHS(0x10);
#endif

#ifdef TCC_MODE_PATTERN_GENERATION
	/* Configure the Output Matrix Channel for Pattern Generation of Stepper Motor */
	TCC0->WEXCTRL.reg |= TCC_WEXCTRL_OTMX(2);
	/* Enable the Pattern Generator Output for 4 Waveform Outputs and 
	   Load the PATT and PATTB register values respectively for Stepper Motor Pattern Generation */
	TCC0->PATT.reg = TCC_PATT_PGE(0x0F) | TCC_PATT_PGV(sm_pattern[i++]);
	while (TCC0->SYNCBUSY.reg & TCC_SYNCBUSY_PATT) {
	}
	TCC0->PATTB.reg = TCC_PATTB_PGEB(0x0F) | TCC_PATTB_PGVB(sm_pattern[i++]);
	while (TCC0->SYNCBUSY.reg & TCC_SYNCBUSY_PATTB) {
	}
#endif

#ifdef TCC_MODE_SWAP
	/* Enable the Dead Time Insertion Generator for the channel 0 (CC0) */
	TCC0->WEXCTRL.reg |=  TCC_WEXCTRL_DTIEN0;
	/* Define the High side time and Low side time for Dead Time generation */
	TCC0->WEXCTRL.reg |= TCC_WEXCTRL_DTLS(0x20) | TCC_WEXCTRL_DTHS(0x60);
#endif

	/* Enable the TCC module */
	tcc_enable(&tcc_instance);
}

/*	This Function loads the Stepper Motor Pattern into the Pattern Buffer 
	register respectively in the PGVB continuously. Please note that here 
	we have not added any delay between the pattern on the wave output pin. 
	Hence please add the appropriate delay before load the pattern into 
	Pattern Generation Value Buffer (PGVB register) as mentioned 
	in the stepper motor  datasheet */

#ifdef TCC_MODE_PATTERN_GENERATION
void pattern_generation(void)
{
	if (i == 4) {
		i = 0;
	}
	while (!(TCC0->INTFLAG.reg & TCC_INTFLAG_MC0)) {
	}
	TCC0->INTFLAG.reg = TCC_INTFLAG_MC0;
	TCC0->PATTB.reg = TCC_PATTB_PGEB(0x0F) | TCC_PATTB_PGVB(sm_pattern[i++]);
	while (TCC0->SYNCBUSY.reg & TCC_SYNCBUSY_PATT) {
	}
}
#endif

/*	This function Waits for the user input(Button Press) BUTTON_0_PIN 
	then clears the counter value and restart the counter for the Oneshot Operation */

#ifdef TCC_MODE_ONESHOT
void oneshot_operation(void)
{	
	while (port_pin_get_input_level(BUTTON_0_PIN)) {
	}
	while (!port_pin_get_input_level(BUTTON_0_PIN)) {
	}
	tcc_set_count_value(&tcc_instance, 0);
	tcc_restart_counter(&tcc_instance);
}
#endif


/*	This function waits for the user input(Button Press) BUTTON_0_PIN 
	then toggles the SWAP bit for the SWAP continuously */

#ifdef TCC_MODE_SWAP
void swap_operation(void)
{
	while (port_pin_get_input_level(BUTTON_0_PIN)) {
	}
	while (!port_pin_get_input_level(BUTTON_0_PIN)) {
	}
	TCC0->WAVE.reg ^= TCC_WAVE_SWAP0;
	while (TCC0->SYNCBUSY.reg & TCC_SYNCBUSY_WAVE) {
	}
}
#endif


int main (void)
{
	system_init();
	configure_tcc();
	
	while (1)
	{
#ifdef TCC_MODE_ONESHOT
		oneshot_operation();		
#endif	
			
#ifdef TCC_MODE_PATTERN_GENERATION
		pattern_generation();
#endif
		
#ifdef TCC_MODE_SWAP
		swap_operation();
#endif
	}
}