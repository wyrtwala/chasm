macro heap.claim size* {
  mov rax, 9               ; mmap
  mov rdi, 0               ; allocate wherever
  mov rsi, size            ; size in bytes
  mov rdx, 3               ; read and write
  mov r10, 33              ; anonymous and shared (for threads)
  mov r9,  0               ; offset
  mov r8, -1               ; don't allocate in file
}

macro heap.release size*, address* {
  mov rax, 11
  mov rdi, address
  mov rsi, size
  syscall
}
;-----------------------------------------------------neads work------------------------------------------------------------
heap.move:
  mov rax, ;pointer
  ret
  
heap.hook:
  mov rax, ;pointer
  ret

