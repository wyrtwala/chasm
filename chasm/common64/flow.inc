    macro goif op1,cond,op2,label {
        cmp op1,op2
        j#cond label
     }

     macro goto label {
       jmp label
     }
