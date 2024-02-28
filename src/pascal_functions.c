#include <stdio.h>

#include "pascal_functions.h"

int binom_coeff(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }

    int result = 1;
    for (int i = 1; i <= k; ++i) {
        result *= (n - i + 1);
        result /= i;
    }
    return result;
}

void find_base_triangle(int *base, int number) {
    for (int i = 0; i < number; ++i) {
        base[i] = binom_coeff(number - 1, i);
    }
}

void output_base_triangle(int *base, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d", base[i]);
        if (i < n - 1) printf(" ");
    }
}