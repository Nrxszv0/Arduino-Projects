#include <LiquidCrystal.h>
int rs = 7, e = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
int columns = 16, rows = 2;
int latchPin = 3, clockPin = 2, dataPin = 4;
int dly = 250;
int maxLED = 255;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(columns, rows);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (byte LED = 0b00000000; LED <= maxLED; LED++) {
    lcd.setCursor(0, 0);
    lcd.print("Binary Counter");
    lcd.setCursor(0, 1);
    Serial.print("BIN: ");
    Serial.print(LED, BIN);
    Serial.print(" = ");
    Serial.print("HEX: ");
    Serial.print(LED, HEX);
    Serial.print(" = ");
    Serial.print("DEC: ");
    Serial.println(LED, DEC);

    lcd.print(LED, BIN);
    lcd.print(" = ");
    lcd.print(LED, DEC);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, LED);
    digitalWrite(latchPin, HIGH);

    delay(dly);
    lcd.clear();
  }
}
