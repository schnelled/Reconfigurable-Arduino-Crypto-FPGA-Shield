#include <time.h>
#include <stdint.h>
#include "benchm.h"
#include "benchm_time.h"
#include "bench_stats.h"
#include "aes_tb.h"

#undef DEBUG

/* 
	This is just an example of something that can be run on the 
	Arduino.
	Arduino has its own version of time.h but basically the same.
	Remove the print statements and possibly use a static key.
	Should give you a good idea of how the AES-128 encryption works.
*/
int main()
{

/* Variables */
AES_KEY aes_ks1;
unsigned char test_key[16];
unsigned char test_in[16];
unsigned char test_out[16];
int file_count = 0;

FILE *fp;
fp = fopen("aes.kat", "r");

do{
	aes128_read_file(fp, test_key, test_in, test_out);
	aes128_encrypt_match(&aes_ks1, test_key, test_in, test_out);
	++file_count;
}while(file_count < 100);

fclose(fp);


#ifdef DEBUG
double sec_time[TRIALS];
int encrypt_count[TRIALS];

/* Set the key */
aes128_key_wrap(&aes_ks1);

/* run trials */
aes128_timer_trials(&aes_ks1, sec_time);
aes128_count_trials(&aes_ks1, encrypt_count);

/* generate stats */
aes128_time_stats(sec_time);
aes128_count_stats(encrypt_count);
printf("\n\n");
#endif

return 0;
}
