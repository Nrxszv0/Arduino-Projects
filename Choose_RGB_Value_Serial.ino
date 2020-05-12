int rPin = 11, bPin = 12, gPin = 13, rVal, gVal, bVal;
String msgR = "What red value do you want? ", msgG = "What green value do you want? ", msgB = "What blue value do you want? ";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println(msgR);
  while (Serial.available() == 0) {

  }
  rVal = Serial.parseInt();

  Serial.println(msgG);
  while (Serial.available() == 0) {

  }
  gVal = Serial.parseInt();

  Serial.println(msgB);
  while (Serial.available() == 0) {

  }
  bVal = Serial.parseInt();
  analogWrite(rPin, rVal);
  analogWrite(gPin, gVal);
  analogWrite(bPin, bVal);
}
