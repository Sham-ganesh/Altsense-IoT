void setup() {
  // put your setup code here, to run once:
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
while(1)
{
  digitalWrite(9,HIGH);
digitalWrite(10,HIGH);
digitalWrite(11,HIGH);
delay(2000);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
digitalWrite(11,LOW);
delay(2000);
}
}

void loop() {
  // put your main code here, to run repeatedly:

}
