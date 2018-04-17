#include "aes_tb.h"

#define FILE_NAME "aes.kat"

/*
	Reads in a File of Vectors
	Compares input, key, and 
	known good encrypted output
	with output from AES_Encrypt
*/
int aes128_test_vectors(AES_KEY *aes_ks1)
{

unsigned char test_key[16];
unsigned char test_input[16];
unsigned char known_good_out[16];
int ret = 0;

FILE *fp;

/* read file and test vectors */
fp = fopen(FILE_NAME, "r");

if(!fp)
	return -1;

do{

if(ret == 0)
	ret = aes128_read_file(fp, test_key, test_input, known_good_out);
if(ret == 0)
	ret = aes128_encrypt_match(aes_ks1, test_key, test_input, 
				   known_good_out);

}while(ret == 0);

fclose(fp);

return ret;

}

/*
	Read in sample file of AES128
	Test Vectors - 100 Vectors of
	Format - 
		key
		data in
		encrypted data out
	The data out is a known good
	value.
*/
int aes128_read_file(FILE *fp, unsigned char *key, unsigned char *in, 
		     unsigned char * out)
{

if(!fp)
	return -1;

char buf[100];
char temp[2];
unsigned int hold;

/* get key and store as uchar buffer */
fgets(buf, 100, (FILE*)fp);

for(int i = 0; i < 32; i += 2){

temp[0] = buf[i + 2];
temp[1] = buf[i + 3];
temp[2] = '\0';
if(sscanf(temp, "%x", &hold) == EOF)
	return -1;
key[i / 2] = (unsigned char)hold;

}

/* get input data and store as uchar buffer */
fgets(buf, 100, (FILE*)fp);

for(int i = 0; i < 32; i += 2){

temp[0] = buf[i + 2];
temp[1] = buf[i + 3];
temp[2] = '\0';
if(sscanf(temp, "%x", &hold) == EOF)
	return -1;
in[i / 2] = (unsigned char)hold;

}

/* get known good output and store as uchar buffer */
fgets(buf, 100, (FILE*)fp);

for(int i = 0; i < 32; i += 2){

temp[0] = buf[i + 2];
temp[1] = buf[i + 3];
temp[2] = '\0';
if(sscanf(temp, "%x", &hold) == EOF)
	return -1;
out[i / 2] = (unsigned char)hold;

}

return 0;

}

/*
	Checks if the *known good* Encrypted
	Output Matches the Output from 
	OpenSSLs AES_encryption
*/
int aes128_encrypt_match(AES_KEY *aes_ks1, unsigned char *key, 
			 unsigned char *in, unsigned char *out)
{

unsigned char enc_out[16];

AES_set_encrypt_key(key, 128, aes_ks1);

AES_encrypt(in, enc_out, aes_ks1);

if(*enc_out != *out){
	printf("\nNo Match!\n");
	return -1;
}

return 0;
}
