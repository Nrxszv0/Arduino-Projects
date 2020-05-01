int ledPin = 13, element = 200, dly = 1000, i, tdly=100;
int dit = element;
int dah = 3 * element;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);

}

void loop() {
  for (i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(dit);
    digitalWrite(ledPin, LOW);
    delay(dit);
  }
  delay(tdly);
  for (i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(dah);
    digitalWrite(ledPin, LOW);
    delay(dah);
  }
  delay(tdly);
  for (i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(dit);
    digitalWrite(ledPin, LOW);
    delay(dit);
  }
  delay(dly);

//  digitalWrite(ledPin, HIGH);
//  delay(dit);
//  digitalWrite(ledPin, LOW);
//  delay(dit);
//
//  digitalWrite(ledPin, HIGH);
//  delay(dit);
//  digitalWrite(ledPin, LOW);
//  delay(dit);
//
//  digitalWrite(ledPin, HIGH);
//  delay(dit);
//  digitalWrite(ledPin, LOW);
//  delay(dit);
//
//  digitalWrite(ledPin, HIGH);
//  delay(dah);
//  digitalWrite(ledPin, LOW);
//  delay(dah);
//
//  digitalWrite(ledPin, HIGH);
//  delay(dah);
//  digitalWrite(ledPin, LOW);
//  delay(dah);
//
//  digitalWrite(ledPin, HIGH);
//  delay(dah);
//  digitalWrite(ledPin, LOW);
//  delay(dah);
//
//  digitalWrite(ledPin, HIGH);
//  delay(dit);
//  digitalWrite(ledPin, LOW);
//  delay(dit);
//
//  digitalWrite(ledPin, HIGH);
//  delay(dit);
//  digitalWrite(ledPin, LOW);
//  delay(dit);
//
//  digitalWrite(ledPin, HIGH);
//  delay(dit);
//  digitalWrite(ledPin, LOW);
//  delay(dit);
//
//  delay(dly);

}
