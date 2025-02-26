#include "fibonacci.h"

#include <stdio.h>

int results[MAX_N];

int fibonacci_calculations(int number) {
    if (number == 0)
        return 0;
    if (number == 1)
        return 1;
    return (*fibonacci_provider)(number - 1) +
           (*fibonacci_provider)(number - 2);
}

int cache(int value) {
    if (results[value] == NOT_PRESENT)
        results[value] = (*fibonacci_provider)(value);
    return results[value];
}

void cache_load(void) {
    for (size_t i = 0; i < MAX_N; ++i)
        results[i] = NOT_PRESENT;
}

int main() {
    cache_load();
    int n                             = 10;
    fibonacci_provider                = fibonacci_calculations;
    ProviderFunction caching_provider = cache;

    if (n < 0) {
        fprintf(stderr, "Value must be greater than or equal to 0.\n");
        return 1;
    }

    printf("The value of %d is %d.\n", n, (*caching_provider)(n));

    return 0;
}
