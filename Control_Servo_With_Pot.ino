#include <Servo.h>
int serPin = 13, serAng, potPin = A0, potVal, dly = 5 , maxAng;
bool t = true;
Servo ser;
String msgPV = "Potentiometer Value: ", msgSA = ", Servo Angle: ", msgDly = "What do you want the delay to be?", msgMxAng = "What do you want the maximum servo angle to be?";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ser.attach(serPin);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println(msgDly);
  while (Serial.available() == 0) {

  }
  dly = Serial.parseInt();

  Serial.println(msgMxAng);
  while (Serial.available() == 0) {

  }
  maxAng = Serial.parseInt();
  while (t) {
    potVal = analogRead(potPin);
    Serial.print(msgPV);
    Serial.print(potVal);
    serAng = map(potVal, 0, 1023, 0, maxAng);
    Serial.print(msgSA);
    Serial.println(serAng);
    ser.write(serAng);
    delay(dly);
  }

}
