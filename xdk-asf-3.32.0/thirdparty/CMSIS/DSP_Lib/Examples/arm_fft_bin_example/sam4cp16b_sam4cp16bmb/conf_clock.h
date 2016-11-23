/**
 * \file
 *
 * \brief SAM4CP clock configuration.
 *
 * Copyright (c) 2014-2015 Atmel Corporation. All rights reserved.
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

#ifndef CONF_CLOCK_H_INCLUDED
#define CONF_CLOCK_H_INCLUDED

// ===== System Clock (MCK) Source Options
//#define CONFIG_SYSCLK_SOURCE        SYSCLK_SRC_SLCK_RC
//#define CONFIG_SYSCLK_SOURCE        SYSCLK_SRC_SLCK_XTAL
//#define CONFIG_SYSCLK_SOURCE        SYSCLK_SRC_SLCK_BYPASS
//#define CONFIG_SYSCLK_SOURCE        SYSCLK_SRC_MAINCK_4M_RC
//#define CONFIG_SYSCLK_SOURCE        SYSCLK_SRC_MAINCK_8M_RC
//#define CONFIG_SYSCLK_SOURCE        SYSCLK_SRC_MAINCK_12M_RC
//#define CONFIG_SYSCLK_SOURCE        SYSCLK_SRC_MAINCK_XTAL
//#define CONFIG_SYSCLK_SOURCE        SYSCLK_SRC_MAINCK_BYPASS
//#define CONFIG_SYSCLK_SOURCE        SYSCLK_SRC_PLLACK
#define CONFIG_SYSCLK_SOURCE        SYSCLK_SRC_PLLBCK

// ===== System Clock (MCK) Prescaler Options   (Fmck = Fsys / (SYSCLK_PRES))
#define CONFIG_SYSCLK_PRES          SYSCLK_PRES_1
//#define CONFIG_SYSCLK_PRES          SYSCLK_PRES_2
//#define CONFIG_SYSCLK_PRES          SYSCLK_PRES_4
//#define CONFIG_SYSCLK_PRES          SYSCLK_PRES_8
//#define CONFIG_SYSCLK_PRES          SYSCLK_PRES_16
//#define CONFIG_SYSCLK_PRES          SYSCLK_PRES_32
//#define CONFIG_SYSCLK_PRES          SYSCLK_PRES_64
//#define CONFIG_SYSCLK_PRES          SYSCLK_PRES_3

// ===== PLL0 (A) Options   (8.192M = (32.768K * 250) / 1)
//#define CONFIG_PLL0_SOURCE          PLLA_SRC_SLCK_32K_XTAL

// ===== PLL1 (B) Options   (Fpll = (Fclk * PLL_mul) / PLL_div)
// Use mul and div effective values here.
#define CONFIG_PLL1_SOURCE          PLLB_SRC_MAINCK_BYPASS
#define CONFIG_PLL1_MUL             (240000000UL / BOARD_FREQ_MAINCK_BYPASS)
#define CONFIG_PLL1_DIV             2

// ===== Coprocessor System Clock (CPMCK) Options
// Fcpmck = Fcpclk_source / CPCLK_PRES

// Note:
// CONFIG_CPCLK_ENABLE  MUST be defined if using peripherals on bus matrix 1.
#define CONFIG_CPCLK_ENABLE

// Coprocessor System Clock Source Options
//#define CONFIG_CPCLK_SOURCE         CPCLK_SRC_SLCK
//#define CONFIG_CPCLK_SOURCE         CPCLK_SRC_MAINCK
//#define CONFIG_CPCLK_SOURCE         CPCLK_SRC_PLLACK
//#define CONFIG_CPCLK_SOURCE         CPCLK_SRC_PLLBCK
#define CONFIG_CPCLK_SOURCE         CPCLK_SRC_MCK

// Coprocessor System Clock Prescaler Options (CPCLK_PRES may be 1 to 16).
#define CONFIG_CPCLK_PRES           1

// ===== Main processor frequency (MCK)
// - Bypass mode frequency: 10MHz
// - System clock source: PLLB
// - System clock prescaler: 1 (divided by 1)
// - PLLB source: BYPASS
// - PLLB output: BYPASS * 24 / 2
// - System clock: 10 * 24 / 2 / 1 = 120MHz
//
// ===== Coprocessor frequency (CPMCK)
// - Coprocessor system clock source: MCK
// - Coprocessor system clock prescaler: 1 (divided by 1)
// - Coprocessor system clock: 120MHz / 1 = 120MHz


#endif /* CONF_CLOCK_H_INCLUDED */
