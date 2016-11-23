/**
 * \file
 *
 * \brief TWIM Configuration File for AVR UC3.
 *
 * Copyright (C) 2014-2015 Atmel Corporation. All rights reserved.
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
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#ifndef CONF_TWIM_H
#define CONF_TWIM_H

/* The TWIM interface to use */
#define TWI_INTERFACE               MXT143E_XPLAINED_TWI

/* These defines are missing from or wrong in the toolchain header file
 * ip_xxx.h or part.h */

#if UC3C
# if !defined(AVR32_TWIM0_GROUP)
#  define AVR32_TWIM0_GROUP         25
# else
#  warning "Duplicate define(s) to remove from the ASF"
# endif
# if !defined(AVR32_TWIM1_GROUP)
#  define AVR32_TWIM1_GROUP         26
# else
#  warning "Duplicate define(s) to remove from the ASF"
# endif
# if !defined(AVR32_TWIM2_GROUP)
#  define AVR32_TWIM2_GROUP         45
# else
#  warning "Duplicate define(s) to remove from the ASF"
# endif
# define CONF_TWIM_IRQ_LINE          AVR32_TWIM0_IRQ
# define CONF_TWIM_IRQ_GROUP         AVR32_TWIM0_GROUP
# define CONF_TWIM_IRQ_LEVEL         1

#elif UC3A3
# if !defined(AVR32_TWIM0_GROUP)
#  define AVR32_TWIM0_GROUP         11
# else
#  warning "Duplicate define(s) to remove from the ASF"
# endif
# if !defined(AVR32_TWIM1_GROUP)
#  define AVR32_TWIM1_GROUP         12
# else
#  warning "Duplicate define(s) to remove from the ASF"
# endif
# define CONF_TWIM_IRQ_LINE          AVR32_TWIM0_IRQ
# define CONF_TWIM_IRQ_GROUP         AVR32_TWIM0_GROUP
# define CONF_TWIM_IRQ_LEVEL         1

#elif UC3L
# if !defined(AVR32_TWIM0_GROUP)
#   define AVR32_TWIM0_GROUP         20
# else
#  warning "Duplicate define(s) to remove from the ASF"
# endif
# if !defined(AVR32_TWIM1_GROUP)
#  define AVR32_TWIM1_GROUP         21
# else
#  warning "Duplicate define(s) to remove from the ASF"
# endif
# define CONF_TWIM_IRQ_LINE          AVR32_TWIM0_IRQ
# define CONF_TWIM_IRQ_GROUP         AVR32_TWIM0_GROUP
# define CONF_TWIM_IRQ_LEVEL         1

#elif UC3D
# if !defined(AVR32_TWIM_GROUP)
#  define AVR32_TWIM_GROUP         10
# else
#  warning "Duplicate define(s) to remove from the ASF"
# endif
# define CONF_TWIM_IRQ_LINE          AVR32_TWIM_IRQ
# define CONF_TWIM_IRQ_GROUP         AVR32_TWIM_GROUP
# define CONF_TWIM_IRQ_LEVEL         1

#else
# error MCU Not Supported
#endif

#endif /* CONF_TWIM_H */
