#include <Servo.h>
int photoPin = A0, photoVal, serPin=8,serAng, dly=50;
int maxSerAng=165, minSerAng=0, maxPhotoVal=830, minPhotoVal=150;
Servo servo;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(serPin);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  photoVal = analogRead(photoPin);
  //serAng = map(photoVal, minPhotoVal,maxPhotoVal, minSerAng, maxSerAng);
  serAng = map(photoVal, maxPhotoVal,minPhotoVal, minSerAng, maxSerAng);
  Serial.println(serAng);
  //Serial.println(photoVal);
  servo.write(serAng);
  delay(dly);
}
