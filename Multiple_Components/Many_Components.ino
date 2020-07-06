#include <LiquidCrystal.h>
#include <Servo.h>
#include <DHT.h>
#include <IRremote.h>
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
int irPin = 13;
String command = "";
IRrecv IR(irPin);
decode_results cmd;
unsigned long val, preMillis;
int trigPin = 12, echoPin = 10;
float pingTime, distanceIn;
int ssDly = 2, sDly = 20, microsecondsToInchVal = 148; //For speed of sound
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

  IR.enableIRIn();

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  getDHTVals();
  getTempVals();
  getDistance();
  getIRVal();
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
  Serial.print("\tSV: ");
  Serial.print(sensVal);
  Serial.print("\tV: ");
  Serial.print(voltage);
  Serial.print("\tTC2: ");
  Serial.print(tempC2);
  Serial.print("\tTF2: ");
  Serial.print(tempF2);
}
void getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(ssDly);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(sDly);
  digitalWrite(trigPin, LOW);
  pingTime = pulseIn(echoPin, HIGH);
  distanceIn = pingTime / microsecondsToInchVal;
  Serial.print("\tPT: ");
  Serial.print(pingTime);
  Serial.print("DIn: ");
  Serial.println(distanceIn);
}
void getIRVal() {
  if (IR.decode(&cmd)) {
    preMillis = millis();
    val = cmd.value;
    Serial.println();
    Serial.print(val, HEX);
    IR.resume();
    switch (val) {
      case 0xFFA25D:
      case 0xE318261B: command = "pwr"; break;
      case 0xFF629D:
      case 0x511DBB: command = "vol+"; break;
      case 0xFFE21D:
      case 0xEE886D7F: command = "stop"; break;
      case 0xFF22DD:
      case 0x52A3D41F: command = "rew"; break;
      case 0xFF02FD:
      case 0xD7E84B1B: command = "pause"; break;
      case 0xFFC23D:
      case 0x20FE4DBB: command = "FF"; break;
      case 0xFFE01F:
      case 0xF076C13B: command = "down"; break;
      case 0xFFA857:
      case 0xA3C8EDDB: command = "vol-"; break;
      case 0xFF906F:
      case 0xE5CFBD7F: command = "up"; break;
      case 0xFF6897:
      case 0xC101E57B: command = "zero"; break;
      case 0xFF9867:
      case 0x97483BFB: command = "eq"; break;
      case 0xFFB04F:
      case 0xF0C41643: command = "rept"; break;
      case 0xFF30CF:
      case 0x9716BE3F: command = "one"; break;
      case 0xFF18E7:
      case 0x3D9AE3F7: command = "two"; break;
      case 0xFF7A85:
      case 0x6182021B: command = "three"; break;
      case 0xFF10EF:
      case 0x8C22657B: command = "four"; break;
      case 0xFF38C7:
      case 0x488F3CBB: command = "five"; break;
      case 0xFF5AA5:
      case 0x449E79F: command = "six"; break;
      case 0xFF42BD:
      case 0x32C6FDF7: command = "seven"; break;
      case 0xFF4AB5:
      case 0x1BC0157B: command = "eight"; break;
      case 0xFF52AD:
      case 0x3EC3FC1B: command = "nine"; break;
      default: command = "null"; break;
    }
    Serial.print("==");
    Serial.println(command);
  }
}
