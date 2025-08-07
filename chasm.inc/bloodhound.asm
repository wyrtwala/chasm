ifndef bloodhound.h
define bloodhound.h

segment readable executable
bloodhound:
  .trail dq ?                 ;pointer to tracks

segment readable writeable
bloodhound.point:
  ret
bloodhound.release: 
  ret    
endif
