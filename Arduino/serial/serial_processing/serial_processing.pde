import processing.opengl.*;
import processing.serial.*;

PImage img;

Serial port;
String buffer = null;
float r = 0.0;

void setup() {
  println(Serial.list());
  
  img = loadImage("next_bi.png");
  int sz = 0;
  if (img.width > img.height) {
    sz = img.width * 3;
  } else {
    sz = img.height * 3;
  }
  
  size(sz, sz, OPENGL);
  background(255,255,255);
  noStroke();

  port = new Serial(this, "COM4",9600); 
  
}

void draw() {
  while (port.available() > 0) {
    buffer = port.readStringUntil('\n');
    if (buffer != null) {
      String [] val = split(buffer,'\n');
      r = parseInt(val[0].trim())/100.0 * PI;
      println(r);
    }
  }
  
  background(255);
  translate(width / 2, height / 2);
  rotateZ(r);  
  beginShape();
    texture(img);
    vertex(-img.width,-img.height,0,0,0);
    vertex( img.width,-img.height,0,img.width, 0);
    vertex(img.width,img.height, 0,img.width, img.height);
    vertex(-img.width,img.height,0,0,img.height);
  endShape();  
}




 
