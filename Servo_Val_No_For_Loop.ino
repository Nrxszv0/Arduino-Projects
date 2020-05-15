#include <Servo.h>
int servoPin = 13, serVal, dly = 500, maxVal = 160, minVal = 0;
bool t=true;
Servo ser;
String serMsg = "The degree of the servo is: " , msgD = "What should the delay be?", msgMx = "What should the maximum value be?", msgMn = "What should the minimum value be?";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ser.attach(servoPin);
}

void loop() {
  Serial.println(msgD);
  while (Serial.available() == 0) {

  }
  dly = Serial.parseInt();

  Serial.println(msgMn);
  while (Serial.available() == 0) {

  }
  minVal = Serial.parseInt();

  Serial.println(msgMx);
  while (Serial.available() == 0) {

  }
  maxVal = Serial.parseInt();
  while (t) {
    ser.write(minVal);
    delay(dly);
    ser.write(maxVal);
    delay(dly);
  }
}
