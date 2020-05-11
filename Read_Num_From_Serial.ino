int serNumb;
String serMsg="Please Enter a Number:", serMsg2="The Number is: ";

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(serMsg);
while(Serial.available()==0) {
  
}
serNumb=Serial.parseInt();
Serial.print(serMsg2);
Serial.println(serNumb);
}
