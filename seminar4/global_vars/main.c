#include <stdio.h>
#include <stdint.h>

uint64_t A = 0;
uint64_t B = 0;
uint64_t C = 0;
uint64_t D = 0;

extern uint64_t R;
extern void calculate();

int main() {
  scanf("%d %d %d %d", &A, &B, &C, &D);
  calculate();
  printf("%d\n", R);
}
