io:

;----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
macro cli.read.char {
  xor rax, rax
  xor rdi, rdi
  mov rdx, 1
  syscall
  mov rax, rsi
  ret
}
macro cli.read.line: buffer*, max_length {
  push r15
  xor rax, rax
  xor r15, r15
  local cli_read_line_loop:
  cmp r15, max_length
  je cli_read_line_end
  call cli.read.char
  mov [buffer + r15], rax
  cmp rax, "\n"
  jne cli_read_line_loop
  local cli_read_line_end:
  mov rax, buffer
  pop r15
  ret
}
macro cli.write.char chartowrite* {
  mov rax, 1
  mov rdx, 1
  mov rsi, chartowrite
  syscall
}
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
  ret
}

;----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
macro file.read.char filedescriptor* {
  xor rax, rax
  mov rdx, 1
  mov rdi, filedescriptor
  syscall
  mov rax, rsi
  ret
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
  ret
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
  ret
}

;----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
macro file.write.byte filedescriptor*, bytetowrite* {
  mov rax, 1
  mov rdx, 1
  mov rdi, filedescriptor
  mov rsi, bytetowrite
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
