int voltPin=A2, readVal, dly=100, ledPin=11;
float v2, ledVal;
String ledString="LED has a value of ", potString=" with a voltage of ";

void setup() {
  // put your setup code here, to run once:
pinMode(ledPin, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  readVal=analogRead(voltPin);
  v2=(5./1023.) *readVal;
  ledVal=(readVal*255.)/(1023.);
  analogWrite(ledPin, ledVal);
 
  Serial.print(ledString);
  Serial.print(ledVal);
  Serial.print(potString);
  Serial.println(v2);
  delay(dly);

}
