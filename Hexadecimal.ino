int dly=500, num=0;
byte myByte=0x0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print(myByte,HEX);
Serial.print(" = ");
Serial.println(num);
myByte = myByte+1;
num = num+1;
delay(dly);
}
