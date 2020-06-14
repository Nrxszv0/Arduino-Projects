int dly=500;
byte myByte=B00001111;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(myByte,HEX);
myByte = myByte+1;
delay(dly);
}
