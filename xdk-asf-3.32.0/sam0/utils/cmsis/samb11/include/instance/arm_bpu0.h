/**
 * \file
 *
 * \brief Instance description for ARM_BPU0
 *
 * Copyright (c) 2015-2016 Atmel Corporation. All rights reserved.
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

#ifndef _SAMB11_ARM_BPU0_INSTANCE_
#define _SAMB11_ARM_BPU0_INSTANCE_

/* ========== Register definition for ARM_BPU0 peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_ARM_BPU0_BP_CTRL    (0xE0002000U) /**< (ARM_BPU0) Break Point Control Register */
#define REG_ARM_BPU0_BP_COMP0   (0xE0002008U) /**< (ARM_BPU0) Break Point Compare Register 0 */
#define REG_ARM_BPU0_BP_COMP1   (0xE000200CU) /**< (ARM_BPU0) Break Point Compare Register 1 */
#define REG_ARM_BPU0_BP_COMP2   (0xE0002010U) /**< (ARM_BPU0) Break Point Compare Register 2 */
#define REG_ARM_BPU0_BP_COMP3   (0xE0002014U) /**< (ARM_BPU0) Break Point Compare Register 3 */
#define REG_ARM_BPU0_BP_PID4    (0xE0002FD0U) /**< (ARM_BPU0) Peripheral ID Register 4 */
#define REG_ARM_BPU0_BP_PID0    (0xE0002FE0U) /**< (ARM_BPU0) Peripheral ID Register 0 */
#define REG_ARM_BPU0_BP_PID1    (0xE0002FE4U) /**< (ARM_BPU0) Peripheral ID Register 1 */
#define REG_ARM_BPU0_BP_PID2    (0xE0002FE8U) /**< (ARM_BPU0) Peripheral ID Register 2 */
#define REG_ARM_BPU0_BP_PID3    (0xE0002FECU) /**< (ARM_BPU0) Peripheral ID Register 3 */
#define REG_ARM_BPU0_BP_CID0    (0xE0002FF0U) /**< (ARM_BPU0) Component ID Register 0 */
#define REG_ARM_BPU0_BP_CID1    (0xE0002FF4U) /**< (ARM_BPU0) Component ID Register 1 */
#define REG_ARM_BPU0_BP_CID2    (0xE0002FF8U) /**< (ARM_BPU0) Component ID Register 2 */
#define REG_ARM_BPU0_BP_CID3    (0xE0002FFCU) /**< (ARM_BPU0) Component ID Register 3 */

#else

#define REG_ARM_BPU0_BP_CTRL    (*(__IO uint8_t*)0xE0002000U) /**< (ARM_BPU0) Break Point Control Register */
#define REG_ARM_BPU0_BP_COMP0   (*(__IO uint32_t*)0xE0002008U) /**< (ARM_BPU0) Break Point Compare Register 0 */
#define REG_ARM_BPU0_BP_COMP1   (*(__IO uint32_t*)0xE000200CU) /**< (ARM_BPU0) Break Point Compare Register 1 */
#define REG_ARM_BPU0_BP_COMP2   (*(__IO uint32_t*)0xE0002010U) /**< (ARM_BPU0) Break Point Compare Register 2 */
#define REG_ARM_BPU0_BP_COMP3   (*(__IO uint32_t*)0xE0002014U) /**< (ARM_BPU0) Break Point Compare Register 3 */
#define REG_ARM_BPU0_BP_PID4    (*(__I  uint8_t*)0xE0002FD0U) /**< (ARM_BPU0) Peripheral ID Register 4 */
#define REG_ARM_BPU0_BP_PID0    (*(__I  uint8_t*)0xE0002FE0U) /**< (ARM_BPU0) Peripheral ID Register 0 */
#define REG_ARM_BPU0_BP_PID1    (*(__I  uint8_t*)0xE0002FE4U) /**< (ARM_BPU0) Peripheral ID Register 1 */
#define REG_ARM_BPU0_BP_PID2    (*(__I  uint8_t*)0xE0002FE8U) /**< (ARM_BPU0) Peripheral ID Register 2 */
#define REG_ARM_BPU0_BP_PID3    (*(__I  uint8_t*)0xE0002FECU) /**< (ARM_BPU0) Peripheral ID Register 3 */
#define REG_ARM_BPU0_BP_CID0    (*(__I  uint8_t*)0xE0002FF0U) /**< (ARM_BPU0) Component ID Register 0 */
#define REG_ARM_BPU0_BP_CID1    (*(__I  uint8_t*)0xE0002FF4U) /**< (ARM_BPU0) Component ID Register 1 */
#define REG_ARM_BPU0_BP_CID2    (*(__I  uint8_t*)0xE0002FF8U) /**< (ARM_BPU0) Component ID Register 2 */
#define REG_ARM_BPU0_BP_CID3    (*(__I  uint8_t*)0xE0002FFCU) /**< (ARM_BPU0) Component ID Register 3 */

#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif /* _SAMB11_ARM_BPU0_INSTANCE_ */
