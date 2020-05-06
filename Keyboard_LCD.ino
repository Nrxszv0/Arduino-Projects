#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int dly = 250, b1Pin = 7, b1St = 0, b2Pin = 6, b2St = 0, b3Pin = 5, b3St = 0,  b4Pin = 4, b4St = 0;
String line1 = "This will act as", line2 = "a keyboard", b1S = "Oops ", b2S = "I did ", b3S = "it ", b4S = "again ", b234S = "I played..";
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.print(line1);
  lcd.setCursor(0, 1);
  lcd.print(line2);
  pinMode(b1Pin, INPUT);
  pinMode(b2Pin, INPUT);
  pinMode(b3Pin, INPUT);
  lcd.blink();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  b1St = digitalRead(b1Pin);
  b2St = digitalRead(b2Pin);
  b3St = digitalRead(b3Pin);
  b4St = digitalRead(b4Pin);
  if (b1St == HIGH) {
    Serial.println("Button 1 pressed");
    lcd.print(b1S);
    delay(dly);
  }
  if (b2St == HIGH) {
    Serial.println("Button 2 pressed");
    lcd.print(b2S);
    delay(dly);
  }
  if (b3St == HIGH) {
    Serial.println("Button 3 pressed");
    lcd.print(b3S);
    delay(dly);
  }

  if (b4St == HIGH) {
    Serial.println("Button 4 pressed");
    lcd.print(b4S);
    delay(dly);
  }
  if (b3St == HIGH && b4St == HIGH) {
    Serial.println("Button 3 and 4 pressed");
    lcd.clear();
    delay(dly);
  }
  if (b2St == HIGH && b3St == HIGH) {
    Serial.println("Buttons 2 and 3 pressed");
    lcd.setCursor(0, 1);
    delay(dly);
  }

  if (b2St == HIGH && b3St == HIGH && b4St == HIGH) {
    Serial.println("Buttons 2, 3, and 4 pressed");
    lcd.print(b234S);
    delay(dly);
  }



}
