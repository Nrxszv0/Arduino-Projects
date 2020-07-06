#include <LiquidCrystal.h>
int rs = 34, e = 35, d4 = 36, d5=37, d6=38, d7=39;
LiquidCrystal lcd1(rs, e, d4, d5, d6, d7);
void setup() {
  // put your setup code here, to run once:
lcd1.begin(16,2);
lcd1.setCursor(0,0);
lcd1.print("Hello");
}

void loop() {
  // put your main code here, to run repeatedly:
lcd1.print("Hello");
}
