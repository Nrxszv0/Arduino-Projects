#include <Stepper.h>
int stepsPerRevolution = 2048, motSpeed = 18 , dly = 200, motorDir = 1;
int sPin = 7, sState = 0, prevSState = 0;
int N1 = 8, N2 = 9, N3 = 10, N4 = 11;
Stepper stepMotor(stepsPerRevolution, N1, N3, N2, N4);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  stepMotor.setSpeed(motSpeed);
  pinMode(sPin , INPUT);
}

void loop() {
  sState = digitalRead(sPin);
  if (sState != prevSState) {
    if (sState == HIGH) {
      motorDir = !motorDir;
    }
  }
  if (motorDir == 1) {
    stepMotor.step(1);
  }
  else {
    stepMotor.step(-1);
  }
  Serial.println(motorDir);
  prevSState = sState;
}
