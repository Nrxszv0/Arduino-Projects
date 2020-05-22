int rLED=11, rVal, yLED=12, yVal, gLED=13,gVal;
String msg="Do you want to turn on the Red, Yellow, or Green LED?", ans;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(rLED, OUTPUT);
  pinMode(yLED, OUTPUT);
  pinMode(gLED, OUTPUT);
  Serial.println(msg);
  while(Serial.available() == 0) {
    
  }
  ans=Serial.readString();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(ans);
  if(ans == "red") {
    digitalWrite(rLED, HIGH);
  }
  
  else if(ans =="yellow") {
    digitalWrite(yLED, HIGH);
  }

  else if(ans =="green") {
    digitalWrite(gLED, HIGH);
  }
 

}
