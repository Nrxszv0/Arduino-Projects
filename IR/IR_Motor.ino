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
  if (motorEnabled == true) {
    analogWrite(speedPin, speedVal);
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
    motorEnabled = true;

  }
   if (cmd.value == 0xFF629D && motorEnabled == true) {
    command = "vol+";
    Serial.print(command);
    Serial.println(", Speed Increased");
    speedVal += speedIncrement;
  }
   if (cmd.value == 0xFFE21D) {
    command = "stop";
    Serial.print(command);
    Serial.println(", Motor Disabled");
    motorEnabled = false;
  }
   if (cmd.value == 0xFF22DD && motorEnabled == true) {
    command = "rew";
    Serial.print(command);
    Serial.println(", Motor Direction Reverse");
    digitalWrite(dirPin1, LOW);
    digitalWrite(dirPin2, HIGH);
  }
   if (cmd.value == 0xFF02FD) {
    command = "pause";
    Serial.println(command);
  }
   if (cmd.value == 0xFFC23D && motorEnabled == true) {
    command = "FF";
    Serial.print(command);
    Serial.println(", Motor Direction Normal");
    digitalWrite(dirPin1, HIGH);
    digitalWrite(dirPin2, LOW);
  }
   if ((cmd.value == 0xFFA857) && (motorEnabled == true)) {
    command = "vol-";
    Serial.print(command);
    Serial.println(", Speed Decreased");
    speedVal -= speedIncrement;
  }





}
