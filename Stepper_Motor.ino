#include <Stepper.h>
int stepsPerRevolution = 2048, motSpeed = 18 , dly = 200;
int N1 = 8, N2 = 9, N3 = 10, N4 = 11;
Stepper stepMotor(stepsPerRevolution, N1, N3, N2, N4);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  stepMotor.setSpeed(motSpeed);
}

void loop() {
  stepMotor.step(stepsPerRevolution);
  delay(dly);
  stepMotor.step(-stepsPerRevolution);
  delay(dly);
}
