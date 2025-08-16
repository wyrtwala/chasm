macro io.read.char fd*, buffer* {
  stack    rbp rax rdx rdi rsi
  xor rax, rax                           ; read
  mov rdx, 1                             ; one char (32bits?)
  xor rdi, fd                            ; where from
  lea rsi, [buffer]                      ; read buffer
  syscall   
  unstack  rbp rax rdx rdi rsi
}  

macro io.write.char fd*, buffer* {
  stack    rbp, rax, rdi, rsi, rdx
  mov rax, 1                      ; write
  mov rdi, fd                     ; where
  mov rsi, chartowrite            ; load char (check syntax)
  mov rdx, 1                      ; one char (32bits?)
  syscall
  unstack  rbp, rax, rdi, rsi, rdx
}

macro io.read.line: fd* ,buffer*, max_length=1024 {
  stack    rbp rax rdx rdi rsi r15       ; save rxx in case already used
  xor rax, rax                           ; read
  mov rdx, 1                             ; one char (32bits?)
  xor rdi, fd                            ; where from
  xor r15, r15                           ; counter
@@:                                      ; loop back label
  lea rsi, [buffer + r15]                ; read buffer (check syntax)
  cmp r15, max_length                    ; check length
  jge      @f                            ; end macro if too long
  syscall
  cmp rsi, 10                            ; check for line feed
  jne      @b                            ; repeat
@@:                                      ; cancel label
  unstack  rbp, rax, rdx, rdi, rsi, r15
}  

io.write fix sys.write
io.file.read fix sys.mmap

macro io.file.create filename* {
  stack    rbp, rdi, rsi
  mov rbp, rsp
  mov rax, 2
  mov rdi, filename
  mov rsi, 33282
  syscall
  mov rsp, rbp
  unstack  rbp, rdi, rsi
}

io.file.open fix sys.open
io.file.close fix sys.close
