/**
 * \file
 *
 * \brief SAM L21 Xplained Pro Application Configuration.
 *
 * Copyright (c) 2015 Atmel Corporation. All rights reserved.
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
 /**
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#ifndef CONF_APP_H_INCLUDED
#define CONF_APP_H_INCLUDED

#define CONF_EXT_WAKEUP_PIN   PIN_PC01A_EIC_EXTINT9
#define CONF_EXT_WAKEUP_PINMUX MUX_PC01A_EIC_EXTINT9

#define CONF_STDIO_USART          EDBG_CDC_MODULE
#define CONF_STDIO_MUX_SETTING    EDBG_CDC_SERCOM_MUX_SETTING
#define CONF_STDIO_PINMUX_PAD0    EDBG_CDC_SERCOM_PINMUX_PAD0
#define CONF_STDIO_PINMUX_PAD1    EDBG_CDC_SERCOM_PINMUX_PAD1
#define CONF_STDIO_PINMUX_PAD2    EDBG_CDC_SERCOM_PINMUX_PAD2
#define CONF_STDIO_PINMUX_PAD3    EDBG_CDC_SERCOM_PINMUX_PAD3
#define CONF_STDIO_BAUDRATE       38400

#define CONF_STDIO_PAD0_PIN PIN_PC24D_SERCOM4_PAD2
#define CONF_STDIO_PAD1_PIN PIN_PC25D_SERCOM4_PAD3

#define ACTIVE_MODE_PL0		'a'
#define ACTIVE_MODE_PL2		'b'
#define IDLE_MODE			'c'
#define STANDBY_MODE		'd'
#define BACKUP_MODE			'e'
#define OFF_MODE			'f'

#define UNUSED_GPIO_POWER_SAVE

//milli seconds
#define CONF_RTC_WAKEUP 5000

//comment the following DEBUG_ENABLE constant if we want to test the sleep mode individually without user menu on EDBG virtual COM port
#define DEBUG_ENABLE

//The 'TEST_X_MODE' constant is used only when DEBUG_ENABLE is not used (i.e when 'DEBUG_ENABLE' constant is commented)

//uncomment (only) one of the below sleep mode which we want to test 

//#define TEST_ACTIVE_PL0_MODE	'a'
//#define TEST_ACTIVE_PL2_MODE	'b'
//#define TEST_IDLE_MODE		'c'
//#define TEST_STANDBY_MODE		'd'
//#define TEST_BACKUP_MODE		'e'
//#define TEST_OFF_MODE			'f'
   
#endif
