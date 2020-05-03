int bit1 = 13, bit2 = 12, bit3 = 11, bit4 = 10, dly = 1500, bdly = 3000;

void setup() {
  // put your setup code here, to run once:
  pinMode(bit1, OUTPUT);
  pinMode(bit2, OUTPUT);
  pinMode(bit3, OUTPUT);
  pinMode(bit4, OUTPUT);
}

void loop() {
  //1 0001
  //2 0010
  //3 0011
  //4 0100
  //5 0101
  //6 0110
  //7 0111
  //8 1000
  //9 1001
  //10 1010
  //11 1011
  //12 1100
  //13 1101
  //14 1110
  //15 1111
  digitalWrite(bit4, LOW);
  digitalWrite(bit3, LOW);
  digitalWrite(bit2, LOW);
  digitalWrite(bit1, HIGH);
  delay(dly);

  digitalWrite(bit4, LOW);
  digitalWrite(bit3, LOW);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit1, LOW);
  delay(dly);

  digitalWrite(bit4, LOW);
  digitalWrite(bit3, LOW);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit1, HIGH);
  delay(dly);

  digitalWrite(bit4, LOW);
  digitalWrite(bit3, HIGH);
  digitalWrite(bit2, LOW);
  digitalWrite(bit1, LOW);
  delay(dly);

  digitalWrite(bit4, LOW);
  digitalWrite(bit3, HIGH);
  digitalWrite(bit2, LOW);
  digitalWrite(bit1, HIGH);
  delay(dly);

  digitalWrite(bit4, LOW);
  digitalWrite(bit3, HIGH);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit1, LOW);
  delay(dly);

  digitalWrite(bit4, LOW);
  digitalWrite(bit3, HIGH);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit1, HIGH);
  delay(dly);

  digitalWrite(bit4, HIGH);
  digitalWrite(bit3, LOW);
  digitalWrite(bit2, LOW);
  digitalWrite(bit1, LOW);
  delay(dly);

  digitalWrite(bit4, HIGH);
  digitalWrite(bit3, LOW);
  digitalWrite(bit2, LOW);
  digitalWrite(bit1, HIGH);
  delay(dly);

  digitalWrite(bit4, HIGH);
  digitalWrite(bit3, LOW);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit1, LOW);
  delay(dly);

  digitalWrite(bit4, HIGH);
  digitalWrite(bit3, LOW);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit1, HIGH);
  delay(dly);

  digitalWrite(bit4, HIGH);
  digitalWrite(bit3, HIGH);
  digitalWrite(bit2, LOW);
  digitalWrite(bit1, LOW);
  delay(dly);

  digitalWrite(bit4, HIGH);
  digitalWrite(bit3, HIGH);
  digitalWrite(bit2, LOW);
  digitalWrite(bit1, HIGH);
  delay(dly);

  digitalWrite(bit4, HIGH);
  digitalWrite(bit3, HIGH);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit1, LOW);
  delay(dly);

  digitalWrite(bit4, HIGH);
  digitalWrite(bit3, HIGH);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit1, HIGH);
  delay(dly);

  delay(bdly);
}
