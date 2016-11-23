/**
 * \file
 *
 * \brief SAM D11 Direct Memory Access Driver Configuration Header
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
 *
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#ifndef CONF_DMA_H_INCLUDED
#define CONF_DMA_H_INCLUDED


/* Number of DMA channels used in this example */
# define CONF_MAX_USED_CHANNEL_NUM     3


/* 
 * Enable port toggle to calculate idle time.
 * Use Oscilloscope to probe the pins.
 */
#define ENABLE_PORT_TOGGLE


/*
 * This demonstrates DMA peripheral to peripheral transfer 
 * between ADC and USART
 */ 
//#define ADC_DMAC_USART

/*
 * This demonstrates DMA peripheral to memory transfer, memory to 
 * memory transfer and memory to peripheral transfer.
 */
//#define ADC_DMAC_MEM_MEM_USART

/*
 * This demonstrates ADC to USART transfer with out using DMA
 */
//#define ADC_NO_DMAC_USART

/*
 * This demonstrates ADC data transfer from peripheral
 * to memory to and copy to another memory to USART data 
 * register with out using DMA
 */
#define ADC_NO_DMAC_MEM_MEM_USART

#endif
