#include<WiFiEsp.h>
#include<SoftwareSerial.h>

WiFiEspClient client;
SoftwareSerial esp(4,5);

char ssid[]="AltSense";
char pass[]="alt2018sense";

char server[]="192.168.0.3";

int status = WL_IDLE_STATUS;

void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT);
Serial.begin(9600);
esp.begin(9600);

WiFi.init(&esp);

if(WiFi.status()==WL_NO_SHIELD)
{
  Serial.println("No Esp-Conect a Esp");
  while(1);
}
while(WiFi.status()!=WL_CONNECTED)
{
  Serial.println("Connecting");
  WiFi.begin(ssid,pass);
  delay(2000);
  
}
Serial.println("Succlesfully Conneted");
Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
float x=analogRead(A0)*0.48;
float y=analogRead(A1);
client.connect(server,8090);
Serial.println("Succesfully connected to the server");
client.println("Temperature Data:"+String(x));

client.println("Ldr Data: "+String(y));
delay(5000);
client.stop();


}
