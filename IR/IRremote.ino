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
  Serial.print(cmd.value, HEX);
  Serial.print("==");
  IR.resume();
  if (cmd.value == 0xFFA25D || cmd.value == 0xE318261B) {
    command = "pwr";    
  }
  else if (cmd.value == 0xFF629D || cmd.value ==0x511DBB) {
    command = "vol+";    
  }
  else if (cmd.value == 0xFFE21D || cmd.value ==0xEE886D7F) {
    command = "stop";    
  }
  else if (cmd.value == 0xFF22DD || cmd.value ==0x52A3D41F) {
    command = "rew";    
  }
  else if (cmd.value == 0xFF02FD || cmd.value ==0xD7E84B1B) {
    command = "pause";    
  }
  else if (cmd.value == 0xFFC23D || cmd.value ==0x20FE4DBB) {
    command = "FF";    
  }
  else if (cmd.value == 0xFFE01F || cmd.value ==0xF076C13B) {
    command = "down";    
  }
  else if (cmd.value == 0xFFA857 || cmd.value ==0xA3C8EDDB) {
    command = "vol-";    
  }
  else if (cmd.value == 0xFF906F || cmd.value ==0xE5CFBD7F) {
    command = "up";    
  }
  else if (cmd.value == 0xFF6897 || cmd.value ==0xC101E57B) {
    command = "zero";    
  }
  else if (cmd.value == 0xFF9867 || cmd.value ==0x97483BFB) {
    command = "eq";    
  }
  else if (cmd.value == 0xFFB04F || cmd.value ==0xF0C41643) {
    command = "rept";    
  }
  else if (cmd.value == 0xFF30CF || cmd.value ==0x9716BE3F) {
    command = "one";    
  }
  else if (cmd.value == 0xFF18E7 || cmd.value ==0x3D9AE3F7) {
    command = "two";    
  }
  else if (cmd.value == 0xFF7A85 || cmd.value ==0x6182021B) {
    command = "three";    
  }
  else if (cmd.value == 0xFF10EF || cmd.value ==0x8C22657B) {
    command = "four";    
  }
  else if (cmd.value == 0xFF38C7 || cmd.value ==0x488F3CBB) {
    command = "five";    
  }
  else if (cmd.value == 0xFF5AA5 || cmd.value ==0x449E79F) {
    command = "six";    
  }
  else if (cmd.value == 0xFF42BD || cmd.value ==0x32C6FDF7) {
    command = "seven";    
  }
  else if (cmd.value == 0xFF4AB5 || cmd.value ==0x1BC0157B) {
    command = "eight";    
  }
  else if (cmd.value == 0xFF52AD || cmd.value ==0x3EC3FC1B) {
    command = "nine";    
  }
  else if(cmd.value == 0x61A06897) {
    command ="left";    
  }
  else {
    command = "null";    
  }
  Serial.println(command);

}
