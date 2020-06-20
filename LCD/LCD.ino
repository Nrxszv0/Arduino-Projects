#include <LiquidCrystal.h>
int rs = 7, e=8, d4 = 9, d5=10, d6=11, d7=12;
int columns = 16, rows = 2; 
LiquidCrystal lcd(rs,e,d4,d5,d6,d7);
void setup() {
  // put your setup code here, to run once:
  lcd.begin(columns, rows);
}

void loop() {
  // put your main code here, to run repeatedly:
lcd.setCursor(0,0);
lcd.print("Imma count cuh");
delay(500);
for (int c=1; c<=10; c++) {
  lcd.setCursor(0,1);
  lcd.print(c);
  delay(500);
  
}
lcd.clear();
}
