


//Declare Variable 
const int ledPin1 = 13; 
const int ledPin2 = 12; 
const int buttonPin1 = 2; 
const int buttonPin2 = 3; 

void setup() {
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop(){
 
  if (digitalRead(buttonPin1) == LOW) {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
  }


  if (digitalRead(buttonPin2) == LOW) {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
  }

}
