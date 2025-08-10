macro data-string name*, string* {
segment readable writeable
    name: 
        .asciz string
        name.length equ $ - string
segment readable executable
}

macro data input* {
segment readable writeable
    input
segment readable executable
}
