/*
 *Tyler Foster
 *Program #10
 *Blink LEDs
 *6/16/17
*/
#include "simpletools.h"                      // Include simple tools

int main() 
{    
while(1)
{                              // Main function
while(input(1) == 1)
  {
high(26);
low(27);
pause(100);
low(26);
high(27);
pause(100);
}
low(27);
low(26);
}
}
