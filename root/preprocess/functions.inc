macro funcion name* {
name:
    push ebp
    mov ebp, esp
}

macro end-function* {
    mov esp, ebp
    pop ebp
    ret
}
