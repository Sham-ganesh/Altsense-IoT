void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(A1,INPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(analogRead(A1)<100)
      { 
       digitalWrite(9,1);
       digitalWrite(10,1);
       digitalWrite(11,1);
      }
else
{
       digitalWrite(9,0);
       digitalWrite(10,0);
       digitalWrite(11,0);
       delay(200);
}
}
