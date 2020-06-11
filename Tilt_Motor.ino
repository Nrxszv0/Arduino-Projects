int speedPin = 5, dirP1 = 6, dirP2 = 7, mSpeed = 100, boostTime=25, boostSpeed=255;
int tiltPin=8, tiltState, tipSpeed = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(speedPin, OUTPUT);
  pinMode(dirP1, OUTPUT);
  pinMode(dirP2, OUTPUT);
  pinMode(tiltPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  tiltState = digitalRead(tiltPin);
  Serial.println(tiltState);
  digitalWrite(dirP1, HIGH);
  digitalWrite(dirP2, LOW);
  if (millis() <= boostTime &&tiltState== HIGH) {
    analogWrite(speedPin, boostSpeed);

  }
  else if(tiltState == HIGH) {
    analogWrite(speedPin, mSpeed);
  }
  else{
    analogWrite(speedPin, tipSpeed);
  }

}
