#include <DHT.h>
#define TYPE DHT11
int sensPin=13, dly =250;
DHT HT(sensPin, TYPE);
float humidity, tempC, tempF;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
HT.begin();
delay(dly);
}
void loop() {
  // put your main code here, to run repeatedly:
humidity = HT.readHumidity();
tempC=HT.readTemperature();
tempF=HT.readTemperature(true); // reads in fahrenheit with true

Serial.print("Humidity: ");
Serial.print(humidity);
Serial.print("\t\tTemperature C: ");
Serial.print(tempC);
Serial.print("\t\tTemperature F: ");
Serial.println(tempF);
}
