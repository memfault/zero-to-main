/**
 * \file
 *
 * \brief SAM L21 Xplained Pro board configuration.
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

#ifndef CONF_CCL_EXAMPLE_H_INCLUDED
#define CONF_CCL_EXAMPLE_H_INCLUDED

#define CCL_TC                  TC0                   // Def TC
#define CCL_ALTTC               TC1                   // Alt TC
#define MUX_CCL_TC_OUT          MUX_PB08E_TC0_WO0     // Def TC mux out
#define PIN_CCL_TC_OUT          PIN_PB08E_TC0_WO0     // Def TC pin out
#define MUX_CCL_ALTTC_OUT       MUX_PB10E_TC1_WO0     // Alt TC mux out
#define PIN_CCL_ALTTC_OUT       PIN_PB10E_TC1_WO0     // Alt TC pin out
#define EVSYS_GEN_CCL_TC_OVF    EVSYS_ID_GEN_TC0_OVF  // Def TC event gen overflow
#define EVSYS_GEN_CCL_ALTTC_OVF EVSYS_ID_GEN_TC1_OVF  // Alt TC event gen overflow
#define EVSYS_USER_CCL_ALTTC    EVSYS_ID_USER_TC1_EVU // Alt TC event user
#define CCL_ALTTC_DMAC_OVF      TC1_DMAC_ID_OVF       // Alt TC DMAC trigger

#define MUX_CCL_OUTPUT          MUX_PA07I_CCL_OUT0    // CCL pin out
#define PIN_CCL_OUTPUT          PIN_PA07I_CCL_OUT0    // CCL mux out

#endif /* CONF_CCL_EXAMPLE_H_INCLUDED */
