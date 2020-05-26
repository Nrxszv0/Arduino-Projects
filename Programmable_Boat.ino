#include <Servo.h>
int contPin1 = 2, contPin2 = 10, enablePin = 11, directionBtnPin = 12, powerStateBtnPin = 13, potPin = A1, powerBtnState = 0, prevPowerBtnState = 0, directionBtnState = 0, prevDirectionBtnState = 0, motorEnabled = 0, motorSpeed = 0, motorDirection = 1, servoPin=9, serAng;
Servo servo;
void setup() {
  pinMode(directionBtnPin, INPUT);
  pinMode(powerStateBtnPin, INPUT);
  pinMode(contPin1, OUTPUT);
  pinMode(contPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  servo.attach(servoPin);
  digitalWrite(enablePin, LOW);
}

void loop() {
  servo.write(13);
  powerBtnState = digitalRead(powerStateBtnPin);
  delay(1);
  directionBtnState = digitalRead(directionBtnPin);
  motorSpeed = analogRead(potPin) / 4;
  if (powerBtnState != prevPowerBtnState) {
    if (powerBtnState == HIGH) {
      motorEnabled = !motorEnabled;
    }
  }
  if (directionBtnState != prevDirectionBtnState) {
    if (directionBtnState == HIGH) {
      motorDirection = ! motorDirection;
    }
  }
  if (motorDirection == 1) {
    digitalWrite(contPin1, HIGH);
    digitalWrite(contPin2, LOW);
  }
  else {
    digitalWrite(contPin1, LOW);
    digitalWrite(contPin2, HIGH);
  }
  if (motorEnabled == 1) {
    analogWrite(enablePin, motorSpeed);
  }
  else {
    analogWrite(enablePin, 0);
  }
  prevDirectionBtnState = directionBtnState;
  prevPowerBtnState = powerBtnState;
}
