int latchPin = 11, clockPin = 10, dataPin = 12, maxLED = 255;
int dly = 250;
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
byte LED = 0b00010011;
byte sLED;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  sLED = LED;
}

void loop() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, LED);
  digitalWrite(latchPin, HIGH);
  Serial.print("DEC: ");
  Serial.println(LED, DEC);
  LED = (LED/128) + (LED * 2);  
  delay(dly);
}
