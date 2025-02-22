/*
 * Copyright (c) 2020 SECOM CO., LTD. All Rights reserved.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 */

#ifndef SUIT_EXAMPLES_COMMON_H
#define SUIT_EXAMPLES_COMMON_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "suit_cose.h"

#define SUIT_EXAMPLE_SUCCESS    1
#define SUIT_EXAMPLE_ERROR      0

#define PRIME256V1_PUBLIC_KEY_DER_SIZE      91
#define PRIME256V1_PUBLIC_KEY_CHAR_SIZE     130
#define PRIME256V1_PRIVATE_KEY_DER_SIZE     121
#define PRIME256V1_PRIVATE_KEY_CHAR_SIZE    64

#define PRIME256V1_PRIVATE_KEY_START_INDEX  7
#define PRIME256V1_PRIVATE_KEY_LENGTH       32
#define PRIME256V1_PUBLIC_KEY_IN_KEY_PAIR_START_INDEX  56
#define PRIME256V1_PUBLIC_KEY_START_INDEX   26
#define PRIME256V1_PUBLIC_KEY_LENGTH        65

typedef struct uint8_buf {
    uint8_t     *ptr;
    size_t      len;
} uint8_buf_t;

size_t read_from_file(const char *file_path, const size_t buf_len, uint8_t *buf);
size_t write_to_file(const char *file_path, const size_t buf_len, const void *buf);
void read_prime256v1_key_pair(const uint8_t *key_der, char *private_key, char *public_key);
void read_prime256v1_public_key(const uint8_t *public_key_der, char *public_key);
int32_t suit_create_es256_key_pair(const char *private_key, const char *public_key, struct t_cose_key *cose_key_pair);
#endif  /* SUIT_EXAMPLES_COMMON_H */
