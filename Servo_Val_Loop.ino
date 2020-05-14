#include <Servo.h>
int servoPin = 13, serVal, dly=10;
Servo ser;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
ser.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<=160; i++) {
    ser.write(i);
    delay(dly); 
  }

  for(int i=160; i>=0; i--) {
    ser.write(i);
    delay(dly); 
  }
}
