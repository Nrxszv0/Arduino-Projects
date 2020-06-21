int w, r, r2, g, b, y;
int minVal = 20;
int wPins[]  = {
  13, 12, 11, 10, 9, 8
};
int rPins[] = {
  7, 6, 5, 4, 3, 2, 22, 23, 24, 25, 26, 27, 28, 29, 30
};
void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
  for (int i = 0; i <= 53; i++) {
    if (i != 0 && i != 1 && i != 14 && i != 15 && i != 16 && i != 17 && i != 18 && i != 19 && i != 20 && i != 21 ) {
      pinMode(i, OUTPUT);
      Serial.println(i);
    }

  }

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i <= 53; i++) {
    if (i != 0 && i != 1 && i != 14 && i != 15 && i != 16 && i != 17 && i != 18 && i != 19 && i != 20 && i != 21 ) {
      digitalWrite(i, HIGH);
    }

  }



}
