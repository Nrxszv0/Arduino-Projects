#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int dly = 100;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.print("Serial Monitor");
  lcd.setCursor(0, 1);
  lcd.print("Display");
  Serial.begin(9600);


}

void loop() {
  for (int i = 1; i < 100; i++) {
    lcd.clear();
    lcd.print(i);
    Serial.println(i);
    delay(dly);
  }



}
