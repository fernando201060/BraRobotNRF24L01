/*
---- Receiver Code ----
*/

#include <Servo.h>
#include <SPI.h>
#include "RF24.h"  


int positionC = 90;
int positionD = 90;
int positionY = 90;
int positionZ = 90;
Servo myServoC;
Servo myServoD;
Servo myServoY;
Servo myServoZ;
long previousMillis = 0;
long interval = 15;


int joystick[4];

RF24 radio(7,8);
const uint64_t pipe = 123456;

void setup()
{

  myServoC.attach(6);
  myServoD.attach(9);
  myServoY.attach(16);
  myServoZ.attach(17);
  
  radio.begin();
  radio.openReadingPipe(1, pipe);   
  radio.startListening();       
}

void loop()
{
  if(radio.available())
  {       
    bool done = false;      
    while (!done) {
      done = radio.read(joystick, sizeof(joystick) );

      unsigned long currentMillis = millis();
      if(currentMillis - previousMillis > interval)
      {
        previousMillis = currentMillis;

      
         {
          if(joystick[0] < 412 && positionC < 180)
          {
            positionC++;
            myServoC.write(positionC);
          }
          if(joystick[0] > 612 && positionC > 0)
          {
            positionC--;
            myServoC.write(positionC);
          }
          if(joystick[1] < 412 && positionD < 180)
          {
            positionD++;
            myServoD.write(positionD);
          }
          if(joystick[1] > 612 && positionD > 0)
          {
            positionD--;
            myServoD.write(positionD);
          }
        }

        {
          if(joystick[2] < 412 && positionY < 180)
          {
            positionY++;
            myServoY.write(positionY);
          }
          if(joystick[2] > 612 && positionY > 0)
          {
            positionY--;
            myServoY.write(positionY);            
          }
          if(joystick[3] < 412 && positionZ < 180)
          {
            positionZ++;
            myServoZ.write(positionZ);
          }
          if(joystick[3] > 612 && positionZ > 0)
          {
            positionZ--;
            myServoZ.write(positionZ);
          }
        }
        
      }          
    }
  }
}
