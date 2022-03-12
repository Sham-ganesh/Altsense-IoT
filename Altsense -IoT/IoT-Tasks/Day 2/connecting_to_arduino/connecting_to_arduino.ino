/*
 WiFiEsp example: WebClientRepeating

 This sketch connects to a web server and makes an HTTP request
 using an Arduino ESP8266 module.
 It repeats the HTTP call each 10 seconds.

 For more details see: http://yaab-arduino.blogspot.com/p/wifiesp.html
*/

#include "WiFiEsp.h"   //library for esp8266-01 support for arduino
#include "SoftwareSerial.h" /* software serial library for assingning other digital pins
for Serial communication
*/

SoftwareSerial esp8266(4, 5); // RX, TX

char ssid[] = "altsense";            // your network SSID (name)
char pass[] = "alt2018sense";        // your network password


int status = WL_IDLE_STATUS;        // the Wifi radio's status

char server[] = "arduino.cc";


WiFiEspClient client;

void setup()
{
  Serial.begin(9600); // Serial communication between laptop to arduino and viceversa
  
  esp8266.begin(9600); //Serial communication between esp8266-01 to arduino and viceversa
  
  WiFi.init(&esp8266); 

  
  if (WiFi.status() == WL_NO_SHIELD) {
   
      while (true)
      {Serial.print(".");
      
delay(1000);      }
  }

  
  while (status != WL_CONNECTED) {
    Serial.print("ROUTER_NAME: ");
    Serial.println(ssid);
    
    status = WiFi.begin(ssid, pass);
  }

  Serial.println("yes successfully connected to the network");
  
}

void loop()
{
   client.stop();
   client.connect(server, 80); 
    // send the HTTP PUT request
    client.println(F("GET /asciilogo.txt HTTP/1.1"));
    client.println(F("Host: arduino.cc"));
    client.println();
    String x = client.readString();
    Serial.println(x);
    // note the time that the connection was made
    delay(10000);
    
    

}
