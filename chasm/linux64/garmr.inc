macro garmr {
segment readable writable 
  garmr.door dq 0
  garmr.door.size dq 64
  garmr.door.count dq 0
segment readable executable 
  sys.mmap 64
  mov [garmr.door], rax
}
macro garmr.gate.new name*, size* {
segment readable writable
  garmr.gate.#name dq 0
  garmr.gate.#name#.size dq size
  garmr.gate.#name#.location dq 0
  segment readable executable
  garmr.gate.#name#.location = garmr.door.count
  sys.mmap size * 64
  mov [garmr.door + garmr.door.count * 8], rax
  mov [garmr.gate.#name#], rax
  cmp garmr.door.count, 64
jl @f
  stack rdi, rsi, rdx, rcx
  mov rax,      25 
  mov rdi, garmr.door
  mov rsi, garmr.door.size
  mov rdx, garmr.door.size + 64
  mov rcx, 1
  syscall
  add garmr.door.size, 64
  mov [garmr.door], rax
  unstack rdi, rsi, rdx, rcx
@@:
  inc garmr.door.count
}
macro garmr.gate.close name* {
  stack rdi, rsi
  mov [garmr.door + garmr.gate.#name#.location], [garmr.door + garmr.door.count * 8]
  mov [garmr.door + garmr.door.count * 8], 0
  dec garmr.door.count
  mov rax, [garmr.gate.#name#.size]
  mul 64
  mov rsi, rax
  mov rax, 11    
  mov rdi, [garmr.gate.#name#]
  syscall
  unstack rdi, rsi
}
