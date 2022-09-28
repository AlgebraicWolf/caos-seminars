.global main

.text
main:
  // Save stack frame and ret address
  stp x29, x30, [sp, -16]! // sp <- sp - 16
  mov x29, sp
  // Allocate local variables
  sub sp, sp, 16

  // Call scanf
  adr x0, FORMAT_STR
  sub x1, x29, 4
  bl scanf

  // Call printf

  // adrp x0, FORMAT_STR
  // add x0, x0, :lo12:FORMAT_STR
  adr x0, FORMAT_STR
  ldr w1, [x29, -4]
  bl printf

  // Free local variables
  mov sp, x29
  // Restore fp, sp and free the memory
  ldp x29, x30, [sp], 16
  // Exit
  ret

.data
FORMAT_STR: .string "%d"
