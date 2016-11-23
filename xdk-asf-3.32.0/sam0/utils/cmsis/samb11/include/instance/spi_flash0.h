/**
 * \file
 *
 * \brief Instance description for SPI_FLASH0
 *
 * Copyright (c) 2015-2016 Atmel Corporation. All rights reserved.
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

#ifndef _SAMB11_SPI_FLASH0_INSTANCE_
#define _SAMB11_SPI_FLASH0_INSTANCE_

/* ========== Register definition for SPI_FLASH0 peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_SPI_FLASH0_MODE_CTRL (0x40012000U) /**< (SPI_FLASH0) SPI Flash Mode Control */
#define REG_SPI_FLASH0_TRANSACTION_CTRL (0x40012004U) /**< (SPI_FLASH0) Transaction Control (Cleared after each transaction completes) */
#define REG_SPI_FLASH0_READ_CTRL (0x40012008U) /**< (SPI_FLASH0) Read Control (Cleared after each transaction completes) */
#define REG_SPI_FLASH0_CMD_BUFFER0 (0x4001200CU) /**< (SPI_FLASH0) Command Buffer 0 (Bytes 3 - 0) */
#define REG_SPI_FLASH0_CMD_BUFFER1 (0x40012010U) /**< (SPI_FLASH0) Command Buffer 1 (Bytes 7 - 4) */
#define REG_SPI_FLASH0_DIRECTION (0x40012014U) /**< (SPI_FLASH0) Read/Write bit for Bytes 7 - 0 */
#define REG_SPI_FLASH0_IRQ_STATUS (0x40012018U) /**< (SPI_FLASH0) IRQ Status (Write 0 to bit to clear, Read clears interupts) */
#define REG_SPI_FLASH0_DMA_START_ADDRESS (0x4001201CU) /**< (SPI_FLASH0) DMA Starting Address */
#define REG_SPI_FLASH0_CONFIG   (0x40012020U) /**< (SPI_FLASH0) SPI Flash Configuration */
#define REG_SPI_FLASH0_TX_CONTROL (0x40012024U) /**< (SPI_FLASH0) TX Control */
#define REG_SPI_FLASH0_STATUS   (0x40012028U) /**< (SPI_FLASH0) Misc Status */

#else

#define REG_SPI_FLASH0_MODE_CTRL (*(__IO uint8_t*)0x40012000U) /**< (SPI_FLASH0) SPI Flash Mode Control */
#define REG_SPI_FLASH0_TRANSACTION_CTRL (*(__IO uint32_t*)0x40012004U) /**< (SPI_FLASH0) Transaction Control (Cleared after each transaction completes) */
#define REG_SPI_FLASH0_READ_CTRL (*(__IO uint32_t*)0x40012008U) /**< (SPI_FLASH0) Read Control (Cleared after each transaction completes) */
#define REG_SPI_FLASH0_CMD_BUFFER0 (*(__IO uint32_t*)0x4001200CU) /**< (SPI_FLASH0) Command Buffer 0 (Bytes 3 - 0) */
#define REG_SPI_FLASH0_CMD_BUFFER1 (*(__IO uint32_t*)0x40012010U) /**< (SPI_FLASH0) Command Buffer 1 (Bytes 7 - 4) */
#define REG_SPI_FLASH0_DIRECTION (*(__IO uint8_t*)0x40012014U) /**< (SPI_FLASH0) Read/Write bit for Bytes 7 - 0 */
#define REG_SPI_FLASH0_IRQ_STATUS (*(__O  uint8_t*)0x40012018U) /**< (SPI_FLASH0) IRQ Status (Write 0 to bit to clear, Read clears interupts) */
#define REG_SPI_FLASH0_DMA_START_ADDRESS (*(__IO uint32_t*)0x4001201CU) /**< (SPI_FLASH0) DMA Starting Address */
#define REG_SPI_FLASH0_CONFIG   (*(__IO uint16_t*)0x40012020U) /**< (SPI_FLASH0) SPI Flash Configuration */
#define REG_SPI_FLASH0_TX_CONTROL (*(__IO uint16_t*)0x40012024U) /**< (SPI_FLASH0) TX Control */
#define REG_SPI_FLASH0_STATUS   (*(__I  uint16_t*)0x40012028U) /**< (SPI_FLASH0) Misc Status */

#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for SPI_FLASH0 peripheral ========== */
#define SPI_FLASH0_FLASH_SIZE                    131072    
#define SPI_FLASH0_ADDRESS_SPACE_REF             extflash  
#define SPI_FLASH0_PAGES                         2048      
#define SPI_FLASH0_PAGE_SIZE                     64        

#endif /* _SAMB11_SPI_FLASH0_INSTANCE_ */
