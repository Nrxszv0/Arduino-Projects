#include "pitches.h"
int piezoPin = 13, dly=100;
int notes[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
int noteLengths[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};
void setup() {
  // put your setup code here, to run once:
//  for (int currentNote = 0; currentNote < 8; currentNote++) {
//    int noteLength = 1000 / noteLengths[currentNote];
//    tone(piezoPin, notes[currentNote], noteLength);
//    int notesPause = noteLength * 1.30;
//    delay(notesPause);
//    noTone(piezoPin);
//  }
}

void loop() {
  // put your main code here, to run repeatedly:
    for (int currentNote = 0; currentNote < 8; currentNote++) {
    int noteLength = 1000 / noteLengths[currentNote];
    tone(piezoPin, notes[currentNote], noteLength);
    int notesPause = noteLength * 1.30;
    delay(notesPause);
    noTone(piezoPin);
  }
  delay(dly);

}
