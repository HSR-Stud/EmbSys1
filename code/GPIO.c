;========================================================================
; Addresses PxDir and PxDat are assumed declared in header file
; Assumes Dir = 1 for In
;------------------------------------------------------------------------
#include "headers.h"
;------------------------------------------------------------------------
            ...
            AND #0FEh,&PxDir        ; Set Px.0 bit 0 as input (FEh=11111110b)
            OR #002h,&PxDir         ; Set Px.1 as output (02h=00000010b)
            AND #0FDh,&PxDat        ; Begin with D1 off
            ...
loop_low    TEST #001h,&PxDat       ; Check the value of Px.0
            JNZ loop_low            ; If set, continue to poll Px.0
            XOR #002,&PxDat         ; Otherwise, toggle Px.1
loop_high   TEST #001,&PxDat        ; Check if SW1 was released
            JZ loop_high
            JMP loop_low            ; When released go back to poll depress
            END
;========================================================================
