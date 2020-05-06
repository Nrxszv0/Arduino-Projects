int tempPin = A0, gPin = 13, yPin = 12, rPin = 11, dly=100, bdly=250;
float tempC = 20, valTemp, volt, tempF;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(gPin, OUTPUT);
  pinMode(yPin, OUTPUT);
  pinMode(rPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  valTemp = analogRead(tempPin);
  Serial.print("Temperature sensor value: ");
  Serial.print(valTemp);
  volt = (valTemp / 1023.) * 5.;
  Serial.print(" voltage: ");
  Serial.print(volt);

  tempC = (volt - .5) * 100;
  Serial.print(" temperature Celsius: ");
  Serial.print(tempC);
  tempF = (tempC * 1.8) + 32;
  Serial.print(" temperature Fahrenheit: ");
  Serial.println(tempF);
  if (tempF < 70) {
    digitalWrite(gPin, LOW);
    digitalWrite(yPin, LOW);
    digitalWrite(rPin, LOW);
  }

  else if (tempF > 70 && tempF < 75) {
    digitalWrite(gPin, HIGH);
    digitalWrite(yPin, LOW);
    digitalWrite(rPin, LOW);
  }

  else if (tempF > 75 && tempF < 80) {
    digitalWrite(gPin, LOW);
    digitalWrite(yPin, HIGH);
    digitalWrite(rPin, LOW);
  }

  else if (tempF > 80 && tempF < 85) {
    digitalWrite(gPin, LOW);
    digitalWrite(yPin, LOW);
    digitalWrite(rPin, HIGH);
  }

  else if (tempF > 85) {
    digitalWrite(yPin, LOW);
    digitalWrite(rPin, LOW);
    digitalWrite(gPin, HIGH);
    delay(dly);
    digitalWrite(gPin, LOW);
    digitalWrite(yPin, HIGH);
    delay(dly);
    digitalWrite(yPin, LOW);
    digitalWrite(rPin, HIGH);
    delay(dly);
    
  }



}
