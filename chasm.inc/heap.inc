heap:

heap.allocate:
  push ebp
  mov ebp, esp
  ;allocate
  mov esp, ebp
  pop ebp
  mov rax, ;pointer
  ret

heap.move
  ;put _ into allocated memory
  mov rax, ;pointer
  ret
  
heap.hook
  ;realloc and concatenate two strings onto heap
  mov rax, ;pointer
  ret

