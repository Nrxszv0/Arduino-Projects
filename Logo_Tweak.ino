int potPin = A0, potVal, writeVal;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);
  writeVal = potVal / 4;
  Serial.write(writeVal);
  delay(1);
}
