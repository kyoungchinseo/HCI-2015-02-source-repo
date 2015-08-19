int lightFlag = 0;

void setup() {
  size(400, 400, P3D);
}

void draw() {
  background(0);
  translate(200, 200, 0);
  switch(key)
  {
  case '1':
    lights();
    break;
  case '2':
    ambientLight(0,0,255);
    break;
  case '3':
    directionalLight(0,0,255,0,-1,-1);
    break;
  case '4':
    spotLight(255, 0, 0, width/2, height/2, 400, 0, 0, -1, PI/2, 2);
    break;
  case '5':
    pointLight(255, 0, 0, width/2, height/2, 400);
    break;
  }
  noStroke();
  fill(255);
  sphere(100);
}

