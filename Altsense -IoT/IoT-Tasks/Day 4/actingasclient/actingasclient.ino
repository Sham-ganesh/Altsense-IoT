#include"WiFiEsp.h"
#include"SoftwareSerial.h"


SoftwareSerial esp(4,5);
WiFiEspClient client;

char ssid[]="AltSense";
char pass[]="alt2018sense";

int status=WL_IDLE_STATUS;

char server[]="192.168.0.40";

void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT);
pinMode(A1,INPUT);


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
  }



void loop() {
  // put your main code here, to run repeatedly:
float temp=analogRead(A0)*0.48;
int x=analogRead(A1);
client.connect(server,8090);


  Serial.println("Succesfully Connected to Server");
  
  client.println("Temperature And Intensity Data:"+String(temp)+","+String(x));
  Serial.println("Temperature data Sent successfully:");
  Serial.println("Intensity Data Sent successfully");
  delay(10000);
  
client.stop();
 }
