#include <IRremote.h>
int irPin = 10;
IRrecv IR(irPin);
decode_results cmd;
String command = "";
int dly = 250;
int speedPin = 5, dirPin1 = 4, dirPin2 = 3;
int speedVal = 100, speedIncrement = 5;
int i = 1;
boolean motorEnabled = false;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  IR.enableIRIn();
  pinMode(speedPin, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(speedPin, 255);
  if ( i == 1) {
    digitalWrite(dirPin1, HIGH);
    digitalWrite(dirPin2, LOW);
  }
  else {
    digitalWrite(dirPin1, LOW);
    digitalWrite(dirPin2, HIGH);
  }

  while (IR.decode(&cmd) == 0) {

  }
  delay(dly);
  Serial.println(cmd.value, HEX);
  IR.resume();
  if (cmd.value == 0xFFA25D) {
    command = "pwr";
    Serial.print(command);
    Serial.println(", Motor Enabled");
    motorEnabled == true;

  }
  else if (cmd.value == 0xFF629D && motorEnabled==true) {
    command = "vol+";
    Serial.print(command);
    Serial.println(", Speed Increased");
    speedVal += speedIncrement;
  }
  else if (cmd.value == 0xFFE21D) {
    command = "stop";
    Serial.print(command);
    Serial.println(", Motor Disabled");
    motorEnabled == false;
  }
  else if (cmd.value == 0xFF22DD && motorEnabled==true) {
    command = "rew";
    Serial.print(command);
    Serial.println(", Motor Direction Reverse");
    digitalWrite(dirPin1, LOW);
    digitalWrite(dirPin2, HIGH);
  }
  else if (cmd.value == 0xFF02FD) {
    command = "pause";
    Serial.println(command);
  }
  else if (cmd.value == 0xFFC23D && motorEnabled==true) {
    command = "FF";
    Serial.print(command);
    Serial.println(", Motor Direction Normal");
    digitalWrite(dirPin1, HIGH);
    digitalWrite(dirPin2, LOW);
  }
  else if (cmd.value == 0xFFE01F) {
    command = "down";
    Serial.println(command);
  }
  else if (cmd.value == 0xFFA857 && motorEnabled==true) {
    command = "vol-";
    Serial.print(command);
    Serial.println(", Speed Decreased");
    speedVal -= speedIncrement;
  }
  else if (cmd.value == 0xFF906F) {
    command = "up";
    Serial.println(command);
  }
  else if (cmd.value == 0xFF6897) {
    command = "zero";
    Serial.println(command);
  }
  else if (cmd.value == 0xFF9867) {
    command = "eq";
    Serial.println(command);
  }
  else if (cmd.value == 0xFFB04F) {
    command = "rept";
    Serial.println(command);
  }
  else if (cmd.value == 0xFF30CF) {
    command = "one";
    Serial.println(command);
  }
  else if (cmd.value == 0xFF18E7) {
    command = "two";
    Serial.println(command);
  }
  else if (cmd.value == 0xFF7A85) {
    command = "three";
    Serial.println(command);
  }
  else if (cmd.value == 0xFF10EF) {
    command = "four";
    Serial.println(command);
  }
  else if (cmd.value == 0xFF38C7) {
    command = "five";
    Serial.println(command);
  }
  else if (cmd.value == 0xFF5AA5) {
    command = "six";
    Serial.println(command);
  }
  else if (cmd.value == 0xFF42BD) {
    command = "seven";
    Serial.println(command);
  }
  else if (cmd.value == 0xFF4AB5) {
    command = "eight";
    Serial.println(command);
  }
  else if (cmd.value == 0xFF52AD) {
    command = "nine";
    Serial.println(command);
  }
  else {
    command = "null";
    Serial.println(command);
  }



}
