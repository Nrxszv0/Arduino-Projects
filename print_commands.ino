int i, dly = 25, j;
String varString = "var = ", mess1 ="A circle with radis ", mess2=" has an area of ", prd=".";
float pi = 3.14, area;
int r;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (i = 0; i < 250; i++) {
    Serial.print(i);
    delay(dly);
  }

  for (j = 255; j > 0; j--) {
    Serial.println(varString + j);
    delay(dly);
  }
  for (int h = 0; h < 100; h++) {
    Serial.println(" hellooo");
    delay(dly);
  }

  for (r = 1; r <= 100; r++) {
    area = r * r * pi;
    Serial.print(mess1);
    Serial.print(r);
    Serial.print(mess2);
    Serial.print(area);
    Serial.println(prd);
    delay(50);
  }

}
