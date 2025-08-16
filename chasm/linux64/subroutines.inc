macro sub_routine name* {
name#:
    stack rbp, r8, r9, r10, r11, r12, r13, r14, r15
}

macro end_routine* {
    unstack rbp, r8, r9, r10, r11, r12, r13, r14, r15
    ret
}
