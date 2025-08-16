reg.caller fix rcx,rdx,rdi,esi,r8,r9
reg.callee fix rbx,rsp,rbp,r12,r13,r14,r15

macro subroute.define name* {
name:
    stack rbx,r12,r13,r14,r15
}
macro subroute.exit {
    stack rbx,r12,r13,r14,r15
    ret
}
macro subroute.execute subroutine*, sr.arg1, sr.arg2, sr.arg3, sr.arg4, sr.arg6 {
    stack reg.caller   
    mov #1, sr.arg1
    mov #2, sr.arg2
    mov #3, sr.arg3
    mov #4, sr.arg4
    mov #5, sr.arg5
    mov #6, sr.arg6
    call subroutine
}
macro subroute.return variable* {
    mov variable, rax
    unstack reg.caller
}
