/*Program Name: Blink
 *This program prompts the led to make and SOS call through blinking lights
 * SETUP: 
   Things you need:
   1) LED pin
   2) 4 wires
   3) Arduino Board and Breadboard
   4) Power Supply
   5) USB Wire
   
 * January 30,2023
 * Student Name: Ian Jericho Pedeglorio 
   Student Number: 200450851
*/



//start of program

int led = 13;              //Declare led output to pin 13 adn store it to variable "led"
int enddelay = 300;        //end delay for every letter (3 units of time)
int dlay = 100;            //end delay for every dot (1 unit of time)
int loopdelay = 700;       //end delay before starting the loop again (7 units of time)
int sdelay = 300;          //delay for the dashes in letter "O"

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin led as an output.
  pinMode(led, OUTPUT);
}

//loop function for " S O S "
//A unit of time is in hundreds e.g 100 = 1 unit, 300 = 3 units
void loop() {
  //Letter S
  digitalWrite(led, HIGH);    //HIGH means the LED is turned on
  delay(dlay);                 //hold light for 1 unit of time           
  digitalWrite(led, LOW);     //Low means the LED is turned off
  delay(dlay);                 //delay light for 1 unit of time
  digitalWrite(led, HIGH);
  delay(dlay);
  digitalWrite(led, LOW);    
  delay(dlay); 
  digitalWrite(led, HIGH);    
  delay(dlay); 
  digitalWrite(led, LOW);   
  delay(enddelay);                 // delay by 3 units of time before starting O
  
  // Letter O
  digitalWrite(led, HIGH);
  delay(sdelay);
  digitalWrite(led, LOW); 
  delay(dlay);
  digitalWrite(led, HIGH); 
  delay(sdelay);
  digitalWrite(led, LOW); 
  delay(dlay);
  digitalWrite(led, HIGH); 
  delay(sdelay);
  digitalWrite(led, LOW); 
  delay(enddelay);                 // delay 3 units of time before starting S
  
  //Letter S
  digitalWrite(led, HIGH);  
  delay(dlay);                   
  digitalWrite(led, LOW);   
  delay(dlay); 
  digitalWrite(led, HIGH);
  delay(dlay);
  digitalWrite(led, LOW);    
  delay(dlay); 
  digitalWrite(led, HIGH);    
  delay(dlay); 
  digitalWrite(led, LOW);    
  delay(loopdelay);                 //delay 7 units of time before starting the loop again

}
//end of program
