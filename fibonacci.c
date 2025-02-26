#include "fibonacci.h"

#include <stdio.h>

#include "cache.h"

int fibonacci_calculations(int number) {
    if (number == 0)
        return 0;
    if (number == 1)
        return 1;
    return (*fibonacci_provider)(number - 1) +
           (*fibonacci_provider)(number - 2);
}

// I figured it was not worth creating another file called main
int main() {
    cache_load();
    int n                             = 11;
    fibonacci_provider                = fibonacci_calculations;
    ProviderFunction caching_provider = cache;

    if (n < 0) {
        fprintf(stderr, "Value must be greater than or equal to 0.\n");
        return 1;
    }

    printf("The value of %d is %d.\n", n, (*caching_provider)(n));

    return 0;
}
