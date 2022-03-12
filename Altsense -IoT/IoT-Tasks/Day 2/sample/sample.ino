void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);  //To intialise serial communication.
/*Baud Rate:Speed of serial communication-no of bits transferred per second*/
/*Standard Baud Rate:9600*/
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<10;i++)
{
Serial.println("Message to be sent to laptop");  //From Aurdino to laptop(used for debugging or finding errors)
delay(300);
}
exit(0);
}
