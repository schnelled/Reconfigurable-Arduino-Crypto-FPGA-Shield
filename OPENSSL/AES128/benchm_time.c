#include "benchm_time.h"

/*
	Iteration Counter
	*****************
	returns the amount
	of iterations in 
	x amount of time
*/
int aes128_iter_counter(AES_KEY *aes_ks1)
{

/* variables */
struct timespec start, end;
unsigned long nsec_time = 0;
unsigned char iv[VEC_SIZE];
int iters = 0;

/* encryption counter */
clock_gettime(CLOCK_REALTIME, &start);
do{
	aes128_bench_timer(ITERS, (size_t)BLOCK_SIZE, aes_ks1, iv, 
			   BENCH_COUNT);
	clock_gettime(CLOCK_REALTIME, &end);
	nsec_time = NANO*(end.tv_sec - start.tv_sec) + 
			  end.tv_nsec - start.tv_nsec;
	++iters;
}while(nsec_time < (TIMER * NANO));

return iters;

}

/*
	Iteration Timer
	***************
	returns time taken for x
	encryptions of some
	block size
*/
double aes128_iter_timer(AES_KEY *aes_ks1)
{

/* variables */
struct timespec start, end;
unsigned long nsec_time = 0;
unsigned char iv[VEC_SIZE];
double sec_time = 0.0;

/* encryption timer */
clock_gettime(CLOCK_REALTIME, &start);
aes128_bench_timer(ITERS, (size_t)BLOCK_SIZE, aes_ks1, iv, BENCH_TIME);
clock_gettime(CLOCK_REALTIME, &end);

nsec_time = NANO*(end.tv_sec - start.tv_sec) +
		  end.tv_nsec - start.tv_nsec;

/* return seconds w/ nsec precision */
sec_time = nsec_time / (double)NANO;

return sec_time;

}

/*
	Timer Benchmark
	******************************
	runs x amount of cbc encryptions
*/
void aes128_bench_timer(long iters, size_t size, AES_KEY *aes_ks1, 
		        unsigned char *iv, int benchtype)
{

if(!benchtype)
{

	int count = 0;

	do{
		/* count the encryptions */
		aes128_cbc_encrypt_wrap(size, aes_ks1, iv);
		++count;

	}while(count < iters);
}
else
{
	/* just run the encryption */
	aes128_cbc_encrypt_wrap(size, aes_ks1, iv);
}

}
