/**
 * \file
 *
 * \brief Instance description for GPIO2
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

#ifndef _SAMB11_GPIO2_INSTANCE_
#define _SAMB11_GPIO2_INSTANCE_

/* ========== Register definition for GPIO2 peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_GPIO2_DATA          (0x40013000U) /**< (GPIO2) Data Value */
#define REG_GPIO2_DATAOUT       (0x40013004U) /**< (GPIO2) Data Output Register Value */
#define REG_GPIO2_OUTENSET      (0x40013010U) /**< (GPIO2) Output Enable Set */
#define REG_GPIO2_OUTENCLR      (0x40013014U) /**< (GPIO2) Output Enable Clear */
#define REG_GPIO2_INTENSET      (0x40013020U) /**< (GPIO2) Interrupt Enable Set */
#define REG_GPIO2_INTENCLR      (0x40013024U) /**< (GPIO2) Interrupt Enable Clear */
#define REG_GPIO2_INTTYPESET    (0x40013028U) /**< (GPIO2) Interrupt Type Set */
#define REG_GPIO2_INTTYPECLR    (0x4001302CU) /**< (GPIO2) Interrupt Type Clear */
#define REG_GPIO2_INTPOLSET     (0x40013030U) /**< (GPIO2) Polarity-level, edge IRQ Configuration */
#define REG_GPIO2_INTPOLCLR     (0x40013034U) /**< (GPIO2) IRQ Configuration Clear */
#define REG_GPIO2_INTSTATUSCLEAR (0x40013038U) /**< (GPIO2) Interrupt Status */
#define REG_GPIO2_PID4          (0x40013FD0U) /**< (GPIO2) Peripheral ID Register 4 */
#define REG_GPIO2_PID5          (0x40013FD4U) /**< (GPIO2) Peripheral ID Register 5 */
#define REG_GPIO2_PID6          (0x40013FD8U) /**< (GPIO2) Peripheral ID Register 6 */
#define REG_GPIO2_PID7          (0x40013FDCU) /**< (GPIO2) Peripheral ID Register 7 */
#define REG_GPIO2_PID0          (0x40013FE0U) /**< (GPIO2) Peripheral ID Register 0 */
#define REG_GPIO2_PID1          (0x40013FE4U) /**< (GPIO2) Peripheral ID Register 1 */
#define REG_GPIO2_PID2          (0x40013FE8U) /**< (GPIO2) Peripheral ID Register 2 */
#define REG_GPIO2_PID3          (0x40013FECU) /**< (GPIO2) Peripheral ID Register 3 */
#define REG_GPIO2_CID0          (0x40013FF0U) /**< (GPIO2) Component ID Register 0 */
#define REG_GPIO2_CID1          (0x40013FF4U) /**< (GPIO2) Component ID Register 1 */
#define REG_GPIO2_CID2          (0x40013FF8U) /**< (GPIO2) Component ID Register 2 */
#define REG_GPIO2_CID3          (0x40013FFCU) /**< (GPIO2) Component ID Register 3 */

#else

#define REG_GPIO2_DATA          (*(__IO uint16_t*)0x40013000U) /**< (GPIO2) Data Value */
#define REG_GPIO2_DATAOUT       (*(__IO uint16_t*)0x40013004U) /**< (GPIO2) Data Output Register Value */
#define REG_GPIO2_OUTENSET      (*(__IO uint16_t*)0x40013010U) /**< (GPIO2) Output Enable Set */
#define REG_GPIO2_OUTENCLR      (*(__IO uint16_t*)0x40013014U) /**< (GPIO2) Output Enable Clear */
#define REG_GPIO2_INTENSET      (*(__IO uint16_t*)0x40013020U) /**< (GPIO2) Interrupt Enable Set */
#define REG_GPIO2_INTENCLR      (*(__IO uint16_t*)0x40013024U) /**< (GPIO2) Interrupt Enable Clear */
#define REG_GPIO2_INTTYPESET    (*(__IO uint16_t*)0x40013028U) /**< (GPIO2) Interrupt Type Set */
#define REG_GPIO2_INTTYPECLR    (*(__IO uint16_t*)0x4001302CU) /**< (GPIO2) Interrupt Type Clear */
#define REG_GPIO2_INTPOLSET     (*(__IO uint16_t*)0x40013030U) /**< (GPIO2) Polarity-level, edge IRQ Configuration */
#define REG_GPIO2_INTPOLCLR     (*(__IO uint16_t*)0x40013034U) /**< (GPIO2) IRQ Configuration Clear */
#define REG_GPIO2_INTSTATUSCLEAR (*(__IO uint16_t*)0x40013038U) /**< (GPIO2) Interrupt Status */
#define REG_GPIO2_PID4          (*(__I  uint8_t*)0x40013FD0U) /**< (GPIO2) Peripheral ID Register 4 */
#define REG_GPIO2_PID5          (*(__I  uint8_t*)0x40013FD4U) /**< (GPIO2) Peripheral ID Register 5 */
#define REG_GPIO2_PID6          (*(__I  uint8_t*)0x40013FD8U) /**< (GPIO2) Peripheral ID Register 6 */
#define REG_GPIO2_PID7          (*(__I  uint8_t*)0x40013FDCU) /**< (GPIO2) Peripheral ID Register 7 */
#define REG_GPIO2_PID0          (*(__I  uint8_t*)0x40013FE0U) /**< (GPIO2) Peripheral ID Register 0 */
#define REG_GPIO2_PID1          (*(__I  uint8_t*)0x40013FE4U) /**< (GPIO2) Peripheral ID Register 1 */
#define REG_GPIO2_PID2          (*(__I  uint8_t*)0x40013FE8U) /**< (GPIO2) Peripheral ID Register 2 */
#define REG_GPIO2_PID3          (*(__I  uint8_t*)0x40013FECU) /**< (GPIO2) Peripheral ID Register 3 */
#define REG_GPIO2_CID0          (*(__I  uint8_t*)0x40013FF0U) /**< (GPIO2) Component ID Register 0 */
#define REG_GPIO2_CID1          (*(__I  uint8_t*)0x40013FF4U) /**< (GPIO2) Component ID Register 1 */
#define REG_GPIO2_CID2          (*(__I  uint8_t*)0x40013FF8U) /**< (GPIO2) Component ID Register 2 */
#define REG_GPIO2_CID3          (*(__I  uint8_t*)0x40013FFCU) /**< (GPIO2) Component ID Register 3 */

#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif /* _SAMB11_GPIO2_INSTANCE_ */
