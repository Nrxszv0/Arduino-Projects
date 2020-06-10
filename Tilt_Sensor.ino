int tiltPin=2, tiltState, tiltPin2=2, tiltState2;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(tiltPin, INPUT);
pinMode(tiltPin2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
tiltState = digitalRead(tiltPin);
tiltState2 = digitalRead(tiltPin2);
Serial.print(tiltState);
Serial.print("\t\t");
Serial.println(tiltState2);
}
