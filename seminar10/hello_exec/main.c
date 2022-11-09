#include <unistd.h>
#include <stdio.h>

int main() {
  execlp("python",
         "python",
         "-h",
         NULL);
  perror("execlp");
}
