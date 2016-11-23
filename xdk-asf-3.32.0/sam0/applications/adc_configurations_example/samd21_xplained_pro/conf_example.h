/**
 * \file
 *
 * \brief SAM D21 Xplained Pro board ADC configurations Example.
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

#ifndef CONF_EXAMPLE_H_INCLUDED
#define CONF_EXAMPLE_H_INCLUDED


#define ENABLE	1
#define	DISABLE	0

/* Macro Definitions for ADC Configuration */

/* Please define any one of the below ADC mode */
#define ADC_MODE_DIFFERENTIAL	DISABLE
#define ADC_MODE_HW_AVERAGING	DISABLE	
#define ADC_MODE_OVERSAMPLING	DISABLE
#define ADC_MODE_WINDOW			DISABLE
#define ADC_MODE_CALIBRATION	DISABLE
#define ADC_MODE_TEMP_SENSOR	ENABLE

#if (ADC_MODE_DIFFERENTIAL + ADC_MODE_HW_AVERAGING + ADC_MODE_OVERSAMPLING \
	+ ADC_MODE_WINDOW + ADC_MODE_CALIBRATION + ADC_MODE_TEMP_SENSOR) > 1 
#error "Please enable only one feature at a time"
#endif


/* Macro Definitions for ADC SCALE definitions */

#define ADC_REFERENCE_INTVCC1_VALUE		1.65
#define ADC_12BIT_FULL_SCALE_VALUE		4095
#define ADC_11BIT_FULL_SCALE_VALUE		2047
#define ADC_16BIT_FULL_SCALE_VALUE		65535
/* 12 bit ADC value for corresponding 0.75V with respect 1.65V reference */
#define ADC_WINDOW_LOWER_THERSOLD_VALUE 0x0745 


/* Function Prototypes for the ADC mode operation */

uint16_t adc_start_read_result(void);
void adc_differential(void);
void adc_hardware_averaging(void);
void adc_oversampling(void);
void adc_window_monitor(void);
void adc_calibration(void);
void adc_temp_sensor(void);

/* Function prototype for Serial console */
void configure_console(void);

#endif /* CONF_EXAMPLE_H_INCLUDED */
