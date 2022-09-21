#include <stdio.h>
#include <limits.h>


int compare(int x) {
  return (x + 1) > x;
}

int main() {
  int x = INT_MAX;

  printf("%d > %d : %d\n", x + 1, x, compare(x));
}
