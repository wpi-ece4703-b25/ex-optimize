int test(int a, int b) {
  int j;
  for (j = 0; j < a; j++)
    b += b;
  return b;
}

int main() {
  int i, sum = 0;
  for (i=0; i<10000; i++)
    sum = sum + test(i, i+1);
  return sum;
}
