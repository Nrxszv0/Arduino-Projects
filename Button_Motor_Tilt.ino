int speedPin = 5, dirP1 = 6, dirP2 = 7, mSpeed = 0, boostTime = 25, boostSpeed = 255, dly=100;
int tiltPin = 8, tiltState, tipSpeed = 0;
int incPin = 10, decPin = 9, incVal = 5, incDecVal = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(speedPin, OUTPUT);
  pinMode(dirP1, OUTPUT);
  pinMode(dirP2, OUTPUT);
  pinMode(tiltPin, INPUT);
  pinMode(incPin, INPUT);
  pinMode(decPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  tiltState = digitalRead(tiltPin);
  if (digitalRead(incPin) == HIGH && tiltState == HIGH && mSpeed <= 255) {
    incDecVal += incVal;
    mSpeed = abs(incDecVal);
    analogWrite(speedPin, mSpeed);
  }
  else if (digitalRead(decPin) == HIGH && tiltState == HIGH && mSpeed <= 255) {
    incDecVal -= incVal;
    mSpeed = abs(incDecVal);
    analogWrite(speedPin, mSpeed);
  }
  else if (tiltState == LOW) {
    mSpeed = 0;
    analogWrite(speedPin, tipSpeed);
  }
  Serial.print("mSpeed: ");
  Serial.print(mSpeed);
  Serial.print("\t\tIDVal: ");
  Serial.print(incDecVal);
  Serial.print("\t\ttiltState: ");
  Serial.println(tiltState);
  if (incDecVal < 0) {
    digitalWrite(dirP1, HIGH);
    digitalWrite(dirP2, LOW);
  }
  else if (incDecVal > 0) {
    digitalWrite(dirP1, LOW);
    digitalWrite(dirP2, HIGH);
  }
  
  if ( mSpeed > 255) {
    mSpeed = 250;
    if(incDecVal > 0) {
      incDecVal=250;
    }
    else if(incDecVal <0){
      incDecVal=-250;
    }
  }
  delay(dly);
}
