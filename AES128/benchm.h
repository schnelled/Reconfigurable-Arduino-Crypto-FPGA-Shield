/*includes*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "aes.h"

#ifdef __cplusplus
extern "C" {
#endif

/*function_decs*/
int AES_benchmark(unsigned char*, int);
static int AES_encrypt_block();
static int AES_encrypt_cbc(unsigned char*, int);
static int AES_decrypt_cbc(unsigned char*, int);

#ifdef __cplusplus
}
#endif

