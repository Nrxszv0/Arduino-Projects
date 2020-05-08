int piezPin = 13, noteLen = 10, dly = 50, b0Pin = 6, b1Pin = 7, b2Pin = 8, b3Pin = 9, b4Pin = 10, b5Pin = 11, b6Pin = 12, b0St = 0, b1St = 0, b2St = 0, b3St = 0, b4St = 0, b5St = 0, b6St = 0;
int notes[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
//            mid C  C#   D    D#   E    F    F#   G    G#   A
String b0S = "Button 0 was pressed", b1S = "Button 1 was pressed", b2S = "Button 2 was pressed", b3S = "Button 3 was pressed", b4S = "Button 4 was pressed", b5S = "Button 5 was pressed", b6S = "Button 6 was pressed";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(b0Pin, INPUT);
  pinMode(b1Pin, INPUT);
  pinMode(b2Pin, INPUT);
  pinMode(b3Pin, INPUT);
  pinMode(b4Pin, INPUT);
  pinMode(b5Pin, INPUT);
  pinMode(b6Pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  b0St = digitalRead(b0Pin);
  b1St = digitalRead(b1Pin);
  b2St = digitalRead(b2Pin);
  b3St = digitalRead(b3Pin);
  b4St = digitalRead(b4Pin);
  b5St = digitalRead(b5Pin);
  b6St = digitalRead(b6Pin);
  //  for (int i = 0; i < noteLen; i++) {
  //    tone(piezPin, notes[i]);
  //    delay(dly);
  //  }

  if (b0St == HIGH) {
    tone(piezPin, notes[0]);
    Serial.print(b0S);    
    
  }
  else {
    noTone(piezPin);
  }





}
