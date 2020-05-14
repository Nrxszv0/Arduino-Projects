#include <Servo.h>
int servoPin=13;
int servoPos=165;
Servo servo;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
servo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  servo.write(servoPos);

}
