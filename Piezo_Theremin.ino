int piezoPin = 10, piezoVal, sensVal, sensHigh = 0, sensLow = 1023, tinyLedPin = 13, sensPin = A0, pitch, maxPitch = 4978, minPitch = 31, duration = 20, dly = 10;
String sensST = "Sensor Value: ", pitchST = ", Pitch Value: ", serMessage = "Please Wait\nThe sensor is calibrating", lowST = "Sensor Low: ", highST = ", Sensor High: ";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(tinyLedPin, OUTPUT);
  digitalWrite(tinyLedPin, HIGH);
  Serial.println(serMessage);
  while (millis() < 5000) {
    sensVal = analogRead(sensPin);
    if (sensVal > sensHigh) {
      sensHigh = sensVal;
    }
    if (sensVal < sensLow) {
      sensLow = sensVal;
    }
  }

  digitalWrite(tinyLedPin, LOW);
  Serial.print(sensST);
  Serial.print(sensLow);
  Serial.print(highST);
  Serial.print(sensHigh);
  Serial.print("\n");

}

void loop() {
  // put your main code here, to run repeatedly:
  sensVal = analogRead(sensPin);
  pitch = map(sensVal, sensLow, sensHigh, 50, 4000);
  Serial.print(sensST);
  Serial.print(sensVal);
  Serial.print(pitchST);
  Serial.println(pitch);
  tone(piezoPin, pitch, duration);
  delay(dly);
}
