

String imgURL = "http://www.processing.org/img/learning/books/programming-interactivity.jpg";
PImage img;

void setup() {
  size(400, 400, P3D);
  noStroke();
  
  img = loadImage(imgURL);
  textureMode(NORMAL);  
}

void draw() {  
  beginShape();
    texture(img);
    vertex( 40, 80, 0, 0);
    vertex(320, 20, 0.5, 0);
    vertex(380,360, 0.5, 0.5);
    vertex(160,380, 0, 0.5);
  endShape();  
}

