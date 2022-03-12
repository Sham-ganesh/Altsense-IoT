void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
pinMode(A1,INPUT);//For arudino it is input from the sensor
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(9,1);
  if(analogRead(A1)<75)
  {
    digitalWrite(10,1);
    digitalWrite(11,1);
  }
  else
  if((analogRead(A1)>75)&&(analogRead(A1)<200))
  {
    digitalWrite(10,1);
    digitalWrite(11,0);
  }
  else
  {
       digitalWrite(10,0);
       digitalWrite(11,0);
  }
  

}
