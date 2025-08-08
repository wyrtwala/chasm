heap:

.allocate:
  push ebp
  mov ebp, esp
  ;allocate
  mov esp, ebp
  pop ebp
  mov rax, ;pointer
  ret

.move:
  mov rax, ;pointer
  ret
  
.hook:
  mov rax, ;pointer
  ret

