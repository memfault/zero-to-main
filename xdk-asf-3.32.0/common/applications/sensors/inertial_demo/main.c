/**
 * \file
 *
 * \brief Common Sensor Service Inertial Sensor Example
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
 * This application obtains sensor data from a MEMS accelerometer, gyroscope,
 * and electronic compass devices installed on an Atmel development board.
 *
 * \section contactinfo Contact Information
 * For further information, visit
 * <a href="http://www.atmel.com/avr">Atmel AVR</a>.\n
 * Support and FAQ: http://www.atmel.com/design-support/
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#include <stdio.h>
#include <asf.h>
#include <led.h>

/* Application configuration constants */
#define PRINT_BANNER    (true) /* If true, print sensor config information */
#define SCALED_DATA     (true) /* If true, convert sensor data to std. units */

/* Hardware environment constants */
#define ACTIVITY_LED    (LED1) /* LED to blink to show activity */


/** \brief Inertial sensor demo application entry
 *
 * After initializing the Xplained platform and sensor boards, this application
 * attaches descriptors to the accelerometer, gyroscope, and compass devices on
 * an Xplained inertial sensor board.  The sensor data, which is formatted and
 * printed via printf() after being read, can be viewed with a serial terminal
 * application on a machine attached to the USB interface on the Xplained
 * board.
 */
int main(void)
{
	sensor_t accel;   /* Accelerometer device descriptor */
	sensor_t compass; /* Magnetic compass device descriptor */
	sensor_t gyro;    /* Gyroscope device descriptor */

	/* Initialize the board (Xplained UC3 or XMEGA & Xplained Sensor boards)
	 * I/O pin mappings and any other configurable resources selected in
	 * the build configuration.
	 */
	sensor_platform_init();

	/* Attach descriptors to the defined sensor devices */
	sensor_attach(&gyro, SENSOR_TYPE_GYROSCOPE, 0, 0);
	sensor_attach(&accel, SENSOR_TYPE_ACCELEROMETER, 0, 0);
	sensor_attach(&compass, SENSOR_TYPE_COMPASS, 0, 0);

	if (gyro.err || accel.err || compass.err) {
		puts("\rSensor initialization error.");

		while (true) {
			/* Error occurred, loop forever */
		}
	}

	/* Print sensor information */
	if (PRINT_BANNER) {
		static const char *const banner_format
			= "%s\r\nID = 0x%02x ver. 0x%02x\r\n"
				"Bandwidth = %d Hz  Range = +/- %d\r\n\n";

		uint32_t id;
		uint8_t version;
		int16_t freq, range;

		sensor_device_id(&gyro, &id, &version);
		sensor_get_bandwidth(&gyro, &freq);
		sensor_get_range(&gyro, &range);

		printf(banner_format, gyro.drv->caps.name,
				(unsigned)id, (unsigned)version, freq, range);

		sensor_device_id(&accel, &id, &version);
		sensor_get_bandwidth(&accel, &freq);
		sensor_get_range(&accel, &range);

		printf(banner_format, accel.drv->caps.name,
				(unsigned)id, (unsigned)version, freq, range);

		sensor_device_id(&compass, &id, &version);
		sensor_get_bandwidth(&compass, &freq);
		sensor_get_range(&compass, &range);

		printf(banner_format, compass.drv->caps.name,
				(unsigned)id, (unsigned)version, freq, range);

		delay_ms(500);
	}

	/* Initialize sensor data descriptors for scaled vs. raw data. */
	static sensor_data_t accel_data   = {.scaled = SCALED_DATA};
	static sensor_data_t compass_data = {.scaled = SCALED_DATA};
	static sensor_data_t gyro_data    = {.scaled = SCALED_DATA};
	static sensor_data_t temp_data    = {.scaled = SCALED_DATA};

	while (true) {
		LED_Toggle(ACTIVITY_LED);

		/* Read sensor values */
		sensor_get_acceleration(&accel, &accel_data);
		sensor_get_rotation(&gyro, &gyro_data);
		sensor_get_temperature(&gyro, &temp_data); /* Get temp from gyro */

		if (SCALED_DATA) {
			/* Get calculated magnetic heading from compass */
			sensor_get_heading(&compass, &compass_data);
		} else {
			/* Get raw magnetic field readings (X,Y,Z) */
			sensor_get_field(&compass, &compass_data);
		}

		/* Print sensor values */
		if (SCALED_DATA) {
			printf("acc = [%5d, %5d, %5d]\r\n",
					(int16_t)accel_data.axis.x,
					(int16_t)accel_data.axis.y,
					(int16_t)accel_data.axis.z);

			printf("rot = [%5d, %5d, %5d]\r\n",
					(int16_t)gyro_data.axis.x,
					(int16_t)gyro_data.axis.y,
					(int16_t)gyro_data.axis.z);

			printf("heading %5d, inclination %5d, strength %5d\r\n",
					(uint16_t)compass_data.heading.direction,
					(int16_t)compass_data.heading.inclination,
					(uint16_t)compass_data.heading.strength);

			printf("T = %d C\r\n\n",
					(int16_t)temp_data.temperature.value);
		} else {
			printf("acc = [%.5x, %.5x, %.5x]\r\n",
					(uint16_t)accel_data.axis.x,
					(uint16_t)accel_data.axis.y,
					(uint16_t)accel_data.axis.z);

			printf("rot = [%.5x, %.5x, %.5x]\r\n",
					(uint16_t)gyro_data.axis.x,
					(uint16_t)gyro_data.axis.y,
					(uint16_t)gyro_data.axis.z);

			printf("field = [%.5x, %.5x, %.5x]\r\n",
					(int16_t)compass_data.axis.x,
					(int16_t)compass_data.axis.y,
					(int16_t)compass_data.axis.z);

			printf("T = %.5x\r\n\n",
					(uint16_t)temp_data.temperature.value);
		}

		delay_ms(500);
	}

	return 0;
}
