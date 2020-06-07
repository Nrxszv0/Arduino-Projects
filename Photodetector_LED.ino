int photoPin = A0, photoVal, rPin = 2, gPin = 3, rVal = 700;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  photoVal = analogRead(photoPin);
  Serial.println(photoVal);
  if (photoVal >= rVal) {
    digitalWrite(rPin, HIGH);
    digitalWrite(gPin, LOW);
  }
  else {
    digitalWrite(gPin, HIGH);
    digitalWrite(rPin, LOW);
  }
}
