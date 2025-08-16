macro heap.request size* {
  mov rax, 9               ; mmap
  mov rdi, 0               ; allocate wherever
  mov rsi, size * 64       ; size in cache lines
  mov rdx, 3               ; read and write
  mov r10, 33              ; anonymous and shared (for threads)
  mov r9,  0               ; offset
  mov r8, -1               ; don't allocate in file
}

macro heap.release size*, address* {
  mov rax, 11
  mov rdi, address
  mov rsi, size * 64
  syscall
}


