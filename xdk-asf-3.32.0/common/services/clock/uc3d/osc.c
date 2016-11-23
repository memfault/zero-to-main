/**
 * \file
 *
 * \brief Chip-specific oscillator management functions
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

#include <osc.h>

#ifdef BOARD_OSC0_HZ
void osc_priv_enable_osc0(void)
{
	irqflags_t flags;

	flags = cpu_irq_save();
	AVR32_SCIF.unlock = 0xaa000000 | AVR32_SCIF_OSCCTRL;
	AVR32_SCIF.oscctrl[0] =
			(OSC0_STARTUP_VALUE << AVR32_SCIF_OSCCTRL_STARTUP)
			| (OSC0_GAIN_VALUE << AVR32_SCIF_OSCCTRL_GAIN)
			| (OSC0_MODE_VALUE << AVR32_SCIF_OSCCTRL_MODE)
			| (1U << AVR32_SCIF_OSCCTRL_OSCEN);
	cpu_irq_restore(flags);
}

void osc_priv_disable_osc0(void)
{
	irqflags_t flags;

	flags = cpu_irq_save();
	AVR32_SCIF.unlock = 0xaa000000 | AVR32_SCIF_OSCCTRL;
	AVR32_SCIF.oscctrl[0] = 0;
	cpu_irq_restore(flags);
}
#endif /* BOARD_OSC0_HZ */

#ifdef BOARD_OSC32_HZ
void osc_priv_enable_osc32(void)
{
	irqflags_t flags;

	flags = cpu_irq_save();
	AVR32_SCIF.unlock = 0xaa000000 | AVR32_SCIF_OSCCTRL32;
	AVR32_SCIF.oscctrl32 =
			(OSC32_STARTUP_VALUE << AVR32_SCIF_OSCCTRL32_STARTUP)
			| (OSC32_MODE_VALUE << AVR32_SCIF_OSCCTRL32_MODE)
			| (1U << AVR32_SCIF_OSCCTRL32_OSC32EN);
	cpu_irq_restore(flags);
}

void osc_priv_disable_osc32(void)
{
	irqflags_t flags;

	flags = cpu_irq_save();
	AVR32_SCIF.unlock = 0xaa000000 | AVR32_SCIF_OSCCTRL32;
	AVR32_SCIF.oscctrl32 = 0;
	cpu_irq_restore(flags);
}
#endif /* BOARD_OSC32_HZ */

void osc_priv_enable_rc120m(void)
{
	irqflags_t flags;

	flags = cpu_irq_save();
	AVR32_SCIF.unlock = 0xaa000000 | AVR32_SCIF_RC120MCR;
	AVR32_SCIF.rc120mcr = 1U << AVR32_SCIF_RC120MCR_EN;
	cpu_irq_restore(flags);
}

void osc_priv_disable_rc120m(void)
{
	irqflags_t flags;

	flags = cpu_irq_save();
	AVR32_SCIF.unlock = 0xaa000000 | AVR32_SCIF_RC120MCR;
	AVR32_SCIF.rc120mcr = 0;
	cpu_irq_restore(flags);
}
