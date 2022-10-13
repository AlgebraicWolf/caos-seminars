#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  // O_RDONLY -- read
  // O_WRONLY -- write
  // O_RDWR   -- read & write
  // O_CREAT  -- create file
  // O_APPEND -- append to file
  // O_NONBLOCK -- non-blocking mode
  int fd = open("in.txt", O_RDONLY);
  int fd_out = open("out.txt", O_RDWR | O_CREAT, 0640);

  if (fd == -1) {
    perror("open_1");
    exit(1);
  }

  char buf[5] = {};

  lseek(fd, -2, SEEK_END);

  ssize_t bytes = read(fd, buf, sizeof(buf));
  if (-1 == bytes) {
    perror("read");
  };

  if (-1 == write(fd_out, buf, bytes)) {
    perror("write");
  }

  printf("File descriptor is: %d\n", fd);

  close(fd_out);
  close(fd);
}
