/**
 * \file
 *
 * \brief Sensor API device definitions
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

#ifndef _SENSOR_DEV_h_
#define _SENSOR_DEV_h_

/* Sensor API Definitions */
#include "sensor.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \name Sensor Driver Initialization Entry Points */
/** @{ */
extern bool ak8975_init(sensor_t *, int);
extern bool bma020_init(sensor_t *, int);
extern bool bma150_init(sensor_t *, int);
extern bool bma180_init(sensor_t *, int);
extern bool bma220_init(sensor_t *, int);
extern bool bma222_init(sensor_t *, int);
extern bool bma250_init(sensor_t *, int);
extern bool bmp085_init(sensor_t *, int);
extern bool bmp180_init(sensor_t *, int);
extern bool hmc5883l_init(sensor_t *, int);
extern bool imu3000_init(sensor_t *, int);
extern bool itg3200_init(sensor_t *, int);
extern bool kxtf9_init(sensor_t *, int);
extern bool sfh5712_init(sensor_t *, int);
extern bool sfh7770_init(sensor_t *, int);
/** @} */

/** \name Sensor Device Bus Addresses
 *
 * Each driver must have a bus address $(name)_bus_addr defined here, where
 * $(name) is the same prefix used for the driver $(name)_init function.
 *
 * The bus address definitions are keyed off build constants and will vary
 * by application.  If the bus does not assign particular addresses, then
 * define the address as (0).  If, as is the case with TWI/I2C, the device
 * responds to a specific address, then define the constant bus address value.
 *
 * The default values provided here may be modified or redefined by specific
 * board and bus implementations.
 *
 * @{
 */
#if defined(CONF_SENSOR_BUS_TWI)
#   define ak8975_bus_addr      (0x0c)
#   define kxtf9_bus_addr       (0x0f)
#   define hmc5883l_bus_addr    (0x1e)
#   define bma020_bus_addr      (0x38)
#   define bma150_bus_addr      (0x38)
#   define bma180_bus_addr      (0x40)
#   define bma220_bus_addr      (0x0b)
#   define bma222_bus_addr      (0x08)
#   define bma250_bus_addr      (0x18)
#   define bmp085_bus_addr      (0x77)
#   define bmp180_bus_addr      (0x77)
#   define imu3000_bus_addr     (0x68)
#   define itg3200_bus_addr     (0x68)
#   define sfh5712_bus_addr     (0x29)
#   define sfh7770_bus_addr     (0x38)
#else
#   define ak8975_bus_addr      (0)
#   define kxtf9_bus_addr       (0)
#   define hmc5883l_bus_addr    (0)
#   define bma020_bus_addr      (0)
#   define bma150_bus_addr      (0)
#   define bma180_bus_addr      (0)
#   define bma220_bus_addr      (0)
#   define bma222_bus_addr      (0)
#   define bma250_bus_addr      (0)
#   define bmp085_bus_addr      (0)
#   define bmp180_bus_addr      (0)
#   define imu3000_bus_addr     (0)
#   define itg3200_bus_addr     (0)
#   define sfh5712_bus_addr     (0)
#   define sfh7770_bus_addr     (0)
#endif
/** @} */

#ifdef __cplusplus
}
#endif

#endif
