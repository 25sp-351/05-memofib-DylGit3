#ifndef FIBONACCI_H
#define FIBONACCI_H

#define NOT_PRESENT -1
#define MAX_N 100

typedef int (*ProviderFunction)(int number);
ProviderFunction fibonacci_provider;

int cache(int value);
int fibonacci(int number);
int fibonacci_calculations(int number);
int cache(int value);
void cache_load(void);

#endif
