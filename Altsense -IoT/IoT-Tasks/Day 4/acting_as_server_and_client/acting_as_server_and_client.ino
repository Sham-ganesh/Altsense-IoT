#include"WiFiEsp.h"
#include"SoftwareSerial.h"


SoftwareSerial esp(4,5);
WiFiEspServer server(8090);

WiFiEspClient client1;
WiFiEspClient client2;

char ssid[]="AltSense";
char pass[]="alt2018sense";

char server1[]="api.thingspeak.com";

int status=WL_IDLE_STATUS;
RingBuffer buf(30);


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
esp.begin(9600);

WiFi.init(&esp);
if(WiFi.status()==WL_NO_SHIELD)
 {
  Serial.println("No Esp Conected ");
  while(1);
  }
if(WiFi.status()!=WL_CONNECTED)
  {
    Serial.println("Connecting");
    WiFi.begin(ssid,pass);
    delay(1000);
  }
  Serial.println("Connected Successfully");
  Serial.println(WiFi.localIP());
  }



void loop()
{
   client1 = server.available();  // listen for incoming clients

    client2.connect(server1,80); 
    // if you get a client,
    Serial.println("New client");             // print a message out the serial port
    buf.init();                               // initialize the circular buffer
    //while (client1.connected()) 
                 // loop while the client's connected
      //if (client1.available()) 
        char c='a';            
        c = client1.read();               // read a byte, then
       buf.push(c);
       // push it to the ring buffer
        Serial.println(String(c));
        client2.println("GET https://api.thingspeak.com/update?api_key=G0VVUIKV5M9S9HAI&field1="+String(c));
        //Serial.println("Uploaded Data:"+c);
        
    client1.stop();
    Serial.println("Client disconnected");
    delay(10000);
  
  client2.stop();
  
}
