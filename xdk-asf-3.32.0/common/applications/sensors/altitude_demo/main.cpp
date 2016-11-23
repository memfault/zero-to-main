/**
 * \file
 *
 * \brief Common Sensor Service Pressure Sensor Example
 *
 * Copyright (c) 2011-2014 Atmel Corporation. All rights reserved.
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
 * This application uses the common sensor service to obtain pressure data
 * from a MEMS pressure sensor installed on an Atmel development board.  After
 * initializing sensor platform board resources, this demonstration will
 * attach and initialize a barometric sensor installed on the development board.
 * In the case of the Atmel Xplained development boards, for example, the
 * platform should be fitted and built for a Sensors Xplained Pressure sensor
 * board.
 *
 * Once an appropriate pressure sensor is initialized, the
 * \ref pressure_altitude() utility in the ASF Common Sensor service is used
 * to calculate the pressure altitude as a function of the current barometric
 * pressure and configured local mean sea level pressure.  Adjust the
 * \ref MSL_PRESSURE constant to local conditions to improve the altitude
 * estimate.  The pressure sample, converted to hectopascals, along with
 * altitude estimate are printed to the application console.  In the case of
 * Atmel Xplained development boards communicating over a USART, the serial
 * channel configuration is selected by the board configuration files; see, for
 * example, the conf_board.h file in the project directories.
 *
 * \section contactinfo Contact Information
 * For further information, visit
 * <a href="http://www.atmel.com/avr">Atmel AVR</a>.\n
 * Support and FAQ: http://www.atmel.com/design-support/
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <asf.h>

/** \name Runtime Configuration Variables
 * @{
 */

/** \brief display a startup banner with basic sensor information */
static const bool PRINT_BANNER = true;

/** \brief current local mean sea level pressure (Pascals) */
static const long MSL_PRESSURE = 102300;

/** @} */


/** \brief Convert an altitude to a pressure value.
 *
 * The pressure_altitude() utility converts barometric pressure values in
 * Pascal units to an estimated altitude in meters using a standard model.
 * In this model, a difference in altitude of 10m corresponds to 120Pa
 * pressure change at sea level.  This relation is used to estimate pressure
 * given a specified altitude difference.
 *
 * \param   meters      An altitude in meters.
 *
 * \return  float       The estimated atmospheric pressure in Pascals.
 */
static inline float meters_to_pascals(float meters)
{
	return (12 * meters);
}

/*! \brief Get a pressure sample from a specified sensor.
 *
 * This returns the scaled value of a pressure sample taken from
 * a user-specified pressure sensor.
 *
 * \param   sensor      The address of an initialized sensor descriptor.
 *
 * \return  int32_t     A pressure samples.
 */
static inline int32_t barometric_pressure(sensor_t *sensor)
{
	sensor_data_t data;
	data.scaled = true;

	sensor_get_pressure(sensor, &data);

	return *(data.value);
}

/** \brief Get an averaged function value.
 *
 * This utility returns the average of a specified number of function
 * values.
 *
 * \param   callback    The name of a user sample function.
 * \param   arg         An argument passed to the sample function.
 * \param   M           The number of samples to average.
 *
 * \return  int32_t     An average (scaled) of 'M' pressure samples.
 */
template <typename func, typename T>
static inline int32_t average(func callback, T arg, int M = 25)
{
	float avg = 0;

	for (int j = M; j > 0; --j) {
		avg += callback(arg);
		delay_ms(5);
	}

	return (int32_t)((avg / M) + 0.5);
}

/** \brief Pressure demo application entry
 *
 * After initializing sensor platform board resources, this demonstration will
 * attach and initialize a barometric sensor installed on the development board.
 * In the case of the Atmel Xplained development boards, for example, the
 * platform should be fitted and built for a Sensors Xplained Pressure sensor
 * board.
 */
int main(void)
{
	/* Initialize the board (Xplained UC3 or XMEGA & Xplained Sensor boards)
	 * I/O pin mappings and any other configurable resources selected in
	 * the build configuration.
	 */
	sensor_platform_init();

	/* Attach a descriptor to the existing sensor device. */
	sensor_t barometer;
	sensor_attach(&barometer, SENSOR_TYPE_BAROMETER, 0, 0);

	if (barometer.err) {
		puts("\rSensor initialization error.");

		while (true) {
			/* Error occurred, loop forever */
		}
	}

	/* Set the barometer sample mode & altimeter reference values. */
	sensor_set_state(&barometer, SENSOR_STATE_LOWEST_POWER);
	pressure_sea_level(MSL_PRESSURE);

	if (PRINT_BANNER) {
		uint32_t id; uint8_t ver;

		sensor_device_id(&barometer, &id, &ver);

		printf(
				"%s\r\nID = 0x%02x ver. 0x%02x\r\n  %d-bit Resolution\r\n",
				barometer.drv->caps.name,
				(unsigned)id,
				(unsigned)ver,
				barometer.hal->resolution);
	}

	while (true) {
		static float P_old = 0;
		const float P_new = average(barometric_pressure, &barometer);

		if (fabs(P_new - P_old) > meters_to_pascals(0.5)) {
			printf("P = %.2f hPa, altimeter: %.1f m\r",
					(P_new / 100),
					pressure_altitude(P_new));
		}

		P_old = P_new;
	}
}
