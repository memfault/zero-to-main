/**
 * \file
 *
 * \brief Bosch Digital, triaxial acceleration sensor axis format
 *
 * This module defines accelerometer axis data types and utility routines
 * used in multiple Bosch sensor drivers, including BMA020, BMA150, BMA180,
 * BMA220, BMA222, and BMA250 devices.
 *
 * The module relies upon conditionally compiled types and functions to
 * generate functions specialized for a particular driver module. Driver
 * source modules include this module directly via the C-preprocessor
 * with a #include directive.
 *
 * Copyright (c) 2014-2015 Atmel Corporation. All rights reserved.
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
#ifndef _BMA_AXIS_C_
#define _BMA_AXIS_C_

#include "bma_axis.inc.h"

#if defined(_BMA020_H_)
#   define bma_axis_t       bma_axis10_t
#   define bma_axis_val     bma_axis10_val
#elif defined(_BMA150_H_)
#   define bma_axis_t       bma_axis10_t
#   define bma_axis_val     bma_axis10_val
#elif defined(_BMA180_H_)
#   define bma_axis_t       bma_axis14_t
#   define bma_axis_val     bma_axis14_val
#elif defined(_BMA220_H_)
#   define bma_axis_t       int8_t
#   define bma_axis_val(x)  ((int8_t)((x) >> 2))
#elif defined(_BMA222_H_)
#   define bma_axis_t       bma_axis8_t
#   define bma_axis_val     bma_axis8_val
#elif defined(_BMA250_H_)
#   define bma_axis_t       bma_axis10_t
#   define bma_axis_val     bma_axis10_val
#endif

#if defined(bma_axis_t)

/**
 * @brief Format Bosch 3-axis accelerometer data samples
 *
 * This routine formats Bosch 3-axis accelerometer data using tunable
 * configuration parameters controlling device orientation and flags that
 * indicate whether or not axis data should be scaled in engineering units.
 *
 * @param   hal     Address of an initialized sensor hardware descriptor.
 * @param   acc     Bosch accelerometer axis data samples.
 * @param   data    Address of sensor_data_t structure to return values.
 * @return          Nothing
 */
static void format_axis_data(const sensor_hal_t *hal, const bma_axis_t acc[],
		sensor_data_t *data)
{
	/* Get axis values based based on device orientation configuration. */
	int32_t const acc_x = hal->orientation.x.sign *
			bma_axis_val(acc[hal->orientation.x.axis]);

	int32_t const acc_y = hal->orientation.y.sign *
			bma_axis_val(acc[hal->orientation.y.axis]);

	int32_t const acc_z = hal->orientation.z.sign *
			bma_axis_val(acc[hal->orientation.z.axis]);

	/* Convert raw sensor sample to engineering units if requested. */
	if (data->scaled) {
		data->axis.x = raw_to_scaled(hal, acc_x);
		data->axis.y = raw_to_scaled(hal, acc_y);
		data->axis.z = raw_to_scaled(hal, acc_z);
	} else {
		data->axis.x = acc_x;
		data->axis.y = acc_y;
		data->axis.z = acc_z;
	}
}

#endif

#endif
