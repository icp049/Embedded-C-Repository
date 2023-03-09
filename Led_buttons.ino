/*Program Name: Buttons
  This program turns on the led lights with the use of buttons.
  Button 1 will turn on led 1 while button 2 will turn on led 2.
  If button 1 is pressed and led 1 is turned on, led 2 should be turned off
  and vice versa. The lights should alternate in turning on and off as the buttons
  are pressed.

   SETUP:
   Things you need:
   1) 2 LED pins
   2) 2 buttons
   3) 2 10kΩ resistors
   4) 2 560Ω resistors
   5) 12 wires
   6) Arduino UNO and Breadboard
   7) USB Wire

   February 13,2023
   Student Name: Ian Jericho Pedeglorio
   Student Number: 200450851
*/

//start of program
//declare the varibles and pins that will be used

const int photoR = A3;
const int ledPin = 5;
const int thrs = 700;

void setup() {

  pinMode(photoR, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  int sensorVal = analogRead(photoR);
  if (sensorVal < thrs) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  Serial.println(sensorVal);

}
//end of program
