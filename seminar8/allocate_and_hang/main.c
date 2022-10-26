#include <sys/mman.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  void *mem = mmap(NULL,
                   (size_t)(32) * 1024 * 1024 * 1024,
                   PROT_READ | PROT_WRITE,
                   MAP_PRIVATE | MAP_ANONYMOUS,
                   -1,
                   0);

  if (MAP_FAILED == mem) {
    perror("mmap");
    _exit(1);
  }

  printf("Address of allocated memory: %p\n", mem);

  while(1) {}
}
