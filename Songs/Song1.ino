int piezPin = 13, noteLen = 10, dly = 100, bpm = 60;
float wholeNt = 4 * (60 / bpm);
float halfNt = 2 * (60 / bpm);
float quarterNt = 60 / bpm;
float eighhtNt = .5 * (60 / bpm);
float sixteenthNt = .25 * (60 / bpm);

int notes[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494};
//            mid C  C#   D    D#   E    F    F#   G    G#   A    A#   B
//String b0S = "Button 0 was pressed", b1S = "Button 1 was pressed", b2S = "Button 2 was pressed", b3S = "Button 3 was pressed", b4S = "Button 4 was pressed", b5S = "Button 5 was pressed", b6S = "Button 6 was pressed";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:



}
