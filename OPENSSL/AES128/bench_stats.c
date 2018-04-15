#include "bench_stats.h"

void aes128_count_stats(int * iters, float *mean, float *std_dev)
{

float mean_sum, dev_sum, dev_mean;

for(int i = 0; i < TRIALS; i++)
{
	mean_sum += (float)iters[i];
}

*mean = mean_sum / TRIALS;

for(int i = 0; i < (float)TRIALS; i++)
{
	dev_sum += (float)((iters[i] - *mean) * (iters[i] - *mean));
}

dev_mean = dev_sum / TRIALS;
*std_dev = (float)sqrt(dev_mean);

}

void aes128_time_stats(double *time, float *mean, float *std_dev)
{

float mean_sum, dev_sum, dev_mean;

for(int i = 0; i < TRIALS; i++)
{
	mean_sum += (float)time[i];
}

*mean = mean_sum / (float)TRIALS;

for(int i = 0; i < TRIALS; i++)
{
	dev_sum += (float)((time[i] - *mean) * (time[i] - *mean));
}

dev_mean = dev_sum / TRIALS;
*std_dev = (float)sqrt(dev_mean);

}	
