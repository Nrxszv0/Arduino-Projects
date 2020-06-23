#include <IRremote.h>
int irPin = 10;
IRrecv IR(irPin);
decode_results cmd;
String command = "";
int dly = 250;
int speedPin = 5, dirPin1 = 4, dirPin2 = 3;
int speedVal = 130, speedIncrement = 25, disabledSpeedVal = 0;
int speedVals[] = {
  100,
  119,
  138,
  157,
  176,
  195,
  214,
  233,
  255
};
boolean motorEnabled = false;
String SST =", Speed Set To ";
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
  while (IR.decode(&cmd) == 0) {

  }
  delay(dly);
  Serial.println(cmd.value, HEX);
  IR.resume();
  if (cmd.value == 0xFFA25D) {
    command = "pwr";
    Serial.print(command);
    Serial.println(", Motor Enabled");
    motorEnabled = true;

  }
  if (cmd.value == 0xFF629D && motorEnabled == true && speedVal <= 255) {
    command = "vol+";
    speedVal += speedIncrement;
    Serial.print(command);
    Serial.print(", Speed Increased, Speed = ");
    Serial.println(speedVal);
  }
  if (cmd.value == 0xFFE21D) {
    command = "stop";
    Serial.print(command);
    Serial.println(", Motor Disabled");
    motorEnabled = false;
    analogWrite(speedPin, disabledSpeedVal);
  }
  if (cmd.value == 0xFF22DD && motorEnabled == true) {
    command = "rew";
    Serial.print(command);
    Serial.println(", Motor Direction Reverse");
    digitalWrite(dirPin1, LOW);
    digitalWrite(dirPin2, HIGH);
  }
  if (cmd.value == 0xFFC23D && motorEnabled == true) {
    command = "FF";
    Serial.print(command);
    Serial.println(", Motor Direction Normal");
    digitalWrite(dirPin1, HIGH);
    digitalWrite(dirPin2, LOW);
  }
  if (cmd.value == 0xFFA857 && motorEnabled == true && speedVal >= 0) {
    command = "vol-";
    speedVal -= speedIncrement;
    Serial.print(command);
    Serial.print(", Speed Decreased, Speed = ");
    Serial.println(speedVal);

  }

  if (cmd.value == 0xFF6897) {
    command = "zero";
    speedVal = 0;
    Serial.print(command);
    Serial.print(SST);
    Serial.println(speedVal);
  }
  if (cmd.value == 0xFF6897) {
    command = "one";
    speedVal = speedVals[0];
    Serial.print(command);
    Serial.print(SST);
    Serial.println(speedVal);
  }
  if (cmd.value == 0xFF18E7) {
    command = "two";
    speedVal = speedVals[1];
    Serial.print(command);
    Serial.print(SST);
    Serial.println(speedVal);
  }
  if (cmd.value == 0xFF7A85) {
    command = "three";
    speedVal = speedVals[2];
    Serial.print(command);
    Serial.print(SST);
    Serial.println(speedVal);
  }
  if (cmd.value == 0xFF10EF) {
    command = "four";
    speedVal = speedVals[3];
    Serial.print(command);
    Serial.print(SST);
    Serial.println(speedVal);
  }
  if (cmd.value == 0xFF38C7) {
    command = "five";
    speedVal = speedVals[4];
    Serial.print(command);
    Serial.print(SST);
    Serial.println(speedVal);
  }
  if (cmd.value == 0xFF5AA5) {
    command = "six";
    speedVal = speedVals[5];
    Serial.print(command);
    Serial.print(SST);
    Serial.println(speedVal);
  }
  if (cmd.value == 0xFF42BD) {
    command = "seven";
    speedVal = speedVals[6];
    Serial.print(command);
    Serial.print(SST);
    Serial.println(speedVal);
  }
  if (cmd.value == 0xFF4AB5) {
    command = "eight";
    speedVal = speedVals[7];
    Serial.print(command);
    Serial.print(SST);
    Serial.println(speedVal);
  }
  if (cmd.value == 0xFF52AD) {
    command = "nine";
    speedVal = speedVals[8];
    Serial.print(command);
    Serial.print(SST);
    Serial.println(speedVal);
  }

  if (motorEnabled == true) {
    analogWrite(speedPin, speedVal);
  }
  if (speedVal > 255) {
    speedVal = 255;
  }
  if (speedVal < 0) {
    speedVal = 0;
  }
}
