#include <SPI.h>
#include <Ethernet.h>

// mac address of ethernet shield
byte mac[] = { 0x90, 0xA2, 0xDA, 0x0E, 0xF7, 0x3B };
// ip address of ethernet shield that you set (at 192.168.1.1)
//IPAddress ip(192,168,1,12);
IPAddress ip(192,168,0,4);
// server port number that you set
int port = 8001;
// ip address of server
//IPAddress server(192, 168, 1, 10);
IPAddress server(192, 168, 0, 2);

int ledPin = 9;
int buttonPin = 2;
int prevVal, buttonVal;
boolean LEDON = false;

EthernetClient client;

void setup() {
  Serial.begin(9600);
  delay(1000);
  
  // pull_up for button
  pinMode(2, INPUT_PULLUP);
  prevVal = buttonVal = LOW;
  pinMode(ledPin, OUTPUT);
  
  Ethernet.begin(mac, ip);
  
  // connect with server
  if (client.connect(server, port)) {
    Serial.println("server connected");
  } else {
    Serial.println("connection failed...");
  }
}


void loop() {

  // inversing value; it is (LOW->HIGH) when button is pushed.
  buttonVal = (HIGH - digitalRead(buttonPin));
  
  if(buttonVal != prevVal) {
    // when it is pressed, not during pressed
    prevVal = buttonVal;
    if(buttonVal == HIGH) {
      Serial.println("Button");
      // send '1' to server for request
      client.print("1");
    }
  }
  
  // if there's something to read in stream
  if (client.available()) {
    char c = client.read();
    Serial.print("recieved : ");
    Serial.println(c);
    
    // set 'LEDON' value true/false, when recieved values is '1'/'0'
    if(c == '1') {Serial.println("LEDON"); LEDON = true;}
    if(c == '0') {Serial.println("LEDOFF"); LEDON = false;}
  }
  
  // set LED ON/OFF when LEDON value is true/false
  if(LEDON == true){
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}



