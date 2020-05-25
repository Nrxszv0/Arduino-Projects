import processing.serial.*;
Serial port;
PImage img;
int bgColor=0, saturation=255, brightness=255, x=0,y=0, baud=9600, maxVal=255;
String url="https://arduino.cc/arduino_logo.png", serMsg="Available serial ports:";
void setup() {
  size(1, 1);
  surface.setResizable(true);
  colorMode(HSB, maxVal);
  img=loadImage(url);
  surface.setSize(img.width, img.height);
  println(serMsg);
  println(Serial.list());
  port= 
    new Serial(this, Serial.list()[1], baud);
}
void draw() {
  if (port.available() > 0) {
    bgColor=port.read();
    println(bgColor);
  }
  background(bgColor, saturation, brightness);
  image(img, x, y);
}
