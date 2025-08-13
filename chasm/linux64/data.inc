macro data.string name*, string* {
segment readable writeable
    name dq string, 0
    name.length equ $ - string
segment readable executable
}

macro data.atom name*, atom* {
segment readable writeable
    name dq atom
    name.lenght dq 0
segment readable executable
}

macro data.manual input* {
segment readable writeable
    input
segment readable executable
}
