PImage pic;
int location = 0;

void setup()
{
  pic = loadImage("test.jpg");
  size(pic.width, pic.height);
}

void draw()
{
  background(255, 255, 255);
  image(pic, 0, 0);

  location = mouseY * width + mouseX;
  fill(pic.pixels[location]);
  
  int row = location / width;
  int pos = location - (row * width);
  rect(0, 0, 30, 30);
}
