#include <Stepper.h>
int stepsPerRevolution=2048, motSpeed=10, dly=200;
Stepper stepMotor(stepsPerRevolution, 8,10,9,11);
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
