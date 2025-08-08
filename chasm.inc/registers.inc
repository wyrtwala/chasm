.equ $a, rsi
.equ $b, rdi
.equ $1, r8
.equ $2, r9
.equ $3, r10
.equ $4, r11
.equ $5, r12
.equ $6, r13
.equ $7, r14
.equ $8, r15

.macro returnto
  \n\t return_to_macro
.endm

.macro return_to_macro variable
  mov variable rax
.endm
