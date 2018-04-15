#include "bench_stats.h"
#include "benchm_time.h"

/*
	Capture Encryption Count Data for x Trials
*/
void aes128_count_trials(AES_KEY *aes_ks1, int *iters)
{

for(int i = 0; i < TRIALS; i++)
{
	printf("\nTRIAL %d\n", i + 1);

	iters[i] = aes128_iter_counter(aes_ks1);

	printf("\nSeconds: %.1Lf Size: %d Total Encryptions: %d\n",
		TIMER, BLOCK_SIZE, iters[i]);
} 

} 

/*
	Capture Encryption Timing Data for x Trials
*/
void aes128_timer_trials(AES_KEY *aes_ks1, double *time)
{

for(int i = 0; i < TRIALS; i++)
{
	printf("\nTRIAL %d\n", i + 1);

	time[i] = aes128_iter_timer(aes_ks1);

	printf("\nBlocks: %ld Size: %d Seconds: %.8lf\n", ITERS, 
		BLOCK_SIZE, time[i]);	
}

}

/*
	Get Mean # of Encryptions
	along with Standard Deviation
*/
void aes128_count_stats(int * iters)
{

float mean_sum, dev_sum, dev_mean, mean, std_dev;

for(int i = 0; i < TRIALS; i++)
{
	mean_sum += (float)iters[i];
}

/* get the mean */
mean = mean_sum / (float)TRIALS;

for(int i = 0; i < TRIALS; i++)
{
	dev_sum += pow((iters[i] - mean), 2);
}

/* get the standard deviation */
dev_mean = dev_sum / TRIALS;
std_dev = (float)sqrt(dev_mean);

/* results */
printf("\nTrials: %d Time: %.1Lf Average Encryptions: %.3lf Standard "
       "Deviation: %.8lf\n", TRIALS, TIMER, mean, std_dev);

}

/*
	Get Mean Time for Encrypting 
	x Values along with Standard
	Deviation
*/
void aes128_time_stats(double *time)
{

float mean_sum, dev_sum, dev_mean, mean, std_dev;

for(int i = 0; i < TRIALS; i++)
{
	mean_sum += (float)time[i];
}

/* get the mean */
mean = mean_sum / (float)TRIALS;

for(int i = 0; i < TRIALS; i++)
{
	dev_sum += pow((time[i] - mean), 2);
}

/* get the standard deviation */
dev_mean = dev_sum / TRIALS;
std_dev = (float)sqrt(dev_mean);

/* results */
printf("\nTrials: %d Encryptions: %ld Average Time: %.8lf Standard "
       "Deviation: %.8lf\n", TRIALS, ITERS, mean, std_dev);

}	
