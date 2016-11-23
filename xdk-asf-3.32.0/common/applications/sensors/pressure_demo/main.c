/**
 * \file
 *
 * \brief Common Sensor Service Pressure Sensor Example
 *
 * Copyright (c) 2011-2015 Atmel Corporation. All rights reserved.
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
 * \mainpage
 *
 * \section intro Introduction
 *
 * This application obtains sensor data from the MEMS pressure sensor device
 * installed on an Atmel development board.
 *
 * \section contactinfo Contact Information
 * For further information, visit
 * <A href="http://www.atmel.com/avr">Atmel AVR</A>.\n
 * Support and FAQ: http://www.atmel.com/design-support/
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#include <stdio.h>
#include <asf.h>
#include <led.h>

/* Application configuration constants */
#define PRINT_BANNER    (true)

/* Hardware environment constants */
#define ACTIVITY_LED    (LED1)


/** \brief Pressure sensor demonstration application entry
 *
 * After initializing the development platform and sensors, this application
 * attaches a descriptor to the sensor on an Xplained pressure sensor board.
 * The sensor pressure and temperature data, which is formatted and printed
 * via printf() after being read, can be viewed with a terminal application on
 * a machine attached to the serial interface on the development board.
 */
int main(void)
{
	sensor_t barometer;             /* Pressure sensor device descriptor */
	sensor_data_t press_data;       /* Pressure data */
	sensor_data_t temp_data;        /* Temperature data */

	/* Initialize the board (Xplained UC3 or XMEGA & Xplained Sensor boards)
	 * I/O pin mappings and any other configurable resources selected in
	 * the build configuration.
	 */
	sensor_platform_init();

	/* Attach a descriptor to the existing sensor device. */
	sensor_attach(&barometer, SENSOR_TYPE_BAROMETER, 0, 0);

	if (barometer.err) {
		puts("\rSensor initialization error.");

		while (true) {
			/* Error occurred, loop forever */
		}
	}

	sensor_set_state(&barometer, SENSOR_STATE_HIGHEST_POWER);

	/* Initialize sensor data structure flags for scaled vs. raw data */
	press_data.scaled = true;
	temp_data.scaled = true;

	/* Print sensor config info */
	if (PRINT_BANNER) {
		uint32_t id;
		uint8_t ver;

		static const char *const banner_format
			= "%s\r\nID = 0x%02x ver. 0x%02x\r\n  %d-bit Resolution\r\n";

		sensor_device_id(&barometer, &id, &ver);

		printf(banner_format, barometer.drv->caps.name, (unsigned)id,
				(unsigned)ver, barometer.hal->resolution);
	}

	while (true) {
		LED_Toggle(ACTIVITY_LED);

		sensor_get_pressure(&barometer, &press_data);
		sensor_get_temperature(&barometer, &temp_data);

		printf("P = %.2f hPa,  T = %.1f C\r\n",
				(press_data.pressure.value / 100.0),
				(temp_data.temperature.value / 10.0));

		delay_ms(500);
	}

	return 0;
}
