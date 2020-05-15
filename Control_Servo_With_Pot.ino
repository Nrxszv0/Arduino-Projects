#include <Servo.h>
int serPin = 13, serAng, potPin=A0, potVal, dly=10;
Servo ser;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
ser.attach(serPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal=analogRead(potPin);
  serAng=map(potVal,0,1023,0,165);
  ser.write(serAng);
  delay(dly);
  

}
