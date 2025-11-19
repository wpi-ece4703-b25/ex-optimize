#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(long long*)a - *(long long*)b);
}

static inline unsigned long long ccnt_read(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (unsigned long long)ts.tv_sec * 1000000000ULL + ts.tv_nsec;
}

int test(int a, int b) {
  int j;
  for (j = 0; j < a; j++)
    b += b;
  return b;
}

int main() {
  int i, sum = 0;
  long long start, lap;
  long long measure[9];
  int iter;
  for (iter = 0; iter < 9; iter++) {
    start = ccnt_read();
    for (i=0; i<10000; i++)
      sum = sum + test(i, i+1);
    measure[iter] = (ccnt_read() - start);
  }
  qsort(measure, 9, sizeof(long long), compare);
  printf("Cycles %lld\n", measure[4]);
  return sum;
}
