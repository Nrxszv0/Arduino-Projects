int optoPin=2, dly=15, bDly=20000;
void setup() {
  // put your setup code here, to run once:
pinMode(optoPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(optoPin, HIGH);
delay(dly);
digitalWrite(optoPin, LOW);
delay(bDly);
}
