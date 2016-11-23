/**
 * \file
 *
 * \brief ADP window configuration
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
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#ifndef ADP_WINDOW_H_INCLUDED
#define ADP_WINDOW_H_INCLUDED

/** Stream number defines */
/* Status messages stream id */
#define STREAM_ID_STATUS_MESSAGE    0x00
/* Outgoing voltage value stream id */
#define STREAM_ID_LIGHT_SENSOR      0x01
/* Outgoing ADC value stream id */
#define STREAM_ID_LIGHT_SENSOR_ADC  0x02
/* Incoming stream setting high hysteresis */
#define STREAM_ID_HYST_HIGH         0x10
/* Incoming stream setting low hysteresis */
#define STREAM_ID_HYST_LOW          0x11
/* Night mode signal stream id */
#define STREAM_ID_NIGHT_MODE        0x29
/* Led toggle stream id */
#define STREAM_ID_LED_TOGGLE        0x30

/** Dashboard and elements defines */
/* Light sensor example dashboard id */
#define DASHBOARD_ID_LIGHT_SENSOR       0x00
#define DASHBOARD_ID_CONTROL            0x01

/* Terminal label */
#define TERMINAL_LABEL "Status terminal"
/* Graph label */
#define GRAPH_LABEL    "Light Sensor Output"
/* Dashboard label */
#define DASHBOARD_DIS_LABEL "Light Sensor Example Dashboard"
#define DASHBOARD_CON_LABEL "Control Dashboard"

extern struct adp_msg_conf_terminal terminal_config;

enum adp_example_element_id {
	/* Dashboard example */
	ELEMENT_ID_LABEL_TITEL,
	ELEMENT_ID_LABEL_VALUE_VOL,
	ELEMENT_ID_LABEL_NIGHT_LIGHT,
	ELEMENT_ID_LABEL_LED_CONTROL,
	ELEMENT_ID_BAR,
	ELEMENT_ID_SIGNAL,
	ELEMENT_ID_BUTTON,
	ELEMENT_ID_GRAPH,
	
	/* Dashboard config */
	ELEMENT_ID_LABEL_HYSTERESIS,
	ELEMENT_ID_LABEL_LOW,
	ELEMENT_ID_LABEL_HIGH,
	ELEMENT_ID_LABEL_VALUE_ADC,
	ELEMENT_ID_SLIDER_LOW,
	ELEMENT_ID_SLIDER_HIGH,
	ELEMENT_ID_SEGMENT,
};

void adp_window_init(void);

#endif
