int rPin = 11, bPin = 12, gPin = 13;
String myCol, msg = "What color do you want? ", r = "red", g = "green", b = "blue", o = "off", aq="aqua", ye="yellow";
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
  while (Serial.available() == 0) {

  }
  myCol = Serial.readString();
  if (myCol == r) {
    digitalWrite(rPin, HIGH);
    digitalWrite(gPin, LOW);
    digitalWrite(bPin, LOW);
  }
  if (myCol == g) {
    digitalWrite(rPin, LOW);
    digitalWrite(gPin, HIGH);
    digitalWrite(bPin, LOW);
  }
  if (myCol == b) {
    digitalWrite(rPin, LOW);
    digitalWrite(gPin, LOW);
    digitalWrite(bPin, HIGH);
  }
  if (myCol == o) {
    digitalWrite(rPin, LOW);
    digitalWrite(gPin, LOW);
    digitalWrite(bPin, LOW);
  }
  if (myCol == aq) {
    digitalWrite(rPin, LOW);
    analogWrite(gPin, 255);
    analogWrite(bPin, 255);
  }
  if (myCol == ye) {
    analogWrite(rPin, 255);
    analogWrite(gPin, 255);
    analogWrite(bPin, 0);
  }

}
