void setup() {
  // put your setup code here, to run once:
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int i=0,j=0;
for(j=0;j<2;j++)
{
  for(i=0;i<2;i++)
  {
  digitalWrite(9,i);
  digitalWrite(10,j);
  delay(2000);
  }
}
}
