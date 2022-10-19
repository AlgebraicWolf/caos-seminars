#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define INC_COUNT 0x100000

const char filename[] = "counter.bin";

int main() {
  // Open file
  int fd = open(filename, O_RDWR);
  // Check for errors
  if (-1 == fd) {
    perror("open");
    _exit(1);
  }

  // Increment INC_COUNT times
  for (int i = 0; i < INC_COUNT; i++) {
    int current_value = 0;

    // Set position to the beginning
    if (-1 == lseek(fd, 0, SEEK_SET)) {
      perror("lseek for read");
      _exit(1);
    }

    // Read current value
    if (-1 == read(fd, &current_value, sizeof(current_value))) {
      perror("read");
      _exit(1);
    }

    // Increment
    current_value++;

    // Set position to the beginning
    if (-1 == lseek(fd, 0, SEEK_SET)) {
      perror("lseek for write");
      _exit(1);
    }

    // Write new value
    if(-1 == write(fd, &current_value, sizeof(current_value))) {
      perror("write");
      _exit(1);
    }
  }

  close(fd);
  return 0;
}
