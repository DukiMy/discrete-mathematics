#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

unsigned long long factorial(int num) {
  unsigned long long result = 1;
  for (int i = 2; i <= num; ++i)
    result *= i;
  return result;
}

unsigned long long permutation(int n, int r) {
  return (factorial(n) / factorial(n - r));
}

void formula_10() {
  printf("Formula 10 called.\n");
}
