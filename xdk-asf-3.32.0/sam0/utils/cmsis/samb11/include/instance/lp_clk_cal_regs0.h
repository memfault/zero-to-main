/**
 * \file
 *
 * \brief Instance description for LP_CLK_CAL_REGS0
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

#ifndef _SAMB11_LP_CLK_CAL_REGS0_INSTANCE_
#define _SAMB11_LP_CLK_CAL_REGS0_INSTANCE_

/* ========== Register definition for LP_CLK_CAL_REGS0 peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_LP_CLK_CAL_REGS0_CONFIG_REG (0x4000C000U) /**< (LP_CLK_CAL_REGS0) Configuration of the calibration clocks and the enable of calibration */
#define REG_LP_CLK_CAL_REGS0_CALIB_OSC_COUNT_REG (0x4000C004U) /**< (LP_CLK_CAL_REGS0) Calibration OSC Count Register (Any write sets bit 15 and clears bit 31) */
#define REG_LP_CLK_CAL_REGS0_CALIB_RTC_COUNT_REG (0x4000C008U) /**< (LP_CLK_CAL_REGS0) Calibration RTC Count Register (Any write sets bit 15 and clears bit 31) */
#define REG_LP_CLK_CAL_REGS0_CALIB_STATUS_REG (0x4000C00CU) /**< (LP_CLK_CAL_REGS0) Calibration Status Register */

#else

#define REG_LP_CLK_CAL_REGS0_CONFIG_REG (*(__IO uint16_t*)0x4000C000U) /**< (LP_CLK_CAL_REGS0) Configuration of the calibration clocks and the enable of calibration */
#define REG_LP_CLK_CAL_REGS0_CALIB_OSC_COUNT_REG (*(__I  uint32_t*)0x4000C004U) /**< (LP_CLK_CAL_REGS0) Calibration OSC Count Register (Any write sets bit 15 and clears bit 31) */
#define REG_LP_CLK_CAL_REGS0_CALIB_RTC_COUNT_REG (*(__I  uint32_t*)0x4000C008U) /**< (LP_CLK_CAL_REGS0) Calibration RTC Count Register (Any write sets bit 15 and clears bit 31) */
#define REG_LP_CLK_CAL_REGS0_CALIB_STATUS_REG (*(__I  uint8_t*)0x4000C00CU) /**< (LP_CLK_CAL_REGS0) Calibration Status Register */

#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif /* _SAMB11_LP_CLK_CAL_REGS0_INSTANCE_ */
