int trigPin = 12, echoPin = 13, pingTime;
int dly = 25, sDly = 10;
int rateMi = 767;
float  ft = 5280, in = 12;
float pingTravelDistance, targetDistance;
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
  Serial.print("Ping Time: ");
  Serial.print(pingTime);

  //  rateFt = rateMi * 5280;
  //  rateIn = rateFt * 12;
  //  Serial.println(rateIn);
  //  tim = .5 * pingTime;
  pingTravelDistance = (pingTime * 767.* 5280. *12.) / (3600. * 1000000.); //inches/microseconds
  targetDistance = pingTravelDistance / 2;
   Serial.print("\t\tPing Travel Distance: ");
  Serial.print(pingTravelDistance);
  Serial.print("\t\tTarget Distance: ");
  Serial.println(targetDistance);
  delay(dly);
}
