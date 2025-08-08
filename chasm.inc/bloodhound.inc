.ifndef bloodhound.inc
.define bloodhound.inc

.data

bloodhound.pointer:
  .octa ? 
bloodhound.pointer.count:
  .octa ?
bloodhound.allocated:
  .octa ?
bloodhound.allocated.count:
  .octa ?

.text

bloodhound.track:
  push ebp
  move ebp, esp


  move esp, ebp
  pop ebp
  ret


bloodhound.release: 
  push ebp
  move ebp, esp

  move esp, ebp
  pop ebp
  ret    


.endif
