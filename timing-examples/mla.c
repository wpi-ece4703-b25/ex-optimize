#include <stdint.h>
#include <stdio.h>

static inline int32_t multiply_accumulate(int32_t acc, int16_t a, int16_t b) {
    int32_t result;
    asm volatile (
        "madd %w[res], %w[mul1], %w[mul2], %w[accumulator]"
        : [res] "=r" (result)
        : [mul1] "r" (a), [mul2] "r" (b), [accumulator] "r" (acc)
    );
    return result;
}

void main() {
  int acc = 25;
  acc = multiply_accumulate(acc, 5, 6);
  printf("acc %d\n", acc);
}
