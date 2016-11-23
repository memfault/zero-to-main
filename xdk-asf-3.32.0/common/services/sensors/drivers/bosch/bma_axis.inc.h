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
#ifndef _BMA_AXIS_H_
#define _BMA_AXIS_H_

#include <asf.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name Bosch Accelerometer Driver Axis Types
 * @{
 */

/**
 * @brief Bosch 8-bit Axis Data Format
 *
 * The BMA222 stores 2's-complement 8-bit axis data samples split across
 * two contiguous 8-bit device locations where the lower address in the
 * device register space stores a 1-bit "new data" flag and the next
 * higher address stores the 8 most significant bits of the axis data.
 */
typedef union {
	int16_t word;

	struct {
		uint16_t unused   : 7;
		uint16_t new_data : 1;
		int16_t acc_msb   : 8;
	} field;
} bma_axis8_t;

/**
 * @brief Bosch 10-bit Axis Data Format
 *
 * The BMA020, BMA150, and BMA250 store 2's-complement 10-bit axis data
 * samples split across two contiguous 8-bit device locations where the
 * lower address in the device register space stores a 1-bit "new data"
 * flag and the next higher locations store the 10 most significant bits
 * of the axis data.
 */
typedef union {
	int16_t word;

	struct {
		uint16_t acc_lsb  : 2;
		uint16_t unused   : 5;
		uint16_t new_data : 1;
		int16_t acc_msb   : 8;
	} field;
} bma_axis10_t;

/**
 * @brief Bosch 14-bit Axis Data Format
 *
 * The BMA180 stores 2's-complement 14-bit axis data samples split across
 * two contiguous 8-bit device locations where the lower address in the
 * device register space stores the 6 least significant bits and the next
 * higher address stores the 8 most significant bits of the axis data.
 */
typedef union {
	int16_t word;

	struct {
		uint16_t acc_lsb  : 6;
		uint16_t unused   : 1;
		uint16_t new_data : 1;
		int16_t acc_msb   : 8;
	} field;
} bma_axis14_t;

/** @} */

/**
 * @name Bosch Accelerometer Driver Axis Value (type conversion)
 * @{
 */

/**
 * @brief Construct a signed value from a raw axis sample.
 *
 * The BMA222 returns little-endian 2's-complement 8-bit axis values
 * stored within a 16-bit word.
 *
 * @param   axis    An bma_axis8_t type storing a raw sensor axis sample.
 * @return          The aligned and sign-extended axis data value.
 */
static inline int16_t bma_axis8_val(const bma_axis8_t axis)
{
#if UC3
	return axis.field.acc_msb;
#elif XMEGA
	return (axis.word >> 8);
#endif
}

/**
 * @brief Construct a signed value from a raw axis sample.
 *
 * The BMA020, BMA150, and BMA250 return little-endian 2's-complement
 * 10-bit axis values stored within a 16-bit word.
 *
 * @param   axis    An bma_axis10_t type storing a raw sensor axis sample.
 * @return          The aligned and sign-extended axis data value.
 */
static inline int16_t bma_axis10_val(const bma_axis10_t axis)
{
#if UC3
	return (axis.field.acc_msb << 2) | (axis.field.acc_lsb);
#elif XMEGA
	return (axis.word >> 6);
#endif
}

/**
 * @brief Construct a signed value from a raw axis sample.
 *
 * The BMA180 returns little-endian 2's-complement 14-bit axis values
 * stored within a 16-bit word.
 *
 * @param   axis    An bma_axis14_t type storing a raw sensor axis sample.
 * @return          The aligned and sign-extended axis data value.
 */
static inline int16_t bma_axis14_val(const bma_axis14_t axis)
{
#if UC3
	return (axis.field.acc_msb << 6) | (axis.field.acc_lsb);
#elif XMEGA
	return (axis.word >> 2);
#endif
}

/** @} */

#ifdef __cplusplus
}
#endif

#endif
