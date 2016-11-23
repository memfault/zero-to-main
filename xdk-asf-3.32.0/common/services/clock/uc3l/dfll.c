/**
 * \file
 *
 * \brief Chip-specific DFLL implementation
 *
 * Copyright (c) 2010-2015 Atmel Corporation. All rights reserved.
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
#include <dfll.h>

#if (UC3L3_L4 || UC3L0128 || UC3L0256)
#define dfll_write_reg(reg, value)                                             \
	do {                                                                   \
		while (!(AVR32_SCIF.pclksr & AVR32_SCIF_PCLKSR_DFLL0RDY_MASK)); \
		irqflags_t ATPASTE2(dfll_flags, __LINE__) = cpu_irq_save();     \
		AVR32_SCIF.unlock = \
				(AVR32_SCIF_UNLOCK_KEY_VALUE << AVR32_SCIF_UNLOCK_KEY_OFFSET) |\
				AVR32_SCIF_##reg; \
		*(volatile uint32_t *)(AVR32_SCIF_ADDRESS + AVR32_SCIF_##reg)   \
				= (value);                                     \
		cpu_irq_restore(ATPASTE2(dfll_flags, __LINE__));                \
	} while (0)

#else
#define dfll_write_reg(reg, value)                                             \
	do {                                                                   \
		while (!(AVR32_SCIF.pclksr & AVR32_SCIF_DFLL0RDY_MASK));        \
		irqflags_t ATPASTE2(dfll_flags, __LINE__) = cpu_irq_save();     \
		AVR32_SCIF.unlock = \
				(AVR32_SCIF_UNLOCK_KEY_VALUE << AVR32_SCIF_UNLOCK_KEY_OFFSET) |\
				AVR32_SCIF_##reg; \
		*(volatile uint32_t *)(AVR32_SCIF_ADDRESS + AVR32_SCIF_##reg)   \
				= (value);                                     \
		cpu_irq_restore(ATPASTE2(dfll_flags, __LINE__));                \
	} while (0)
#endif

void dfll_enable_open_loop(const struct dfll_config *cfg,
		unsigned int dfll_id)
{
	irqflags_t flags;

	/* First, enable the DFLL, then configure it */
	flags = cpu_irq_save();
	AVR32_SCIF.unlock =
			( AVR32_SCIF_UNLOCK_KEY_VALUE << AVR32_SCIF_UNLOCK_KEY_OFFSET) |
			AVR32_SCIF_DFLL0CONF;
	AVR32_SCIF.dfll0conf = 1U << AVR32_SCIF_DFLL0CONF_EN;
	cpu_irq_restore(flags);
	dfll_write_reg(DFLL0CONF, cfg->conf | (1U << AVR32_SCIF_DFLL0CONF_EN)
#if (UC3L0128 || UC3L0256 || UC3L3_L4)
		| (1U << AVR32_SCIF_DFLL0CONF_CCEN)
#endif
		);
	dfll_write_reg(DFLL0SSG, cfg->ssg);
}

void dfll_disable_open_loop(unsigned int dfll_id)
{
	/*
	 * First, reduce the frequency to the lowest setting, then
	 * disable the DFLL.
	 */
	dfll_write_reg(DFLL0CONF, 1U << AVR32_SCIF_DFLL0CONF_EN);
	dfll_write_reg(DFLL0CONF, 0);
}

void dfll_enable_closed_loop(const struct dfll_config *cfg,
		unsigned int dfll_id)
{
	irqflags_t flags;
	/* Enable the reference clock */
	genclk_enable(&cfg->ref_cfg, 0);

	/*
	 * Enable the DFLL first, but don't wait for the DFLL0RDY bit
	 * because if the DFLL has been disabled before, the DFLL0RDY
	 * bit stays cleared until it is re-enabled.
	 */
	flags = cpu_irq_save();
	AVR32_SCIF.unlock =
			( AVR32_SCIF_UNLOCK_KEY_VALUE << AVR32_SCIF_UNLOCK_KEY_OFFSET ) |
			AVR32_SCIF_DFLL0CONF;
	AVR32_SCIF.dfll0conf = 1U << AVR32_SCIF_DFLL0CONF_EN;
	cpu_irq_restore(flags);

	/*
	 * Then, configure the DFLL, taking care to wait for the
	 * DFLL0RDY bit before every step.
	 */
	dfll_write_reg(DFLL0STEP, cfg->step);
#if AVR32_SCIF_H_VERSION < 110
	dfll_write_reg(DFLL0FMUL, cfg->mul);
#else
	dfll_write_reg(DFLL0MUL, cfg->mul);
#endif
	dfll_write_reg(DFLL0SSG, cfg->ssg);
	dfll_write_reg(DFLL0CONF, cfg->conf | (1U << AVR32_SCIF_DFLL0CONF_EN)
#if (UC3L0128 || UC3L0256 || UC3L3_L4)
		| (1U << AVR32_SCIF_DFLL0CONF_CCEN)
#endif
		);
}

void dfll_disable_closed_loop(unsigned int dfll_id)
{
	/*
	 * First, reduce the frequency to the lowest setting, then
	 * disable the DFLL.
	 */
	dfll_write_reg(DFLL0CONF, 1U << AVR32_SCIF_DFLL0CONF_EN);
	dfll_write_reg(DFLL0CONF, 0);

	/* Finally, stop the reference clock */
	genclk_disable(0);
}

void dfll_enable_config_defaults(unsigned int dfll_id)
{
	struct dfll_config dfllcfg;

	if (dfll_is_fine_locked(dfll_id)) {
		return; // DFLL already running
	}

	switch (dfll_id) {
#ifdef CONFIG_DFLL0_SOURCE
	case 0:
		dfll_enable_source(CONFIG_DFLL0_SOURCE);
		dfll_config_init_closed_loop_mode(&dfllcfg,
			CONFIG_DFLL0_SOURCE,
			CONFIG_DFLL0_DIV,
			CONFIG_DFLL0_MUL);
		break;
#endif

	default:
		Assert(false);
		break;
	}

	dfll_enable_closed_loop(&dfllcfg, dfll_id);
	while (!dfll_is_fine_locked(dfll_id));
}


