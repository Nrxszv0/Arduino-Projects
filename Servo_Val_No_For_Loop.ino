#include <Servo.h>
int servoPin = 13, serVal, dly = 500, maxVal = 160, minVal = 0;
Servo ser;
String serMsg = "The degree of the servo is: ";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ser.attach(servoPin);
}

void loop() {
  ser.write(minVal);
  delay(dly);
  ser.write(maxVal);
  delay(dly);


}
