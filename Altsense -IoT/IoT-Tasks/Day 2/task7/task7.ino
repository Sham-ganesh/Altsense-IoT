void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>1)
{
  char a=Serial.read();
  if(a=='x')
  {
    digitalWrite(9,1);
    digitalWrite(10,0);
    digitalWrite(11,0);
    Serial.println("Only 9 is glowing"); 
    delay(2000);
  }
  else
  if(a=='y')
  {
     digitalWrite(9,1);
     digitalWrite(10,1);
     digitalWrite(11,0);
     Serial.println("Only 9 and 10 is glowing");
     delay(2000); 
  }
  else
  if(a=='z')
  {
     digitalWrite(9,1);
     digitalWrite(10,1);
     digitalWrite(11,1);
     Serial.println("All 9,10,11 is glowing");
     delay(2000);
  }
  if(a=='a')
  {
     digitalWrite(9,0);
     digitalWrite(10,0);
     digitalWrite(11,0);
     Serial.println("No bulb is glowing");
     delay(2000);
  }
}
}
