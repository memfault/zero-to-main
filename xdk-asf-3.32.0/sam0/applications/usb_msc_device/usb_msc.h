/**
 * \file
 *
 * \brief USB Mass Storage Class Driver
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

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* USB GCLK generator */
#define USB_GCLK_GEN                    1
/* USB SOF callback*/
#define USB_CALLBACK_SOF                main_callback_sof

/*Total number of endpoint is 3 control endpoint -1, BULK OUT Endpoint -2*/
#define TOTAL_EP                        3
/* Default Control Endpoint is 0 */
#define CTRL_EP                         0
/* BULK IN Endpoint is 1 */
#define MSC_BULK_IN_EP                  1
/* BULK OUT Endpoint is 2 */
#define MSC_BULK_OUT_EP                 2
/*Control Endpoint size - 64 bytes */
#define CTRL_EP_SIZE                    64
/*BULK IN/OUT Endpoint size - 64 bytes */
#define MSC_BULK_IN_EP_SIZE             64
#define MSC_BULK_OUT_EP_SIZE            64

/* USB standard request code */
#define STD_GET_STATUS_ZERO             0x0080
#define STD_GET_STATUS_INTERFACE        0x0081
#define STD_GET_STATUS_ENDPOINT         0x0082

#define STD_CLEAR_FEATURE_ZERO          0x0100
#define STD_CLEAR_FEATURE_INTERFACE     0x0101
#define STD_CLEAR_FEATURE_ENDPOINT      0x0102

#define STD_SET_FEATURE_ZERO            0x0300
#define STD_SET_FEATURE_INTERFACE       0x0301
#define STD_SET_FEATURE_ENDPOINT        0x0302

#define STD_SET_ADDRESS                 0x0500
#define STD_GET_DESCRIPTOR              0x0680
#define STD_SET_DESCRIPTOR              0x0700
#define STD_GET_CONFIGURATION           0x0880
#define STD_SET_CONFIGURATION           0x0900
#define STD_GET_INTERFACE               0x0A81
#define STD_SET_INTERFACE               0x0B01
#define STD_SYNCH_FRAME                 0x0C82

/*MSC class specific request*/
#define GET_MAX_LUN                     0xFEA1
#define MASS_STORAGE_RESET              0xFF21

#define MIN(a, b)                       (((a) < (b)) ? (a) : (b))
#define COMPILER_PACK_SET(alignment)    COMPILER_PRAGMA(pack(alignment))
#define COMPILER_PACK_RESET()           COMPILER_PRAGMA(pack())

#if defined (USB_CALLBACK_SOF)
typedef void (*callback_t)(void);

void usb_set_callback(callback_t callback_func);
void main_callback_sof(void);

#endif

void usb_init(void);
int32_t USB_Write(uint8_t *pData, int32_t length, uint8_t ep_num);
