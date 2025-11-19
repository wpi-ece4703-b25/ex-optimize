#include <stdio.h>
#include <time.h>

static inline unsigned long long ccnt_read(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (unsigned long long)ts.tv_sec * 1000000000ULL + ts.tv_nsec;
}

#define SIZE 65536

struct {
    float real[SIZE];
    float imag[SIZE];
} ComplexArray;


typedef struct {
  float real;
  float imag;
} Complex;
Complex C[SIZE];


void main() {
  long long start, lap;
  int i;

  start = ccnt_read();
  for (i = 0; i<SIZE; i++) {
    ComplexArray.real[i] = 0;
    ComplexArray.imag[i] = 0;
  }
  lap = ccnt_read() - start;
  printf("Cycles %lld\n", lap);

  start = ccnt_read();
  for (i = 0; i<SIZE; i++) {
    C[i].real = 0;
    C[i].imag = 0;
  }
  lap = ccnt_read() - start;
  printf("Cycles %lld\n", lap);

  float rr = 0, ii = 0;
  start = ccnt_read();
  for (i = 0; i<SIZE; i++) {
    rr += ComplexArray.real[i];
    ii += ComplexArray.imag[i];
  }
  lap = ccnt_read() - start;
  printf("Cycles %lld\n", lap);

  start = ccnt_read();
  for (i = 0; i<SIZE; i++) {
    rr += C[i].real ;
    ii += C[i].imag ;
  }
  lap = ccnt_read() - start;
  printf("Cycles %lld\n", lap);


}
