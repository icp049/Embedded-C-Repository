/*Program Name: Sensors

   This program measures the value in the sensor using the analog pin.
   The value is monitored in the serial monitor and must concide with the voltage measurements in the multimeter

   SETUP: 
   1)Arduino
   2)Breadboard
   3)USB Cable
   4)560Ω resistor
   5)10kΩ resistor
   6)2.2kΩ resistor
   7)>=3 jumper wires
   8)Multimeter

   February 13 ,2023
   Student Name: Ian Jericho Pedeglorio
   Student Number: 200450851
*/

//start of program
//declare the varibles and pins that will be used

const float aRead = A1;


void setup() {
 
  pinMode(aRead, INPUT);   //read input from A1
  Serial.begin(9600);      //initiate serial monitor
}

void loop() {
  

  float pot_value = analogRead(aRead) / 1023.0 * 5.0;  //formula to get the voltage measurements in decimal form

  Serial.println(pot_value);                           //print values in serial monitor
}
//end of program
