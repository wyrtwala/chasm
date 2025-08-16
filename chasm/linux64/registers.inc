$a fix rsi
$b fix rdi
$1 fix r8
$2 fix r9
$3 fix r10
$4 fix r11
$5 fix r12
$6 fix r13
$7 fix r14
$8 fix r15

macro stack [rxx] {
  forward push rxx
  common mov rbp, rsp
}

macro unstack [rxx] {
  common mov rsp, rbp
  reverse pop rxx
}

macro return variable {
  mov variable, rax
}
