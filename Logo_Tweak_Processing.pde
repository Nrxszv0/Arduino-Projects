import processing.serial.*;
Serial port;
PImage img;
int bgColor=0;
void setup() {
  size(1, 1);
  surface.setResizable(true);
  colorMode(HSB, 255);
  img=loadImage("http://arduino.cc/arduino_logo.png");
  surface.setSize(img.width, img.height);
  println("Available serial ports:");
  //println(Serial.list());
  port= 
    new Serial(this, "COM5", 9600);
}
void draw() {
  if (port.available() > 0) {
    bgColor=port.read();
    println(bgColor);
  }
  background(bgColor, 255, 255);
  image(img, 0, 0);
}
