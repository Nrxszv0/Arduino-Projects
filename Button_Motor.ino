int buttonPin = 13, motorPin = 2, buttonState = 0, buttonPin2 = 12, motorPin2 = 3, buttonState2 = 0;
String b1 = "Button 1 State: ", b2 = ", Button 2 State: ";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);
  Serial.print(b1);
  Serial.print(buttonState);
  Serial.print(b2);
  Serial.println(buttonState2);
  if (buttonState == HIGH) {
    digitalWrite(motorPin, HIGH);
  }
  else if (buttonState2 == HIGH) {
    digitalWrite(motorPin2, HIGH);
  }
  else {
    digitalWrite(motorPin, LOW);
    digitalWrite(motorPin2, LOW);
  }
}
