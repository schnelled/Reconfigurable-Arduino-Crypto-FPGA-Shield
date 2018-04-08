#include <time.h>
#include "benchm.h"

/* 
	This is just an example of something that can be run on the Arduino.
	Arduino has its own version of time.h but basically the same.
	Remove the print statements and possibly use a static key.
	Should give you a good idea of how the AES-128 encryption works.
*/
int main()
{

int count = 0;

clock_t start, stop;

unsigned char buf[VEC_SIZE];
unsigned char key[VEC_SIZE];
unsigned char  iv[VEC_SIZE];

AES_KEY aes_ks1;

/* Same key that OpenSSL uses for aes-128 */
static const unsigned char key16[VEC_SIZE] = {
    0x12, 0x34, 0x56, 0x78, 0x9a, 0xbc, 0xde, 0xf0,
    0x34, 0x56, 0x78, 0x9a, 0xbc, 0xde, 0xf0, 0x12, 
};

/* Using non-random key */
AES_set_encrypt_key(key16, 128, &aes_ks1);

srand(time(0));

int count_vector[TRIALS];
int count_tot = 0;
int count_avg = 0;

/* Do x trials just for fun, change value in benchm.h */
for(int k = 0; k < TRIALS; k++){

count_vector[k] = 0;

printf("\n\nTrial %d\n\n", k+1);

/* Generate a random buffer to start with */
/*
printf("\nStarting Input Vector: ");
for(int i = 0; i < VEC_SIZE; i++){
	buf[i] = rand() % MAX_BIN_VAL;
	printf("%x", buf[i]);
}
printf("\n\n");
*/

/* Also can use a random key */
/*
printf("\nStarting Key Vector: ");
for(int i = 0; i < VEC_SIZE; i++){
	key[i] = rand() % MAX_BIN_VAL;
	printf("%x", key[i]);
}
*/

/* OpenSSL function with random key, aes.c */
/*
AES_set_encrypt_key(key, 128, &aes_ks1);
*/

printf("\n\nRunning....\n\n");

/* Check how many encryptions get evaluated in some time frame */
start = time(NULL);

do {
	/* aes_core.c */
	AES_cbc_encrypt(buf, buf, (size_t)16, &aes_ks1, iv, AES_ENCRYPT);
	stop = time(NULL) - start;
	++count_vector[k];
}while(stop < 3);

count_tot += count_vector[k];

printf("\n\nTotal blocks encrypted in 3 seconds: %d\n\n", count_vector[k]);

}
count_avg = count_tot / TRIALS;
printf("\n\nAverage blocks encrypted per %d trials: %d\n\n", TRIALS, count_avg);

return 0;
}
