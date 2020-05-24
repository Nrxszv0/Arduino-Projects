#include <CapacitiveSensor.h>
int rLED = 13, foilThreshold = 1000, sendPin=4, sensePin=2;
CapacitiveSensor capSens = CapacitiveSensor(sendPin, sensePin);
long sensVal;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(rLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(rLED, HIGH);
  sensVal = capSens.capacitiveSensor(30);
  Serial.println(sensVal);
  if (sensVal > foilThreshold) {
    digitalWrite(rLED, HIGH);
  }
  else {
    digitalWrite(rLED, LOW);
  }
  delay(15);
}
