int switchState=0, swtchPin = 2, led1=3, led2=4, led3=5, led4=6, led5=7, dly=250;
void setup() {
  // put your setup code here, to run once:
pinMode(swtchPin, INPUT);
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(led4, OUTPUT);
pinMode(led5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
switchState=digitalRead(swtchPin);
if(switchState == LOW) {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  delay(dly);
  digitalWrite(led1, LOW);
  delay(dly);
}
else {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, HIGH);
  delay(dly);

  digitalWrite(led5, LOW);
  digitalWrite(led4, HIGH);
  delay(dly);

  digitalWrite(led4, LOW);
  digitalWrite(led3, HIGH);
  delay(dly);
  
  digitalWrite(led3, LOW);
  digitalWrite(led2, HIGH);
  delay(dly);
}


}
