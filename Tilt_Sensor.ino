int tiltPin=2, tiltState;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(tiltPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
tiltState = digitalRead(tiltPin);
Serial.println(tiltState);
}
