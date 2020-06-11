int speedPin=5, dirP1=6, dirP2=7, mSpeed=100;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(speedPin, OUTPUT);
pinMode(dirP1, OUTPUT);
pinMode(dirP2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(dirP1, HIGH);
digitalWrite(dirP2, LOW);
if(millis() <=100){
  analogWrite(speedPin, 255);

}
else{
  analogWrite(speedPin, mSpeed);
}

}
