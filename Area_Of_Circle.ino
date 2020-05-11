float rad, area, pi=3.14;
String serMsg = "What is the circle's radius", msg2 = "The area of the circle is: ";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println(serMsg);
  while (Serial.available() == 0) {

  }
  rad = Serial.parseFloat();
  area= pi*rad*rad;
  Serial.print(msg2);
  Serial.println(area);

}
