PImage img;

boolean drawKernel = false;

float[][] kernel = { { .111, .111, .111 }, { .111, 8, .111 },
{ .111, .111, .111 }};

void setup() {
  img = loadImage("test.jpg"); 
  size(img.width, img.height); 
}

void draw() {
  img.loadPixels(); 
  
  PImage kerneledImg = createImage(width, height, RGB);
  
  for (int y = 1; y < height-1; y++) { // Skip top and bottom edges
    for (int x = 1; x < width-1; x++) { // Skip left and right edges
      float sum = 0; 
      
      for(int kernely = -1; kernely <=1; kernely++) {
        for(int kernelx = -1; kernelx <=1; kernelx++) {
          int pos = (y + kernely)*width + (x + kernelx);
          float val = red(img.pixels[pos]);

          sum += kernel[kernely+1][kernelx+1] * val;
        }
      }
      kerneledImg.pixels[y* width + x] = color(sum);
    }
  }    
  kerneledImg.updatePixels();
  if (drawKernel) {
    image(kerneledImg, 0, 0);
  } else {
    image(img,0,0);
  }
}

void keyPressed() {
  drawKernel = !drawKernel;
}
