String myName, msg = "What is the your name? ", msg2 = "Hello ", msg3 = "Welcome to Arduino!";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 
    Serial.println(msg);
    while (Serial.available()==0) {
  
    }
    myName = Serial.readString();
    Serial.print(msg2);
    Serial.println(myName);
    Serial.println(msg3);

}
