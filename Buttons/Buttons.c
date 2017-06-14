/*
 *Tyler Foster
 **Use a button to turn on and off a LED
 *Program #5 
 *6/14/17 
*/
#include "simpletools.h"                      // Include simple tools

int main()                                    // Main function
{
    // Add startup code here.

 
  while(1)
  {
    if ( input(0) == 0 )
    {
      putChar(HOME);
      print("The button is pressed %c\n",CLREOL);
      while (input(0) == 0)
      {
      low(27);
     high(26);
     pause(500);
     low(26);
     high(27);
     pause(500);
   }     
    }       
    else
    {
      putChar(HOME);
      print("The button is not pressed %c\n",CLREOL);
      while(input(0) == 1)
      {
      low(26);
      high(27);
      pause(100);
      low(27);
      high(26);
      pause(100);
    }      
   }     
    pause(100);
  }  
}
