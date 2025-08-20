;----------------------------------------------------------------------------------------------------------------------------------------
; 32BIT
;----------------------------------------------------------------------------------------------------------------------------------------
macro rend.32.string string*, length*, buffer* {
  local counter = 0
  @@:
  lea  rax,    [string + counter * 8]
  rend.32.unit  rax
  mov [buffer + counter * 4], eax
  inc counter
  cmp length,   counter
  jg  @b
}

macro rend.32.unit unit* {
  push r8
  mov  r8, unit
  mov  eax, r8d
  cdq3
  pop  r8
}
;----------------------------------------------------------------------------------------------------------------------------------------
; 16BIT
;----------------------------------------------------------------------------------------------------------------------------------------
macro rend.16.string name*, string* {
  local counter = 0
  @@:
  lea  rax,     [string + counter * 8]
  rend.16.unit  rax
  mov [buffer + counter * 2], ax
  inc counter
  cmp length,   counter
  jg  @b
}

macro rend.16.unit name*, unit* {
  push r8
  mov  r8, unit
  mov  ax, r8w
  cdwe
  cdq3
  pop  r8
}
;----------------------------------------------------------------------------------------------------------------------------------------
;  8BIT
;----------------------------------------------------------------------------------------------------------------------------------------
macro rend.8.string name*, string* {
  local counter = 0
  @@:
  lea  rax,    [string + counter * 8]
  rend.8.unit   rax
  mov [buffer + counter], al
  inc  counter
  cmp  length,  counter
  jg   @b
}

macro rend.8.unit name*,unit* {
  push r8
  mov  r8, unit
  mov  al, r8b
  cbw
  cdwe
  cdq3
  pop  r8
}
