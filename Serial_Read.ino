int readPin=A3, v2=0, dly=500;
void setup() {
  // put your setup code here, to run once:
pinMode(readPin,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
v2=analogRead(readPin);
Serial.println(v2);
delay(dly);
}
