#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int sensVal;
float tempC, tempF, voltage;
const int sensorPin = A0;
const float baseTemp = 23.33;
String line1 = "Temperature", line2 = "Sensor";
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.print(line1);
  lcd.setCursor(0, 1);
  lcd.print(line2);
  Serial.begin(9600);
}

void loop() {
  lcd.clear();
  sensVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensVal);
  voltage = (sensVal / 1023.0) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C: ");
  tempC = (voltage - .5) * 100;
  Serial.print(tempC);
  Serial.print(", degrees F: ");
  tempF = (tempC * 1.8) + 32;
  Serial.println(tempF);
  lcd.print(line1);
  lcd.setCursor(0,1);
  lcd.print(tempF);
  lcd.print(" Fahrenheit");
  delay(250);

}
