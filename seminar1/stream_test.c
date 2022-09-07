#include <stdlib.h>
#include <stdio.h>

int main() {
  fprintf(stdout, "Some text");
  fprintf(stderr, "Some error\n");
  fprintf(stdout, " on standard output\n");
}
