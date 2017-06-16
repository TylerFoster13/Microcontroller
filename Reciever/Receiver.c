/*
 *Tyler Foster
 *Program #9
 *Recieve text over wireless radio
 *6/16/17
*/
#include "simpletools.h"                      // Include simple tools
#include "fdserial.h"

void init_radio(fdserial*radio);

int main()                                    // Main function
{  
  // Add startup code here.

    char c = '?';
    fdserial *xbee;
    
    //Check to make sure the sender program is running on another board
    print("This board will recieve messages via wireless.\n");
    pause(2000);
    print("You MUST start the other program on the other \nboard first.\n");
    while(c != 'Y')
    {
      print("Is the other end started?" );
      scan ("%c", &c);
      
   }     
   print("\n");
    
    //open a serial connection to the xbee radio
    xbee = fdserial_open(0, 1, 0, 9600);
    init_radio(xbee);
    
     // Clear the sender's screen and tell them it is OK to start typing
     fdserial_txChar(xbee, CLS);
     dprint(xbee, "Connnection established!\n");
     dprint(xbee, "Click on this screen and type your message.\n");
    
 
 // get a character from the radio and print it on the screen
  while(1)
  { 
   c = fdserial_rxChar(xbee);
   if (c != 255)
   {
     print("%c", c);
   }       
  }  
}

void init_radio(fdserial*radio)
{
  const char channel = 'D';        // 0x0B to 0x1A, must match your partner
  const char PAN_ID[]= "BEEF";    //0x0 to 0xFFFF, must match your partner
  const char DEST_ID[]= "0001";   //0x0 to oxFFFF must be your partner's SRC_ID
  const char SRC_ID[]= "0002";     //oxo to 0xFFFF, Must be your partner's DEST_ID
  
  char result [32] = {0};
  
  dprint(radio, "+++");
  pause(50);
  dscan(radio,"%s", &result);
  print("Radio Initialization: %s\n",result);
  pause(50);
  
  dprint(radio, "ATRE\n");
  dprint(radio, "ATCH%c\n", channel);
  dprint(radio, "ATID%s\n", PAN_ID);
  dprint(radio, "ATDL%s\n", DEST_ID);
  dprint(radio, "ATMY%s\n",SRC_ID);
  dprint(radio, "ATAC\n");
  dprint(radio, "ATCN\n");
  pause(500);
  print("\n");  
}  