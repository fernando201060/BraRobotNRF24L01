/*
---- Transmitter Code ----
*/

#include <SPI.h>
#include "RF24.h"

int joystick[6];

RF24 radio(7,8);                   
                                      
const uint64_t pipe = 123456;

void setup(void)
{
  radio.begin();
  radio.openWritingPipe(pipe);
 
}

void loop(void)
{
  joystick[0] = analogRead(0); // Horizontal esquerdo 
  joystick[1] = analogRead(1); // Vertical esquerdo 
  joystick[2] = analogRead(2); // Horizontal direito
  joystick[3] = analogRead(3); // Vertical direito
  
  radio.write(joystick, sizeof(joystick) );
}
