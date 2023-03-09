/*Program Name: Sensors
  This program turns on the led light with the use of a sensor (photoresistor).
  The aim of this lab is to create a night light that turns on during dark.
  Led light turns on when the sensor detects darkness at a certain thresold and turns back off in the light.

   SETUP:
   
   1)Arduino
   2)Breadboard
   3)USB Cable
   4)LED
   5)photoresistor
   6)2 resistors of your choice (one for the LED, the other for the photoresistor)
   7)>=5 jumper wires
   8)Danger Shield (we will provide one)

   February 13 ,2023
   Student Name: Ian Jericho Pedeglorio
   Student Number: 200450851
*/

//start of program
//declare the varibles and pins that will be used

const int photoR = A3;
const int ledPin = 5;
const int thrs = 700;

void setup() {

  pinMode(photoR, INPUT);         //Photoresistor will be an input
  pinMode(ledPin, OUTPUT);        //Led will turn on based on input value from photoresistor
  Serial.begin(9600);             //Initiate Serial Monitor
}

void loop() {

  int sensorVal = analogRead(photoR);               //Read the value from the photoresistor and store in variable sensorVal
  if (sensorVal < thrs) {                           
    digitalWrite(ledPin, HIGH);                     //if the value from the sensor exceeds the thresold of "700", turn on the led
  } else {
    digitalWrite(ledPin, LOW);                      //otherwise, turn it off
  }

  Serial.println(sensorVal);                        //print the value of the sensor in the serial monitor

}
//end of program
