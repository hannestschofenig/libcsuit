/*
 * Copyright (c) 2020 SECOM CO., LTD. All Rights reserved.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "suit_examples_common.h"

#if !defined(LIBCSUIT_PSA_CRYPTO_C)

size_t read_from_file(const char *file_path, const size_t buf_len, uint8_t *buf) {
    size_t read_len = 0;
    FILE* fp = fopen(file_path, "rb");
    if (fp == NULL) {
        return 0;
    }
    read_len = fread(buf, 1, buf_len, fp);
    fclose(fp);
    return read_len;
}

size_t write_to_file(const char *file_path, const size_t buf_len, const void *buf) {
    size_t write_len = 0;
    FILE* fp = fopen(file_path, "wb");
    if (fp == NULL) {
        return 0;
    }
    write_len = fwrite(buf, 1, buf_len, fp);
    fclose(fp);
    return write_len;
}

void read_prime256v1_key_pair(const uint8_t *key_der, char *private_key, char *public_key) {
    uint8_t raw_private_key[PRIME256V1_PRIVATE_KEY_LENGTH];
    uint8_t raw_public_key[PRIME256V1_PUBLIC_KEY_LENGTH];
    memcpy(raw_private_key,
           &(key_der[PRIME256V1_PRIVATE_KEY_START_INDEX]),
           PRIME256V1_PRIVATE_KEY_LENGTH);
    memcpy(raw_public_key,
           &(key_der[PRIME256V1_PUBLIC_KEY_IN_KEY_PAIR_START_INDEX]),
           PRIME256V1_PUBLIC_KEY_LENGTH);
    size_t i = 0;
    for (size_t j = 0; j < PRIME256V1_PRIVATE_KEY_LENGTH; j++) {
        sprintf(&private_key[i], "%02x", (unsigned char)raw_private_key[j]);
        i += 2;
    }
    i = 0;
    for (size_t j = 0; j < PRIME256V1_PUBLIC_KEY_LENGTH; j++) {
        sprintf(&public_key[i], "%02x", (unsigned char)raw_public_key[j]);
        i += 2;
    }
}

void read_prime256v1_public_key(const uint8_t *public_key_der, char *public_key) {
    uint8_t raw_public_key[PRIME256V1_PUBLIC_KEY_LENGTH];
    memcpy(raw_public_key,
           &(public_key_der[PRIME256V1_PUBLIC_KEY_START_INDEX]),
           PRIME256V1_PUBLIC_KEY_LENGTH);
    size_t i = 0;
    for (size_t j = 0; j < PRIME256V1_PUBLIC_KEY_LENGTH; j++) {
        sprintf(&public_key[i], "%02x", (unsigned char)raw_public_key[j]);
        i += 2;
    }
}
#endif /* LIBCSUIT_PSA_CRYPTO_C */
