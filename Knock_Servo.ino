#include <Servo.h>
Servo kServo;
int servoPin=10, rLED=11, yLED=12, gLED=13, btnPin=2, piezoPin=A0;

void setup() {
  // put your setup code here, to run once:
pinMode(rLED, OUTPUT);
pinMode(yLED, OUTPUT);
pinMode(gLED, OUTPUT);
pinMode(piezoPin, INPUT);
pinMode(btnPin, INPUT);
kServo.attach(10);
}

void loop() {
  // put your main code here, to run repeatedly:
//for(int i=0; i<160; i=i+5){
//  kServo.write(i);
//  delay(100);
//}
kServo.write(0);
}
