/**
 * \file
 *
 * \brief Analog Devices ADXL345Z Digital, triaxial acceleration sensor driver.
 *
 * This module defines registers, constants, data structures, and
 * global function prototypes for an ADI ADXL345Z sensor driver.
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
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#include "adxl345z.h"

/** Analog Devices ADXL345Z Range Table (milli-g, register value) */
static const sensor_map_t range_table[] = {

};

/** Analog Devices ADXL345Z Bandwidth Table (Hertz, register value) */
static const sensor_map_t band_table[] = {

};

/**
 * @brief Analog Devices ADXL345Z accelerometer driver initialization.
 *
 * This is the main initialization function for the ADXL345Z device.
 *
 * @param sensor    Address of a sensor device descriptor.
 * @param reserved  Reserved value.
 *
 * @return bool     true if the call succeeds, else false is returned.
 */
bool adxl345z_init(sensor_t *sensor, int reserved)
{
	bool status = false;
	sensor_hal_t *const hal = sensor->hal;

	if (0xe5 == sensor_bus_get(hal, ADXL345Z_DEVID)) {
		/* Set the driver function table and capabilities pointer. */
		static const sensor_device_t adxl345z_device = {
			.func.read        = adxl345z_read,
			.func.ioctl       = adxl345z_ioctl,
			.func.selftest    = adxl345_selftest,
			.func.event       = adxl345_event,

			.caps.feature     = SENSOR_CAPS_3_AXIS    |
					SENSOR_CAPS_SELFTEST  |
					SENSOR_CAPS_TAP_EVENT |
					SENSOR_CAPS_DROP_EVENT,

			.caps.vendor      = SENSOR_VENDOR_ADI,
			.caps.range_table = range_table,
			.caps.band_table  = band_table,
			.caps.range_count = ARRAYSIZE(range_table),
			.caps.band_count  = ARRAYSIZE(band_table),
			.caps.units       = SENSOR_UNITS_g0,
			.caps.scale       = SENSOR_SCALE_milli,
			.caps.name = "ADXL345Z Digital, triaxial acceleration sensor"
		};

		sensor->drv = &adxl345z_device;

		/* Set the driver (device) default range, bandwidth, &
		 * resolution.
		 * Per the ADXL345Z Datasheet the default range and bandwidth
		 * after device reset are +/- 2g and 100Hz respectively.
		 */
		hal->range      = 2000;
		hal->bandwidth  = 100;
		hal->resolution = 10;
		hal->burst_addr = ADXL345Z_DATAX0;

		/* After power is applied the device enters standby mode, where
		 * power consumption is minimized and the device waits for the
		 * command to enter measurement mode. While in standby mode, any
		 * register can be read or written to configure the part.
		 * Configure the part in standby mode prior to enabling
		 * measurement mode.
		 */
		sensor_reg_bitset(hal, ADXL345Z_POWER_CTL, POWER_CTL_MEASURE);

		/* Install an interrupt handler. */
		if ((STATUS_OK == hal->bus.status) &&
				sensor_irq_connect(hal->mcu_sigint,
				adxl345z_isr, hal)) {
			status = true;
		}
	}

	return status;
}
