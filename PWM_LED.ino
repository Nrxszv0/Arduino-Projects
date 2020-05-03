int pin1 = 11, anlgVal = 10;
void setup() {
  // put your setup code here, to run once:
pinMode(pin1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(pin1, anlgVal);

}
