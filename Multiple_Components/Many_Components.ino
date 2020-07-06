#include <LiquidCrystal.h>
#include <Servo.h>
#include <DHT.h>
#define TYPE DHT11
int htPin = 2;
float humidity, tempC, tempF;
DHT HT(htPin, TYPE);
int rs = 34, e = 35, d4 = 36, d5 = 37, d6 = 38, d7 = 39;
int rs2 = 40, e2 = 41, d42 = 42 , d52 = 43, d62 = 44, d72 = 45;
LiquidCrystal lcd1(rs, e, d4, d5, d6, d7);
LiquidCrystal lcd2(rs2, e2, d42, d52, d62, d72);
int ser1Pin = 22, ser2Pin = 23, ser3Pin = 24, ser4Pin = 25, ser5Pin = 26, ser6Pin = 27, ser7Pin = 28, ser8Pin = 29, ser9Pin = 30, ser10Pin = 31, ser11Pin = 32, ser12Pin = 33;
int serVal = 10;
Servo ser1;
Servo ser2;
Servo ser3;
Servo ser4;
Servo ser5;
Servo ser6;
Servo ser7;
Servo ser8;
Servo ser9;
Servo ser10;
Servo ser11;
Servo ser12;
int tempPin = A0;
int baseTemp = 24, sensVal;
float voltage, tempC2, tempF2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd1.begin(16, 2);
  lcd2.begin(16, 2);
  lcd1.setCursor(0, 0);
  lcd2.setCursor(0, 0);
  lcd1.print("Hello");
  lcd2.print("Hello");

  ser1.attach(ser1Pin);
  ser2.attach(ser2Pin);
  ser3.attach(ser3Pin);
  ser4.attach(ser4Pin);
  ser5.attach(ser5Pin);
  ser6.attach(ser6Pin);
  ser7.attach(ser7Pin);
  ser8.attach(ser8Pin);
  ser9.attach(ser9Pin);
  ser10.attach(ser10Pin);
  ser11.attach(ser11Pin);
  ser12.attach(ser12Pin);

  HT.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
getDHTVals();
getTempVals();

}
void moveServos(int sersVal) {
  ser1.write(sersVal);
  ser2.write(sersVal);
  ser3.write(sersVal);
  ser4.write(sersVal);
  ser5.write(sersVal);
  ser6.write(sersVal);
  ser7.write(sersVal);
  ser8.write(sersVal);
  ser9.write(sersVal);
  ser10.write(sersVal);
  ser11.write(sersVal);
  ser12.write(sersVal);
}
void getDHTVals() {
  humidity = HT.readHumidity();
  tempC = HT.readTemperature();
  tempF = HT.readTemperature(true);
  Serial.print("H:");
  Serial.print(humidity);
  Serial.print("\tTC: ");
  Serial.print(tempC);
  Serial.print("\tTF: ");
  Serial.print(tempF);
}
void getTempVals() {
  sensVal = analogRead(tempPin);
  voltage = (sensVal / 1024.0) * 5.0;
  tempC2 = (voltage - 0.5) * 100.0;
  tempF2 = (tempC2 * 1.8) + 32;
  Serial.print("SV: ");
  Serial.print(sensVal);
  Serial.print("\tV: ");
  Serial.print(voltage);
  Serial.print("\tTC2: ");
  Serial.print(tempC2);
  Serial.print("\tTF2: ");
  Serial.println(tempF2);
}
