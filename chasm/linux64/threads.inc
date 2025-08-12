macro threads.fork {
  mov rax, 57
  syscall
} 

macro threads.pipe pipename* {
segment readable writeable
  pipename dq 0, 0
segment readable executable
  mov rdi, pipename
  mov rax, 22
  syscall
}

macro threads.kill pid* {
  mov rax, 62
  mov rdi, pid
  mov rsi, 15
  syscall
}

macro threads.murder pid* {
  mov rax, 62
  mov rdi, pid
  mov rsi 9
  syscall
}

macro threads.wait pid* {
  mov rax, 247
  mov rdi, -1
  mov rsi, pid
  mov r10, 1
  syscall
}
