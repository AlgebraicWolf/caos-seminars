#include <sys/syscall.h>

.intel_syntax noprefix

.global _start
.text
_start:
  mov rax, SYS_write
  mov rdi, 1
  lea rsi, [Msg]
  mov rdx, OFFSET Msg_LEN
  syscall

  mov rax, SYS_exit
  xor rdi, rdi
  syscall


.data
Msg: .ascii "Hello, World!\n"
Msg_LEN = . - Msg
