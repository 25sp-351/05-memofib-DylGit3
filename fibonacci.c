#include <stdint.h>
#include <stdio.h>

typedef unsigned long long (*ull_func_ptr)(int number);

#define NOT_PRESENT (unsigned long long)(-1)
#define MAX_N 93

static unsigned long long results[MAX_N];
ull_func_ptr fibonacci_provider;
ull_func_ptr original_provider;

unsigned long long fibonacci(int number) {
    if (number < 0) {
        fprintf(stderr, "Value must be greater than or equal to 0.\n");
        return NOT_PRESENT;
    }

    return original_provider(number);
}

unsigned long long fibonacci_calculations(int number) {
    if (number == 0)
        return 0;
    if (number == 1)
        return 1;
    if (number >= MAX_N)
        return original_provider(number - 1) + original_provider(number - 2);

    return fibonacci_provider(number - 1) + fibonacci_provider(number - 2);
}

unsigned long long cache(int value) {
    if (results[value] == NOT_PRESENT)
        results[value] = original_provider(value);

    return results[value];
}

int main() {
    int n = 97;

    for (int i = 0; i < MAX_N; i++)
        results[i] = NOT_PRESENT;

    original_provider  = fibonacci_calculations;
    fibonacci_provider = cache;

    printf("The value of %d is %llu.\n", n, fibonacci(n));

    return 0;
}
