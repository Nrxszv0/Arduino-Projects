#include <Servo.h>
int contPin1 = 4, contPin2 = 3, enablePin = 5, directionBtnPin = 12, powerStateBtnPin = 13;
int motorSpeedBtn1 = 8, motorSpeedBtn2 = 9, motorSpeedBtn3 = 10, motorSpeedBtn4 = 11;
int speedVal1 = 64, speedVal2 = 128, speedVal3 = 192, speedVal4 = 255;
int powerBtnState = 0, prevPowerBtnState = 0, directionBtnState = 0, prevDirectionBtnState = 0, motorEnabled = 0,  motorDirection = 1;
float motorSpeed = 0;
int servoPin = 2, serAng, serPotPin = A5, serPotVal, maxSerAng = 165, startSerVal = 0, minSerAng = 0;
Servo servo;
void setup() {
  Serial.begin(9600);
  pinMode(directionBtnPin, INPUT);
  pinMode(powerStateBtnPin, INPUT);
  pinMode(contPin1, OUTPUT);
  pinMode(contPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(motorSpeedBtn1, INPUT);
  pinMode(motorSpeedBtn2, INPUT);
  pinMode(motorSpeedBtn3, INPUT);
  pinMode(motorSpeedBtn4, INPUT);
  servo.attach(servoPin);
  digitalWrite(enablePin, LOW);
  servo.write(startSerVal);
}

void loop() {
  if (digitalRead(motorSpeedBtn1) == HIGH) {
    Serial.println("Button 1 Pressed");
    motorSpeed = speedVal1;
  }
  else if ( digitalRead(motorSpeedBtn2) == HIGH) {
    Serial.println("Button 2 Pressed");
    motorSpeed =  speedVal2;
  }
  else if ( digitalRead(motorSpeedBtn3) == HIGH) {
    Serial.println("Button 3 Pressed");
    motorSpeed =  speedVal3;
  }
  else if ( digitalRead(motorSpeedBtn4) == HIGH) {
    Serial.println("Button 4 Pressed");
    motorSpeed =  speedVal4;
  }
  serPotVal = analogRead(serPotPin);
  serAng = map(serPotVal, 0, 1023, minSerAng, maxSerAng);
  servo.write(serAng);
  Serial.println(serAng);
  powerBtnState = digitalRead(powerStateBtnPin);
  delay(1);
  directionBtnState = digitalRead(directionBtnPin);
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
