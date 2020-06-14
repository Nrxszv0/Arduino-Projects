int latchPin = 11, clockPin = 10, dataPin = 12, maxLED=255;
int dly = 250;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {

  for (byte LED = 0b00000000; LED <= maxLED; LED++) {
    Serial.print("BIN: ");
    Serial.print(LED, BIN);  
    Serial.print(" = ");    
    Serial.print("HEX: ");
    Serial.print(LED, HEX);
    Serial.print(" = ");
    Serial.print("DEC: ");
    Serial.println(LED, DEC);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, LED);
    digitalWrite(latchPin, HIGH);
    delay(dly);
  }
}
