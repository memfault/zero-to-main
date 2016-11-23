/**
 * \file
 *
 * \brief Atmel Development Board Clock Configuration (ASF)
 *
 * Copyright (c) 2010-2015 Atmel Corporation. All rights reserved.
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
#ifndef CONF_CLOCK_H_INCLUDED
#define CONF_CLOCK_H_INCLUDED

#if (UC3A3 || UC3C)
#   define CONFIG_SYSCLK_INIT_CPUMASK   (0)
#   define CONFIG_SYSCLK_INIT_PBAMASK   (0)
#   define CONFIG_SYSCLK_INIT_PBBMASK   (0)
#   define CONFIG_SYSCLK_INIT_HSBMASK   (0)
#elif UC3L
#   define CONFIG_SYSCLK_INIT_CPUMASK   (0)
#   define CONFIG_SYSCLK_INIT_PBAMASK   (0)
#   define CONFIG_SYSCLK_INIT_PBBMASK   (0)
#   define CONFIG_SYSCLK_INIT_HSBMASK   (0)
#endif

#if UC3A3
#   define CONFIG_SYSCLK_SOURCE         (SYSCLK_SRC_OSC0)
#   define CONFIG_SYSCLK_CPU_DIV        (0)
#   define CONFIG_SYSCLK_PBA_DIV        (0)
#   define CONFIG_SYSCLK_PBB_DIV        (0)
#   define CONFIG_PLL0_SOURCE           (PLL_SRC_OSC0)
#   define CONFIG_PLL0_MUL              (48000000UL / BOARD_OSC0_HZ)
#   define CONFIG_PLL0_DIV              (1)
#   define CONFIG_USBCLK_SOURCE         (USBCLK_SRC_OSC0)
#   define CONFIG_USBCLK_DIV            (1)
#   define CONFIG_PLL1_SOURCE           (PLL_SRC_OSC0)
#   define CONFIG_PLL1_DIV              (2)
#   define CONFIG_PLL1_MUL              (8)
#elif UC3L
#   define CONFIG_SYSCLK_SOURCE         (SYSCLK_SRC_DFLL)
#   define CONFIG_DFLL0_SOURCE          (GENCLK_SRC_OSC32K)
#   define CONFIG_DFLL0_MUL             (80000000UL / BOARD_OSC32_HZ)
#   define CONFIG_DFLL0_DIV             (2)
#elif UC3C
#   define CONFIG_SYSCLK_SOURCE         (SYSCLK_SRC_RC8M)
#elif XMEGA_A1 || XMEGA_A1U
#   define CONFIG_SYSCLK_SOURCE         (SYSCLK_SRC_PLL)
#   define CONFIG_SYSCLK_PSADIV         (SYSCLK_PSADIV_1)
#   define CONFIG_SYSCLK_PSBCDIV        (SYSCLK_PSBCDIV_1_2)
#   define CONFIG_PLL0_SOURCE           (PLL_SRC_RC32MHZ)
#   define CONFIG_PLL0_MUL              (8)
#   define CONFIG_PLL0_DIV              (4)
#elif XMEGA_B1
#   define CONFIG_USBCLK_SOURCE                (USBCLK_SRC_RCOSC)
#   define CONFIG_OSC_RC32_CAL                 (48000000UL)
#   define CONFIG_OSC_AUTOCAL_RC32MHZ_REF_OSC  (OSC_ID_USBSOF)
#   define CONFIG_SYSCLK_SOURCE                (SYSCLK_SRC_RC32MHZ)
#   define CONFIG_SYSCLK_PSADIV                (SYSCLK_PSADIV_2)
#   define CONFIG_SYSCLK_PSBCDIV               (SYSCLK_PSBCDIV_1_1)
#elif XMEGA_A3B || XMEGA_A3BU

/*  Configuration using On-Chip RC oscillator at 48MHz */
/*    The RC oscillator is calibrated via USB Start Of Frame */
/*    Clk USB     = 48MHz (used by USB) */
/*    Clk sys     = 48MHz */
/*    Clk cpu/per = 24MHz */
#   define CONFIG_USBCLK_SOURCE                (USBCLK_SRC_RCOSC)
#   define CONFIG_OSC_RC32_CAL                 (48000000UL)
#   define CONFIG_OSC_AUTOCAL_RC32MHZ_REF_OSC  (OSC_ID_USBSOF)
#   define CONFIG_SYSCLK_SOURCE                (SYSCLK_SRC_RC32MHZ)
#   define CONFIG_SYSCLK_PSADIV                (SYSCLK_PSADIV_2)
#   define CONFIG_SYSCLK_PSBCDIV               (SYSCLK_PSBCDIV_1_1)
#endif

#endif /* CONF_CLOCK_H_INCLUDED */
