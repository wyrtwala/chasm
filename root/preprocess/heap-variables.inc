macro heap pointer*, size* {         ;allocate heap memory
  mov eax, 9                         ;mmap syscall
  xor ebx, ebx                       ;addr, let kernal choose
  mov ecx, 4*size                    ;size in bytes
  mov edx, 1|2                       ;read and write
  mov esi, 20h                       ;don't map to file
  mov edi, edi                       ;choose fd
  xor ebp, ebp                       ;offset
  syscall
  pointer dw eax
  ;
  ; need to make heap tracker
}
