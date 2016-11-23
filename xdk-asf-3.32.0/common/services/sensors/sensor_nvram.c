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

#include "sensor_nvram.h"

#include <sysclk.h>
#include <string.h>

#if defined(AVR32_FLASHC)
#   define SYSCLK_FLASH_REGS    (SYSCLK_FLASHC_REGS)
#   define flash_memcpy         flashc_memcpy
#elif defined(AVR32_FLASHCDW)
#   define SYSCLK_FLASH_REGS    (SYSCLK_FLASHCDW_REGS)
#   define flash_memcpy         flashcdw_memcpy
#endif

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
void nvram_write(nvram_addr_t dst, const void *src, size_t count)
{
#if XMEGA
	nvm_wait_until_ready();
	nvm_user_sig_write_buffer((flash_addr_t)(dst + SENSOR_NVM_OFFSET),
			src, count, true);
	/* check for blank, erase if needed */
#elif UC3
	const bool erase_page = true;
	volatile void *const flash_addr
		= (volatile void *)(dst + SENSOR_NVM_BASE + SENSOR_NVM_OFFSET);

	sysclk_enable_pbb_module(SYSCLK_FLASH_REGS);
	(void)flash_memcpy(flash_addr, src, count, erase_page);
	sysclk_disable_pbb_module(SYSCLK_FLASH_REGS);
#endif
}

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
void nvram_read(nvram_addr_t src, void *dst, size_t count)
{
#if XMEGA
	nvm_wait_until_ready();
	nvm_user_sig_read_buffer((flash_addr_t)(src + SENSOR_NVM_OFFSET), dst,
			count);
#elif UC3
	memcpy(dst, (void *)(src + SENSOR_NVM_BASE + SENSOR_NVM_OFFSET), count);
#endif
}
