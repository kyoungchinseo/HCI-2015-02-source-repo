import processing.serial.*;     // import the Processing serial library
Serial myPort;
char val;


PImage img_on;
PImage img_off;
int blue = 255;
int red = 0;
int speed = 5;

void setup() {
  size(640, 360);
  
  img_on = loadImage("on.png");
  img_off = loadImage("off.png");
  
  println(Serial.list());

  //Choose usb adapter
  String portName = Serial.list()[2];
  println("portName:" + portName);
  //myPort = new Serial(this, portName, 9600);
  myPort = new Serial(this, "COM9", 9600);
}

void draw() {
  
  background(red, 0, blue);
  
  if ( mousePressed )
  {
    println("MousePressed");
    myPort.write('A');
    image(img_on, 285, 166);
  } else {
    image(img_off, 287, 166);
  }
  
  
  if ( myPort.available() > 0) {
    String buffer = myPort.readStringUntil('\n');
    println("DATA : " + buffer);    
    if (buffer != null) {
     String [] values = split(buffer,'\n');
     int value = parseInt(values[0].trim());
     println(value);
    if(value == 0) {      
      //blue = blue - speed;
      blue = 0;
      red = 255;            
    } else if (value == 1) {
      blue = 255;
      red = 0;
    } 
    }
  } 
  
}

