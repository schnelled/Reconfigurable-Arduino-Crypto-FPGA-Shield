#include <time.h>
#include <stdint.h>
#include "benchm.h"

#define NANO        1000000000L
#define ITERS       10000000L
#define TIMER       1.0L
#define BENCH_TIME  0
#define BENCH_COUNT 1

#ifdef __cplusplus
extern "C" {
#endif

int aes128_iter_counter(AES_KEY *);
double aes128_iter_timer(AES_KEY *);
void aes128_bench_timer(long, size_t, AES_KEY *, unsigned char *, int);

#ifdef __cplusplus
}
#endif
