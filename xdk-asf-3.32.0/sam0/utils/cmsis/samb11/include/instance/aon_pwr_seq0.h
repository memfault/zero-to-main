/**
 * \file
 *
 * \brief Instance description for AON_PWR_SEQ0
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

#ifndef _SAMB11_AON_PWR_SEQ0_INSTANCE_
#define _SAMB11_AON_PWR_SEQ0_INSTANCE_

/* ========== Register definition for AON_PWR_SEQ0 peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_AON_PWR_SEQ0_GPIO_WAKEUP_CTRL (0x4000E000U) /**< (AON_PWR_SEQ0) Controls the wakeup enable for GPIO_0, GPIO_1 and GPIO_2 (Pinmux will control the ARM wakeup) */
#define REG_AON_PWR_SEQ0_AON_ST_WAKEUP_CTRL (0x4000E00CU) /**< (AON_PWR_SEQ0) Controls the wakeup enable for the Always On Sleep Timer (AON_ST) */
#define REG_AON_PWR_SEQ0_LPMCU_WAKEUP_CTRL (0x4000E010U) /**< (AON_PWR_SEQ0) Controls the wakeup enable for the Low Power Micro Controller Unit (LPMCU) */
#define REG_AON_PWR_SEQ0_BLE_ST_WAKEUP_CTRL (0x4000E014U) /**< (AON_PWR_SEQ0) Controls the wakeup enable for the BLE Sleep Timer (BLE_ST) */
#define REG_AON_PWR_SEQ0_LPMCU_SLEEP_1_CTRL (0x4000E020U) /**< (AON_PWR_SEQ0) Controls the sleep and retention options for SLEEP request 1 from the ARM */
#define REG_AON_PWR_SEQ0_OFF_DELAY_0_CTRL (0x4000E040U) /**< (AON_PWR_SEQ0) Power OFF Delays */
#define REG_AON_PWR_SEQ0_OFF_DELAY_1_CTRL (0x4000E044U) /**< (AON_PWR_SEQ0) Power OFF Delays */
#define REG_AON_PWR_SEQ0_ON_DELAY_0_CTRL (0x4000E048U) /**< (AON_PWR_SEQ0) Power ON Delays */
#define REG_AON_PWR_SEQ0_ON_DELAY_1_CTRL (0x4000E04CU) /**< (AON_PWR_SEQ0) Power ON Delays */
#define REG_AON_PWR_SEQ0_VDD_DCDC_EN_DELAY_CTRL (0x4000E050U) /**< (AON_PWR_SEQ0) VDD_DCDC_EN Delay Control */
#define REG_AON_PWR_SEQ0_MISC_BYPASS_0_CTRL (0x4000E218U) /**< (AON_PWR_SEQ0) Bypass control for misc signals */
#define REG_AON_PWR_SEQ0_RAW_WAKEUP_BITS (0x4000E300U) /**< (AON_PWR_SEQ0) Raw Wakeup Bits */
#define REG_AON_PWR_SEQ0_PD_WAKEUP_BITS (0x4000E304U) /**< (AON_PWR_SEQ0) Individual Power Domain Wakeup Bits */
#define REG_AON_PWR_SEQ0_SERVICED_REQUEST (0x4000E308U) /**< (AON_PWR_SEQ0) Serviced Request Status Bits */
#define REG_AON_PWR_SEQ0_ACTIVE_REQUEST (0x4000E30CU) /**< (AON_PWR_SEQ0) Active Request Status Bits */
#define REG_AON_PWR_SEQ0_LOGIC_FSM_STATES (0x4000E3F0U) /**< (AON_PWR_SEQ0) Current Logic FSM States */

#else

#define REG_AON_PWR_SEQ0_GPIO_WAKEUP_CTRL (*(__IO uint8_t*)0x4000E000U) /**< (AON_PWR_SEQ0) Controls the wakeup enable for GPIO_0, GPIO_1 and GPIO_2 (Pinmux will control the ARM wakeup) */
#define REG_AON_PWR_SEQ0_AON_ST_WAKEUP_CTRL (*(__IO uint8_t*)0x4000E00CU) /**< (AON_PWR_SEQ0) Controls the wakeup enable for the Always On Sleep Timer (AON_ST) */
#define REG_AON_PWR_SEQ0_LPMCU_WAKEUP_CTRL (*(__IO uint16_t*)0x4000E010U) /**< (AON_PWR_SEQ0) Controls the wakeup enable for the Low Power Micro Controller Unit (LPMCU) */
#define REG_AON_PWR_SEQ0_BLE_ST_WAKEUP_CTRL (*(__IO uint8_t*)0x4000E014U) /**< (AON_PWR_SEQ0) Controls the wakeup enable for the BLE Sleep Timer (BLE_ST) */
#define REG_AON_PWR_SEQ0_LPMCU_SLEEP_1_CTRL (*(__IO uint32_t*)0x4000E020U) /**< (AON_PWR_SEQ0) Controls the sleep and retention options for SLEEP request 1 from the ARM */
#define REG_AON_PWR_SEQ0_OFF_DELAY_0_CTRL (*(__IO uint32_t*)0x4000E040U) /**< (AON_PWR_SEQ0) Power OFF Delays */
#define REG_AON_PWR_SEQ0_OFF_DELAY_1_CTRL (*(__IO uint32_t*)0x4000E044U) /**< (AON_PWR_SEQ0) Power OFF Delays */
#define REG_AON_PWR_SEQ0_ON_DELAY_0_CTRL (*(__IO uint16_t*)0x4000E048U) /**< (AON_PWR_SEQ0) Power ON Delays */
#define REG_AON_PWR_SEQ0_ON_DELAY_1_CTRL (*(__IO uint32_t*)0x4000E04CU) /**< (AON_PWR_SEQ0) Power ON Delays */
#define REG_AON_PWR_SEQ0_VDD_DCDC_EN_DELAY_CTRL (*(__IO uint16_t*)0x4000E050U) /**< (AON_PWR_SEQ0) VDD_DCDC_EN Delay Control */
#define REG_AON_PWR_SEQ0_MISC_BYPASS_0_CTRL (*(__IO uint16_t*)0x4000E218U) /**< (AON_PWR_SEQ0) Bypass control for misc signals */
#define REG_AON_PWR_SEQ0_RAW_WAKEUP_BITS (*(__I  uint8_t*)0x4000E300U) /**< (AON_PWR_SEQ0) Raw Wakeup Bits */
#define REG_AON_PWR_SEQ0_PD_WAKEUP_BITS (*(__I  uint16_t*)0x4000E304U) /**< (AON_PWR_SEQ0) Individual Power Domain Wakeup Bits */
#define REG_AON_PWR_SEQ0_SERVICED_REQUEST (*(__I  uint16_t*)0x4000E308U) /**< (AON_PWR_SEQ0) Serviced Request Status Bits */
#define REG_AON_PWR_SEQ0_ACTIVE_REQUEST (*(__I  uint16_t*)0x4000E30CU) /**< (AON_PWR_SEQ0) Active Request Status Bits */
#define REG_AON_PWR_SEQ0_LOGIC_FSM_STATES (*(__I  uint32_t*)0x4000E3F0U) /**< (AON_PWR_SEQ0) Current Logic FSM States */

#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif /* _SAMB11_AON_PWR_SEQ0_INSTANCE_ */
