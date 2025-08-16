;----------------------------------------------------------------------------------------------------------------------------------------
; 32BIT
;----------------------------------------------------------------------------------------------------------------------------------------
macro smelt.32.string string*, length*, buffer* {
local counter = 0
@@:
lea rax, [string + counter]
smelt.32.unit rax
mov [buffer + counter * 2], rax
inc counter
cmp length, counter
jg @b
}

macro smelt.32.unit unit* {
  mov eax, unit
  cdqe
}
;----------------------------------------------------------------------------------------------------------------------------------------
; 16BIT
;----------------------------------------------------------------------------------------------------------------------------------------
macro smelt.16.string string*, length*, buffer* {
local counter = 0
@@:
lea rax, [string + counter]
smelt.16.unit rax
mov [buffer + counter * 4], rax
inc counter
cmp length, counter
jg @b
}

macro smelt.16.unit unit* {
  mov ax, unit
  cwde
  cdqe
}
;----------------------------------------------------------------------------------------------------------------------------------------
;  8BIT
;----------------------------------------------------------------------------------------------------------------------------------------
macro smelt.8.string string*, length*, buffer* {
local counter = 0
@@:
lea rax, [string + counter]
smelt.8.unit rax
mov [buffer + counter * 8], rax
inc counter
cmp length, counter
jg @b
}

macro smelt.8.unit unit* {
  mov al, unit
  cbw
  cwde
  cdqe
}
