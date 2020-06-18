int trigPin = 12, echoPin = 13, pingTime;
int dly = 25, sDly = 10;
int rateMi = 767, rateFt, rateIn;
float tim, distance;
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
  Serial.print(pingTime);

  //  rateFt = rateMi * 5280;
  //  rateIn = rateFt * 12;
  //  Serial.println(rateIn);
  //  tim = .5 * pingTime;
  distance = ((rateMi)*(5280)*(12)*(1)*(1)) / ((1)*(1)*(1)*(3600)*(1000000)) * pingTime; //inches/microseconds
  Serial.print("\t\t");
  Serial.println(distance);
  delay(dly);
}
