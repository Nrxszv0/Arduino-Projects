int latchPin = 11, clockPin = 10, dataPin = 12;
int dly = 250;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {

  for (byte LED = 0b00000000; LED <= 255; LED++) {
    Serial.print(LED, BIN);
    Serial.print(" = ");
    Serial.print(LED, HEX);
    Serial.print(" = ");
    Serial.println(LED, DEC);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, LED);
    digitalWrite(latchPin, HIGH);
    delay(dly);

  }
}
