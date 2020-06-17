#include <LiquidCrystal.h>
#include <DHT.h>
#define TYPE DHT11
int brightPin = 6, brightVal=45, rs=7, e=8, d4=9, d5=10, d6=11, d7=12;
int columns=16, rows=2;
int sensPin =13;
DHT TH(sensPin, TYPE);
LiquidCrystal lcd(rs,e,d4,d5,d6,d7);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
TH.begin();
lcd.begin(columns, rows);
lcd.setCursor(0,0);
pinMode(brightPin, OUTPUT); 
analogWrite(brightPin, brightVal);


}

void loop() {
  // put your main code here, to run repeatedly:
lcd.print("Hello");
delay(10000);
}
