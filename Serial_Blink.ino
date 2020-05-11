int serBlinks, ledPin = 13, dly = 250;
String serMsg = "How many times do you want the LED to blink?", msg2 = "The LED blinked";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(ledPin, LOW);
  Serial.println(serMsg);
  while (Serial.available() == 0) {

  }
  serBlinks = Serial.parseInt();
  for (int i = 0; i < serBlinks; i++) {
    digitalWrite(ledPin, HIGH);
    delay(dly);
    digitalWrite(ledPin, LOW);
    delay(dly);
    Serial.println(msg2);
  }

}
