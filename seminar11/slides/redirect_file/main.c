#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>

pid_t launch(const char *cmd, int fd_in, int fd_out) {
  pid_t pid = fork();

  if (0 == pid) {
    if (-1 == dup2(fd_in, STDIN_FILENO)) {
      return -1;
    }

    if(-1 == dup2(fd_out, STDOUT_FILENO)) {
      return -1;
    }

    execlp(cmd, cmd, NULL);
    return -1;
  }

  return pid;
}

int main() {
  int fd_in  = open("in.txt", O_RDONLY);
  int fd_out = open("out.txt", O_CREAT | O_WRONLY, 0666);

  pid_t pid = launch("cat", fd_in, fd_out);

  if(-1 == pid) {
    perror("launch");
  } else {
    waitpid(pid, NULL, 0);
  }

  close(fd_in);
  close(fd_out);
}
