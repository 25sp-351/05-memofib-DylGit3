// Copied the code from the slides. Also experiemnted using unsigned long long
// to expand how many values of fibonacci could be reached

#include <stdint.h>
#include <stdio.h>

typedef unsigned long long (*ull_func_ptr)(long number);

#define NOT_PRESENT (unsigned long long)(-1)
#define MAX_N 100

static unsigned long long results[MAX_N];
ull_func_ptr fibonacci_provider;
ull_func_ptr original_provider;

unsigned long long fibonacci(long number) {
    if (number < 0) {
        fprintf(stderr, "Value must be greater than or equal to 0.\n");
        return NOT_PRESENT;
    }
    return original_provider(number);
}

unsigned long long fibonacci_calculations(long number) {
    if (number == 0)
        return 0;
    if (number == 1)
        return 1;
    return fibonacci_provider(number - 1) + fibonacci_provider(number - 2);
}

unsigned long long cache(long value) {
    if (results[value] == NOT_PRESENT)
        results[value] = original_provider(value);
    return results[value];
}

int main() {
    long n = 97;

    for (int i = 0; i < MAX_N; i++)
        results[i] = NOT_PRESENT;

    original_provider  = fibonacci_calculations;
    fibonacci_provider = cache;

    printf("The value of %ld is %llu.\n", n, fibonacci(n));

    return 0;
}
