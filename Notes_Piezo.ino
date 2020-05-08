int piezPin = 13, toneVal = 0, noteLen=10, dly=250;;
int notes[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
//            mid C  C#   D    D#   E    F    F#   G    G#   A 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<noteLen;i++) {
    tone(piezPin, notes[i]);
    delay(dly);
  }
  noTone(piezPin);
}
