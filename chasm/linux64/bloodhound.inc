ifndef bloodhound.inc
define bloodhound.inc

section .data ;check syntax

..bloodhound:
.pointer dq ? 
.pointer.count dq ?
.allocated dq ?
.allocated.count dq ?

section .text

..bloodhound.track:  ;check syntax
  push ebp
  move ebp, esp


  move esp, ebp
  pop ebp
  ret


..bloodhound.release: 
  push ebp
  move ebp, esp

  move esp, ebp
  pop ebp
  ret    


endif
