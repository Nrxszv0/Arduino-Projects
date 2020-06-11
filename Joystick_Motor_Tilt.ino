int speedPin = 5, dirP1 = 6, dirP2 = 7, mSpeed = 100, boostTime = 25, boostSpeed = 255;
int tiltPin = 8, tiltState, tipSpeed = 0;
int xPin = A0, yPin = A1, sPin = 2, xVal, yVal, sVal, midSpeed=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(speedPin, OUTPUT);
  pinMode(dirP1, OUTPUT);
  pinMode(dirP2, OUTPUT);
  pinMode(tiltPin, INPUT);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(sPin, INPUT);
  digitalWrite(sPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  sVal = digitalRead(sPin);
  tiltState = digitalRead(tiltPin);
  Serial.print("x Value: ");
  Serial.print(xVal);
  Serial.print("\t\ty Value: ");
  Serial.print(yVal);
  Serial.print("\t\ts Value: ");
  Serial.print(sVal);
  Serial.print("\t\ttValue: ");
  Serial.print(tiltState);
  if (millis() <= boostTime && tiltState == HIGH) {
    analogWrite(speedPin, boostSpeed);

  }
  
  if (yVal > 521 && tiltState==HIGH) {
    mSpeed = map(yVal, 521, 1023, 0, 255);
    digitalWrite(dirP1, HIGH);
    digitalWrite(dirP2, LOW);
    analogWrite(speedPin, mSpeed);
  }
  else if (yVal == 521) {
    digitalWrite(dirP1, LOW);
    digitalWrite(dirP2, LOW);
    analogWrite(speedPin, midSpeed);
  }
  else if(yVal < 521 && tiltState==HIGH) {
    mSpeed = map(yVal, 521, 0, 0, 255);
    digitalWrite(dirP1, LOW);
    digitalWrite(dirP2, HIGH);
    analogWrite(speedPin, mSpeed);
  }
  else if(tiltState ==LOW) {
    analogWrite(speedPin, tipSpeed);
  }
  Serial.print("\t\tmSpeed: ");
  Serial.println(mSpeed);
  delay(100);

}
