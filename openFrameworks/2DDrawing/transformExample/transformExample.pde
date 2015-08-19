float rotateAmt = 0.0;

void setup() {
    size(700, 700);
}

void draw() {
  background(122);
  pushMatrix();
      translate(100, 100);
        fill(255,0,0,100);        
        rect(250, 250, 200, 200);
        pushMatrix();
          fill(0,255,0, 100);
          translate(mouseX - 350,100);          
          rect(100, 100, 200, 200);
          pushMatrix();
              fill(0,0,255, 100);
              translate(100,mouseY - 350);
              rect(100, 100, 200, 200);
              pushMatrix();
                fill(255,255,255,100);                
                rotate(PI*rotateAmt);
                translate(-25,-25);
                rect(0,0,50,50);                
              popMatrix();
          popMatrix();
        popMatrix();
    popMatrix();    
    
    rotateAmt += 0.01;
}
