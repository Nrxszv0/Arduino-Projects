#include <LiquidCrystal.h>
int rs = 7, e = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
int columns = 16, rows = 2;
int firstNum, secondNum, val;
String operation = "";
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);
void setup() {
  Serial.begin(9600);
  lcd.begin(columns, rows);
  lcd.setCursor(0, 0);

}
void loop() {
  lcd.print("Enter First");
  lcd.setCursor(0, 1);
  lcd.print("Number");
  Serial.println("Enter First Number");
  while (Serial.available() == 0) {

  }
  firstNum = Serial.parseInt();

  Serial.println("Enter Second Number");
  lcd.clear();
  lcd.print("Enter Second");
  lcd.setCursor(0, 1);
  lcd.print("Number");
  while (Serial.available() == 0) {

  }
  secondNum = Serial.parseInt();

  Serial.println("Enter Operation");
  lcd.clear();
  lcd.print("Enter Operation");
  while (Serial.available() == 0) {

  }
  operation = Serial.readString();
  lcd.clear();
  if (operation == "+") {
    val = firstNum + secondNum;
  }
  else if (operation == "-") {
    val = firstNum - secondNum;
  }
  else if (operation == "*") {
    val = firstNum - secondNum;
  }
  else if (operation == "/") {
    val = firstNum / secondNum;
  }
  else if (operation == "%") {
    val = firstNum % secondNum;
  }
  else {
    Serial.print(operation);
    Serial.print(" is not a valid operation");
    lcd.print(operation);
    lcd.print(" is invalid");
    lcd.setCursor(0, 1);
    lcd.print("\"r\" to restart");
    operation = "ERR";
    
    Serial.print("Enter \"r\" to restart");      
  }
  if (operation != "ERR"); {
    Serial.print(firstNum);
    Serial.print(" ");
    Serial.print(operation);
    Serial.print(" ");
    Serial.print(secondNum);
    Serial.print(" = ");
    Serial.println(val);

    lcd.print(firstNum);
    lcd.print(" ");
    lcd.print(operation);
    lcd.print(" ");
    lcd.print(secondNum);
    lcd.print(" = ");
    lcd.print(val);

    lcd.setCursor(0, 1);
    lcd.print("\"r\" to restart");
    Serial.print("Enter \"r\" to restart");    
  }
  while(Serial.available() == 0) {
    
  }
  if(Serial.readString() == "r") {
    lcd.clear();
  }
  
  
}
