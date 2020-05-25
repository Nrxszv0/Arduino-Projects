int potPin = A0, potVal, writeVal, baud=9600;
void setup() {
  Serial.begin(baud);
}

void loop() {
  potVal = analogRead(potPin);
  writeVal = potVal / 4;
  Serial.write(writeVal);
  delay(1);
}
