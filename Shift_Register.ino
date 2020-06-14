int latchPin=11, clockPin=10,dataPin=12;
int dly=250;
byte LEDs=0b00000000, LED2s=0b00000001;
void setup() {
  // put your setup code here, to run once:
pinMode(latchPin, OUTPUT);
pinMode(dataPin, OUTPUT);
pinMode(clockPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(latchPin, LOW);
shiftOut(dataPin,clockPin,LSBFIRST,LEDs);
digitalWrite(latchPin,HIGH);
delay(dly);

digitalWrite(latchPin, LOW);
shiftOut(dataPin,clockPin,LSBFIRST,LED2s);
digitalWrite(latchPin,HIGH);
delay(dly);
}
