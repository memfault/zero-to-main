/**
 * \file
 *
 * \brief Top header file for SAMC20
 *
 * Copyright (c) 2016 Atmel Corporation. All rights reserved.
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

#ifndef _SAMC20_
#define _SAMC20_

/**
 * \defgroup SAMC20_definitions SAMC20 Device Definitions
 * \brief SAMC20 CMSIS Definitions.
 */

#if   defined(__SAMC20E15A__) || defined(__ATSAMC20E15A__)
  #include "samc20e15a.h"
#elif defined(__SAMC20E16A__) || defined(__ATSAMC20E16A__)
  #include "samc20e16a.h"
#elif defined(__SAMC20E17A__) || defined(__ATSAMC20E17A__)
  #include "samc20e17a.h"
#elif defined(__SAMC20E18A__) || defined(__ATSAMC20E18A__)
  #include "samc20e18a.h"
#elif defined(__SAMC20G15A__) || defined(__ATSAMC20G15A__)
  #include "samc20g15a.h"
#elif defined(__SAMC20G16A__) || defined(__ATSAMC20G16A__)
  #include "samc20g16a.h"
#elif defined(__SAMC20G17A__) || defined(__ATSAMC20G17A__)
  #include "samc20g17a.h"
#elif defined(__SAMC20G18A__) || defined(__ATSAMC20G18A__)
  #include "samc20g18a.h"
#elif defined(__SAMC20J15A__) || defined(__ATSAMC20J15A__)
  #include "samc20j15a.h"
#elif defined(__SAMC20J15AU__) || defined(__ATSAMC20J15AU__)
  #include "samc20j15au.h"
#elif defined(__SAMC20J16A__) || defined(__ATSAMC20J16A__)
  #include "samc20j16a.h"
#elif defined(__SAMC20J16AU__) || defined(__ATSAMC20J16AU__)
  #include "samc20j16au.h"
#elif defined(__SAMC20J17A__) || defined(__ATSAMC20J17A__)
  #include "samc20j17a.h"
#elif defined(__SAMC20J17AU__) || defined(__ATSAMC20J17AU__)
  #include "samc20j17au.h"
#elif defined(__SAMC20J18A__) || defined(__ATSAMC20J18A__)
  #include "samc20j18a.h"
#elif defined(__SAMC20J18AU__) || defined(__ATSAMC20J18AU__)
  #include "samc20j18au.h"
#else
  #error Library does not support the specified device.
#endif

#endif /* _SAMC20_ */
