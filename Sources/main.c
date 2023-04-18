#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */






void main(void) {
  /* put your own code here */
  
  DDRC = 0xFF;



  for(;;) {
  
  int i;
  for(i = 0; i < 10000; i++)
  {
      ;
  }
  
  PORTC ^= 0x01;
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}
