macro cli.read.char buffer{
  stack rbp rax rdx rdi rsi
  mov rbp, rsp
  xor rax, rax                           ; read
  mov rdx, 1                             ; one char (32bits?)
  xor rdi, rdi                           ; stdin
  lea rsi, [buffer]                      ; read buffer
  syscall   
  mov rsp, rbp
  unstack rbp rax rdx rdi rsi
}  

macro cli.read.line: buffer*, max_length=1024 {
  stack rbp rax rdx rdi rsi r15          ; save rxx in case they
  mov rbp, rsp                           ; are being used
  local cli_read_line_loop cli_read_line_end
  xor rax, rax                           ; read
  mov rdx, 1                             ; one char (32bits?)
  xor rdi, rdi                           ; stdin
  xor r15, r15                           ; counter
cli_read_line_loop:                      ; loop back label
  lea rsi, [buffer + r15]                ; read buffer (check syntax)
  cmp r15, max_length                    ; check length
  jge cli_read_line_end                  ; end macro if too long
  syscall
  cmp rsi, 10                            ; check for line feed
  jne cli_read_line_loop                 ; repeat
cli_read_line_end:                       ; cancel label
  mov rsp, rbp
  unstack rbp rax rdx rdi rsi r15
}  

macro cli.write.char chartowrite* {
  mov rax, 1                      ; write
  mov rdi, 1                      ; stdout
  mov rdx, 1                      ; one char (32bits?)
  mov rsi, chartowrite            ; load char (check syntax)
  syscall
}

;------------------------------------------------------------------------------------------------continue checking----------------------------------------------------------------------------------------------------------------
macro cli.write.string string*, max_length {
  push r14 r15
  xor rax, 1
  xor r14, r14
  xor r15, r15
  local cli_write_loop:
  cmp r15, max_length
  jge cli_write_end
  mov r14, [string + r15]
  cmp r14, 0
  je cli_read_line
  cli.write.char 
  cmp r14, "\n"
  jne file_read_line_loop
  local cli_read_line_end:
  mov rax, buffer
  pop r14 r15
}

;----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
macro file.read.char filedescriptor* {
  xor rax, rax
  mov rdx, 1
  mov rdi, filedescriptor
  syscall
  mov rax, rsi
}
macro file.read.line filedescriptor*, buffer*, max_length {
  push r15
  xor rax, rax
  xor r15, r15
  local file_read_line_loop:
  cmp r15, max_length
  je file_read_line_end
  call file.read.char
  mov [buffer + r15], rax
  cmp rax, "\n"
  jne file_read_line_loop
  local cli_read_line_end:
  mov rax, buffer
  pop r15
}
macro file.read filedescriptor*, buffer*, max_length {
  push r15
  xor rax, rax
  xor r15, r15
  local read_file_loop:
  cmp r15, max_length
  je read_file_end
  call file.read.char
  mov [buffer + r15], rax
  cmp rax, 0
  jge read_file_loop
  local read_file_end:
  mov rax, buffer
  pop r15
}

;----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
macro file.write.char filedescriptor*, chartowrite* {
  mov rax, 1
  mov rdx, 1
  mov rdi, filedescriptor
  mov rsi, chartowrite
  syscall
}




macro file.write.line {}
macro file.write.string {}

macro file.create filename* {}
macro file.open filename* {}
macro file.close filedescriptor* {
  mov rax, 3
  mov rdi, filedescriptor
  syscall
}
