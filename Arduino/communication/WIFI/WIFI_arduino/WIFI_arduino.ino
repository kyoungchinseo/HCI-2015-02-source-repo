#include <SPI.h>
#include <WiFi.h>

char ssid[] = "next_wlan"; // network SSID
char pass[] = "!!@@##$$";  // network password

int ledPin = 9;
int buttonPin = 2;
int buttonState = 0;

int status = WL_IDLE_STATUS;
WiFiServer server(80);

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  Serial.begin(9600);
  while (!Serial) {
    ;
  }

  // check for the presence of the wifi-shield
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present"); 
    while(true);
  } 
  
  // attempt to connect to Wifi network
  while ( status != WL_CONNECTED) { 
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
    // wait 10 seconds for connection
    delay(10000);
  }
  server.begin();
  printWifiStatus();
}


void loop() {
  // listen for incoming clients
  WiFiClient client = server.available();
  if (client) {
    Serial.println("new client");
    String currentLine = "";
    boolean currentLineIsBlank = true;

    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        if (c == '\n' && currentLineIsBlank) {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");
          client.println("Refresh: 5");
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");

          // read the state of the pushbutton
          buttonState = digitalRead(buttonPin);
          if(buttonState == HIGH) {
            client.print("<h2>BUTTON ON!!!!!</h1>");
          }
          else if(buttonState == LOW) {
            client.print("<h2>BUTTON OFF....</h2>");
          }

          // 
          client.println("Click <a href=\"/H\">here</a> turn the LED on pin 9 on<br>");
          client.println("Click <a href=\"/L\">here</a> turn the LED on pin 9 off<br>");

          for (int analogChannel = 0; analogChannel < 3; analogChannel++) {
            int sensorReading = analogRead(analogChannel);
            client.print("analog input ");
            client.print(analogChannel);
            client.print(" is ");
            client.print(sensorReading);
            client.println("<br />");       
          }
          client.println("</html>");
           break;
        }
        if (c == '\n') {
          currentLineIsBlank = true;
        } 
        else if (c != '\r') {
          currentLineIsBlank = false;
          currentLine += c;
        }
      }
    }
    
    // Check to see if the client request was "GET /H" or "GET /L"
    if (currentLine.startsWith("GET /H")) {
      digitalWrite(ledPin, HIGH);             // GET /H turns the LED on
    }
    else if (currentLine.startsWith("GET /L")) {
      digitalWrite(ledPin, LOW);             // GET /L turns the LED off
    }

    delay(1);
    
    client.stop();
    Serial.println("client disonnected");
  }
}

void printWifiStatus() {
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
