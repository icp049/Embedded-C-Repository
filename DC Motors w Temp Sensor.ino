/*Program Name: Motors
   This program turns on/off a DC motor by using a temperature reading from a temperature sensor to conttrol it.
   It prints the temperature readings in Celsius and Farenheit. The serial monotor also tells if motor is ON or OFF
   
   SETUP:
   Things you need:
   Arduino
   Breadboard
   USB Cable
   1 small electric motor
   1 2.2kΩ resistor
   1 1N4001 diode or equivalent
   1 temperature sensor
   1 transistor
   6+ jumper wires

   March 6,2023
   Student Name: Ian Jericho Pedeglorio
   Student Number: 200450851
*/

//start of program

//Declare variables and pins associated with them
const int tmpPin = A1;
const int motorPin = 11;

void setup() {
  Serial.begin(9600);                                         //Initialize serial monitor
  pinMode(motorPin, OUTPUT);                                  //motorPin is the output (motor running)
  Serial.println("Temperature(C)\tTemperature(F)\tMotor");    //Print a header in serial monitor
}

void loop() {
  float voltage = AnalogtoVolts();                            //Call AnalogtoVolts function for voltage
  float temperature = getCTemperature(voltage);               //Call getCtemperature function with voltage as a parameter for the temperature conversion from volts toc celsius
  getFTemperature(temperature);                               //Call getFtemperature using temperature parameter which has the Celcius temperature
  controlMotor(temperature);                                  //Call controlMotor function with temperature parameter as it runs based on temperature
  delay(1000);
}

float AnalogtoVolts() {                                       //function that converts analog to volts
  int sensorValue = analogRead(tmpPin);                       //Store the reading from the temperature sensor to variable SensorValue
  float voltage = (sensorValue / 1023.0) * 5.0;               //Convert the stored amount to voltage

  return voltage;                                             //return voltage
}



float getCTemperature(float voltage) {                        //function that converts the volts to celsius

  float Ctemperature = (voltage - 0.5) * 100.0;               //Formula for voltage to celsius

  Serial.print(Ctemperature);                                 //Print converted celsius value in serial monitor
  Serial.print("\t\t");                                       //tabular data spacer in serial monitor

  return Ctemperature;                                        //Return Celsius


}
 
float getFTemperature(float Ctemperature) {                   //function that converts celsius to volts
  float Ftemperature = (Ctemperature * 1.8) + 32;             //formula for celsius to farenheit
 
  Serial.print(Ftemperature);                                 //Print converted farenheit value in serial monitor
  Serial.print("\t\t");                                       //tabular data spacer in serial monitor

  return Ftemperature;                                        //return farenheit


}

void controlMotor(float temperature) {                        //function that controls the motor based on temperature thresold 
  if (temperature >= 25) {                                    //if the temperature is more or equal than 25, start the motor
    analogWrite(motorPin, 100);                               //I placed 100 instead of high for precision
    Serial.println("On");                                     //Serial monitor tells the motor is ON
  } else {
    analogWrite(motorPin, 0);                                 //O means motor turned off
    Serial.println("Off");                                    //Serial monitor tells the motor is ON
  }

}
//end of program
