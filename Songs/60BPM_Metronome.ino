#include "pitches.h"
int piezoPin = 13, dly = 100, bpm = 60; // quarter notes
int notes[] = {
  NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4
};
int noteLengths[] = {
  250, 1000, 1000, 1000, 1000, 1000, 1000, 1000
};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //  for (int currentNote = 0; currentNote < 8; currentNote++) {
  //    int noteLength =  noteLengths[currentNote] * (60 / bpm); // For a quarter note on 60 bpm: 1000 * (60/60.
  //    tone(piezoPin, notes[currentNote], noteLength);
  //    Serial.println("A note just played");
  ////    int notesPause = noteLength * 1.30;
  //    delay(noteLength);
  //    noTone(piezoPin);
  //  }
  //  delay(dly);
  int noteLength =  noteLengths[0] * (60000 / bpm); // For a quarter note on 60 bpm: 1000 * (60/60.
  tone(piezoPin, 500);
  Serial.println("A note just played");
  delay(100);
  noTone(piezoPin);
  delay(900);
  

}
