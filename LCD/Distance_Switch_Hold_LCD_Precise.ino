#include <LiquidCrystal.h>
int rs = 7, e = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
int columns = 16, rows = 2;
int sPin = 8, sVal;
int trigPin = 12, echoPin = 13;
int ping;
String unit = "in";
float pingTotalDistance, targetDistance, prevTargetDistance;
float soundSpeed = 767, ftInMi = 5280, inInFt = 12, sInHr = 3600, usInSec = 1000000;
int dly = 250, sDly = 10;
int j , numMeas = 50;
float bucket = 0,  avTargetDistance, prevAvTargetDistance;
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
  lcd.print("Press to Measure");
  lcd.setCursor(0, 1);
  if (sVal == HIGH) {
    Serial.println("Measuring");
    lcd.print("Measuring");
    for (j = 0; j <= numMeas; j++) {
      digitalWrite(trigPin, LOW);
      delayMicroseconds(sDly);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(sDly);
      digitalWrite(trigPin, LOW);
      delayMicroseconds(sDly);
      ping = pulseIn(echoPin, HIGH);
      pingTotalDistance = (ping * soundSpeed * ftInMi * inInFt) / (sInHr * usInSec);
      targetDistance = pingTotalDistance / 2;
      bucket += targetDistance;
    }
    avTargetDistance = bucket / numMeas;
    bucket = 0;
    Serial.println(avTargetDistance);
    prevAvTargetDistance = avTargetDistance;
  }
  else {
    Serial.println("Press the button to measure.");
    lcd.print("Avg: ");
    lcd.print(prevAvTargetDistance);
    lcd.print(unit);
  }
  delay(dly);
  lcd.clear();
}
