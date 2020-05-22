int buttonPin=2, motorPin=10, buttonState=0;

void setup() {
  // put your setup code here, to run once:
pinMode(motorPin, OUTPUT);
pinMode(buttonPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
buttonState=digitalRead(buttonPin);
if(buttonState== HIGH){
  digitalWrite(motorPin, HIGH);
}
else{
  digitalWrite(motorPin, LOW);
}
}
