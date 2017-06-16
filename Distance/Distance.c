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
    pause(250);
  }  
}