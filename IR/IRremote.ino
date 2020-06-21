#include <IRremote.h>
int irPin = 10;
IRrecv IR(irPin);
decode_results cmd;
String command = "";
int dly = 250;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  IR.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  while (IR.decode(&cmd) == 0) {

  }
  delay(dly);
  IR.resume();
  if (cmd.value == 0xFFA25D) {
    command = "pwr";
    Serial.println(command);
  }
  if (cmd.value == 0xFF629D) {
    command = "vol+";
    Serial.println(command);
  }
  if (cmd.value == 0xFFE21D) {
    command = "stop";
    Serial.println(command);
  }
  if (cmd.value == 0xFF22DD) {
    command = "rew";
    Serial.println(command);
  }
  if (cmd.value == 0xFF02FD) {
    command = "pause";
    Serial.println(command);
  }
  if (cmd.value == 0xFFC23D) {
    command = "FF";
    Serial.println(command);
  }
  if (cmd.value == 0xFFE01F) {
    command = "down";
    Serial.println(command);
  }
  if (cmd.value == 0xFFA857) {
    command = "vol-";
    Serial.println(command);
  }
  if (cmd.value == 0xFF906F) {
    command = "up";
    Serial.println(command);
  }
  if (cmd.value == 0xFF6897) {
    command = "zero";
    Serial.println(command);
  }
  if (cmd.value == 0xFF9867) {
    command = "eq";
    Serial.println(command);
  }
  if (cmd.value == 0xFFB04F) {
    command = "rept";
    Serial.println(command);
  }
  if (cmd.value == 0xFF30CF) {
    command = "one";
    Serial.println(command);
  }
  if (cmd.value == 0xFF18E7) {
    command = "two";
    Serial.println(command);
  }
  if (cmd.value == 0xFF7A85) {
    command = "three";
    Serial.println(command);
  }
  if (cmd.value == 0xFF10EF) {
    command = "four";
    Serial.println(command);
  }
  if (cmd.value == 0xFF38C7) {
    command = "five";
    Serial.println(command);
  }
  if (cmd.value == 0xFF5AA5) {
    command = "six";
    Serial.println(command);
  }
  if (cmd.value == 0xFF42BD) {
    command = "seven";
    Serial.println(command);
  }
  if (cmd.value == 0xFF4AB5) {
    command = "eight";
    Serial.println(command);
  }
  if (cmd.value == 0xFF52AD) {
    command = "nine";
    Serial.println(command);
  }

}
