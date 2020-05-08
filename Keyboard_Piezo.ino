int piezPin = 13, toneVal = 0, noteLen = 10, dly = 250, b1Pin = 6, b2Pin = 7, b3Pin = 8, b4Pin = 9, b5Pin = 10, b6Pin = 11, b7Pin = 12;
int notes[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
//            mid C  C#   D    D#   E    F    F#   G    G#   A
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(b1Pin, INPUT);
  pinMode(b2Pin, INPUT);
  pinMode(b3Pin, INPUT);
  pinMode(b4Pin, INPUT);
  pinMode(b5Pin, INPUT);
  pinMode(b6Pin, INPUT);
  pinMode(b7Pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < noteLen; i++) {
    tone(piezPin, notes[i]);
    delay(dly);
  }
  noTone(piezPin);
}
