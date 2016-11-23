/**
 * \file
 *
 * \brief ADC temperature sensor macro definition and prototype.
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

#ifndef ADC_TEMP_H_INCLUDED
#define ADC_TEMP_H_INCLUDED

/* TEMP_LOG Base Address*/
#define TEMP_LOG_READ_NVM1					(*(RwReg*)NVMCTRL_TEMP_LOG)     
/* TEMP_LOG Next Address*/
#define TEMP_LOG_READ_NVM2					(*(RwReg*)NVMCTRL_TEMP_LOG + 4) 
#define ADC_TEMP_SAMPLE_LENGTH				4
#define INT1V_VALUE_FLOAT					1.0
#define INT1V_DIVIDER_1000					1000.0
#define ADC_12BIT_FULL_SCALE_VALUE_FLOAT	4095.0




/* Function Prototypes for the ADC Temp Sensor Operation */
void configure_adc_temp(void);
float convert_dec_to_frac(uint8_t val);
void load_calibration_data(void);
float calculate_temperature(uint16_t raw_code);


#endif /* ADC_TEMP_H_INCLUDED */
