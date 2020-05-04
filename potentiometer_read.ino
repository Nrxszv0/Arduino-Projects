int voltPin=A2, readVal, dly=100;
float v2;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal=analogRead(voltPin);
  v2=(5./1023.) *readVal;
  Serial.println(v2);
  delay(dly);

}
