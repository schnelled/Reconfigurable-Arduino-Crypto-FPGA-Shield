#include <time.h>
#include <stdint.h>
#include "benchm.h"
#include "benchm_time.h"
#include "bench_stats.h"

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
unsigned char iv[VEC_SIZE];
AES_KEY aes_ks1;

double sec_time[TRIALS];
int encrypt_count[TRIALS];

float mean_time, mean_count, std_dev_time, std_dev_count;

/* Set the key */
aes128_key_wrap(&aes_ks1);

for(int i = 0; i < TRIALS; i++)
{

printf("\nTRIAL %d\n", i+1);

/* Timer function */
sec_time[i] = aes128_iter_timer(&aes_ks1);

/* Print out the time */
printf("\n\nSeconds to encrypt %ld size %d blocks: %.8lf\n\n", ITERS, 
	BLOCK_SIZE, sec_time[i]);

/* Counter function */
encrypt_count[i] = aes128_iter_counter(&aes_ks1);

/* Print out the # of encryptions */
printf("\n\nEncrypted %d size %d blocks in %.1Lf seconds.\n\n", 
	encrypt_count[i], BLOCK_SIZE, TIMER); 

}

/* generate stats */
aes128_time_stats(sec_time, &mean_time, &std_dev_time);

printf("\n\n%d Trials Mean Time for %ld Encryptions: %.8lf with Standard "
       "Deviation: %.8lf\n\n", TRIALS, ITERS, mean_time, std_dev_time);

aes128_count_stats(encrypt_count, &mean_count, &std_dev_count);

printf("\n\nMean Encryptions in %.1Lf Seconds: %.3lf with Standard "
       "Deviation: %.8lf\n\n", TIMER, mean_count, std_dev_count);


return 0;
}
