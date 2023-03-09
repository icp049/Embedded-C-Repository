#include <TFT.h>  // Arduino LCD library
#include <SPI.h>
  // pin definition for the Uno/nano
  #define cs   10
  #define dc   9
  #define rst  8
  // create an instance of the library
  TFT TFTscreen = TFT(cs, dc, rst);
  // char array to print to the screen
  char rc_Printout[4];
  
void setup() 
{ 
  servo.attach(6);  //D6 pin as Servo signal
  pinMode( 2, OUTPUT );
  pinMode( 3, INPUT );
  Serial.begin( 9600 );

  TFTscreen.begin();
  TFTscreen.background(0, 0, 0);
} 
 
void loop() 
{ 
 int r_beam = 100; //D6 pin as Servo signal
 TFTscreen.stroke(255, 255, 255);
 TFTscreen.circle(80,128,r_beam+2);
 TFTscreen.setTextSize(2);
 TFTscreen.text("Dist(cm)", 0, 0);

//Right rotation  
for (int i=0;i<180;i=i+1){
  servo.write(i);
  measure_dist();
  Serial.print(i);
  Serial.print("\n");
  delay(20);

  int r = distance*2;
  String r_Printout = String(r/2);

  TFTscreen.stroke(0, 0, 0);
  TFTscreen.setTextSize(2);
  TFTscreen.text(rc_Printout, 100, 0);
  
  r_Printout.toCharArray(rc_Printout, 4); 
  TFTscreen.stroke(255, 255, 255);
  TFTscreen.setTextSize(2);
  TFTscreen.text(rc_Printout, 100, 0);
  
  TFTscreen.stroke(70, 70, 70);
  TFTscreen.line(80,128,80+r_beam*cos((360-i)*3.14/180), 128+r_beam*sin((360-i)*3.14/180));
  TFTscreen.stroke(0, 255, 0);
  TFTscreen.circle(80+r*cos((360-i)*3.14/180), 128+r*sin((360-i)*3.14/180), 2);
  }
    TFTscreen.background(0, 0, 0);
    
 TFTscreen.stroke(255, 255, 255);
 TFTscreen.circle(80,128,r_beam+2);
 TFTscreen.setTextSize(2);
 TFTscreen.text("Dist(cm)", 0, 0);

//Left rotation  
for (int i=180;i>0;i=i-1){
  servo.write(i);
  measure_dist();
  Serial.print(i);
  Serial.print("\n");
  delay(20);

  int r = distance*2;
  String r_Printout = String(r/2);

  TFTscreen.stroke(0, 0, 0);
  TFTscreen.setTextSize(2);
  TFTscreen.text(rc_Printout, 100, 0);

  r_Printout.toCharArray(rc_Printout, 4);

  TFTscreen.stroke(255, 255, 255);
  TFTscreen.setTextSize(2);
  TFTscreen.text(rc_Printout, 100, 0);

  TFTscreen.stroke(70, 70, 70);
  TFTscreen.line(80,128,80+r_beam*cos((360-i)*3.14/180), 128+r_beam*sin((360-i)*3.14/180));
  TFTscreen.stroke(0, 255, 0);
  TFTscreen.circle(80+r*cos((360-i)*3.14/180), 128+r*sin((360-i)*3.14/180), 2);
  }
    TFTscreen.background(0, 0, 0);  
}

void measure_dist()
{ 
  Serial.read();
  // pulse !
  digitalWrite( 2, HIGH );
  delayMicroseconds( 100 );
  digitalWrite( 2, LOW );
  // mesure the interval 
  interval = pulseIn( 3, HIGH );
  distance = interval * 0.017; // cm 
  Serial.print( interval, DEC );
  Serial.print( "\t" );
  Serial.print( distance, 1 );
  Serial.print( "\n" );
}
