/**
 * \file
 *
 * \brief TWIM Configuration File for AVR XMEGA.
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
#ifndef _CONF_TWIM_H_
#define _CONF_TWIM_H_

#include <board.h>

#if defined(AVR32_TWIM0_IRQ_GROUP)
#   define AVR32_TWIM0_GROUP    AVR32_TWIM0_IRQ_GROUP
#else
#   define AVR32_TWIM0_GROUP    (AVR32_TWIM0_IRQ / 32)
#endif

#if defined(AVR32_TWIM1_IRQ_GROUP)
#   define AVR32_TWIM1_GROUP    AVR32_TWIM1_IRQ_GROUP
#else
#   define AVR32_TWIM1_GROUP    (AVR32_TWIM1_IRQ / 32)
#endif

#if defined(CONFIG_TWIM_INT_LVL)
#   define CONF_TWIM_IRQ_LEVEL  CONFIG_TWIM_INT_LVL
#else
#   define CONF_TWIM_IRQ_LEVEL  2
#endif

#define CONF_TWIM_IRQ_LINE      AVR32_TWIM0_IRQ
#define CONF_TWIM_IRQ_GROUP     AVR32_TWIM0_GROUP

#endif // _CONF_TWIM_H_
