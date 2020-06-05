#include "pitches.h"
int piezoPin = 10, dly = 123, noteTot = 26;
float bpm = 140; //quarter notes
int notes[] = {
  NOTE_E4, NOTE_D4, NOTE_C4, NOTE_D4,
  NOTE_E4, NOTE_E4, NOTE_E4,
  NOTE_D4, NOTE_D4, NOTE_D4,
  NOTE_E4, NOTE_E4, NOTE_E4, //4
  NOTE_E4, NOTE_D4, NOTE_C4, NOTE_D4,
  NOTE_E4, NOTE_E4, NOTE_E4, NOTE_C4,
  NOTE_D4, NOTE_D4, NOTE_E4, NOTE_D4,
  NOTE_C4//8
};
float noteLengths[] = {
  1, 1, 1, 1,
  1, 1, 2,
  1, 1, 2,
  1, 1, 2, //4
  1, 1, 1, 1,
  1, 1, 1, 1,
  1, 1, 1, 1,
  4//8
};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int currentNote = 0; currentNote < noteTot; currentNote++) {
    float noteLength =  (noteLengths[currentNote] * (60.0 / bpm)) * 1000.0;
    Serial.print("noteLength: ");
    Serial.print(noteLength);
    tone(piezoPin, notes[currentNote], noteLength);
    Serial.print(" A note just played ");
    float notesPause = noteLength * 1.30;
    Serial.print("notesPause: ");
    Serial.println(notesPause);
    delay(notesPause);
    noTone(piezoPin);
  }
}
