float cosVal, sinVal, parab, x;
float cv2, cv3, cv4, cv5, cv6, cv7, cv8, cv9, cv10;
float sv2, sv3, sv4, sv5, sv6, sv7, sv8, sv9, sv10;
float par, par2, p;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//  for (x = 0; x <= 2 * 3.141519265; x = x + .01) {
//    cosVal = cos(x);
//    sinVal = sin(x);
//
//    cv2 = cos(x * x);
//    cv3 = cos(x) + x;
//    cv4 = cos(x) - x;
//    cv5 = cos(x * x * x);
//
//    Serial.print(cosVal);
//    Serial.print(",");
//    Serial.print(sinVal);
//    Serial.print(",");
//    Serial.print(cv2);
//    Serial.print(",");
//    Serial.print(cv3);
//    Serial.print(",");
//    Serial.print(cv4);
//    Serial.print(",");
//    Serial.println(cv5);
//
//
//  }
  for(p = -4; p<=4; p=p+0.01) {
    par=p*p;
    par2 = -p*p; 

    Serial.print(par);
    Serial.print(",");
    Serial.print(par2);
  }
  
}
