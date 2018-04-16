#include "aes_tb.h"

int aes128_read_file(FILE *fp, unsigned char *key, unsigned char *in, 
		     unsigned char * out)
{

char buf[100];
char temp[2];
unsigned int hold;

fgets(buf, 100, (FILE*)fp);

for(int i = 0; i < 32; i += 2){

temp[0] = buf[i + 2];
temp[1] = buf[i + 3];
temp[2] = '\0';
sscanf(temp, "%x", &hold);
key[i / 2] = (unsigned char)hold;

}

fgets(buf, 100, (FILE*)fp);

for(int i = 0; i < 32; i += 2){

temp[0] = buf[i + 2];
temp[1] = buf[i + 3];
temp[2] = '\0';
sscanf(temp, "%x", &hold);
in[i / 2] = (unsigned char)hold;

}

fgets(buf, 100, (FILE*)fp);

for(int i = 0; i < 32; i += 2){

temp[0] = buf[i + 2];
temp[1] = buf[i + 3];
temp[2] = '\0';
sscanf(temp, "%x", &hold);
out[i / 2] = (unsigned char)hold;

}

return 0;

}

int aes128_encrypt_match(AES_KEY *aes_ks1, unsigned char *key, 
			 unsigned char *in, unsigned char *out)
{

unsigned char enc_out[16];

AES_set_encrypt_key(key, 128, aes_ks1);

AES_encrypt(in, enc_out, aes_ks1);

if(*enc_out != *out)
	printf("\nNo Match!\n");

return 0;
}
