int ledPin = 11, anlgVal, bdly = 250, dly = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (anlgVal = 0; anlgVal < 255; anlgVal++) {
    analogWrite(ledPin, anlgVal);
    delay(20);
  }
  for (anlgVal = 255; anlgVal > 0; anlgVal--) {
    analogWrite(ledPin, anlgVal);
    delay(20);
  }
}
