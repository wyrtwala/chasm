format ELF64 executable 3

include 'chasm/linux64/registers.inc'
include 'chasm/linux64/data.inc'
include 'chasm/linux64/subroutinea.inc'
include 'chasm/linux64/heap.inc'
include 'chasm/linux64/bloodhound.inc'
include 'chasm/linux64/io.inc'
include 'chasm/linux64/ascii.inc'
include 'chasm/linux64/convertions.inc'
include 'chasm/linux64/networking.inc'
include 'chasm/linux64/logging.inc'
include 'chasm/linux64/errors.inc'
include 'chasm/linux64/threads.inc'
include 'chasm/linux64/utf8.inc'

global main
chasm.start fix main:

postpone {
  mov rax, 60
  mov rdi, 0
  syscall
}

segment readable executable

macro starter {
  if used main {
  ;-----------------------  
  } else {
    main:
  }
}
starter
