/**
 * \file
 *
 * \brief Atmel AVR and AVR UC3 Sensor NVRAM Interfaces
 *
 * This module provides general access to the NVRAM interfaces
 * in the Atmel Software Framework.
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

#ifndef _SENSOR_NVRAM_H_
#define _SENSOR_NVRAM_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <compiler.h>

/** \brief Data type for NVRAM memory addresses. */
typedef uint16_t nvram_addr_t;

/** \brief Atmel platform non-volatile memory spaces. */
/** @{ */
#if XMEGA
#   include <nvm.h>

#   define SENSOR_NVM_BASE      (USER_SIGNATURES_START)
#   define SENSOR_NVM_OFFSET    (0)
#   define SENSOR_NVM_SIZE      (USER_SIGNATURES_SIZE)
#elif defined(AVR32_FLASHC)
#   include <flashc.h>

#   define SENSOR_NVM_BASE      (AVR32_FLASHC_USER_PAGE_ADDRESS)
#   define SENSOR_NVM_OFFSET    (0x10)
#   define SENSOR_NVM_SIZE      (AVR32_FLASHC_USER_PAGE_SIZE)
#elif defined(AVR32_FLASHCDW)
#   include <flashcdw.h>

#   define SENSOR_NVM_BASE      (AVR32_FLASHCDW_USER_PAGE_ADDRESS)
#   define SENSOR_NVM_OFFSET    (0x10)
#   define SENSOR_NVM_SIZE      (AVR32_FLASHCDW_USER_PAGE_SIZE)
#endif
/** @} */

/** \brief Write a buffer to non-volatile RAM
 *
 * This routine writes \c count Bytes to the NVRAM destination pointed
 * to by \c dst from the source buffer pointed to by \c src.
 *
 * \param   dst     the write destination in the NVRAM address space
 * \param   src     the source buffer in program data memory space
 * \param   count   the number of Bytes to write
 *
 * \return  Nothing.
 */
extern void nvram_write(nvram_addr_t dst, const void *src, size_t count);

/** \brief Read a buffer from non-volatile RAM
 *
 * This routine reads \c count Bytes from the NVRAM source pointed
 * to by \c src to the destination buffer pointed to by \c dst.
 *
 * \param   src     the read source in the NVRAM address space
 * \param   dst     the destination buffer in program data memory space
 * \param   count   the number of Bytes to read
 *
 * \return  Nothing.
 */
extern void nvram_read(nvram_addr_t src, void *dst, size_t count);

#ifdef __cplusplus
}
#endif

#endif
