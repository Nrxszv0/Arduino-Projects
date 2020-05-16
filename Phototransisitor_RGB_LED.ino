int redPhotoPin = A0, greenPhotoPin = A1, bluePhotoPin = A2, redLedPin = 9, greenLedPin = 10, blueLedPin = 11, redPhotoVal, redLedVal, greenPhotoVal, greenLedVal, bluePhotoVal, blueLedVal, dly = 10;
String redPhoto = "Red Photoresistor: ", greenPhoto = ", Green Photoresistor: ", bluePhoto = ", Blue Photoresistor: ", blueRGB = ", Blue RGB: ", redRGB = ", Red RGB: ", greenRGB = ", Green RGB: ";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  redPhotoVal = analogRead(redPhotoPin);
  greenPhotoVal = analogRead(greenPhotoPin);
  bluePhotoVal = analogRead(bluePhotoPin);
  redLedVal = redPhotoVal / 4;
  greenLedVal = greenPhotoVal / 4;
  blueLedVal = bluePhotoVal / 4;
  Serial.print(redPhoto);
  Serial.print(redPhotoVal);
  Serial.print(greenPhoto);
  Serial.print(greenPhotoVal);
  Serial.print(bluePhoto);
  Serial.print(bluePhotoVal);
  Serial.print(redRGB);
  Serial.print(redLedVal);
  Serial.print(greenRGB);
  Serial.print(greenLedVal);
  Serial.print(blueRGB);
  Serial.println(blueLedVal);
  analogWrite(redLedPin, redLedVal);
  analogWrite(greenLedPin, greenLedVal);
  analogWrite(blueLedPin, blueLedVal);
  delay(dly);
}
