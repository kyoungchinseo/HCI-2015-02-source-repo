void setup() {
  size(800,800);
  
}

void draw() {
  background(0,0,0);
  for (int i=0;i<50;i++) {
    ellipse(400-(400 - mouseX)/50.0 * i,
            400-(400 - mouseY)/50.0 * i,
            i*2,
            i*2);    
    fill(255,255,255);
  }  
}
