int rpin = 5, gpin=6, bpin=7, rdly= 200, gdly=300, bdly=400, dly = 500, i;
void setup() {
  // put your setup code here, to run once:
  pinMode(rpin, OUTPUT);
  pinMode(bpin, OUTPUT);
  pinMode(gpin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

for(i=0; i<5; i++) {
  digitalWrite(rpin, HIGH);
  delay(rdly);
  digitalWrite(rpin, LOW);
  delay(rdly);
}

for(i=0; i<10; i++) {
  digitalWrite(gpin, HIGH);
  delay(gdly);
  digitalWrite(gpin, LOW);
  delay(gdly);
}

for(i=0; i<15; i++) {
  digitalWrite(bpin, HIGH);
  delay(bdly);
  digitalWrite(bpin, LOW);
  delay(bdly);
}

delay(dly);
}
