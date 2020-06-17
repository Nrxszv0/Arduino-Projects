int echoPin = 13, trigPin = 12;
int pingTime, sDly = 10, dly = 25;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(sDly);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(sDly);
  digitalWrite(trigPin, LOW);
  pingTime = pulseIn(echoPin, HIGH);
  delay(dly);
  Serial.println(pingTime);
}
