#include <Servo.h>
#include "pitches.h"
int notes[] = {
  NOTE_B0,
  NOTE_C1,
  NOTE_CS1,
  NOTE_D1,
  NOTE_DS1,
  NOTE_E1  ,
  NOTE_F1  ,
  NOTE_FS1 ,
  NOTE_G1 ,
  NOTE_GS1 ,
  NOTE_A1  ,
  NOTE_AS1 ,
  NOTE_B1  ,
  NOTE_C2  ,
  NOTE_CS2 ,
  NOTE_D2  ,
  NOTE_DS2 ,
  NOTE_E2  ,
  NOTE_F2  ,
  NOTE_FS2 ,
  NOTE_G2  ,
  NOTE_GS2 ,
  NOTE_A2  ,
  NOTE_AS2 ,
  NOTE_B2  ,
  NOTE_C3  ,
  NOTE_CS3 ,
  NOTE_D3  ,
  NOTE_DS3 ,
  NOTE_E3  ,
  NOTE_F3  ,
  NOTE_FS3 ,
  NOTE_G3  ,
  NOTE_GS3 ,
  NOTE_A3  ,
  NOTE_AS3 ,
  NOTE_B3  ,
  NOTE_C4  ,
  NOTE_CS4 ,
  NOTE_D4  ,
  NOTE_DS4 ,
  NOTE_E4  ,
  NOTE_F4  ,
  NOTE_FS4 ,
  NOTE_G4  ,
  NOTE_GS4 ,
  NOTE_A4  ,
  NOTE_AS4 ,
  NOTE_B4  ,
  NOTE_C5  ,
  NOTE_CS5 ,
  NOTE_D5  ,
  NOTE_DS5 ,
  NOTE_E5  ,
  NOTE_F5  ,
  NOTE_FS5 ,
  NOTE_G5  ,
  NOTE_GS5 ,
  NOTE_A5  ,
  NOTE_AS5 ,
  NOTE_B5  ,
  NOTE_C6  ,
  NOTE_CS6 ,
  NOTE_D6  ,
  NOTE_DS6 ,
  NOTE_E6  ,
  NOTE_F6  ,
  NOTE_FS6 ,
  NOTE_G6  ,
  NOTE_GS6 ,
  NOTE_A6  ,
  NOTE_AS6 ,
  NOTE_B6  ,
  NOTE_C7  ,
  NOTE_CS7 ,
  NOTE_D7  ,
  NOTE_DS7 ,
  NOTE_E7  ,
  NOTE_F7  ,
  NOTE_FS7 ,
  NOTE_G7  ,
  NOTE_GS7 ,
  NOTE_A7  ,
  NOTE_AS7 ,
  NOTE_B7  ,
  NOTE_C8  ,
  NOTE_CS8 ,
  NOTE_D8  ,
  NOTE_DS8 ,
};
int xPin = A0, yPin = A1, sPin = 2, xVal, yVal, sVal, dly = 100;
int xSerPin = 3, ySerPin = 4, xSerVal, ySerVal, minSerVal = 0, maxSerVal = 165;
int piezoPin = 5;
Servo xServo;
Servo yServo;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sPin, INPUT);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(piezoPin, OUTPUT);
  digitalWrite(sPin, HIGH); // Read without extra stuff. When you press down stuff happens
  xServo.attach(xSerPin);
  yServo.attach(ySerPin);
}

void loop() {
  //  // put your main code here, to run repeatedly:
  sVal = digitalRead(sPin);
  //  xVal = analogRead(xPin);
  //  yVal = analogRead(yPin);
  //  Serial.print("Switch Value: ");
  //  Serial.print(sVal);
  //  Serial.print("\t\tX Value: ");
  //  Serial.print(xVal);
  //  Serial.print("\t\tY Value: ");
  //  Serial.println(yVal);
  //  xSerVal = map(xVal, 0, 1023, minSerVal, maxSerVal);
  //  ySerVal = map(yVal, 0, 1023, minSerVal, maxSerVal);
  //  Serial.print("\nX Servo Value: ");
  //  Serial.print(xSerVal);
  //  Serial.print("\t\tY Servo Value: ");
  //  Serial.println(ySerVal);
  //  xServo.write(xSerVal);
  //  yServo.write(ySerVal);
  if (sVal == 0) {
    for (int i = 0; i <=sizeof(notes); i++) {
      tone(piezoPin, notes[i], 5);
      
      delay(5 * 1.3);
      noTone(piezoPin);
      Serial.println(i);
      delay(100);
    }
  }
  else {
    noTone(piezoPin);
  }
  //  //  tone(piezoPin, 200);
  //  delay(dly);

}
