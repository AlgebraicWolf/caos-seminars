#include <unistd.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main () {
  pid_t pid = fork();

  if (0 == pid) {
    // Child exits normally
    exit(0);
  } else {
    // Parent outputs child pid and exits
    printf("Process id of child: %" PRIdMAX "\n", (intmax_t) pid);
    while(1) {}
  }
}
