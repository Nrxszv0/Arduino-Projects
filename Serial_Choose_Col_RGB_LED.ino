int rPin = 11, bPin = 12, gPin = 13;
String myCol, msg = "What color do you want? ";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println(msg);
  while(Serial.available()==0) {
    
  }
  myCol=Serial.readString();
  if(myCol == "red") {
    digitalWrite(rPin,HIGH);
    digitalWrite(gPin,LOW);
    digitalWrite(bPin,LOW);
  }
  if(myCol == "green") {
    digitalWrite(rPin,LOW);
    digitalWrite(gPin,HIGH);
    digitalWrite(bPin,LOW);
  }
  if(myCol == "blue") {
    digitalWrite(rPin,LOW);
    digitalWrite(gPin,LOW);
    digitalWrite(bPin,HIGH);
  }
  if(myCol == "off") {
    digitalWrite(rPin,LOW);
    digitalWrite(gPin,LOW);
    digitalWrite(bPin,LOW);
  }

}
