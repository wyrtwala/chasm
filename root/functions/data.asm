macro data-string name*, string* {
  name dq string, 0
  name.length equ $ - string
}
