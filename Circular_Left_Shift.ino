int latchPin = 11, clockPin = 10, dataPin = 12, maxLED = 255;
int dly = 250;
//byte LEDs[] = {
//  0b10000000,
//  0b01000000,
//  0b00100000,
//  0b00010000,
//  0b00001000,
//  0b00000100,
//  0b00000010,
//  0b00000001,
//  0b10000000
//};
byte LEDs[] = {
  128,
  64,
  32,
  16,
  8,
  4,
  2,
  1,
  128
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  for (int i = 0; i <9; i++ ) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, LEDs[i]);
    digitalWrite(latchPin, HIGH);
    Serial.print("DEC: ");
    Serial.println(LEDs[i], DEC);
    delay(dly);
  }
  //  digitalWrite(latchPin, LOW);
  //  shiftOut(dataPin, clockPin, LSBFIRST, LED);
  //  digitalWrite(latchPin, HIGH);
  //  Serial.print("DEC: ");
  //  Serial.println(LED, DEC);
  //  delay(dly);
  //  LED = LED * 2;
  //  digitalWrite(latchPin, LOW);
  //  shiftOut(dataPin, clockPin, LSBFIRST, LED);
  //  digitalWrite(latchPin, HIGH);
  //  Serial.print("DEC: ");
  //  Serial.println(LED, DEC);
  //  delay(dly);
}
