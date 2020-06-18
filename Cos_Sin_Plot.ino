float cosVal, sinVal, i;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (i = 0; i <= 2 * 3.141519265; i = i + .01) {
    cosVal = cos(i*2)+2;
    sinVal = sin(i*9)-3l;
    Serial.print(cosVal);
    Serial.print(",");
    Serial.println(sinVal);
  }


}
