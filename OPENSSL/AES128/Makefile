# makefile for aes_128 encryption files

all: main.c benchm.c benchm_time.c bench_stats.c aes_cbc.c aes_core.c \
     cbc128.c aes_tb.c
	gcc -Wall -g -o aes_cbc main.c benchm.c benchm_time.c bench_stats.c \
	aes_cbc.c aes_core.c cbc128.c aes_tb.c -lm

clean:
	rm -f aes_cbc  
