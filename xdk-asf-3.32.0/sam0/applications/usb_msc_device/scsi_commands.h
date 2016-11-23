/**
 * \file
 *
 * \brief SAM USB SCSI commands
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


#ifndef SCSI_COMMANDS_H_
#define SCSI_COMMANDS_H_


/****************************************************************************/
/* Command for all SCSI device types                                        */
/****************************************************************************/

// Mandatory Command set list from SBC-2
// (subclass 6, peripheral device type 0, version 5)
// FORMAT UNIT
// INQUIRY
// READ (6)
// READ (10)
// READ (16)
// READ CAPACITY (10)
// READ CAPACITY (16)
// REQUEST SENSE
// SEND DIAGNOSTIC
// TEST UNIT READY

#define SBC_CMD_TEST_UNIT_READY                   (0x00)
#define SBC_CMD_REQUEST_SENSE                     (0x03)
#define SBC_CMD_FORMAT_UNIT                       (0x04)
#define SBC_CMD_READ_6                            (0x08)
#define SBC_CMD_INQUIRY                           (0x12)
#define SBC_CMD_MODE_SELECT_6                     (0x15)
#define SBC_CMD_READ_FORMAT_CAPACITY              (0x23)
#define SBC_CMD_MODE_SENSE_6                      (0x1A)
#define SBC_CMD_START_STOP_UNIT                   (0x1B)
#define SBC_CMD_RECEIVE_DIAGNOSTICS               (0x1C)
#define SBC_CMD_SEND_DIAGNOSTIC                   (0x1D)
#define SBC_CMD_PREVENT_ALLOW_MEDIUM_REMOVAL      (0x1E)
#define SBC_CMD_READ_LONG                         (0x23)
#define SBC_CMD_READ_CAPACITY_10                  (0x25)
#define SBC_CMD_READ_CD_ROM_CAPACITY              (0x25)
#define SBC_CMD_READ_10                           (0x28)
#define SBC_CMD_WRITE_10                          (0x2A)
#define SBC_CMD_READ_12							  (0xA8)	
#define SBC_CMD_WRITE_12						  (0xAA)
#define SBC_VERIFY10							   0x2F

#define SBC_CMD_SEEK                              (0x2B)
#define SBC_CMD_WRITE_VERIFY_10                   (0x2E)
#define SBC_CMD_VERIFY_10                         (0x2F)
#define SBC_CMD_SYNCHRONIZE_CACHE                 (0x35)
#define SBC_CMD_WRITE_BUFFER                      (0x3B)
#define SBC_CMD_CHANGE_DEFINITION                 (0x40)
#define SBC_CMD_READ_TOC                          (0x43)
#define SBC_CMD_MODE_SELECT_10                    (0x55)
#define SBC_CMD_RESERVE_10                        (0x56)
#define SBC_CMD_RELEASE_10                        (0x57)
#define SBC_CMD_MODE_SENSE_10                     (0x5A)

#define SBC_CONTROL_BYTE                          (0x00)
#define SBC_CMD_DIR_IN                            (0x80)
#define SBC_CMD_DIR_OUT                           (0x00)



#endif /* SCSI_COMMANDS_H_ */
