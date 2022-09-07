#include <stdio.h>
#include <stdbool.h>

static void show_hello() {
  printf("Hello!\n");
}

void show_int(int x) {
  printf("The int is: %d\n", x);
}

int main() {
  show_hello();
  show_int(42);

  while(true) {}
}
