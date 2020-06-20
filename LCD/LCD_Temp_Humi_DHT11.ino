#include <LiquidCrystal.h>
#include <DHT.h>
#define TYPE DHT11
int rs=7, e=8, d4=9, d5=10, d6=11, d7=12;
int columns=16, rows=2;
int sensPin =13;
float humidity, tempC, tempF;
DHT TH(sensPin, TYPE);
LiquidCrystal lcd(rs,e,d4,d5,d6,d7);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
TH.begin();
lcd.begin(columns, rows);
lcd.setCursor(0,0);
}

void loop() {
  // put your main code here, to run repeatedly:
humidity = TH.readHumidity();
tempC = TH.readTemperature();
tempF = TH.readTemperature(true);

Serial.print("Humidity: ");
Serial.print(humidity);
Serial.print("\t\tTemperature C: ");
Serial.print(tempC);
Serial.print("\t\tTemperature F: ");
Serial.println(tempF);
lcd.print("Humidity: ");
lcd.print(humidity);
lcd.setCursor(0,1);
lcd.print("Temp F: ");
lcd.print(tempF);
delay(500);
lcd.clear();
}
