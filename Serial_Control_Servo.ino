#include <Servo.h>
int servoPin=13;
int servoPos;
Servo servo;
String msg="What should the servo's position be?";

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
servo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg);
  while(Serial.available()==0) {
    
  }
  servoPos=Serial.parseInt();
  servo.write(servoPos);

}
