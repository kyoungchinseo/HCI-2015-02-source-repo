#include <SPI.h>
#include <Ethernet.h>

// mac address of ethernet shield
byte mac[] = { 0x90, 0xA2, 0xDA, 0x0E, 0xF7, 0x3B };
// ip address of ethernet shield that you set (at 192.168.1.1)
//IPAddress ip(192,168,1,12);
IPAddress ip(192,168,0,4);


// server port number that you set
int port = 8001;

int ledPin = 9;
boolean LEDON = false;
// string buffer for recieved request string
String buffer;

EthernetServer server(80);

void setup() {
  Serial.begin(9600);
  Serial.println("Serial is set");
  
  // begin server(ethernet shield)
  Ethernet.begin(mac, ip);
  Serial.println("Ethernet began");
  server.begin();
  // check server ip
  Serial.print("server is at");
  Serial.println(Ethernet.localIP());
  
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // client = availalbe client(browser)
  EthernetClient client = server.available();
  
  // if there's any available client
  if (client) {
    Serial.println("new client");
    // init buffer
    buffer = String("");
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      // if there's something to read in stream
      if(client.available()) {
        // c = one character read
        char c = client.read();
        // and append c to buffer
        buffer.concat(c);
        
        // when you read all request string
        if (c == '\n' && currentLineIsBlank) {
          
          // String.indexOf("some string") > -1  ==  "some string" exists in String
          // check GET parameter, and process LEDON value
          if(buffer.indexOf("GET /L=0") > -1) {
            LEDON = false;
            digitalWrite(ledPin, LOW);
          }
          if(buffer.indexOf("GET /L=1") > -1) {
            LEDON = true;
            digitalWrite(ledPin, HIGH);
          }
          
          // send HTML page for response
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          client.println("<body>");
          client.print("LED is ");
          (LEDON)? client.print("on") : client.print("off");
          client.println("<br>");
          client.print("Make it ");
          (LEDON) ? client.print("<a href='L=0'>OFF</a>") : client.print("<a href='L=1'>ON</a>");
          client.println("<br>");
          client.println("</body>");
          client.println("</html>");
          // break while loop
          break;
        }
        // some process for checking end of request string
        if (c == '\n') {
          currentLineIsBlank = true;
        }
        else if (c != '\r') {
          currentLineIsBlank = false;
        }
      }
    }
    delay(1);
    
    client.stop();
    Serial.println("client disconnected");
  }
}
