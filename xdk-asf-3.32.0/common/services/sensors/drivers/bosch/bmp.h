/**
 * \file
 *
 * \brief Bosch Digital pressure sensor common definitions
 *
 * This module defines registers, constants, data structures, and
 * global function prototypes that are common to multiple Bosch sensor
 * drivers, in particular those for BMP085 and BMP180 devices.
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
#ifndef _BMP_COMMON_H_
#define _BMP_COMMON_H_

#include <asf.h>

#ifdef __cplusplus
extern "C" {
#endif

/* TWI/I2C address (write @ 0xee on bus, read @ 0xef on bus) */
#define BMP_TWI_ADDR               (0x77)

/** \brief BMP Register Addresses */
/** @{ */
#define BMP_CHIP_ID                (0xd0)   /* chip ID - always 0x55 */
#define BMP_CHIP_VERSION           (0xd1)   /* chip revision */
#define BMP_SOFT_RESET             (0xe0)   /* reset device */
#define BMP_CONTROL                (0xf4)   /* device control register */
#define BMP_DATA_MSB               (0xf6)   /* temp. or press. data MSB */
#define BMP_DATA_LSB               (0xf7)   /* temp. or press. data LSB */
#define BMP_DATA_XLSB              (0xf8)   /* press. data XLSB (19 bit data) */
/** @} */

/* EEPROM Calibration Coefficient Addresses (MSB | LSB) */

#define BMP_EEPROM_ADDR            (0xaa)   /* BMP085/BMP180 EEPROM base address */
#define BMP_EEPROM_SIZE_BYTES      (22)     /* BMP085/BMP180 EEPROM size (bytes) */

/** \brief BMP Register Bit Definitions */
/** @{ */

/* BMP_CHIP_ID (0xd0) */

#define BMP085_ID_VAL              (0x55)   /* BMP085 chip id value */
#define BMP085_VER_VAL             (0x01)   /* BMP085 chip version value */

#define BMP180_ID_VAL              (0x55)   /* BMP180 chip id value */
#define BMP180_VER_VAL             (0x02)   /* BMP180 chip version value */

/* BMP_SOFT_RESET (0xe0) */

#define BMP_RESET_CMD              (0xb6)   /* soft reset command */

/* BMP_CONTROL (0xf4) */

#define BMP_TEMP_READ              (0x2e)   /* read temperature */
#define BMP_PRESS_READ             (0x34)   /* read pressure (@ osrs = 0) */

/* Operating Ranges */

#define BMP_MIN_hPa                (300)    /* +9 000 (m) above sea level */
#define BMP_MAX_hPa                (1100)   /* -500 (m) above sea level */

#define BMP_MIN_COUNTS             (0)
#define BMP_MAX_COUNTS             (0xfffful)

/** @} */

extern bool bmp085_init(sensor_t *, int);
extern bool bmp180_init(sensor_t *, int);

#ifdef __cplusplus
}
#endif

#endif
