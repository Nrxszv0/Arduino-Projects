int piezoPin=13, dly=300, beepsVal, piezoVal=500, len=250; 
String msg="Enter the number of piezo beeps: ";
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
beepsVal=Serial.parseInt();
for(int i=0; i<beepsVal; i++) {
  tone(piezoPin, piezoVal, len);
  delay(dly);
  noTone(piezoPin);
}


}
