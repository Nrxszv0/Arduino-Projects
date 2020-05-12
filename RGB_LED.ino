int rPin = 11, bPin = 12, gPin = 13;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(rPin,HIGH);
  digitalWrite(bPin,HIGH);
  digitalWrite(gPin,HIGH);
}
