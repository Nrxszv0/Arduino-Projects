int dly=1000, num=0;
byte myByte=0x15;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print(myByte,HEX);
Serial.print(" = ");
Serial.print(myByte,BIN);
Serial.print(" = ");
Serial.println(myByte, DEC);
myByte = myByte+1;
delay(dly);
}
