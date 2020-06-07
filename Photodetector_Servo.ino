#include <Servo.h>
int photoPin = A0, photoVal, serPin=8,serAng;
Servo servo;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(serPin);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  photoVal = analogRead(photoPin);
  Serial.println(photoVal);
  servo.write(165);
}
