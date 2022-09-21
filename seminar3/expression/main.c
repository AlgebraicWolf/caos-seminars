#include <stdio.h>
#include <stdint.h>

extern int64_t f(int64_t A, int64_t B, int64_t C, int64_t x);

int main() {
  int A = 0, B = 0, C = 0, x = 0;
  scanf("%d %d %d %d", &A, &B, &C, &x);
  printf("Result: %d\n", f(A, B, C, x));
}
