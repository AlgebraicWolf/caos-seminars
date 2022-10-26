#include <sys/mman.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main () {
  int fd = open("f.txt", O_RDWR);

  if (-1 == fd) {
    perror("open");
    _exit(1);
  }

  struct stat statbuf = {};
  fstat(fd, &statbuf);

  char *mem = mmap(NULL,
                   statbuf.st_size,
                   PROT_READ | PROT_WRITE,
                   MAP_SHARED,
                   fd,
                   0);
  close(fd);

  if (MAP_FAILED == mem) {
    perror("mmap");
    _exit(1);
  }

  mem[1] = mem[0];

  munmap(mem, statbuf.st_size);
}
