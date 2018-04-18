#include <time.h>
#include <stdint.h>
#include "benchm.h"
#include "benchm_time.h"
#include "bench_stats.h"
#include "aes_tb.h"

#define DEBUG
#define TIME_TRIAL
#undef  COUNT_TRIAL
#undef  FILE_READ
/* 
	This main.c is just a testing playground for AES128 Encryption.

	Many of these files may not work on all systems, i.e. Arduino.
	The functionality should generally be the same and hopefully
	will need only slight modifications to run on other platforms.
*/
int main()
{

/* Variables */
AES_KEY aes_ks1;

#ifdef FILE_READ
if(!aes128_test_vectors(&aes_ks1))
	printf("\nError with file reading.\n");
else
	printf("\nAll test vectors match!\n");
#endif

#ifdef DEBUG
double sec_time[TRIALS];
int encrypt_count[TRIALS];

/* Set the key */
aes128_key_wrap(&aes_ks1);

	/* run trials */
	#ifdef TIME_TRIAL
	aes128_timer_trials(&aes_ks1, sec_time);
	aes128_time_stats(sec_time);
	#endif

	#ifdef COUNT_TRIAL
	aes128_count_trials(&aes_ks1, encrypt_count);
	aes128_count_stats(encrypt_count);
	#endif

printf("\n\n");
#endif

return 0;
}
