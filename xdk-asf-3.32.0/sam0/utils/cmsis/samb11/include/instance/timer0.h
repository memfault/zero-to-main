/**
 * \file
 *
 * \brief Instance description for TIMER0
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

#ifndef _SAMB11_TIMER0_INSTANCE_
#define _SAMB11_TIMER0_INSTANCE_

/* ========== Register definition for TIMER0 peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_TIMER0_CTRL         (0x40000000U) /**< (TIMER0) Timer Control */
#define REG_TIMER0_VALUE        (0x40000004U) /**< (TIMER0) Current Value */
#define REG_TIMER0_RELOAD       (0x40000008U) /**< (TIMER0) Reload Value */
#define REG_TIMER0_INTSTATUSCLEAR (0x4000000CU) /**< (TIMER0) Timer Interrupt, write 1 to clear */
#define REG_TIMER0_PID4         (0x40000FD0U) /**< (TIMER0) Peripheral ID Register 4 */
#define REG_TIMER0_PID5         (0x40000FD4U) /**< (TIMER0) Peripheral ID Register 5 */
#define REG_TIMER0_PID6         (0x40000FD8U) /**< (TIMER0) Peripheral ID Register 6 */
#define REG_TIMER0_PID7         (0x40000FDCU) /**< (TIMER0) Peripheral ID Register 7 */
#define REG_TIMER0_PID0         (0x40000FE0U) /**< (TIMER0) Peripheral ID Register 0 */
#define REG_TIMER0_PID1         (0x40000FE4U) /**< (TIMER0) Peripheral ID Register 1 */
#define REG_TIMER0_PID2         (0x40000FE8U) /**< (TIMER0) Peripheral ID Register 2 */
#define REG_TIMER0_PID3         (0x40000FECU) /**< (TIMER0) Peripheral ID Register 3 */
#define REG_TIMER0_CID0         (0x40000FF0U) /**< (TIMER0) Component ID Register 0 */
#define REG_TIMER0_CID1         (0x40000FF4U) /**< (TIMER0) Component ID Register 1 */
#define REG_TIMER0_CID2         (0x40000FF8U) /**< (TIMER0) Component ID Register 2 */
#define REG_TIMER0_CID3         (0x40000FFCU) /**< (TIMER0) Component ID Register 3 */

#else

#define REG_TIMER0_CTRL         (*(__IO uint8_t*)0x40000000U) /**< (TIMER0) Timer Control */
#define REG_TIMER0_VALUE        (*(__IO uint32_t*)0x40000004U) /**< (TIMER0) Current Value */
#define REG_TIMER0_RELOAD       (*(__IO uint32_t*)0x40000008U) /**< (TIMER0) Reload Value */
#define REG_TIMER0_INTSTATUSCLEAR (*(__IO uint8_t*)0x4000000CU) /**< (TIMER0) Timer Interrupt, write 1 to clear */
#define REG_TIMER0_PID4         (*(__I  uint8_t*)0x40000FD0U) /**< (TIMER0) Peripheral ID Register 4 */
#define REG_TIMER0_PID5         (*(__I  uint8_t*)0x40000FD4U) /**< (TIMER0) Peripheral ID Register 5 */
#define REG_TIMER0_PID6         (*(__I  uint8_t*)0x40000FD8U) /**< (TIMER0) Peripheral ID Register 6 */
#define REG_TIMER0_PID7         (*(__I  uint8_t*)0x40000FDCU) /**< (TIMER0) Peripheral ID Register 7 */
#define REG_TIMER0_PID0         (*(__I  uint8_t*)0x40000FE0U) /**< (TIMER0) Peripheral ID Register 0 */
#define REG_TIMER0_PID1         (*(__I  uint8_t*)0x40000FE4U) /**< (TIMER0) Peripheral ID Register 1 */
#define REG_TIMER0_PID2         (*(__I  uint8_t*)0x40000FE8U) /**< (TIMER0) Peripheral ID Register 2 */
#define REG_TIMER0_PID3         (*(__I  uint8_t*)0x40000FECU) /**< (TIMER0) Peripheral ID Register 3 */
#define REG_TIMER0_CID0         (*(__I  uint8_t*)0x40000FF0U) /**< (TIMER0) Component ID Register 0 */
#define REG_TIMER0_CID1         (*(__I  uint8_t*)0x40000FF4U) /**< (TIMER0) Component ID Register 1 */
#define REG_TIMER0_CID2         (*(__I  uint8_t*)0x40000FF8U) /**< (TIMER0) Component ID Register 2 */
#define REG_TIMER0_CID3         (*(__I  uint8_t*)0x40000FFCU) /**< (TIMER0) Component ID Register 3 */

#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif /* _SAMB11_TIMER0_INSTANCE_ */
