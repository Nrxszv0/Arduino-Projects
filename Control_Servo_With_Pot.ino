#include <Servo.h>
int serPin = 13, serAng, potPin=A0, potVal, dly=10;
Servo ser;
String msgPV="Potentiometer Value: ", msgSA=", Servo Angle: ";
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
ser.attach(serPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal=analogRead(potPin);
  Serial.print(msgPV);
  Serial.print(potVal);
  serAng=map(potVal,0,1023,0,165);
  Serial.print(msgSA);
  Serial.println(serAng);
  ser.write(serAng);
  delay(dly);
}
