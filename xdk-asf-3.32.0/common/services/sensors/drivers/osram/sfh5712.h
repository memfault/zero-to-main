/**
 * \file
 *
 * \brief Osram SFH5712 light sensor driver.
 *
 * This file contains functions for initializing and reading data
 * from a Osram SFH5712 light sensor.
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
#ifndef _SFH5712_H_
#define _SFH5712_H_

#include <asf.h>

#ifdef __cplusplus
extern "C" {
#endif

/* TWI/I2C address (write @ 0x52 on bus, read @ 0x53 on bus) */

#define SFH5712_TWI_ADDR            (0x29)

/* Signed 16-bit axis data sample resolution and alignment */

#define SFH5712_DATA_RESOLUTION     (16)

/** \brief SFH5712 Register Addresses */
/** @{ */

#define SFH5712_ALS_CONTROL         (0x80)   /* ambient light sensor control */
#define SFH5712_PART_ID             (0x8A)   /* part id & revision */
#define SFH5712_MAN_ID              (0x8B)   /* manufacturer id */
#define SFH5712_ALS_DATA_LSB        (0x8C)   /* light meas data (low 8 bits) */
#define SFH5712_ALS_DATA_MSB        (0x8D)   /* light meas data (high 8 bits) */

/** @} */

/** \brief SFH5712 Register Bit Definitions */
/** @{ */

/* SFH5712_ALS_CONTROL (0x80) ambient light sensor control */

#define ALS_MODE_MASK               (0x03)  /* light sensor mode mask */
#define ALS_MODE_STANDBY            (0x00)  /* standby mode (default) */
#define ALS_MODE_ACTIVE             (0x03)  /* active mode */

/* SFH5712_PART_ID (0x8A) part ID and revision */

#define PART_REV_MASK               (0x0F)   /* SFH5712 chip revision bit mask */
#define PART_ID_MASK                (0xF0)   /* SFH5712 chip id bit mask */
#define PART_ID_SHIFT               (0x04)   /* bit shift for part ID (upper 4
	                                      * bits) */

#define SFH5712_PART_ID_VAL         (0x80)   /* expected chip id field value */
#define SFH5712_PART_REV_VAL        (0x04)   /* expected chip revision field
	                                      * value */

/* SFH5712_MAN_ID (0x8B) */

#define SFH5712_MAN_ID_VAL          (0x03)   /* expected manufacturer id value */

/** @} */

extern bool sfh5712_init(sensor_t *, int);

#ifdef __cplusplus
}
#endif

#endif
