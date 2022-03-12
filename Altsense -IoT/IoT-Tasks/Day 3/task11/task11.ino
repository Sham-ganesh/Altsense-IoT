

#include "WiFiEsp.h"   //library for esp8266-01 support for arduino
#include "SoftwareSerial.h" 

SoftwareSerial esp8266(4, 5); // RX, TX

char ssid[] = "AltSense";            // your network SSID (name)
char pass[] = "alt2018sense";        // your network password


int status = WL_IDLE_STATUS;        // the Wifi radio's status

char server[] = "api.thingspeak.com";


WiFiEspClient client;

void setup()
{

  Serial.begin(9600); // Serial communication between laptop to arduino and viceversa
  
  esp8266.begin(9600); //Serial communication between esp8266-01 to arduino and viceversa
  
  WiFi.init(&esp8266); 

  
  if (WiFi.status() == WL_NO_SHIELD)
  {
   
      while (true);
         
  }

  
  while (status != WL_CONNECTED) {
    Serial.print("ROUTER_NAME: ");
    Serial.println(ssid);
    
    status = WiFi.begin(ssid, pass);
  }

  Serial.println("yes successfully connected to the network");
    pinMode(A0,INPUT);
  pinMode(A1,INPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
  
 
   client.stop();
   if(Serial.available()>0)
   {
   client.connect(server, 80); 
    char x=Serial.read();
   if(x=='a')
   
   {
    float temp=analogRead(A0)*0.48;
    client.println("GET https://api.thingspeak.com/update?api_key=ML57PKUL6IS85F01&field1="+String(temp));
    Serial.println(temp);
    // note the time that the connection was made
    delay(5000);
    
    }
   
  else
  if(x=='b')
  { int inte=analogRead(A1);
   client.println("GET https://api.thingspeak.com/update?api_key=20M1MS0P0ZKS0GP5&field1="+String(inte)); 
    Serial.println(inte);
    // note the time that the connection was made
    delay(5000);
  }
  else
  if(x=='c')
  {float temp=analogRead(A0)*0.48;
     int inte=analogRead(A1);
  client.println("GET https://api.thingspeak.com/update?api_key=ML57PKUL6IS85F01&field1="+String(temp)); 
  client.println("GET https://api.thingspeak.com/update?api_key=20M1MS0P0ZKS0GP5&field1="+String(inte)); 
 Serial.println(temp);
 Serial.println(inte);
  delay(5000);
  }
  else
  Serial.println("Invalid input");
}
}
