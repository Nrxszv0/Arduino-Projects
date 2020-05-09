#include "pitches.h"
int piezoPin = 13, dly = 100, bpm = 60, noteTot = 26; // quarter notes
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
int noteLengths[] = {
  1000, 1000, 1000, 1000,
  1000, 1000, 2000,
  1000, 1000, 2000,
  1000, 1000, 2000, //4
  1000, 1000, 1000, 1000,
  1000, 1000, 1000, 1000,
  1000, 1000, 1000, 1000,
  4000//8
};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int currentNote = 0; currentNote < noteTot; currentNote++) {
    float noteLength =  noteLengths[currentNote] * (60 / bpm); // For a quarter note on 60 bpm: 1000 * (60/60.
    tone(piezoPin, notes[currentNote], noteLength);
    Serial.println("A note just played");
    float notesPause = noteLength * 1.30;
    delay(notesPause);
    noTone(piezoPin);

  }
  //  delay(dly);
  //  int noteLength =  noteLengths[0] * (60000 / bpm); // For a quarter note on 60 bpm: 1000 * (60/60.
  //  tone(piezoPin, 500);
  //  Serial.println("A note just played");
  //  delay(100);
  //  noTone(piezoPin);
  //  delay(900);


}
