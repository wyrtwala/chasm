macro data name*, string* {
  if used name
    name dq string, 0
    name.length equ $-string
  end if
}
