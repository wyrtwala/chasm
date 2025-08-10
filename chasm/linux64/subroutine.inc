macro sub-routine name* {
name:
    push ebp r8 r9 r10 r11 r12 r13 r14 r15
    mov ebp, esp
}

macro end-routine* {
    mov esp, ebp
    pop ebp r8 r9 r10 r11 r12 r13 r14 r15
    ret
}
