/**
 * \file
 *
 * \brief Instance description for AON_GP_REGS0
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

#ifndef _SAMB11_AON_GP_REGS0_INSTANCE_
#define _SAMB11_AON_GP_REGS0_INSTANCE_

/* ========== Register definition for AON_GP_REGS0 peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_AON_GP_REGS0_AON_PINMUX_SEL (0x4000F000U) /**< (AON_GP_REGS0) Controls the pinmux selection for the AO GPIOs */
#define REG_AON_GP_REGS0_AON_PMU_CTRL (0x4000F004U) /**< (AON_GP_REGS0) Always On Misc Control */
#define REG_AON_GP_REGS0_AON_BLE_LP_CTRL (0x4000F008U) /**< (AON_GP_REGS0) Always On BLE LP Control */
#define REG_AON_GP_REGS0_AON_MISC_CTRL (0x4000F00CU) /**< (AON_GP_REGS0) Always On Misc Control */
#define REG_AON_GP_REGS0_AON_GLOBAL_RESET (0x4000F010U) /**< (AON_GP_REGS0) Active Low Always On Reset Control */
#define REG_AON_GP_REGS0_AON_PULL_ENABLE (0x4000F014U) /**< (AON_GP_REGS0) Active Low Always On Pull Enable Control */
#define REG_AON_GP_REGS0_AON_RESET_CTRL (0x4000F01CU) /**< (AON_GP_REGS0) Reset Count Control for PD1, PD4, PD6 and PD7 */
#define REG_AON_GP_REGS0_AON_BTRIM_ACTIVE (0x4000F020U) /**< (AON_GP_REGS0) BTRIM settings for active mode (i.e. not in retention) */
#define REG_AON_GP_REGS0_AON_BTRIM_RETENTION (0x4000F024U) /**< (AON_GP_REGS0) BTRIM settings for retention mode */
#define REG_AON_GP_REGS0_AON_LPMCU_SCRATCH_PAD (0x4000F040U) /**< (AON_GP_REGS0) Usage for the LPMCU for any sort of status it needs to store for itself before it goes to sleep */
#define REG_AON_GP_REGS0_AON_LPMCU_COLD_BOOT (0x4000F044U) /**< (AON_GP_REGS0) To be used by ARM to determine if it is a cold boot or not */
#define REG_AON_GP_REGS0_AON_BO_OUT_STATUS (0x4000F080U) /**< (AON_GP_REGS0) Brown Out Detected (must be cleared manually) */
#define REG_AON_GP_REGS0_CLEAR_BROWN_OUT_REG (0x4000F084U) /**< (AON_GP_REGS0) Set to 1 to clear (hold until 0 read at aon_bo_out_status and then this must be cleared to detect another brown out condition) */
#define REG_AON_GP_REGS0_RF_PMU_REGS_0 (0x4000F400U) /**< (AON_GP_REGS0) RF PMU Registers */
#define REG_AON_GP_REGS0_RF_PMU_REGS_1 (0x4000F404U) /**< (AON_GP_REGS0) RF PMU Registers */
#define REG_AON_GP_REGS0_RF_PMU_REGS_2 (0x4000F408U) /**< (AON_GP_REGS0) RF PMU Registers */
#define REG_AON_GP_REGS0_MS_GPIO_MODE (0x4000F410U) /**< (AON_GP_REGS0) Analog Mode Select of Mixed Signal GPIOs */
#define REG_AON_GP_REGS0_IO_PADS_CONTROL (0x4000F414U) /**< (AON_GP_REGS0) Controls behaviour of IO Pads in Sleep Mode */

#else

#define REG_AON_GP_REGS0_AON_PINMUX_SEL (*(__IO uint16_t*)0x4000F000U) /**< (AON_GP_REGS0) Controls the pinmux selection for the AO GPIOs */
#define REG_AON_GP_REGS0_AON_PMU_CTRL (*(__IO uint32_t*)0x4000F004U) /**< (AON_GP_REGS0) Always On Misc Control */
#define REG_AON_GP_REGS0_AON_BLE_LP_CTRL (*(__IO uint8_t*)0x4000F008U) /**< (AON_GP_REGS0) Always On BLE LP Control */
#define REG_AON_GP_REGS0_AON_MISC_CTRL (*(__IO uint32_t*)0x4000F00CU) /**< (AON_GP_REGS0) Always On Misc Control */
#define REG_AON_GP_REGS0_AON_GLOBAL_RESET (*(__IO uint8_t*)0x4000F010U) /**< (AON_GP_REGS0) Active Low Always On Reset Control */
#define REG_AON_GP_REGS0_AON_PULL_ENABLE (*(__IO uint8_t*)0x4000F014U) /**< (AON_GP_REGS0) Active Low Always On Pull Enable Control */
#define REG_AON_GP_REGS0_AON_RESET_CTRL (*(__IO uint32_t*)0x4000F01CU) /**< (AON_GP_REGS0) Reset Count Control for PD1, PD4, PD6 and PD7 */
#define REG_AON_GP_REGS0_AON_BTRIM_ACTIVE (*(__IO uint8_t*)0x4000F020U) /**< (AON_GP_REGS0) BTRIM settings for active mode (i.e. not in retention) */
#define REG_AON_GP_REGS0_AON_BTRIM_RETENTION (*(__IO uint8_t*)0x4000F024U) /**< (AON_GP_REGS0) BTRIM settings for retention mode */
#define REG_AON_GP_REGS0_AON_LPMCU_SCRATCH_PAD (*(__IO uint8_t*)0x4000F040U) /**< (AON_GP_REGS0) Usage for the LPMCU for any sort of status it needs to store for itself before it goes to sleep */
#define REG_AON_GP_REGS0_AON_LPMCU_COLD_BOOT (*(__IO uint8_t*)0x4000F044U) /**< (AON_GP_REGS0) To be used by ARM to determine if it is a cold boot or not */
#define REG_AON_GP_REGS0_AON_BO_OUT_STATUS (*(__I  uint8_t*)0x4000F080U) /**< (AON_GP_REGS0) Brown Out Detected (must be cleared manually) */
#define REG_AON_GP_REGS0_CLEAR_BROWN_OUT_REG (*(__IO uint8_t*)0x4000F084U) /**< (AON_GP_REGS0) Set to 1 to clear (hold until 0 read at aon_bo_out_status and then this must be cleared to detect another brown out condition) */
#define REG_AON_GP_REGS0_RF_PMU_REGS_0 (*(__IO uint32_t*)0x4000F400U) /**< (AON_GP_REGS0) RF PMU Registers */
#define REG_AON_GP_REGS0_RF_PMU_REGS_1 (*(__IO uint32_t*)0x4000F404U) /**< (AON_GP_REGS0) RF PMU Registers */
#define REG_AON_GP_REGS0_RF_PMU_REGS_2 (*(__IO uint16_t*)0x4000F408U) /**< (AON_GP_REGS0) RF PMU Registers */
#define REG_AON_GP_REGS0_MS_GPIO_MODE (*(__IO uint8_t*)0x4000F410U) /**< (AON_GP_REGS0) Analog Mode Select of Mixed Signal GPIOs */
#define REG_AON_GP_REGS0_IO_PADS_CONTROL (*(__IO uint8_t*)0x4000F414U) /**< (AON_GP_REGS0) Controls behaviour of IO Pads in Sleep Mode */

#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif /* _SAMB11_AON_GP_REGS0_INSTANCE_ */
