#include <Servo.h>
#include "pitches.h"
int xPin = A0, yPin = A1, sPin = 2, xVal, yVal, sVal;
int xSerPin=3, ySerPin=4, xSerVal, ySerVal;
int piezoPin= 5;
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
  // put your main code here, to run repeatedly:
  sVal = digitalRead(sPin);
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  Serial.print("Switch Value: ");
  Serial.print(sVal);
  Serial.print("\t\tX Value: ");
  Serial.print(xVal);
  Serial.print("\t\tY Value: ");
  Serial.println(yVal);
  xSerVal = map(xVal, 0, 1023, 0, 165);
  ySerVal = map(yVal, 0, 1023, 0, 165);
  xServo.write(xSerVal);
  yServo.write(ySerVal);
//  tone(piezoPin, 200);

}
