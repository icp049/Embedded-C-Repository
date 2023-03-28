#include <EEPROM.h>

const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;
const int buttonPin = 12;
const int eepromAddress = 0;

float hue = 0, s = 1, v = 1;
float r,g,b;

float curButton = HIGH;
float lastButton = HIGH;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
  
  // read hue from EEPROM and set it
  int storedHue;
   EEPROM.get(eepromAddress, storedHue);
  if (storedHue >= 0 && storedHue <= 359) {
    hue = storedHue;
  }
  
  // convert hue to RGB and set LED color
  hsv2rgb(hue, s, v, r, g, b);
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}

void loop()
{
  lastButton = curButton;
  curButton = digitalRead(buttonPin);
  
  if (curButton == LOW) {
    hue++;
    if (hue < 0 || hue > 359) {
      hue = 0;
    }
  }
  
  if (curButton == HIGH && lastButton == LOW) {
    // button released, store hue in EEPROM
    EEPROM.put(eepromAddress, (int)hue);
    
  }
    
  // convert hue to RGB and set LED color
  hsv2rgb(hue, s, v, r, g, b);
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
  
  delay(10);
}

void hsv2rgb(float h, float s, float v, float &r, float &g, float &b)
{
  v = constrain(v, 0, 1);
  s = constrain(s, 0, 1);
  float c = v*s;
  float hprime = h/60.0f;
  float x = c * ( 1 - abs(hprime - ((int)hprime/2)*2 - 1));
  
  if (h < 0 || h > 360)
  {
    r = g = b = 0;
  }
  else if ( 0 <= hprime && hprime < 1)
  {
    r = c;
    g = x;
    b = 0;
  }
    else if ( 1 <= hprime && hprime < 2)
  {
    r = x;
    g = c;
    b = 0;
  }
    else if ( 2 <= hprime && hprime < 3)
  {
    r = 0;
    g = c;
    b = x;
  }
    else if ( 3 <= hprime && hprime < 4)
  {
    r = 0;
    g = x;
    b = c;
  }
    else if ( 4 <= hprime && hprime < 5)
  {
    r = x;
    g = 0;
    b = c;
  }
    else if ( 5 <= hprime && hprime < 6)
  {
    r = c;
    g = 0;
    b = x;
  }
  
  float m = v - c;
  r += m;
  g += m;
  b += m;
  r *= 255;
  g *= 255;
  b *= 255;
}
