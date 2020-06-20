#include <LiquidCrystal.h>
int rs = 7, e = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
int columns = 16, rows = 2;
int sPin = 8, sState = 0, sVal = 0, prevSVal = 0;
int trigPin = 12, echoPin = 13;
int ping;
float pingTotalDistance, targetDistance;
float soundSpeed = 767, ftInMi = 5280, inInFt = 12, sInHr = 3600, usInSec = 1000000;
int dly = 250, sDly = 10;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16  , 2);
  lcd.setCursor(0, 0);
  pinMode(sPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  sVal = digitalRead(sPin);
  //  if (sVal != prevSVal) {
  //    if (sVal == HIGH) {
  //      sVal = !sVal;
  //    }
  //  }
  //
  //  Serial.println(sVal);
  //  prevSVal = sVal;
  if (sVal == HIGH) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(sDly);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(sDly);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(sDly);
    ping = pulseIn(echoPin, HIGH);
    pingTotalDistance = (ping * soundSpeed * ftInMi * inInFt) / (sInHr * usInSec);
    targetDistance = pingTotalDistance / 2;
    Serial.println(targetDistance);
    Serial.println(ping);
  }





}
