/**
 * \file Example configuration file AES-128 mode demo example using 
 *        Software Library
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


#ifndef CONF_EXAMPLE_H_
#define CONF_EXAMPLE_H_


/* Set to true to enable respective mode 
 * set to false to disable the respective mode
 */
//Enable/Disable ECB mode
#define AES_ECB    true

//Enable/Disable CBC mode
#define AES_CBC    true

//Enable/Disable CFB mode
#define AES_CFB    true

//Enable/Disable OFB mode
#define AES_OFB    true

//Enable/Disable CTR mode
#define AES_CTR    true


/* If CTR mode is enabled, load the counter, nonce and IV value */
#if (AES_CTR == true)
	#define AES_CTR_IVECTOR  0xC0543B59DA48D90BULL
	#define  AES_CTR_NONCE   0x006CB6DB
	#define  AES_CTR_COUNTER 0x00000001
#endif

// Available CFB modes
#define CFB_MODE_8    8
#define CFB_MODE_64   64
#define CFB_MODE_128  128

#endif /* CONF_EXAMPLE_H_ */