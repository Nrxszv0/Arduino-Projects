int rLed = 13, yLed = 12, gLed = 11, dly = 1000;
String myLed, msg = "What LED do you want to light? Red, Yellow, or Green? ", msg2 = " is lit.", msg3 = "Pretty Cool", msg4 = "Error: Name is invalid", r = "Red", y = "Yellow", g = "Green";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(rLed, OUTPUT);
  pinMode(yLed, OUTPUT);
  pinMode(gLed, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg);
  while (Serial.available() == 0) {

  }
  myLed = Serial.readString();
  if (myLed == r) {
    digitalWrite(rLed, HIGH);
    digitalWrite(yLed, LOW);
    digitalWrite(gLed, LOW);
    delay(dly);
    Serial.print(myLed);
    Serial.println(msg2);
    Serial.println(msg3);

  }
  else if (myLed == y) {
    digitalWrite(yLed, HIGH);
    digitalWrite(rLed, LOW);
    digitalWrite(gLed, LOW);

    delay(dly);
    Serial.print(myLed);
    Serial.println(msg2);
    Serial.println(msg3);

  }

  else if (myLed == g) {
    digitalWrite(gLed, HIGH);
    digitalWrite(yLed, LOW);
    digitalWrite(rLed, LOW);
    delay(dly);
    Serial.print(myLed);
    Serial.println(msg2);
    Serial.println(msg3);

  }
  else {
    Serial.println(msg4);
  }



}
