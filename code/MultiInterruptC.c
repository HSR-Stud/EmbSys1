//==========================================================================
// Multi source Interrupt Service routine for four events
// Assumes FlagReg contains prioritized, encoded IRQ flags organized as:
// 0000 - No IRQ 0004 - Event2 0008 - Event4
// 0002 - Event 1 0006 - Event3
//--------------------------------------------------------------------------
#include <headers.h> ; Header file for target MCU
... ; Preliminary declarations and code
// Multi-source ISR
#pragma vector = MultiSrc_VECTOR _ _interrupt void MultiSrc_ISR(void) {
switch(_ _even_in_range(FlagReq,8)) {
case 0x00:     // Vector 0: No interrupts
break;
case 0x02: ... // Vector 2: Event1
break;
case 0x04: ... // Vector 4: Event2
break;
case 0x06: ... // Vector 6: Event3
break;
case 0x08: ... // Vector 8: Event4
break;
default: break;
}
}
