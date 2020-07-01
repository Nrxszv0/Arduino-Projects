#include <IRremote.h>
int irPin = 10;
IRrecv IR(irPin);
decode_results cmd;
String command = "", color = "";
int dly = 250;
int dimVal, dimIncrement = 15;
int rVal, gVal, bVal;
int rPin = 5, gPin = 6, bPin = 9;
int white[] = {255, 255, 255};
int off[] = {0, 0, 0};
int red[] = {255, 0 , 0};
int green[] = {0, 255, 0};
int blue[] = {0, 0, 255};
int yellow[] = {255, 255, 0};
int teal[] = {0, 255, 255};
int pink[] = {255, 0, 255};
//int colors[] = {{255,255,255}, {255,0,0}}
String colMsg = ", LED Color: ", dimMsg = ", LED Dimnesss: ", rMsg = "Red Value: ", gMsg = "Green Value: ", bMsg = "Blue Value: ", tab = "    "; // \t is kind of messed up
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  IR.enableIRIn();

  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(rPin, OUTPUT);
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
  if (cmd.value == 0xFF6897 || cmd.value == 0xC101E57B) {
    command = "zero";
    color = "White";
    rVal = white[0];
    gVal = white[1];
    bVal = white[2];
  }
  if (cmd.value == 0xFF30CF || cmd.value == 0x9716BE3F) {
    command = "one";
    color = "Red";
    rVal = red[0];
    gVal = red[1];
    bVal = red[2];
  }
  if (cmd.value == 0xFF18E7 || cmd.value == 0x3D9AE3F7) {
    command = "two";
    color = "Green";
    rVal = green[0];
    gVal = green[1];
    bVal = green[2];
  }
  if (cmd.value == 0xFF7A85 || cmd.value == 0x6182021B) {
    command = "three";
    color = "Blue";
    rVal = blue[0];
    gVal = blue[1];
    bVal = blue[2];
  }
  if (cmd.value == 0xFF10EF || cmd.value == 0x8C22657B) {
    command = "four";
    color = "Yellow";
    rVal = yellow[0];
    gVal = yellow[1];
    bVal = yellow[2];
  }
  if (cmd.value == 0xFF38C7 || cmd.value == 0x488F3CBB) {
    command = "five";
    color = "Teal";
    rVal = teal[0];
    gVal = teal[1];
    bVal = teal[2];
  }
  else if (cmd.value == 0xFF5AA5 || cmd.value == 0x449E79F) {
    command = "six";
    color = "Pink";
    rVal = pink[0];
    gVal = pink[1];
    bVal = pink[2];
  }
  if ((cmd.value == 0xFFE01F || cmd.value == 0xF076C13B) && (rVal >= 0 && gVal >= 0 && bVal >= 0)) {
    command = "down";
    rVal -= dimIncrement;
    gVal -= dimIncrement;
    bVal -= dimIncrement;
    dimVal -= dimIncrement;
  }
  if ((cmd.value == 0xFF906F || cmd.value == 0xE5CFBD7F) && (rVal <= 255 && gVal <= 255 && bVal <= 255)) {
    command = "up";
    rVal += dimIncrement;
    gVal += dimIncrement;
    bVal += dimIncrement;
    dimVal += dimIncrement;
  }
  Serial.print(command);
  if (command == "up" || command == "down") {
    Serial.print(dimMsg);
    Serial.print(dimVal);
  }
  else {
    Serial.print(colMsg);
    Serial.print(color);
  }
  analogWrite(rPin, rVal);
  analogWrite(gPin, gVal);
  analogWrite(bPin, bVal);
  Serial.print(tab);
  Serial.print(rMsg);
  Serial.print(rVal);
  Serial.print(tab);
  Serial.print(gMsg);
  Serial.print(gVal);
  Serial.print(tab);
  Serial.print(bMsg);
  Serial.println(bVal);

}
