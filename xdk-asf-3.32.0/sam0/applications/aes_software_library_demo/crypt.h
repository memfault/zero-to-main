/**
 * \file FIPS SP800-38A software library header file
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
#ifndef CRYPT_H
#define CRYPT_H

#include "aes.h"
#include <compiler.h>

//Counter block structure for AES-CTR mode
typedef struct{
	uint32_t nonce;
	uint64_t i_vector;
	uint32_t counter;
} ctr_blk_t;

/*! \brief This function performs ECB encryption on input plain text blocks.
 * \param plainText  pointer to the array containing the plain text bytes
 * \param cipherText pointer to the array where the encrypted cipher output has to be stored
 * \param size       size of the input plain text
 */ 
void ecb_encrypt(uint8_t *plainText, uint8_t *cipherText, uint32_t size);


/*! \brief This function performs ECB decryption on input cipher text blocks.
 * \param cipherText pointer to the array containing the cipher text bytes
 * \param plainText  pointer to the array where the decrypted plain text has to be stored
 * \param size       size of the input plain text
 */ 
void ecb_decrypt(uint8_t *cipherText, uint8_t *plainText, uint32_t size);


/*! \brief This function performs CBC encryption on input plain text blocks.
 * \param plainText   pointer to the array containing the plain text bytes
 * \param cipherText  pointer to the array where the encrypted cipher output has to be stored
 * \param init_vector pointer to the array containing the unique initialization vector
 * \param size        size of the input plain text
 */ 
void cbc_encrypt (uint8_t *plainText, uint8_t *cipherText, uint8_t *init_vector, uint32_t size);


/*! \brief This function performs CBC decryption on input cipher text blocks.
 * \param cipherText  pointer to the array containing the cipher text bytes
 * \param plainText   pointer to the array where the decrypted plain text has to be stored
 * \param init_vector pointer to the array containing the unique initialization vector
 * \param size        size of the input plain text
 */ 
void cbc_decrypt (uint8_t *cipherText, uint8_t *plainText, uint8_t *init_vector, uint32_t size);


/*! \brief This function performs CFB encryption on input plain text blocks.
 * \param plainText   pointer to the array containing the plain text bytes
 * \param cipherText  pointer to the array where the encrypted cipher output has to be stored
 * \param init_vector pointer to the array containing the unique initialization vector
 * \param mode        CFB mode in bits - can be 8, 16, 32, 64, 128.
 * \param size        size of the input plain text
 */ 
void cfb_encrypt(uint8_t *plainText, uint8_t *cipherText, uint8_t *init_vector, uint8_t mode, uint32_t size);


/*! \brief This function performs CFB decryption on input cipher text blocks.
 * \param cipherText  pointer to the array containing the cipher text bytes
 * \param plainText   pointer to the array where the decrypted plain text has to be stored
 * \param init_vector pointer to the array containing the unique initialization vector
 * \param mode        CFB mode in bits - can be 8, 64, 128.
 * \param size        size of the input plain text
 */ 
void cfb_decrypt(uint8_t *cipherText, uint8_t *plainText, uint8_t *init_vector, uint8_t mode, uint32_t size);


/*! \brief This function performs OFB encryption on input plain text blocks.
 * \param plainText   pointer to the array containing the plain text bytes
 * \param cipherText  pointer to the array where the encrypted cipher output has to be stored
 * \param init_vector pointer to the array containing the unique initialization vector
 * \param size        size of the input plain text
 */ 
void ofb_encrypt(uint8_t *plainText, uint8_t *cipherText, uint8_t *init_vector, uint32_t size);

 
 /*! \brief This function performs OFB decryption on input cipher text blocks.
 * \param cipherText  pointer to the array containing the cipher text bytes
 * \param plainText   pointer to the array where the decrypted plain text has to be stored
 * \param init_vector pointer to the array containing the unique initialization vector
 * \param size        size of the input plain text
 */ 
void ofb_decrypt(uint8_t *cipherText, uint8_t *plainText, uint8_t *init_vector, uint32_t size);


/*! \brief Performs counter increment to prepare input for next round.
 * \param counter   value of counter used in CTR mode
 */
void ctr_inc_counter(ctr_blk_t *counter);


/*! \brief This function performs CTR encryption/decryption on input blocks.
  * Note: Both encryption and decryption is same for CTR mode.
  * In both the cases, the input block to the cipher process is the counter.
  * The resulting output is XOR-ed with plain text for encryption.
  * For decryption case, it is XOR-ed with cipher text to retrieve the actual data.
 * \param plainText   pointer to the array containing the plain text bytes
 * \param cipherText  pointer to the array where the encrypted cipher output has to be stored
 * \param init_vector pointer to the array containing the unique initialization vector
 * \param size        size of the input plain text
 */ 
void ctr_encrypt_decrypt (uint8_t *input_block , uint8_t *output_block, ctr_blk_t *counter, uint32_t size);



#endif
