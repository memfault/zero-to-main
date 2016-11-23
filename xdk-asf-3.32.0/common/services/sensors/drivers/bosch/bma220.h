/**
 * \file
 *
 * \brief Bosch BMA220 3-axis accelerometer driver.
 *
 * This file contains functions for initializing and reading data
 * from a Bosch BMA220 3-axis accelerometer.
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
#ifndef _BMA220_H_
#define _BMA220_H_

#include <asf.h>

#ifdef __cplusplus
extern "C" {
#endif

/* TWI/I2C address (write @ 0x16 on bus, read @ 0x17 on bus) */

#define BMA220_TWI_ADDR             (0x0b)
#define BMA220_SPI_MODE             (4)

/* Sensor Data Resolution and Offsets */

#define BMA220_DATA_RESOLUTION      (6)
#define BMA220_ZERO_G_OFFSET        (95)    /* +/- 95 mg @ 2g FS resolution */

/**
 * @brief Standard Register Addresses
 *
 * The TWI/I2C register address for a particular register is derived by
 * shifting the SPI register address to the left by one bit. In other words,
 * from I2C->SPI the burst address increment is 0x2 steps.
 */
typedef enum {                      /* SPI register address space & functions */
	BMA220_CHIP_ID = 0,         /* 0x00 chip ID - always 0xdd */
	BMA220_CHIP_VERSION,        /* 0x01 chip revision */
	BMA220_X_AXIS_DATA,         /* 0x02 X-axis acceleration data */
	BMA220_Y_AXIS_DATA,         /* 0x03 Y-axis acceleration data */
	BMA220_Z_AXIS_DATA,         /* 0x04 Z-axis acceleration data */
	BMA220_HG_CONFIG,           /* 0x05 high-g event configuration */
	BMA220_HG_LG_THRESHOLD,     /* 0x06 high-g & low-g thresholds */
	BMA220_LG_CONFIG,           /* 0x07 low-g event configuration */
	BMA220_TAP_CONFIG,          /* 0x08 tap/double-tap configuration */
	BMA220_SLOPE_CONFIG,        /* 0x09 slope detection configuration */
	BMA220_DIRECTION_CONFIG,    /* 0x0a orientation event configuration */
	BMA220_DIRECTION_STATUS,    /* 0x0b orientation event status */
	BMA220_INT_STATUS,          /* 0x0c interrupt status bits */
	BMA220_INT_ENABLE1,         /* 0x0d interrupt / event enable bits */
	BMA220_INT_ENABLE2,         /* 0x0e interrupt / event enable bits */
	BMA220_SLEEP_CONFIG,        /* 0x0f low-power configuration */
	BMA220_BANDWIDTH_CONFIG,    /* 0x10 bandwidth filter configuration */
	BMA220_RANGE_SELFTEST,      /* 0x11 range setting & built-in self-test */
	BMA220_12_RSVD,             /* 0x12 reserved */
	BMA220_13_RSVD,             /* 0x13 reserved */
	BMA220_14_RSVD,             /* 0x14 reserved */
	BMA220_15_RSVD,             /* 0x15 reserved */
	BMA220_16_RSVD,             /* 0x16 reserved */
	BMA220_SPI_MODE_SELECT,     /* 0x17 SPI & watch-dog timer configuration */
	BMA220_SUSPEND_MODE,        /* 0x18 suspend mode status */
	BMA220_SOFTRESET            /* 0x19 software reset status */
} bma220_register_t;

/* Register Field Access Macros */

#define get_field(reg, mask, offset)    (((reg) & (mask)) >> (offset))
#define set_field(reg, mask, value)     ((reg) & ~(mask)) | ((value) & (mask))

/** \brief BMA220 Register Bit Definitions */
/** @{ */

/* BMA220_CHIP_ID (0x00) */

#define BMA220_ID_VAL               (0xdd)  /* BMA220 chip ID (always ddh) */

/* BMA220_HG_CONFIG (0x05) */

#define HIGH_DUR_FIELD              (0x3f)  /* high-g duration mask */
#define HIGH_HY_FIELD               (0xc0)  /* high-g hysteresis mask */

/* BMA220_HG_LG_THRESHOLD (0x06) */

#define HIGH_TH_FIELD               (0x0f)  /* high-g threshold mask */
#define LOW_TH_FIELD                (0xf0)  /* low-g threshold mask */

/* BMA220_LG_CONFIG (0x07) */

#define LOW_DUR_FIELD               (0x3f)  /* low-g duration mask */
#define LOW_HY_FIELD                (0xc0)  /* low-g hysteresis mask */

/* BMA220_TAP_SENSING_CONFIG (0x08) */

#define TT_DUR_FIELD                (0x07)  /* tap duration mask */
#define TT_DUR_50MS                 (0)
#define TT_DUR_105MS                (1)
#define TT_DUR_150MS                (2)
#define TT_DUR_219MS                (3
#define TT_DUR_250MS                (4)
#define TT_DUR_375MS                (5)
#define TT_DUR_500MS                (6)
#define TT_DUR_700MS                (7)

#define TT_TH_FIELD                 (0x78)  /* tap threshold mask */
#define TT_FILT_FIELD               (0x80)  /* tap filter mask */

/* BMA220_SLOPE_DET_CONFIG (0x09) */

#define SLOPE_DUR_FIELD             (0x03)
#define SLOPE_DUR_1                 (0)
#define SLOPE_DUR_2                 (1)
#define SLOPE_DUR_3                 (2)
#define SLOPE_DUR_4                 (3)

#define SLOPE_TH_FIELD              (0x3c)
#define SLOPE_FILT_FIELD            (0x40)
#define ORIENT_EX_FIELD             (0x80)

/* BMA220_DIRECTION_CONFIG (0x0a) */

#define TT_SAMP_FIELD               (0x03)
#define ORIENT_BLOCKING_FIELD       (0x0c)
#define TIP_EN_FIELD                (0x10)

/* BMA220_DIRECTION_STATUS (0x0b) */

#define INT_SIGN_FIELD              (0x01)
#define INT_FIRST_Z_FIELD           (0x02)
#define INT_FIRST_Y_FIELD           (0x04)
#define INT_FIRST_X_FIELD           (0x08)
#define ORIENT_FIELD                (0x70)
#define ORIENT_INT_FIELD            (0x80)

/* BMA220_INT_STATUS (0x0c) */

#define SLOPE_INT_FIELD             (0x01)
#define DATA_INT_FIELD              (0x02)
#define HIGH_INT_FIELD              (0x04)
#define LOW_INT_FIELD               (0x08)
#define TT_INT_FIELD                (0x10)

/* BMA220_INT_ENABLE1 (0x0d) */

#define EN_TT_Z_FIELD               (0x01)
#define EN_TT_Y_FIELD               (0x02)
#define EN_TT_X_FIELD               (0x04)
#define EN_SLOPE_Z_FIELD            (0x08)
#define EN_SLOPE_Y_FIELD            (0x10)
#define EN_SLOPE_X_FIELD            (0x20)
#define EN_ORIENT_FIELD             (0x40)
#define EN_DATA_FIELD               (0x80)

/* BMA220_INT_ENABLE2 (0x0e) */

#define EN_HIGH_Z_FIELD             (0x01)
#define EN_HIGH_Y_FIELD             (0x02)
#define EN_HIGH_X_FIELD             (0x04)
#define EN_LOW_FIELD                (0x08)

#define LATCH_INT_FIELD             (0x70)
#define LATCH_INT_OFF               (0)     /* unlatched */
#define LATCH_INT_250MS             (1)     /* 0.25s latch time */
#define LATCH_INT_500MS             (2)     /* 0.5s latch time */
#define LATCH_INT_1000MS            (3)     /* 1s latch time */
#define LATCH_INT_2000MS            (4)     /* 2s latch time */
#define LATCH_INT_4000MS            (5)     /* 4s latch time */
#define LATCH_INT_8000MS            (6)     /* 8s latch time */
#define LATCH_INT_ON                (7)     /* permanent latch */

#define RESET_INT                   (0x80)  /* w/o software reset bit */

/* BMA220_SLEEP_CONFIG (0x0f) */

#define EN_Z_CHANNEL_FIELD          (0x01)
#define EN_Y_CHANNEL_FIELD          (0x02)
#define EN_X_CHANNEL_FIELD          (0x04)

#define SLEEP_DUR_FIELD             (0x38)
#define SLEEP_DUR_2MS               (0)
#define SLEEP_DUR_10MS              (1)
#define SLEEP_DUR_25MS              (2)
#define SLEEP_DUR_50MS              (3)
#define SLEEP_DUR_100MS             (4)
#define SLEEP_DUR_500MS             (5)
#define SLEEP_DUR_1000MS            (6)
#define SLEEP_DUR_2000MS            (7)

#define SLEEP_ENABLE                (0x40)

/* BMA220_BANDWIDTH_CONFIG (0x10) */

#define FILTER_CONFIG_FIELD         (0x0f)
#define BANDWIDTH_1000HZ            (0)
#define BANDWIDTH_500HZ             (1)
#define BANDWIDTH_250HZ             (2)
#define BANDWIDTH_125HZ             (3)
#define BANDWIDTH_64HZ              (4)
#define BANDWIDTH_32HZ              (5)

#define SERIAL_HIGH_BW_FIELD        (0x80)

/* BMA220_RANGE_SELFTEST (0x11) */

#define RANGE_FIELD                 (0x03)
#define RANGE_2G                    (0)
#define RANGE_4G                    (1)
#define RANGE_8G                    (2)
#define RANGE_16G                   (3)

#define SBIST_FIELD                 (0x0c)
#define SBIST_OFF                   (0)
#define SBIST_X_AXIS                (1)
#define SBIST_Y_AXIS                (2)
#define SBIST_Z_AXIS                (3)

#define SBIST_SIGN_FIELD            (0x70)
#define SBIST_SIGN_POSITIVE         (0)
#define SBIST_SIGN_NEGATIVE         (1)

/* BMA220_SPI_MODE_SELECT (0x17) */

#define SPI3_FIELD                  (0x01)  /* SPI3 ENABLE */
#define WDT_TO_SEL_FIELD            (0x02)  /* WATCHDOG TIMEOUT SELECT */
#define WDT_TO_EN_FIELD             (0x04)  /* WATCHDOG TIMEOUT ENABLE */

/** @} */

/**
 * convert real G values into register values
 *  \note no range checking is included
 *  \see HIGH_TH, LOW_TH, SLOPE_TH, TT_TH
 */
#define THRESHOLD_IN_G(threshold, grange)   (((threshold) * 16) / (grange))

/**
 * convert real G values into hysteresis register values
 *  \note no range checking is included
 *  \see HIGH_HYS, LOW_HYS, SLOPE_HYS, TT_HYS
 */
#define HYSTERESIS_IN_G(hysteresis, grange) (((threshold) * 4) / (grange))

extern bool bma220_init(sensor_t *, int);

#ifdef __cplusplus
}
#endif

#endif
