/**
 * \file
 *
 * \brief Example specific board configuration file
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
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#ifndef CONF_BOARD_H_INCLUDED
#define CONF_BOARD_H_INCLUDED

/* Because the LED pins are defined statically in the board setup,
 * we have to undefine them before they can be moved to the port used
 * by this example.
 */
#undef LED0_GPIO
#undef LED1_GPIO
#undef LED2_GPIO
#undef LED3_GPIO
#undef LED4_GPIO
#undef LED5_GPIO
#undef LED6_GPIO
#undef LED7_GPIO

#define LED0_GPIO   IOPORT_CREATE_PIN(PORTD,0)
#define LED1_GPIO   IOPORT_CREATE_PIN(PORTD,1)
#define LED2_GPIO   IOPORT_CREATE_PIN(PORTD,2)
#define LED3_GPIO   IOPORT_CREATE_PIN(PORTD,3)
#define LED4_GPIO   IOPORT_CREATE_PIN(PORTD,4)
#define LED5_GPIO   IOPORT_CREATE_PIN(PORTD,5)
#define LED6_GPIO   IOPORT_CREATE_PIN(PORTD,6)
#define LED7_GPIO   IOPORT_CREATE_PIN(PORTD,7)




#endif /* CONF_BOARD_H_INCLUDED */
