#include <math.h>
#include "benchm.h"

#ifdef __cplusplus
extern "C" {
#endif

void aes128_count_trials(AES_KEY *, int *);
void aes128_timer_trials(AES_KEY *, double *);
void aes128_count_stats(int *);
void aes128_time_stats(double *);

#ifdef __cplusplus
}
#endif
