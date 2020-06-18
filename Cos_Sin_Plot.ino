float co =5,si=5;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  co = cos(co);
  si = sin(si);
Serial.print(0);
Serial.print(",");
Serial.print(co);
Serial.print(",");
Serial.print(si);
Serial.print(",");
Serial.println(10);
}
