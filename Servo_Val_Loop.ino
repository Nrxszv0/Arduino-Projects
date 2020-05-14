#include <Servo.h>
int servoPin = 13, serVal, dly = 100, increment = 40;
boolean t = true;
Servo ser;
String serMsg = "The degree of the servo is: ", msg = "What do you want the delay to be?" ,msg2 = "What do you want the increment to be?";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ser.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg);
  while (Serial.available() == 0) {

  }
  dly = Serial.parseInt();

  Serial.println(msg2);
  while (Serial.available() == 0) {

  }
  increment = Serial.parseInt();
  while (t) {
    for (int i = 0; i <= 160; i = i + increment) {

      ser.write(i);
      Serial.print(serMsg);
      Serial.println(i);
      delay(dly);
    }

    for (int i = 160; i >= 0; i = i - increment) {
      ser.write(i);
      Serial.print(serMsg);
      Serial.println(i);
      delay(dly);
    }
  }
}
