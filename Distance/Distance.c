/*
 * Tyler Foster
 * Program #8
 * Measuring distance with an ultrasonic sensor
 * 6/15/17 
*/
#include "simpletools.h"

const int TRIGGER_PIN = 0;
const int ECHO_PIN = 1;

int main()
{
  long duration;
  long distance;
  
  low(TRIGGER_PIN);
  low(ECHO_PIN);
  pause(250);
 
  while(1)
  {
    pulse_out(TRIGGER_PIN, 10);
    duration = pulse_in(ECHO_PIN, 1);
    print("%c%c", HOME, CLREOL);
    distance = duration / 148;
    print("Distance = %d inches\n", distance);
    
    if (distance ==  9)
    {
     high(15);
     pause(250);
     low(15);
     pause(250); 
    }      
    else
    {
      low(15);
    }      
       if (distance == 8 )
    {
     high(15);
     pause(200);
     low(15);
     pause(200); 
    }      
    else
    {
      low(15);
    } 
     if (distance < 8)
    {
     high(15);
     pause(50);
     low(15);
     pause(50); 
    }      
    else
    {
      low(15);
    }           
    pause(250);
    
  }  
}