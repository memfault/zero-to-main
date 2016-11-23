/**
 * \file
 *
 * \brief Chip-specific system clock management functions
 *
 * Copyright (c) 2014-2016 Atmel Corporation. All rights reserved.
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

#include <compiler.h>
#include <sysclk.h>

/* ! \name System Clock Initialization */
/* @{ */

/**
 *  Function to initialize the clock and disable clock for not required modules.
 */
void sysclk_init(void)
{
#if !MEGA_XX_UN0 && !MEGA_XX_UN1
	uint8_t *reg = (uint8_t *)&(POWER_REG_ADD);
	uint8_t i;
	/* Turn off all peripheral clocks that can be turned off.
	 * The debugWIRE system of some devices that shares system clock with the SPI module.
	 * Thus the PRSPI bit in the PRR register must not be set when debugging.
	 */
	for (i = 0; i < NUMBER_OF_POWER_REG; i++) {
		*(reg++) = 0xFF;
	}
#endif
#if !MEGA_UNSPECIFIED && !MEGA_XX
	/* Set up system clock prescalers if different from defaults */
	if ((CONFIG_SYSCLK_PSDIV != SYSCLK_PSDIV_8) ||
			(SYSCLK_PSDIV_8 != CLKPR)) {
		sysclk_set_prescalers(CONFIG_SYSCLK_PSDIV);
	}
#endif
}

/* @} */

/* ! \name System enable and disable module */
/* @{ */

/**
 * \brief Enable the clock to peripheral \a id on port \a port
 *
 * \param port ID of the port to which the module is connected (one of
 * the \c power_red_id *definitions).
 * \param id The ID (bitmask) of the peripheral module to be enabled.
 */
void sysclk_enable_module(enum power_red_id port, uint8_t id)
{
#if !MEGA_UNSPECIFIED && !MEGA_XX
	uint8_t *reg = (uint8_t *)&(POWER_REG_ADD);
	irqflags_t flags = cpu_irq_save();

	if (port < NUMBER_OF_POWER_REG) {
		*(reg + port)  &= ~id;
	}
	cpu_irq_restore(flags);
#endif
}

/*
 * \brief Disable the clock to peripheral \a id on port \a port
 *
 * \param port ID of the port to which the module is connected (one of
 * the \c power_red_id *definitions).
 * \param id The ID (bit mask) of the peripheral module to be disabled.
 */
void sysclk_disable_module( enum power_red_id port, uint8_t id)
{
#if !MEGA_UNSPECIFIED && !MEGA_XX
	uint8_t *reg = (uint8_t *)&(POWER_REG_ADD);
	irqflags_t flags = cpu_irq_save();
	if (port < NUMBER_OF_POWER_REG) {
		*(reg + port) |= id;
	}
	cpu_irq_restore(flags);
#endif
}

/* @} */
