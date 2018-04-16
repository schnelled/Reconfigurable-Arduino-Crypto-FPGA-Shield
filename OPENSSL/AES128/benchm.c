#include "benchm.h"

/*
	AES128 Encryption Wrapper
	*************************
	runs aes128 encryption for
	a specific block size
*/
void aes128_cbc_encrypt_wrap(size_t size, AES_KEY *aes_ks1,
			     unsigned char *iv)
{

unsigned char buf[BLOCK_SIZE];

/* From aes_cbc.c */
AES_cbc_encrypt(buf, buf, size, aes_ks1, iv, AES_ENCRYPT);
	
}

/*
	Key Encryption Wrapper
	**********************
	sets the encryption key
*/
int aes128_key_wrap(AES_KEY *aes_ks1)
{

int ret = 0;

/* Same key that OpenSSL uses for aes-128 */
static const unsigned char key16[VEC_SIZE] = {
    0x12, 0x34, 0x56, 0x78, 0x9a, 0xbc, 0xde, 0xf0,
    0x34, 0x56, 0x78, 0x9a, 0xbc, 0xde, 0xf0, 0x12, 
};

/* Set the key, from aes_core.c */
ret = AES_set_encrypt_key(key16, 128, aes_ks1);

if(ret == 0)
	return ret;
else
	return -1;

}

	

