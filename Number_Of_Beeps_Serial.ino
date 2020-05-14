int piezoPin = 13, dly = 300, beepsVal, piezoVal = 500, len = 250;
String msgB = "Enter the number of piezo beeps: " , msgPV = "Enter the value of the piezo tone: ";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(piezoPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msgB);
  while (Serial.available() == 0) {

  }
  beepsVal = Serial.parseInt();

  Serial.println(msgPV);
  while (Serial.available() == 0) {

  }
  piezoVal = Serial.parseInt();
  for (int i = 0; i < beepsVal; i++) {
    tone(piezoPin, piezoVal, len);
    delay(dly);
    noTone(piezoPin);
  }


}
