#include <unistd.h>
const char prog_name[] = "./racer";

int main() {
  fork();
  execlp(prog_name, prog_name);
}
