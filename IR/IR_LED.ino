#include <IRremote.h>
int irPin = 10;
IRrecv IR(irPin);
decode_results cmd;
String command = "", color = "";
int dly = 250;
int dimVal, dimIncrement = 15;
int rVal, gVal, bVal;
int rPin = 11, gPin = 5, bPin = 6;
int white[] = {255, 255, 255};
int off[] = {0, 0, 0};
int red[] = {255, 0 , 0};
int green[] = {0, 255, 0};
//int colors[] = {{255,255,255}, {255,0,0}}
String colMsg = ", LED Color: ", dimMsg = ", LED Dimnesss: ";
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  IR.enableIRIn();
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    while (IR.decode(&cmd) == 0) {
  
    }
    delay(dly);
    Serial.print(cmd.value, HEX);
    Serial.print("==");
    IR.resume();
    if (cmd.value == 0xFFA25D || cmd.value == 0xE318261B) {
      command = "pwr";
      color = "White";
      rVal = white[0];
      gVal = white[1];
      bVal = white[2];
    }
    if ((cmd.value == 0xFFE21D || cmd.value == 0xEE886D7F)) {
      command = "stop";
      color = "Off";
      rVal = off[0];
      gVal = off[1];
      bVal = off[2];
    }
    if (cmd.value == 0xFFE01F || cmd.value == 0xF076C13B) {
      command = "down";
      rVal -= dimIncrement;
      gVal -= dimIncrement;
      bVal -= dimIncrement;
      dimVal -= dimIncrement;
    }
    if (cmd.value == 0xFF906F || cmd.value == 0xE5CFBD7F) {
      command = "up";
      rVal += dimIncrement;
      gVal += dimIncrement;
      bVal += dimIncrement;
      dimVal += dimIncrement;
    }
    Serial.print(command);
    if (command == "up" || command == "down") {
      Serial.print(dimMsg);
      Serial.println(dimVal);
    }
    else {
      Serial.print(colMsg);
      Serial.println(color);
    }
    analogWrite(rPin, rVal);
    analogWrite(gPin, gVal);
    analogWrite(bPin, bVal);
    Serial.print(rVal);
    Serial.print(gVal);
    Serial.println(bVal);
//  analogWrite(rPin, 220);
//  analogWrite(gPin, 100);
//  analogWrite(bPin, 100);

}
