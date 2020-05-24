#include <Servo.h>
Servo kServo;
int servoPin = 10, rLED = 11, yLED = 12, gLED = 13, btnPin = 2, btnVal, piezoPin = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(rLED, OUTPUT);
  pinMode(yLED, OUTPUT);
  pinMode(gLED, OUTPUT);
  pinMode(piezoPin, INPUT);
  pinMode(btnPin, INPUT);
  kServo.attach(10);
}

void loop() {
  // put your main code here, to run repeatedly:

  kServo.write(0);

  digitalWrite(rLED, HIGH);
  digitalWrite(gLED, HIGH);
  digitalWrite(yLED, HIGH);

  btnVal = digitalRead(btnPin);
  Serial.println(btnVal);
}
