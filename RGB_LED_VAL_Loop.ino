int rPin = 11, bPin = 12, gPin = 13, rVal, gVal, bVal, dly = 1;
String   r = "Red: ", g = ", Green: ", b = ", Blue: ";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);

}

void loop() {
  rVal = 255;
  bVal = 0;
  for (gVal = 0; gVal <= 255; gVal++) {
    analogWrite(rPin, rVal);
    analogWrite(gPin, gVal);
    analogWrite(bPin, bVal);
    Serial.print(r);
    Serial.print(rVal);
    Serial.print(g);
    Serial.print(gVal);
    Serial.print(b);
    Serial.println(bVal);
    delay(dly);
  }

  gVal = 255;
  bVal = 0;
  for (rVal = 255; rVal >= 0; rVal--) {
    analogWrite(rPin, rVal);
    analogWrite(gPin, gVal);
    analogWrite(bPin, bVal);
    Serial.print(r);
    Serial.print(rVal);
    Serial.print(g);
    Serial.print(gVal);
    Serial.print(b);
    Serial.println(bVal);
    delay(dly);
  }

  gVal = 255;
  rVal = 0;
  for (bVal = 0; bVal <= 255; bVal++) {
    analogWrite(rPin, rVal);
    analogWrite(gPin, gVal);
    analogWrite(bPin, bVal);
    Serial.print(r);
    Serial.print(rVal);
    Serial.print(g);
    Serial.print(gVal);
    Serial.print(b);
    Serial.println(bVal);
    delay(dly);
  }

  bVal = 255;
  rVal = 0;
  for (gVal = 255; gVal >= 0; gVal--) {
    analogWrite(rPin, rVal);
    analogWrite(gPin, gVal);
    analogWrite(bPin, bVal);
    Serial.print(r);
    Serial.print(rVal);
    Serial.print(g);
    Serial.print(gVal);
    Serial.print(b);
    Serial.println(bVal);
    delay(dly);
  }

  bVal = 255;
  gVal = 0;
  for (rVal = 0; rVal <= 255; rVal++) {
    analogWrite(rPin, rVal);
    analogWrite(gPin, gVal);
    analogWrite(bPin, bVal);
    Serial.print(r);
    Serial.print(rVal);
    Serial.print(g);
    Serial.print(gVal);
    Serial.print(b);
    Serial.println(bVal);
    delay(dly);
  }

  rVal = 255;
  gVal = 0;
  for (bVal = 255; bVal >= 0; bVal--) {
    analogWrite(rPin, rVal);
    analogWrite(gPin, gVal);
    analogWrite(bPin, bVal);
    Serial.print(r);
    Serial.print(rVal);
    Serial.print(g);
    Serial.print(gVal);
    Serial.print(b);
    Serial.println(bVal);
    delay(dly);
  }
}
