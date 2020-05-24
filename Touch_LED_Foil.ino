#include <CapacitiveSensor.h>
int rLED = 11, foilThreshold = 1000, sendPin=4, sensePin=2;
CapacitiveSensor capSens = CapacitiveSensor(sendPin, sensePin);
long sensVal;

void setup() {
  Serial.begin(9600);
  pinMode(rLED, OUTPUT);
}

void loop() {
  digitalWrite(rLED, HIGH);
  sensVal = capSens.capacitiveSensor(30);
  Serial.println(sensVal);
  if (sensVal > foilThreshold) {
    digitalWrite(rLED, HIGH);
  }
  else if( sensVal< foilThreshold){
    digitalWrite(rLED,LOW);
  }
  delay(15);
}
