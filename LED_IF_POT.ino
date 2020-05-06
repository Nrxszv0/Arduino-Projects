int potPin = A0, gPin = 13, yPin = 12, rPin = 11, readVal;
float volt0 = 0;
String line1 = "The voltage is ";
void setup() {
  // put your setup code here, to run once:
  pinMode(gPin, OUTPUT);
  pinMode(yPin, OUTPUT);
  pinMode(rPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(potPin);
  volt0 = (5. / 1023.) * readVal;
  Serial.print(line1);
  Serial.println(volt0);
  if (volt0 > 3. && volt0 < 4.) {
    digitalWrite(gPin, HIGH);
    digitalWrite(yPin, LOW);
    digitalWrite(rPin, LOW);
  }
  else if (volt0 > 4. && volt0 < 5.) {
    digitalWrite(yPin, HIGH);
    digitalWrite(gPin, LOW);
    digitalWrite(rPin, LOW);
  }
  else if (volt0 == 5.) {
    digitalWrite(rPin, HIGH);
    digitalWrite(gPin, LOW);
    digitalWrite(yPin, LOW);
  }
  else if (volt0 < 3.) {
    digitalWrite(gPin, LOW);
    digitalWrite(yPin, LOW);
    digitalWrite(rPin, LOW);
  }
}
