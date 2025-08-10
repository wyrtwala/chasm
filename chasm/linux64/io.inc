io:

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
  

cli.read.char fix cli_read_char

cli_read_char:
  xor rax, rax
  xor rdi, rdi
  mov rdx, 1
  syscall
  mov rax, rsi
  ret



.read.byte:
.read.line:
.read.file:

.write.byte:
.write.line:
.write.file:

file:
macro .creat.file: filename*, {
  mov rdi, [filename]
  mov rsi, 

}
.create_file:
.open_file:
.close_file:
