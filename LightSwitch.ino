/*
 * Name: Ian Jericho Pedeglorio
 * Student #: 200450851
 * Assignment 2 
 */


//variables used for the program
//constant variables are declared according to PINS in arduino
//states are declared by 1 and 0
//time is declared in millis
const int ledPin = 13;
const int buttonPin = 3; 
int lastButtonState = 0;
int ledState = 0;
int debounceDuration = 50; 
unsigned long previousButtonTime = 0; 


void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); //use INPUT_PULLUP to avoid floating 
}
void loop() {
  if (millis() - previousButtonTime > debounceDuration) {          //If time of previous button state change is greater that 50 milliseconds, read the current state of the button
    int buttonState = digitalRead(buttonPin);                      
    if (buttonState != lastButtonState) {                          //Current state should be different from last state e.g on and off
      previousButtonTime = millis();                               
      lastButtonState = buttonState;                               //Store current buttonstate to previous state for next loop
      if (buttonState == 0) {                                      
        if(ledState == 1){                                         //if button is not pressed and led is on, it turns off, otherwise, it is turned on.
          ledState = LOW;
        }
        else{
          ledState = HIGH;
        }
        digitalWrite(ledPin, ledState);                           //led turns on and off depending on state of led
      }
    }
  }
}

//end of program
