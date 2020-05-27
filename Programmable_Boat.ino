#include <Servo.h>
int contPin1 = 4, contPin2 = 3, enablePin = 5, directionBtnPin = 12, powerStateBtnPin = 13, potPin = A0;
int powerBtnState = 0, prevPowerBtnState = 0, directionBtnState = 0, prevDirectionBtnState = 0, motorEnabled = 0, motorSpeed = 0, motorDirection = 1;
int servoPin = 2, serAng, serPotPin = A5, serPotVal, maxSerAng = 165, startSerVal = 0, minSerAng=0;
Servo servo;
void setup() {
  Serial.begin(9600);
  pinMode(directionBtnPin, INPUT);
  pinMode(powerStateBtnPin, INPUT);
  pinMode(contPin1, OUTPUT);
  pinMode(contPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  servo.attach(servoPin);
  digitalWrite(enablePin, LOW);
  servo.write(startSerVal);
}

void loop() {
  serPotVal = analogRead(serPotPin);
  serAng = map(serPotVal, 0, 1023, minSerAng, maxSerAng);
  servo.write(serAng);
  Serial.println(serAng);  
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
