int piezoPin=13, dly=100, piezoVal;
String msg="Enter a value for the piezo: ";
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(piezoPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(msg);
while(Serial.available()==0) {
  
}
piezoVal=Serial.parseInt();
tone(piezoPin, piezoVal);

}
