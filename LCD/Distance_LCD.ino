#include <LiquidCrystal.h>
int rs = 7, e = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
int columns = 16, rows = 2;
int trigPin = 12, echoPin = 13, pingTime;
int sDly = 10, dly = 250;
float speedOfSound = 767, ft = 5280, in = 12, scs=3600, mScs=1000000;
float targetDistance, pingTravelDistance;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(columns, rows);
  lcd.setCursor(0, 0);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(sDly);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(sDly);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(sDly);
  pingTime = pulseIn(echoPin, HIGH);
  pingTravelDistance = (pingTime * speedOfSound * ft * in) / (scs * mScs);
  targetDistance = pingTravelDistance / 2.;
  Serial.print("Ping Time: ");
  Serial.print(pingTime);
  Serial.print("\t\tPing Travel Distance: ");
  Serial.print(pingTravelDistance);
  Serial.print("\t\tTarget Distance: ");
  Serial.println(targetDistance);

  lcd.print("Distance Meter");
  lcd.setCursor(0, 1);
  lcd.print("Distance:");
  lcd.print(targetDistance);
  lcd.print("in");
  delay(dly);
  lcd.clear();

}
