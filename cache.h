#ifndef CACHE_H
#define CACHE_H

#include <stdio.h>

#define NOT_PRESENT -1
#define MAX_N 94

typedef int (*ProviderFunction)(int number);
ProviderFunction fibonacci_provider;

int cache(int value);
void cache_load(void);

#endif
