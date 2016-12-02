#include <msp430g2231.h>

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;         //Stop watchdog timer
  P1DIR |= 0xF7;                    //All P1 pins as out but P1.3
  P1REN |= 0x08;                    //P1.3 Resistor enabled
  P1OUT |= 0x08;                    //P1.3 Resistor as pull.up
  P1IES |= 0x08;                    //P1.3 Hi->Lo edge selected
  P1IFG &= 0x08;                    //P1.3 Clear any pendig PP1.3 IRQ
  P1IE  |= 0x08;                    //P1.3 interrupt enabled

  __bis_SR_register(LPM4_bits + GIE); // Enter LPM4 w/GIE enabled
}

//Port 1 interrupt service routine
#pragma vector = PORT1_VECTOR     // Port 1 vector configured
__interrupt void Poert_1(void)    //The ISR code
{
  P1OUT ^= 0x04;                  // Toggle LED in P1.2
  P1IFG &= ~0x08;                 // Clear P1.3 IFG
}
