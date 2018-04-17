/* includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aes.h"

/* defines */
#define MAX_BIN_VAL 255
#define TRIALS      50
#define VEC_SIZE    16
#define BLOCK_SIZE  16

#ifdef __cplusplus
extern "C" {
#endif

int aes128_key_wrap(AES_KEY *);
void aes128_cbc_encrypt_wrap(size_t, AES_KEY *, unsigned char *);

#ifdef __cplusplus
}
#endif

