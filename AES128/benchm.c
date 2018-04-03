/*includes*/
#include "benchm.h"

/*g_variables*/
static AES_KEY aes_ks1;
static unsigned char iv[32];
static const unsigned char key16[16] = {
        0x12, 0x34, 0x56, 0x78, 0x9a, 0xbc, 0xde, 0xf0,
        0x34, 0x56, 0x78, 0x9a, 0xbc, 0xde, 0xf0, 0x12, 
    };

/*functions*/
int AES_benchmark(unsigned char *buf, int timer)
{
	int count = 0;
	AES_set_encrypt_key(key16, 128, &aes_ks1);
	clock_t start;
	clock_t stop;

	start = time(NULL);
	do {
		AES_encrypt(buf,buf,&aes_ks1);
		++count;
	stop = time(NULL) - start;
	
	}while(stop < timer);
	printf("Time: %li\n", stop);
	return count;
}

static int AES_encrypt_cbc(unsigned char *buf, int size)
{
/*
	AES_cbc_encrypt(buf,buf,(size_t)size,&aes_ks1,iv,AES_ENCRYPT);

	return 0;
*/
}

static int AES_decrypt_cbc(unsigned char *buf, int size)
{
/*
	AES_cbc_encrypt(buf,buf,(size_t)size,&aes_ks1,iv,AES_DECRYPT);

	return 0;
*/
}

static int AES_encrypt_block()
{
/*
	unsigned char * buf;
	buf = (unsigned char*)malloc(sizeof(unsigned char));
	for(int i = 0; i < 16; i++)
	{
		AES_encrypt(buf,buf,&aes_ks1);	
		
		printf("%x ", *buf);
	}
	free(buf);

	return 0;
*/
}

