#include <Servo.h>

Servo myservo;  // create servo object to control a servo
                // a maximum of eight servo objects can be created

int pos = 0;    // variable to store the servo position

void setup()
{
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop()
{
  int angle = 90;
  for (angle = 90; angle >= 0; angle -= 10)
  {
    // goes from 0 degrees to 180 degrees and back to 0 degrees
    for (pos = 90 - angle; pos <= 90 + angle; pos++)
    {
      myservo.write(pos);  // tell servo to go to position in variable 'pos'
      delay(10);           // waits 10ms for the servo to reach the position
    }
    
    for (pos = 90 + angle; pos >= 90 - angle; pos--)
    {
      myservo.write(pos);  // tell servo to go to position in variable 'pos'
      delay(10);           // waits 10ms for the servo to reach the position
    }
  }
  delay(2000);
}


//servo motor program
