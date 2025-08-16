;----------------------------------------------------------------------------------------------------------------------------------------
; 64BIT
;----------------------------------------------------------------------------------------------------------------------------------------
macro data.64.string name*, string* {
segment readable writeable
    name dq string, 0
    name.length = $ - string
segment readable executable
}

macro data.64.unit name*, unit* {
segment readable writeable
    name dq unit
    name.lenght = 0
segment readable executable
}
;----------------------------------------------------------------------------------------------------------------------------------------
; 32BIT
;----------------------------------------------------------------------------------------------------------------------------------------
macro data.32.string name*, string* {
segment readable writeable
    name dd string, 0
    name.length = $ - string
segment readable executable
}

macro data.32.unit name*, unit* {
segment readable writeable
    name dd unit
    name.lenght = 0
segment readable executable
}
;----------------------------------------------------------------------------------------------------------------------------------------
; 16BIT
;----------------------------------------------------------------------------------------------------------------------------------------
macro data.16.string name*, string* {
segment readable writeable
    name dw string, 0
    name.length = $ - string
segment readable executable
}

macro data.16.unit name*, unit* {
segment readable writeable
    name dw unit
    name.lenght = 0
segment readable executable
}
;----------------------------------------------------------------------------------------------------------------------------------------
;  8BIT
;----------------------------------------------------------------------------------------------------------------------------------------
macro data.8.string name*, string* {
segment readable writeable
    name db string, 0
    name.length fix $ - string
segment readable executable
}

macro data.8.unit name*,unit* {
segment readable writeable
    name db unit
    name.lenght = 0
segment readable executable
}
