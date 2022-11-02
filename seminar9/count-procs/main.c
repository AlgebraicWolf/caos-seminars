#include <unistd.h>
#include <stdio.h>
#include <sched.h>
#include <stdint.h>
#include <sys/wait.h>

int main() {
  uint64_t proc_cnt = 1;

  /* while (1) { */
  /*   pid_t pid = fork(); */

  /*   if (-1 == pid) { */
  /*     printf("%ld\n", proc_cnt); */
  /*     break; */
  /*   } else if (0 == pid) { */
  /*     while(1) { */
  /*       sched_yield(); */
  /*     } */
  /*   } else { */
  /*     proc_cnt++; */
  /*   } */
  /* } */

  while(1) {
    pid_t pid = fork();

    if (-1 == pid) {
      printf("%ld\n", proc_cnt);
      break;
    } else if (0 == pid) {
      proc_cnt += 1;
    } else {
      waitpid(pid, NULL, 0);
      break;
    }
  }
}

