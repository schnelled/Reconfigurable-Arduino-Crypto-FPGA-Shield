#include <string.h>
#include <stdio.h>
#include "benchm.h"

int aes128_test_vectors(AES_KEY *);
int aes128_read_file(FILE *, unsigned char *, unsigned char *, 
		     unsigned char *);
int aes128_encrypt_match(AES_KEY *, unsigned char *, unsigned char *,
			 unsigned char *);
