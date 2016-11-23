/**
 * \file
 *
 * \brief Common Sensor Service Direction Cosine Matrix Example
 *
 * Copyright (c) 2011-2012 Atmel Corporation. All rights reserved.
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
 * This application obtains MEMS accelerometer sensor data in addition to
 * angular rate change data from a MEMS gyroscope then uses these values to
 * calculate rotations and a direction cosine matrix.
 *
 * \section contactinfo Contact Information
 * For further information, visit
 * <a href="http://www.atmel.com/avr">Atmel AVR</a>.\n
 */

#include <stdio.h>
#include <stdlib.h>
#include <asf.h>

/* Configuration constants */
#define     AXIS_ANGLE_ORIENTATION
/* #define EULER_ANGLE_ORIENTATION */


#define     DEGREES(a)  ((a) * RAD_TO_DEG)

typedef     math::vector3d vector;
typedef     math::quaternion quaternion;

namespace {
	/** \brief Print a math::matrix3d object w/ formatting
	 *
	 * This routine prints formatted elements of a math::matrix3d object to the
	 * standard output device.
	 *
	 * \param   Mat             Specifies a math::matrix3d object to display.
	 */
	void print_matrix(const math::matrix3d &Mat)
	{
		printf("\r\n%#8.2f %#8.2f %#8.2f",
				double (Mat(0, 0)), double (Mat(0, 1)), double (Mat(0, 2)));

		printf("\r\n%#8.2f %#8.2f %#8.2f",
				double (Mat(1, 0)), double (Mat(1, 1)), double (Mat(1, 2)));

		printf("\r\n%#8.2f %#8.2f %#8.2f",
				double (Mat(2, 0)), double (Mat(2, 1)), double (Mat(2, 2)));
	}

	const scalar sec_per_us(1e-6);
}

/** \brief Direction cosine matrix demo application entry
 *
 * This is the main entry point of the MEMS accelerometer and gyroscope
 * application.  It performs all initialization of the devices, bus
 * interface, as well as serial and GPIO interfaces
 *
 * Once the initialization is complete, the function enters an infinite
 * loop in which the X, Y, and Z axes of the accelerometer and gyroscope
 * are read and the corresponding data values are used in the calculation
 * of rotation angles and a direction cosine matrix.
 */
int main(void)
{
	/* Initialize the board (Xplain UC3 or XMEGA & Xplain Sensor boards)
	 * I/O pin mappings and any other configurable resources selected in
	 * the build configuration.
	 */
	sensor_platform_init();

	/* Attach some descriptors to the existing sensor devices. */
	sensor_t accelerometer;
	sensor_t gyroscope;
	sensor_t &thermometer(gyroscope);

	sensor_attach(&accelerometer, SENSOR_TYPE_ACCELEROMETER, 0, 0);
	sensor_attach(&gyroscope, SENSOR_TYPE_GYROSCOPE, 0, 0);

	if (accelerometer.err || gyroscope.err) {
		puts("\rSensor initialization error.");

		while (true) {
			/* Error occurred, loop forever */
		}
	}

	scalar t_previous(0);

	sensor_data_t tmp;
	sensor_data_t acc;
	sensor_data_t rot;

	tmp.scaled = true;
	acc.scaled = true;
	rot.scaled = true;

	while (true) {
		sensor_get_temperature(&thermometer, &tmp);
		sensor_get_acceleration(&accelerometer, &acc);
		sensor_get_rotation(&gyroscope, &rot);

		const scalar dt(sec_per_us * (rot.timestamp - t_previous));
		t_previous = rot.timestamp;

		/** \todo Linear Acceleration Rate
		 *
		 * Separate the accelerometer data into gravitation and
		 * acceleration components. Subtract the gravity force from the data to
		 * get the current acceleration.
		 */
		vector acceleration(acc.axis.x, acc.axis.y, acc.axis.z);
		static vector gravity(0, 0, 1000 /* milli-g */);

		acceleration.normalize();

		/** \todo Device Orientation
		 *
		 * Static orientation angles relative to the gravity vector can
		 * be calculated in a variety of ways. Rotations about body axes
		 * and changes in heading must be accounted for using gyroscope and/or
		 * compass data.
		 *
		 * For the Euler-angle orientation, add code to support setting the
		 * yaw from a calibrated compass heading.
		 *
		 * For the axis-angle orientation, write a method to extract
		 * orientation angles from the orientation quaternion.
		 */
#if defined(AXIS_ANGLE_ORIENTATION)
		scalar const angle(acos(acceleration.dot(gravity.unit())));
		vector const axis(acceleration.cross(gravity.unit()));

		quaternion orientation(cos(angle / 2), sin(angle / 2) * axis);
#elif defined(EULER_ANGLE_ORIENTATION)
		scalar const pitch(atan2( acceleration.y, acceleration.z));
		scalar const roll(atan2(-acceleration.x, acceleration.z));
		scalar const yaw(atan2( acceleration.x, acceleration.y));

		quaternion orientation
			(quaternion(cos(pitch / 2), sin(pitch / 2) * vector(1, 0, 0)) *
			quaternion(cos(roll / 2), sin(roll / 2)  * vector(0, 1, 0)) *
			quaternion(cos(yaw / 2), sin(yaw / 2)   * vector(0, 0, 1)));
#endif

		orientation.normalize();

		/** \todo   Angular Velocity Rate
		 *
		 * Adjust the static orientation by "integrating" gyroscope angular
		 * rotation rate data.  Track angular velocity deltas between samples.
		 * Periodically recalibrate the gyroscope data using accelerometer
		 * roll-pitch drift correction and compass data for yaw (heading)
		 * drift correction.
		 *
		 * Select scaling and units appropriate to calculations and math
		 * functions.  For example, scaled gyroscope data my be in
		 * degree-per-second units, but the standard C-library math functions
		 * work in radians.
		 *
		 * quaternion omega (0, rot.angle.pitch, rot.angle.roll, rot.angle.yaw);
		 *
		 * omega *= (orientation * dt) / 2;
		 * orientation += omega;
		 */

		static int32_t tmp_last;

		if (abs(tmp.temperature.value - tmp_last) > 1) {
			/*! \todo Implement temperature drift compensation.
			 * ...
			 */
			tmp_last = tmp.temperature.value;
		}

		vector const euler(quaternion2euler(orientation));

		printf
			("\r\n__________________________________________________"
				"\r\n     accelerometer: (%7ld, %7ld, %7ld)"
				"\r\n         gyroscope: (%7ld, %7ld, %7ld)"
				"\r\nstatic orientation: (%#7.2f, %#7.2f, %#7.2f)\r\n\r\nDCM:",
				acc.axis.x, acc.axis.y, acc.axis.z,
				rot.axis.x, rot.axis.y, rot.axis.z,
				DEGREES(euler.x), DEGREES(euler.y),
				DEGREES(euler.z));

		print_matrix(quaternion2DCM(orientation));

		delay_ms(3000);
	}

	return 0;
}
