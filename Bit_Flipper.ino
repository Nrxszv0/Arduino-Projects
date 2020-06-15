int latchPin = 11, clockPin = 10, dataPin = 12, maxLED = 255;
int dly = 250;
byte LED = 0xAA;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, LED);
  digitalWrite(latchPin, HIGH);
  Serial.print("DEC: ");
  Serial.println(LED, DEC);
  LED = 255-LED;
  delay(dly);
}
