/**
 * \file
 *
 * \brief Sensor API Platform Bus Interfaces
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

#ifndef _SENSOR_BUS_H_
#define _SENSOR_BUS_H_

#include <status_codes.h>

#ifdef __cplusplus
extern "C" {
#endif

/** \brief Platform Bus Type Constants */
typedef enum {
	BUS_TYPE_UNKNOWN,                   /**< Unknown bus */
	BUS_TYPE_TWI,                       /**< TWI/I2C bus */
	BUS_TYPE_SPI,                       /**< SPI bus */
	BUS_TYPE_PMBUS,                     /**< PMBus protocol */
	BUS_TYPE_SMBUS                      /**< SMBus protocol */
} bus_type_t;

/** \brief Platform Bus Status Constants */
typedef status_code_t bus_status_t;

/** \internal Platform Bus Interface Types */

#if UC3
typedef volatile avr32_spi_t *spi_if;
#else
typedef SPI_t *spi_if;
#endif

/** \brief Platform Bus Interface Descriptor */
typedef struct {
	bus_type_t type;                    /**< Bus type and protocol */
	volatile void *id;                  /**< Bus interface address */
	uint16_t addr;                      /**< Device bus address */
	bus_status_t status;                /**< Bus transaction status */
	bool no_wait;                       /**< Bus transaction non-wait option */
} bus_desc_t;

/** \name System Bus I/O Access Methods */
/** @{ */

/** \internal Initialize the bus I/O interface.
 *
 * \param   busif   The address of a system bus (registers) interface.
 * \param   speed   The bus data rate.
 *
 * \retval  true    The bus was initialized.
 * \retval  false   The bus was not initialized.
 */
bool bus_init(volatile void *busif, uint32_t speed);

/** \brief Read multiple Bytes from a bus interface.
 *
 * \param   bus     An initialized bus interface descriptor.
 * \param   addr    The device register or memory address.
 * \param   data    The destination read buffer address.
 * \param   count   The destination read buffer size (Bytes).
 *
 * \return The number of Bytes read, which may be less than the
 *         requested number of Bytes in the event of an error.
 */
size_t bus_read(bus_desc_t *bus, uint8_t addr, void *data, size_t count);

/** \brief Write multiple Bytes to a bus interface.
 *
 * \param   bus     An initialized bus interface descriptor.
 * \param   addr    The device register or memory address.
 * \param   data    The source write buffer address.
 * \param   count   The source write buffer size (Bytes).
 *
 * \return The number of Bytes written, which may be less than the
 *         requested number of Bytes in the event of an error.
 */
size_t bus_write(bus_desc_t *bus, uint8_t addr, const void *data, size_t count);

/** \brief Determine the existence of a bus device
 *
 * This routine determines the existence of a device located at a bus interface
 * and address specified by an initialized \c bus descriptor.
 * Implementations are only required to return \c true when it can be determined
 * that a device is installed at the bus interface address.
 *
 * \param   bus     An initialized bus interface descriptor.
 * \param   arg     Ignored reserved argument.
 *
 * \retval  true    A device responded to the bus address.
 * \retval  false   A device did not respond to the bus address.
 */
bool bus_probe(bus_desc_t *bus, int arg);

/** \brief Read a single Byte from a bus interface.
 *
 * \param   bus     An initialized bus interface descriptor.
 * \param   addr    The device register or memory address.
 *
 * \return A value fetched from the device.  This value is
 *         undefined in the event of an I/O error.
 */
static inline uint8_t bus_get(bus_desc_t *bus, uint8_t addr)
{
	uint8_t data = 0;
	bus_read(bus, addr, &data, sizeof(uint8_t));

	return data;
}

/** \brief Write a single Byte to a bus interface.
 *
 * \param   bus     An initialized bus interface descriptor.
 * \param   addr    The device register or memory address.
 * \param   data    The value of the Byte to write.
 *
 * \return  Nothing
 */
static inline void bus_put(bus_desc_t *bus, uint8_t addr, uint8_t data)
{
	bus_write(bus, addr, &data, sizeof(uint8_t));
}

/** \brief Clear a bit at a bus device register or memory address.
 *
 * \param   bus     An initialized bus interface descriptor.
 * \param   addr    The device register or memory address.
 * \param   mask    The mask value of the bit to clear.
 *
 * \return  Nothing
 */
static inline void bus_reg_bitclear(bus_desc_t *bus, uint8_t addr,
		uint8_t mask)
{
	bus_put(bus, addr, ~mask & bus_get(bus, addr));
}

/** \brief Set a bit at a bus device register or memory address.
 *
 * \param   bus     An initialized bus interface descriptor.
 * \param   addr    The device register or memory address.
 * \param   mask    The mask value of the bit to set.
 *
 * \return  Nothing
 */
static inline void bus_reg_bitset(bus_desc_t *bus, uint8_t addr, uint8_t mask)
{
	bus_put(bus, addr, mask | bus_get(bus, addr));
}

/** \brief Read a field stored at a device register or memory address
 *
 * This routine reads a specified value from a bit field within a 1-Byte
 * device register or memory address. The set bits in the mask parameter
 * determine the field location. For example, if the mask is 30h and the
 * value AFh is stored in the register, the value 2h will be returned.
 *
 * \param   bus     An initialized bus interface descriptor.
 * \param   addr    The device register or memory address.
 * \param   mask    The mask of the field to set.
 *
 * \return  The value stored in the register or memory field.
 */
uint8_t bus_reg_fieldget(bus_desc_t *bus, uint8_t addr, uint8_t mask);

/** \brief Write a field stored at a device register or memory address
 *
 * This routine writes a specified value to a bit field within a 1-Byte
 * device register or memory address. The set bits in the mask parameter
 * determine the field location. For example, if the mask is 30h and the
 * value is 2h, the value 20h will be bitwise logically OR'd into the
 * 1-Byte register value after clearing the bit values in the field.
 *
 * \param   bus     An initialized bus interface descriptor.
 * \param   addr    The device register or memory address.
 * \param   mask    The mask of the field to set.
 * \param   value   The value of the field to set.
 *
 * \return  Nothing
 */
void bus_reg_fieldset(bus_desc_t *bus, uint8_t addr, uint8_t mask,
		uint8_t value);

/** @} */

#ifdef __cplusplus
}
#endif

#endif
