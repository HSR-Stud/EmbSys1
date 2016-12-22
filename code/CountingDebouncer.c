;========================================================================
; Timer service routine for debouncing a switch closure (Closed = Low)
; Global variables "S_Count" and "EdgeOK" initialized to FFFFh and FALSE
;------------------------------------------------------------------------
Timer_ISR   BIT.B #SW1,&PxDat   ; Load switch status into carry flag (C)
            JC Bouncing         ; If high then contact was found open
            RLC.W &S_Count      ; Valid contact state detected & counted
            CMP #F000h,&S_Count ; Is it the 12th steady sample?
            JNZ Exit            ; Valid closure but not there yet
            MOV.B #TRUE,&EdgeOK ; Count top reached
Bouncing    MOV #FFFFh,&S_Count ; Restart counter
Exit        RETI
;========================================================================
