#include "WiFiEsp.h"
#include "SoftwareSerial.h"

SoftwareSerial Serial1(4, 5); // RX, TX


char ssid[] = "Ramo";            // your network SSID (name)
char pass[] = "sgfhcl@11";        // your network password
int status = WL_IDLE_STATUS;

int ledStatus = LOW;

WiFiEspServer server(80);

RingBuffer buf(30);
void setup() {
  // put your setup code here, to run once:
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
Serial.begin(9600);
Serial1.begin(9600);

WiFi.init(&Serial1);

  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue
    while (true);
  }

  // attempt to connect to WiFi network
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
  }

  Serial.println("You're connected to the network");

    Serial.println(WiFi.localIP());
  // start the web server on port 80
  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  WiFiEspClient client = server.available();  // listen for incoming clients

  if (client) {                               // if you get a client,
    Serial.println("New client");             // print a message out the serial port
    buf.init();                               // initialize the circular buffer
    while (client.connected()) 
    {              // loop while the client's connected
      if (client.available()) 
      {               // if there's bytes to read from the client,
        char c = client.read();               // read a byte, then
        buf.push(c);                          // push it to the ring buffer

        // printing the stream to the serial monitor will slow down
        // the receiving of data from the ESP filling the serial buffer
        //Serial.write(c);
        
        // you got two newline characters in a row
        // that's the end of the HTTP request, so send a response
        if (buf.endsWith("\r\n\r\n")) {
          sendHttpResponse(client);
          break;
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (buf.endsWith("GET /a")) {
          Serial.println("9th  led ON");
          ledStatus = HIGH;
          digitalWrite(9, HIGH);   // turn the LED on (HIGH is the voltage level)
        }
        else if (buf.endsWith("GET /b")) {
          Serial.println("9th led OFF");
          ledStatus = LOW;
          digitalWrite(9, LOW);    // turn the LED off by making the voltage LOW
        }
        else  if (buf.endsWith("GET /c")) {
          Serial.println("10th led ON");
         // ledStatus = HIGH;
          digitalWrite(10, HIGH);   // turn the LED on (HIGH is the voltage level)
        }
        else if (buf.endsWith("GET /d")) {
          Serial.println("10th led OFF");
         // ledStatus = LOW;
          digitalWrite(10, LOW); 
      }
    }
    }
    // close the connection
    client.stop();
    Serial.println("Client disconnected");
  
 }
}


void sendHttpResponse(WiFiEspClient client)
{
  // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
  // and a content-type so the client knows what's coming, then a blank line:
  client.println("HTTP/1.1 200 OK");
  client.println("Content-type:text/html");
  client.println();
  
  // the content of the HTTP response follows the header:
  client.print("The LED is ");
  client.print(ledStatus);
  client.println("<br>");
  client.println("<br>");
  client.println("<br>");
  client.println("<br>");
   
  client.println("Click <a href=\"/a\">here</a> turn the 9th LED on<br>");
  client.println("Click <a href=\"/b\">here</a> turn the 9th LED off<br>");
  client.println("Click <a href=\"/c\">here</a> turn the 10th LED on<br>");
  client.println("Click <a href=\"/d\">here</a> turn the 10th LED off<br>");
  
  // The HTTP response ends with another blank line:
  client.println();
}
