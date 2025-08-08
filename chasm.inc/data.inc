.macro data-string name*, string* 
    name: 
        .asciz string
        \name.length equ $ - string
.endm
