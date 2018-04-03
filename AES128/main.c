#include "benchm.h"

int main()
{
unsigned char * buf;
buf = (unsigned char *)malloc(sizeof(unsigned char));

AES_KEY aes_ks1;
  static const unsigned char key16[16] = {
        0x12, 0x34, 0x56, 0x78, 0x9a, 0xbc, 0xde, 0xf0,
        0x34, 0x56, 0x78, 0x9a, 0xbc, 0xde, 0xf0, 0x12, 
    };
AES_set_encrypt_key(key16, 128, &aes_ks1);
int count = AES_benchmark(buf,3);
printf("Total iterations in 3 seconds: %d\n", count);
return 0;
}
