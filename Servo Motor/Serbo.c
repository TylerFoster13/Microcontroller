/*
  * Tyler Foster
  * Control a servo motor with two buttons
  * Program #7
  * 6/15/17
*/
#include "simpletools.h"                      // Include simple tools
#include "servo.h"

//Constants are names we use to make our program easier to program and maintain

const int RIGHT = 4;
const int LEFT = 3;
const int SERVO = 14;

// servo angles are shown times ten, ex. 90* = 900*
const int RSTOP = 1700;
const int LSTOP = 10;

int main()                                    // Main function
{
 
  int angle = 900;

 while(1)
 {
   // get pushbutton state
   if (input(LEFT) == 1)
   {
    angle =  angle - 18; 
   }     
   if (input(RIGHT) == 1)
   {
    angle = angle + 18; 
   } 
   // limit the angle of the servo
   if (angle> RSTOP)
   {
    angle = RSTOP ;
   }          
   if (angle < LSTOP)
   {
    angle = LSTOP ;
   }     
   // update the serial console (Screen output)
   print("%c angle = %d %c", HOME, angle, CLREOL);
   
   servo_angle(SERVO, angle);
   pause(25);
 }   // End of while loop
}
