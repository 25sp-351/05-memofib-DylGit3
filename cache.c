#include "cache.h"

int results[MAX_N];

int cache(int value) {
    if (results[value] == NOT_PRESENT)
        results[value] = (*fibonacci_provider)(value);
    return results[value];
}

void cache_load(void) {
    for (size_t i = 0; i < MAX_N; ++i)
        results[i] = NOT_PRESENT;
}
